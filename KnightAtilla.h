#pragma once
#include <vector>
#include <iostream>
#include <fstream>
#include <conio.h>
using namespace std;



/// <summary>
/// ������ � ���� ������
/// </summary>
void lab4task7();


/// <summary>
/// ������ � ���� ������
/// </summary>
void AttilaKnight(vector<vector<int>>&, int, pair<int, int>&, pair<int, int> const, pair<int, int> const, vector<vector<int>>&, int);

/// <summary>
/// ��� �����
/// </summary>
void NextStep(vector<vector<int>>&, pair<int, int>, int);

/// <summary>
/// ������ ����
/// </summary>
void PreviewStep(vector<vector<int>>&, pair<int, int>);

/// <summary>
/// ����� ����
/// </summary>

void printField(vector<vector<int>>, int, pair<int, int>);

/// <summary>
/// ���������� ������ �� �����
/// </summary>
void fileRead(vector<vector<int>>&, pair<int, int>&, pair<int, int>&, string);

/// <summary>
/// �������� ����
/// </summary>
vector<vector<int>> createField(int);
