#include"SearchNumbersAlgorithms.h"





void lab1task1() {



		//	long long v;

	long long countAll1(0);

	long long countWithEl1(0);

	long long countAll2(0);

	long long countWithEl2(0);

	long long countAll3(0);

	long long countWithEl3(0);

	long long countAll4(0);

	long long countWithEl4(0);

	

	//	cin >> v;

	size_t size = 100000000;

	int* arr = new int[size];

	for (long long i = 0; i < size; i++) {

		arr[i] = i + 1;

	}

	

	///////////////////////////////////ВЫВОД В КОНСОЛЬ/////////////////////////////////

	//	cout << '\n' << LineSearch(arr, v, size, countAll1, countWithEl1) << "\n";

	//	cout << "Сравнений в целом:" << countAll1 << '\n';

	//	cout << "Сравнений с элементами массива:" << countWithEl1 << '\n';

	//	long long countAll2(0);

	//	long long countWithEl2(0);

	//

	//	cout << '\n' << BarrierSearch(arr, v, size, countAll2, countWithEl2) << "\n";

	//	cout << "Сравнений в целом:" << countAll2 << '\n';

	//	cout << "Сравнений с элементами массива:" << countWithEl2 << '\n';

	//	long long countAll3(0);

	//	long long countWithEl3(0);

	//

	//	cout << '\n' << BinarySearch(arr, v, size, countAll3, countWithEl3) << "\n";

	//	cout << "Сравнений в целом:" << countAll3 << '\n';

	//	cout << "Сравнений с элементами массива:" << countWithEl3 << '\n';

	//	long long countAll4(0);

	//	long long countWithEl4(0);

	//

	//	long long first(0);

	//	long long end(size - 1);

	//	cout << '\n' << RecurseSearch(arr, v, size, countAll4, countWithEl4, first, end) << "\n";

	//	cout << "Сравнений в целом:" << countAll4 << '\n';

	//	cout << "Сравнений с элементами массива:" << countWithEl4 << '\n';

	//

	/////////////////////////////////ЗАПИСЬ В ФАЙЛ/////////////////////////////////

	

	

	{

		ofstream file;

		file.open("SEARCH_DATA.txt");

	

		file << " ____________________________________________________________________________________________________________________________________________\n";

		file << "|                          |  Искомый элемент первый  |  Искомый элемент в середине  |  Искомый элемент последний  |  Искомого элемента нет  |\n";

		file << "|__________________________|__________________________|______________________________|_____________________________|_________________________|\n";

		file << "|                          |  В целом   | С элементом |    В целом   |  С элементом  |   В целом   |  С элементом  |   В целом   |С элементом|\n";

		file << "|__________________________|____________|_____________|______________|_______________|_____________|_______________|_____________|___________|\n";

		LineSearch(arr, 1, size, countAll1, countWithEl1);

		LineSearch(arr, 50000000, size, countAll2, countWithEl2);

		LineSearch(arr, 100000000, size, countAll3, countWithEl3);

		LineSearch(arr, -5, size, countAll4, countWithEl4);

	

		file << "|      Линейный поиск      |      " << countAll1 << "     |      " << countWithEl1 << "     |   " << countAll2 << "  |   " << countWithEl2 << "  |   " << countAll3 << "  |   " << countWithEl3 << "  |   " << countAll4 << "  |   " << countWithEl4 << "  | \n";

		file << "|__________________________|____________|_____________|______________|_______________|_____________|_______________|_____________|___________|\n";

	

		{

			countAll1 = 0;

			countWithEl1 = 0;

			countAll2 = 0;

			countWithEl2 = 0;

			countAll3 = 0;

			countWithEl3 = 0;

			countAll4 = 0;

			countWithEl4 = 0;

		}

	

		BarrierSearch(arr, 1, size, countAll1, countWithEl1);

		BarrierSearch(arr, 50000000, size, countAll2, countWithEl2);

		BarrierSearch(arr, 100000000, size, countAll3, countWithEl3);

		BarrierSearch(arr, -5, size, countAll4, countWithEl4);

	

		file << "| Линейный поиск с барьером|      " << countAll1 << "     |      " << countWithEl1 << "     |   " << countAll2 << "  |   " << countWithEl2 << "  |   " << countAll3 << "  |   " << countWithEl3 << "  |   " << countAll4 << "  |   " << countWithEl4 << "  |\n";

		file << "|__________________________|____________|_____________|______________|_______________|_____________|_______________|_____________|___________|\n";

	

		{

			countAll1 = 0;

			countWithEl1 = 0;

			countAll2 = 0;

			countWithEl2 = 0;

			countAll3 = 0;

			countWithEl3 = 0;

			countAll4 = 0;

			countWithEl4 = 0;

		}

	

		BinarySearch(arr, 1, size, countAll1, countWithEl1);

		BinarySearch(arr, 50000000, size, countAll2, countWithEl2);

		BinarySearch(arr, 100000000, size, countAll3, countWithEl3);

		BinarySearch(arr, -5, size, countAll4, countWithEl4);

	

		file << "|      Бинарный поиск      |     " << countAll1 << "    |      " << countWithEl1 << "     |       " << countAll2 << "      |       " << countWithEl2 << "       |      " << countAll3 << "     |        " << countWithEl3 << "      |    " << countAll4 << "     |    " << countWithEl4 << "     |\n";

		file << "|__________________________|____________|_____________|______________|_______________|_____________|_______________|_____________|___________|\n";

	

		{

			countAll1 = 0;

			countWithEl1 = 0;

			countAll2 = 0;

			countWithEl2 = 0;

			countAll3 = 0;

			countWithEl3 = 0;

			countAll4 = 0;

			countWithEl4 = 0;

		}

	

		long long first(0);

		long long end(size - 1);

		RecurseSearch(arr, 1, size, countAll1, countWithEl1, first, end);

		RecurseSearch(arr, 50000000, size, countAll2, countWithEl2, first, end);

		RecurseSearch(arr, 100000000, size, countAll3, countWithEl3, first, end);

		RecurseSearch(arr, -5, size, countAll4, countWithEl4, first, end);

	

		file << "| Бинарный поиск(рекурсия) |     " << countAll1 << "    |     " << countWithEl1 << "     |       " << countAll2 << "      |       " << countWithEl2 << "        |      " << countAll3 << "    |        " << countWithEl3 << "      |        " << countAll4 << "     |   " << countWithEl4 << "     | \n";

		file << "|__________________________|____________|_____________|______________|_______________|_____________|_______________|_____________|___________|\n";

	

		file.close();

	}

	

	delete[] arr;

	

}


