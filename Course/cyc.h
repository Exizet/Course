#pragma once
using namespace std;

int cyc(int** ar, struct queue* q, struct Stack* s, int c, int r)
{
	int i = 0;
	int f = 1;
	int a;
	do
	{
		if (i >= r)
		{
			return -1;
			break;
		}

		for (int j = 0; j < r; j++)
		{
			if (i != c) {
				if (ar[i][j] == 1 and isempty(q) == 1)
				{
					insert(q, i);
					break;
				}
			}
		}
		if (isempty(q) != 1)
		{
			for (int j = 0; j < r; j++)
			{
				if (j != c) {
					if (ar[i][j] == 1)
					{

						if (difer_s(s, j) == 1 or isempty_s(s) != 0 or difer(q, j) == 1)
						{
							insert_s(s, j);
							f = 0;
						}
					}
					else if (isempty_s(s) == 1) f = 1;
					else f = 0;
				}
			}

			if (f == 1)
			{
				i = remove(q);
				remove_all(q);
				f = 0;
			}

			if (isempty_s(s) != 1)
			{
				a = remove_s(s);
				if (difer(q, a) == 1)
				{
					insert(q, a);
				}
				else
				{
					a = remove(q);
					f = 1;
					return a;

				}


				i = a;
			}
			else i++;
		}
		else i++;
	} while (f != 1);

}

