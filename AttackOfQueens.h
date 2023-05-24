#pragma once
#include <vector>
#include <iostream>
using namespace std;


/// <summary>
/// ������ � ����������� ����. ������ � p �������
/// </summary>
void lab4task4();


/// <summary>
/// ������ � ����������� ����. ������ � p �������
/// </summary>
void AttackOfQueens(const int, const int, vector<int>&, vector<int>&, vector<int>&, int&, int, int, int);

/// <summary>
/// ��������� ��� (������ � ����������� ����. ������ � p �������)
/// </summary>
void NextStep(vector<int>&, vector<int>&, int, int, int);

/// <summary>
/// ���������� ��� (������ � ����������� ����. ������ � p �������)
/// </summary>
void PreviewStep(vector<int>&, vector<int>&, int, int, int);
