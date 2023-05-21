#pragma once
#include <vector>
#include <iostream>
using namespace std;



/// <summary>
/// Задача о расстановке мирных ферзей
/// </summary>
void lab4task1();


/// <summary>
/// Главный код (задача о расстановке мирных ферзей)
/// </summary>
void ArrangementOfQueensMain(int N);

/// <summary>
/// Рекурсия поиска (задача о расстановке мирных ферзей)
/// </summary>
bool ArrangementOfQueensRecurs(vector<int>& field, vector<int>& vertical, vector<int>& diagonalUp, vector<int>& diagonalDown, int& count, int size);

/// <summary>
/// Шаг вперёд (задача о расстановке мирных ферзей)
/// </summary>
void NextStep(vector<int>& field, vector<int>& vertical, vector<int>& diagonalUp, vector<int>& diagonalDown, int& count, int size, int index);

/// <summary>
/// Шаг назад (задача о расстановке мирных ферзей)
/// </summary>
void PreviewStep(vector<int>& field, vector<int>& vertical, vector<int>& diagonalUp, vector<int>& diagonalDown, int& count, int size, int index);

/// <summary>
/// Все комбинации (задача о расстановке мирных ферзей)
/// </summary>
bool AllCombinationsArrangementOfQueensRecurs(vector<int>& field, vector<int>& vertical, vector<int>& diagonalUp, vector<int>& diagonalDown, int& count, int N, bool& ifFound);
