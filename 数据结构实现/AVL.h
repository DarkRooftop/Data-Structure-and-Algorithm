#pragma once
#include<iostream>
#include<algorithm>
struct AVLNode {
    int data;
    AVLNode* left;
    AVLNode* right;
    int height;
    AVLNode() : data(0), left(nullptr), right(nullptr), height(0) {}
    AVLNode(int val) : data(val), left(nullptr), right(nullptr), height(1) {}
};
int getHeight(AVLNode*);
AVLNode* SingleLeftRotation(AVLNode*);
AVLNode* SingleRightRotation(AVLNode*);
AVLNode* DoubleLeftRightRotation(AVLNode*);
AVLNode* DoubleRightLeftRotation(AVLNode*);
AVLNode* Insert(int, AVLNode*);