#include<iostream>
using namespace std;
class DTNode//�ж�������ඨ�� 
{
public:
	DTNode* LeftChild;
	DTNode* RightChild;
	int     LeftThreshold;//����֦��ֵ 
	int     RightThreshold;//����֦��ֵ 
	char    grade;//��ΪҶ��㣬��������������Ϊ�ȼ� 
	DTNode();
	DTNode(int l,int r,DTNode* left,DTNode* right);//���캯�� 
	DTNode(int l,int r,char c);//���캯������ 
	bool    IsLeaf();//�ж��Ƿ�ΪҶ��㣬���ж������� 
	DTNode* Divide(int score);//��֧�����ж� 
};
class DTree//�ж����ඨ�� 
{
public:
	DTNode* root; 
	DTree(DTNode* r);//���캯�� 
	void Preorder(DTNode* r);//ǰ�к������ 
	void Inorder(DTNode* r);
	void Postorder(DTNode* r);
};

DTNode::DTNode()//���캯��1 
{
	LeftThreshold = -1;
	RightThreshold = -1;
	LeftChild = RightChild = NULL;
	return;
}
DTNode::DTNode(int l,int r,char c)//���캯�����أ�Ҷ��㹹�죩 
{
	LeftThreshold = l;
	RightThreshold = r;
	grade = c;
	LeftChild = RightChild = NULL;
	return;
}
DTNode::DTNode(int l,int r,DTNode* left, DTNode* right)//���캯�����أ���֧���ж���㹹�죩 
{
	LeftThreshold = l;
	RightThreshold = r;
	LeftChild = left;
	RightChild = right;
	return;
}
bool DTNode::IsLeaf()//�ж��Ƿ�ΪҶ��� 
{
	if (!LeftChild&&!RightChild)
		return true;
	else
		return false;
}
DTNode* DTNode::Divide(int score)//�ж����� 
{
	if (score>=LeftThreshold&&score<=RightThreshold)
		return RightChild;
	else
		return LeftChild;
}

DTree::DTree(DTNode* r)//�ж������캯�� 
{
	root = r;
	return;
}
void DTree::Inorder(DTNode* r)//�ݹ�ǰ����� 
{
	if (!r)//��Ϊ�����򷵻� 
		return;
	Inorder(r->LeftChild);//������������� 
	if (!r->IsLeaf())//��Ϊ��ΪҶ��㣬������ж����� 
		cout<<'['<<r->LeftThreshold<<','<<r->RightThreshold<<"]?"<<endl;
	else
		cout<<r->grade<<endl;//��ΪҶ���������ж���� 
	Inorder(r->RightChild);//������������� 
}
void DTree::Preorder(DTNode* r)//�ݹ�ǰ����� 
{
	if (!r)//��Ϊ�����򷵻� 
		return;
	if (!r->IsLeaf())//��Ϊ��ΪҶ��㣬������ж����� 
		cout<<'['<<r->LeftThreshold<<','<<r->RightThreshold<<"]?"<<endl;
	else
		cout<<r->grade<<endl;//��ΪҶ���������ж����
	Preorder(r->LeftChild);//ǰ����������� 
	Preorder(r->RightChild);//ǰ����������� 
}
void DTree::Postorder(DTNode* r)
{
	if (!r)
		return;
	Postorder(r->LeftChild);//������������� 
	Postorder(r->RightChild);//������������� 
	if (!r->IsLeaf())//��Ϊ��ΪҶ��㣬������ж����� 
		cout<<'['<<r->LeftThreshold<<','<<r->RightThreshold<<"]?"<<endl;
	else//��ΪҶ���������ж����
		cout<<r->grade<<endl;
	return;
}

