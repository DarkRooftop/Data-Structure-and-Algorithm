#pragma once
#include<vector>

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
    std::vector<AdjList> G;
    //DataType Data;
};

typedef struct ENode* PtrToENode;
struct ENode {//Edge是插入的中介
    Vertex V1, V2;
    WeightType Weight;
};
typedef PtrToENode Edge;

GNode* CreatGraph(int Nv);
void InsertEdge(GNode* Graph, Edge E);
GNode* BuildGraph();