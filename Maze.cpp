#include "Maze.h"




const int steps[4][2] = { {-1, 0},{0, 1},{1, 0},{0, -1} };

bool isEndMaze = false;

void lab5task1() {

	string fileName = "Maze2.txt";



	vector<vector<int>> field;

	pair<int, int> size; //размер поля
	
	pair<int, int> startPosition; //стартовая позиция
	
	pair<int, int> endPosition; //конечная позиция

	int count(2); //количество ходов

	int minCount(0);

	readFile(field, size, startPosition, endPosition, fileName);

	vector<vector<int>> result(field); //результат поле

	pair<int, int> position(startPosition); //текущая позиция

	cout << "Изначальное поле: \n";

	printField(field, size, startPosition, endPosition);

	_getch();

	field[startPosition.first][startPosition.second] = 1; //ставим начальную позицию

	maze(field, size, position, startPosition, endPosition, result, count, minCount);

	if (isEndMaze == true) {

		cout << "\n\nВыход из лабиринта: \n";

		printField(result, size, startPosition, endPosition);

		cout << "\nХодов необходимо: " << minCount - 2;

	}
	else cout << "\nПутей из лабиринта нет\n";

	isEndMaze = false;

}


void maze(vector<vector<int>>& field, pair<int, int>& size, pair<int, int>& position, pair<int, int> startPosition, pair<int, int> endPosition, vector<vector<int>>& result, int count, int& minCount) {

	if ((position.first == endPosition.first) && (position.second == endPosition.second)) {

		isEndMaze = true;

		result = field;

		minCount = count;

	}
	else {

		//если текущий путь (+ следующий ход) не равен минимальному. Если путь уже равен минимальному и мы не дошли до выхода, то дальше нет смысла смотреть
		if (count+1 != minCount) {

			for (int i = 0; i < 4; i++) {

				pair<int, int> newIndex; //новый индекс

				newIndex.first = position.first + steps[i][0];

				newIndex.second = position.second + steps[i][1];

				if (field[newIndex.first][newIndex.second] == 0) {

					//шаг вперёд
					nextStep(field, size, newIndex, count);

					//рекурсия
					maze(field, size, newIndex, startPosition, endPosition, result, count + 1, minCount);

					//шаг назад
					previewStep(field, size, newIndex);

				}

			}

		}

	}

}


void nextStep(vector<vector<int>>& field, pair<int, int> size, pair<int, int> newIndex, int count) {

	field[newIndex.first][newIndex.second] = count;

}


void previewStep(vector<vector<int>>& field, pair<int, int>  size, pair<int, int> newIndex) {

	field[newIndex.first][newIndex.second] = 0;

}


void printField(vector<vector<int>> field, pair<int, int> size, pair<int, int> startPosition, pair<int, int> endPosition) {

	for (int i = 1; i < size.first - 1; i++) {

		for (int j = 1; j < size.second - 1; j++) {

			if (i == startPosition.first && j == startPosition.second) cout << "S\t";

			else if (i == endPosition.first && j == endPosition.second) cout << "E\t";

			else if (field[i][j] == -1) cout << " - \t";

			else cout << field[i][j] << "\t";

		}

		cout << "\n";

	}

}


void readFile(vector<vector<int>>& field, pair<int, int>& size, pair<int, int>& startPosition, pair<int, int>& endPosition, string fileName) {

	ifstream file;

	file.open(fileName);

	file >> size.first;

	file >> size.second;

	vector<int> line(size.second, 0);

	vector<vector<int>> fild(size.first, line);

	int cell;

	for (int i = 0; i < size.first; i++) {

		for (int j = 0; j < size.second; j++) {

			file >> cell;

			if (cell == -2) {

				startPosition.first = i;

				startPosition.second = j;

				fild[i][j] = 0;

			}
			else if (cell == -3) {

				endPosition.first = i;

				endPosition.second = j;

				fild[i][j] = 0;

			}
			else fild[i][j] = cell;

		}

	}

	field = fild;

	file.close();

}
