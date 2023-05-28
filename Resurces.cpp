#include "Resurces.h"





void lab7task3() {

	string fileName = "Resurces2.txt";



	cout << "������: \n";

	vector<vector<pair<int, int>>> resurces; //������� ��������

	vector<pair<pair<int, int>, int>> requests; //������ ������ (�����(������-���������), ������)

	int resurceSize; //������ �������

	fileRead(fileName, requests, resurceSize);

	for (int i = 0; i < requests.size(); i++) cout << "(" << requests[i].first.first << ";" << requests[i].first.second << "), ";

	resurcesDistribution(requests, resurces, resurceSize);

	_getch();

	cout << "\n\n";

	printResurces(resurces);

}


void resurcesDistribution(vector<pair<pair<int, int>, int>>& requests, vector<vector<pair<int, int>>>& resurces, int& resurceSize) {

	sortRequests(requests); //��������� ������ �� ���������� �������

	vector<int> resurceCount(resurceSize);

	for (int i = 0; i < requests.size(); i++) {

		for (int j = requests[i].first.first; j < requests[i].first.second; j++) resurceCount[j]++; //������� �������� �� ������ �������

	}

	int max(0);
	for (int i = 0; i < resurceCount.size(); i++) if (resurceCount[i] > max) max = resurceCount[i]; //������� ���������� ����� ����������� ������


	int minResurce = max; //���������� ��������� ����� ��������
	resurceCount.clear();



	for (int i = 0; i < requests.size(); i++) { //��������� ���������� �� ���� �������

		vector<int> exceptions(minResurce+1); //����������� �������

		for (int j = i; j >= 0; j--) { //��������� ������ ����� �������� �� ���������

			if (requests[i].first.first <= requests[j].first.second) exceptions[requests[j].second]++; //���� ���������� ������ ��������� ��� ������� �� �������, �� �� ������� �������� ����� ������� ����������

		}

		int resurceNum(1); //����� �������

		while ((resurceNum <= minResurce) && (requests[i].second == 0)) {

			if (exceptions[resurceNum] == 0) { //���� ������ ��������

				requests[i].second = resurceNum;

			}

			resurceNum++;

		}

	}

	vector<vector<pair<int, int>>> resurcesTEMP(minResurce+1);

	for (int i = 0; i < requests.size(); i++) { //������������ ������ �� �������

		resurcesTEMP[requests[i].second].push_back(requests[i].first); 

	}

	resurces = resurcesTEMP;

}


void sortRequests(vector<pair<pair<int, int>, int>>& requests) {

	for (int i = 1; i < requests.size(); i++) { //���������� ���������

		for (int j = 0; j < requests.size()-i; j++) {

			if (requests[j].first > requests[j + 1].first) {

				pair<pair<int, int>, int> temp;

				temp = requests[j];

				requests[j] = requests[j + 1];

				requests[j + 1] = temp;

			}

		}

	}

}


void fileRead(string fileName, vector<pair<pair<int, int>, int>>& requests, int& resurceSize) {

	ifstream file;
	file.open(fileName);

	file >> resurceSize;

	int size;

	file >> size;

	vector<pair<pair<int, int>, int>> requestes(size, pair<pair<int, int>, int>(pair<int, int>(0, 0), 0));

	for (int i = 0; i < size; i++) {

		file >> requestes[i].first.first >> requestes[i].first.second;

	}

	file.close();

	requests = requestes;

}


void printResurces(vector<vector<pair<int, int>>> resurces) {

	for (int i = 1; i < resurces.size(); i++) {

		cout << "\n" << i << " ������: \n";

		for (int j = 0; j < resurces[i].size(); j++) {

			cout << "(" << resurces[i][j].first << ";" << resurces[i][j].second << "), ";

		}

	}


}
