#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include "Temp.h"
using namespace std;


#pragma region task_funct

void task1();
void task2();
void task3();

void task4();

void task5();
void task6();
void task7();

void task8();
void task9();
void task10();
void task11();
void task12();
void task13();
void task14();

void task15();
void task16();
void task17();
void task18();

void task19();
void task20();
void task21();
void task22();
void task23();
void task24();

void task25();
void task26();
void task27();
void task28();
void task29();
void task30();
void task31();

void task32();

#pragma endregion



#pragma region funct

int LineSearch(int* a, int v, size_t size, long long& countAll, long long& countWithEl);
int BarrierSearch(int* a, int v, size_t size, long long& countAll, long long& countWithEl);
int BinarySearch(int* a, int v, size_t size, long long& countAll, long long& countWithEl);
int RecurseSearch(int* a, int v, size_t size, long long& countAll, long long& countWithEl, long long first, long long end);
int TDArrayLineSearch(int** a, int v, size_t sizeA, size_t sizeB, int& A, int& B);
int TDArrayBarrierSearch(int** a, int v, size_t sizeA, size_t sizeB, int& A, int& B);
int TDArrayBinarySearch(int** a, int v, size_t sizeA, size_t sizeB, int& A, int& B, int up, int down, int right, int left);
int** FileRead(string filename, int& n, int& m);
string** FileReader2(string filename, int& n, int& m);
int LineSearchStr(string str, string substr, int& count);

int boyerMoore(string& s, string& x, int& c);
int* createArr(string& s);
int KnutMorrisPratt(string& s, string& x, int& c);
int karpRabin(string& s, string& x, int& c, int& hashs);
int SymbolHash(string& s);

void createFilesForSort();
vector<int> simpleSort(vector<int> array, int size, int m);
vector<int> sortingByParity(vector<int> array, int size);
vector<int> simpleSelect(vector<int> array, int size, unsigned long int &comparisonWithElement, unsigned long int &comparisionWithNotElement, unsigned long int &countReplace);
vector<int> simpleExchange(vector<int> array, int size, unsigned long int& comparisonWithElement, unsigned long int& comparisionWithNotElement, unsigned long int& countReplace);
vector<int> simpleExchangeUpgrade(vector<int> array, int size, unsigned long int& comparisonWithElement, unsigned long int& comparisionWithNotElement, unsigned long int& countReplace);
vector<int> simpleExchangeShaker(vector<int> array, int size, unsigned long int& comparisonWithElement, unsigned long int& comparisionWithNotElement, unsigned long int& countReplace);
vector<int> insertionSort(vector<int> array, int size, unsigned long int& comparisonWithElement, unsigned long int& comparisionWithNotElement, unsigned long int& countReplace);
vector<int> insertionSortWithBarrier(vector<int> arrayA, int size, unsigned long int& comparisonWithElement, unsigned long int& comparisionWithNotElement, unsigned long int& countReplace);
vector<int> mergeSort(vector<int> array, int size, int& count, unsigned long int& comparisonWithElement, unsigned long int& comparisionWithNotElement, unsigned long int& countReplace);
void sortHoar(vector<int>& array, int first, int last, int& count, unsigned long int& comparisonWithElement, unsigned long int& comparisionWithNotElement, unsigned long int& countReplace);

void ArrangementOfQueensMain(int N);
bool ArrangementOfQueensRecurs(vector<int> &field, vector<int> &vertical, vector<int> &diagonalUp, vector<int> &diagonalDown, int &count, int size);
void NextStep(vector<int>& field, vector<int>& vertical, vector<int>& diagonalUp, vector<int>& diagonalDown, int& count, int size, int index);
void PreviewStep(vector<int>& field, vector<int>& vertical, vector<int>& diagonalUp, vector<int>& diagonalDown, int& count, int size, int index);
void NextStep(vector<int>& field, vector<int>& queensField, int index, int size, int n);
void PreviewStep(vector<int>& field, vector<int>& queensField, int index, int size, int n);
bool AllCombinationsArrangementOfQueensRecurs(vector<int>& field, vector<int>& vertical, vector<int>& diagonalUp, vector<int>& diagonalDown, int& count, int N, bool& ifFound);
void CompactArrangementOfQueens(vector<int>& mainField, vector<int>& queensField, int n, int& fields, vector<int>& result);
void AttackOfQueens(const int p, const int n, vector<int>& MainField, vector<int>& queensField, vector<int>& result, int& queensCount, int thisStep, int size, int count);
int GetEmpty(vector<int> mainField);
void NextStep(vector<int>& MainField, vector<int>& queensField, int pos);
void PreviewStep(vector<int>& MainField, vector<int>& queensField, int pos);
void SmallestNumberOfMoves(int& minMoves, int& countMoves, vector<int>& MainField, vector<int>& queensIndexes, vector<int>& result, int size, int currentDirection = 0, int pos = 0, int n = 0);
void NextStep(vector<int>& mainField, int index);
vector<int> Step(vector<int>& field, int startInd, int pos, int n);
void PreviewStep(vector<int>& field, vector<int> oneStep);
void KnightTraversingTheChessboard(int** field, int N, int M, vector<int> position, vector<int>& result);
int countingSteps(int** field, int N, int M, vector<int> position);
int getEmptyCells(int** field, int N, int M);
void KnightTraversingTheChessboard(int** field, int N, int M, vector<int> position, int& result);
void ArrangementOfMagaraja(vector<int>& field, vector<int>& vertical, vector<int>& diagonalUp, vector<int>& diagonalDown, vector<int>& knight, int& count, int size);
void NextStepKnight(vector<int>& knight, int index, vector<int>& indexes);
void PreviewStepKnight(vector<int> indexes, vector<int>& knight);

vector<vector<int>> read_maze();
void find_way(vector<vector<int>>& maze, int startx, int starty, int endx, int endy, vector<vector<int>>& result_maze, bool& flag, int& turn);
void set_points(vector<vector<int>>& maze, int& startx, int& starty, int& endx, int& endy);
void set(int& n, vector<int>& v, vector<int>& w, int& W);
void find_max_cost(int types, int cur_weight, int cur_cost, vector<int>& weight, vector<int>& price, int MAXWEIGHT, vector<int>& backpack, vector<int>& backpack_result);
int backpack_cost(vector<int>& backpack, vector<int>& price);
void print(vector<int> backpack);
void set_table();

#pragma endregion




const int rateKnight[8][2] = { {-2, 1},{-1, 2},{1, 2},{2, 1},{2, -1},{1, -2},{-1, -2},{-2, -1} };

const int rateMaze[4][2] = { {-1,0},{0, 1},{1, 0},{0, -1} };





int main()
{
	bool rev = true;
	setlocale(0, "");
	while (rev == true) {
		cout << "Выберите задачу (или 0 для выхода): ";
		int key;
		cin >> key;

		switch (key) {
		case 1: system("cls");
			task1();
			break;
		case 2: system("cls");
			task2();
			break;
		case 3: system("cls");
			task3();
			break;
		case 4: system("cls");
			task4();
			break;
		case 5: system("cls");
			task5();
			break;
		case 6: system("cls");
			task6();
			break;
		case 7: system("cls");
			task7();
			break;
		case 8: system("cls");
			task8();
			break;
		case 9: system("cls");
			task9();
			break;
		case 10: system("cls");
			task10();
			break;
		case 11: system("cls");
			task11();
			break;
		case 12: system("cls");
			task12();
			break;
		case 13: system("cls");
			task13();
			break;
		case 14: system("cls");
			task14();
			break;
		case 15: system("cls");
			task15();
			break;
		case 16: system("cls");
			task16();
			break;
		case 17: system("cls");
			task17();
			break;
		case 18: system("cls");
			task18();
			break;
		case 19: system("cls");
			task19();
			break;
		case 20: system("cls");
			task20();
			break;
		case 21: system("cls");
			task21();
			break;
		case 22: system("cls");
			task22();
			break;
		case 23: system("cls");
			task23();
			break;
		case 24: system("cls");
			task24();
			break;
		case 25: system("cls");
			task25();
			break;
		case 26: system("cls");
			task26();
			break;
		case 27: system("cls");
			task27();
			break;
		case 28: system("cls");
			task28();
			break;
		case 29: system("cls");
			task29();
			break;
		case 30: system("cls");
			task30();
			break;
		case 31: system("cls");
			task31();
			break;
		case 32: system("cls");
			task32();
			break;
		case 0: rev = false;
			break;
		}
	}
}









