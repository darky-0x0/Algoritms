#include "Backpack.h"



void lab5task2() {

	string fileName = "Backpack.txt";

	

	vector<pair<int, int>> items; //вещи

	int size(0); //количество типов вещей

	int maxWeight(0); //максимальный вес

	int weight(0); //текущий вес

	int price(0); //текущий прайс

	int maxPrice(0); //максимальная стоимость вещей

	vector<int> itemIndexes; //индексы всех вещей

	vector<int> result;

	readFile(items, size, maxWeight, fileName);

	cout << "Доступные вещи: \n";

	for (int i = 0; i < size; i++) {

		cout << i+1 << "|" << items[i].first << " " << items[i].second << "\n";

	}

	cout << "Вместимость: " << maxWeight;

	_getch();

	backpack(items, size, result, itemIndexes, maxWeight, weight, maxPrice, price);

	printResult(maxPrice, result);



	vector<int> countItems(size, 0);

	result.clear();

	maxPrice = 0;

	int weightRemainder(maxWeight);

	backpack2(items, size, result, countItems, weightRemainder, maxPrice, price, 0);

	cout << "\n\nАлгоритм v2: \nКоличество предметов по индексам: ";

	for (int i = 0; i < result.size(); i++) cout << result[i] << " ";

}


void backpack(vector<pair<int, int>> const items, int const size, vector<int>& result, vector<int>& itemIndexes, int const maxWeight, int& weight, int& maxPrice, int& price) {

	if (maxPrice < price) {

		maxPrice = price;

		result = itemIndexes;
	
	}

	for (int i = 0; i < size; i++) {

		//если при добавлении вещи вес не перевалит на максимальный
		if (weight + items[i].first <= maxWeight) {

			lay(items, i, itemIndexes, weight, price);
			//следующая вещь

			backpack(items, size, result, itemIndexes, maxWeight, weight, maxPrice, price);
			//рекурсия

			layOut(items, i, itemIndexes, weight, price);
			//выкладываем вещь

		}

	}

}


void backpack2(vector<pair<int, int>> const items, int const size, vector<int>& result, vector<int>& itemIndexes, int weightRemainder, int& maxPrice, int price, int k) {

	//если текущая цена меньше максимальной и мы дошли до конца возможных типов предметов
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

	cout << "\n\nРезультат: \nИндексы вещей: ";

	for (int i = 0; i < result.size(); i++) {

		cout << result[i] << " ";

	}

	cout << "\nМаксимально возможная цена: ";

	cout << maxPrice;

}
