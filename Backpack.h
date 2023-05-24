#pragma once
#include <iostream>
#include <fstream>
#include <conio.h>
#include <vector>
using namespace std;



/// <summary>
/// ������ � �������
/// </summary>
void lab5task2();


/// <summary>
/// ���������� �� �����
/// </summary>
void readFile(vector<pair<int, int>>&, int&, int&, string);

/// <summary>
/// ������ � �������
/// </summary>
void backpack(vector<pair<int, int>> const, int const, vector<int>&, vector<int>&, int const, int&, int&, int&);

/// <summary>
/// ������ � �������
/// </summary>
void backpack2(vector<pair<int, int>> const, int const, vector<int>&, vector<int>&, int const, int&, int, int);

/// <summary>
/// ������� � ������
/// </summary>
void lay(vector<pair<int, int>>, int, vector<int>&, int&, int&);

/// <summary>
/// ������� �� �������
/// </summary>
void layOut(vector<pair<int, int>>, int, vector<int>&, int&, int&);

/// <summary>
/// ������� ���������
/// </summary>
void printResult(int, vector<int>);
