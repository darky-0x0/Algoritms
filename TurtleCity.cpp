#include "TurtleCity.h"




void lab6task1() {

	string fileName = "TurtleCity.txt";

	

	vector<vector<int>> fieldValue;

	vector<vector<pair<int, int>>> resultField; //пара <значение, данные о ходе>

	pair<int, int> size;

	fileRead(fieldValue, resultField, size, fileName);

	pair<int, int> startPosition(1, 1);
	pair<int, int> endPosition(size.first * 2 - 1, size.second * 2 - 1);

	cout << "Данные были взяты из файла\nБыло выведено 2 поля: поле с изначальными значениями \\ поле с конечными подсчитанными углами\nОбъяснение для первого поля: \n\t- Х - дороги перекрыты или их не существует; \n\t- в местах перекрёстков указаны стоимости поворотов.\nОбъяснение для вторго поля: \n\t- Т - дороги перекрыты.\n\nПоле изначальных значений:\t\t\tРезультаты:\n";

	turtleCity(fieldValue, resultField, size);
	
	printField(fieldValue, resultField, size);

	cout << "\n\nМинимальная стоимость для черепахи: " << resultField[endPosition.first][endPosition.second].first;

	printPath(resultField, startPosition, endPosition, size);

}


void turtleCity(vector<vector<int>>& fieldValue, vector<vector<pair<int, int>>>& resultField, pair<int, int>size) {

	for (int i = 1; i < size.first * 2; i += 2) {

		for (int j = 1; j < size.second * 2; j += 2) {

			if (!(i == 1 && j == 1)) { //избегая начальную клетку

				int trav; //направление/откуда был совершён ход (0 - ход был совершён по горизонтальной улице, 1 - по вертикальной)

				int sumX(-1), sumY(-1), *minSum(0);


				if (fieldValue[i - 1][j] == -1 && fieldValue[i][j - 1] == -1) resultField[i][j].first = -1; //если в клетку никак не попасть 
				else {


					if (fieldValue[i - 1][j] != -1) { //смотрим возможность попадания сверху. Если оно не -1, считаем сумму проезда

						sumY = resultField[i - 2][j].first + fieldValue[i - 1][j]; //к прошлому перекрёстку добавляем стоимость дороги

						if (!(i - 2 == 1 && j == 1)) { //избегаем начальную клетку, у которой нет направления

							if (resultField[i - 2][j].second == 0) sumY += fieldValue[i - 2][j]; //если прошлый путь предполагал движение по горизонтали, добавляем стоимость поворота на прошлом перекрёстке

						}

					}
					else {

						minSum = &sumX; //присваиваем указателю ссылку на сумму по X
						trav = 0; //горизонтальный ход (по Х)

					}

					if (fieldValue[i][j - 1] != -1) { //смотрим возможность попадания сверху. Если оно не -1, считаем сумму прозда

						sumX = resultField[i][j - 2].first + fieldValue[i][j - 1]; //к прошлому перекрёстку добавляем стоимость дороги

						if (!(i - 2 == 1 && j == 1)) { //избегаем начальную клетку, которая не имеет прошлого направления

							if (resultField[i][j - 2].second == 1) sumX += fieldValue[i][j - 2]; //если прошлый путь предполагал движение по вертикали, добавляем стоимость поворота на прошлом перекрёстке

						}

					}
					else {

						minSum = &sumY; //присваиваем указателю ссылку на сумму по Y
						trav = 1; //вертикальный ход (по Y)

					}


					if (sumY == -1 || sumX == -1) { //если существует только один ход

						resultField[i][j].first = *minSum; 
						resultField[i][j].second = trav;

					}
					else { //иначе существует два хода

						if (sumX < sumY) { //по горизонтали ход дешевле, чем по вертикали

							resultField[i][j].first = sumX;
							resultField[i][j].second = 0;

						}
						else { //иначе...

							resultField[i][j].first = sumY;
							resultField[i][j].second = 1;

						}

					}

				}


			}

		}

	}

}


