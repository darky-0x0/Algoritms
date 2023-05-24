#pragma once
#include <vector>
#include <iostream>
using namespace std;



/// <summary>
/// Задача о расстановке мирных магараджей
/// </summary>
void lab4task6();


/// <summary>
/// Задача о расстановке мирных магараджей
/// </summary>
void ArrangementOfMagaraja(vector<int>&, vector<int>&, vector<int>&, vector<int>&, vector<int>&, int&, int);

/// <summary>
/// Следующий шаг для коня (Задача о расстановке мирных магараджей)
/// </summary>
void NextStepKnight(vector<int>&, int, vector<int>&);

/// <summary>
/// Шаг назад для коня (Задача о расстановке мирных магараджей)
/// </summary>
void PreviewStepKnight(vector<int>, vector<int>&);

/// <summary>
/// Следующий шаг для ферзя (Задача о расстановке мирных магараджей)
/// </summary>
void NextStep1(vector<int>&, vector<int>&, vector<int>&, vector<int>&, int&, int, int);

/// <summary>
/// Шаг назад для ферзя (Задача о расстановке мирных магараджей)
/// </summary>
void PreviewStep1(vector<int>&, vector<int>&, vector<int>&, vector<int>&, int&, int, int);
