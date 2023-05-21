#include "ArrangementOfQueens.h"





void lab4task1() {

	cout << "Введите размерность шахматной доски: ";

	int n;

	cin >> n;

	system("cls");

	ArrangementOfQueensMain(n);

}



void ArrangementOfQueensMain(int N) {

	int count(0);

	vector<int> field(N * N, 0);

	vector<int> vertical(N * N, 0);

	vector<int> diagonalUp(N * N, 0);

	vector<int> diagonalDown(N * N, 0);



	bool ifFound;

	ifFound = ArrangementOfQueensRecurs(field, vertical, diagonalUp, diagonalDown, count, N);

	int k(0);

	if (ifFound == true) {

		for (int i = 0; i < N; i++) {

			for (int j = 0; j < N; j++) {

				cout << field[k++] << ' ';

			}

			cout << endl;

		}

		ifFound = true;

		cout << "\nБыл показан один вариант. Желаете увидеть остальные?\n1)Да\n2)Выход\n";

		field.~vector(); vertical.~vector(); diagonalUp.~vector(); diagonalDown.~vector();

		vector<int> field(N * N, 0);

		vector<int> vertical(N * N, 0);

		vector<int> diagonalUp(N * N, 0);

		vector<int> diagonalDown(N * N, 0);

		int q; cin >> q; cout << "\n"; count = 0;

		if (q == 1) AllCombinationsArrangementOfQueensRecurs(field, vertical, diagonalUp, diagonalDown, count, N, ifFound);

		else system("cls");

		field.~vector(); vertical.~vector(); diagonalUp.~vector(); diagonalDown.~vector();

	}

	else cout << "Решений нет\n";
}


bool ArrangementOfQueensRecurs(vector<int>& field, vector<int>& vertical, vector<int>& diagonalUp, vector<int>& diagonalDown, int& count, int size) {

	if (count == size) { //если количество собранных строк равно размерности

		return true;

	}



	vector<int> step(size, 0); //текущий ряд

	for (int i = 0; i < size; i++) {

		if (vertical[count * size + i] >= 1 || diagonalDown[count * size + i] >= 1 || diagonalUp[count * size + i] >= 1) step[i] = 1;

	}



	bool end;

	int j(0);



	for (int i = count * size; i < (count + 1) * size; i++) {

		if (step[j++] == 0) {

			NextStep(field, vertical, diagonalUp, diagonalDown, count, size, i);

			end = ArrangementOfQueensRecurs(field, vertical, diagonalUp, diagonalDown, count, size);

			if (end == false) {

				PreviewStep(field, vertical, diagonalUp, diagonalDown, count, size, i);

			}

			else {

				return true;

			}

		}

	}



	return false;

}


void NextStep(vector<int>& field, vector<int>& vertical, vector<int>& diagonalUp, vector<int>& diagonalDown, int& count, int size, int index)

{

	field[index] = -1;

	for (int i = index; i < size * size; i += size) {

		vertical[i] += 1;

	}

	bool ifBarrier(false);

	if ((index % size) != 0) { //проверка на нахождение у стенки слева

		for (int i = index; i < size * size; i += (size - 1)) {

			if (ifBarrier == false) diagonalUp[i] += 1;

			if ((i != index) && ((i % size) == 0)) ifBarrier = true; //проверка, не уткнулась ли диагональ в стенку

		}

	}

	ifBarrier = false;

	if ((index + 1) % size != 0) {//проверка на нахождение у стенки справа

		for (int i = index; i < size * size; i += (size + 1)) {

			if (ifBarrier == false) diagonalDown[i] += 1;

			if ((i != index) && ((i + 1) % size == 0)) ifBarrier = true;

		}

	}

	count++;

}


void PreviewStep(vector<int>& field, vector<int>& vertical, vector<int>& diagonalUp, vector<int>& diagonalDown, int& count, int size, int index)

{

	field[index] = 0;

	for (int i = index; i < size * size; i += size) {

		vertical[i] -= 1;

	}

	bool ifBarrier(false);

	if ((index % size) != 0) { //проверка на нахождение у стенки слева

		for (int i = index; i < size * size; i += (size - 1)) {

			if (ifBarrier == false) diagonalUp[i] -= 1;

			if ((i != index) && ((i % size) == 0)) ifBarrier = true; //проверка, не уткнулась ли диагональ в стенку

		}

	}

	ifBarrier = false;

	if ((index + 1) % size != 0) {//проверка на нахождение у стенки справа

		for (int i = index; i < size * size; i += (size + 1)) {

			if (ifBarrier == false) diagonalDown[i] -= 1;

			if ((i != index) && ((i + 1) % size == 0)) ifBarrier = true;

		}

	}

	count--;

}


bool AllCombinationsArrangementOfQueensRecurs(vector<int>& field, vector<int>& vertical, vector<int>& diagonalUp, vector<int>& diagonalDown, int& count, int size, bool& ifFound) {

	if (count == size) { //если количество собранных строк равно размерности

		if (ifFound == false) {

			int k(0);

			for (int i = 0; i < size; i++) {

				for (int j = 0; j < size; j++) {

					cout << field[k++] << ' ';

				}

				cout << endl;

			}

			cout << endl;

			return false;

		}

		ifFound = false;

		return false;

	}



	vector<int> step(size, 0); //текущий ряд

	for (int i = 0; i < size; i++) {

		if (vertical[count * size + i] >= 1 || diagonalDown[count * size + i] >= 1 || diagonalUp[count * size + i] >= 1) step[i] = 1;

	}



	bool end;

	int j(0);



	for (int i = count * size; i < (count + 1) * size; i++) {

		if (step[j++] == 0) {

			NextStep(field, vertical, diagonalUp, diagonalDown, count, size, i);

			end = AllCombinationsArrangementOfQueensRecurs(field, vertical, diagonalUp, diagonalDown, count, size, ifFound);

			if (end == false) {

				PreviewStep(field, vertical, diagonalUp, diagonalDown, count, size, i);

			}

			else {

				return true;

			}

		}

	}



	return false;

}
