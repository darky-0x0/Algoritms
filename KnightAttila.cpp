#include "KnightAtilla.h"



const int rateKnight[8][2] = { {-2, 1},{-1, 2},{1, 2},{2, 1},{2, -1},{1, -2},{-1, -2},{-2, -1} };

bool isEndAttila = false;

bool kingDefeated = false;



void lab4task7() {

	string fileName = "AttilaKnight.txt";




	int N = 8; //����������� ����
	
	int count(2); //������� ��������

	pair<int, int> knight; //������� ����

	pair<int, int> startPosition(knight); //��������� ������� ���� 

	pair<int, int> king; //������� ������

	vector<vector<int>> field(createField(N)); //����

	vector<vector<int>> result(field); //���������

	fileRead(field, knight, king, fileName);

	field[knight.first][knight.second] = -2; field[king.first][king.second] = -3;

	cout << "�������� ����:\n";

	printField(field, N, startPosition);

	field[knight.first][knight.second] = 1; field[king.first][king.second] = 0;

	_getch();

	AttilaKnight(field, N, knight, startPosition, king, result, count);

	if (isEndAttila == true) {

		cout << "\n\n���������� ����:\n";

		printField(result, N, startPosition);

	}
	else {

		cout << "\n����, ������� ������������� ������� ������, ���\n";

	}

	isEndAttila = false; //���������� ���������� ����������

	kingDefeated = false;

}


void AttilaKnight(vector<vector<int>>& field, int size, pair<int, int>& knight, pair<int, int> const startPosition, pair<int, int> const king, vector<vector<int>>& result, int count) {

	if ((kingDefeated == true) && ((knight.first == startPosition.first) && (knight.second == startPosition.second))) { //���� ���� �������� ����� ������ ������ � �� ��������� � ������

		isEndAttila = true;

		result = field;
		//���������� ���������

	}
	else {

		for (int i = 0; (i < 8) && (isEndAttila == false); i++) { //������� ��������� �����

			pair<int, int> newIndex;

			newIndex.first = knight.first + rateKnight[i][0];

			newIndex.second = knight.second + rateKnight[i][1];

			//�������, ���� ������ ������ || ������� �� ��������� �������, ���� ������ ��������
			if ((field[newIndex.first][newIndex.second] == 0) || ((field[newIndex.first][newIndex.second] == 1) && kingDefeated == true)) { 

				NextStep(field, newIndex, count);
				//��� �����

				if ((newIndex.first == king.first) && (newIndex.second == king.second)) kingDefeated = true; //��������, ���� �������� ������

				AttilaKnight(field, size, newIndex, startPosition, king, result, count + 1);
				//��������

				PreviewStep(field, newIndex);
				//��� �����

				if ((newIndex.first == king.first) && (newIndex.second == king.second)) kingDefeated = false; //����� �� ������ ������������ �����

			}

		}

	}

}

void NextStep(vector<vector<int>>& field, pair<int, int> newIndex, int count) {

	field[newIndex.first][newIndex.second] = count;

}


void PreviewStep(vector<vector<int>>& field, pair<int, int> newIndex) {

	field[newIndex.first][newIndex.second] = 0;

}

void printField(vector<vector<int>> field, int size, pair<int, int> startPosition) {

	for (int i = 2; i < size+2; i++) {

		for (int j = 2; j < size+2; j++) {

			if (i == startPosition.first && j == startPosition.second) cout << "K" << "\t";

			else if (field[i][j] == -3) cout << "F" << "\t";

			else if (field[i][j] == -1) cout << " - \t";
			
			else cout << field[i][j] << "\t";

		}

		cout << "\n";

	}

}

void fileRead(vector<vector<int>>& field, pair<int, int>& knight, pair<int, int>& king, string fileName) {

	ifstream file;

	int x, y;

	file.open(fileName);

	file >> knight.first; knight.first += 2;
	
	file >> knight.second; knight.second += 2;

	file >> king.first; king.first += 2;

	file >> king.second; king.second += 2;

	while (!(file.eof())) {

		file >> x;

		file >> y;

		field[x+2][y+2] = -1;

	}

	file.close();

}


vector<vector<int>> createField(int size) {

	vector<int> arr(size + 4, -1);

	vector<int> arr2(size + 4, 0);

	arr2[0] = -1; arr2[1] = -1; arr2[size + 2] = -1; arr2[size + 3] = -1;

	vector<vector<int>> field(size + 4, arr2);

	field[0] = arr; field[1] = arr; field[size + 2] = arr; field[size + 3] = arr;
	
	return field;

}