#pragma region tasks
//ЛАБА 1
void task1()
{
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

void task2()
{
	int n, m, k(1), v, A, B, res;
	cout << "Введите размерность двумерного массива N(эл/ст) x M(эл/стр): ";
	cin >> n >> m;
	system("cls");
	cout << "Введите элемент который будем искать от 1 до " << n * m << ": ";
 	cin >> v;
	int** arr = new int*[n];
	system("cls");
	for (int i = 0; i < n; i++) {
		arr[i] = new int[m];
		for (int j = 0; j < m; j++) {
			arr[i][j] = k++;
		}
	}
	res = TDArrayLineSearch(arr, v, n, m, A, B);
	if (res == -1) cout << "Такого элемента не найдено\n";
	else cout << "Элемент находится по индексу [" << A << ";" << B << "]\n";
	res = TDArrayBarrierSearch(arr, v, n, m, A, B);
	if (res == -1) cout << "Такого элемента не найдено\n";
	else cout << "Элемент находится по индексу [" << A << ";" << B << "]\n";


	for (int i = 0; i < n; i++) {
		delete[] arr[i];
	}
	delete[] arr;
}

void task3()
{
	int n, m, k(1), v, A, B, res; 
	string file = "input.txt";
	cout << "Введите элемент который будем искать ";
	cin >> v;
	system("cls");
	int** arr = new int*;
	arr = FileRead(file, n, m);

	int up(0), down(n - 1), right(m - 1), left(0);
	res = TDArrayBinarySearch(arr, v, n, m, A, B, 0, n-1, m-1, 0);
	if (res == -1) cout << "Такого элемента не найдено\n";
	else cout << "Элемент находится по индексу [" << A << ";" << B << "]\n";
	for (int i = 0; i < n; i++) {
		delete[] arr[i];
	}
	delete[] arr;
}

//ЛАБА 2
void task4() {
	string filename = "input_search.txt";
	int n, m, ind1, ind2, ind3, ind4, count1, count2, count3, count4, hash;
	string** str = new string*;
	str = FileReader2(filename, n, m);

	ofstream file;
	file.open("STR_SEARCH_DATA.txt");

	file << "#\tПримеры\t\t\t\t\t\tАлгоритмы поиска подстроки в строке, количество сравнений символов\tКомментарии\n";
	file << " \t\t\t\t\t\t\t\tЛинейный\tБойлера-Мура\tКнута–Морриса–Пратта\tКарпа–Рабина\t" << "\n";

	for (int i = 0; i < 10; i++) {
		count1 = 0;
		count2 = 0;
		count3 = 0;
		count4 = 0;
		hash = 0;
		ind1 = LineSearchStr(str[i][0], str[i][1], count1);
		ind2 = boyerMoore(str[i][0], str[i][1], count2);
		ind3 = KnutMorrisPratt(str[i][0], str[i][1], count3);
		ind4 = karpRabin(str[i][0], str[i][1], count4, hash);
		file << i+1 << "\t" << str[i][0] << "\n";
		file << " \t" << str[i][1] << "\t" << "\n";
		file << "\t\t\t\t\t\t\t\t\t" << count1 << "\t\t" << count2 << "\t\t\t" << count3 << "\t\t\t\t" << count4+hash << "\t\t" << "\n";
	}

//	ind = KnutMorrisPratt(str[i][0], str[i][1], count);
//	ind = boyerMoore(str[i][0], str[i][1], count);
//	ind = LineSearchStr(str[i][0], str[i][1], count);
}

//ЛАБА 3
void task5() {

	vector<int> array; int k(0); int size(0); int m;

	string filename = "sort1.txt";

	ifstream fin;

	fin.open(filename);

	fin >> m;

	while (!(fin.eof())) {

		size++;

		array.push_back(0);

		fin >> array[k++];

	}

	array = simpleSort(array, size, m);

	cout << "Отсортированный массив: ";

	for (int i = 0; i < size; i++) {
		cout << array[i] << ' ';
	}

	cout << "\n\n";

	array.clear();

	fin.close();
}

void task6() {

	vector<int> array; int k(0); int size(0);

	string filename = "sort2.txt";

	ifstream fin;

	fin.open(filename);

	while (!(fin.eof())) {

		size++;

		array.push_back(0);

		fin >> array[k++];

	}

	array = sortingByParity(array, size);

	cout << "Отсортированный массив: ";

	for (int i = 0; i < size; i++) {
		cout << array[i] << ' ';
	}

	cout << "\n\n";

	array.clear();

	fin.close();

}

void task7() {
	ofstream file;

	cout << "Обработка файлов...\n\n";

	ifstream file1; file1.open("sortNONIncreasing.txt");
	ifstream file2; file2.open("sortNONDereasing.txt");
	ifstream file3; file3.open("sortRandom.txt");

	vector<int> Vfile1(100000, 0), Vfile2(100000, 0), Vfile3(100000, 0);

	for (int i = 0; i < 100000; i++) {

		file1 >> Vfile1[i];
		file2 >> Vfile2[i];
		file3 >> Vfile3[i];

	}

	int size = 100000;

	file1.close(); file2.close(); file3.close();



	{
		file.open("table.txt");

		unsigned long int n11(0), n12(0), n13(0), n21(0), n22(0), n23(0), n31(0), n32(0), n33(0); //перечисления

		file << "\t\t|\t\tИзначально по неубыванию\t\t\t|\t\tИзначально по невозрастанию\t\t\t|\t\tСлучайным образом\t\t\t\t\t|\n";

		file << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";

		file << "\t\t|Кол-во\t\t|Кол-во\t\t|Кол-во\t\t|Кол-во\t\t|Кол-во\t\t|Кол-во\t\t|Кол-во\t\t|Кол-во\t\t|Кол-во\t\t|\n";

		file << "\t\t|сравнений\t\t|сравнений не\t|перестановок\t|равнений\t\t|сравнений не\t|перестановок\t|сравнений\t\t|сравнений не\t|перестановок\t|\n";

		file << "\t\t|с элементом\t|с элементом\t|\t\t\t|с элементом\t|с элементом\t|\t\t\t|с элементом\t|с элементом\t|\t\t\t|\n";

		file << "\t\t|массива\t\t|массива\t\t|\t\t\t|массива\t\t|массива\t\t|\t\t\t|массива\t\t|массива\t\t|\t\t\t|\n";

		file << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";

		cout << "Алгоритм простого выбора(в работе 1/3):\n";
		simpleSelect(Vfile1, size, n11, n12, n13);
		cout << "Алгоритм простого выбора(в работе 2/3):\n";
		simpleSelect(Vfile2, size, n21, n22, n23);
		cout << "Алгоритм простого выбора(в работе 3/3):\n";
		simpleSelect(Vfile3, size, n31, n32, n33);
		cout << "Алгоритм простого выбора(готов):\n\n";

		file << "1\t\t|" << n11 << "\t\t|" << n12 << "\t\t|" << n13 << "\t\t|" << n21 << "\t\t|" << n22 << "\t\t|" << n23 << "\t\t|" << n31 << "\t\t|" << n32 << "\t\t|" << n33 << "\t\t|";

		file << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";

		n11 = 0; n12 = 0; n13 = 0; n21 = 0; n22 = 0; n23 = 0; n31 = 0; n32 = 0; n33 = 0;

		cout << "Алгоритм простого обмена(в работе 1/3):\n";
		simpleExchange(Vfile1, size, n11, n12, n13);
		cout << "Алгоритм простого обмена(в работе 2/3):\n";
		simpleExchange(Vfile2, size, n21, n22, n23);
		cout << "Алгоритм простого обмена(в работе 3/3):\n";
		simpleExchange(Vfile3, size, n31, n32, n33);
		cout << "Алгоритм простого обмена(готов):\n\n";

		file << "1\t\t|" << n11 << "\t\t|" << n12 << "\t\t|" << n13 << "\t\t|" << n21 << "\t\t|" << n22 << "\t\t|" << n23 << "\t\t|" << n31 << "\t\t|" << n32 << "\t\t|" << n33 << "\t\t|";

		file << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";

		n11 = 0; n12 = 0; n13 = 0; n21 = 0; n22 = 0; n23 = 0; n31 = 0; n32 = 0; n33 = 0;

		cout << "Улучшенный алгоритм простого обмена(в работе 1/3):\n";
		simpleExchangeUpgrade(Vfile1, size, n11, n12, n13);
		cout << "Улучшенный алгоритм простого обмена(в работе 2/3):\n";
		simpleExchangeUpgrade(Vfile2, size, n21, n22, n23);
		cout << "Улучшенный алгоритм простого обмена(в работе 3/3):\n";
		simpleExchangeUpgrade(Vfile3, size, n31, n32, n33);
		cout << "Улучшенный алгоритм простого обмена(готов):\n";

		file << "1\t\t|" << n11 << "\t\t|" << n12 << "\t\t|" << n13 << "\t\t|" << n21 << "\t\t|" << n22 << "\t\t|" << n23 << "\t\t|" << n31 << "\t\t|" << n32 << "\t\t|" << n33 << "\t\t|";

		file << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";

		n11 = 0; n12 = 0; n13 = 0; n21 = 0; n22 = 0; n23 = 0; n31 = 0; n32 = 0; n33 = 0;

		cout << "Улучшенный алгоритм простого обмена – шейкер-сортировка(в работе 1/3):\n";
		simpleExchangeShaker(Vfile1, size, n11, n12, n13);
		cout << "Улучшенный алгоритм простого обмена – шейкер-сортировка(в работе 2/3):\n";
		simpleExchangeShaker(Vfile2, size, n21, n22, n23);
		cout << "Улучшенный алгоритм простого обмена – шейкер-сортировка(в работе 3/3):\n";
		simpleExchangeShaker(Vfile3, size, n31, n32, n33);
		cout << "Улучшенный алгоритм простого обмена – шейкер-сортировка(готов):\n";

		file << "1\t\t|" << n11 << "\t\t|" << n12 << "\t\t|" << n13 << "\t\t|" << n21 << "\t\t|" << n22 << "\t\t|" << n23 << "\t\t|" << n31 << "\t\t|" << n32 << "\t\t|" << n33 << "\t\t|";

		file << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";

		n11 = 0; n12 = 0; n13 = 0; n21 = 0; n22 = 0; n23 = 0; n31 = 0; n32 = 0; n33 = 0;

		cout << "Алгоритм прямого включения(в работе 1/3):\n";
		insertionSort(Vfile1, size, n11, n12, n13);
		cout << "Алгоритм прямого включения(в работе 2/3):\n";
		insertionSort(Vfile2, size, n21, n22, n23);
		cout << "Алгоритм прямого включения(в работе 3/3):\n";
		insertionSort(Vfile3, size, n31, n32, n33);
		cout << "Алгоритм прямого включения(готов):\n";

		file << "1\t\t|" << n11 << "\t\t|" << n12 << "\t\t|" << n13 << "\t\t|" << n21 << "\t\t|" << n22 << "\t\t|" << n23 << "\t\t|" << n31 << "\t\t|" << n32 << "\t\t|" << n33 << "\t\t|";

		file << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";

		n11 = 0; n12 = 0; n13 = 0; n21 = 0; n22 = 0; n23 = 0; n31 = 0; n32 = 0; n33 = 0;

		cout << "Улучшенный алгоритм прямого включения(в работе 1/3):\n";
		insertionSortWithBarrier(Vfile1, size, n11, n12, n13);
		cout << "Улучшенный алгоритм прямого включения(в работе 2/3):\n";
		insertionSortWithBarrier(Vfile2, size, n21, n22, n23);
		cout << "Улучшенный алгоритм прямого включения(в работе 3/3):\n";
		insertionSortWithBarrier(Vfile3, size, n31, n32, n33);
		cout << "Улучшенный алгоритм прямого включения(готов):\n";

		file << "1\t\t|" << n11 << "\t\t|" << n12 << "\t\t|" << n13 << "\t\t|" << n21 << "\t\t|" << n22 << "\t\t|" << n23 << "\t\t|" << n31 << "\t\t|" << n32 << "\t\t|" << n33 << "\t\t|";

		file << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";

		n11 = 0; n12 = 0; n13 = 0; n21 = 0; n22 = 0; n23 = 0; n31 = 0; n32 = 0; n33 = 0;

		int count(0);
		cout << "Алгоритм сортировки слияниями(в работе 1/3):\n";
		mergeSort(Vfile1, size, count, n11, n12, n13);
		cout << "Алгоритм сортировки слияниями(в работе 2/3):\n";
		mergeSort(Vfile2, size, count, n21, n22, n23);
		cout << "Алгоритм сортировки слияниями(в работе 3/3):\n";
		mergeSort(Vfile3, size, count, n31, n32, n33);
		cout << "Алгоритм сортировки слияниями(готов):\n";

		file << "1\t\t|" << n11 << "\t\t|" << n12 << "\t\t|" << n13 << "\t\t|" << n21 << "\t\t|" << n22 << "\t\t|" << n23 << "\t\t|" << n31 << "\t\t|" << n32 << "\t\t|" << n33 << "\t\t|";

		file << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";

		n11 = 0; n12 = 0; n13 = 0; n21 = 0; n22 = 0; n23 = 0; n31 = 0; n32 = 0; n33 = 0; count = 0;

		cout << "Быстрая сортировка Хоара(в работе 1/3):\n";
		sortHoar(Vfile1, 0, Vfile1.size()-1, count, n11, n12, n13);
		cout << "Быстрая сортировка Хоара(в работе 2/3):\n";
		sortHoar(Vfile2, 0, Vfile2.size()-1, count, n21, n22, n23);
		cout << "Быстрая сортировка Хоара(в работе 3/3):\n";
		sortHoar(Vfile3, 0, Vfile3.size()-1, count, n31, n32, n33);
		cout << "Быстрая сортировка Хоара(готов):\n";

		file << "1\t\t|" << n11 << "\t\t|" << n12 << "\t\t|" << n13 << "\t\t|" << n21 << "\t\t|" << n22 << "\t\t|" << n23 << "\t\t|" << n31 << "\t\t|" << n32 << "\t\t|" << n33 << "\t\t|";

		file << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
	
		file.close();

		cout << "\n\n\n\t\t\t\tОБРАБОТКА ФАЙЛА ЗАВЕРШЕНА";

	}
	
}

//ЛАБА 4
void task8() {

	cout << "Введите размерность шахматной доски: ";

	int n;

	cin >> n;

	system("cls");

	ArrangementOfQueensMain(n);
}

void task9() {

	cout << "Введите размерность шахматной доски: "; int n; cin >> n;

	vector<int> MainField(n * n, 0);

	vector<int> queensField(n, -1);

	vector<int> result(n, -1);

	int fields = 0;

	system("cls");

	CompactArrangementOfQueens(MainField, queensField, n, fields, result);

	cout << fields << "\n";
	

	vector<int> printArray(n * n, 0);

	int k(0);

	for (int i = 0; i < n * n; i++) {

		if ((k < n) && (result[k] == i)) {

			printArray[i] = 1;

			k++;

		}

	}



	for (int i = 0; i < n; i++) {

		for (int j = 0; j < n; j++) {

			cout << printArray[j + (n * i)] << ' ';

		}

		cout << '\n';

	}
}

void task10() {

	cout << "Введите размерность шахматной доски: "; int n; cin >> n;

	vector<int> MainField(n * n, 0);

	vector<int> queensIndexes;

	vector<int> result(2*n, 0);

	int minMoves(2 * n);

	int countMoves(0);

	int fields = 0;

	system("cls");

	SmallestNumberOfMoves(minMoves, countMoves, MainField, queensIndexes, result, n);

	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}

	cout << "\nМинимум " << result.size() - 1 << " ходов\n";

}

