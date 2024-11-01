```ts
// 基于fetch封装的http请求（优化前）
import { stringifyQuery } from 'vue-router';
const apiPrefix = import.meta.env.VITE_BASE_URL;

interface RequestOptionType {
  method?: string;
  headers?: {
    [header: string]: string;
  };
  body?: any;
}

export interface ResponseType<T = any> {
  success: boolean;
  data: T;
  code: string;
  message: string;
  total?: number;
  pageIndex?: number;
  pageSize?: number;
}

interface ParamsType {
  [x: string]: any;
}

interface RequestInterface {
  <T = any>(url: string, options?: RequestOptionType, params?: ParamsType): Promise<
    ResponseType<T>
  >;
  get<T = any>(url: string, query?: ParamsType, customUrl?: boolean): Promise<ResponseType<T>>;
  post<T = any>(
    url: string,
    body?: RequestOptionType['body'],
    customUrl?: boolean
  ): Promise<ResponseType<T>>;
  put<T = any>(url: string, body?: RequestOptionType['body']): Promise<ResponseType<T>>;
  delete<T = any>(url: string): Promise<ResponseType<T>>;
}

/**
 * Requests a URL, returning a promise.
 *
 * @param {string} url      - The path we want to request
 * @param {Object} [options] - The options we want to pass to "fetch"
 * @param {Object} [params]
 *
 * @return {object}           An object containing either "data" or "err"
 */
const request: RequestInterface = async (url, options, params) => {
  const headers = {
    ...((options || {}).headers || {})
  };
  //   const token = tokenStorage.get();
  //   const employeeId = employeeIdStorage.get();
  //   const gameId = gameIdStorage.get();

  //   if (token) {
  //     headers.Authorization = `Bearer ${token}`;
  //   }

  //   if (employeeId) {
  //     // eslint-disable-next-line @typescript-eslint/camelcase
  //     headers.employee_id = employeeId;
  //   }

  //   if (gameId) {
  //     headers.gameId = gameId;
  //   }

  //   if (group) {
  //     headers.group = group;
  //   }

  const response = await fetch(params ? `${url}?${stringifyQuery(params)}` : url, {
    ...options,
    headers
  });

  const resJson = await response.json();

  if (response.status < 200 || response.status > 299 || !resJson.success) {
    throw Object.assign(new URIError(response.statusText), resJson);
  }

  return resJson;
};

request.get = (url, query, customUrl) => {
  return request(customUrl ? url : `${apiPrefix}${url}`, {}, query);
};

request.post = (url, body, customUrl) =>
  request(customUrl ? url : `${apiPrefix}${url}`, {
    method: 'POST',
    headers: {
      'Content-type': 'application/json',
      encrypt: '0'
    },
    body: JSON.stringify(body)
  });

request.put = (url, body) =>
  request(`${apiPrefix}${url}`, {
    method: 'PUT',
    headers: {
      'Content-type': 'application/json'
    },
    body: JSON.stringify(body)
  });

request.delete = (url) =>
  request(`${apiPrefix}${url}`, {
    method: 'DELETE'
  });

export default request;

```

