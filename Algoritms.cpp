#include "Menu.h"

#include <iostream>

#include <fstream>

#include <string>

#include <vector>

#include <ctime>

#include "Temp.h"

using namespace std;


#pragma region task_funct

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

void NextStep(vector<int>& field, vector<int>& queensField, int index, int size, int n);
void PreviewStep(vector<int>& field, vector<int>& queensField, int index, int size, int n);
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

		rev = menu(key);

	}

}









#pragma region tasks

//ЛАБА 4

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







#pragma region lab4


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


