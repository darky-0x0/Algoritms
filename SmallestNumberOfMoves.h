#pragma once
#include <vector>
#include <iostream>
using namespace std;




/// <summary>
/// ������ �� ������ ����� ����
/// </summary>
void lab4task3();


/// <summary>
/// ������ �� ������ ����� ����
/// </summary>
void SmallestNumberOfMoves(int&, int&, vector<int>&, vector<int>&, vector<int>&, int, int currentDirection = 0, int pos = 0, int n = 0);

/// <summary>
/// ������� ��������� ����� � ����� (������ �� ������ ����� ����)
/// </summary>
void NextStep(vector<int>&, int);

/// <summary>
/// ��������� ��� (������ �� ������ ����� ����)
/// </summary>
vector<int> Step(vector<int>&, int, int, int);

/// <summary>
/// ��� ����� (������ �� ������ ����� ����)
/// </summary>
void PreviewStep(vector<int>&, vector<int>);

/// <summary>
/// ��������� ������ ������
/// </summary>
int GetEmpty(vector<int>);
