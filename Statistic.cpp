#include "Statistic.h"






void lab7task4() {

	int end(0);


	string fileName = "Statistic1.txt";



	vector<int> array;

	cout << "Дан массив: ";

	fileRead(fileName, array);

	printArray(array);

	while (end != -1) {

		cout << "\n\nВведите статистику от 1 до " << array.size()<< ", которую необходимо найти(-1 проверка): ";

		int statistic; cin >> statistic; statistic--; //i-элемент (не индекс)

		end = statistic;

		if (statistic > -1) {

			int result(searchingStatistic(array, statistic, 0, array.size() - 1, 0));

			cout << "\n" << ++statistic << "-ая статистика массива: " << result;

		}
		else if (statistic == -2) printSortArray(array);

	}


}


void lab7task5() {

	int end(0);


	string fileName = "Statistic1.txt";



	vector<int> array;

	cout << "Дан массив: ";

	fileRead(fileName, array);

	printArray(array);

	while (end != -1) {

		cout << "\n\nВведите статистику от 0 до " << array.size() - 1 << ", которую необходимо найти(-1 проверка): ";

		int statistic; cin >> statistic; statistic--;

		end = statistic;

		if (statistic > -1) {

			int result(searchingStatistic(array, statistic, 0, array.size() - 1, 1));

			cout << "\n" << ++statistic << "-ая статистика массива: " << result;

		}
		else if (statistic == -2) printSortArray(array);

	}

}


int searchingStatistic(vector<int>& array, int statistic, int p, int r, int algorithmTime) {

	if (p == r) { //если остался массив из одного элемента

		return array[p];

	}
	else {


		pair<int, int> partsIndexes;

		if (algorithmTime == 0) { //за линейное в среднем время

			int pIndex = randGenerate(p, r); //рандомное число от p до r
			
			partsIndexes = partition(p, r, array[pIndex], array); //сортируем элементы, индексами разбивая на части

		}
		else { //за линейное в худшем случае время

			int element = select(array, p, r); //медиана медиан

			partsIndexes = partition(p, r, element, array); //сортируем элементы, индексами разбивая на части

		}


		if (statistic >= partsIndexes.first+1 && statistic <= partsIndexes.second) return array[statistic]; //если статистика - средний массив
		else if (statistic < partsIndexes.first+1) return searchingStatistic(array, statistic, p, partsIndexes.first, algorithmTime); //если статистика в левой части
		else return searchingStatistic(array, statistic, partsIndexes.second + 1, r, algorithmTime); //если статистика в правой части

	}

}


int select(vector<int>& array, int p, int r) {

	vector<int> medians;

	vector<int> arrayTemp;

	for (int i = p; i <= r; i++) arrayTemp.push_back(array[i]); //переписываем часть массива

	for (int i = 0; i < arrayTemp.size()/5; i++) { //разбиваем массив на массивы по 5 элементов и используем сортировку 5 за 7

		sortFiveForSeven(arrayTemp, i);

		medians.push_back(arrayTemp[5*i+2]);

	}

	if (medians.size() == 0) { //если массив состоял из менее чем 5 элементов

		for (int i = 0; i < arrayTemp.size(); i++) medians.push_back(arrayTemp[i]);

	}

	arrayTemp.clear();

	while (medians.size() > 5) { //пока массив медиан больше 5

		vector<int> mediansTmp;

		for (int i = 0; i < medians.size()/5; i++) { //разбиваем массив медиан на массивы по 5 элементов и используем сортировку 5 за 7

			sortFiveForSeven(medians, i);

			mediansTmp.push_back(medians[5 * i + 2]);

		}

		medians = mediansTmp;

	}

	unsigned long pass(0); //заглушка

	medians = simpleSelect(medians, medians.size(), pass, pass, pass); //сортируем массив медиан от медиан j простым выбором

	return medians[medians.size()/2]; //берём медиану медианы медиан)))

}


pair<int, int> partition(int p, int r, int element, vector<int>& array) {

	int firstIndex(p - 1), endIndex(r); //индексы границ отсортированных частей

	int k = p - 1; //индекс пробега 

	while (k!= endIndex) {

		if (array[k + 1] == element) k++; //если текущий элемент равен элементу разбиеня, смещаем индекс пробега
		else {

			if (array[k + 1] < element) { //если текущий элемент меньше элемента разбиения, делаем свап и смещение индексов отсортированной части и пробега

				int temp(array[k + 1]);
				array[k + 1] = array[firstIndex + 1]; //
				array[firstIndex + 1] = temp;

				firstIndex++;
				k++;

			}
			else {

				int temp(array[k + 1]);
				array[k + 1] = array[endIndex]; //
				array[endIndex] = temp;

				endIndex--; //смещаем указатель отсортированной части с конца

			}

		}

	}

	pair<int, int> partsIndexes(firstIndex, k); //сохраняем индекс конца первой и начала последней частей

	return partsIndexes;

}


void sortFiveForSeven(vector<int>& array, int i) {

	if (array[5 * i + 0] > array[5 * i + 1]) swap(array, (5 * i + 0), (5 * i + 1));

	if (array[5 * i + 2] > array[5 * i + 3]) swap(array, (5 * i + 2), (5 * i + 3));

	if (array[5 * i + 1] > array[5 * i + 3]) {

		swap(array, (5 * i + 1), (5 * i + 3));
		swap(array, (5 * i + 0), (5 * i + 2));

	}

	if (array[5 * i + 4] < array[5 * i + 1]) {

		if (array[5 * i + 4] < array[5 * i + 0]) {

			swap(array, (5 * i + 4), (5 * i + 3));
			swap(array, (5 * i + 3), (5 * i + 1));
			swap(array, (5 * i + 1), (5 * i + 0));

		}
		else {

			swap(array, (5 * i + 4), (5 * i + 1));
			swap(array, (5 * i + 4), (5 * i + 3));

		}

	}
	else {

		if (array[5 * i + 4] < array[5 * i + 3]) swap(array, (5 * i + 4), (5 * i + 3));

	}

	if (array[5 * i + 2] < array[5 * i + 1]) {

		if (array[5 * i + 2] < array[5 * i + 0]) {

			swap(array, (5 * i + 2), (5 * i + 1));
			swap(array, (5 * i + 1), (5 * i + 0));

		}
		else {

			swap(array, (5 * i + 2), (5 * i + 1));

		}

	}
	else {

		if (array[5 * i + 2] > array[5 * i + 3]) swap(array, (5 * i + 3), (5 * i + 2));

	}

}


void fileRead(string fileName, vector<int>& array) {

	ifstream file;
	file.open(fileName);

	int size; 

	file >> size;

	vector<int> arry(size);

	for (int i = 0; i < size; i++) file >> arry[i];


	file.close();

	array = arry;

}


void printArray(vector<int> array) {

	cout << "\n";

	for (int i = 0; i < array.size(); i++) cout << array[i] << " ";

	cout << "\n";

}


int randGenerate(int start, int end) {

	srand(time(NULL));

	int randomEl;

	randomEl = start + rand() % (end - start + 1);

	return randomEl;

}


void swap(vector<int>& array, int a, int b) {

	int temp(array[a]);

	array[a] = array[b];

	array[b] = temp;

}


void printSortArray(vector<int> array) {

	cout << "\nОтсортированный массив: \n";

	unsigned long pass(0);

	array = simpleSelect(array, array.size(), pass, pass, pass);

	for (int i = 0; i < array.size(); i++) {

		cout << array[i] << "(" << i+1 << ") ";

	}

}
