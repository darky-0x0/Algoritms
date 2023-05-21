#include "Sorting.h"





void lab3task1() {


	vector<int> array; int k(0); int size(0); int m;

	string filename = "sort1.txt";

	ifstream fin;

	fin.open(filename);

	fin >> m;

	while (!(fin.eof())) {

		size++;

		array.push_back(0);

		fin >> array[k++];

	}

	array = simpleSort(array, size, m);

	cout << "Отсортированный массив: ";

	for (int i = 0; i < size; i++) {
		cout << array[i] << ' ';
	}

	cout << "\n\n";

	array.clear();

	fin.close();

}

void lab3task2() {


	vector<int> array; int k(0); int size(0);

	string filename = "sort2.txt";

	ifstream fin;

	fin.open(filename);

	while (!(fin.eof())) {

		size++;

		array.push_back(0);

		fin >> array[k++];

	}

	array = sortingByParity(array, size);

	cout << "Отсортированный массив: ";

	for (int i = 0; i < size; i++) {
		cout << array[i] << ' ';
	}

	cout << "\n\n";

	array.clear();

	fin.close();


}

void lab3task3() {

	ofstream file;

	cout << "Обработка файлов...\n\n";

	ifstream file1; file1.open("sortNONIncreasing.txt");
	ifstream file2; file2.open("sortNONDereasing.txt");
	ifstream file3; file3.open("sortRandom.txt");

	vector<int> Vfile1(100000, 0), Vfile2(100000, 0), Vfile3(100000, 0);

	for (int i = 0; i < 100000; i++) {

		file1 >> Vfile1[i];
		file2 >> Vfile2[i];
		file3 >> Vfile3[i];

	}

	int size = 100000;

	file1.close(); file2.close(); file3.close();



	{
		file.open("table.txt");

		unsigned long int n11(0), n12(0), n13(0), n21(0), n22(0), n23(0), n31(0), n32(0), n33(0); //перечисления

		file << "\t\t|\t\tИзначально по неубыванию\t\t\t|\t\tИзначально по невозрастанию\t\t\t|\t\tСлучайным образом\t\t\t\t\t|\n";

		file << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";

		file << "\t\t|Кол-во\t\t|Кол-во\t\t|Кол-во\t\t|Кол-во\t\t|Кол-во\t\t|Кол-во\t\t|Кол-во\t\t|Кол-во\t\t|Кол-во\t\t|\n";

		file << "\t\t|сравнений\t\t|сравнений не\t|перестановок\t|равнений\t\t|сравнений не\t|перестановок\t|сравнений\t\t|сравнений не\t|перестановок\t|\n";

		file << "\t\t|с элементом\t|с элементом\t|\t\t\t|с элементом\t|с элементом\t|\t\t\t|с элементом\t|с элементом\t|\t\t\t|\n";

		file << "\t\t|массива\t\t|массива\t\t|\t\t\t|массива\t\t|массива\t\t|\t\t\t|массива\t\t|массива\t\t|\t\t\t|\n";

		file << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";

		cout << "Алгоритм простого выбора(в работе 1/3):\n";
		simpleSelect(Vfile1, size, n11, n12, n13);
		cout << "Алгоритм простого выбора(в работе 2/3):\n";
		simpleSelect(Vfile2, size, n21, n22, n23);
		cout << "Алгоритм простого выбора(в работе 3/3):\n";
		simpleSelect(Vfile3, size, n31, n32, n33);
		cout << "Алгоритм простого выбора(готов):\n\n";

		file << "1\t\t|" << n11 << "\t\t|" << n12 << "\t\t|" << n13 << "\t\t|" << n21 << "\t\t|" << n22 << "\t\t|" << n23 << "\t\t|" << n31 << "\t\t|" << n32 << "\t\t|" << n33 << "\t\t|";

		file << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";

		n11 = 0; n12 = 0; n13 = 0; n21 = 0; n22 = 0; n23 = 0; n31 = 0; n32 = 0; n33 = 0;

		cout << "Алгоритм простого обмена(в работе 1/3):\n";
		simpleExchange(Vfile1, size, n11, n12, n13);
		cout << "Алгоритм простого обмена(в работе 2/3):\n";
		simpleExchange(Vfile2, size, n21, n22, n23);
		cout << "Алгоритм простого обмена(в работе 3/3):\n";
		simpleExchange(Vfile3, size, n31, n32, n33);
		cout << "Алгоритм простого обмена(готов):\n\n";

		file << "1\t\t|" << n11 << "\t\t|" << n12 << "\t\t|" << n13 << "\t\t|" << n21 << "\t\t|" << n22 << "\t\t|" << n23 << "\t\t|" << n31 << "\t\t|" << n32 << "\t\t|" << n33 << "\t\t|";

		file << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";

		n11 = 0; n12 = 0; n13 = 0; n21 = 0; n22 = 0; n23 = 0; n31 = 0; n32 = 0; n33 = 0;

		cout << "Улучшенный алгоритм простого обмена(в работе 1/3):\n";
		simpleExchangeUpgrade(Vfile1, size, n11, n12, n13);
		cout << "Улучшенный алгоритм простого обмена(в работе 2/3):\n";
		simpleExchangeUpgrade(Vfile2, size, n21, n22, n23);
		cout << "Улучшенный алгоритм простого обмена(в работе 3/3):\n";
		simpleExchangeUpgrade(Vfile3, size, n31, n32, n33);
		cout << "Улучшенный алгоритм простого обмена(готов):\n";

		file << "1\t\t|" << n11 << "\t\t|" << n12 << "\t\t|" << n13 << "\t\t|" << n21 << "\t\t|" << n22 << "\t\t|" << n23 << "\t\t|" << n31 << "\t\t|" << n32 << "\t\t|" << n33 << "\t\t|";

		file << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";

		n11 = 0; n12 = 0; n13 = 0; n21 = 0; n22 = 0; n23 = 0; n31 = 0; n32 = 0; n33 = 0;

		cout << "Улучшенный алгоритм простого обмена – шейкер-сортировка(в работе 1/3):\n";
		simpleExchangeShaker(Vfile1, size, n11, n12, n13);
		cout << "Улучшенный алгоритм простого обмена – шейкер-сортировка(в работе 2/3):\n";
		simpleExchangeShaker(Vfile2, size, n21, n22, n23);
		cout << "Улучшенный алгоритм простого обмена – шейкер-сортировка(в работе 3/3):\n";
		simpleExchangeShaker(Vfile3, size, n31, n32, n33);
		cout << "Улучшенный алгоритм простого обмена – шейкер-сортировка(готов):\n";

		file << "1\t\t|" << n11 << "\t\t|" << n12 << "\t\t|" << n13 << "\t\t|" << n21 << "\t\t|" << n22 << "\t\t|" << n23 << "\t\t|" << n31 << "\t\t|" << n32 << "\t\t|" << n33 << "\t\t|";

		file << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";

		n11 = 0; n12 = 0; n13 = 0; n21 = 0; n22 = 0; n23 = 0; n31 = 0; n32 = 0; n33 = 0;

		cout << "Алгоритм прямого включения(в работе 1/3):\n";
		insertionSort(Vfile1, size, n11, n12, n13);
		cout << "Алгоритм прямого включения(в работе 2/3):\n";
		insertionSort(Vfile2, size, n21, n22, n23);
		cout << "Алгоритм прямого включения(в работе 3/3):\n";
		insertionSort(Vfile3, size, n31, n32, n33);
		cout << "Алгоритм прямого включения(готов):\n";

		file << "1\t\t|" << n11 << "\t\t|" << n12 << "\t\t|" << n13 << "\t\t|" << n21 << "\t\t|" << n22 << "\t\t|" << n23 << "\t\t|" << n31 << "\t\t|" << n32 << "\t\t|" << n33 << "\t\t|";

		file << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";

		n11 = 0; n12 = 0; n13 = 0; n21 = 0; n22 = 0; n23 = 0; n31 = 0; n32 = 0; n33 = 0;

		cout << "Улучшенный алгоритм прямого включения(в работе 1/3):\n";
		insertionSortWithBarrier(Vfile1, size, n11, n12, n13);
		cout << "Улучшенный алгоритм прямого включения(в работе 2/3):\n";
		insertionSortWithBarrier(Vfile2, size, n21, n22, n23);
		cout << "Улучшенный алгоритм прямого включения(в работе 3/3):\n";
		insertionSortWithBarrier(Vfile3, size, n31, n32, n33);
		cout << "Улучшенный алгоритм прямого включения(готов):\n";

		file << "1\t\t|" << n11 << "\t\t|" << n12 << "\t\t|" << n13 << "\t\t|" << n21 << "\t\t|" << n22 << "\t\t|" << n23 << "\t\t|" << n31 << "\t\t|" << n32 << "\t\t|" << n33 << "\t\t|";

		file << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";

		n11 = 0; n12 = 0; n13 = 0; n21 = 0; n22 = 0; n23 = 0; n31 = 0; n32 = 0; n33 = 0;

		int count(0);
		cout << "Алгоритм сортировки слияниями(в работе 1/3):\n";
		mergeSort(Vfile1, size, count, n11, n12, n13);
		cout << "Алгоритм сортировки слияниями(в работе 2/3):\n";
		mergeSort(Vfile2, size, count, n21, n22, n23);
		cout << "Алгоритм сортировки слияниями(в работе 3/3):\n";
		mergeSort(Vfile3, size, count, n31, n32, n33);
		cout << "Алгоритм сортировки слияниями(готов):\n";

		file << "1\t\t|" << n11 << "\t\t|" << n12 << "\t\t|" << n13 << "\t\t|" << n21 << "\t\t|" << n22 << "\t\t|" << n23 << "\t\t|" << n31 << "\t\t|" << n32 << "\t\t|" << n33 << "\t\t|";

		file << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";

		n11 = 0; n12 = 0; n13 = 0; n21 = 0; n22 = 0; n23 = 0; n31 = 0; n32 = 0; n33 = 0; count = 0;

		cout << "Быстрая сортировка Хоара(в работе 1/3):\n";
		sortHoar(Vfile1, 0, Vfile1.size() - 1, count, n11, n12, n13);
		cout << "Быстрая сортировка Хоара(в работе 2/3):\n";
		sortHoar(Vfile2, 0, Vfile2.size() - 1, count, n21, n22, n23);
		cout << "Быстрая сортировка Хоара(в работе 3/3):\n";
		sortHoar(Vfile3, 0, Vfile3.size() - 1, count, n31, n32, n33);
		cout << "Быстрая сортировка Хоара(готов):\n";

		file << "1\t\t|" << n11 << "\t\t|" << n12 << "\t\t|" << n13 << "\t\t|" << n21 << "\t\t|" << n22 << "\t\t|" << n23 << "\t\t|" << n31 << "\t\t|" << n32 << "\t\t|" << n33 << "\t\t|";

		file << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";

		file.close();

		cout << "\n\n\n\t\t\t\tОБРАБОТКА ФАЙЛА ЗАВЕРШЕНА";

	}

}


