#include "NumberBoxes.h"




void lab7task2() {

	string fileName = "NumberBoxes.txt";



	cout << "������ �� �����: \n";

	vector<int> numbers;
	vector<string> signs;

	readFile(fileName, signs, numbers);

	vector<int> results(numbers.size());

	for (int i = 0; i < numbers.size(); i++) cout << numbers[i] << " ";
	cout << "\n";
	for (int i = 0; i < signs.size(); i++) cout << signs[i] << " ";
	cout << "\n";

	numberBoxes(signs, numbers, results);

	cout << "\n\n����������: \n";
	for (int i = 0; i < results.size()-1; i++) cout << results[i] << " " << signs[i] << " ";
	cout << results[results.size()-1] << "\n";

}


void numberBoxes(vector<string> signs, vector<int> numbers, vector<int>& results) {
	unsigned long pass(0);

	int Ip(0); //������ ���������, �� ������� �� ����� ���������
	int Ep(numbers.size()-1); //��������� �� ��������� �������

	numbers = simpleSelect(numbers, numbers.size(), pass, pass, pass); //��������� ��������

	vector<int> minNums; //����� �����
	vector<int> maxNums; //������� �����

	for (int i = 0; i < signs.size(); i++) {

		if (signs[i] == ">") maxNums.push_back(i);

		else minNums.push_back(i);

	}

	maxNums.push_back(signs.size()); //�������� ������� �������� ��� �������



	for (int i = 0; i < minNums.size(); i++) { //���������� ����� �����

		results[minNums[i]] = numbers[Ip++]; //��������� ����������� ��������

	}



	for (int i = maxNums.size()-1; i >= 0; i--) { //���������� ������� �����

		int counter(0);

		int endIndex(maxNums[i]); //���������� ����� �������

		int j(i);

		while ((j > 0) && (maxNums[j] == maxNums[j - 1] + 1)) { //���� ��������� ������ ����������� �������� ������ ������ (��������: minNums[0](0) == minNums[0+1](1) - 1)

			counter++;

			j--;

		}

		int startIndex(maxNums[i] - counter); //���������� ����� �������

		if (startIndex == endIndex) { //���� ������� �������

			results[maxNums[i]] = numbers[Ep--]; //��������� ��������� �������

		}
		else { //����� ���� ���� �������

			for (int k = startIndex; k <= endIndex; k++) { //��������� ������� � ����� �������������

				results[k] = numbers[Ep--];

			}

			i -= (endIndex-startIndex); //������� ������ 

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