void task11() {

	int n, p, queensCount(0), thisStep(0), size, count(1);

	cout << "Введите размерность шахматной доски: ";

	cin >> n;

	size = n * n;

	cout << "Введите количество нападений ферзей: ";

	cin >> p;

	system("cls");

	vector<int> MainField(size, 0), queensField(size, 0), result(size, 0);

	time_t timeTask12Start = clock();

	AttackOfQueens(p, n, MainField, queensField, result, queensCount, thisStep, size, count);

	time_t timeTask12End = clock();

	int countVector(0);

	bool ifFinal(false);

	cout << "\n\n";

	for (int i = 0; i < size; i++) {

		if (result[i] != 0) ifFinal = true;

	}

	if (ifFinal == true) {

		for (int i = 0; i < n; i++) {

			for (int j = 0; j < n; j++) {

				cout << result[countVector++] << ' ';

			}

			cout << '\n';

		}

	}

	else cout << "Такого случая нет";

	cout << "\nВ общем случае потрачено " << ((double)(timeTask12End - timeTask12Start)/CLOCKS_PER_SEC) << "с\n";

}

void task12() {

	cout << "Выберите подзадачу: \n1) Найти один способ обхода конем доски N×M. Конь должен побывать на каждой клетке доски только один раз. Начальная позиция коня определяется случайным образом. Использовать правило Варнсдорфа. \n2) Для каждого начального расположения коня найти количество способов обхода доски.\n";

	int taskNum; cin >> taskNum;

	system("cls");

	cout << "Введите размерность шахматного поля N x M: \n";

	int N, M; cin >> N >> M;

	system("cls");

	int** field = new int*[N + 4];

	for (int i = 0; i < N + 4; i++) {

		field[i] = new int[M + 4];
		
		for (int j = 0; j < M + 4; j++) {

			if ((i < 2) || (i >= N + 2)) {

				field[i][j] = -1;

			}
			else {

				if (j < 2 || (j >= M + 2)) {

					field[i][j] = -1;

				}
				else {
				
					field[i][j] = 0;
				
				}
			}
		}

	}


	if (taskNum == 1) {

		srand((unsigned int)time(NULL));

		int ri = rand() % N + 2;
		
		int rj = rand() % M + 2;

		vector<int> position = {ri, rj};

		cout << "Индекс коня: " << ri-2 << " " << rj-2 << "\n\n";

		vector<int> result;

		result.push_back(position[0]);
		result.push_back(position[1]);

		field[ri][rj] = 1;

		KnightTraversingTheChessboard(field, N, M, position, result);

		for (int i = 2; i < N + 2; i++) {

			for (int j = 2; j < M + 2; j++) {

				cout << field[i][j] << " ";

			}

			cout << "\n";

		}

	}
	else {

		vector<int> tempResult;

		vector<vector<int>> tempResult2;

		for (int i = 2; i <= ((N + 2)+1)/2; i++) {

			for (int j = 2; j <= ((M + 2)+1)/2; j++) {

				int result(0);

				vector<int> position = { i, j };

				field[i][j] = 1;

				KnightTraversingTheChessboard(field, N, M, position, result);

				field[i][j] = 0;

				tempResult.push_back(result);

				cout << result << " ";

			}

			for (int i = M / 2 - 1; i >= 0; i--) {

				tempResult.push_back(tempResult[i]); 

				cout << tempResult[i] << " ";

			}

			tempResult2.push_back(tempResult);

			tempResult.clear();

			cout << "\n";

		}


		for (int i = N / 2 - 1; i >= 0; i--) {
				
			tempResult = tempResult2[i];

			for (int j = 0; j < M; j++) {

				cout << tempResult[j] << " ";

			}

			cout << "\n";

		}

	}

}

void task13() {


	int N = 10;



	int count(0);

	vector<int> field(N * N, 0);

	vector<int> vertical(N * N, 0);

	vector<int> diagonalUp(N * N, 0);

	vector<int> diagonalDown(N * N, 0);

	vector<int> knight(N * N, 0);



	ArrangementOfMagaraja(field, vertical, diagonalUp, diagonalDown, knight, count, N);

}

void task14() {

}



//ЛАБА 5

void task15() {

	//vector<vector<int>> maze = read_maze();

	//bool flag = false;

	//int turn = 1;

	//vector<vector<int>> result = maze;

	//int startx, starty, endx, endy;

	//set_points(maze, startx, starty, endx, endy);

	//maze[startx][starty] = 0;
	//maze[endx][endy] = 0;
	//result[endx][endy] = 0;

	//find_way(maze, startx, starty, endx, endy, result, flag, turn);

	//for (int i = 0; i < result.size(); ++i) {

	//	for (int j = 0; j < result[0].size(); ++j) {

	//		cout << result[i][j] << ' ';

	//	}

	//	cout << endl;

	//}

}

void task16() {

	/*int types;
	vector<int> price;
	vector<int> weight;
	int MAXWEIGHT;

	set(types, price, weight, MAXWEIGHT);

	vector<int> backpack(types, 0);
	vector<int> backpack_result(types, 0);

	find_max_cost(types, 0, 0, weight, price, MAXWEIGHT, backpack, backpack_result);

	cout << backpack_cost(backpack_result, price);*/

}

void task17() {

	/*set_table();

	vector<int> way;

	way.push_back(START);

	vector<bool> destination(N - 1, true);

	find_way(START, destination);*/

}

void task18() {

}



//ЛАБА 6
void task19() {

}

void task20() {

}

void task21() {

}

void task22() {

}

void task23() {

}

void task24() {

}

//ЛАБА 7
void task25() {

}

void task26() {

}

void task27() {

}

void task28() {

}

void task29() {

}

void task30() {

}

void task31() {

}

//ТЕСТЫ
void task32() {

	task366();

}

#pragma endregion







#pragma region lab1

