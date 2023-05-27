#include "N_Polygons.h"




void lab6task4() {

	cout << "ƒанные вз€ты из файла";

	string fileName = "N_Polygons2.txt";

	

	vector<pair<int, int>> coordinates;

	fileRead(fileName, coordinates);
	
	vector<vector<float>> cost(coordinates.size(), vector<float>(coordinates.size())); //таблица дл€ записи стоимостей
	vector<vector<float>> diagonalsLength(coordinates.size(), vector<float>(coordinates.size()));

	cout << "\nƒаны следующие координаты " << coordinates.size() << "-угольника: \n";
	for (int i = 0; i < coordinates.size(); i++) cout << "(" << coordinates[i].first << ";" << coordinates[i].second << ") ";

	int size = coordinates.size();

	cout << "\n\nƒлины диагоналей от 1 до n-1 до каждой стороны: \n";

	lengthOfAllDiagonals(diagonalsLength, coordinates); //нахождение размерности всех диагоналей

	polygonsCut(diagonalsLength, cost, size); //основной цикл



	cout << "\n\nѕолучившиес€ соотношени€ по минимальным длинам (где номер строки это k, а номер столбца - l): \n";

	for (int i = 0; i < cost.size(); i++) {

		for (int j = 0; j < cost.size(); j++) {

			cout << cost[i][j] << "\t";

		}

		cout << "\n";
	}

	cout << "\n\nћинимальный разрез фигуры: " << cost[0][size - 1];

}



void polygonsCut(vector<vector<float>> diagonalsLength, vector<vector<float>>& cost, int size) {

	int i(0); //точка относительного перебора

	int k(0), l(0); //точки диапазона

	for (int t = 3; t < size; t++) { //размер шага

		for (k = 0, l = t; l < size; k++, l++) { //объ€вл€ем две границы и их размерность. ƒо момента, пока l не дойдЄт до крайней точки увеличиваем обе переменные

			vector<float> cuts; //хранит все возможные разрезы на данном диапазоне

			for (int i = k + 1; i < l; i++) { //пробегаемс€ по возможным точкам

				float count(0);

				if (i == k + 1) { //если (k;i) €вл€етс€ ребром многоугольника (считаем вторую фигуру и (i;l))

					count += diagonalsLength[i][l]; //плюсуем диагональ (i;l)

					if (!(i == l - 2)) { //если (i;l) не €вл€етс€ треугольником, в противном случае фигура с одной диагональю (n == 4)

						count += cost[i][l]; //минимальна€ длина l-i+1-многоугольника

					}

				}

				else if (i == l - 1) { //иначе если (i;l) не €вл€етс€ ребром многоугольника

					count += diagonalsLength[k][i]; //плюсуем диагональ (k;i)

					if (!(i == k + 2)) { //если (k;i) не €вл€етс€ треугольником, в противном случае фигура с одной диагональю (n == 4)

						count += cost[k][i]; //минимальна€ длина i-k+1-многоугольника

					}


				}
				else { //если и (k;i), и (i;l) €вл€ютс€ собственными диагонал€ми фигуры k-l

					count += diagonalsLength[k][i]; //плюсуем диагональ (k;i)

					if (!(i == k + 2)) count += cost[k][i]; //если одна из трЄх под-фигур - составна€, берЄм из вектора уже известную минимальную

					count += diagonalsLength[i][l];

					if (!(i == l - 2)) count += cost[i][l]; //если одна из трЄх под-фигур - составна€, берЄм из вектора уже известную минимальную

				}

				cuts.push_back(count);

			}

			float minNum = cuts[0];

			for (int s = 1; s < cuts.size(); s++) if (minNum > cuts[s]) minNum = cuts[s]; //вычисл€ем наименьший разрез диагоналей фигуры k-l

			cost[k][l] = minNum; //минимальный размер диагоналей дл€ фигуры k-l

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
