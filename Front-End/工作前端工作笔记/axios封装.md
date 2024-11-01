针对相对通用的使用场景对axios进行了封装，满足目前的常规业务场景
> 使用方法：
```ts
import { get, post } from './http';
/**
 * 事件分析平台与策略选股
 * 查询用户的配置
 * @param personId 用户id
 */

export const queryPageConfig = (params: { personId: string }) => {
  return get('/stock/analyse/platform/queryPageConfig', params);
};

/**
 * 事件分析平台与策略选股
 * 保存用户的配置
 * @param analysePageRatio	事件分析平台首页页面比例
 * @param conditionPageRatio	策略选股页面比例、
 * @param personId	用户卡号
 */

export const savePageConfig = (params: {
  personId: string;
  analysePageRatio?: string;
  conditionPageRatio?: string;
}) => {
  return post('/stock/analyse/platform/savePageConfig', params);
};
```

```ts
// 基于axios封装的http请求(优化前)
import axios from 'axios';
import { stringifyQuery } from 'vue-router';
// 这里可以替换成所有组件的弹窗信息组件
import Message from '@/components/common/base-message/message';

// 从环境变量中获取API前缀
const baseURL = import.meta.env.VITE_URL_PREFIX;
// 创建实例
const axiosInstance = axios.create({
  baseURL,
  timeout: 60000
});

/** 请求地址必须以/开头 */
type url = `/${string}` | `https://${string}` | `http://${string}`;

interface Options {
  headers?: any;
  // /** 用于串行接口调取避免loading闪烁 */
  // delay?: boolean;
  // /** 判断接口是否开启loading,可以传入也可以不传入使用系统内置的loading */
  // isLoading?: boolean | null;
  /** 返回所有数据 */
  perfectBody?: boolean;
  /** 是否返回所有响应内容 */
  allresponse?: boolean;
  /** 是否隐藏后端的响应错误 */
  hidenError?: boolean;
  /** 是否不校验登录信息 */
  noAuth?: boolean;
}

interface Response {
  resultCode: number | string;
  data: any;
  resultMsg?: string;
  requestId: string;
  timestamp?: number;
}

interface GetOption extends Options {
  /** 是否保留空字符串的属性 */
  keepEmpty?: boolean;
  /** 是否缓存当前请求的内容，默认false */
  cache?: boolean;
  /** 是否刷新当前的请求缓存,默认false */
  fresh?: boolean;
}

interface PostOption extends Options {
  /** 表单数据格式, 默认是json, 即: Content-Type: application/json;
   * form 的格式是 Content-Type: application/x-www-form-urlencoded */
  dataType?: 'json' | 'form';
  /** 是否保留空字符串的属性 */
  keepEmpty?: boolean;
}

const combineGetOption = (option = {}): GetOption => {
  return Object.assign(
    {
      allresponse: false,
      perfectBody: false,
      hidenError: false
    } as GetOption,
    option
  );
};

const combinePostOption = (option = {}): PostOption => {
  return Object.assign(
    {
      allresponse: false,
      perfectBody: false,
      hidenError: false,
      dataType: 'json'
    } as PostOption,
    option
  );
};

const getHeader = (header = {}): any => {
  const headers = {
    encrypt: 0
  };

  return Object.assign(headers, header);
};

// 接口错误数量
let ErrorNumber = 0;
// 登录标识
let hasNoLogin = false;
/**
 * 统一的处理
 * @param res 接口类型
 * @param hidenError 是否隐藏报错信息
 *  */
const responseHandler = async (res: Response, hidenError = false): Promise<any> => {
  if (res.resultCode === 0 || res.resultCode === '000000') {
    hasNoLogin = false;
    // 正确的响应请求
    return Promise.resolve(res.data);
  }
  ErrorNumber++;
  // 当错误太多的时候那么就不会进行提示推送
  if (!hidenError && ErrorNumber < 3 && !hasNoLogin) {
    hasNoLogin = false;
    if (res.resultMsg) {
      Message.error('系统繁忙，请稍后再试');
    } else {
      Message.error('系统繁忙，请稍后再试');
    }
  }
  return Promise.reject({ ...res, throwByHanlder: true });
};

/**
 * get请求
 * @param url 接口的url地址
 * @param query 接口的参数对象
 * @param option 该接口需要返回的配置项
 * @param header 接口header的配置添加信息，结构同：GetOption
 * @returns Promise类型
 */
