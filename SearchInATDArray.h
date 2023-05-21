#pragma once
#include <iostream>
#include <fstream>
using namespace std;



/// <summary>
/// Алгоритмы линейного и барьерного поиска в двумерном массиве
/// </summary>
void lab1task2();

/// <summary>
/// Алгоритм бинарного поиска в двумерном массиве
/// </summary>
void lab1task3();

/// <summary>
/// Линейный поиск в двумерном массиве
/// </summary>
int TDArrayLineSearch(int**, int, size_t, size_t, int&, int&);

/// <summary>
/// Барьерный поиск в двумерном массиве
/// </summary>
int TDArrayBarrierSearch(int**, int, size_t, size_t, int&, int&);

/// <summary>
/// Бинарный поиск в двумерном массиве
/// </summary>
int TDArrayBinarySearch(int**, int, size_t, size_t, int&, int&, int, int, int, int);

/// <summary>
/// Рекурсивный поиск (Бинарный поиск в двумерном массиве)
/// </summary>
int RecurseSearch(int*, int, size_t, long long, long long);

/// <summary>
/// Чтение массива из файла
/// </summary>
int** FileRead(string filename, int& n, int& m);