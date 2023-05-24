#include "ArrangementOfMagaraja.h"



const int rateKnight[8][2] = { {-2, 1},{-1, 2},{1, 2},{2, 1},{2, -1},{1, -2},{-1, -2},{-2, -1} };


void lab4task6() {

	int N = 10;


	int count(0);

	vector<int> field(N * N, 0);

	vector<int> vertical(N * N, 0);

	vector<int> diagonalUp(N * N, 0);

	vector<int> diagonalDown(N * N, 0);

	vector<int> knight(N * N, 0);



	ArrangementOfMagaraja(field, vertical, diagonalUp, diagonalDown, knight, count, N);

}


void ArrangementOfMagaraja(vector<int>& field, vector<int>& vertical, vector<int>& diagonalUp, vector<int>& diagonalDown, vector<int>& knight, int& count, int size) {


	if (count == size) { //если количество собранных строк равно размерности

		int k(0);

		for (int i = 0; i < 10; i++) {

			for (int j = 0; j < 10; j++) {

				cout << field[k++] << " ";

			}

			cout << "\n";

		}

		cout << "\n\n";

	}
	else {

		vector<int> step(size, 0); //текущий ряд

		for (int i = 0; i < size; i++) {

			if (vertical[count * size + i] >= 1 || diagonalDown[count * size + i] >= 1 || diagonalUp[count * size + i] >= 1 || knight[count * size + i] >= 1) step[i] = 1;

		}

		int j(0);

		for (int i = count * size; i < (count + 1) * size; i++) {

			if (step[j++] == 0) {

				vector<int> indexes;

				NextStep1(field, vertical, diagonalUp, diagonalDown, count, size, i);

				NextStepKnight(knight, i, indexes);

				ArrangementOfMagaraja(field, vertical, diagonalUp, diagonalDown, knight, count, size);

				PreviewStep1(field, vertical, diagonalUp, diagonalDown, count, size, i);

				PreviewStepKnight(indexes, knight);

			}

		}

	}

}

void NextStepKnight(vector<int>& knight, int index, vector<int>& indexes) {

	for (int i = 0; i < 8; i++) {

		if ((index < 10) && ((i == 0) || (i == 1) || (i == 6) || (i == 7))) continue;

		if ((index < 20) && ((i == 0) || (i == 7))) continue;

		if ((index > 89) && ((i == 3) || (i == 4))) continue;

		if ((index > 79) && ((i == 2) || (i == 3) || (i == 4) || (i == 5))) continue;

		if ((index % 10 == 0) && ((i == 4) || (i == 5) || (i == 6) || (i == 7))) continue;

		if ((index % 10 == 1) && ((i == 5) || (i == 6))) continue;

		if ((index % 10 == 9) && ((i == 0) || (i == 1) || (i == 2) || (i == 3))) continue;

		if ((index % 10 == 8) && ((i == 1) || (i == 2))) continue;

		int newIndex = index + (rateKnight[i][0] * 10) + rateKnight[i][1];

		if ((newIndex >= 0) && (newIndex < 100)) {



			knight[newIndex]++;

			indexes.push_back(newIndex);

		}

	}
}

void PreviewStepKnight(vector<int> indexes, vector<int>& knight) {

	for (int i = 0; i < indexes.size(); i++) {
		knight[indexes[i]]--;
	}

}

void NextStep1(vector<int>& field, vector<int>& vertical, vector<int>& diagonalUp, vector<int>& diagonalDown, int& count, int size, int index)

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

void PreviewStep1(vector<int>& field, vector<int>& vertical, vector<int>& diagonalUp, vector<int>& diagonalDown, int& count, int size, int index)

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

