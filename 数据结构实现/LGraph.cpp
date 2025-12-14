#include<iostream>
#include"LGraph.h"

using namespace std;


GNode* CreatGraph(int Nv) {//空图
    GNode* Graph = new GNode;
    Graph->Nv = Nv;
    Graph->Ne = 0;
    for (int i = 0; i < Nv; i++) {
        AdjList tmp;
        tmp.FirstEdge = nullptr;
        Graph->G.push_back(tmp);
    }
    return Graph;
}

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
