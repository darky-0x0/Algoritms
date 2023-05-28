#include "BouncingBall.h"





void lab6task5() {

	cout << "������� ���������� ��������: ";

	int n;
	cin >> n;

	vector<int> steps(n + 3, 0); //������ ��������� ����� + 3 ��������

	bounceBall(n, steps);

	cout << "���������� ��������� ������: " << steps[0];

}


void bounceBall(int n, vector<int>& steps) {

	steps[n] = 1; //������ ��������� ���


	for (int i = n - 1; i >= 0; i--) {

		steps[i] = steps[i + 1] + steps[i + 2] + steps[i + 3];

	}

}
