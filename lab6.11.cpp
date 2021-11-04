#include <iostream>
using namespace std;

void create(int* c, int i, int n)
{
	if (i < n)
	{
		c[i] = -35 + rand() % (61);
		cout <<c[i]<< " ";
		create(c, i + 1, n);
	}
}

void show(int* a, int S, int kil, int n,int z)
{
	if (z <= n)
	{
		cout << a[z] << " ";
		show(a, S, kil, n,z+1);
	}
}

void sumandquantity(int* c, int i, int n,int &S, int &q)
{
	if (i <= n)
	{
		if (c[i] > 0)
		{
			S += c[i];
			q += 1;
			c[i] = 0;
		}
		else if ((-c[i]) % 2 == 1)
		{
			S += c[i];
			q += 1;
			c[i] = 0;
		}
		sumandquantity(c, i + 1, n, S, q);
	}
}
void show1(int q, int S)
{
	cout << "S=" << S << endl;
	cout << "q=" << q;
}
int main()
{
	srand((unsigned)time(NULL));

	const int n = 26;
	int c[n + 1];
	int S = 0, i = 0, q = 0, z = 0;

	create(c, i, n + 1);
	sumandquantity(c, i, n, S, q);

	cout << endl;
	show(c, S, q, n, z);

	cout << endl;
	show1(q, S);

	return 0;
}