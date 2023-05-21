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
void ArrangementOfMagaraja(vector<int>& field, vector<int>& vertical, vector<int>& diagonalUp, vector<int>& diagonalDown, vector<int>& knight, int& count, int size);

/// <summary>
/// Следующий шаг для коня (Задача о расстановке мирных магараджей)
/// </summary>
void NextStepKnight(vector<int>& knight, int index, vector<int>& indexes);

/// <summary>
/// Шаг назад для коня (Задача о расстановке мирных магараджей)
/// </summary>
void PreviewStepKnight(vector<int> indexes, vector<int>& knight);

/// <summary>
/// Следующий шаг для ферзя (Задача о расстановке мирных магараджей)
/// </summary>
void NextStep(vector<int>& field, vector<int>& vertical, vector<int>& diagonalUp, vector<int>& diagonalDown, int& count, int size, int index);

/// <summary>
/// Шаг назад для ферзя (Задача о расстановке мирных магараджей)
/// </summary>
void PreviewStep(vector<int>& field, vector<int>& vertical, vector<int>& diagonalUp, vector<int>& diagonalDown, int& count, int size, int index);
