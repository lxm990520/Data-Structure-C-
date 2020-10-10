//利用模板创建栈结构体以及相关函数 
template <typename T>
struct Stack//栈定义 
{
	int top;
	int maxsize;
	T c[100];
};
template <typename T>
bool pop(Stack<T> *s,T* b)//出栈 
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
bool push(Stack<T> *s,T b)//入栈 
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
T get_top(Stack<T> *s)//取顶部元素 
{
	return s->c[s->top];
}
template <typename T>
void view(Stack<T> s)//可视化调试工具 
{
	for (int i=s.top;i>=0;i--)
		printf("%2d",s.c[i]);
	printf("\n");
	return;
}
