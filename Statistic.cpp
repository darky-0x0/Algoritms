#include "Statistic.h"






void lab7task4() {

	int end(0);


	string fileName = "Statistic1.txt";



	vector<int> array;

	cout << "��� ������: ";

	fileRead(fileName, array);

	printArray(array);

	while (end != -1) {

		cout << "\n\n������� ���������� �� 1 �� " << array.size()<< ", ������� ���������� �����(-1 ��������): ";

		int statistic; cin >> statistic; statistic--; //i-������� (�� ������)

		end = statistic;

		if (statistic > -1) {

			int result(searchingStatistic(array, statistic, 0, array.size() - 1, 0));

			cout << "\n" << ++statistic << "-�� ���������� �������: " << result;

		}
		else if (statistic == -2) printSortArray(array);

	}


}


void lab7task5() {

	int end(0);


	string fileName = "Statistic1.txt";



	vector<int> array;

	cout << "��� ������: ";

	fileRead(fileName, array);

	printArray(array);

	while (end != -1) {

		cout << "\n\n������� ���������� �� 0 �� " << array.size() - 1 << ", ������� ���������� �����(-1 ��������): ";

		int statistic; cin >> statistic; statistic--;

		end = statistic;

		if (statistic > -1) {

			int result(searchingStatistic(array, statistic, 0, array.size() - 1, 1));

			cout << "\n" << ++statistic << "-�� ���������� �������: " << result;

		}
		else if (statistic == -2) printSortArray(array);

	}

}


int searchingStatistic(vector<int>& array, int statistic, int p, int r, int algorithmTime) {

	if (p == r) { //���� ������� ������ �� ������ ��������

		return array[p];

	}
	else {


		pair<int, int> partsIndexes;

		if (algorithmTime == 0) { //�� �������� � ������� �����

			int pIndex = randGenerate(p, r); //��������� ����� �� p �� r
			
			partsIndexes = partition(p, r, array[pIndex], array); //��������� ��������, ��������� �������� �� �����

		}
		else { //�� �������� � ������ ������ �����

			int element = select(array, p, r); //������� ������

			partsIndexes = partition(p, r, element, array); //��������� ��������, ��������� �������� �� �����

		}


		if (statistic >= partsIndexes.first+1 && statistic <= partsIndexes.second) return array[statistic]; //���� ���������� - ������� ������
		else if (statistic < partsIndexes.first+1) return searchingStatistic(array, statistic, p, partsIndexes.first, algorithmTime); //���� ���������� � ����� �����
		else return searchingStatistic(array, statistic, partsIndexes.second + 1, r, algorithmTime); //���� ���������� � ������ �����

	}

}


int select(vector<int>& array, int p, int r) {

	vector<int> medians;

	vector<int> arrayTemp;

	for (int i = p; i <= r; i++) arrayTemp.push_back(array[i]); //������������ ����� �������

	for (int i = 0; i < arrayTemp.size()/5; i++) { //��������� ������ �� ������� �� 5 ��������� � ���������� ���������� 5 �� 7

		sortFiveForSeven(arrayTemp, i);

		medians.push_back(arrayTemp[5*i+2]);

	}

	if (medians.size() == 0) { //���� ������ ������� �� ����� ��� 5 ���������

		for (int i = 0; i < arrayTemp.size(); i++) medians.push_back(arrayTemp[i]);

	}

	arrayTemp.clear();

	while (medians.size() > 5) { //���� ������ ������ ������ 5

		vector<int> mediansTmp;

		for (int i = 0; i < medians.size()/5; i++) { //��������� ������ ������ �� ������� �� 5 ��������� � ���������� ���������� 5 �� 7

			sortFiveForSeven(medians, i);

			mediansTmp.push_back(medians[5 * i + 2]);

		}

		medians = mediansTmp;

	}

	unsigned long pass(0); //��������

	medians = simpleSelect(medians, medians.size(), pass, pass, pass); //��������� ������ ������ �� ������ j ������� �������

	return medians[medians.size()/2]; //���� ������� ������� ������)))

}


pair<int, int> partition(int p, int r, int element, vector<int>& array) {

	int firstIndex(p - 1), endIndex(r); //������� ������ ��������������� ������

	int k = p - 1; //������ ������� 

	while (k!= endIndex) {

		if (array[k + 1] == element) k++; //���� ������� ������� ����� �������� ��������, ������� ������ �������
		else {

			if (array[k + 1] < element) { //���� ������� ������� ������ �������� ���������, ������ ���� � �������� �������� ��������������� ����� � �������

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

				endIndex--; //������� ��������� ��������������� ����� � �����

			}

		}

	}

	pair<int, int> partsIndexes(firstIndex, k); //��������� ������ ����� ������ � ������ ��������� ������

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

	cout << "\n��������������� ������: \n";

	unsigned long pass(0);

	array = simpleSelect(array, array.size(), pass, pass, pass);

	for (int i = 0; i < array.size(); i++) {

		cout << array[i] << "(" << i+1 << ") ";

	}

}
