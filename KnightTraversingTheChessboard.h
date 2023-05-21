#pragma once
#include <vector>
#include <iostream>
#include <ctime>
using namespace std;



/// <summary>
/// Задача об обходе доски конём 
/// </summary>
void lab4task5();


/// <summary>
/// Задача об обходе доски конём (Получение пути)
/// </summary>
void KnightTraversingTheChessboard(int** field, int N, int M, vector<int> position, vector<int>& result);

/// <summary>
/// Подсчёт возможных шагов из клетки
/// </summary>
int countingSteps(int** field, int N, int M, vector<int> position);

/// <summary>
/// Получение пустых клеток
/// </summary>
int getEmptyCells(int** field, int N, int M);

/// <summary>
/// Задача об обходе доски конём (Получение количества возможных обходов)
/// </summary>
void KnightTraversingTheChessboard(int** field, int N, int M, vector<int> position, int& result);