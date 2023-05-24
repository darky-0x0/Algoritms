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
void NextStep(vector<int>&, vector<int>&, int);

/// <summary>
/// Откат шага (Задача о расстановке N ферзей и не битых клетках)
/// </summary>
void PreviewStep(vector<int>&, vector<int>&, int);

/// <summary>
/// Задача о расстановке N ферзей и не битых клетках
/// </summary>
void CompactArrangementOfQueens(vector<int>&, vector<int>&, int n, int&, vector<int>&);

/// <summary>
/// Получение пустых клеток
/// </summary>
int GetEmpty1(vector<int>);