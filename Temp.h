#pragma once
#include <vector>
#include <iostream>
#include <conio.h>

using namespace std;

void second_solve();

void second_solve(vector<int>&, vector<int>&, int, int&, vector<int>&);

int get_empty(vector<int>);

void print_field(vector<int>&, int);

void place_queen(vector<int>&, vector<int>&, int);

void remove_queen(vector<int>&, vector<int>&, int);

void print(vector<int>&);