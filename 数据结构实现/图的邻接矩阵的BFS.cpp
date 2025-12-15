#include<iostream>
#include<vector>
#include<queue>

using namespace std;

#define Vertex int
#define WeightType int
#define DataType vector<string>

struct GNode {
    int Nv;
    int Ne;
    std::vector<std::vector<int>> G;
    DataType Data;
};

vector<int>Visited;//BFS中使用，记录已访问节点
vector<int>BFSans;
vector<int>DFSans;

GNode* CreatGraph(int Nv) {//空图
    GNode* Graph = new GNode;
    Graph->Nv = Nv;
    Graph->Ne = 0;
    for (int i = 0; i < Nv; i++) {
        vector<int>col;
        for (int j = 0; j < Nv; j++) {
            col.push_back(0);
        }
        Graph->G.push_back(col);
    }
    //BFS中使用，记录已访问节点
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
    Graph->G[E->V1][E->V2] = E->Weight;
    //如果是无向图还要加边<V2,V1>
    Graph->G[E->V2][E->V1] = E->Weight;
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
            //cin >> Weight;
            E->V1 = V1; E->V2 = V2;
            Weight = 1;
            E->Weight = Weight;
            InsertEdge(G, E);
        }
        delete E;

    }
    //if 有顶点数据
    /*Vertex V;
    for (V = 0; V < Nv; V++) {
        string y;
        cin >> y;
        G->Data.push_back(y);
    }*/
    return G;
}

bool IsEdge(GNode* Graph, Vertex V, Vertex W) {
    return Graph->G[V][W] > 0 ? true : false;
}

void Visit(Vertex V) {
    BFSans.push_back(V);
}

void BFS(GNode* Graph, Vertex S, void (*Visit)(Vertex)) {
    queue<Vertex>Q;
    Vertex V, W;
    Visit(S);
    Visited[S] = 1;
    Q.push(S);

    while (!Q.empty()) {
        V = Q.front();
        Q.pop();
        for (W = 0; W < Graph->Nv; W++) {
            if (!Visited[W] && IsEdge(Graph, V, W)) {
                Visit(W);
                Visited[W] = 1;
                Q.push(W);
            }
        }
    }
}

void PrintAns(vector<int>Ans) {
    cout << "{ ";
    for (int i = 0; i < Ans.size(); i++) {
        cout << Ans[i] << " ";
    }
    cout << "}";
}

int main() {
    GNode* Graph = BuildGraph();

    //所有连通分支
    for (int i = 0; i < Graph->Nv; i++) {
        if (!Visited[i]) {
            BFS(Graph, i, Visit);
            PrintAns(BFSans);
            BFSans.clear();
            cout << endl;
        }
    }

    return 0;
}