int LineSearch(int* a, int v, size_t size, long long &countAll, long long &countWithEl) {
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
	int* newArr = new int[size+1];
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

int RecurseSearch(int* a, int v, size_t size, long long first, long long end) {
	if (first > end) {		//end>=first
		return -1;
	}
	long long center = (first + end) / 2;
	if (a[center] == v) {
		return center;
	}
	else if (a[center] > v) {
		return RecurseSearch(a, v, size, first, center - 1);
	}
	else {
		return RecurseSearch(a, v, size, center + 1, end);
	}
}

int TDArrayLineSearch(int** a, int v, size_t sizeA, size_t sizeB, int& A, int& B)
{
	A = 0;
	unsigned int i = 0;
	B = 0;
 	while ((i < sizeA*sizeB) && (a[A][B++] != v)) {
		i++;
		if (B == sizeB) {
			B = 0;
			A++;
		}
	}
	if (i != sizeA*sizeB) {
		B--;
		return 1;
	}
	return -1;
}

int TDArrayBarrierSearch(int** a, int v, size_t sizeA, size_t sizeB, int& A, int& B)
{
	int** newArr = new int*[sizeA + 1];
	for (int i = 0; i < sizeA; i++) {
		newArr[i] = new int[sizeB];
		for (int j = 0; j < sizeB; j++) {
			newArr[i][j] = a[i][j];
		}
	}
	newArr[sizeA] = new int[1];
	newArr[sizeA][0] = v;
	A = 0;
	unsigned int i = 0;
	B = 0;
	while (newArr[A][B] != v) {
		i++;
		B++;
		if (B == sizeB) {
			B = 0;
			A++;
		}

	}

	delete[] newArr[sizeA];
	for (int i = 0; i < sizeA; i++) {
		delete[] newArr[i];
	}
	delete[] newArr;

	if (i != sizeA * sizeB) {
		return 1;
	}
	return -1;
}

int TDArrayBinarySearch(int** a, int v, size_t sizeA, size_t sizeB, int& A, int& B, int up, int down, int right, int left)
{
	int height, width;
	bool isEnd = false;
	if ((up >= down) && (right <= left))
		return -1;
	height = (up + down) / 2;
	width = (right + left) / 2;
	if (right == left) {		//если остаётся одна полоска
		int size = down - up + 1;
		int t(0);
		int* arr = new int[size];
		for (int i = up; i <= down; i++) {
			arr[t++] = a[i][right];
		}
		int center = RecurseSearch(arr, v, size, 0, size - 1); //находим элемент
		if (center == -1) {
			delete[] arr;
			return -1;
		}
		else {
			A = up+center;
			B = width;
			delete[] arr;
			return a[up+center][width];
		}
	}
	else if (up == down) {
		int size = right - left + 1;
		int t(0);
		int* arr = new int[size];
		for (int i = left; i <= right; i++) {
			arr[t++] = a[up][i];
		}
		int center = RecurseSearch(arr, v, size, 0, size - 1); //находим элемент
		if (center == -1) {
			delete[] arr;
			return -1;
		}
		else {
			A = height;
			B = left+center;
			delete[] arr;
			return a[height][left+center];
		}
	}
	if (a[height][width] == v) {
		A = height;
		B = width;
		return a[height][width];
	}
	else if (v < a[height][width]) {
		int k;	//для проверки
		k = TDArrayBinarySearch(a, v, sizeA, sizeB, A, B, up, height-1, right, width);
		if (k == v) {
			return a[A][B];
		}
		else {
			if (width - 1 < left) return -1;
			return TDArrayBinarySearch(a, v, sizeA, sizeB, A, B, up, down, width-1, left);
		}
	}
	else {
		int k;	//для проверки
		k = TDArrayBinarySearch(a, v, sizeA, sizeB, A, B, height+1, down, width, left);
		if (k == v) {
			return a[A][B];
		}
		else {
			if (width - 1 < left) return -1;
			return TDArrayBinarySearch(a, v, sizeA, sizeB, A, B, up, down, right, width+1);
		}
	}
}

int** FileRead(string filename, int& n, int& m)
{
	ifstream file;
	file.open(filename);
	file >> n;
	file >> m;
	int** a = new int*[n];
	for (int i = 0; i < n; i++) {
		a[i] = new int[m];
		for (int j = 0; j < m; j++) {
			file >> a[i][j];
		}
	}
	return a;
}


#pragma endregion







#pragma region lab2

string** FileReader2(string filename, int& n, int& m)
{
	ifstream file;
	string line;
	file.open(filename);
	file >> n;
	file >> m;
	getline(file, line);
	string** a = new string * [n];
	for (int i = 0; i < n; i++) {
		a[i] = new string[m];
		for (int j = 0; j < m; j++) {
			getline(file, line);
			a[i][j] = line;
		}
		getline(file, line);
	}
	return a;
}

int LineSearchStr(string str, string substr, int& count) {
	int tmp(0), tmpI(0);
	for (int i = 0; i < str.length() - substr.length() + 1; i++) {
		tmpI = i;
		for (int j = 0; j < substr.length(); j++) {
			if (str[tmpI++] != substr[j]) {
				count++;
				break;
			}
			tmp = j + 1;
			count++;
		}
		if (tmp == (substr.length())) return i;
	}
	return -1;
}

int boyerMoore(string& s, string& x, int& count) {
	int index = -1;
	count = 0;
	int* ind = createArr(x);
	int i(x.size() - 1), j(x.size() - 1);
	int sum = 0;
	while (i < s.size()) {
		while (j != -1 && ++count && s[i] == x[j]) {
			j--;
			i--;
			sum++;
		}
		if (j == -1) {
			index = i + 1;
			break;
		}
		j = x.size() - 1;
		i += ind[s[i]] + sum;
		sum = 0;
	}
	return index;
}

int* createArr(string& s) {
	int tmp[500];
	int k = 1;
	for (int i = 0; i < 500; ++i) {
		tmp[i] = s.size();
	}
	for (int i = s.size() - 2; i >= 0; --i) {
		if (tmp[s[i]] == s.size()) {

			tmp[s[i]] = k;

		}
		k++;
	}
	return tmp;
}

int KnutMorrisPratt(string& s, string& x, int& c)
{
	c = 0;
	int m = s.size();
	int n = x.size();
	vector<int> next(n + 1, 0);
	for (int i = 1; i < n; ++i)
	{
		int j = next[i + 1];
		while (j > 0 && x[j] != x[i]) {
			j = next[j];
		}
		if (j > 0 || x[j] == x[i]) {
			next[i + 1] = j + 1;
		}
	}
	for (int i = 0, j = 0; i < m; ++i) {
		if (++c && s[i] == x[j]) {
			if (++j == n) {
				return i - j + 1;
			}
		}
		else if (j > 0) {
			j = next[j];
			i--;
		}
	}
	return -1;
}

int karpRabin(string& s, string& x, int& c, int& hashs) {
	c = 0;
	hashs = 0;
	int patHash = SymbolHash(x);
	int n = s.size();
	int m = x.size();
	int i = m - 1;
	while (i < n) {
		string temp = s.substr(i, m);
		if (++hashs && SymbolHash(temp) == patHash) {
			int j = 0;
			while (j < m && ++c && x[j] == s[i + j]) {
				j++;
			}
			if (j == m) {
				return i;
			}
		}
		i++;
	}
	return -1;
}

int SymbolHash(string& s) {
	int hash = 0;
	for (int i = 0; i != s.size(); ++i) {
		hash += s[i];
	}
	return hash;
}

#pragma endregion








#pragma region lab3

void createFilesForSort()
{
	ofstream file; //создание рандомного массива

	file.open("sortRandom.txt");

	for (int i = 1; i <= 100000; i++) {

		file << rand() << " ";

	}

	file.close();

	ifstream file2;

	vector<int> arrayTEST(100000, 0);

	file2.open("sortRandom.txt");

	for (int i = 0; i < 100000; i++) {

		file2 >> arrayTEST[i];

	}

	cout << "Сортировка началась\n\nГотовность:\n";

	unsigned long int a, b, c;

	arrayTEST = simpleSelect(arrayTEST, 100000, a, b, c);



	ofstream fileNONInc;
	ofstream fileNONDer;

	fileNONInc.open("sortNONIncreasing.txt");
	fileNONDer.open("sortNONDereasing.txt");

	for (int i = 0; i < 100000; i++) {

		fileNONInc << arrayTEST[i] << " ";

		fileNONDer << arrayTEST[100000 - 1 - i] << " ";

	}

	fileNONInc.close();
	fileNONDer.close();


	file2.close();
}

vector<int> simpleSort(vector<int> array, int size, int m) {

	vector<int> sortoff(m, 0); int j(0);

	for (int i = 0; i < size; i++) { //заполняем массив кол-вом вхождений

		sortoff[array[i]]++;

	}

	array.clear();

	for (int i = 0; i < size; i++) {

		array.push_back(0);

	}

	for (int i = 0; i < size; i++) {

		while (sortoff[j++] == 0); //двигаемся до ближайшего непустого элемента

		j--;

		array[i] = j; //присваиваем 

		sortoff[j]--;//вычитаем элемент

	}

	sortoff.clear();

	return array;

}

vector<int> sortingByParity(vector<int> array, int size) {

	vector<int> even;

	vector<int> odd;

	for (int i = 0; i < size; i++) {

		if (array[i] % 2 == 0) even.push_back(array[i]);

		else odd.push_back(array[i]);

	}

	int j(0);

	for (int i = 0; i < even.size(); i++) {

		array[j++] = even[i];

	}

	for (int i = 0; i < odd.size(); i++) {

		array[j++] = odd[i];

	}
	return array;
}

vector<int> simpleSelect(vector<int> array, int size, unsigned long int& comparisonWithElement, unsigned long int& comparisionWithNotElement, unsigned long int& countReplace)
{
	int maxEl;

	int counter(1);


	for (int i = size - 1; i > 0; i--) {
		comparisionWithNotElement++;

		maxEl = i;

		for (int j = 0; j < i; j++) {  //ищем наибольший элемент
			comparisionWithNotElement++;

			comparisonWithElement++;
			if (array[maxEl] < array[j]) maxEl = j;

		}
		comparisionWithNotElement++;


		if (array[maxEl] > array[i]) { //перестановка
			comparisonWithElement++;

			int TEMP = array[i];

			array[i] = array[maxEl];

			array[maxEl] = TEMP;
			countReplace++;

		}

		if (i % 1000 == 0) { //просто счётчик :)

			cout << counter++ << "%\n";

		}

	}
	comparisionWithNotElement++;

	return array;

}

vector<int> simpleExchange(vector<int> array, int size, unsigned long int& comparisonWithElement, unsigned long int& comparisionWithNotElement, unsigned long int& countReplace)
{
	int counter(1);

	for (int l = 1; l < size - 1; l++) {
		comparisionWithNotElement++;

		for (int i = 0; i < size - l; i++) {
			comparisionWithNotElement++;

			comparisonWithElement++;
			if (array[i] > array[i + 1]) {
				countReplace++;

				int TEMP = array[i];

				array[i] = array[i + 1];

				array[i + 1] = TEMP;
			}

		}
		comparisionWithNotElement++;

	}
	comparisionWithNotElement++;

	return array;
}

vector<int> simpleExchangeUpgrade(vector<int> array, int size, unsigned long int& comparisonWithElement, unsigned long int& comparisionWithNotElement, unsigned long int& countReplace)
{

	int counter(1);
	int count(1);

	bool isEnd(false);

	int indexReplace = size - 1; //последняя замена
	int lastReplace = size - 1; //последняя замена для сравнения с преыдущим занчением

	while(isEnd == false) {
		comparisionWithNotElement++;

		count++;


		for (int i = 0; i < indexReplace; i++) {
			comparisionWithNotElement++;

			comparisonWithElement++;
			if (array[i] > array[i + 1]) {
				countReplace++;

				int TEMP = array[i];

				array[i] = array[i + 1];

				array[i + 1] = TEMP;

				lastReplace = i;

			}

		}
		comparisionWithNotElement++;

		if (lastReplace == indexReplace) isEnd = true; 
		comparisionWithNotElement++;

		indexReplace = lastReplace;


	}
	comparisionWithNotElement++;

	return array;
}

vector<int> simpleExchangeShaker(vector<int> array, int size, unsigned long int& comparisonWithElement, unsigned long int& comparisionWithNotElement, unsigned long int& countReplace)
{

	int counter(1);
	int count(1);

	bool isEnd(false), shake(true);

	int indexReplace = size - 1; //последняя замена с конца для сравнения с преыдущим занчением
	int lastReplace = size - 1; //последняя замена 
	int firstReplace = 0; //последняя замена с начала

	while (isEnd == false) {
		comparisionWithNotElement++;

		count++;

		if (shake == true) {
			comparisionWithNotElement++;

			indexReplace = lastReplace;

			for (int i = firstReplace; i < lastReplace; i++) {
				comparisionWithNotElement++;

				comparisonWithElement++;
				if (array[i] > array[i + 1]) { //перестановка
					countReplace++;

					int TEMP = array[i];

					array[i] = array[i + 1];

					array[i + 1] = TEMP;

					indexReplace = i;

				}

			}
			comparisionWithNotElement++;

			if (lastReplace == indexReplace) isEnd = true;
			comparisionWithNotElement++;

			lastReplace = indexReplace;

			shake = false;

		}
		else {
			comparisionWithNotElement++;

			indexReplace = firstReplace;

			for (int i = lastReplace; i > firstReplace; i--) {
				comparisionWithNotElement++;

				comparisonWithElement++;
				if (array[i] < array[i - 1]) {
					countReplace++;

					int TEMP = array[i];

					array[i] = array[i - 1];

					array[i - 1] = TEMP;

					indexReplace = i;

				}

			}
			comparisionWithNotElement++;

			if (firstReplace == indexReplace) isEnd = true;
			comparisionWithNotElement++;

			firstReplace = indexReplace;

			shake = true;

		}



	}

	return array;
}

vector<int> insertionSort(vector<int> array, int size, unsigned long int& comparisonWithElement, unsigned long int& comparisionWithNotElement, unsigned long int& countReplace)
{
	int counter(1);
	int count(1);

	int x, index;
	
	for (int i = 1; i < size; i++) {
		comparisionWithNotElement++;

		count++;

		x = array[i];
		index = i - 1;

		while ((index >= 0) && (array[index] > x)) {
			comparisionWithNotElement++;
			comparisonWithElement++;

			countReplace++;
			array[index + 1] = array[index];

			index--;

		}
		if (index >= 0) {
			comparisonWithElement++;
			comparisionWithNotElement++;
		}
		else comparisionWithNotElement++;

		array[index + 1] = x;



		if (count % 1000 == 0) {

			cout << counter++ << "%\n";

		}

	}
	comparisionWithNotElement++;

	return array;

}

vector<int> insertionSortWithBarrier(vector<int> arrayA, int size, unsigned long int& comparisonWithElement, unsigned long int& comparisionWithNotElement, unsigned long int& countReplace)
{
	int counter(1);
	int count(1);

	int x, index;

	vector<int> array(size + 1, 0);

	for (int i = 1; i <= size; i++) { //заполнение массива с местом под баррьерный элемент
		comparisionWithNotElement++;

		array[i] = arrayA[i-1];

	}
	comparisionWithNotElement++;

	for (int i = 2; i <= size; i++) {
		comparisionWithNotElement++;

		count++;

		x = array[i];

		array[0] = x;
		
		index = i - 1;

		while (array[index] > x) {
			comparisonWithElement++;

			countReplace++;
			array[index + 1] = array[index];

			index--;

		}
		comparisonWithElement++;

		array[index + 1] = x;


		if (count % 1000 == 0) {

			cout << counter++ << "%\n";

		}

	}
	comparisionWithNotElement++;


	for (int i = 0; i < size; i++) {
		comparisionWithNotElement++;

		arrayA[i] = array[i + 1];

	}
	comparisionWithNotElement++;

	return arrayA;

}

vector<int> mergeSort(vector<int> array, int size, int& count, unsigned long int& comparisonWithElement, unsigned long int& comparisionWithNotElement, unsigned long int& countReplace)
{

	int counter(0);

	comparisionWithNotElement++;
	if (array.size() == 1) {
		
		return array;

	}
	else {

		int center = array.size() / 2;

		vector<int> part1, part2;

		for (int i = 0; i < center; i++) {	//разделение
			comparisionWithNotElement++;

			part1.push_back(array[i]);

		}
		comparisionWithNotElement++;

		for (int i = center; i < array.size(); i++) {	//разделение
			comparisionWithNotElement++;

			part2.push_back(array[i]);

		}
		comparisionWithNotElement++;

		part1 = mergeSort(part1, part1.size(), count, comparisonWithElement, comparisionWithNotElement, countReplace);	//сортировка первой части

		part2 = mergeSort(part2, part1.size(), count, comparisonWithElement, comparisionWithNotElement, countReplace);	//сортировка второй части

		array.clear();

		int ind1(0), ind2(0);

		while ((ind1 != part1.size()) && (ind2 != part2.size()) && (array.size() != part1.size() + part2.size())) {	//слияние в один массив
			comparisionWithNotElement += 3;

			comparisonWithElement++;
			if (part1[ind1] < part2[ind2]) {

				array.push_back(part1[ind1++]);
				countReplace++;

			}
			else {

				array.push_back(part2[ind2++]);
				countReplace++;

			}

		}
		if (ind1 != part1.size()) {
			comparisionWithNotElement += 2;
			if (ind2 != part2.size()) comparisionWithNotElement++;
		}
		else comparisionWithNotElement++;

		comparisionWithNotElement++;
		if (ind1 == part1.size()) {	//запись оставшихся элементов

			for (int i = ind2; i < part2.size(); i++) {
				comparisionWithNotElement++;

				array.push_back(part2[i]);
				countReplace++;

			}
			comparisionWithNotElement++;

		}
		else {

			for (int i = ind1; i < part1.size(); i++) {
				comparisionWithNotElement++;

				array.push_back(part1[i]);
				countReplace++;

			}
			comparisionWithNotElement++;

		}

		if (array.size() % 1000 == 0) {

			cout << counter++ << "%\n";

		}

		return array;

	}
}

void sortHoar(vector<int>& array, int first, int last, int& count, unsigned long int& comparisonWithElement, unsigned long int& comparisionWithNotElement, unsigned long int& countReplace)
{

	int el = array[(first + last) / 2];

	int i(first), j(last); 

	do
	{

		comparisonWithElement++; //отсекаем края, которые соответсвуют своим сторонам
		while (array[i] < el) 
		{

			comparisonWithElement++;

			i++; 

		}

		comparisonWithElement++;

		while (array[j] > el) 
		{

			comparisonWithElement++;

			j--;

		}

		comparisionWithNotElement++;

		if (i <= j) //меняем местами элементы, несоответствующие сторонам
		{

			countReplace++;
			comparisonWithElement++;

			int tmp = array[i];

			array[i] = array[j];

			array[j] = tmp;

			i++;

			j--;

		}

		comparisionWithNotElement++;

	} while (i <= j);//пока левая граница не пересечет правую



	comparisionWithNotElement++;
	if (first < j) sortHoar(array, first, j, count, comparisonWithElement, comparisionWithNotElement, countReplace); 

	comparisionWithNotElement++;
	if (i < last) sortHoar(array, i, last, count, comparisonWithElement, comparisionWithNotElement, countReplace);

	if (array.size() % 1000 == 0) {

		cout << count++ << "%\n";

	}

}

#pragma endregion








#pragma region lab4

//Задача №1

void ArrangementOfQueensMain(int N) {
	int count(0);
	vector<int> field(N * N, 0);
	vector<int> vertical(N * N, 0);
	vector<int> diagonalUp(N * N, 0);
	vector<int> diagonalDown(N * N, 0);

	bool ifFound;
	ifFound = ArrangementOfQueensRecurs(field, vertical, diagonalUp, diagonalDown, count, N);
	int k(0);
	if (ifFound == true) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cout << field[k++] << ' ';
			}
			cout << endl;
		}
		ifFound = true;
		cout << "\nБыл показан один вариант. Желаете увидеть остальные?\n1)Да\n2)Выход\n";
		field.~vector(); vertical.~vector(); diagonalUp.~vector(); diagonalDown.~vector();
		vector<int> field(N * N, 0);
		vector<int> vertical(N * N, 0);
		vector<int> diagonalUp(N * N, 0);
		vector<int> diagonalDown(N * N, 0);
		int q; cin >> q; cout << "\n"; count = 0;
		if (q == 1) AllCombinationsArrangementOfQueensRecurs(field, vertical, diagonalUp, diagonalDown, count, N, ifFound);
		else system("cls");
		field.~vector(); vertical.~vector(); diagonalUp.~vector(); diagonalDown.~vector();
	}
	else cout << "Решений нет\n";
}

