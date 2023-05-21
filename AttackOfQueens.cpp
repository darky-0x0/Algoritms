#include "AttackOfQueens.h"


void lab4task4() {

	int n, p, queensCount(0), thisStep(0), size, count(1);

	cout << "Введите размерность шахматной доски: ";

	cin >> n;

	size = n * n;

	cout << "Введите количество нападений ферзей: ";

	cin >> p;

	system("cls");

	vector<int> MainField(size, 0), queensField(size, 0), result(size, 0);

	time_t timeTask12Start = clock();

	AttackOfQueens(p, n, MainField, queensField, result, queensCount, thisStep, size, count);

	time_t timeTask12End = clock();

	int countVector(0);

	bool ifFinal(false);

	cout << "\n\n";

	for (int i = 0; i < size; i++) {

		if (result[i] != 0) ifFinal = true;

	}

	if (ifFinal == true) {

		for (int i = 0; i < n; i++) {

			for (int j = 0; j < n; j++) {

				cout << result[countVector++] << ' ';

			}

			cout << '\n';

		}

	}

	else cout << "Такого случая нет";

	cout << "\nВ общем случае потрачено " << ((double)(timeTask12End - timeTask12Start) / CLOCKS_PER_SEC) << "с\n";

}


void AttackOfQueens(const int p, const int n, vector<int>& MainField, vector<int>& queensField, vector<int>& result, int& QueensCount, int thisStep, int size, int count) {

	for (int i = thisStep; i < n * n; i++) {

		time_t start = clock();

		NextStep(MainField, queensField, i, size, n); //шаг вперёд

		int tempQueensCount(0);

		int numberTrueField(0);

		bool flag(true);

		for (int j = 0; (j < size) && (flag == true); j++) {

			if (queensField[j] == 1) {

				tempQueensCount++;

				if (MainField[j] == p) numberTrueField++;

				else if (MainField[j] > p) flag = false;

			}

		}

		if ((numberTrueField == tempQueensCount) && (QueensCount < tempQueensCount)) {

			QueensCount = tempQueensCount;

			for (int i = 0; i < size; i++) {

				result[i] = queensField[i];

			}

		}

		if (flag == true) {

			AttackOfQueens(p, n, MainField, queensField, result, QueensCount, i + 1, size, count + 1);

		}

		PreviewStep(MainField, queensField, i, size, n); //шаг назад



		time_t end = clock();

		if ((count == 1) && (i == 0)) cout << "На выполнение программы~" << (((double)(end - start) / CLOCKS_PER_SEC) / 16.5f * 100) << "с\n\n";

		if (count == 1) cout << (double)(100 / size) * (i + 1) << "%\n";

	}
}

void NextStep(vector<int>& field, vector<int>& queensField, int index, int size, int n)
{

	queensField[index] = 1;

	//вертикали

	for (int i = index + n; i < size; i += n) {

		field[i]++;

	}

	for (int i = index - n; i >= 0; i -= n) {

		field[i]++;

	}

	//диагональ

	bool ifBarrier(false);

	for (int i = index; (i >= 0) && (ifBarrier == false); i -= (n + 1)) { //вверх влево

		if (i != index) field[i]++;

		if ((i % n) == 0) ifBarrier = true; //проверка, не уткнулась ли диагональ в стенку

	}

	ifBarrier = false;

	for (int i = index; (i >= 0) && (ifBarrier == false); i -= (n - 1)) { //вверх вправо

		if (i != index) field[i]++;

		if (((i + 1) % n) == 0) ifBarrier = true;

	}

	ifBarrier = false;

	for (int i = index; (i < size) && (ifBarrier == false); i += (n - 1)) { //вниз влево

		if (i != index) field[i]++;

		if ((i % n) == 0) ifBarrier = true;

	}

	ifBarrier = false;

	for (int i = index; (i < size) && (ifBarrier == false); i += (n + 1)) { //вниз вправо

		if (i != index) field[i]++;

		if (((i + 1) % n) == 0) ifBarrier = true;

	}

	for (int i = index - (index % n); i < index - (index % n) + n; i++) { //

		if (i != index) field[i]++;

	}
}

void PreviewStep(vector<int>& field, vector<int>& queensField, int index, int size, int n)

{

	queensField[index] = 0;

	//вертикали

	for (int i = index + n; i < size; i += n) {

		field[i]--;

	}

	for (int i = index - n; i >= 0; i -= n) {

		field[i]--;

	}

	//диагональ

	bool ifBarrier(false);

	for (int i = index; (i >= 0) && (ifBarrier == false); i -= (n + 1)) { //вверх влево

		if (i != index) field[i]--;

		if ((i % n) == 0) ifBarrier = true; //проверка, не уткнулась ли диагональ в стенку

	}

	ifBarrier = false;

	for (int i = index; (i >= 0) && (ifBarrier == false); i -= (n - 1)) { //вверх вправо

		if (i != index) field[i]--;

		if (((i + 1) % n) == 0) ifBarrier = true;

	}

	ifBarrier = false;

	for (int i = index; (i < size) && (ifBarrier == false); i += (n - 1)) { //вниз влево

		if (i != index) field[i]--;

		if ((i % n) == 0) ifBarrier = true;

	}

	ifBarrier = false;

	for (int i = index; (i < size) && (ifBarrier == false); i += (n + 1)) { //вниз вправо

		if (i != index) field[i]--;

		if (((i + 1) % n) == 0) ifBarrier = true;

	}

	for (int i = index - (index % n); i < index - (index % n) + n; i++) { //

		if (i != index) field[i]--;

	}
}


