//����ģ�崴��ջ�ṹ���Լ���غ��� 
template <typename T>
struct Stack//ջ���� 
{
	int top;
	int maxsize;
	T c[100];
};
template <typename T>
bool pop(Stack<T> *s,T* b)//��ջ 
{
	if (s->top<0)
		return false;
	else
	{
		int top = s->top;
		*b = s->c[top];
		s->top--;
		return true;
	}
}
template <typename T>
bool push(Stack<T> *s,T b)//��ջ 
{
	if (s->top==s->maxsize-1)
		return false;
	else
	{
		s->top++;
		int top = s->top;
		s->c[top]=b;
		return true;
	}
}
template <typename T>
T get_top(Stack<T> *s)//ȡ����Ԫ�� 
{
	return s->c[s->top];
}
template <typename T>
void view(Stack<T> s)//���ӻ����Թ��� 
{
	for (int i=s.top;i>=0;i--)
		printf("%2d",s.c[i]);
	printf("\n");
	return;
}
