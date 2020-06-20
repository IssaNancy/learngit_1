#include <iostream>
#include <iomanip>
#define X 10
using namespace std;
int a[X+1][X+1];

int main()
{
    int x, y;
    cin >> x;
    y = x;
    int num = 0;
    int i = 1, j = 0;
    int re = x * y;//   x行   y列
    while (num < re) {
        while (j <= y && !a[i][j + 1]) {
            a[i][++j] = ++num;
        }
        if (j > y)
        {
            j--; num--;
        }
        while (i <= x && !a[i + 1][j]) {
            a[++i][j] = ++num;
        }
        if (i > x)
        {
            i--; num--;
        }
        while (j >= 1 && !a[i][j - 1]) {
            a[i][--j] = ++num;
        }
        if (j < 1) {
            j++; num--;
        }
        while (i >= 1 && !a[i - 1][j]) {
            a[--i][j] = ++num;
        }
    }

	for (i = 1; i <= x; ++i)
	{
		for (j = 1; j <= y; ++j)
		{
			cout << setw(4)<< setfill('*') << a[i][j];
		}
		cout << endl;
	}

	return 0;
}


