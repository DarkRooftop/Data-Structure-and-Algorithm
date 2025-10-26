#include"Tree.h"
#include<queue>


using namespace std;

Position Find(ElementType X, BinTree BST) {
	if (!BST) return NULL;//没找到
	if (X > BST->Data)
		return Find(X, BST->Right);//大于，右子树找--尾递归
	else if (X < BST->Data)
		return Find(X, BST->Left);//小于，左子树找--尾递归--可以用循环实现（迭代函数，执行效率更高）
	else
		return BST;//找到了，返回结点地址
}
Position Find2(ElementType X, BinTree BST) {
	while (BST) {
		if (X > BST->Data)
			BST = BST->Right;
		else if (X < BST->Data)
			BST = BST->Left;
		else
			return BST;
	}
	return NULL;
}
Position FindMin(BinTree BST) {//递归函数
	if (!BST)return NULL;
	else if (!BST->Left)
		return BST;//叶结点返回
	else
		return FindMin(BST->Left);//沿左分支继续查找
}
Position FindMax(BinTree BST) {//迭代函数
	if (BST)
		while (BST->Right)BST = BST->Right;
	else
		return BST;
}
BinTree Insert(ElementType X, BinTree BST) {
	if (!BST) {
		//若原树为空，生成并返回一个节点的二叉搜索树
		BST = (BinTree)malloc(sizeof(struct TreeNode));
		BST->Data = X;
		BST->Left = BST->Right = NULL;
	}
	else {//开始找要插入元素的位置
		if (X < BST->Data)
			BST->Left = Insert(X, BST->Left);//递归插入左子树
		else if (X > BST->Data)
			BST->Right = Insert(X, BST->Right);//递归插入右子树
		//else X 已经存在，什么都不做
		return BST;
	}
}
BinTree Delete(ElementType X, BinTree BST) {
	Position Tmp;
	if (!BST)cout << "未找到要删除的元素" << endl;
	else if (X < BST->Data)
		BST->Left = Delete(X, BST->Left);//左子树递归删除
	else if (X > BST->Data)
		BST->Right = Delete(X, BST->Right);//右子树递归删除
	else {//找到要删除的结点
		if (BST->Left && BST->Right) {//被删除结点有左右两个子结点
			Tmp = FindMin(BST->Right);
			//在右子树中找最小元素并填充删除结点（或左子树最大元素）
			BST->Data = Tmp->Data;
			BST->Right = Delete(BST->Data, BST->Right);
			//在删除结点的右子树中删除最小元素
		}
		else {//被删除结点有一个或无子结点
			Tmp = BST;
			if (!BST->Left)//有右孩子或无子结点
				BST = BST->Right;
			else if (!BST->Right)//有左孩子或无子结点
				BST = BST->Left;
			free(Tmp);
		}
	}
	return BST;
}


//创建一个二叉树
BinTree CreateSampleTree() {
	/*
	 创建以下二叉树：
		   1
		  / \
		 2   3
		/ \
	   4   5
	   */

	TreeNode* root = new TreeNode('1');
	root->Left = new TreeNode('2');
	root->Right = new TreeNode('3');
	//root->Left->Left = new TreeNode('4');
	root->Left->Right = new TreeNode('5');
	root->Right->Left = new TreeNode('6');
	root->Right->Right = new TreeNode('7');


	return root;
}

//层序创建树
BinTree CengCreatTree() {
	queue<TreeNode*>Q; TreeNode* temp, * root;

	ElementType z;
	cin >> z;
	root = new TreeNode(z);

	//如果不是空树
	if (root->Data == -1)return root;
	//第一个节点加入队列
	Q.push(root);

	//处理队列
	while (!Q.empty()) {

		//记录当前节点（取出当前节点）
		temp = Q.front();

		//删除队列第一个元素
		Q.pop();

		ElementType x, y;
		cin >> x;
		if (x != -1)
			cin >> y;
		//如果有元素，把元素加入树，并压入左右
		if (x != -1) {
			TreeNode* t = new TreeNode(x);
			temp->Left = t;
			Q.push(temp->Left);
		}
		else return root;
		if (y != -1) {
			TreeNode* t2 = new TreeNode(y);
			temp->Right = t2;
			Q.push(temp->Right);
		}
		else return root;

	}
	return root;
}

//先序遍历树
void Traversal(TreeNode* cur, vector<ElementType>& vec) {
	if (cur == NULL) {
		return;
	}
	vec.push_back(cur->Data);
	Traversal(cur->Left, vec);
	Traversal(cur->Right, vec);
}
vector<ElementType> PreTraversal(TreeNode* root) {
	vector<ElementType> result;
	Traversal(root, result);
	return result;
}

//层序遍历树
vector<ElementType> CengTraversal(TreeNode* root) {
	queue<TreeNode*>Q; TreeNode* temp;
	vector<ElementType> result;

	//如果不是空树
	if (!root)return result;
	//第一个节点加入队列
	Q.push(root);

	//处理队列
	while (!Q.empty()) {

		//记录当前节点（取出当前节点）
		temp = Q.front();
		//存入当前节点数据
		result.push_back(temp->Data);
		//删除队列第一个元素
		Q.pop();

		//如果左右不空，压入左右
		if (temp->Left) {
			Q.push(temp->Left);
		}
		if (temp->Right) {
			Q.push(temp->Right);
		}

	}
	return result;
}

//打印树
void PrintBT(vector<ElementType> vec) {
	for (ElementType a : vec) {
		cout << a << " ";
	}
	return;
}

//判别BT是否为空
int IsEmptyBT(BinTree bt) {
	int boolbt = 0;
	if (bt == NULL) {
		cout << "这是一颗空树。" << endl;
		boolbt = 1;
	}
	return boolbt;
}

//求树的高度
int TreeHeight(const BinTree bt) {
	int LH = 0, RH = 0, MH = 0;
	if (bt) {
		LH = TreeHeight(bt->Left);
		RH = TreeHeight(bt->Right);
		return max(LH, RH) + 1;
	}
	else
		return 0;
}
