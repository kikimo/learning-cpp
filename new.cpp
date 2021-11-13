#include <iostream>

using namespace std;

int main()
{
	int arry[1024];
	for (int i = 0; i < 1024; i++) {
		arry[i] = i + 1;
	}

	int **ptr = new int*[10];
	ptr[0] = arry;
	for (int i = 0; i < 1024; i++) {
		cout << ptr[0][i] << '\n';
	}

	delete []ptr;
	return 0;
}