```ts
// 基于fetch封装的http请求(优化后)
import { stringifyQuery } from 'vue-router';
// 从环境变量中获取API前缀
const apiPrefix = import.meta.env.VITE_BASE_URL;
// 请求选项类型定义
interface RequestOptionType {
  method?: string; // HTTP方法，如GET, POST等
  headers?: { // 请求头
    [header: string]: string;
  };
  body?: any; // 请求体
  timeout?: number; // 请求超时时间
  cache?: boolean; // 是否启用缓存
  cacheTime?: number; // 缓存时间
}

// 响应类型定义
export interface ResponseType<T = any> {
  success: boolean; // 请求是否成功
  data: T; // 响应数据
  code: string; // 响应代码
  message: string; // 响应消息
  total?: number; // 数据总数（分页时使用）
  pageIndex?: number; // 当前页码（分页时使用）
  pageSize?: number; // 每页数据量（分页时使用）
}

// 参数类型定义
interface ParamsType {
  [x: string]: any;
}

// 请求接口定义
interface RequestInterface {
  <T = any>(url: string, options?: RequestOptionType, params?: ParamsType): Promise<
    ResponseType<T>
  >;
  get<T = any>(url: string, query?: ParamsType, customUrl?: boolean): Promise<ResponseType<T>>;
  post<T = any>(
    url: string,
    body?: RequestOptionType['body'],
    customUrl?: boolean
  ): Promise<ResponseType<T>>;
  put<T = any>(url: string, body?: RequestOptionType['body']): Promise<ResponseType<T>>;
  delete<T = any>(url: string): Promise<ResponseType<T>>;
}

// 自定义HTTP错误类
class HttpError extends Error {
  constructor(public status: number, public data: any) {
    super(data.message || '请求错误'); // 错误信息
    this.name = 'HttpError'; // 错误名称
  }
}

// 拦截器接口定义
interface Interceptor {
  request?: (config: RequestOptionType) => RequestOptionType; // 请求拦截器
  response?: (response: ResponseType) => ResponseType; // 响应拦截器
  error?: (error: any) => any; // 错误拦截器
}

// 拦截器实现
const interceptors: Interceptor = {
  request: (config) => {
    // 在这里处理请求配置
    return config;
  },
  response: (response) => {
    // 在这里处理响应数据
    return response;
  },
  error: (error) => {
    // 统一错误处理
    return Promise.reject(error);
  }
};

// 缓存Map，用于存储请求缓存
const cacheMap = new Map<string, { data: any, timestamp: number }>();

// 生成缓存键
const getCacheKey = (url: string, options?: RequestOptionType, params?: ParamsType) => {
  return `${url}-${JSON.stringify(options)}-${JSON.stringify(params)}`;
};

// 超时处理函数
const timeout = (ms: number) => {
  return new Promise((_, reject) => {
    setTimeout(() => {
      reject(new Error(`请求超时 ${ms}ms`)); // 超时错误
    }, ms);
  });
};

/**
 * 请求函数，返回一个Promise
 *
 * @param {string} url      - 请求的URL
 * @param {Object} [options] - 请求选项
 * @param {Object} [params]  - 请求参数
 *
 * @return {object}          - 包含"data"或"err"的对象
 */
const request: RequestInterface = async (url, options, params) => {
  try {
    // 通过拦截器处理请求选项
    const finalOptions = interceptors.request?.(options) || options;
    const headers = {
      ...finalOptions.headers || {}
    };

    // 处理缓存
    const cacheKey = getCacheKey(url, finalOptions, params);
    if (finalOptions?.cache) {
      const cached = cacheMap.get(cacheKey);
      if (cached && Date.now() - cached.timestamp < (finalOptions.cacheTime || 0)) {
        return cached.data; // 返回缓存数据
      }
    }

    // 发起请求并处理超时
    const response = await Promise.race([
      fetch(params ? `${url}?${stringifyQuery(params)}` : url, {
        ...finalOptions,
        headers
      }),
      timeout(finalOptions?.timeout || 10000) // 默认超时10秒
    ]);

    const resJson = await response.json();

    // 检查响应状态和成功标志
    if (response.status < 200 || response.status > 299 || !resJson.success) {
      throw new HttpError(response.status, resJson); // 抛出自定义错误
    }

    // 缓存响应数据
    if (finalOptions?.cache) {
      cacheMap.set(cacheKey, {
        data: resJson,
        timestamp: Date.now()
      });
    }

    // 通过拦截器处理响应数据
    return interceptors.response?.(resJson) || resJson;
  } catch (error) {
    // 通过拦截器处理错误
    return interceptors.error?.(error) || Promise.reject(error);
  }
};

// GET请求方法
request.get = (url, query, customUrl) => {
  return request(customUrl ? url : `${apiPrefix}${url}`, {}, query);
};

// POST请求方法
request.post = (url, body, customUrl) =>
  request(customUrl ? url : `${apiPrefix}${url}`, {
    method: 'POST',
    headers: {
      'Content-type': 'application/json',
      encrypt: '0'
    },
    body: JSON.stringify(body)
  });

// PUT请求方法
request.put = (url, body) =>
  request(`${apiPrefix}${url}`, {
    method: 'PUT',
    headers: {
      'Content-type': 'application/json'
    },
    body: JSON.stringify(body)
  });

// DELETE请求方法
request.delete = (url) =>
  request(`${apiPrefix}${url}`, {
    method: 'DELETE'
  });

export default request;

```