void createFilesForSort()
{
	ofstream file; //создание рандомного массива

	file.open("sortRandom.txt");

	for (int i = 1; i <= 100000; i++) {

		file << rand() << " ";

	}

	file.close();

	ifstream file2;

	vector<int> arrayTEST(100000, 0);

	file2.open("sortRandom.txt");

	for (int i = 0; i < 100000; i++) {

		file2 >> arrayTEST[i];

	}

	cout << "Сортировка началась\n\nГотовность:\n";

	unsigned long int a, b, c;

	arrayTEST = simpleSelect(arrayTEST, 100000, a, b, c);



	ofstream fileNONInc;
	ofstream fileNONDer;

	fileNONInc.open("sortNONIncreasing.txt");
	fileNONDer.open("sortNONDereasing.txt");

	for (int i = 0; i < 100000; i++) {

		fileNONInc << arrayTEST[i] << " ";

		fileNONDer << arrayTEST[100000 - 1 - i] << " ";

	}

	fileNONInc.close();
	fileNONDer.close();


	file2.close();
}

vector<int> sortingByParity(vector<int> array, int size) {

	vector<int> even;

	vector<int> odd;

	for (int i = 0; i < size; i++) {

		if (array[i] % 2 == 0) even.push_back(array[i]);

		else odd.push_back(array[i]);

	}

	int j(0);

	for (int i = 0; i < even.size(); i++) {

		array[j++] = even[i];

	}

	for (int i = 0; i < odd.size(); i++) {

		array[j++] = odd[i];

	}
	return array;
}

