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
void AttackOfQueens(const int p, const int n, vector<int>& MainField, vector<int>& queensField, vector<int>& result, int& queensCount, int thisStep, int size, int count);

/// <summary>
/// ��������� ��� (������ � ����������� ����. ������ � p �������)
/// </summary>
void NextStep(vector<int>& MainField, vector<int>& queensField, int pos);

/// <summary>
/// ���������� ��� (������ � ����������� ����. ������ � p �������)
/// </summary>
void PreviewStep(vector<int>& MainField, vector<int>& queensField, int pos);
