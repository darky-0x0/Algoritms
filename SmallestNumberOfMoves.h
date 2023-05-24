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
void SmallestNumberOfMoves(int&, int&, vector<int>&, vector<int>&, vector<int>&, int, int currentDirection = 0, int pos = 0, int n = 0);

/// <summary>
/// Подсчёт возможных ходов с места (Задача об обхода ферзём поля)
/// </summary>
void NextStep(vector<int>&, int);

/// <summary>
/// Следующий ход (Задача об обхода ферзём поля)
/// </summary>
vector<int> Step(vector<int>&, int, int, int);

/// <summary>
/// Шаг назад (Задача об обхода ферзём поля)
/// </summary>
void PreviewStep(vector<int>&, vector<int>);

/// <summary>
/// Получение пустых клеток
/// </summary>
int GetEmpty(vector<int>);
