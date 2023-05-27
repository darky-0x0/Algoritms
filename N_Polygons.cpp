#include "N_Polygons.h"




void lab6task4() {

	cout << "������ ����� �� �����";

	string fileName = "N_Polygons2.txt";

	

	vector<pair<int, int>> coordinates;

	fileRead(fileName, coordinates);
	
	vector<vector<float>> cost(coordinates.size(), vector<float>(coordinates.size())); //������� ��� ������ ����������
	vector<vector<float>> diagonalsLength(coordinates.size(), vector<float>(coordinates.size()));

	cout << "\n���� ��������� ���������� " << coordinates.size() << "-���������: \n";
	for (int i = 0; i < coordinates.size(); i++) cout << "(" << coordinates[i].first << ";" << coordinates[i].second << ") ";

	int size = coordinates.size();

	cout << "\n\n����� ���������� �� 1 �� n-1 �� ������ �������: \n";

	lengthOfAllDiagonals(diagonalsLength, coordinates); //���������� ����������� ���� ����������

	polygonsCut(diagonalsLength, cost, size); //�������� ����



	cout << "\n\n������������ ����������� �� ����������� ������ (��� ����� ������ ��� k, � ����� ������� - l): \n";

	for (int i = 0; i < cost.size(); i++) {

		for (int j = 0; j < cost.size(); j++) {

			cout << cost[i][j] << "\t";

		}

		cout << "\n";
	}

	cout << "\n\n����������� ������ ������: " << cost[0][size - 1];

}



void polygonsCut(vector<vector<float>> diagonalsLength, vector<vector<float>>& cost, int size) {

	int i(0); //����� �������������� ��������

	int k(0), l(0); //����� ���������

	for (int t = 3; t < size; t++) { //������ ����

		for (k = 0, l = t; l < size; k++, l++) { //��������� ��� ������� � �� �����������. �� �������, ���� l �� ����� �� ������� ����� ����������� ��� ����������

			vector<float> cuts; //������ ��� ��������� ������� �� ������ ���������

			for (int i = k + 1; i < l; i++) { //����������� �� ��������� ������

				float count(0);

				if (i == k + 1) { //���� (k;i) �������� ������ �������������� (������� ������ ������ � (i;l))

					count += diagonalsLength[i][l]; //������� ��������� (i;l)

					if (!(i == l - 2)) { //���� (i;l) �� �������� �������������, � ��������� ������ ������ � ����� ���������� (n == 4)

						count += cost[i][l]; //����������� ����� l-i+1-��������������

					}

				}

				else if (i == l - 1) { //����� ���� (i;l) �� �������� ������ ��������������

					count += diagonalsLength[k][i]; //������� ��������� (k;i)

					if (!(i == k + 2)) { //���� (k;i) �� �������� �������������, � ��������� ������ ������ � ����� ���������� (n == 4)

						count += cost[k][i]; //����������� ����� i-k+1-��������������

					}


				}
				else { //���� � (k;i), � (i;l) �������� ������������ ����������� ������ k-l

					count += diagonalsLength[k][i]; //������� ��������� (k;i)

					if (!(i == k + 2)) count += cost[k][i]; //���� ���� �� ��� ���-����� - ���������, ���� �� ������� ��� ��������� �����������

					count += diagonalsLength[i][l];

					if (!(i == l - 2)) count += cost[i][l]; //���� ���� �� ��� ���-����� - ���������, ���� �� ������� ��� ��������� �����������

				}

				cuts.push_back(count);

			}

			float minNum = cuts[0];

			for (int s = 1; s < cuts.size(); s++) if (minNum > cuts[s]) minNum = cuts[s]; //��������� ���������� ������ ���������� ������ k-l

			cost[k][l] = minNum; //����������� ������ ���������� ��� ������ k-l

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
