#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;



/// <summary>
/// Алгоритм поиска подстроки в строке
/// </summary>
void lab2task1();

/// <summary>
/// Считывание строк из файла
/// </summary>
string** FileReader2(string, int&, int&);

/// <summary>
/// Линейный алгоритм поиска подстроки в строке
/// </summary>
int LineSearchStr(string, string, int&);

/// <summary>
/// Алгоритм поиска подстроки в строке Бойера–Мура 
/// </summary>
int boyerMoore(string&, string&, int&);

/// <summary>
/// Создание массива
/// </summary>
int* createArr(string&);

/// <summary>
/// Алгоритм поиска подстроки в строке Кнута–Морриса–Пратта 
/// </summary>
int KnutMorrisPratt(string&, string&, int&);

/// <summary>
/// Алгоритм поиска подстроки в строке Карпа-Рабина
/// </summary>
int karpRabin(string&, string&, int&, int&);

/// <summary>
/// Подсчёт хэша (Алгоритм поиска подстроки в строке Карпа-Рабина)
/// </summary>
int SymbolHash(string&);
