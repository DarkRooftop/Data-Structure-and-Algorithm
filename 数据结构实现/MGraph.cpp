#include<iostream>
#include"MGraph.h"

using namespace std;

GNode* CreatGraph(int Nv) {//空图
    GNode* Graph = new GNode;
	Graph->Nv = Nv;
    Graph->Ne = 0;
    //看起来是一个方阵
    for (int i = 0; i < Nv; i++) {
        vector<int>col;
        for (int j = 0; j < Nv; j++) {
            col.push_back(0);
        }
        Graph->G.push_back(col);
    }
    return Graph;
}

void InsertEdge(GNode* Graph, Edge E) {
    Graph->G[E->V1][E->V2] = E->Weight;
    //如果是无向图还要加边<V2,V1>
    //Graph->G[E->V2][E->V1] = E->Weight;
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
        delete E;

    }
    //if 有顶点数据
    Vertex V;
    for (V = 0; V < Nv; V++) {
        string y;
        cin >> y;
        G->Data.push_back(y);
    }
    return G;
}
// 销毁图（防止内存泄漏）
void DestroyGraph(GNode* Graph) {
    if (Graph) {
        delete Graph;
    }
}
//int main() {
//    GNode* Graph = BuildGraph();
//    cout << "制图成功！";
//    return 0;
//}