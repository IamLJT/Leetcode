#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define ERROR	0
#define OK		1
#define MAXBUFFER 10

//typedef enum {DOUBLE, CHAR} Type;
//typedef union
//{
//	double i;
//	char c;
//}ElemType;

typedef char ElemType;

typedef struct
{
	//Type t;
	ElemType *base;
	ElemType *top;
	int stackSize;
}sqStack;

#define STACK_INIT_SIZE 100
void InitStack(sqStack *s)
{
	s->base = (ElemType *)malloc(
		STACK_INIT_SIZE * sizeof(ElemType));
	if( !s->base )
		exit(0);
	s->top = s->base;
	s->stackSize = STACK_INIT_SIZE;
}

#define STACKCREMENT 10
void Push(sqStack *s, ElemType e)
{
	//如果栈满的话就追加空间
	if(s->top - s->base >= s->stackSize)
	{
		s->base = (ElemType *)realloc(
			s->base, (s->stackSize + STACKCREMENT) * sizeof(ElemType));
		if( !s->base )
			exit(0);

		s->top = s->base + s->stackSize;
		s->stackSize = s->stackSize + STACKCREMENT;
	}

	*(s->top) = e;
	s->top++;
}

void Pop(sqStack *s, ElemType *e)
{
	if(s->top == s->base)
		return;
	*e = *--(s->top);
}

void ClearStack(sqStack *s)
{
	s->top = s->base;
}

void DestroyStack(sqStack *s)
{
	int i, len;
	len = s->stackSize;
	for(i=0; i<len; i++)
	{
		free(s->base);
		s->base++;
	}
	s->base = s->top = NULL;
	s->stackSize = 0;
}

int StackLen(sqStack *s)
{
	return (s->top - s->base);
}

bool StackEmpty(sqStack *s)
{
	if(s->top == s->base)
		return false;
	else
		return true;
}

void infix2suffix(sqStack s, sqStack s0)
{
	char c;
	char str[MAXBUFFER];
	ElemType e;
	int i=0;
	double d;

	printf("请输入表达式：\n");
	scanf("%c", &c);

	while( c != '#' )
	{
		while( isdigit(c) || c == '.' )	
		{
			printf("%c", c);
			/*str[i++] = c;
			str[i] = '\0';
			if(i >= 10)
			{
				printf("出错：输入的单个数据过大！\n");
				return;
			}*///怎么定义两种类型的链表
			scanf("%c", &c);
			if((!isdigit(c))&&(c != '.'))
			{
				printf(" ");
			//	d = atof(str);
			//	Push(&s0, d);
			}
		}
		if( c == ')')
		{
			Pop(&s, &e);
			while( e != '(')
			{
				printf("%c ", e);
				Pop(&s, &e);
			}
		}
		else if( '+' == c || '-'== c )
		{
			if(!StackEmpty(&s))
			{
				Push(&s, c);
			}
			else
			{
				do
				{
					Pop(&s, &e);
					if( '(' == e )
						Push(&s, e);
					else
						printf("%c ", e);
				}while( StackEmpty(&s) && '(' != e);
				Push(&s, c);
			}
		}
		else if( '*' == c || '/' == c || '(' == c)
		{
			Push(&s, c);
		}
		else if( '#' == c)
		{
			break;
		}
		else
		{
			printf("\n出错：输入格式错误！\n");
			return;
		}
		scanf("%c", &c);
	}
	while(StackEmpty(&s))
	{
		Pop(&s, &e);
		printf("%c ", e);
	}
	printf("\n");
}


int main()
{
	sqStack s, s0;

	InitStack(&s);
	InitStack(&s0);

	infix2suffix(s, s0);

	system("pause");
	return 0;
}