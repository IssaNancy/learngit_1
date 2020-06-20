#include <iostream>
using namespace std;

template <typename T>
void insertionSort(T a[], int n) {
	for (int i = 1; i < n; i++) {
		int j = i;
		T temp = a[i];
		for (; j != 0 && a[j] < a[j - 1]; j--) {
			T swap = a[j];
			a[j] = a[j - 1];
			a[j - 1] = swap;
		}
		a[j] = temp;
		for (int m = 0; m < n; m++) {
			cout << a[m] << " ";
		}
		cout << endl;
	}
}

int main() {
	int data[] = { 1,3,5,7,9,11,13,15,17,19,2,4,6,8,10,12,14,16,18,20 };
	insertionSort(data, 20);
	return 0;
}
