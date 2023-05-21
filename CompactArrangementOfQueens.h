#pragma once
#include <vector>
#include <iostream>
using namespace std;



/// <summary>
/// Задача о расстановке N ферзей и не битых клетках
/// </summary>
void lab4task2();


/// <summary>
/// Следующий шаг (Задача о расстановке N ферзей и не битых клетках)
/// </summary>
void NextStep(vector<int>& field, vector<int>& queensField, int index, int size, int n);

/// <summary>
/// Откат шага (Задача о расстановке N ферзей и не битых клетках)
/// </summary>
void PreviewStep(vector<int>& field, vector<int>& queensField, int index, int size, int n);

/// <summary>
/// Задача о расстановке N ферзей и не битых клетках
/// </summary>
void CompactArrangementOfQueens(vector<int>& mainField, vector<int>& queensField, int n, int& fields, vector<int>& result);

/// <summary>
/// Получение пустых клеток
/// </summary>
int GetEmpty(vector<int> mainField);