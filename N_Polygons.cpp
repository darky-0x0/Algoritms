#include "N_Polygons.h"




void lab6task4() {

	cout << "Данные взяты из файла";

	string fileName = "N_Polygons3.txt";

	

	vector<pair<int, int>> coordinates;

	fileRead(fileName, coordinates);
	
	vector<vector<float>> cost(coordinates.size(), vector<float>(coordinates.size())); //таблица для записи стоимостей
	vector<vector<float>> diagonalsLength(coordinates.size(), vector<float>(coordinates.size())); //длины известных диагоналей
	vector<vector<vector<pair<int, int>>>> finalDiagonals(coordinates.size(), vector<vector<pair<int, int>>>(coordinates.size())); //поле-дубликат стоимостей. Только вместо значений здесь вектора истории диагоналей из пар значений сторон 

	cout << "\nДаны следующие координаты " << coordinates.size() << "-угольника: \n";
	for (int i = 0; i < coordinates.size(); i++) cout << "(" << coordinates[i].first << ";" << coordinates[i].second << ") ";

	int size = coordinates.size();

	cout << "\n\nДлины диагоналей от 1 до n-1 до каждой стороны: \n";

	lengthOfAllDiagonals(diagonalsLength, coordinates); //нахождение размерности всех диагоналей

	polygonsCut(diagonalsLength, cost, size, finalDiagonals); //основной цикл



	cout << "\n\nПолучившиеся соотношения по минимальным длинам (где номер строки это k, а номер столбца - l): \n";

	for (int i = 0; i < cost.size(); i++) {

		for (int j = 0; j < cost.size(); j++) {

			cout << cost[i][j] << "\t";

		}

		cout << "\n";
	}

	cout << "\n\nМинимальный разрез фигуры: " << cost[0][size - 1];

	cout << "\n\nНомера сторон разрезов(диагонали): ";

	for (int i = 0; i < finalDiagonals[0][size - 1].size(); i++) {

		cout << "(" <<finalDiagonals[0][size - 1][i].first + 1 << ";" << finalDiagonals[0][size - 1][i].second + 1 << "), ";
	}

}



void polygonsCut(vector<vector<float>> diagonalsLength, vector<vector<float>>& cost, int size, vector<vector<vector<pair<int, int>>>>& finalDiagonals) {

	int i(0); //точка относительного перебора

	int k(0), l(0); //точки диапазона

	for (int t = 3; t < size; t++) { //размер шага

		for (k = 0, l = t; l < size; k++, l++) { //объявляем две границы и их размерность. До момента, пока l не дойдёт до крайней точки увеличиваем обе переменные

			vector<float> cuts; //хранит все возможные разрезы на данном диапазоне

			vector<vector<pair<int, int>>> diagonals; //всевозможные комбинации диагоналей с данной фигуры

			for (int i = k + 1; i < l; i++) { //пробегаемся по возможным точкам

				float count(0); //локальный счётчик значения разрезов

				vector<pair<int, int>> localDiagonals; //счётчик локальных диагоналей

				if (i > k + 2) { //если фигура составная

					count += cost[k][i]; //если одна из трёх под-фигур - составная, берём из вектора уже известную минимальную

					for (int a = 0; a < finalDiagonals[k][i].size(); a++) localDiagonals.push_back(pair<int, int>(finalDiagonals[k][i][a].first, finalDiagonals[k][i][a].second)); //покоординатно пушбекаем минимальные диагонали фигуры i-l

				}


				if (i < l - 2) { //если фигура составная

					count += cost[i][l]; //если одна из трёх под-фигур - составная, берём из вектора уже известную минимальную

					for (int a = 0; a < finalDiagonals[i][l].size(); a++) localDiagonals.push_back(pair<int, int>(finalDiagonals[i][l][a].first, finalDiagonals[i][l][a].second)); //покоординатно пушбекаем минимальные диагонали фигуры i-l

				}

				if (i == k + 1) { //если (k;i) является ребром многоугольника (считаем вторую фигуру и (i;l))

					count += diagonalsLength[i][l]; //плюсуем диагональ (i;l)

					localDiagonals.push_back(pair<int, int>(i, l)); //пушбекаем диагональ

				}

				else if (i == l - 1) { //иначе если (i;l) не является ребром многоугольника

					count += diagonalsLength[k][i]; //плюсуем диагональ (k;i)

					localDiagonals.push_back(pair<int, int>(k, i)); //пушбекаем диагональ

				}
				else { //если и (k;i), и (i;l) являются собственными диагоналями фигуры k-l

					count += diagonalsLength[k][i]; //плюсуем диагональ (k;i)

					localDiagonals.push_back(pair<int, int>(k, i)); //пушбекаем диагональ

					count += diagonalsLength[i][l]; //плюсуем диагональ (i;l)

					localDiagonals.push_back(pair<int, int>(i, l)); //пушбекаем диагональ

				}


				cuts.push_back(count);

				diagonals.push_back(localDiagonals); 

			}

			float minNum = cuts[0];
			int position(0); //позиция минимального разреза в массиве

			for (int s = 1; s < cuts.size(); s++) {
				if (minNum >= cuts[s]) {

					minNum = cuts[s]; //вычисляем наименьший разрез диагоналей фигуры k-l
					position = s;

				}
			}

			cost[k][l] = minNum; //минимальный размер диагоналей для фигуры k-l

			finalDiagonals[k][l] = diagonals[position];

		}

	}


}


void lengthOfAllDiagonals(vector<vector<float>>& diagonalsLength, vector<pair<int, int>>& coordinates) {

	for (int i = 0; i < coordinates.size(); i++) {

		for (int j = i + 2; (j < coordinates.size()) && !((i == 0) && (j == coordinates.size()-1)); j++) {

			int x = coordinates[i].first - coordinates[j].first;

			int y = coordinates[i].second - coordinates[j].second;

			diagonalsLength[i][j] = sqrt(x*x+y*y);

			cout << "(" << i << ";" << j << ")" << diagonalsLength[i][j] << ";  ";

		}

	}

}


void fileRead(string fileName, vector<pair<int, int>>& coordinates) {

	ifstream file;
	file.open(fileName);

	int n;

	file >> n;

	vector<pair<int, int>> coordinats(n);

	for (int i = 0; i < n; i++) {

		file >> coordinats[i].first;
		file >> coordinats[i].second;

	}

	file.close();

	coordinates = coordinats;

}
