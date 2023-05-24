#pragma once
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;




/// <summary>
/// Простая сортировка
/// </summary>
void lab3task1();

/// <summary>
/// Сортировка чётные-нечётные
/// </summary>
void lab3task2();

/// <summary>
/// Алгоритмы сортировки
/// </summary>
void lab3task3();

/// <summary>
/// Создание файлов для сорттировки
/// </summary>
void createFilesForSort();

/// <summary>
/// Сортировка чётные-нечётные
/// </summary>
vector<int> sortingByParity(vector<int>, int);

/// <summary>
/// Сортировка "по индексам"
/// </summary>
vector<int> simpleSort(vector<int>, int, int);


/// <summary>
/// Алгоритм сортировки простым выбором
/// </summary>
vector<int> simpleSelect(vector<int>, int, unsigned long int&, unsigned long int&, unsigned long int&);

/// <summary>
/// Алгоритм сортировки "пузырьком"
/// </summary>
vector<int> simpleExchange(vector<int>, int, unsigned long int&, unsigned long int&, unsigned long int&);

/// <summary>
/// Алгоритм сортировки "пузырьком" (учёт последнего обмена)
/// </summary>
vector<int> simpleExchangeUpgrade(vector<int>, int, unsigned long int&, unsigned long int&, unsigned long int&);

/// <summary>
/// Алгоритм сортировки "пузырьком" ("шейкер-сортировка")
/// </summary>
vector<int> simpleExchangeShaker(vector<int>, int, unsigned long int&, unsigned long int&, unsigned long int&);

/// <summary>
/// Алгоритм прямого включения
/// </summary>
vector<int> insertionSort(vector<int>, int, unsigned long int&, unsigned long int&, unsigned long int&);

/// <summary>
/// Алгоритм прямого включения (баррьерный элемент)
/// </summary>
vector<int> insertionSortWithBarrier(vector<int>, int, unsigned long int&, unsigned long int&, unsigned long int&);

/// <summary>
/// Алгоритм сортировки слиянием
/// </summary>
vector<int> mergeSort(vector<int>, int, int&, unsigned long int&, unsigned long int&, unsigned long int&);

/// <summary>
/// Быстрая сортировка Хоара
/// </summary>
void sortHoar(vector<int>&, int, int, int&, unsigned long int&, unsigned long int&, unsigned long int&);

