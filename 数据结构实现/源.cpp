#include<iostream>


using namespace std;

//数据结构表示二叉树：静态链表
#define MaxTree 10
#define ElementType char
#define Tree int
#define Null -1

struct TreeNode {
	ElementType Element;
	Tree Left;
	Tree Right;
}T1[MaxTree], T2[MaxTree];

Tree BuildTree(struct TreeNode T[]) {
	int N = 0, check[MaxTree], i = 0;
	char cl, cr;
	Tree Root;
	cin >> N;
	if (N) {
		for (i = 0; i < N; i++)check[i] = 0;
		for (i = 0; i < N; i++) {
			cin >> T[i].Element >> cl >> cr;

			if (cl != '-') {
				T[i].Left = cl - '0';
				check[T[i].Left] = 1;
			}
			else T[i].Left = Null;

			//对cr的处理
			if (cr != '-') {
				T[i].Right = cr - '0';
				check[T[i].Right] = 1;
			}
			else T[i].Right = Null;
		}
		for (i = 0; i < N; i++)
			if (!check[i])break;

		Root = i;
	}
	return Root;
}

int isomorphic(Tree R1, Tree R2) {
	if ((R1 == Null) && (R2 == Null))//都空
		return 1;
	if (((R1 == Null) && (R2 != Null)) || ((R2 == Null) && (R1 != Null)))//一个空一个不空
		return 0;
	if (T1[R1].Element != T2[R2].Element)//根节点不一样
		return 0;
	if ((T1[R1].Left == Null) && (T2[R2].Left == Null))//都没有左儿子
		return isomorphic(T1[R1].Right, T2[R2].Right);
	if ((T1[R1].Left != Null) && (T2[R2].Left != Null) &&
		(T1[T1[R1].Left].Element) == (T2[T2[R2].Left].Element))//不需要交换左右儿子（子树）比较
		return (isomorphic(T1[R1].Left, T2[R2].Left) &&
			isomorphic(T1[R1].Right, T2[R2].Right));
	else
		return (isomorphic(T1[R1].Left, T2[R2].Right) &&//需要交换
			isomorphic(T1[R1].Right, T2[R2].Left));

}

int main() {
	Tree R1, R2;
	//建二叉树1
	R1 = BuildTree(T1);
	//建二叉树2
	R2 = BuildTree(T2);
	//判别是否同构并输出
	if (isomorphic(R1, R2))printf("Yes\n");


	return 0;
}