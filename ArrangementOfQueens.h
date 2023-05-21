#pragma once
#include <vector>
#include <iostream>
using namespace std;



/// <summary>
/// ������ � ����������� ������ ������
/// </summary>
void lab4task1();


/// <summary>
/// ������� ��� (������ � ����������� ������ ������)
/// </summary>
void ArrangementOfQueensMain(int N);

/// <summary>
/// �������� ������ (������ � ����������� ������ ������)
/// </summary>
bool ArrangementOfQueensRecurs(vector<int>& field, vector<int>& vertical, vector<int>& diagonalUp, vector<int>& diagonalDown, int& count, int size);

/// <summary>
/// ��� ����� (������ � ����������� ������ ������)
/// </summary>
void NextStep(vector<int>& field, vector<int>& vertical, vector<int>& diagonalUp, vector<int>& diagonalDown, int& count, int size, int index);

/// <summary>
/// ��� ����� (������ � ����������� ������ ������)
/// </summary>
void PreviewStep(vector<int>& field, vector<int>& vertical, vector<int>& diagonalUp, vector<int>& diagonalDown, int& count, int size, int index);

/// <summary>
/// ��� ���������� (������ � ����������� ������ ������)
/// </summary>
bool AllCombinationsArrangementOfQueensRecurs(vector<int>& field, vector<int>& vertical, vector<int>& diagonalUp, vector<int>& diagonalDown, int& count, int N, bool& ifFound);
