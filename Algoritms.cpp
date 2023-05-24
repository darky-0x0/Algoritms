#include "Menu.h"

#include "Conditions.h"

#include "Temp.h"

#include <iostream>

#include <conio.h>

using namespace std;





int main()
{

	bool rev = true;

	int lab = 1;

	setlocale(0, "");

	while (rev == true) {

		switch (lab)
		{
		case 1: system("cls");

			lab1Conditions();

			break;

		case 2: system("cls");

			lab2Conditions();

			break;

		case 3: system("cls");

			lab3Conditions();

			break;

		case 4: system("cls");

			lab4Conditions();

			break;

		case 5: system("cls");

			lab5Conditions();

			break;

		case 6: system("cls");

			lab6Conditions();

			break;

		case 7: system("cls");

			lab7Conditions();

			break;

		default:

			break;

		}

		int key;

		cout << "\nДля переключения между лабораторными воспользуйтесь стрелочками\n";

		cout << "Выберите задачу (или 0 для выхода): ";

		key = _getch();

		if (key == 224) {

			key = _getch();

			if (key == 75) {

				if (lab != 1) {

					lab--;

				}

			}
			else if (key == 77) {

				if (lab != 7) {

					lab++;

				}

			}

		}
		else {

			rev = menu(lab, key, rev);

			key = _getch();

		}

	}

}


