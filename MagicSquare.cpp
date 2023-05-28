#include "MagicSquare.h"






void lab7task1() {

	cout << "Был использован метод полного перебора исходя из словия задачи. \nВозможные варианты: \n";

	vector<bool> nums(10, false); //хранение данных об испольовании цифер
	vector<int> square(9, 0); 

	int index(0);

	magicSuare(nums, square, index);

}

void magicSuare(vector<bool>& nums, vector<int>& square, int index) {

	if (index == 9) {

		if (validationSquare(square)) {

			cout << "\n";

			for (int i = 0; i < 9; i++) {

				if (i % 3 == 0) cout << "\n";

				cout << square[i] << " ";

			}

		 }

	}
	else { //пока не заполним весь квадрат

		for (int i = 0; i < 9; i++) {

			if (!nums[i+1]) {  //проверяем, использовалась ли цифра ранее

				square[index] = i + 1; 

				nums[i+1] = true;

				magicSuare(nums, square, index + 1);

				nums[i+1] = false;

			}

		}

		square[index] = 0;

	}

}


bool validationSquare(vector<int> square) {

	int summ = square[0] + square[1] + square[2]; //сумма, относиелльно которой всё проверяется

	for (int i = 0; i < 3; i++) {

		if (summ != square[i * 3] + square[i * 3 + 1] + square[i * 3 + 2]) return false; //проверка горизонталей

	}

	for (int i = 0; i < 3; i++) {

		if (summ != square[0 + i] + square[3+ i] + square[6+ i]) return false; //проверка вертикалей

	}

	if (summ != square[0] + square[4] + square[8]) return false; //проверка диагоналей

	if (summ != square[2] + square[4] + square[6]) return false;

	return true;

}