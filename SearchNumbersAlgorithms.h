#pragma once
#include <iostream>
#include <fstream>
using namespace std;



/// <summary>
/// ��������� ������ � ���������� �������
/// </summary>
void lab1task1();

/// <summary>
/// �������� �����
/// </summary>
int LineSearch(int*, int, size_t, long long&, long long&);

/// <summary>
/// ��������� �����
/// </summary>
int BarrierSearch(int*, int, size_t, long long&, long long&);

/// <summary>
/// �������� �����
/// </summary>
int BinarySearch(int*, int, size_t, long long&, long long&);

/// <summary>
/// ����������� �����
/// </summary>
int RecurseSearch(int*, int, size_t, long long&, long long&, long long, long long);
