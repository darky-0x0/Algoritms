#pragma once
#include <iostream>
#include <fstream>
#include <conio.h>
#include <vector>
#include <ctime>
#include "Sorting.h"
using namespace std;




/// <summary>
/// Поиск k-ой статистики за линейное в среднем время
/// </summary>
void lab7task4();

/// <summary>
/// Поиск k-ой статистики за линейное в худшем случае время
/// </summary>
void lab7task5();


/// <summary>
/// Поиск k-ой статистики
/// </summary>
int searchingStatistic(vector<int>&, int, int, int, int);

/// <summary>
/// Поиск медианы медиан
/// </summary>
int select(vector<int>&, int, int);

/// <summary>
/// Разбиение по элементу
/// </summary>
pair<int, int> partition(int, int, int, vector<int>&);

/// <summary>
/// Чтение из файла
/// </summary>
void fileRead(string, vector<int>&);

/// <summary>
/// Вывод массива
/// </summary>
void printArray(vector<int>);

/// <summary>
/// Генератор случайного числа до end
/// </summary>
int randGenerate(int, int);

/// <summary>
/// Быстрый обмен элементами массива
/// </summary>
void swap(vector<int>& array, int a, int b);

/// <summary>
/// Сортировка 5 за 7
/// </summary>
void sortFiveForSeven(vector<int>&, int);

/// <summary>
/// Вывод отсортированного массива
/// </summary>
void printSortArray(vector<int>);
