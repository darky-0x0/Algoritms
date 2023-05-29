#include "StatisticWithTwoArrays.h"




void lab7task6() {

	string fileName1 = "Statistic3.txt";
	string fileName2 = "Statistic4.txt";


	cout << "Простое решение. Сольем два массива и просто возьмем элемент с индексом k-1. \nСлияние будет выполнено за время O(n+m), и использует O(n+m) дополнительной \nпамяти. \n\nЧуть менее простое.Используются два указателя, с помощью которых сможем \nобойти массивы, не сливая их.Первоначальное значение указателей – на начало \nкаждого из массивов.Будем увеличивать на единицу тот из них, который указывает \nна меньший элемент.После(k - 1) - ой итерации сравним элементы, на которых стоят \nуказатели.Меньший из них и будет ответом.Таким образом, мы получим k - ый \nэлемент за O(k)шагов.\n\nХорошее решение.В первом массиве выберем элемент c индексом i = n / 2 и бинарным \nпоиском найдем во втором массиве позицию j, на которой стоит наибольший \nэлемент, меньший a[i].Если i + j = k - 2, то мы нашли k - ую порядковую статистику — \nэто элемент a[i].Иначе, если i + j > k - 2, то далее тем же способом ищем в массиве a в \nдиапазоне индексов[0, i - 1], а если i + j < k - 2, то в диапазоне индексов[i + 1, n - 1].Решая \nзадачу таким способом, мы получим асимптотику O(log(n)*log(m)). \n\n";

	vector<int> array1;
	vector<int> array2;

	fileRead(fileName1, array1);
	fileRead(fileName2, array2);

	unsigned long pass(0);

	array1 = simpleExchange(array1, array1.size(), pass, pass, pass);
	array2 = simpleExchange(array2, array2.size(), pass, pass, pass);

	cout << "Массив 1: \n";
	for (int i = 0; i < array1.size(); i++) cout << array1[i] << " ";
	cout << "\nМассив 2: \n";
	for (int i = 0; i < array2.size(); i++) cout << array2[i] << " ";

	int statistic(0);

	while (statistic != -1) {

		cout << "\nВведите искомую статистику от 1 до " << array1.size()+array2.size() << ": ";
		cin >> statistic;

		if (statistic > -1) {

			simpleSolution(array1, array2, statistic);
			lessSimpleSolution(array1, array2, statistic);
			cout << goodSolution(array1, array2, statistic, 0, array1.size() - 1, 0, array2.size() - 1);

		}

	}


}


void simpleSolution(vector<int>& const array1, vector<int>& const array2, int k) {

	vector<int> array;

	int i(0), j(0); //указатели

	while (i != array1.size()-1 || j != array2.size()-1) {

		if (array1[i] > array2[j]) array.push_back(array2[j++]); //объединение двух массивов
		else array.push_back(array1[i++]);

	}

	while (i != array1.size()) array.push_back(array1[i++]);
	while (j != array2.size()) array.push_back(array2[j++]);

//	cout << "\nОбщий массив: \n";
//	for (int i = 0; i < array.size(); i++) cout << array[i] << " ";

	cout << "\n" << k << "-ая статистика(простое решение): " << array[k-1];

}


void lessSimpleSolution(vector<int>& const array1, vector<int>& const array2, int k) {

	int i(0), j(0); //указатели

	int t(0); //число итераций

	while (((t+1)!=k) && ((i != array1.size() - 1) || (j != array2.size() - 1))) { //выход, если итерация == искомой статистике или массив закончился

		if (array1[i] > array2[j]) j++; 
		else i++;

		t++;	//увеличиваем переменную интераций

	}

	cout << "\n" << k << "-ая статистика(чуть менее простое решение): ";

	if (array1[i] < array2[j]) {

		cout << array1[i];

	}
	else {

		cout  << array2[j];

	}

}


int goodSolution(vector<int>& const array1, vector<int>& const array2, int k, int firstIndA1, int lastIndA1, int firstIndA2, int lastIndA2) {

	int i = ((lastIndA1+firstIndA1) / 2); //середина области первого массива

	int element = array1[i]; //i-ый элемент первого массива

	int j = binarySearch(array2, firstIndA2, lastIndA2, element); //находим больший элемент меньше i-го во втором массиве бинарным поиском

	if (i + j == k - 2) { //если верно, возвращаем a[i]

		return array1[i];

	}
	else if (i + j > k - 2) { //иначе если k < i+j, продлжаем поиск в левой части

		return goodSolution(array2, array1, k, firstIndA2, j - 1, firstIndA1, i - 1);

	}
	else { //иначе продлжаем поиск в правой части

		return goodSolution(array2, array1, k, j + 1, lastIndA2, i + 1, lastIndA1);

	}

}


int binarySearch(vector<int> array, int first, int end, int element) { 

	int center;

	bool isEnd = false;

	int minMaxEl(0); //элемент, относительно которого находится больший меньше i в первом массиве

	int minMaxInd(0);

	while (end >= first) {

		center = (first + end) / 2;

		if ((array[center] < element) && (array[center] > minMaxEl)) { //если центральный элемент второго массива меньше i-го первого и больше максимального из минимальных

			minMaxEl = array[center];

			minMaxInd = center;

			first = center + 1; //смещаем левую границу

		}

		else if (element < array[center]) { //если центральный эемент второго массива больше i-го первого

			end = center - 1; //смещаем правую границу


		}

	}

	return minMaxInd;

}
