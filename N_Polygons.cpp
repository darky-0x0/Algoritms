#include "N_Polygons.h"




void lab6task4() {

	cout << "������ ����� �� �����";

	string fileName = "N_Polygons3.txt";

	

	vector<pair<int, int>> coordinates;

	fileRead(fileName, coordinates);
	
	vector<vector<float>> cost(coordinates.size(), vector<float>(coordinates.size())); //������� ��� ������ ����������
	vector<vector<float>> diagonalsLength(coordinates.size(), vector<float>(coordinates.size())); //����� ��������� ����������
	vector<vector<vector<pair<int, int>>>> finalDiagonals(coordinates.size(), vector<vector<pair<int, int>>>(coordinates.size())); //����-�������� ����������. ������ ������ �������� ����� ������� ������� ���������� �� ��� �������� ������ 

	cout << "\n���� ��������� ���������� " << coordinates.size() << "-���������: \n";
	for (int i = 0; i < coordinates.size(); i++) cout << "(" << coordinates[i].first << ";" << coordinates[i].second << ") ";

	int size = coordinates.size();

	cout << "\n\n����� ���������� �� 1 �� n-1 �� ������ �������: \n";

	lengthOfAllDiagonals(diagonalsLength, coordinates); //���������� ����������� ���� ����������

	polygonsCut(diagonalsLength, cost, size, finalDiagonals); //�������� ����



	cout << "\n\n������������ ����������� �� ����������� ������ (��� ����� ������ ��� k, � ����� ������� - l): \n";

	for (int i = 0; i < cost.size(); i++) {

		for (int j = 0; j < cost.size(); j++) {

			cout << cost[i][j] << "\t";

		}

		cout << "\n";
	}

	cout << "\n\n����������� ������ ������: " << cost[0][size - 1];

	cout << "\n\n������ ������ ��������(���������): ";

	for (int i = 0; i < finalDiagonals[0][size - 1].size(); i++) {

		cout << "(" <<finalDiagonals[0][size - 1][i].first + 1 << ";" << finalDiagonals[0][size - 1][i].second + 1 << "), ";
	}

}



void polygonsCut(vector<vector<float>> diagonalsLength, vector<vector<float>>& cost, int size, vector<vector<vector<pair<int, int>>>>& finalDiagonals) {

	int i(0); //����� �������������� ��������

	int k(0), l(0); //����� ���������

	for (int t = 3; t < size; t++) { //������ ����

		for (k = 0, l = t; l < size; k++, l++) { //��������� ��� ������� � �� �����������. �� �������, ���� l �� ����� �� ������� ����� ����������� ��� ����������

			vector<float> cuts; //������ ��� ��������� ������� �� ������ ���������

			vector<vector<pair<int, int>>> diagonals; //������������ ���������� ���������� � ������ ������

			for (int i = k + 1; i < l; i++) { //����������� �� ��������� ������

				float count(0); //��������� ������� �������� ��������

				vector<pair<int, int>> localDiagonals; //������� ��������� ����������

				if (i > k + 2) { //���� ������ ���������

					count += cost[k][i]; //���� ���� �� ��� ���-����� - ���������, ���� �� ������� ��� ��������� �����������

					for (int a = 0; a < finalDiagonals[k][i].size(); a++) localDiagonals.push_back(pair<int, int>(finalDiagonals[k][i][a].first, finalDiagonals[k][i][a].second)); //������������� ��������� ����������� ��������� ������ i-l

				}


				if (i < l - 2) { //���� ������ ���������

					count += cost[i][l]; //���� ���� �� ��� ���-����� - ���������, ���� �� ������� ��� ��������� �����������

					for (int a = 0; a < finalDiagonals[i][l].size(); a++) localDiagonals.push_back(pair<int, int>(finalDiagonals[i][l][a].first, finalDiagonals[i][l][a].second)); //������������� ��������� ����������� ��������� ������ i-l

				}

				if (i == k + 1) { //���� (k;i) �������� ������ �������������� (������� ������ ������ � (i;l))

					count += diagonalsLength[i][l]; //������� ��������� (i;l)

					localDiagonals.push_back(pair<int, int>(i, l)); //��������� ���������

				}

				else if (i == l - 1) { //����� ���� (i;l) �� �������� ������ ��������������

					count += diagonalsLength[k][i]; //������� ��������� (k;i)

					localDiagonals.push_back(pair<int, int>(k, i)); //��������� ���������

				}
				else { //���� � (k;i), � (i;l) �������� ������������ ����������� ������ k-l

					count += diagonalsLength[k][i]; //������� ��������� (k;i)

					localDiagonals.push_back(pair<int, int>(k, i)); //��������� ���������

					count += diagonalsLength[i][l]; //������� ��������� (i;l)

					localDiagonals.push_back(pair<int, int>(i, l)); //��������� ���������

				}


				cuts.push_back(count);

				diagonals.push_back(localDiagonals); 

			}

			float minNum = cuts[0];
			int position(0); //������� ������������ ������� � �������

			for (int s = 1; s < cuts.size(); s++) {
				if (minNum >= cuts[s]) {

					minNum = cuts[s]; //��������� ���������� ������ ���������� ������ k-l
					position = s;

				}
			}

			cost[k][l] = minNum; //����������� ������ ���������� ��� ������ k-l

			finalDiagonals[k][l] = diagonals[position];

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
