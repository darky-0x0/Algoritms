#pragma once
#include <vector>
#include <iostream>
using namespace std;




/// <summary>
/// Задача об обхода ферзём поля
/// </summary>
void lab4task3();


/// <summary>
/// Задача об обхода ферзём поля
/// </summary>
void SmallestNumberOfMoves(int& minMoves, int& countMoves, vector<int>& MainField, vector<int>& queensIndexes, vector<int>& result, int size, int currentDirection = 0, int pos = 0, int n = 0);

/// <summary>
/// Подсчёт возможных ходов с места (Задача об обхода ферзём поля)
/// </summary>
void NextStep(vector<int>& mainField, int index);

/// <summary>
/// Следующий ход (Задача об обхода ферзём поля)
/// </summary>
vector<int> Step(vector<int>& field, int startInd, int pos, int n);

/// <summary>
/// Шаг назад (Задача об обхода ферзём поля)
/// </summary>
void PreviewStep(vector<int>& field, vector<int> oneStep);

/// <summary>
/// Получение пустых клеток
/// </summary>
int GetEmpty(vector<int> mainField);
