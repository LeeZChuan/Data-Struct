

//创建图,以邻接矩阵表示

function create(nodes, edges) {
  for (let i = 0; i < nodes.length; i++) {
    const pre = nodes[i];

    graph[pre] = {};

    for (let j = 0; j < nodes.length; j++) {
      const next = nodes[j];

      graph[pre][next] = 0;
    }
  }

  for (let k = 0; k < edges.length; k++) {
    const edge = edges[k];

    graph[edge.source][edge.target] = 1;
  }

  //初始化color数组为0，表示一开始所有顶点都未被访问过

  for (let i = 0; i < nodes.length; i++) {
    visited[nodes[i]] = 0;
  }
}

//邻接矩阵

const graph = {};

//结点个数和边的个数

//标记矩阵,0为当前结点未访问,1为访问过,-1表示当前结点后边的结点都被访问过。

const visited = {};

//是否是DAG(有向无环图)

let isDAG = true;

// 获取所有的节点

const edges = [
  {
    source: "node1",

    target: "node3",
  },

  {
    source: "node3",

    target: "node5",
  },
];

const nodes = [];

edges.forEach((e) => {
  const { source, target } = e;

  if (!nodes.includes(source)) {
    nodes.push(source);
  }

  if (!nodes.includes(target)) {
    nodes.push(target);
  }
});

create(nodes, edges);

//保证每个节点都遍历到，排除有的结点没有边的情况

for (let i = 0; i < nodes.length; i++) {
  //该结点后边的结点都被访问过了，跳过它

  if (visited[nodes[i]] == -1) {
    continue;
  }

  DFS(i);

  if (!isDAG) {
    console.log("有环");

    break;
  }
}

if (isDAG) {
  console.log("无环");
}

