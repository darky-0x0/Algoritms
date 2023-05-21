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
string** FileReader2(string filename, int& n, int& m);

/// <summary>
/// Линейный алгоритм поиска подстроки в строке
/// </summary>
int LineSearchStr(string str, string substr, int& count);

/// <summary>
/// Алгоритм поиска подстроки в строке Бойера–Мура 
/// </summary>
int boyerMoore(string& s, string& x, int& c);

/// <summary>
/// Создание массива
/// </summary>
int* createArr(string& s);

/// <summary>
/// Алгоритм поиска подстроки в строке Кнута–Морриса–Пратта 
/// </summary>
int KnutMorrisPratt(string& s, string& x, int& c);

/// <summary>
/// Алгоритм поиска подстроки в строке Карпа-Рабина
/// </summary>
int karpRabin(string& s, string& x, int& c, int& hashs);

/// <summary>
/// Подсчёт хэша (Алгоритм поиска подстроки в строке Карпа-Рабина)
/// </summary>
int SymbolHash(string& s);
