#include "Backpack.h"



void lab5task2() {

	string fileName = "Backpack.txt";

	

	vector<pair<int, int>> items; //����

	int size(0); //���������� ����� �����

	int maxWeight(0); //������������ ���

	int weight(0); //������� ���

	int price(0); //������� �����

	int maxPrice(0); //������������ ��������� �����

	vector<int> itemIndexes; //������� ���� �����

	vector<int> result;

	readFile(items, size, maxWeight, fileName);

	cout << "��������� ����: \n";

	for (int i = 0; i < size; i++) {

		cout << i+1 << "|" << items[i].first << " " << items[i].second << "\n";

	}

	cout << "�����������: " << maxWeight;

	_getch();

	backpack(items, size, result, itemIndexes, maxWeight, weight, maxPrice, price);

	printResult(maxPrice, result);



	vector<int> countItems(size, 0);

	result.clear();

	maxPrice = 0;

	int weightRemainder(maxWeight);

	backpack2(items, size, result, countItems, weightRemainder, maxPrice, price, 0);

	cout << "\n\n�������� v2: \n���������� ��������� �� ��������: ";

	for (int i = 0; i < result.size(); i++) cout << result[i] << " ";

}


void backpack(vector<pair<int, int>> const items, int const size, vector<int>& result, vector<int>& itemIndexes, int const maxWeight, int& weight, int& maxPrice, int& price) {

	if (maxPrice < price) {

		maxPrice = price;

		result = itemIndexes;
	
	}

	for (int i = 0; i < size; i++) {

		//���� ��� ���������� ���� ��� �� ��������� �� ������������
		if (weight + items[i].first <= maxWeight) {

			lay(items, i, itemIndexes, weight, price);
			//��������� ����

			backpack(items, size, result, itemIndexes, maxWeight, weight, maxPrice, price);
			//��������

			layOut(items, i, itemIndexes, weight, price);
			//����������� ����

		}

	}

}


void backpack2(vector<pair<int, int>> const items, int const size, vector<int>& result, vector<int>& itemIndexes, int weightRemainder, int& maxPrice, int price, int k) {

	//���� ������� ���� ������ ������������ � �� ����� �� ����� ��������� ����� ���������
	if ((maxPrice < price) && (k > size-1)) {

		maxPrice = price;

		result = itemIndexes;

	}
	else {

		if (k <= size-1) {

			for (int i = 0; i == 0 || weightRemainder/(i * items[k].first) > 0; i++) { 

				itemIndexes[k] = i;

				backpack2(items, size, result, itemIndexes, weightRemainder - i * items[k].first, maxPrice, price + i * items[k].second, k + 1);

			}

		}

	}
}


void lay(vector<pair<int, int>> items, int ind, vector<int>& itemIndexes, int& weight, int& price) {

	itemIndexes.push_back(ind+1);

	weight += items[ind].first;

	price += items[ind].second;

}


void layOut(vector<pair<int, int>> items, int ind, vector<int>& itemIndexes, int& weight, int& price) {

	itemIndexes.erase(itemIndexes.end() - 1);

	weight -= items[ind].first;

	price -= items[ind].second;

}


void readFile(vector<pair<int, int>>& items, int& size, int& maxWeight, string fileName) {

	ifstream file;

	file.open(fileName);

	file >> size;

	pair<int, int> item;

	vector<pair<int, int>> itemsTemp(size, item);

	for (int i = 0; i < size; i++) {

		file >> itemsTemp[i].first;

		file >> itemsTemp[i].second;

	}

	file >> maxWeight;

	items = itemsTemp;

	file.close();

}



void printResult(int maxPrice, vector<int> result) {

	cout << "\n\n���������: \n������� �����: ";

	for (int i = 0; i < result.size(); i++) {

		cout << result[i] << " ";

	}

	cout << "\n����������� ��������� ����: ";

	cout << maxPrice;

}
