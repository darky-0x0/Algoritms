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
void SmallestNumberOfMoves(int& minMoves, int& countMoves, vector<int>& MainField, vector<int>& queensIndexes, vector<int>& result, int size, int currentDirection = 0, int pos = 0, int n = 0);

/// <summary>
/// ������� ��������� ����� � ����� (������ �� ������ ����� ����)
/// </summary>
void NextStep(vector<int>& mainField, int index);

/// <summary>
/// ��������� ��� (������ �� ������ ����� ����)
/// </summary>
vector<int> Step(vector<int>& field, int startInd, int pos, int n);

/// <summary>
/// ��� ����� (������ �� ������ ����� ����)
/// </summary>
void PreviewStep(vector<int>& field, vector<int> oneStep);

/// <summary>
/// ��������� ������ ������
/// </summary>
int GetEmpty(vector<int> mainField);
