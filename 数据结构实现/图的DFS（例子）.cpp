#include<iostream>
#include<vector>

using namespace std;

#define Vertex int
#define WeightType int
#define DataType vector<string>

struct AdjVNode {//邻接点
    Vertex AdjV;
    WeightType Weight;
    AdjVNode* Next;
};
typedef struct VNode {//顶点（表头指针）
    AdjVNode* FirstEdge;
    //顶点其他信息
    //DataType Data;
}AdjList;

struct GNode {
    int Nv;
    int Ne;
    vector<AdjList> G;
    //DataType Data;
};

vector<int>Visited;//DFS中使用，记录已访问节点

GNode* CreatGraph(int Nv) {//空图
    GNode* Graph = new GNode;
    Graph->Nv = Nv;
    Graph->Ne = 0;
    for (int i = 0; i < Nv; i++) {
        AdjList tmp;
        tmp.FirstEdge = nullptr;
        Graph->G.push_back(tmp);
    }

    //DFS中使用，记录已访问节点
    for (int i = 0; i < Nv; i++)
        Visited.push_back(0);

    return Graph;
}

typedef struct ENode* PtrToENode;
struct ENode {//Edge是插入的中介
    Vertex V1, V2;
    WeightType Weight;
};
typedef PtrToENode Edge;

void InsertEdge(GNode* Graph, Edge E) {
    AdjVNode* NewNode = new AdjVNode;
    NewNode->AdjV = E->V2;
    NewNode->Weight = E->Weight;
    NewNode->Next = Graph->G[E->V1].FirstEdge;
    Graph->G[E->V1].FirstEdge = NewNode;
    //如果是无向图，同理插入<V2,V1>
    return;
}

GNode* BuildGraph() {
    GNode* G; int Nv, Ne;
    cin >> Nv;
    G = CreatGraph(Nv);

    Edge E;
    cin >> Ne;
    if (Ne) {
        E = new ENode;
        for (int i = 0; i < Ne; i++) {
            Vertex V1, V2; WeightType Weight;
            cin >> V1 >> V2;
            cin >> Weight;
            E->V1 = V1; E->V2 = V2;
            E->Weight = Weight;
            InsertEdge(G, E);
        }

    }
    //if 有顶点数据
    return G;
}

void Visit(Vertex V) {
    cout << "正在访问节点" << V << endl;
}
void DFS(GNode* Graph, Vertex V, void(*visit)(Vertex)) {
    AdjVNode* W;
    Visit(V);
    Visited[V] = 1;
    for (W = Graph->G[V].FirstEdge; W; W = W->Next) {
        if (!Visited[W->AdjV])
            DFS(Graph, W->AdjV, Visit);

    }
}
//int main() {
//    GNode* Graph = BuildGraph();
//    DFS(Graph, 7, Visit);
//    cout << "DFS已完成";
//    return 0;
//}