vector<int> simpleSort(vector<int> array, int size, int m) {

	vector<int> sortoff(m, 0); int j(0);

	for (int i = 0; i < size; i++) { //заполняем массив кол-вом вхождений

		sortoff[array[i]]++;

	}

	array.clear();

	for (int i = 0; i < size; i++) {

		array.push_back(0);

	}

	for (int i = 0; i < size; i++) {

		while (sortoff[j++] == 0); //двигаемся до ближайшего непустого элемента

		j--;

		array[i] = j; //присваиваем 

		sortoff[j]--;//вычитаем элемент

	}

	sortoff.clear();

	return array;

}


vector<int> simpleSelect(vector<int> array, int size, unsigned long int& comparisonWithElement, unsigned long int& comparisionWithNotElement, unsigned long int& countReplace)
{
	int maxEl;

	int counter(1);


	for (int i = size - 1; i > 0; i--) {
		comparisionWithNotElement++;

		maxEl = i;

		for (int j = 0; j < i; j++) {  //ищем наибольший элемент
			comparisionWithNotElement++;

			comparisonWithElement++;
			if (array[maxEl] < array[j]) maxEl = j;

		}
		comparisionWithNotElement++;


		if (array[maxEl] > array[i]) { //перестановка
			comparisonWithElement++;

			int TEMP = array[i];

			array[i] = array[maxEl];

			array[maxEl] = TEMP;
			countReplace++;

		}

		if (i % 1000 == 0) { //просто счётчик :)

			cout << counter++ << "%\n";

		}

	}
	comparisionWithNotElement++;

	return array;

}

