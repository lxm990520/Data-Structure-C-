#include<iostream>
using namespace std;
class DTNode//判定树结点类定义 
{
public:
	DTNode* LeftChild;
	DTNode* RightChild;
	int     LeftThreshold;//左树枝阈值 
	int     RightThreshold;//右树枝阈值 
	char    grade;//若为叶结点，则代表分类结果，即为等级 
	DTNode();
	DTNode(int l,int r,DTNode* left,DTNode* right);//构造函数 
	DTNode(int l,int r,char c);//构造函数重载 
	bool    IsLeaf();//判断是否为叶结点，即判定结果结点 
	DTNode* Divide(int score);//分支，即判定 
};
class DTree//判定树类定义 
{
public:
	DTNode* root; 
	DTree(DTNode* r);//构造函数 
	void Preorder(DTNode* r);//前中后序遍历 
	void Inorder(DTNode* r);
	void Postorder(DTNode* r);
};

DTNode::DTNode()//构造函数1 
{
	LeftThreshold = -1;
	RightThreshold = -1;
	LeftChild = RightChild = NULL;
	return;
}
DTNode::DTNode(int l,int r,char c)//构造函数重载（叶结点构造） 
{
	LeftThreshold = l;
	RightThreshold = r;
	grade = c;
	LeftChild = RightChild = NULL;
	return;
}
DTNode::DTNode(int l,int r,DTNode* left, DTNode* right)//构造函数重载（分支，判定结点构造） 
{
	LeftThreshold = l;
	RightThreshold = r;
	LeftChild = left;
	RightChild = right;
	return;
}
bool DTNode::IsLeaf()//判断是否为叶结点 
{
	if (!LeftChild&&!RightChild)
		return true;
	else
		return false;
}
DTNode* DTNode::Divide(int score)//判定操作 
{
	if (score>=LeftThreshold&&score<=RightThreshold)
		return RightChild;
	else
		return LeftChild;
}

DTree::DTree(DTNode* r)//判定树构造函数 
{
	root = r;
	return;
}
void DTree::Inorder(DTNode* r)//递归前序遍历 
{
	if (!r)//若为空树则返回 
		return;
	Inorder(r->LeftChild);//中序遍历左子树 
	if (!r->IsLeaf())//若为不为叶结点，则输出判定过程 
		cout<<'['<<r->LeftThreshold<<','<<r->RightThreshold<<"]?"<<endl;
	else
		cout<<r->grade<<endl;//若为叶结点则输出判定结果 
	Inorder(r->RightChild);//中序遍历右子树 
}
void DTree::Preorder(DTNode* r)//递归前序遍历 
{
	if (!r)//若为空树则返回 
		return;
	if (!r->IsLeaf())//若为不为叶结点，则输出判定过程 
		cout<<'['<<r->LeftThreshold<<','<<r->RightThreshold<<"]?"<<endl;
	else
		cout<<r->grade<<endl;//若为叶结点则输出判定结果
	Preorder(r->LeftChild);//前序遍历左子树 
	Preorder(r->RightChild);//前序遍历右子树 
}
void DTree::Postorder(DTNode* r)
{
	if (!r)
		return;
	Postorder(r->LeftChild);//后序遍历左子树 
	Postorder(r->RightChild);//后序遍历右子树 
	if (!r->IsLeaf())//若为不为叶结点，则输出判定过程 
		cout<<'['<<r->LeftThreshold<<','<<r->RightThreshold<<"]?"<<endl;
	else//若为叶结点则输出判定结果
		cout<<r->grade<<endl;
	return;
}

