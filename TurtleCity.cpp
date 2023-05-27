#include "TurtleCity.h"




void lab6task1() {

	string fileName = "TurtleCity.txt";

	

	vector<vector<int>> fieldValue;

	vector<vector<pair<int, int>>> resultField; //���� <��������, ������ � ����>

	pair<int, int> size;

	fileRead(fieldValue, resultField, size, fileName);

	pair<int, int> startPosition(1, 1);
	pair<int, int> endPosition(size.first * 2 - 1, size.second * 2 - 1);

	cout << "������ ���� ����� �� �����\n���� �������� 2 ����: ���� � ������������ ���������� \\ ���� � ��������� ������������� ������\n���������� ��� ������� ����: \n\t- � - ������ ��������� ��� �� �� ����������; \n\t- � ������ ����������� ������� ��������� ���������.\n���������� ��� ������ ����: \n\t- � - ������ ���������.\n\n���� ����������� ��������:\t\t\t����������:\n";

	turtleCity(fieldValue, resultField, size);
	
	printField(fieldValue, resultField, size);

	cout << "\n\n����������� ��������� ��� ��������: " << resultField[endPosition.first][endPosition.second].first;

	printPath(resultField, startPosition, endPosition, size);

}


void turtleCity(vector<vector<int>>& fieldValue, vector<vector<pair<int, int>>>& resultField, pair<int, int>size) {

	for (int i = 1; i < size.first * 2; i += 2) {

		for (int j = 1; j < size.second * 2; j += 2) {

			if (!(i == 1 && j == 1)) { //������� ��������� ������

				int trav; //�����������/������ ��� �������� ��� (0 - ��� ��� �������� �� �������������� �����, 1 - �� ������������)

				int sumX(-1), sumY(-1), *minSum(0);


				if (fieldValue[i - 1][j] == -1 && fieldValue[i][j - 1] == -1) resultField[i][j].first = -1; //���� � ������ ����� �� ������� 
				else {


					if (fieldValue[i - 1][j] != -1) { //������� ����������� ��������� ������. ���� ��� �� -1, ������� ����� �������

						sumY = resultField[i - 2][j].first + fieldValue[i - 1][j]; //� �������� ���������� ��������� ��������� ������

						if (!(i - 2 == 1 && j == 1)) { //�������� ��������� ������, � ������� ��� �����������

							if (resultField[i - 2][j].second == 0) sumY += fieldValue[i - 2][j]; //���� ������� ���� ����������� �������� �� �����������, ��������� ��������� �������� �� ������� ����������

						}

					}
					else {

						minSum = &sumX; //����������� ��������� ������ �� ����� �� X
						trav = 0; //�������������� ��� (�� �)

					}

					if (fieldValue[i][j - 1] != -1) { //������� ����������� ��������� ������. ���� ��� �� -1, ������� ����� ������

						sumX = resultField[i][j - 2].first + fieldValue[i][j - 1]; //� �������� ���������� ��������� ��������� ������

						if (!(i - 2 == 1 && j == 1)) { //�������� ��������� ������, ������� �� ����� �������� �����������

							if (resultField[i][j - 2].second == 1) sumX += fieldValue[i][j - 2]; //���� ������� ���� ����������� �������� �� ���������, ��������� ��������� �������� �� ������� ����������

						}

					}
					else {

						minSum = &sumY; //����������� ��������� ������ �� ����� �� Y
						trav = 1; //������������ ��� (�� Y)

					}


					if (sumY == -1 || sumX == -1) { //���� ���������� ������ ���� ���

						resultField[i][j].first = *minSum; 
						resultField[i][j].second = trav;

					}
					else { //����� ���������� ��� ����

						if (sumX < sumY) { //�� ����������� ��� �������, ��� �� ���������

							resultField[i][j].first = sumX;
							resultField[i][j].second = 0;

						}
						else { //�����...

							resultField[i][j].first = sumY;
							resultField[i][j].second = 1;

						}

					}

				}


			}

		}

	}

}


