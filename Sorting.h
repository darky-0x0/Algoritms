#pragma once
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;




/// <summary>
/// ������� ����������
/// </summary>
void lab3task1();

/// <summary>
/// ���������� ������-��������
/// </summary>
void lab3task2();

/// <summary>
/// ��������� ����������
/// </summary>
void lab3task3();

/// <summary>
/// �������� ������ ��� �����������
/// </summary>
void createFilesForSort();

/// <summary>
/// ���������� ������-��������
/// </summary>
vector<int> sortingByParity(vector<int>, int);

/// <summary>
/// ���������� "�� ��������"
/// </summary>
vector<int> simpleSort(vector<int>, int, int);


/// <summary>
/// �������� ���������� ������� �������
/// </summary>
vector<int> simpleSelect(vector<int>, int, unsigned long int&, unsigned long int&, unsigned long int&);

/// <summary>
/// �������� ���������� "���������"
/// </summary>
vector<int> simpleExchange(vector<int>, int, unsigned long int&, unsigned long int&, unsigned long int&);

/// <summary>
/// �������� ���������� "���������" (���� ���������� ������)
/// </summary>
vector<int> simpleExchangeUpgrade(vector<int>, int, unsigned long int&, unsigned long int&, unsigned long int&);

/// <summary>
/// �������� ���������� "���������" ("������-����������")
/// </summary>
vector<int> simpleExchangeShaker(vector<int>, int, unsigned long int&, unsigned long int&, unsigned long int&);

/// <summary>
/// �������� ������� ���������
/// </summary>
vector<int> insertionSort(vector<int>, int, unsigned long int&, unsigned long int&, unsigned long int&);

/// <summary>
/// �������� ������� ��������� (���������� �������)
/// </summary>
vector<int> insertionSortWithBarrier(vector<int>, int, unsigned long int&, unsigned long int&, unsigned long int&);

/// <summary>
/// �������� ���������� ��������
/// </summary>
vector<int> mergeSort(vector<int>, int, int&, unsigned long int&, unsigned long int&, unsigned long int&);

/// <summary>
/// ������� ���������� �����
/// </summary>
void sortHoar(vector<int>&, int, int, int&, unsigned long int&, unsigned long int&, unsigned long int&);