bool ArrangementOfQueensRecurs(vector<int> &field, vector<int> &vertical, vector<int> &diagonalUp, vector<int> &diagonalDown, int &count, int size) {
	if(count == size) { //если количество собранных строк равно размерности
		return true;
	}

	vector<int> step(size, 0); //текущий ряд
	for (int i = 0; i < size; i++) {
		if (vertical[count * size + i] >= 1 || diagonalDown[count * size + i] >= 1 || diagonalUp[count * size + i] >= 1) step[i] = 1;
	}
	
	bool end;
	int j(0);

	for (int i = count * size; i < (count + 1) * size; i++) {
		if (step[j++] == 0) {
			NextStep(field, vertical, diagonalUp, diagonalDown, count, size, i);
			end = ArrangementOfQueensRecurs(field, vertical, diagonalUp, diagonalDown, count, size);
			if (end == false) {
				PreviewStep(field, vertical, diagonalUp, diagonalDown, count, size, i);
			}
			else {
				return true;
			}
		}
	}

	return false;
}

void NextStep(vector<int>& field, vector<int>& vertical, vector<int>& diagonalUp, vector<int>& diagonalDown, int& count, int size, int index)
{
	field[index] = -1;
	for (int i = index; i < size * size; i += size) {
		vertical[i] += 1;
	}
	bool ifBarrier(false);
	if ((index % size) != 0) { //проверка на нахождение у стенки слева
		for (int i = index; i < size * size; i += (size - 1)) {
			if (ifBarrier == false) diagonalUp[i] += 1;
			if ((i != index) && ((i % size) == 0)) ifBarrier = true; //проверка, не уткнулась ли диагональ в стенку
		}
	}
	ifBarrier = false;
	if ((index + 1) % size != 0) {//проверка на нахождение у стенки справа
		for (int i = index; i < size * size; i += (size + 1)) {
			if (ifBarrier == false) diagonalDown[i] += 1;
			if ((i != index) && ((i + 1) % size == 0)) ifBarrier = true;
		}
	}
	count++;
}

