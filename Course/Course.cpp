#include <iostream>
#include<locale>
#include <iomanip>
#include <stdio.h>
#include <fstream>
#include "queue.h"
#include "stack.h"
#include "cyc.h"

using namespace std;

void fill_null(int**, size_t);
void print_arr(int**, size_t);
void print_col(int*, size_t);



int main()
{

	setlocale(LC_ALL, "RU");
	size_t r;
	int** arr;
	int a;
	int b;
	struct Stack* s = new Stack;
	struct queue* q = new queue;

	ifstream file;

	file.open("input.txt");

	int n;
	file >> n;

	r = n;

	arr = new int* [r];
	init(q);
	init_s(s);


	for (size_t i = 0; i < r; i++)
	{
		arr[i] = new int[r];

	}


	fill_null(arr, r);

	file >> a >> b;
	bool flag = false;

	while (!file.eof())
	{
		arr[a - 1][b - 1] = 1;
		file >> a >> b;
		flag = true;
	}
	if (!flag)
	{
		cout << "пустой граф" << endl;
		system("pause");
		return 0;
	}
	flag = false;
	file.close();


	int c = -1;

	a = cyc(arr, q, s, c, r);
	if (a != -1)
	{
		for (int i = 1; i < r; i++)
		{
			c = a;
			a = cyc(arr, q, s, c, r);
			if (a == -1) break;
		}
		if (a == -1)
		{
			cout << "Искомая вершина: " << c + 1 << "\n";
		}
		else cout << "Подходящей вершины нет.";
	}
	else cout << "Подходящей вершины нет.";

}



void fill_null(int** ar, size_t n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			ar[i][j] = 0;
		}
	}
}

