#pragma once
#define SIZE 50

int size_s = 0;

struct Stack
{
	int data[SIZE];
	int top;
};

void init_s(struct Stack* s)
{
	s->top = -1;
}

int isfull_s(struct Stack* s)
{
	if (s->top == SIZE - 1)
		return 1;
	else
		return 0;
}

int isempty_s(struct Stack* s)
{
	if (s->top == -1)
		return 1;
	else
		return 0;
}

void insert_s(struct Stack* s, int st)
{
	if (isfull_s(s) == 1)
	{
		printf("Стек заполнен! \n");
	}
	else
	{
		s->top++;
		s->data[s->top] = st;
	}
	size_s++;
}

int remove_s(struct Stack* s)
{
	int x;
	x = s->data[s->top];
	s->top--;
	size_s--;
	return x;
}
void remove_all_s(struct Stack* s)
{
	while (isempty_s(s) != 1)
	{
		remove_s(s);
	}
}

void vivod(struct Stack* s)
{
	for (int i = 0; i < size_s; i++)
	{
		std::cout << s->data[i] << " ";
	}
}

int difer_s(struct Stack* s, int c)
{
	int f = 0;
	for (int i = 0; i < size_s; i++)
	{
		if (c != s->data[i])
		{
			f = 1;
		}
		else
		{
			f = 0;
			break;
		}
	}
	if (f == 1) return 1;
	else return 0;
}

