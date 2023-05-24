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
void ArrangementOfQueensMain(int);

/// <summary>
/// �������� ������ (������ � ����������� ������ ������)
/// </summary>
bool ArrangementOfQueensRecurs(vector<int>&, vector<int>&, vector<int>&, vector<int>&, int&, int);

/// <summary>
/// ��� ����� (������ � ����������� ������ ������)
/// </summary>
void NextStep(vector<int>&, vector<int>&, vector<int>&, vector<int>&, int&, int, int);

/// <summary>
/// ��� ����� (������ � ����������� ������ ������)
/// </summary>
void PreviewStep(vector<int>&, vector<int>&, vector<int>&, vector<int>&, int&, int, int);

/// <summary>
/// ��� ���������� (������ � ����������� ������ ������)
/// </summary>
bool AllCombinationsArrangementOfQueensRecurs(vector<int>&, vector<int>&, vector<int>&, vector<int>&, int&, int, bool&);