int LineSearch(int* a, int v, size_t size, long long& countAll, long long& countWithEl) {

	long long i = 0;

	while ((i < size) && (a[i] != v)) {

		countAll += 2;

		countWithEl++;

		i++;

	}

	///==================================/// в случае выхода из цикла считаем проверки

	if (i < size) {		//i<size and a[i]!=v

		countAll += 2;

		countWithEl++;

	}

	else countAll++;	//only i<size

	///==================================///

	countAll++; //i!=size 

	if (i != size) {

		return i;

	}

	return -1;

}

int BarrierSearch(int* a, int v, size_t size, long long& countAll, long long& countWithEl) {

	long long last = a[size - 1];

	int* newArr = new int[size + 1];

	for (int i = 0; i < size; i++) {

		newArr[i] = a[i];

	}

	newArr[size] = v;

	size_t i = 0;

	while (newArr[i] != v) {

		countWithEl++;		//a[i] != v

		countAll++;			//a[i] != v

		i++;

	}

	///==================================///  при выходе из цила считаем проверки

	countWithEl++;		//a[i] != v

	countAll++;			//a[i] != v

	///==================================///

	delete[] newArr;

	if (i != (size)) {

		countAll++;	//i!=(size-1)

		return i;

	}

	countAll++; //uncorrect if

	return -1;

}

int BinarySearch(int* a, int v, size_t size, long long& countAll, long long& countWithEl) {

	long long first = 0;

	long long end = size - 1;

	long long center;

	bool isEnd = false;

	while ((isEnd == false) && (end >= first)) {

		countAll += 2;		//isEnd==false and end>=first

		center = (first + end) / 2;

		if (a[center] == v) {

			isEnd = true;

			countWithEl++;		//a[center]==v

			countAll++;			//a[center]==v

		}

		else if (v < a[center]) {

			end = center - 1;

			countAll += 2;		//a[center]==v and v<a[center]

			countWithEl += 2;	//a[center]==v and v<a[center]

		}

		else {

			first = center + 1;

			countAll += 2;		//a[center]==v and v<a[center]

			countWithEl += 2;	//a[center]==v and v<a[center]

		}

	}

	///==================================///  при выходе из цила считаем проверки

	if (isEnd == false) {		//isEnd==false and end>=first

		countAll += 2;

	}

	else countAll++;	//isEnd==false

	///==================================///

	countAll++; //isEnd==true

	if (isEnd == true) return center;

	else return -1;

}

int RecurseSearch(int* a, int v, size_t size, long long& countAll, long long& countWithEl, long long first, long long end) {

	if (first > end) {		//end>=first

		countAll++;

		return -1;

	}

	countAll++; //при выходе из условия

	long long center = (first + end) / 2;

	if (a[center] == v) {

		countAll++;			//a[center]==v

		countWithEl++;		//a[center]==v

		return center;

	}

	else if (a[center] > v) {

		countAll += 2;			//a[center]==v and v<a[center]

		countWithEl += 2;		//a[center]==v and v<a[center]

		return RecurseSearch(a, v, size, countAll, countWithEl, first, center - 1);

	}

	else {

		countAll += 2;			//a[center]==v and v<a[center]

		countWithEl += 2;		//a[center]==v and v<a[center]

		return RecurseSearch(a, v, size, countAll, countWithEl, center + 1, end);

	}

}
