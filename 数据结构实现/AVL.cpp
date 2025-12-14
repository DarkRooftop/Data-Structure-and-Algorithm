#include"AVL.h"
using namespace std;

int getHeight(AVLNode* node) {
    return node ? node->height : 0;
}
AVLNode* SingleLeftRotation(AVLNode* Tree) {
    AVLNode* Root = Tree->left;
    Tree->left = Root->right;
    Root->right = Tree;
    Tree->height = max(getHeight(Tree->left),
        getHeight(Tree->right)) + 1;
    Root->height = max(getHeight(Root->left), Tree->height) + 1;
    return Root;
}
AVLNode* SingleRightRotation(AVLNode* Tree) {
    AVLNode* Root = Tree->right;
    Tree->right = Root->left;
    Root->left = Tree;
    Tree->height = max(getHeight(Tree->left),
        getHeight(Tree->right)) + 1;
    Root->height = max(Tree->height, getHeight(Root->right)) + 1;
    return Root;
}
AVLNode* DoubleLeftRightRotation(AVLNode* Tree) {
    Tree->left = SingleRightRotation(Tree->left);
    return SingleLeftRotation(Tree);
}
AVLNode* DoubleRightLeftRotation(AVLNode* Tree) {
    Tree->right = SingleLeftRotation(Tree->right);
    return SingleRightRotation(Tree);
}
AVLNode* Insert(int x, AVLNode* T) {
    if (!T)
        T = new AVLNode(x);
    else if (x < T->data) {
        T->left = Insert(x, T->left);
        if (getHeight(T->left) - getHeight(T->right) == 2) {
            if (x < T->left->data)
                T = SingleLeftRotation(T);
            else
                T = DoubleLeftRightRotation(T);
        }
    }
    else if (x > T->data) {
        T->right = Insert(x, T->right);
        if (getHeight(T->right) - getHeight(T->left) == 2) {
            if (x > T->right->data)
                T = SingleRightRotation(T);
            else
                T = DoubleRightLeftRotation(T);
        }
    }
    T->height = max(getHeight(T->left), getHeight(T->right)) + 1;
    return T;
}