export const get = <T>(
  url: url,
  query?: Record<string | number, string | number | boolean>,
  option?: any,
  header?: any
): Promise<T | any> => {
  const { allresponse, perfectBody, hidenError } = combineGetOption(option);
  const headers = getHeader(header);
  const _query = query;
  return axiosInstance
    .get<Response>(url, {
      params: typeof _query === 'object' ? { ..._query, t: Date.now() } : { t: Date.now() },
      headers
    })
    .then((res) => {
      if (perfectBody) {
        return res;
      }
      if (allresponse) {
        return res.data;
      }
      return responseHandler(res.data, hidenError);
    })
    .catch((error) => {
      if (error.response) {
        // 请求成功发出且服务器也响应了状态码，但状态代码超出了 2xx 的范围
        return responseHandler(error.response);
      } else if (error.request) {
        // 请求已经成功发起，但没有收到响应
        // `error.request` 在浏览器中是 XMLHttpRequest 的实例，
        // 而在node.js中是 http.ClientRequest 的实例
        console.error(error.request, 'error.request');
      } else {
        // 发送请求时出了点问题
        console.error('Error', error.message);
      }
      if (error.throwByHanlder) {
        return Promise.reject(error);
      }
      // 如果什么请求都没有会统一返回一个结果
      return responseHandler({
        resultCode: 9999,
        data: null,
        resultMsg: '系统繁忙，请稍后再试',
        requestId: '没有requestId！'
      });
    });
};

/**
 * post请求
 * @param url 接口的url地址
 * @param data 接口的参数对象
 * @param option 该接口需要返回的配置项，结构同：PostOption
 * @returns Promise类型
 *
 *  */

export const post = <T>(
  url: url,
  data: Record<string, any> = {},
  option: PostOption = {}
): Promise<T | any> => {
  const { allresponse, perfectBody, hidenError, dataType } = combinePostOption(option);
  const headers = getHeader();
  // 创建一个实例
  return axiosInstance
    .post<Response>(url, dataType === 'json' ? data : stringifyQuery(data), {
      params: { t: Date.now() },
      headers
    })
    .then((res) => {
      if (perfectBody) {
        return res;
      }

      if (allresponse) {
        return res.data;
      }
      return responseHandler(res.data, hidenError);
    })
    .catch((error) => {
      console.error(error, 'error');
      if (error.response) {
        // 请求成功发出且服务器也响应了状态码，但状态代码超出了 2xx 的范围
        return responseHandler(error.response);
      } else if (error.request) {
        // 请求已经成功发起，但没有收到响应
        // `error.request` 在浏览器中是 XMLHttpRequest 的实例，
        // 而在node.js中是 http.ClientRequest 的实例
        console.error(error.request, 'error.request');
      } else {
        // 发送请求时出了点问题
        console.error('Error', error.message);
      }
      if (error.throwByHanlder) {
        return Promise.reject(error);
      }

      return responseHandler({
        resultCode: 9999,
        data: null,
        resultMsg: '系统繁忙，请稍后再试',
        requestId: '没有requestId！'
      });
    });
};
```

```ts
// 基于axios封装的http请求(优化后)
import axios from 'axios';
import { stringifyQuery } from 'vue-router';
// 这里可以替换成所有组件的弹窗信息组件
import Message from '@/components/common/base-message/message';

// 从环境变量中获取API前缀
const baseURL = import.meta.env.VITE_URL_PREFIX;

// 创建实例
const axiosInstance = axios.create({
  baseURL,
  timeout: 60000
});

/** 请求地址必须以/开头 */
type url = `/${string}` | `https://${string}` | `http://${string}`;

interface Options {
  headers?: any;
  // /** 用于串行接口调取避免loading闪烁 */
  // delay?: boolean;
  // /** 判断接口是否开启loading,可以传入也可以不传入使用系统内置的loading */
  // isLoading?: boolean | null;
  /** 返回所有数据 */
  perfectBody?: boolean;
  /** 是否返回所有响应内容 */
  allresponse?: boolean;
  /** 是否隐藏后端的响应错误 */
  hidenError?: boolean;
  /** 是否不校验登录信息 */
  noAuth?: boolean;
}

interface Response {
  resultCode: number | string;
  data: any;
  resultMsg?: string;
  requestId: string;
  timestamp?: number;
}

interface GetOption extends Options {
  /** 是否保留空字符串的属性 */
  keepEmpty?: boolean;
  /** 是否缓存当前请求的内容，默认false */
  cache?: boolean;
  /** 是否刷新当前的请求缓存,默认false */
  fresh?: boolean;
}

