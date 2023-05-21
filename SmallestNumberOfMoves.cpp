#include "SmallestNumberOfMoves.h"




void lab4task3() {

	cout << "Введите размерность шахматной доски: "; int n; cin >> n;

	vector<int> MainField(n * n, 0);

	vector<int> queensIndexes;

	vector<int> result(2 * n, 0);

	int minMoves(2 * n);

	int countMoves(0);

	int fields = 0;

	system("cls");

	SmallestNumberOfMoves(minMoves, countMoves, MainField, queensIndexes, result, n);

	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}

	cout << "\nМинимум " << result.size() - 1 << " ходов\n";

}


void SmallestNumberOfMoves(int& minMoves, int& countMoves, vector<int>& MainField, vector<int>& queensIndexes, vector<int>& result, int size, int currentDirection, int pos, int n) {

	if (!GetEmpty(MainField)) { //если прошли всё поле (нет пустых клеток)

		//запоминаем результат
		result = queensIndexes;
		minMoves = countMoves;

	}

	else {

		if (n == 0) {
			//рекурсия

			vector<int> mainCells(MainField.size(), 0);

			int tempFieldSize(size);

			if (size % 2 == 0) tempFieldSize /= 2;
			else tempFieldSize = tempFieldSize / 2 + 1;


			//берём 1/4 поля, так как все части идентичны
			for (int i = 0; i < tempFieldSize; i++) {

				for (int j = 0; j < tempFieldSize; j++) {

					mainCells[i * size + j] = 1;

				}

			}

			for (int i = 0; i < MainField.size(); i++) {

				if (mainCells[i] == 1) {

					cout << "начало\n";

					queensIndexes.push_back(i); //заход

					SmallestNumberOfMoves(minMoves, countMoves, MainField, queensIndexes, result, size, currentDirection, i, n + 1);

					queensIndexes.erase(queensIndexes.end() - 1); // откат

					cout << "конец\n";

				}

			}

		}

		else {
			vector<int> tempSteps(MainField.size(), 0); //вектор текущих шагов

			//считаем возможные шаги
			NextStep(tempSteps, pos);

			vector<int> directions(8, 0);

			int a;
			int b;
			int k;

			if (n % 2 == 1) {
				a = MainField.size() - 1;
				b = -1;
				k = -1;
			}
			else {
				a = 0;
				b = MainField.size();
				k = 1;
			}

			//записываем прошлое направление
			int lastDirection = currentDirection;

			//цикл (перебираем поле с возможными шагами) с наибольшим ходом
			for (int i = a; (i > b) || (i < b); i += k) {

				bool isQueenIndex(false);

				//проверка, является ли текущий индекс уже пройденным
				for (int t = 0; t < queensIndexes.size(); t++) if (queensIndexes[t] == i) isQueenIndex = true;

				//заходим в случае, если клетка - путь, и она не повторяет прошлое направление и не совершает ход назад
				if ((tempSteps[i] != 0) && (isQueenIndex == false) && ((lastDirection == 0) || (tempSteps[i] != lastDirection) && (tempSteps[i] != (((lastDirection + 3) % 8) + 1)))) {

					//считаем число ходов для каждого направления
					if (i < pos) {

						for (int j = pos; j >= i; j--) if (tempSteps[j] == tempSteps[i]) directions[tempSteps[i] - 1]++;

					}
					else {

						for (int j = pos; j <= i; j++) if (tempSteps[j] == tempSteps[i]) directions[tempSteps[i] - 1]++;

					}

					//последнее направление
					currentDirection = tempSteps[i];

					int countEmpty = GetEmpty(MainField);
					//если клетка доступна для хода																											|
					//если текущее количество шагов превышает рекордно-минимальное или нет новых битых клеток: шаг назад; продолжить						V		
					if ((minMoves > countMoves + 1) && (minMoves - countMoves - 1 < 2 * ((int)sqrt(countEmpty - directions[tempSteps[i] - 1]) + 1))) {
						int beforeEmpty = countEmpty;

						vector<int> oneStep; //вектор, содержащий 1 ход

						//делаем шаг на возможную позицию
						oneStep = Step(MainField, pos, i, size); //запоминаем сделанный ход

						//отмечаем ход ферьзя
						queensIndexes.push_back(i);

						countMoves++;

						if (beforeEmpty == GetEmpty(MainField)) {

							PreviewStep(MainField, oneStep);
							queensIndexes.erase(queensIndexes.end() - 1); //откат в случае неудачного хода
							countMoves--;
							continue;

						}

						//рекурсия
						SmallestNumberOfMoves(minMoves, countMoves, MainField, queensIndexes, result, size, currentDirection, i, n + 1);

						queensIndexes.erase(queensIndexes.end() - 1); //откат в случае неудачного хода

						countMoves--;

						//шаг назад
						PreviewStep(MainField, oneStep);

					}

				}

			}

		}

	}

}