void fileRead(vector<vector<int>>& fieldValue, vector<vector<pair<int, int>>>& resultField, pair<int, int>& size, string fileName) {

	ifstream file;
	file.open(fileName);

	file >> size.first >> size.second;

	vector<vector<int>> fieldTEMP(size.first*2-1, vector<int>(size.second * 2 - 1, -1)); //��������� ������� ������
	vector<pair<int, int>> line(size.second * 2 - 1, pair<int, int>(-1, -1));
	vector<vector<pair<int, int>>> resultTEMP(size.first*2-1, line); //��������� ������ �����������

	for (int i = 0; i < size.first * 2 - 1; i += 2) { //��������� �������������� ��������

		for (int j = 1; j < size.second * 2 - 1; j += 2) {

			file >> fieldTEMP[i][j];

		}

	}

	for (int i = 0; i < size.second * 2 - 1; i += 2) { //��������� ������������ ��������

		for (int j = 1; j < size.first * 2 - 1; j += 2) {

			file >> fieldTEMP[j][i];

		}

	}

	for (int i = 0; i < size.first * 2 - 1; i += 2) { //��������� �������� �� �����������

		for (int j = 0; j < size.second * 2 - 1; j += 2) {

			file >> fieldTEMP[i][j];

			resultTEMP[i][j].first = 0;

		}

	}


	file.close();


	vector<vector<int>> fieldTEMP2(size.first * 2 + 1, vector<int>(size.second * 2 + 1, -1)); //������ ������� ������ � "�������� ������������"
	vector<pair<int, int>> line2(size.second * 2 + 1, pair<int, int>(-1, -1));
	vector<vector<pair<int, int>>> resultTEMP2(size.first * 2 + 1, line2); //������ ������ � ������������ � "�������� ������������"

	for (int i = 1; i < size.first*2; i++) {

		for (int j = 1; j < size.second*2; j++) {

			fieldTEMP2[i][j] = fieldTEMP[i - 1][j - 1];
			resultTEMP2[i][j].first = resultTEMP[i - 1][j - 1].first;

		}

	}

	resultField = resultTEMP2;
	fieldValue = fieldTEMP2;

}


void printField(vector<vector<int>>& fieldValue, vector<vector<pair<int, int>>>& resultField, pair<int, int> size) {

	for (int i = 1; i < size.first * 2; i++) {

		for (int j = 1; j < size.second * 2; j++) {

			if (fieldValue[i][j] == -1) cout << "X";

			else cout << fieldValue[i][j];

			if ((j != size.second * 2 - 1) && (i % 2 == 1)) cout << " - ";
			else if (i % 2 == 0) cout << "   ";

		}



		cout << "\t\t\t";

		for (int j = 1; j < size.second * 2; j++) {

			if ((i % 2 != j % 2) && (fieldValue[i][j] == -1)) cout << "T";

			else if (resultField[i][j].first == -1) cout << "X";

			else cout << resultField[i][j].first;

			if ((j != size.second * 2 - 1) && (i % 2 == 1)) cout << " - ";
			else if (i % 2 == 0) {

				if (j % 2 == 0) cout << "    ";
				else cout << "   ";

			}

		}



		if (i != size.first * 2 - 1) {

			cout << "\n";
			for (int i = 1; i < size.second; i++) cout << "|       ";
			cout << "|";

		}



		
		if (i != size.first * 2 - 1) {

			cout << "\t\t\t";
			for (int i = 1; i < size.second; i++) cout << "|        ";
			cout << "|\n";

		}

	}

}


void printPath(vector<vector<pair<int, int>>> resultField, pair<int, int> startPosition, pair<int, int> endPosition, pair<int, int> size) {

	vector<pair<int, int>> path;

	int X(size.second), Y(size.first); //���������� �������

	bool isEnd = false;

	while (isEnd == false) {

		path.push_back(pair<int, int>(Y, X));

		if (resultField[endPosition.first][endPosition.second].second == 0) { //��������� �����������

			endPosition.second -= 2;
			X--; //��������� ��������

		}
		else if (resultField[endPosition.first][endPosition.second].second == 1) {

			endPosition.first -= 2;
			Y--;

		}
		else isEnd = true;

	}

	cout << "\n����: ";

	for (int i = path.size() - 1; i >= 0; i--) {

		cout << "(" << path[i].first << ":" << path[i].second << ") ";

	}

}
