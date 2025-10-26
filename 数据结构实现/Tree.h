#pragma once

#include<iostream>
#include<vector>


#define MaxTree 10
#define ElementType int

typedef struct TreeNode* BinTree;
typedef BinTree Position;
struct TreeNode {
	ElementType Data;
	BinTree Left;
	BinTree Right;
	TreeNode(ElementType val) : Data(val), Left(nullptr), Right(nullptr) {}
};

Position Find(ElementType X, BinTree BST);
Position Find2(ElementType X, BinTree BST);
Position FindMin(BinTree BST);
Position FindMax(BinTree BST);

BinTree Insert(ElementType X, BinTree BST);
BinTree Delete(ElementType X, BinTree BST);

BinTree CreateSampleTree();
BinTree CengCreatTree();
void Traversal(TreeNode* cur, std::vector<ElementType>& vec);
std::vector<ElementType> PreTraversal(TreeNode* root);
std::vector<ElementType> CengTraversal(TreeNode* root);
void PrintBT(std::vector<ElementType> vec);
int IsEmptyBT(BinTree bt);
int TreeHeight(const BinTree bt);