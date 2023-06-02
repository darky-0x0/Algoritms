#include "Sudoku.h"




bool isEndSudoku = false;

void lab5task4() {

	string fileName = "Sudoku3.txt";


	vector<vector<int>> field(9, vector<int>(9, 0)); //основное поле
	vector<pair<pair<int, int>, int>> emptyCells; //вектор с индексами и значениями пустых клеток

	fileRead(fileName, emptyCells, field);

	vector<pair<pair<int, int>, int>> result; //результат для сохранения пути
	int count(0); //счётчик ходов

	cout << "Изначальное поле: \n";
	printField(field, emptyCells);

	sudoku(field, emptyCells, result, count);

	_getch();

	if (isEndSudoku != true) {

		cout << "\nДанный судоку не имеет решения\n";
	
	}


	isEndSudoku = false;

}


void sudoku(vector<vector<int>> const field, vector<pair<pair<int, int>, int>>& emptyCells, vector<pair<pair<int, int>, int>>& result, int count) {

	if (count == emptyCells.size()) {

		isEndSudoku = true;

		printField(field, emptyCells);

	}
	else {

		vector<int> steps; //возможные шаги

		possibleSteps(steps, field, emptyCells, count);

		for (int i : steps) { //перебираем шаги

			emptyCells[count].second = i; //делаем шаг

			sudoku(field, emptyCells, result, count + 1);

			emptyCells[count].second = 0; //делаем шаг

		}

	}

}


void possibleSteps(vector<int>& steps, vector<vector<int>> const field, vector<pair<pair<int, int>, int>> const emptyCells, int count) {

	vector<int> numbers(10, 0); //для отметки, какие цифры уже имеются

	vector<vector<int>> resultTEMP(field); //общее поле

	for (int i = 0; i < emptyCells.size(); i++) {

		resultTEMP[emptyCells[i].first.first][emptyCells[i].first.second] = emptyCells[i].second; //переписываем в единое целое поле

	}

	int line(emptyCells[count].first.first);
	int column(emptyCells[count].first.second);
	
	//перебираем линию и столбец
	for (int i = 0; i < 9; i++) {

		numbers[resultTEMP[line][i]]++;

		numbers[resultTEMP[i][column]]++;

	}

	//получаем координаты маленького квадратика
	int lineLeft = (column / 3) * 3;
	int lineRight(lineLeft + 3);

	int columnUp = (line / 3) * 3;
	int columnDown(columnUp + 3);

	//перебираем маленький квадратик
	for (int i = columnUp; i < columnDown; i++) {

		for (int j = lineLeft; j < lineRight; j++) {

			numbers[resultTEMP[i][j]]++;	

		}

	}

	for (int i = 1; i < 10; i++) {

		if (numbers[i] == 0) steps.push_back(i); //если такая цифра не встречалась, добавляем в список возможных шагов

	}

}


void fileRead(string fileName, vector<pair<pair<int, int>, int>>& emptyCells, vector<vector<int>>& field) {

	ifstream file;
	file.open(fileName);
	int value;

	for (int i = 0; i < 9; i++) {

		for (int j = 0; j < 9; j++) {

			file >> value;

			field[i][j] = value;

			if (value == 0) {
				
				emptyCells.push_back(pair<pair<int,int>, int>(pair<int,int>(i, j), 0)); //запоминаем пустые клетки
			
			}

		}

	}

}

void printField(vector<vector<int>> field, vector<pair<pair<int, int>, int>> emptyCells) {

	vector<vector<int>> result(field);

	for (int i = 0; i < emptyCells.size(); i++) {

		result[emptyCells[i].first.first][emptyCells[i].first.second] = emptyCells[i].second; //переписываем в единое целое поле

	}


	for (int i = 0; i < 9; i++) {

		if (i % 3 == 0) cout << "-------------------------\n";

		for (int j = 0; j < 9; j++) {

			if (j % 3 == 0) cout << "| ";

			if (result[i][j] == 0) cout << "- ";
			else cout << result[i][j] << " ";

		}

		cout << "|\n";

	}

	cout << "-------------------------\n";

}