void PreviewStep(vector<int>& field, vector<int>& vertical, vector<int>& diagonalUp, vector<int>& diagonalDown, int& count, int size, int index)
{
	field[index] = 0;
	for (int i = index; i < size * size; i += size) {
		vertical[i] -= 1;
	}
	bool ifBarrier(false);
	if ((index % size) != 0) { //проверка на нахождение у стенки слева
		for (int i = index; i < size * size; i += (size - 1)) {
			if (ifBarrier == false) diagonalUp[i] -= 1;
			if ((i != index) && ((i % size) == 0)) ifBarrier = true; //проверка, не уткнулась ли диагональ в стенку
		}
	}
	ifBarrier = false;
	if ((index + 1) % size != 0) {//проверка на нахождение у стенки справа
		for (int i = index; i < size * size; i += (size + 1)) {
			if (ifBarrier == false) diagonalDown[i] -= 1;
			if ((i != index) && ((i + 1) % size == 0)) ifBarrier = true;
		}
	}
	count--;
}

bool AllCombinationsArrangementOfQueensRecurs(vector<int>& field, vector<int>& vertical, vector<int>& diagonalUp, vector<int>& diagonalDown, int& count, int size, bool& ifFound) {
	if (count == size) { //если количество собранных строк равно размерности
		if (ifFound == false) {
			int k(0);
			for (int i = 0; i < size; i++) {
				for (int j = 0; j < size; j++) {
					cout << field[k++] << ' ';
				}
				cout << endl;
			}
			cout << endl;
			return false;
		}
		ifFound = false;
		return false;
	}

	vector<int> step(size, 0); //текущий ряд
	for (int i = 0; i < size; i++) {
		if (vertical[count * size + i] >= 1 || diagonalDown[count * size + i] >= 1 || diagonalUp[count * size + i] >= 1) step[i] = 1;
	}

	bool end;
	int j(0);

	for (int i = count * size; i < (count + 1) * size; i++) {
		if (step[j++] == 0) {
			NextStep(field, vertical, diagonalUp, diagonalDown, count, size, i);
			end = AllCombinationsArrangementOfQueensRecurs(field, vertical, diagonalUp, diagonalDown, count, size, ifFound);
			if (end == false) {
				PreviewStep(field, vertical, diagonalUp, diagonalDown, count, size, i);
			}
			else {
				return true;
			}
		}
	}

	return false;
}




//Задача №2

void CompactArrangementOfQueens(vector<int>& mainField, vector<int>& queensField, int n, int& fields, vector<int>& result) {
	if (n == 0) {
		fields = GetEmpty(mainField);
		result = queensField;
	}
	else {
		int index = 0;
		for (int i = 0; i < queensField.size(); ++i) {
			if (queensField[i] != -1) {
				index = queensField[i] + 1;
			}
		}
		for (int i = index; i < mainField.size(); ++i) {
			NextStep(mainField, queensField, i);
			if (GetEmpty(mainField) <= fields) {
				PreviewStep(mainField, queensField, i);
				continue;
			}
			CompactArrangementOfQueens(mainField, queensField, n - 1, fields, result);
			PreviewStep(mainField, queensField, i);
		}

	}
}

void NextStep(vector<int>& MainField, vector<int>& queensField, int pos) {
	int size = queensField.size();
	int h = pos / queensField.size();
	int v = pos % queensField.size();
	int index;
	for (int i = 0; i < queensField.size(); ++i) {
		index = i + h * size;
		MainField[index]++;
		index = v + i * size;
		MainField[index]++;
	}

	for (int dh = h - 1, dv = v - 1; dh >= 0 && dv >= 0; --dv, --dh) {
		index = dh * size + dv;
		MainField[index]++;
	}

	for (int dh = h - 1, dv = v + 1; dh >= 0 && dv < size; --dh, ++dv) {
		index = dh * size + dv;
		MainField[index]++;
	}


	for (int dh = h + 1, dv = v - 1; dh < size && dv >= 0; ++dh, --dv) {
		index = dh * size + dv;
		MainField[index]++;
	}

	// DOWN RIGHT
	for (int dh = h + 1, dv = v + 1; dh < size && dv < size; ++dh, ++dv) {
		index = dh * size + dv;
		MainField[index]++;
	}

	for (int i = 0; i < queensField.size(); ++i) {
		if (queensField[i] == -1) {
			queensField[i] = pos;
			break;
		}
	}

	MainField[pos] -= 1;
}

void PreviewStep(vector<int>& MainField, vector<int>& queensField, int pos) {
	int size = queensField.size();
	int h = pos / queensField.size();
	int v = pos % queensField.size();
	int index;
	for (int i = 0; i < queensField.size(); ++i) {
		index = i + h * size;
		MainField[index]--;
		index = v + i * size;
		MainField[index]--;
	}

	// UP LEFT
	for (int dh = h - 1, dv = v - 1; dh >= 0 && dv >= 0; --dv, --dh) {
		index = dh * size + dv;
		MainField[index]--;
	}

	// UP RIGHT
	for (int dh = h - 1, dv = v + 1; dh >= 0 && dv < size; --dh, ++dv) {
		index = dh * size + dv;
		MainField[index]--;
	}

	// DOWN LEFT
	for (int dh = h + 1, dv = v - 1; dh < size && dv >= 0; ++dh, --dv) {
		index = dh * size + dv;
		MainField[index]--;
	}

	// DOWN RIGHT
	for (int dh = h + 1, dv = v + 1; dh < size && dv < size; ++dh, ++dv) {
		index = dh * size + dv;
		MainField[index]--;
	}

	for (int i = 0; i < queensField.size(); ++i) {
		if (queensField[i] == pos) {
			queensField[i] = -1;
			break;
		}
	}

	MainField[pos] += 1;

}

int GetEmpty(vector<int> mainField) {

	int count = 0;
	for (int i = 0; i < mainField.size(); ++i) {
		if (!mainField[i]) {
			count++;
		}
	}
	return count;
}




//Задача №3