vector<int> simpleExchange(vector<int> array, int size, unsigned long int& comparisonWithElement, unsigned long int& comparisionWithNotElement, unsigned long int& countReplace)
{
	int counter(1);

	for (int l = 1; l < size - 1; l++) {
		comparisionWithNotElement++;

		for (int i = 0; i < size - l; i++) {
			comparisionWithNotElement++;

			comparisonWithElement++;
			if (array[i] > array[i + 1]) {
				countReplace++;

				int TEMP = array[i];

				array[i] = array[i + 1];

				array[i + 1] = TEMP;
			}

		}
		comparisionWithNotElement++;

	}
	comparisionWithNotElement++;

	return array;
}

vector<int> simpleExchangeUpgrade(vector<int> array, int size, unsigned long int& comparisonWithElement, unsigned long int& comparisionWithNotElement, unsigned long int& countReplace)
{

	int counter(1);
	int count(1);

	bool isEnd(false);

	int indexReplace = size - 1; //последняя замена
	int lastReplace = size - 1; //последняя замена для сравнения с преыдущим занчением

	while (isEnd == false) {
		comparisionWithNotElement++;

		count++;


		for (int i = 0; i < indexReplace; i++) {
			comparisionWithNotElement++;

			comparisonWithElement++;
			if (array[i] > array[i + 1]) {
				countReplace++;

				int TEMP = array[i];

				array[i] = array[i + 1];

				array[i + 1] = TEMP;

				lastReplace = i;

			}

		}
		comparisionWithNotElement++;

		if (lastReplace == indexReplace) isEnd = true;
		comparisionWithNotElement++;

		indexReplace = lastReplace;


	}
	comparisionWithNotElement++;

	return array;
}

