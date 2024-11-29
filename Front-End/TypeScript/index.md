# TS学习笔记

- 请看文件夹目录下的学习笔记

- 如何将a=1&b=2&c=3这种字符串进行解析，定义个ParseQueryString这个类型进行解析，就可以在代码中拿到对应的对象属性
```ts
type ParseParam<Param extends string> = Param extends `${infer Key}=${infer Value}`
  ? {
      [K in Key]: Value;
    }
  : Record<string, any>;

type MergeValues<One, Other> = One extends Other
  ? One
  : Other extends unknown[]
  ? [One, ...Other]
  : [One, Other];

type MergeParams<OneParam extends Record<string, any>, OtherParam extends Record<string, any>> = {
  readonly [Key in keyof OneParam | keyof OtherParam]: Key extends keyof OneParam
    ? Key extends keyof OtherParam
      ? MergeValues<OneParam[Key], OtherParam[Key]>
      : OneParam[Key]
    : Key extends keyof OtherParam
    ? OtherParam[Key]
    : never;
};

export type ParseQueryString<Str extends string> = Str extends `${infer Param}&${infer Rest}`
  ? MergeParams<ParseParam<Param>, ParseQueryString<Rest>>
  : ParseParam<Str>;
```