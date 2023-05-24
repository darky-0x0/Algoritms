#pragma once
#include <conio.h>
#include <vector>
#include <fstream>
#include <iostream>
using namespace std;



/// <summary>
/// ������ � ���������
/// </summary>
void lab5task1();


/// <summary>
/// ��������� ���
/// </summary>
void nextStep(vector<vector<int>>&, pair<int, int>, pair<int, int>, int);

/// <summary>
/// ��� �����
/// </summary>
void previewStep(vector<vector<int>>&, pair<int, int>, pair<int, int>);

/// <summary>
/// ������ � ���������
/// </summary>
void maze(vector<vector<int>>&, pair<int, int>&, pair<int, int>&, pair<int, int>, pair<int, int>, vector<vector<int>>&, int, int&);

/// <summary>
/// ����� ����
/// </summary>
void printField(vector<vector<int>>, pair<int, int>, pair<int, int>, pair<int, int>);

/// <summary>
/// ������ �� �����
/// </summary>
void readFile(vector<vector<int>>&, pair<int, int>&, pair<int, int>&, pair<int, int>&, string);