vector<int> simpleExchangeShaker(vector<int> array, int size, unsigned long int& comparisonWithElement, unsigned long int& comparisionWithNotElement, unsigned long int& countReplace)
{

	int counter(1);
	int count(1);

	bool isEnd(false), shake(true);

	int indexReplace = size - 1; //последняя замена с конца для сравнения с преыдущим занчением
	int lastReplace = size - 1; //последняя замена 
	int firstReplace = 0; //последняя замена с начала

	while (isEnd == false) {
		comparisionWithNotElement++;

		count++;

		if (shake == true) {
			comparisionWithNotElement++;

			indexReplace = lastReplace;

			for (int i = firstReplace; i < lastReplace; i++) {
				comparisionWithNotElement++;

				comparisonWithElement++;
				if (array[i] > array[i + 1]) { //перестановка
					countReplace++;

					int TEMP = array[i];

					array[i] = array[i + 1];

					array[i + 1] = TEMP;

					indexReplace = i;

				}

			}
			comparisionWithNotElement++;

			if (lastReplace == indexReplace) isEnd = true;
			comparisionWithNotElement++;

			lastReplace = indexReplace;

			shake = false;

		}
		else {
			comparisionWithNotElement++;

			indexReplace = firstReplace;

			for (int i = lastReplace; i > firstReplace; i--) {
				comparisionWithNotElement++;

				comparisonWithElement++;
				if (array[i] < array[i - 1]) {
					countReplace++;

					int TEMP = array[i];

					array[i] = array[i - 1];

					array[i - 1] = TEMP;

					indexReplace = i;

				}

			}
			comparisionWithNotElement++;

			if (firstReplace == indexReplace) isEnd = true;
			comparisionWithNotElement++;

			firstReplace = indexReplace;

			shake = true;

		}



	}

	return array;
}

vector<int> insertionSort(vector<int> array, int size, unsigned long int& comparisonWithElement, unsigned long int& comparisionWithNotElement, unsigned long int& countReplace)
{
	int counter(1);
	int count(1);

	int x, index;

	for (int i = 1; i < size; i++) {
		comparisionWithNotElement++;

		count++;

		x = array[i];
		index = i - 1;

		while ((index >= 0) && (array[index] > x)) {
			comparisionWithNotElement++;
			comparisonWithElement++;

			countReplace++;
			array[index + 1] = array[index];

			index--;

		}
		if (index >= 0) {
			comparisonWithElement++;
			comparisionWithNotElement++;
		}
		else comparisionWithNotElement++;

		array[index + 1] = x;



		if (count % 1000 == 0) {

			cout << counter++ << "%\n";

		}

	}
	comparisionWithNotElement++;

	return array;

}

vector<int> insertionSortWithBarrier(vector<int> arrayA, int size, unsigned long int& comparisonWithElement, unsigned long int& comparisionWithNotElement, unsigned long int& countReplace)
{
	int counter(1);
	int count(1);

	int x, index;

	vector<int> array(size + 1, 0);

	for (int i = 1; i <= size; i++) { //заполнение массива с местом под баррьерный элемент
		comparisionWithNotElement++;

		array[i] = arrayA[i - 1];

	}
	comparisionWithNotElement++;

	for (int i = 2; i <= size; i++) {
		comparisionWithNotElement++;

		count++;

		x = array[i];

		array[0] = x;

		index = i - 1;

		while (array[index] > x) {
			comparisonWithElement++;

			countReplace++;
			array[index + 1] = array[index];

			index--;

		}
		comparisonWithElement++;

		array[index + 1] = x;


		if (count % 1000 == 0) {

			cout << counter++ << "%\n";

		}

	}
	comparisionWithNotElement++;


	for (int i = 0; i < size; i++) {
		comparisionWithNotElement++;

		arrayA[i] = array[i + 1];

	}
	comparisionWithNotElement++;

	return arrayA;

}

