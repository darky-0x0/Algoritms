#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;



/// <summary>
/// �������� ������ ��������� � ������
/// </summary>
void lab2task1();

/// <summary>
/// ���������� ����� �� �����
/// </summary>
string** FileReader2(string, int&, int&);

/// <summary>
/// �������� �������� ������ ��������� � ������
/// </summary>
int LineSearchStr(string, string, int&);

/// <summary>
/// �������� ������ ��������� � ������ ����������� 
/// </summary>
int boyerMoore(string&, string&, int&);

/// <summary>
/// �������� �������
/// </summary>
int* createArr(string&);

/// <summary>
/// �������� ������ ��������� � ������ �������������������� 
/// </summary>
int KnutMorrisPratt(string&, string&, int&);

/// <summary>
/// �������� ������ ��������� � ������ �����-������
/// </summary>
int karpRabin(string&, string&, int&, int&);

/// <summary>
/// ������� ���� (�������� ������ ��������� � ������ �����-������)
/// </summary>
int SymbolHash(string&);
