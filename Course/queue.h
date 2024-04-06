#pragma once
#define Qmax 50
struct queue //������ ��������� �������
{
	int qu[Qmax];
	int start, end;
};

void init(struct queue* q) //������ ����� ������������� �������
{
	q->start = 0;
	q->end = -1;
	return;
}

void insert(struct queue* q, int c) //������ ����� ����� ����� � �������
{
	q->end++;
	q->qu[q->end] = c;
}

int isfull(struct queue* q) //������ �������� ������������� �������
{
	if (q->end == Qmax - 1) return 1;
	else return 0;
}

int isempty(struct queue* q) //������ �������� ����� �� �������
{
	if (q->end < q->start) return 1;
	else return 0;
}

void extract(struct queue* q) //������ ����� ������ ��������� �������
{
	if (isempty(q) == 1)
	{
		printf("������� �����.\n");
	}
	for (int h = q->start; h <= q->end; h++)
	{
		printf("%d", q->qu[h]);
	}
	return;
}

int remove(struct queue* q) //������ ����� �������� ��������� �� �������
{
	int x, h;
	x = q->qu[q->start];
	for (h = q->start; h < q->end; h++)
	{
		q->qu[h] = q->qu[h + 1];
	}
	q->end--;

	return x;
}

void remove_all(struct queue* q)
{
	while (isempty(q) != 1)
	{
		remove(q);
	}
}


int difer(struct queue* q, int c)
{
	int f = 0;
	for (int h = q->start; h <= q->end; h++)
	{
		if (c != q->qu[h])
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

