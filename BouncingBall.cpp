#include "BouncingBall.h"





void lab6task5() {

	cout << "Введите количество ступенек: ";

	int n;
	cin >> n;

	vector<int> steps(n + 3, 0); //массив возможных ходов + 3 пустышки

	bounceBall(n, steps);

	cout << "Количество маршрутов мячика: " << steps[0];

}


void bounceBall(int n, vector<int>& steps) {

	steps[n] = 1; //ставим начальный шаг


	for (int i = n - 1; i >= 0; i--) {

		steps[i] = steps[i + 1] + steps[i + 2] + steps[i + 3];

	}

}
