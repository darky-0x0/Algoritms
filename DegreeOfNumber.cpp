#include "DegreeOfNumber.h"




void lab6task3() {

	int N;
	cout << "Введите число-степень N: ";
	cin >> N;
	vector<pair<int, string>> Op(N+1);

	calculateMinimumOperations(N, Op);

	cout << "\nМинимальное количество операций для данной степени: " << Op[N].first;
	cout << "\nВыражениее: " << Op[N].second;

}

void calculateMinimumOperations(int N, vector<pair<int, string>>& Op) {

	Op[1].first = 0;
	Op[1].second = "k";

	for (int i = 2; i <= N; i++) { //поочердёно находим результаты

		Op[i].first = Op[i - 1].first + 1; //просто в упор умножаем прошлый результат на k;
		Op[i].second = Op[i - 1].second + "*k";

		for (int j = 2; j <= i - 1; j++) { //проверяем возможность перемножения уже имеющихся множителей

			int count = Op[j].first + Op[i - j].first + 1; //два решения + 1(перемножаем их)
			
			string exp = Op[j].second + "*" + Op[i - j].second;

			if (count < Op[i].first) { //если оно действительно меньше

				Op[j].first = count;

				Op[j].second = exp;

			}


			if (i % j == 0) { //проверка, если можно представить уже имеющийся результат i/j в степени j (ниже)

				int count = Op[i / j].first + (j - 1); //тут

				string exp = "(" + Op[i / j].second + ")^" + to_string(j);

				if (count < Op[i].first) { //если можно и он меньше, перезаписываем

					Op[i].first = count;

					Op[i].second = exp;

				}
				

			}

		}

	}

}