vector<int> mergeSort(vector<int> array, int size, int& count, unsigned long int& comparisonWithElement, unsigned long int& comparisionWithNotElement, unsigned long int& countReplace)
{

	int counter(0);

	comparisionWithNotElement++;
	if (array.size() == 1) {

		return array;

	}
	else {

		int center = array.size() / 2;

		vector<int> part1, part2;

		for (int i = 0; i < center; i++) {	//разделение
			comparisionWithNotElement++;

			part1.push_back(array[i]);

		}
		comparisionWithNotElement++;

		for (int i = center; i < array.size(); i++) {	//разделение
			comparisionWithNotElement++;

			part2.push_back(array[i]);

		}
		comparisionWithNotElement++;

		part1 = mergeSort(part1, part1.size(), count, comparisonWithElement, comparisionWithNotElement, countReplace);	//сортировка первой части

		part2 = mergeSort(part2, part1.size(), count, comparisonWithElement, comparisionWithNotElement, countReplace);	//сортировка второй части

		array.clear();

		int ind1(0), ind2(0);

		while ((ind1 != part1.size()) && (ind2 != part2.size()) && (array.size() != part1.size() + part2.size())) {	//слияние в один массив
			comparisionWithNotElement += 3;

			comparisonWithElement++;
			if (part1[ind1] < part2[ind2]) {

				array.push_back(part1[ind1++]);
				countReplace++;

			}
			else {

				array.push_back(part2[ind2++]);
				countReplace++;

			}

		}
		if (ind1 != part1.size()) {
			comparisionWithNotElement += 2;
			if (ind2 != part2.size()) comparisionWithNotElement++;
		}
		else comparisionWithNotElement++;

		comparisionWithNotElement++;
		if (ind1 == part1.size()) {	//запись оставшихся элементов

			for (int i = ind2; i < part2.size(); i++) {
				comparisionWithNotElement++;

				array.push_back(part2[i]);
				countReplace++;

			}
			comparisionWithNotElement++;

		}
		else {

			for (int i = ind1; i < part1.size(); i++) {
				comparisionWithNotElement++;

				array.push_back(part1[i]);
				countReplace++;

			}
			comparisionWithNotElement++;

		}

		if (array.size() % 1000 == 0) {

			cout << counter++ << "%\n";

		}

		return array;

	}
}

void sortHoar(vector<int>& array, int first, int last, int& count, unsigned long int& comparisonWithElement, unsigned long int& comparisionWithNotElement, unsigned long int& countReplace)
{

	int el = array[(first + last) / 2];

	int i(first), j(last);

	do
	{

		comparisonWithElement++; //отсекаем края, которые соответсвуют своим сторонам
		while (array[i] < el)
		{

			comparisonWithElement++;

			i++;

		}

		comparisonWithElement++;

		while (array[j] > el)
		{

			comparisonWithElement++;

			j--;

		}

		comparisionWithNotElement++;

		if (i <= j) //меняем местами элементы, несоответствующие сторонам
		{

			countReplace++;
			comparisonWithElement++;

			int tmp = array[i];

			array[i] = array[j];

			array[j] = tmp;

			i++;

			j--;

		}

		comparisionWithNotElement++;

	} while (i <= j);//пока левая граница не пересечет правую



	comparisionWithNotElement++;
	if (first < j) sortHoar(array, first, j, count, comparisonWithElement, comparisionWithNotElement, countReplace);

	comparisionWithNotElement++;
	if (i < last) sortHoar(array, i, last, count, comparisonWithElement, comparisionWithNotElement, countReplace);

	if (array.size() % 1000 == 0) {

		cout << count++ << "%\n";

	}

}