interface PostOption extends Options {
  /** 表单数据格式, 默认是json, 即: Content-Type: application/json;
   * form 的格式是 Content-Type: application/x-www-form-urlencoded */
  dataType?: 'json' | 'form';
  /** 是否保留空字符串的属性 */
  keepEmpty?: boolean;
}

const combineGetOption = (option = {}): GetOption => {
  return Object.assign(
    {
      allresponse: false,
      perfectBody: false,
      hidenError: false
    } as GetOption,
    option
  );
};

const combinePostOption = (option = {}): PostOption => {
  return Object.assign(
    {
      allresponse: false,
      perfectBody: false,
      hidenError: false,
      dataType: 'json'
    } as PostOption,
    option
  );
};

const getHeader = (header = {}): any => {
  const headers = {
    encrypt: 0
  };

  return Object.assign(headers, header);
};

// 接口错误数量
let ErrorNumber = 0;
// 登录标识
let hasNoLogin = false;
/**
 * 统一的处理
 * @param res 接口类型
 * @param hidenError 是否隐藏报错信息
 *  */
const responseHandler = async (res: Response, hidenError = false): Promise<any> => {
  if (res.resultCode === 0 || res.resultCode === '000000') {
    hasNoLogin = false;
    // 正确的响应请求
    return Promise.resolve(res.data);
  }
  ErrorNumber++;
  // 当错误太多的时候那么就不会进行提示推送
  if (!hidenError && ErrorNumber < 3 && !hasNoLogin) {
    hasNoLogin = false;
    if (res.resultMsg) {
      Message.error('系统繁忙，请稍后再试');
    } else {
      Message.error('系统繁忙，请稍后再试');
    }
  }
  return Promise.reject({ ...res, throwByHanlder: true });
};

/**
 * 处理请求错误的通用函数
 * @param error 错误对象
 * @param hidenError 是否隐藏错误信息
 * @returns Promise<any>
 */
const handleError = async (error: any, hidenError: boolean): Promise<any> => {
  if (error.response) {
    // 请求成功发出且服务器也响应了状态码，但状态代码超出了 2xx 的范围
    return responseHandler(error.response);
  } else if (error.request) {
    // 请求已经成功发起，但没有收到响应
    console.error(error.request, 'error.request');
  } else {
    // 发送请求时出了点问题
    console.error('Error', error.message);
  }
  if (error.throwByHanlder) {
    // 如果错误是由处理程序抛出的，直接拒绝
    return Promise.reject(error);
  }
  // 返回一个通用的错误响应
  return responseHandler({
    resultCode: 9999,
    data: null,
    resultMsg: '系统繁忙，请稍后再试',
    requestId: '没有requestId！'
  });
};

/**
 * 发送GET请求
 * @param url 请求的URL
 * @param query 请求的查询参数
 * @param option 请求的配置选项
 * @param header 请求的头部信息
 * @returns Promise<T | any>
 */
export const get = async <T>(
  url: url,
  query?: Record<string | number, string | number | boolean>,
  option?: any,
  header?: any
): Promise<T | any> => {
  const { allresponse, perfectBody, hidenError } = combineGetOption(option);
  const headers = getHeader(header);
  try {
    const res = await axiosInstance.get<Response>(url, {
      params: typeof query === 'object' ? { ...query, t: Date.now() } : { t: Date.now() },
      headers
    });
    if (perfectBody) return res; // 返回完整的响应对象
    if (allresponse) return res.data; // 返回响应数据
    return responseHandler(res.data, hidenError); // 处理响应数据
  } catch (error) {
    return handleError(error, hidenError); // 处理错误
  }
};

/**
 * 发送POST请求
 * @param url 请求的URL
 * @param data 请求的数据
 * @param option 请求的配置选项
 * @returns Promise<T | any>
 */
export const post = async <T>(
  url: url,
  data: Record<string, any> = {},
  option: PostOption = {}
): Promise<T | any> => {
  const { allresponse, perfectBody, hidenError, dataType } = combinePostOption(option);
  const headers = getHeader();
  try {
    const res = await axiosInstance.post<Response>(url, dataType === 'json' ? data : stringifyQuery(data), {
      params: { t: Date.now() },
      headers
    });
    if (perfectBody) return res; // 返回完整的响应对象
    if (allresponse) return res.data; // 返回响应数据
    return responseHandler(res.data, hidenError); // 处理响应数据
  } catch (error) {
    return handleError(error, hidenError); // 处理错误
  }
};

```

