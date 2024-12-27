#include <iostream>
using namespace std;

void fillArray(int* ptr, int size) {
	for (int i = 0; i < size; ++i) {
		ptr[i] = rand() % 10;
	}
}

void displayArray(int* ptr, int size) {
	for (int i = 0; i < size; ++i) {
		cout << ptr[i] << ' ';
	}
	cout << endl;
}




void del(int* ptr) {
	delete[] ptr;
}

void findDifferentElements(int* ptr, int* p, int size_ptr, int size_p) { // #1
	int* c_temp = new int[size_ptr > size_p ? size_ptr : size_p];
	int size = 0;
	for (int i = 0; i < size_ptr; ++i) {
		bool f = false;
		for (int j = 0; j < size_p; ++j)
		{
			if (ptr[i] == p[j]) { f = true; break; }
		}
		if (!f) {
			bool d = false;
			for (int k = 0; k < size; ++k)
			{
				if (c_temp[k] == ptr[i]) { d = true; break; }
			} if (!d) { c_temp[size++] = ptr[i]; }
		}
	}
	int* c = new int[size];
	for (int i = 0; i < size; ++i) c[i] = c_temp[i];
	displayArray(c, size);
	del(c);
}

int main()
{
	srand(time(nullptr));
	int m, n;
	cout << "Enter size of array A and B: ";
	cin >> m >> n;
	int* a = new int[m];
	int* b= new int[n];
	fillArray(a, m);
	fillArray(b, n);
	displayArray(a, m);
	displayArray(b, n);
	findDifferentElements(a, b, m, n);

	del(a);
	del(b);
}

