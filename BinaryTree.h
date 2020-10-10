#include<iostream>
#include<queue>//ͨ������ʵ�ֲ������ 
using namespace std;

template<class T>//������������ 
class BinaryTree;

template<class T>
class BinaryTreeNode//����������ඨ�� 
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
class BinaryTree//�������ඨ�壬���ֺ��������Ժ��� 
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
	void preOrder(BinaryTreeNode<T>* root);//ǰ����� 
	void inOrder(BinaryTreeNode<T>* root);//������� 
	void postOrder(BinaryTreeNode<T>* root);//������� 
	void deleteBinaryTree(BinaryTreeNode<T>* root);
	void visit(BinaryTreeNode<T>* pointer);
	void build_from_pre_and_in(int n, char* preorder, char* inorder, BinaryTreeNode<T>* subtree);//ǰ�������������� 
	void build_from_post_and_in(char* postorder, char*inorder, int m);
	void view(BinaryTreeNode<T>* root);//������� 
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
void BinaryTree<T>::build_from_pre_and_in(int n,char* preorder, char* inorder, BinaryTreeNode<T>* subtree)//ǰ�������������� 
{
	if (n==0)//���Ӵ�����Ϊ0������ 
		return;
	else
	{
		subtree->element=preorder[0];//�����������ڵ� 
		for (int i=0;i<n;i++)
		{
			if (inorder[i]==preorder[0])//�����ĸ��ڵ�Ϊǰ���һ������������Ѱ���������ڵ㣬���Ӵ���Ϊ�������������Ӵ���Ϊ���������� 
			{
				if (i!=0)
					subtree->LeftChild = new BinaryTreeNode<char>;
				build_from_pre_and_in(i,preorder+1,inorder,subtree->LeftChild);//���������� 
				if ((n-i-1)!=0)
					subtree->RightChild = new BinaryTreeNode<char>;
				build_from_pre_and_in(n-i-1,preorder+i+1,inorder+i+1,subtree->RightChild);//���������� 
			}
			
		}
	}

		
		
	
	
	
}
