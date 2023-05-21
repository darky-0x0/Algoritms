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
void AttackOfQueens(const int p, const int n, vector<int>& MainField, vector<int>& queensField, vector<int>& result, int& queensCount, int thisStep, int size, int count);

/// <summary>
/// Следующйи шаг (Задача о расстановке макс. ферзей с p атаками)
/// </summary>
void NextStep(vector<int>& MainField, vector<int>& queensField, int pos);

/// <summary>
/// Предыдущий шаг (Задача о расстановке макс. ферзей с p атаками)
/// </summary>
void PreviewStep(vector<int>& MainField, vector<int>& queensField, int pos);
