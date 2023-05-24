#pragma once
#include <vector>
#include <iostream>
using namespace std;


/// <summary>
/// Задача о расстановке макс. ферзей с p атаками
/// </summary>
void lab4task4();


/// <summary>
/// Задача о расстановке макс. ферзей с p атаками
/// </summary>
void AttackOfQueens(const int, const int, vector<int>&, vector<int>&, vector<int>&, int&, int, int, int);

/// <summary>
/// Следующйи шаг (Задача о расстановке макс. ферзей с p атаками)
/// </summary>
void NextStep(vector<int>&, vector<int>&, int, int, int);

/// <summary>
/// Предыдущий шаг (Задача о расстановке макс. ферзей с p атаками)
/// </summary>
void PreviewStep(vector<int>&, vector<int>&, int, int, int);
