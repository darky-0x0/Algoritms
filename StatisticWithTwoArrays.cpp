#include "StatisticWithTwoArrays.h"




void lab7task6() {

	string fileName1 = "Statistic3.txt";
	string fileName2 = "Statistic4.txt";


	cout << "������� �������. ������ ��� ������� � ������ ������� ������� � �������� k-1. \n������� ����� ��������� �� ����� O(n+m), � ���������� O(n+m) �������������� \n������. \n\n���� ����� �������.������������ ��� ���������, � ������� ������� ������ \n������ �������, �� ������ ��.�������������� �������� ���������� � �� ������ \n������� �� ��������.����� ����������� �� ������� ��� �� ���, ������� ��������� \n�� ������� �������.�����(k - 1) - �� �������� ������� ��������, �� ������� ����� \n���������.������� �� ��� � ����� �������.����� �������, �� ������� k - �� \n������� �� O(k)�����.\n\n������� �������.� ������ ������� ������� ������� c �������� i = n / 2 � �������� \n������� ������ �� ������ ������� ������� j, �� ������� ����� ���������� \n�������, ������� a[i].���� i + j = k - 2, �� �� ����� k - �� ���������� ���������� � \n��� ������� a[i].�����, ���� i + j > k - 2, �� ����� ��� �� �������� ���� � ������� a � \n��������� ��������[0, i - 1], � ���� i + j < k - 2, �� � ��������� ��������[i + 1, n - 1].����� \n������ ����� ��������, �� ������� ����������� O(log(n)*log(m)). \n\n";

	vector<int> array1;
	vector<int> array2;

	fileRead(fileName1, array1);
	fileRead(fileName2, array2);

	unsigned long pass(0);

	array1 = simpleExchange(array1, array1.size(), pass, pass, pass);
	array2 = simpleExchange(array2, array2.size(), pass, pass, pass);

	cout << "������ 1: \n";
	for (int i = 0; i < array1.size(); i++) cout << array1[i] << " ";
	cout << "\n������ 2: \n";
	for (int i = 0; i < array2.size(); i++) cout << array2[i] << " ";

	int statistic(0);

	while (statistic != -1) {

		cout << "\n������� ������� ���������� �� 1 �� " << array1.size()+array2.size() << ": ";
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

	int i(0), j(0); //���������

	while (i != array1.size()-1 || j != array2.size()-1) {

		if (array1[i] > array2[j]) array.push_back(array2[j++]); //����������� ���� ��������
		else array.push_back(array1[i++]);

	}

	while (i != array1.size()) array.push_back(array1[i++]);
	while (j != array2.size()) array.push_back(array2[j++]);

//	cout << "\n����� ������: \n";
//	for (int i = 0; i < array.size(); i++) cout << array[i] << " ";

	cout << "\n" << k << "-�� ����������(������� �������): " << array[k-1];

}


void lessSimpleSolution(vector<int>& const array1, vector<int>& const array2, int k) {

	int i(0), j(0); //���������

	int t(0); //����� ��������

	while (((t+1)!=k) && ((i != array1.size() - 1) || (j != array2.size() - 1))) { //�����, ���� �������� == ������� ���������� ��� ������ ����������

		if (array1[i] > array2[j]) j++; 
		else i++;

		t++;	//����������� ���������� ���������

	}

	cout << "\n" << k << "-�� ����������(���� ����� ������� �������): ";

	if (array1[i] < array2[j]) {

		cout << array1[i];

	}
	else {

		cout  << array2[j];

	}

}


int goodSolution(vector<int>& const array1, vector<int>& const array2, int k, int firstIndA1, int lastIndA1, int firstIndA2, int lastIndA2) {

	int i = ((lastIndA1+firstIndA1) / 2); //�������� ������� ������� �������

	int element = array1[i]; //i-�� ������� ������� �������

	int j = binarySearch(array2, firstIndA2, lastIndA2, element); //������� ������� ������� ������ i-�� �� ������ ������� �������� �������

	if (i + j == k - 2) { //���� �����, ���������� a[i]

		return array1[i];

	}
	else if (i + j > k - 2) { //����� ���� k < i+j, ��������� ����� � ����� �����

		return goodSolution(array2, array1, k, firstIndA2, j - 1, firstIndA1, i - 1);

	}
	else { //����� ��������� ����� � ������ �����

		return goodSolution(array2, array1, k, j + 1, lastIndA2, i + 1, lastIndA1);

	}

}


int binarySearch(vector<int> array, int first, int end, int element) { 

	int center;

	bool isEnd = false;

	int minMaxEl(0); //�������, ������������ �������� ��������� ������� ������ i � ������ �������

	int minMaxInd(0);

	while (end >= first) {

		center = (first + end) / 2;

		if ((array[center] < element) && (array[center] > minMaxEl)) { //���� ����������� ������� ������� ������� ������ i-�� ������� � ������ ������������� �� �����������

			minMaxEl = array[center];

			minMaxInd = center;

			first = center + 1; //������� ����� �������

		}

		else if (element < array[center]) { //���� ����������� ������ ������� ������� ������ i-�� �������

			end = center - 1; //������� ������ �������


		}

	}

	return minMaxInd;

}
