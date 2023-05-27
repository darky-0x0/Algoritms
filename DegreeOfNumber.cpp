#include "DegreeOfNumber.h"




void lab6task3() {

	int N;
	cout << "������� �����-������� N: ";
	cin >> N;
	vector<pair<int, string>> Op(N+1);

	calculateMinimumOperations(N, Op);

	cout << "\n����������� ���������� �������� ��� ������ �������: " << Op[N].first;
	cout << "\n����������: " << Op[N].second;

}

void calculateMinimumOperations(int N, vector<pair<int, string>>& Op) {

	Op[1].first = 0;
	Op[1].second = "k";

	for (int i = 2; i <= N; i++) { //��������� ������� ����������

		Op[i].first = Op[i - 1].first + 1; //������ � ���� �������� ������� ��������� �� k;
		Op[i].second = Op[i - 1].second + "*k";

		for (int j = 2; j <= i - 1; j++) { //��������� ����������� ������������ ��� ��������� ����������

			int count = Op[j].first + Op[i - j].first + 1; //��� ������� + 1(����������� ��)
			
			string exp = Op[j].second + "*" + Op[i - j].second;

			if (count < Op[i].first) { //���� ��� ������������� ������

				Op[j].first = count;

				Op[j].second = exp;

			}


			if (i % j == 0) { //��������, ���� ����� ����������� ��� ��������� ��������� i/j � ������� j (����)

				int count = Op[i / j].first + (j - 1); //���

				string exp = "(" + Op[i / j].second + ")^" + to_string(j);

				if (count < Op[i].first) { //���� ����� � �� ������, ��������������

					Op[i].first = count;

					Op[i].second = exp;

				}
				

			}

		}

	}

}