void SmallestNumberOfMoves(int& minMoves, int& countMoves, vector<int>& MainField, vector<int>& queensIndexes, vector<int>& result, int size, int currentDirection, int pos, int n) {

	if (!GetEmpty(MainField)) { //если прошли всё поле (нет пустых клеток)

		//запоминаем результат
		result = queensIndexes;
		minMoves = countMoves;

	}

	else {

		if (n == 0) {
			//рекурсия

			vector<int> mainCells(MainField.size(), 0);

			int tempFieldSize(size);

			if (size % 2 == 0) tempFieldSize /= 2;
			else tempFieldSize = tempFieldSize / 2 + 1;
			

			//берём 1/4 поля, так как все части идентичны
			for (int i = 0; i < tempFieldSize; i++) {

				for (int j = 0; j < tempFieldSize; j++) {

					mainCells[i * size + j] = 1;

				}

			}

			for (int i = 0; i < MainField.size(); i++) {

				if (mainCells[i] == 1) {

					cout << "начало\n";

					queensIndexes.push_back(i); //заход

					SmallestNumberOfMoves(minMoves, countMoves, MainField, queensIndexes, result, size, currentDirection, i, n + 1);

					queensIndexes.erase(queensIndexes.end() - 1); // откат

					cout << "конец\n";

				}

			}

		}

		else {
			vector<int> tempSteps(MainField.size(), 0); //вектор текущих шагов

			//считаем возможные шаги
			NextStep(tempSteps, pos);

			vector<int> directions(8, 0);
			
			int a;
			int b;
			int k;

			if (n % 2 == 1) {
				a = MainField.size()-1;
				b = -1;
				k = -1;
			}
			else {
				a = 0;
				b = MainField.size();
				k = 1;
			}

			//записываем прошлое направление
			int lastDirection = currentDirection;
			
			//цикл (перебираем поле с возможными шагами) с наибольшим ходом
			for (int i = a; (i > b) || (i < b); i+=k) {
				
				bool isQueenIndex(false);

				//проверка, является ли текущий индекс уже пройденным
				for (int t = 0; t < queensIndexes.size(); t++) if (queensIndexes[t] == i) isQueenIndex = true;

				//заходим в случае, если клетка - путь, и она не повторяет прошлое направление и не совершает ход назад
				if ((tempSteps[i] != 0) && (isQueenIndex == false) && ((lastDirection == 0) || (tempSteps[i] != lastDirection) && (tempSteps[i] != (((lastDirection + 3) % 8) + 1)))) {

					 //считаем число ходов для каждого направления
					if (i < pos) {

						for (int j = pos; j >= i; j--) if(tempSteps[j] == tempSteps[i]) directions[tempSteps[i]-1]++;
						
					}
					else {

						for (int j = pos; j <= i; j++) if (tempSteps[j] == tempSteps[i]) directions[tempSteps[i]-1]++;

					}

					//последнее направление
					currentDirection = tempSteps[i];

					int countEmpty = GetEmpty(MainField);
					//если клетка доступна для хода																											|
					//если текущее количество шагов превышает рекордно-минимальное или нет новых битых клеток: шаг назад; продолжить						V		
					if ((minMoves > countMoves + 1) && (minMoves - countMoves - 1 < 2 * ((int)sqrt(countEmpty - directions[tempSteps[i]-1]) + 1))) {
						int beforeEmpty = countEmpty;

						vector<int> oneStep; //вектор, содержащий 1 ход

						//делаем шаг на возможную позицию
						oneStep = Step(MainField, pos, i, size); //запоминаем сделанный ход

						//отмечаем ход ферьзя
						queensIndexes.push_back(i);

						countMoves++;

						if (beforeEmpty == GetEmpty(MainField)) {

							PreviewStep(MainField, oneStep);
							queensIndexes.erase(queensIndexes.end() - 1); //откат в случае неудачного хода
							countMoves--;
							continue;

						}

						//рекурсия
						SmallestNumberOfMoves(minMoves, countMoves, MainField, queensIndexes, result, size, currentDirection, i, n + 1);

						queensIndexes.erase(queensIndexes.end() - 1); //откат в случае неудачного хода

						countMoves--;

						//шаг назад
						PreviewStep(MainField, oneStep);

					}

				}

			}

		}

	}

}

void NextStep(vector<int>& field, int index)
{

	int n = sqrt(field.size());
	int size = field.size();
	//вертикали
	for (int i = index + n; i < size; i += n) {
		field[i] += 5;
	}
	for (int i = index - n; i >= 0; i -= n) {
		field[i] += 1;
	}
	//диагональ
	bool ifBarrier(false);
	for (int i = index; (i >= 0) && (ifBarrier == false); i -= (n + 1)) { //вверх влево
		if (i != index) field[i] += 8;
		if ((i % n) == 0) ifBarrier = true; //проверка, не уткнулась ли диагональ в стенку
	}
	ifBarrier = false;
	for (int i = index; (i >= 0) && (ifBarrier == false); i -= (n - 1)) { //вверх вправо
		if (i != index) field[i] += 2;
		if (((i + 1) % n) == 0) ifBarrier = true;
	}
	ifBarrier = false;
	for (int i = index; (i < size) && (ifBarrier == false); i += (n - 1)) { //вниз влево
		if (i != index) field[i] += 6;
		if ((i % n) == 0) ifBarrier = true;
	}
	ifBarrier = false;
	for (int i = index; (i < size) && (ifBarrier == false); i += (n + 1)) { //вниз вправо
		if (i != index) field[i] += 4;
		if (((i + 1) % n) == 0) ifBarrier = true;
	}
	for (int i = index; i < index - (index % n) + n; i++) { //горизонтали
		if (i != index) field[i] += 3;
	}
	for (int i = index; i >= index - (index % n); i--) { //горизонтали
		if (i != index) field[i] += 7;
	}

}

vector<int> Step(vector<int>& field, int startInd, int pos, int n) {

	vector<int> oneStep(n*n, 0);

	if (pos > startInd) {

		if (pos % n == startInd % n) { //вертикаль

			for (int i = startInd; i <= pos; i += n) {
				field[i]++;
				oneStep[i]++;
			}

		}
		else if (pos < ((startInd / n) + 1) * n) { //горизонталь

			for (int i = startInd; i <= pos; i++) {
				field[i]++;
				oneStep[i]++;
			}

		}
		else if (pos % n < startInd % n) { //диагональ вниз-влево

			for (int i = startInd; i <= pos; i += (n-1)) {
				field[i]++;
				oneStep[i]++;
			}

		}
		else { //диагональ вниз-вправо

			for (int i = startInd; i <= pos; i += (n + 1)) {
				field[i]++;
				oneStep[i]++;
			}

		}

	}
	else {

		if (pos % n == startInd % n) { //вертикаль

			for (int i = startInd; i >= pos; i -= n) {
				field[i]++;
				oneStep[i]++;
			}

		}
		else if (pos >= (startInd / n) * n) { //горизонталь

			for (int i = startInd; i >= pos; i--) {
				field[i]++;
				oneStep[i]++;
			}

		}
		else if (pos % n < startInd % n) { //диагональ вверх-влево

			for (int i = startInd; i >= pos; i -= (n + 1)) {
				field[i]++;
				oneStep[i]++;
			}

		}
		else { //диагональ вверх-вправо

			for (int i = startInd; i >= pos; i -= (n - 1)) {
				field[i]++;
				oneStep[i]++;
			}

		}

	}

	return oneStep;

}

void PreviewStep(vector<int>& field, vector<int> oneStep) {

	for (int i = 0; i < oneStep.size(); i++) {
		
		if (oneStep[i]) field[i]--;

	}

}




//Задача №4

void AttackOfQueens(const int p, const int n, vector<int>& MainField, vector<int>& queensField, vector<int>& result, int& QueensCount, int thisStep, int size, int count) {
	for (int i = thisStep; i < n * n; i++) {
		time_t start = clock();
		NextStep(MainField, queensField, i, size, n); //шаг вперёд
		int tempQueensCount(0);
		int numberTrueField(0);
		bool flag(true);
		for (int j = 0; (j < size) && (flag==true); j++) {
			if (queensField[j] == 1) {
				tempQueensCount++;
				if(MainField[j] == p) numberTrueField++;
				else if (MainField[j] > p) flag = false;
			}
		}
		if ((numberTrueField == tempQueensCount) && (QueensCount < tempQueensCount)) {
			QueensCount = tempQueensCount;
			for (int i = 0; i < size; i++) {
				result[i] = queensField[i];
			}
		}
		if (flag == true) {
			AttackOfQueens(p, n, MainField, queensField, result, QueensCount, i + 1, size, count+1);
		}
		PreviewStep(MainField, queensField, i, size, n); //шаг назад
		
		time_t end = clock();
		if ((count == 1) && (i == 0)) cout << "На выполнение программы~" << (((double)(end - start) / CLOCKS_PER_SEC) / 16.5f * 100) << "с\n\n";
		if (count == 1) cout << (double)(100 / size) * (i + 1) << "%\n";
	}
}

void NextStep(vector<int>& field, vector<int>& queensField, int index, int size, int n)
{
	queensField[index] = 1;
	//вертикали
	for (int i = index+n; i < size; i += n) {
		field[i]++;
	}
	for (int i = index-n; i >= 0; i -= n) {
		field[i]++;
	}
	//диагональ
	bool ifBarrier(false); 
	for (int i = index; (i >= 0) && (ifBarrier == false); i -= (n + 1)) { //вверх влево
		if (i != index) field[i]++;
		if ((i % n) == 0) ifBarrier = true; //проверка, не уткнулась ли диагональ в стенку
	}
	ifBarrier = false;
	for (int i = index; (i >= 0) && (ifBarrier == false); i -= (n - 1)) { //вверх вправо
		if (i != index) field[i]++;
		if (((i+1) % n) == 0) ifBarrier = true;
	}
	ifBarrier = false;
	for (int i = index; (i < size) && (ifBarrier == false); i += (n - 1)) { //вниз влево
		if (i != index) field[i]++;
		if ((i % n) == 0) ifBarrier = true;
	}
	ifBarrier = false;
	for (int i = index; (i < size) && (ifBarrier == false); i += (n + 1)) { //вниз вправо
		if (i != index) field[i]++;
		if (((i + 1) % n) == 0) ifBarrier = true;
	}
	for (int i = index - (index % n); i < index - (index % n) + n; i++) { //
		if (i != index) field[i]++;
	}
}

void PreviewStep(vector<int>& field, vector<int>& queensField, int index, int size, int n)
{
	queensField[index] = 0;
	//вертикали
	for (int i = index + n; i < size; i += n) {
		field[i]--;
	}
	for (int i = index - n; i >= 0; i -= n) {
		field[i]--;
	}
	//диагональ
	bool ifBarrier(false);
	for (int i = index; (i >= 0) && (ifBarrier == false); i -= (n + 1)) { //вверх влево
		if (i != index) field[i]--;
		if ((i % n) == 0) ifBarrier = true; //проверка, не уткнулась ли диагональ в стенку
	}
	ifBarrier = false;
	for (int i = index; (i >= 0) && (ifBarrier == false); i -= (n - 1)) { //вверх вправо
		if (i != index) field[i]--;
		if (((i + 1) % n) == 0) ifBarrier = true;
	}
	ifBarrier = false;
	for (int i = index; (i < size) && (ifBarrier == false); i += (n - 1)) { //вниз влево
		if (i != index) field[i]--;
		if ((i % n) == 0) ifBarrier = true;
	}
	ifBarrier = false;
	for (int i = index; (i < size) && (ifBarrier == false); i += (n + 1)) { //вниз вправо
		if (i != index) field[i]--;
		if (((i + 1) % n) == 0) ifBarrier = true;
	}
	for (int i = index - (index % n); i < index - (index % n) + n; i++) { //
		if (i != index) field[i]--;
	}
}




