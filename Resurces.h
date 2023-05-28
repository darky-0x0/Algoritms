#pragma once
#include <iostream>
#include <fstream>
#include <conio.h>
#include <vector>
using namespace std;



/// <summary>
/// Задача о заявках
/// </summary>
void lab7task3();



/// <summary>
/// Задача о заявках
/// </summary>
void resurcesDistribution(vector<pair<pair<int, int>, int>>&, vector<vector<pair<int, int>>>&, int&);

/// <summary>
/// Сортировка заявок по началу
/// </summary>
void sortRequests(vector<pair<pair<int, int>, int>>&);

/// <summary>
/// Чтение из файла
/// </summary>
void fileRead(string, vector<pair<pair<int, int>, int>>&, int&);

/// <summary>
/// Вывод ресурсов 
/// </summary>
void printResurces(vector<vector<pair<int, int>>> resurces);

