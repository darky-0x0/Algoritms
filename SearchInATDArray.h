#pragma once
#include <iostream>
#include <fstream>
using namespace std;



/// <summary>
/// ��������� ��������� � ���������� ������ � ��������� �������
/// </summary>
void lab1task2();

/// <summary>
/// �������� ��������� ������ � ��������� �������
/// </summary>
void lab1task3();

/// <summary>
/// �������� ����� � ��������� �������
/// </summary>
int TDArrayLineSearch(int**, int, size_t, size_t, int&, int&);

/// <summary>
/// ��������� ����� � ��������� �������
/// </summary>
int TDArrayBarrierSearch(int**, int, size_t, size_t, int&, int&);

/// <summary>
/// �������� ����� � ��������� �������
/// </summary>
int TDArrayBinarySearch(int**, int, size_t, size_t, int&, int&, int, int, int, int);

/// <summary>
/// ����������� ����� (�������� ����� � ��������� �������)
/// </summary>
int RecurseSearch(int*, int, size_t, long long, long long);

/// <summary>
/// ������ ������� �� �����
/// </summary>
int** FileRead(string filename, int& n, int& m);