void NextStep(vector<int>& field, int index)
{



	int n = sqrt(field.size());

	int size = field.size();

	//вертикали

	for (int i = index + n; i < size; i += n) {

		field[i] += 5;

	}

	for (int i = index - n; i >= 0; i -= n) {

		field[i] += 1;

	}

	//диагональ

	bool ifBarrier(false);

	for (int i = index; (i >= 0) && (ifBarrier == false); i -= (n + 1)) { //вверх влево

		if (i != index) field[i] += 8;

		if ((i % n) == 0) ifBarrier = true; //проверка, не уткнулась ли диагональ в стенку

	}

	ifBarrier = false;

	for (int i = index; (i >= 0) && (ifBarrier == false); i -= (n - 1)) { //вверх вправо

		if (i != index) field[i] += 2;

		if (((i + 1) % n) == 0) ifBarrier = true;

	}

	ifBarrier = false;

	for (int i = index; (i < size) && (ifBarrier == false); i += (n - 1)) { //вниз влево

		if (i != index) field[i] += 6;

		if ((i % n) == 0) ifBarrier = true;

	}

	ifBarrier = false;

	for (int i = index; (i < size) && (ifBarrier == false); i += (n + 1)) { //вниз вправо

		if (i != index) field[i] += 4;

		if (((i + 1) % n) == 0) ifBarrier = true;

	}

	for (int i = index; i < index - (index % n) + n; i++) { //горизонтали

		if (i != index) field[i] += 3;

	}

	for (int i = index; i >= index - (index % n); i--) { //горизонтали

		if (i != index) field[i] += 7;

	}


}

vector<int> Step(vector<int>& field, int startInd, int pos, int n) {

	vector<int> oneStep(n * n, 0);

	if (pos > startInd) {

		if (pos % n == startInd % n) { //вертикаль

			for (int i = startInd; i <= pos; i += n) {
				field[i]++;
				oneStep[i]++;
			}

		}
		else if (pos < ((startInd / n) + 1) * n) { //горизонталь

			for (int i = startInd; i <= pos; i++) {
				field[i]++;
				oneStep[i]++;
			}

		}
		else if (pos % n < startInd % n) { //диагональ вниз-влево

			for (int i = startInd; i <= pos; i += (n - 1)) {
				field[i]++;
				oneStep[i]++;
			}

		}
		else { //диагональ вниз-вправо

			for (int i = startInd; i <= pos; i += (n + 1)) {
				field[i]++;
				oneStep[i]++;
			}

		}

	}
	else {

		if (pos % n == startInd % n) { //вертикаль

			for (int i = startInd; i >= pos; i -= n) {
				field[i]++;
				oneStep[i]++;
			}

		}
		else if (pos >= (startInd / n) * n) { //горизонталь

			for (int i = startInd; i >= pos; i--) {
				field[i]++;
				oneStep[i]++;
			}

		}
		else if (pos % n < startInd % n) { //диагональ вверх-влево

			for (int i = startInd; i >= pos; i -= (n + 1)) {
				field[i]++;
				oneStep[i]++;
			}

		}
		else { //диагональ вверх-вправо

			for (int i = startInd; i >= pos; i -= (n - 1)) {
				field[i]++;
				oneStep[i]++;
			}

		}

	}

	return oneStep;

}

void PreviewStep(vector<int>& field, vector<int> oneStep) {

	for (int i = 0; i < oneStep.size(); i++) {

		if (oneStep[i]) field[i]--;

	}

}

int GetEmpty(vector<int> mainField) {

	int count = 0;

	for (int i = 0; i < mainField.size(); ++i) {

		if (!mainField[i]) {

			count++;

		}

	}

	return count;
}