//Задача №5

void KnightTraversingTheChessboard(int** field, int N, int M, vector<int> position, vector<int>& result) {

	if (getEmptyCells(field, N, M) == 0) {

		int ind(0);

		cout << "\nПуть коня: ";

		for (int i = 0; i < result.size()/2; i++) { //вывод пути

			cout << "(" << result[ind++] - 2 << ";";
			cout << result[ind++]-2 << ") ";

		}

	}
	else {
		
		field[position[0]][position[1]] = 1; //отмечаем на поле

		vector<int> counter;

		for (int i = 0; i < 8; i++) {

			vector<int> newPosition = { position[0] + rateKnight[i][0], position[1] + rateKnight[i][1] };

			if (field[newPosition[0]][newPosition[1]] == 0) {

				counter.push_back(countingSteps(field, N, M, newPosition)); //cохраняем массив с количеством ходов

			}

			else counter.push_back(9); //запоняем бессмысленные поля;

		}

		int minSteps = *min_element(counter.begin(), counter.end()); //находим минимальный элемент вектора

		int minStepsIndex;

		int tempCounter(0); //для подсчёта, остлись ли пути

		for (int i = 0; i < 8; i++) if (counter[i] == minSteps) {

			minStepsIndex = i;

			tempCounter++;

		}

		if (tempCounter == 8 && counter[0] == 9) {

			cout << "Обход всего поля с данной позиции и поля данной размерности и данным способом невозможен";

		}
		else {

			position = { position[0] + rateKnight[minStepsIndex][0], position[1] + rateKnight[minStepsIndex][1] }; //запоминаем шаг

			field[position[0]][position[1]] = 1;

			result.push_back(position[0]);
			result.push_back(position[1]);

			KnightTraversingTheChessboard(field, N, M, position, result);

		}

	}

}

int countingSteps(int** field, int N, int M, vector<int> position)
{
	int counter(0);

	for (int i = 0; i < 8; i++) {
		
		vector<int> newPosition = { position[0] + rateKnight[i][0], position[1] + rateKnight[i][1] };

		if (field[newPosition[0]][newPosition[1]] == 0) counter++;

	}

	return counter;

}

int getEmptyCells(int** field, int N, int M) {

	int counter(0);

	for (int i = 0; i < N+4; i++) {

		for (int j = 0; j < M+4; j++) {

			if (field[i][j] == 0) counter++;

		}

	}

	return counter;

}

void KnightTraversingTheChessboard(int** field, int N, int M, vector<int> position, int& result) {

	if (getEmptyCells(field, N, M) == 0) {

		result++;

	}
	else {

		field[position[0]][position[1]] = 1; //отмечаем на поле

		vector<int> counter;

		for (int i = 0; i < 8; i++) {

			vector<int> newPosition = { position[0] + rateKnight[i][0], position[1] + rateKnight[i][1] };


			if (field[newPosition[0]][newPosition[1]] == 0) {
			
				field[newPosition[0]][newPosition[1]] = 1;

				KnightTraversingTheChessboard(field, N, M, newPosition, result);

				field[newPosition[0]][newPosition[1]] = 0;
			
			}


		}

	}

}



//Задача №6

void ArrangementOfMagaraja(vector<int>& field, vector<int>& vertical, vector<int>& diagonalUp, vector<int>& diagonalDown, vector<int>& knight, int& count, int size) {


	if (count == size) { //если количество собранных строк равно размерности

		int k(0);

		for (int i = 0; i < 10; i++) {

			for (int j = 0; j < 10; j++) {

				cout << field[k++] << " ";

			}

			cout << "\n";

		}

		cout << "\n\n";

	}
	else {

		vector<int> step(size, 0); //текущий ряд

		for (int i = 0; i < size; i++) {

			if (vertical[count * size + i] >= 1 || diagonalDown[count * size + i] >= 1 || diagonalUp[count * size + i] >= 1 || knight[count*size+i] >= 1) step[i] = 1;

		}

		int j(0);

		for (int i = count * size; i < (count + 1) * size; i++) {

			if (step[j++] == 0) {

				vector<int> indexes;

				NextStep(field, vertical, diagonalUp, diagonalDown, count, size, i);

				NextStepKnight(knight, i, indexes);

				ArrangementOfMagaraja(field, vertical, diagonalUp, diagonalDown, knight, count, size);

				PreviewStep(field, vertical, diagonalUp, diagonalDown, count, size, i);

				PreviewStepKnight(indexes, knight);

			}

		}

	}

}

void NextStepKnight(vector<int>& knight, int index, vector<int>& indexes) {

	for (int i = 0; i < 8; i++) {

		if ((index < 10) && ((i == 0) || (i == 1) || (i == 6) || (i == 7))) continue;
		
		if ((index < 20) && ((i == 0) || (i == 7))) continue;

		if ((index > 89) && ((i == 3) || (i == 4))) continue;

		if ((index > 79) && ((i == 2) || (i == 3) || (i == 4) || (i == 5))) continue;

		if ((index % 10 == 0) && ((i == 4) || (i == 5) || (i == 6) || (i == 7))) continue;

		if ((index % 10 == 1) && ((i == 5) || (i == 6))) continue;

		if ((index % 10 == 9) && ((i == 0) || (i == 1) || (i == 2) || (i == 3))) continue;

		if ((index % 10 == 8) && ((i == 1) || (i == 2))) continue;

		int newIndex = index + (rateKnight[i][0] * 10) + rateKnight[i][1];

		if ((newIndex >= 0) && (newIndex < 100)) {



			knight[newIndex]++;

			indexes.push_back(newIndex);

		}

	}
}

void PreviewStepKnight(vector<int> indexes, vector<int>& knight) {

	for (int i = 0; i < indexes.size(); i++) {
		knight[indexes[i]]--;
	}

}


#pragma endregion 






/*

#pragma region lab5

//Задача №1

vector<vector<int>> read_maze() {

	string filename = "maze.txt";

	vector<vector<int>>result;

	ifstream fin(filename);

	int n, m;

	fin >> n >> m;

	int num;

	for (int i = 0; i < n; ++i) {

		result.push_back(vector<int>(m, 0));

		for (int j = 0; j < m; ++j) {

			fin >> num;

			result[i][j] = num;

		}

	}

	fin.close();

	return result;
}

void find_way(vector<vector<int>>& maze, int startx, int starty, int endx, int endy, vector<vector<int>>& result_maze, bool& flag, int& turn) {

	if (startx == endx && starty == endy) {

		maze[startx][starty] = turn;

		result_maze = maze;

		flag = true;

	}
	else {

		maze[startx][starty] = turn;

		if (maze[startx][starty] >= result_maze[endx][endy] && flag) {

			maze[startx][starty] = 0;

			return;

		}

		for (int k = 0; k < 4; ++k) {

			if (maze[startx + rateMaze[k][0]][starty + rateMaze[k][1]] == 0 || maze[startx + rateMaze[k][0]][starty + rateMaze[k][1]] == result_maze[endx][endy]) {

				turn++;

				find_way(maze, startx + rateMaze[k][0], starty + rateMaze[k][1], endx, endy, result_maze);

				turn--;

				maze[startx + rateMaze[k][0]][starty + rateMaze[k][1]] = 0;
			}

		}

	}

}

void set_points(vector<vector<int>>& maze, int& startx, int& starty, int& endx, int& endy) {

	for (int i = 0; i < maze.size(); ++i) {

		for (int j = 0; j < maze[0].size(); ++j) {

			if (maze[i][j] == -2) {

				startx = i;
				starty = j;

			}

			if (maze[i][j] == -3) {

				endx = i;
				endy = j;

			}

		}

	}

}




//Задача №2

void set(int& n, vector<int>& v, vector<int>& w, int& W) {

	string filename = "backpack.txt";

	ifstream fin(filename);

	fin >> n;

	int num;

	for (int i = 0; i < n; ++i) {

		fin >> num;
		w.push_back(num);

		fin >> num;
		v.push_back(num);

	}

	fin >> W;

	fin.close();
}

void find_max_cost(int types, int cur_weight, int cur_cost, vector<int>& weight, vector<int>& price, int MAXWEIGHT, vector<int>& backpack, vector<int>& backpack_result) {


	if (backpack_cost(backpack, price) > backpack_cost(backpack_result, price)) {

		backpack_result = backpack;

	}

	for (int i = 0; i < types; ++i) {

		if (cur_weight + weight[i] <= MAXWEIGHT) {

			backpack[i]++;

			cur_cost += price[i];

			cur_weight += weight[i];



			find_max_cost(types, cur_weight, cur_cost, weight, price, MAXWEIGHT, backpack, backpack_result);

			backpack[i]--;

			cur_cost -= price[i];

			cur_weight -= weight[i];

		}

	}

}

int backpack_cost(vector<int>& backpack, vector<int>& price) {

	int result = 0;

	for (int i = 0; i < backpack.size(); ++i) {

		result += backpack[i] * price[i];

	}

	return result;
}

void print(vector<int> backpack) {

	for (int i = 0; i < backpack.size(); ++i) {

		cout << backpack[i];
		cout << endl;
	}

}




//Задача №3

void set_table() {

	string filename = "places.txt";

	ifstream fin(filename);

	fin >> N;

	int num;

	for (int i = 0; i < N; ++i) {

		TABLE.push_back(vector<int>());

		for (int j = 0; j < N - 1; ++j) {

			fin >> num;

			TABLE[i].push_back(num);

		}

	}

	fin.close();

	cout << "Index of first place: "; cin >> START;
}


#pragma endregion


*/





#pragma region lab6

#pragma endregion









#pragma region lab7

#pragma endregion


