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
void ArrangementOfQueensMain(int);

/// <summary>
/// Рекурсия поиска (задача о расстановке мирных ферзей)
/// </summary>
bool ArrangementOfQueensRecurs(vector<int>&, vector<int>&, vector<int>&, vector<int>&, int&, int);

/// <summary>
/// Шаг вперёд (задача о расстановке мирных ферзей)
/// </summary>
void NextStep(vector<int>&, vector<int>&, vector<int>&, vector<int>&, int&, int, int);

/// <summary>
/// Шаг назад (задача о расстановке мирных ферзей)
/// </summary>
void PreviewStep(vector<int>&, vector<int>&, vector<int>&, vector<int>&, int&, int, int);

/// <summary>
/// Все комбинации (задача о расстановке мирных ферзей)
/// </summary>
bool AllCombinationsArrangementOfQueensRecurs(vector<int>&, vector<int>&, vector<int>&, vector<int>&, int&, int, bool&);
