#include "TravelingSalesman.h"




void lab5task3() {

	string fileName = "Places.txt";



	vector<vector<int>> places; //расстояния м/д городами

	int minLength(0); //минимальная длина пути

	int length(0); //текущая длина пути

	vector<int> path; //общий путь

	vector<int> result; //путь минимальной длины

	int count(0); //счётчик городов

	int size; //количество городов

	fileRead(places, size, fileName);

	vector<int> notVisitedCities(size, 0); //посещённость городов

	int thisCity(0); //начинаем от первого города

	notVisitedCities[0] = -1; //отмечаем город как посещённый

	path.push_back(0); //добавляем в список посещённых городов

	printPlaces(places, size);

	kommivoyager(places, thisCity, length, minLength, path, result, count, size, notVisitedCities);

	cout << "\n\nОтвет:\nСамый минимальный путь: ";

	for (int i = 0; i < result.size(); i++) cout << result[i]+1 << " ";

	cout << "\nЕго длина: " << minLength;

}


void kommivoyager(vector<vector<int>> const places, int thisCity, int length, int& minLength, vector<int>& path, vector<int>& result, int count, int const size, vector<int>& notVisitedCities) {

	if (count == size) {

		if ((minLength > length) || (minLength == 0)) {

			minLength = length;

			result = path;

		}

	}
	else if (count == size - 1) {

		//заезд в город
		next(path, notVisitedCities, 0);

		//рекурсия
		kommivoyager(places, 0, length + places[thisCity][0], minLength, path, result, count + 1, size, notVisitedCities);

		//отсекаем последний элемент
		path.erase(path.end() - 1);

	}
	else {

		//если текущая длина пути не превышает минимальную или минимальная не была найдена
		if ((minLength > length) || (minLength == 0)) {

			int nextCity;

			for (int i = 0; i < size; i++) {

				//если не посещён
				if (notVisitedCities[i] == 0) {

					nextCity = i;

					//заезд в город
					next(path, notVisitedCities, nextCity);

					//рекурсия
					kommivoyager(places, nextCity, length + places[thisCity][nextCity], minLength, path, result, count + 1, size, notVisitedCities);

					//возвращение обратно
					preview(path, notVisitedCities, nextCity);

				}

			}

		}

	}

}


void next(vector<int>& path, vector<int>& notVisitedCities, int nextCity) {

	path.push_back(nextCity);

	notVisitedCities[nextCity] = -1;

}


void preview(vector<int>& path, vector<int>& notVisitedCities, int nextCity) {

	path.erase(path.end()-1);

	notVisitedCities[nextCity] = 0;

}


void fileRead(vector<vector<int>>& places, int& size, string fileName) {

	ifstream file;

	file.open(fileName);

	file >> size;

	vector<int> line(size, 0);

	vector<vector<int>> placess(size, line);

	for (int i = 0; i < size; i++) {

		for (int j = 0; j < size; j++) {

			file >> placess[i][j];

		}

	}

	places = placess;

	file.close();

}


void printPlaces(vector<vector<int>> places, int size) {

	cout << "Текущая таблицы с расстояниями между городами: \n\t";

	for (int i = 0; i < size; i++) {
		
		cout << i+1 << "\t";

	}

	cout << "\n---------------------------------------------------------------------------\n";

	for (int i = 0; i < size; i++) {

		for (int j = -1; j < size; j++) {

			if (j == -1) cout << i+1 << "|\t";
			else cout << places[i][j] << "\t";
		
		}

		cout << "\n";

	}


}
