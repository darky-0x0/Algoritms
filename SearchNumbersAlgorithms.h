#pragma once
#include <iostream>
#include <fstream>
using namespace std;



/// <summary>
/// Алгоритмы поиска в одномерном массиве
/// </summary>
void lab1task1();

/// <summary>
/// Линейный поиск
/// </summary>
int LineSearch(int*, int, size_t, long long&, long long&);

/// <summary>
/// Барьерный поиск
/// </summary>
int BarrierSearch(int*, int, size_t, long long&, long long&);

/// <summary>
/// Бинарный поиск
/// </summary>
int BinarySearch(int*, int, size_t, long long&, long long&);

/// <summary>
/// Рекурсивный поиск
/// </summary>
int RecurseSearch(int*, int, size_t, long long&, long long&, long long, long long);
