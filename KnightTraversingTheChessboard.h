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
void KnightTraversingTheChessboard(int**, int, int, vector<int>, vector<int>&);

/// <summary>
/// Подсчёт возможных шагов из клетки
/// </summary>
int countingSteps(int**, int, int, vector<int>);

/// <summary>
/// Получение пустых клеток
/// </summary>
int getEmptyCells(int**, int, int);

/// <summary>
/// Задача об обходе доски конём (Получение количества возможных обходов)
/// </summary>
void KnightTraversingTheChessboard(int**, int, int, vector<int>, int&);