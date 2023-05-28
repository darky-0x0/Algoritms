#include "NumberBoxes.h"




void lab7task2() {

	string fileName = "NumberBoxes.txt";



	cout << "Данные из файла: \n";

	vector<int> numbers;
	vector<string> signs;

	readFile(fileName, signs, numbers);

	vector<int> results(numbers.size());

	for (int i = 0; i < numbers.size(); i++) cout << numbers[i] << " ";
	cout << "\n";
	for (int i = 0; i < signs.size(); i++) cout << signs[i] << " ";
	cout << "\n";

	numberBoxes(signs, numbers, results);

	cout << "\n\nРезультаты: \n";
	for (int i = 0; i < results.size()-1; i++) cout << results[i] << " " << signs[i] << " ";
	cout << results[results.size()-1] << "\n";

}


void numberBoxes(vector<string> signs, vector<int> numbers, vector<int>& results) {
	unsigned long pass(0);

	int Ip(0); //создаём указатели, по которым мы будем двигаться
	int Ep(numbers.size()-1); //указатель на последнйи элемент

	numbers = simpleSelect(numbers, numbers.size(), pass, pass, pass); //сортируем элементы

	vector<int> minNums; //малые числа
	vector<int> maxNums; //большие числа

	for (int i = 0; i < signs.size(); i++) {

		if (signs[i] == ">") maxNums.push_back(i);

		else minNums.push_back(i);

	}

	maxNums.push_back(signs.size()); //поседний элемент помечаем как больший



	for (int i = 0; i < minNums.size(); i++) { //перебираем малые числа

		results[minNums[i]] = numbers[Ip++]; //добавляем минимальные элементы

	}



	for (int i = maxNums.size()-1; i >= 0; i--) { //перебираем большие числа

		int counter(0);

		int endIndex(maxNums[i]); //определяем конец области

		int j(i);

		while ((j > 0) && (maxNums[j] == maxNums[j - 1] + 1)) { //если следующий индекс минимальных является подряд идущим (Например: minNums[0](0) == minNums[0+1](1) - 1)

			counter++;

			j--;

		}

		int startIndex(maxNums[i] - counter); //определяем конец области

		if (startIndex == endIndex) { //если область нулевая

			results[maxNums[i]] = numbers[Ep--]; //добавляем последний элемент

		}
		else { //иначе если есть область

			for (int k = startIndex; k <= endIndex; k++) { //заполняем область с конца максимальными

				results[k] = numbers[Ep--];

			}

			i -= (endIndex-startIndex); //смещаем индекс 

		}

	}

}


void readFile(string fileName, vector<string>& signs, vector<int>& numbers) {

	int size;

	ifstream file;
	file.open(fileName);

	file >> size;

	for (int i = 0; i < size; i++) {

		int num;

		file >> num;

		numbers.push_back(num);

	}

	for (int i = 0; i < size-1; i++) {

		string sign;

		file >> sign;

		signs.push_back(sign);

	}

	file.close();

}