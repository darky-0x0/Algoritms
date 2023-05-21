#include "SearchInATDArray.h"






void lab1task2() {

	int n, m, k(1), v, A, B, res;

	cout << "Введите размерность двумерного массива N(эл/ст) x M(эл/стр): ";

	cin >> n >> m;

	system("cls");

	cout << "Введите элемент который будем искать от 1 до " << n * m << ": ";

	cin >> v;

	int** arr = new int* [n];

	system("cls");

	for (int i = 0; i < n; i++) {

		arr[i] = new int[m];

		for (int j = 0; j < m; j++) {

			arr[i][j] = k++;

		}

	}

	res = TDArrayLineSearch(arr, v, n, m, A, B);

	if (res == -1) cout << "Такого элемента не найдено\n";

	else cout << "Элемент находится по индексу [" << A << ";" << B << "]\n";

	res = TDArrayBarrierSearch(arr, v, n, m, A, B);

	if (res == -1) cout << "Такого элемента не найдено\n";

	else cout << "Элемент находится по индексу [" << A << ";" << B << "]\n";


	for (int i = 0; i < n; i++) {

		delete[] arr[i];

	}

	delete[] arr;

}

void lab1task3() {

	int n, m, k(1), v, A, B, res;

	string file = "input.txt";

	cout << "Введите элемент который будем искать ";

	cin >> v;

	system("cls");

	int** arr = new int*;

	arr = FileRead(file, n, m);



	int up(0), down(n - 1), right(m - 1), left(0);

	res = TDArrayBinarySearch(arr, v, n, m, A, B, 0, n - 1, m - 1, 0);

	if (res == -1) cout << "Такого элемента не найдено\n";

	else cout << "Элемент находится по индексу [" << A << ";" << B << "]\n";

	for (int i = 0; i < n; i++) {

		delete[] arr[i];

	}

	delete[] arr;

}


int TDArrayLineSearch(int** a, int v, size_t sizeA, size_t sizeB, int& A, int& B)

{

	A = 0;

	unsigned int i = 0;

	B = 0;

	while ((i < sizeA * sizeB) && (a[A][B++] != v)) {

		i++;

		if (B == sizeB) {

			B = 0;

			A++;

		}

	}

	if (i != sizeA * sizeB) {

		B--;

		return 1;

	}

	return -1;

}

int TDArrayBarrierSearch(int** a, int v, size_t sizeA, size_t sizeB, int& A, int& B)

{

	int** newArr = new int* [sizeA + 1];

	for (int i = 0; i < sizeA; i++) {

		newArr[i] = new int[sizeB];

		for (int j = 0; j < sizeB; j++) {

			newArr[i][j] = a[i][j];

		}

	}

	newArr[sizeA] = new int[1];

	newArr[sizeA][0] = v;

	A = 0;

	unsigned int i = 0;

	B = 0;

	while (newArr[A][B] != v) {

		i++;

		B++;

		if (B == sizeB) {

			B = 0;

			A++;

		}



	}



	delete[] newArr[sizeA];

	for (int i = 0; i < sizeA; i++) {

		delete[] newArr[i];

	}

	delete[] newArr;



	if (i != sizeA * sizeB) {

		return 1;

	}

	return -1;

}

int TDArrayBinarySearch(int** a, int v, size_t sizeA, size_t sizeB, int& A, int& B, int up, int down, int right, int left)
{

	int height, width;

	bool isEnd = false;

	if ((up >= down) && (right <= left))

		return -1;

	height = (up + down) / 2;

	width = (right + left) / 2;

	if (right == left) {		//если остаётся одна полоска

		int size = down - up + 1;

		int t(0);

		int* arr = new int[size];

		for (int i = up; i <= down; i++) {

			arr[t++] = a[i][right];

		}

		int center = RecurseSearch(arr, v, size, 0, size - 1); //находим элемент

		if (center == -1) {

			delete[] arr;

			return -1;

		}

		else {

			A = up + center;

			B = width;

			delete[] arr;

			return a[up + center][width];

		}

	}

	else if (up == down) {

		int size = right - left + 1;

		int t(0);

		int* arr = new int[size];

		for (int i = left; i <= right; i++) {

			arr[t++] = a[up][i];

		}

		int center = RecurseSearch(arr, v, size, 0, size - 1); //находим элемент

		if (center == -1) {

			delete[] arr;

			return -1;

		}

		else {

			A = height;

			B = left + center;

			delete[] arr;

			return a[height][left + center];

		}

	}

	if (a[height][width] == v) {

		A = height;

		B = width;

		return a[height][width];

	}

	else if (v < a[height][width]) {

		int k;	//для проверки

		k = TDArrayBinarySearch(a, v, sizeA, sizeB, A, B, up, height - 1, right, width);

		if (k == v) {

			return a[A][B];

		}

		else {

			if (width - 1 < left) return -1;

			return TDArrayBinarySearch(a, v, sizeA, sizeB, A, B, up, down, width - 1, left);

		}

	}

	else {

		int k;	//для проверки

		k = TDArrayBinarySearch(a, v, sizeA, sizeB, A, B, height + 1, down, width, left);

		if (k == v) {

			return a[A][B];

		}

		else {

			if (width - 1 < left) return -1;

			return TDArrayBinarySearch(a, v, sizeA, sizeB, A, B, up, down, right, width + 1);

		}

	}

}

int RecurseSearch(int* a, int v, size_t size, long long first, long long end) {

	if (first > end) {		//end>=first

		return -1;

	}

	long long center = (first + end) / 2;

	if (a[center] == v) {

		return center;

	}

	else if (a[center] > v) {

		return RecurseSearch(a, v, size, first, center - 1);

	}

	else {

		return RecurseSearch(a, v, size, center + 1, end);

	}

}

int** FileRead(string filename, int& n, int& m) {

	ifstream file;

	file.open(filename);

	file >> n;

	file >> m;

	int** a = new int* [n];

	for (int i = 0; i < n; i++) {

		a[i] = new int[m];

		for (int j = 0; j < m; j++) {

			file >> a[i][j];

		}

	}

	return a;
}