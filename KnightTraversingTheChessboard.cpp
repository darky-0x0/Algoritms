#include "KnightTraversingTheChessboard.h"



const int rateKnight[8][2] = { {-2, 1},{-1, 2},{1, 2},{2, 1},{2, -1},{1, -2},{-1, -2},{-2, -1} };


void lab4task5() {

	cout << "Выберите подзадачу: \n1) Найти один способ обхода конем доски N×M. Конь должен побывать на каждой клетке доски только один раз. Начальная позиция коня определяется случайным образом. Использовать правило Варнсдорфа. \n2) Для каждого начального расположения коня найти количество способов обхода доски.\n";

	int taskNum; cin >> taskNum;

	system("cls");

	cout << "Введите размерность шахматного поля N x M: \n";

	int N, M; cin >> N >> M;

	system("cls");

	int** field = new int* [N + 4];

	for (int i = 0; i < N + 4; i++) {

		field[i] = new int[M + 4];

		for (int j = 0; j < M + 4; j++) {

			if ((i < 2) || (i >= N + 2)) {

				field[i][j] = -1;

			}
			else {

				if (j < 2 || (j >= M + 2)) {

					field[i][j] = -1;

				}
				else {

					field[i][j] = 0;

				}
			}
		}

	}


	if (taskNum == 1) {

		srand((unsigned int)time(NULL));

		int ri = rand() % N + 2;

		int rj = rand() % M + 2;

		vector<int> position = { ri, rj };

		cout << "Индекс коня: " << ri - 2 << " " << rj - 2 << "\n\n";

		vector<int> result;

		result.push_back(position[0]);
		result.push_back(position[1]);

		field[ri][rj] = 1;

		KnightTraversingTheChessboard(field, N, M, position, result);

		for (int i = 2; i < N + 2; i++) {

			for (int j = 2; j < M + 2; j++) {

				cout << field[i][j] << " ";

			}

			cout << "\n";

		}

	}
	else {

		vector<int> tempResult;

		vector<vector<int>> tempResult2;

		for (int i = 2; i <= ((N + 2) + 1) / 2; i++) {

			for (int j = 2; j <= ((M + 2) + 1) / 2; j++) {

				int result(0);

				vector<int> position = { i, j };

				field[i][j] = 1;

				KnightTraversingTheChessboard(field, N, M, position, result);

				field[i][j] = 0;

				tempResult.push_back(result);

				cout << result << " ";

			}

			for (int i = M / 2 - 1; i >= 0; i--) {

				tempResult.push_back(tempResult[i]);

				cout << tempResult[i] << " ";

			}

			tempResult2.push_back(tempResult);

			tempResult.clear();

			cout << "\n";

		}


		for (int i = N / 2 - 1; i >= 0; i--) {

			tempResult = tempResult2[i];

			for (int j = 0; j < M; j++) {

				cout << tempResult[j] << " ";

			}

			cout << "\n";

		}

	}

}


void KnightTraversingTheChessboard(int** field, int N, int M, vector<int> position, vector<int>& result) {

	if (getEmptyCells(field, N, M) == 0) {

		int ind(0);

		cout << "\nПуть коня: ";

		for (int i = 0; i < result.size() / 2; i++) { //вывод пути

			cout << "(" << result[ind++] - 2 << ";";
			cout << result[ind++] - 2 << ") ";

		}

	}
	else {

		field[position[0]][position[1]] = 1; //отмечаем на поле

		vector<int> counter;

		for (int i = 0; i < 8; i++) {

			vector<int> newPosition = { position[0] + rateKnight[i][0], position[1] + rateKnight[i][1] };

			if (field[newPosition[0]][newPosition[1]] == 0) {

				counter.push_back(countingSteps(field, N, M, newPosition)); //cохраняем массив с количеством ходов

			}

			else counter.push_back(9); //запоняем бессмысленные поля;

		}

		int minSteps = *min_element(counter.begin(), counter.end()); //находим минимальный элемент вектора

		int minStepsIndex;

		int tempCounter(0); //для подсчёта, остлись ли пути

		for (int i = 0; i < 8; i++) if (counter[i] == minSteps) {

			minStepsIndex = i;

			tempCounter++;

		}

		if (tempCounter == 8 && counter[0] == 9) {

			cout << "Обход всего поля с данной позиции и поля данной размерности и данным способом невозможен";

		}
		else {

			position = { position[0] + rateKnight[minStepsIndex][0], position[1] + rateKnight[minStepsIndex][1] }; //запоминаем шаг

			field[position[0]][position[1]] = 1;

			result.push_back(position[0]);
			result.push_back(position[1]);

			KnightTraversingTheChessboard(field, N, M, position, result);

		}

	}

}

int countingSteps(int** field, int N, int M, vector<int> position)
{
	int counter(0);

	for (int i = 0; i < 8; i++) {

		vector<int> newPosition = { position[0] + rateKnight[i][0], position[1] + rateKnight[i][1] };

		if (field[newPosition[0]][newPosition[1]] == 0) counter++;

	}

	return counter;

}

int getEmptyCells(int** field, int N, int M) {

	int counter(0);

	for (int i = 0; i < N + 4; i++) {

		for (int j = 0; j < M + 4; j++) {

			if (field[i][j] == 0) counter++;

		}

	}

	return counter;

}

void KnightTraversingTheChessboard(int** field, int N, int M, vector<int> position, int& result) {

	if (getEmptyCells(field, N, M) == 0) {

		result++;

	}
	else {

		field[position[0]][position[1]] = 1; //отмечаем на поле

		vector<int> counter;

		for (int i = 0; i < 8; i++) {

			vector<int> newPosition = { position[0] + rateKnight[i][0], position[1] + rateKnight[i][1] };


			if (field[newPosition[0]][newPosition[1]] == 0) {

				field[newPosition[0]][newPosition[1]] = 1;

				KnightTraversingTheChessboard(field, N, M, newPosition, result);

				field[newPosition[0]][newPosition[1]] = 0;

			}


		}

	}

}