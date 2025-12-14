#pragma once
#include <vector>

#define DataType std::vector<string>
typedef struct GNode* PtrToGNode;
struct GNode {
    int Nv;
    int Ne;
    std::vector<std::vector<int>> G;
    DataType Data;
};
typedef  MGraph;

#define Vertex int
#define WeightType int
typedef struct ENode* PtrToENode;
struct ENode {
    Vertex V1, V2;
    WeightType Weight;
};
typedef PtrToENode Edge;

GNode* CreatGraph(int);
void InsertEdge(GNode*);
GNode* BuildGraph();
void DestroyGraph(GNode*);
