#include "ClassicTriangle.h"




void lab6task2() {

	string fileName = "ClassicTriangle.txt";

	vector<vector<int>> triangle;
	vector<vector<pair<int, int>>> results;

	int size(0);


	fileReader(triangle, size, results, fileName);

	classicTriangle(triangle, results, size);

	cout << "�������� �����������/����������� � ������� � ��������:\n";

	printTriangle(triangle, size, results);

	printResults(triangle, results, size);

}



void classicTriangle(vector<vector<int>>& triangle, vector<vector<pair<int, int>>>& results, int size) {

	results[0][1].first = triangle[0][1];

	for (int i = 1; i < size; i++) {

		for (int j = 0; j < size + 1; j++) {

			if (results[i][j].first == 0) { //���� ���� ������

				int left(triangle[i][j]+results[i-1][j-1].first), right(triangle[i][j] + results[i - 1][j].first); //����� � ������ ����

				if (left > right) {

					results[i][j].first = left;
					results[i][j].second = 0; //���������� ����, �� �������� �� ���������

				}
				else if (right > left) {

					results[i][j].first = right;
					results[i][j].second = 1; //���������� ����, �� �������� �� ���������

				}
				else { //���� �����. ��������� �� ���������� � �������, ���� ��������� �������� ����

					results[i][j].first = right;
					
					if(results[i - 1][j - 1].first == -1) results[i][j].second = 1; // ���� ����� ����, ����� ������ ����
					else results[i][j].second = 0; //�����...

				}

			}

		}

	}



}


void printResults(vector<vector<int>> triangle, vector<vector<pair<int, int>>> results, int size) {

	int maxEl(-1);

	int maxInd;

	for (int i = 0; i < size + 1; i++) {

		if (maxEl < results[size - 1][i].first) {

			maxEl = results[size - 1][i].first;
			maxInd = i;

		}
	
	}

	cout << "\n\n���������� ��������� �����: " << maxEl;

	int position(maxInd);
	vector<int> path;

	for (int i = size - 1; i >= 0; i--) { //��������������� ����

		path.push_back(triangle[i][maxInd]);

		if (results[i][maxInd].second == 0) maxInd--; //���� ���� ��� �� ����� �����, ������������ ����

	}

	cout << "\n����: ";
	for (int i = path.size()-1; i >= 0; i--) cout << path[i] << " ";

}


void printTriangle(vector<vector<int>> triangle, int size, vector<vector<pair<int, int>>> results) {

	for (int i = 0; i < size; i++) {

		int j;

		for (j = 1; j < i + 2; j++) {

			cout << triangle[i][j] << "\t";

		}

		for (int t = 0; t < size + 2 - j; t++) cout << "\t";

		for (int j = 1; j < i + 2; j++) {

			cout << results[i][j].first << "\t";

		}

		cout << "\n";

	}

}


void fileReader(vector<vector<int>>& triangle, int& size, vector<vector<pair<int, int>>>& results, string fileName) {

	ifstream file;
	file.open(fileName);

	file >> size;

	pair<int, int> num(-1, -1); //����� ������� ����� � ���� (0 - ����� ����� - ��������; 1 - ������ ����� - ��������)
	vector<vector<pair<int, int>>> result(size, vector<pair<int, int>>(size+1, num));

	vector<vector<int>> triangl(size, vector<int>(size+1, 0));

	for (int i = 0; i < size; i++) {

		for (int j = 1; j < i + 2; j++) {

			file >> triangl[i][j];

			result[i][j].first = 0;

		}

	}

	triangle = triangl;

	results = result;


	file.close();

}