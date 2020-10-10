#include<iostream>
#include<queue>//通过队列实现层序输出 
using namespace std;

template<class T>//二叉树类声明 
class BinaryTree;

template<class T>
class BinaryTreeNode//二叉树结点类定义 
{
	friend class BinaryTree<T>;
private:
	T element;
	BinaryTreeNode<T>* LeftChild;
	BinaryTreeNode<T>* RightChild;
public:
	BinaryTreeNode();
	BinaryTreeNode(const T&ele);
	BinaryTreeNode(const T&ele, BinaryTreeNode<T>* l, BinaryTreeNode<T>* r);
	bool isLeaf()const;
};

template<class T>
BinaryTreeNode<T>::BinaryTreeNode()
{
	LeftChild = RightChild = NULL;
}

template<class T>
BinaryTreeNode<T>::BinaryTreeNode(const T&ele)
{
	LeftChild = RightChild = NULL;
	element   = ele;
}

template<class T>
BinaryTreeNode<T>::BinaryTreeNode(const T&ele, BinaryTreeNode<T>* l, BinaryTreeNode<T>* r)
{
	LeftChild  = l;
	RightChild = r;
	element    = ele;
}

template<class T>
bool BinaryTreeNode<T>::isLeaf() const
{
	if (LeftChild == NULL && RightChild == NULL)
		return true;
	else
		return false;
}


template<class T>
class BinaryTree//二叉树类定义，部分函数留作以后定义 
{
private:
	BinaryTreeNode<T>* root;
public:
	BinaryTree();
	BinaryTree(BinaryTreeNode<T>* r);
//	~BinaryTree();
	bool IsEmpty() const;
	BinaryTreeNode<T>* getRoot() const;
	void breadthFirstOrder(BinaryTreeNode<T>* root);
	void preOrder(BinaryTreeNode<T>* root);//前序遍历 
	void inOrder(BinaryTreeNode<T>* root);//中序遍历 
	void postOrder(BinaryTreeNode<T>* root);//后序遍历 
	void deleteBinaryTree(BinaryTreeNode<T>* root);
	void visit(BinaryTreeNode<T>* pointer);
	void build_from_pre_and_in(int n, char* preorder, char* inorder, BinaryTreeNode<T>* subtree);//前序和中序构造二叉树 
	void build_from_post_and_in(char* postorder, char*inorder, int m);
	void view(BinaryTreeNode<T>* root);//后序输出 
};

template<class T>
void BinaryTree<T>::view(BinaryTreeNode<T>* root)
{
	queue<BinaryTreeNode<T>*> q;
	q.push(root);
	while(!q.empty())
	{
		BinaryTreeNode<T>* pointer = q.front();
		cout<<pointer->element;
		q.pop();
		if (pointer->LeftChild)
		{
			q.push(pointer->LeftChild);
		}
		if (pointer->RightChild)
		{
			q.push(pointer->RightChild);
		}
		
	}
	
}


template<class T>
bool BinaryTree<T>::IsEmpty() const
{
	if (root == NULL)
		return true;
	else
		return false;
}

template<class T>
BinaryTree<T>::BinaryTree()
{
	root = NULL;
}

template<class T>
BinaryTree<T>::BinaryTree(BinaryTreeNode<T>* r)
{
	root = r;
}

template<class T>
BinaryTreeNode<T>* BinaryTree<T>::getRoot() const
{
	return root;
}

template<class T>
void BinaryTree<T>::build_from_pre_and_in(int n,char* preorder, char* inorder, BinaryTreeNode<T>* subtree)//前序和中序构造二叉树 
{
	if (n==0)//若子串长度为0，返回 
		return;
	else
	{
		subtree->element=preorder[0];//构造子树根节点 
		for (int i=0;i<n;i++)
		{
			if (inorder[i]==preorder[0])//子树的根节点为前序第一个，在中序中寻找子树根节点，左子串即为左子树中序，右子串即为右子树中序 
			{
				if (i!=0)
					subtree->LeftChild = new BinaryTreeNode<char>;
				build_from_pre_and_in(i,preorder+1,inorder,subtree->LeftChild);//构造左子树 
				if ((n-i-1)!=0)
					subtree->RightChild = new BinaryTreeNode<char>;
				build_from_pre_and_in(n-i-1,preorder+i+1,inorder+i+1,subtree->RightChild);//构造右子树 
			}
			
		}
	}

		
		
	
	
	
}
