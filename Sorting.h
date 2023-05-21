#pragma once
#include <iostream>
#include <vector>
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
vector<int> sortingByParity(vector<int> array, int size);

/// <summary>
/// Сортировка "по индексам"
/// </summary>
vector<int> simpleSort(vector<int> array, int size, int m);


/// <summary>
/// Алгоритм сортировки простым выбором
/// </summary>
vector<int> simpleSelect(vector<int> array, int size, unsigned long int& comparisonWithElement, unsigned long int& comparisionWithNotElement, unsigned long int& countReplace);

/// <summary>
/// Алгоритм сортировки "пузырьком"
/// </summary>
vector<int> simpleExchange(vector<int> array, int size, unsigned long int& comparisonWithElement, unsigned long int& comparisionWithNotElement, unsigned long int& countReplace);

/// <summary>
/// Алгоритм сортировки "пузырьком" (учёт последнего обмена)
/// </summary>
vector<int> simpleExchangeUpgrade(vector<int> array, int size, unsigned long int& comparisonWithElement, unsigned long int& comparisionWithNotElement, unsigned long int& countReplace);

/// <summary>
/// Алгоритм сортировки "пузырьком" ("шейкер-сортировка")
/// </summary>
vector<int> simpleExchangeShaker(vector<int> array, int size, unsigned long int& comparisonWithElement, unsigned long int& comparisionWithNotElement, unsigned long int& countReplace);

/// <summary>
/// Алгоритм прямого включения
/// </summary>
vector<int> insertionSort(vector<int> array, int size, unsigned long int& comparisonWithElement, unsigned long int& comparisionWithNotElement, unsigned long int& countReplace);

/// <summary>
/// Алгоритм прямого включения (баррьерный элемент)
/// </summary>
vector<int> insertionSortWithBarrier(vector<int> arrayA, int size, unsigned long int& comparisonWithElement, unsigned long int& comparisionWithNotElement, unsigned long int& countReplace);

/// <summary>
/// Алгоритм сортировки слиянием
/// </summary>
vector<int> mergeSort(vector<int> array, int size, int& count, unsigned long int& comparisonWithElement, unsigned long int& comparisionWithNotElement, unsigned long int& countReplace);

/// <summary>
/// Быстрая сортировка Хоара
/// </summary>
void sortHoar(vector<int>& array, int first, int last, int& count, unsigned long int& comparisonWithElement, unsigned long int& comparisionWithNotElement, unsigned long int& countReplace);