void fileRead(vector<vector<int>>& fieldValue, vector<vector<pair<int, int>>>& resultField, pair<int, int>& size, string fileName) {

	ifstream file;
	file.open(fileName);

	file >> size.first >> size.second;

	vector<vector<int>> fieldTEMP(size.first*2-1, vector<int>(size.second * 2 - 1, -1)); //формируем главный массив
	vector<pair<int, int>> line(size.second * 2 - 1, pair<int, int>(-1, -1));
	vector<vector<pair<int, int>>> resultTEMP(size.first*2-1, line); //формируем массив результатов

	for (int i = 0; i < size.first * 2 - 1; i += 2) { //переносим горизонтальные значения

		for (int j = 1; j < size.second * 2 - 1; j += 2) {

			file >> fieldTEMP[i][j];

		}

	}

	for (int i = 0; i < size.second * 2 - 1; i += 2) { //переносим вертикальные значения

		for (int j = 1; j < size.first * 2 - 1; j += 2) {

			file >> fieldTEMP[j][i];

		}

	}

	for (int i = 0; i < size.first * 2 - 1; i += 2) { //переносим значения на перекрёстках

		for (int j = 0; j < size.second * 2 - 1; j += 2) {

			file >> fieldTEMP[i][j];

			resultTEMP[i][j].first = 0;

		}

	}


	file.close();


	vector<vector<int>> fieldTEMP2(size.first * 2 + 1, vector<int>(size.second * 2 + 1, -1)); //создаём главный массив с "подушкой безопасности"
	vector<pair<int, int>> line2(size.second * 2 + 1, pair<int, int>(-1, -1));
	vector<vector<pair<int, int>>> resultTEMP2(size.first * 2 + 1, line2); //создаём массив с результатами с "подушкой безопасности"

	for (int i = 1; i < size.first*2; i++) {

		for (int j = 1; j < size.second*2; j++) {

			fieldTEMP2[i][j] = fieldTEMP[i - 1][j - 1];
			resultTEMP2[i][j].first = resultTEMP[i - 1][j - 1].first;

		}

	}

	resultField = resultTEMP2;
	fieldValue = fieldTEMP2;

}


void printField(vector<vector<int>>& fieldValue, vector<vector<pair<int, int>>>& resultField, pair<int, int> size) {

	for (int i = 1; i < size.first * 2; i++) {

		for (int j = 1; j < size.second * 2; j++) {

			if (fieldValue[i][j] == -1) cout << "X";

			else cout << fieldValue[i][j];

			if ((j != size.second * 2 - 1) && (i % 2 == 1)) cout << " - ";
			else if (i % 2 == 0) cout << "   ";

		}



		cout << "\t\t\t";

		for (int j = 1; j < size.second * 2; j++) {

			if ((i % 2 != j % 2) && (fieldValue[i][j] == -1)) cout << "T";

			else if (resultField[i][j].first == -1) cout << "X";

			else cout << resultField[i][j].first;

			if ((j != size.second * 2 - 1) && (i % 2 == 1)) cout << " - ";
			else if (i % 2 == 0) {

				if (j % 2 == 0) cout << "    ";
				else cout << "   ";

			}

		}



		if (i != size.first * 2 - 1) {

			cout << "\n";
			for (int i = 1; i < size.second; i++) cout << "|       ";
			cout << "|";

		}



		
		if (i != size.first * 2 - 1) {

			cout << "\t\t\t";
			for (int i = 1; i < size.second; i++) cout << "|        ";
			cout << "|\n";

		}

	}

}


void printPath(vector<vector<pair<int, int>>> resultField, pair<int, int> startPosition, pair<int, int> endPosition, pair<int, int> size) {

	vector<pair<int, int>> path;

	int X(size.second), Y(size.first); //координаты графика

	bool isEnd = false;

	while (isEnd == false) {

		path.push_back(pair<int, int>(Y, X));

		if (resultField[endPosition.first][endPosition.second].second == 0) { //проверяем направление

			endPosition.second -= 2;
			X--; //выполняем смещение

		}
		else if (resultField[endPosition.first][endPosition.second].second == 1) {

			endPosition.first -= 2;
			Y--;

		}
		else isEnd = true;

	}

	cout << "\nПуть: ";

	for (int i = path.size() - 1; i >= 0; i--) {

		cout << "(" << path[i].first << ":" << path[i].second << ") ";

	}

}
