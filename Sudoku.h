#pragma once
#include <fstream>
#include <vector>
#include <iostream>
#include <conio.h>
#include <cstring>
using namespace std;





/// <summary>
/// ������
/// </summary>
void lab5task4();


/// <summary>
/// ������
/// </summary>
void sudoku(vector<vector<int>> const, vector<pair<pair<int, int>, int>>&, vector<pair<pair<int, int>, int>>&, int);

/// <summary>
/// ������������ ����������� �����
/// </summary>
void possibleSteps(vector<int>&, vector<vector<int>> const, vector<pair<pair<int, int>, int>> const, int);

/// <summary>
/// ��������� �� �����
/// </summary>
void fileRead(string, vector<pair<pair<int, int>, int>>&, vector<vector<int>>&);

/// <summary>
/// �������
/// </summary>
void printField(vector<vector<int>>, vector<pair<pair<int, int>, int>>);
