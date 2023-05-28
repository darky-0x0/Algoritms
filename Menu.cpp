#include "Menu.h"





bool menu(int lab, int key, bool rev)
{

	switch (key)
	{

	case 49: key = 1;

		break;

	case 50: key = 2;

		break;

	case 51: key = 3;

		break;

	case 52: key = 4;

		break;

	case 53: key = 5;

		break;

	case 54: key = 6;

		break;

	case 55: key = 7;

		break;

	case 56: key = 8;

		break;

	case 57: key = 9;

		break;

	case 48: key = 0;

		break;

	default:
		break;
	}

	switch (lab) {

	case 1: system("cls");

		switch (key) {

		case 1: system("cls");

			lab1task1;

			break;

		case 2: system("cls");

			lab1task2();

			break;

		case 3: system("cls");

			lab1task3();

			break;

		case 0: rev = false;

			break;

		default:

			break;

		}

		break;

	case 2: system("cls");

		switch (key) {

		case 1: system("cls");

			lab2task1();

			break;

		case 0: rev = false;

			break;

		default:

			break;

		}

		break;

	case 3: system("cls");

		switch (key) {

		case 1: system("cls");

			lab3task1();

			break;

		case 2: system("cls");

			lab3task2();

			break;

		case 3: system("cls");

			lab3task3();

			break;

		case 0: rev = false;

			break;

		default:

			break;

		}

		break;

	case 4: system("cls");

		switch (key) {

		case 1: system("cls");

			lab4task1();

			break;

		case 2: system("cls");

			lab4task2();

			break;

		case 3: system("cls");

			lab4task3();

			break;

		case 4: system("cls");

			lab4task4();

			break;

		case 5: system("cls");

			lab4task5();

			break;

		case 6: system("cls");

			lab4task6();

			break;

		case 7: system("cls");

			lab4task7();

			break;

		case 0: rev = false;

			break;

		default:

			break;

		}
		
		break;

	case 5: system("cls");

		switch (key) {

		case 1: system("cls");

			lab5task1();

			break;

		case 2: system("cls");

			lab5task2();

			break;

		case 3: system("cls");

			lab5task3();

			break;

		case 4: system("cls");

			lab5task4();

			break;

		case 0: rev = false;

			break;

		default:

			break;

		}

		break;

	case 6: system("cls");

		switch (key) {

		case 1: system("cls");

			lab6task1();

			break;

		case 2: system("cls");

			lab6task2();

			break;

		case 3: system("cls");

			lab6task3();

			break;

		case 4: system("cls");

			lab6task4();

			break;

		case 5: system("cls");

			lab6task5();

			break;

		case 6: system("cls");

			lab6task6();

			break;

		case 0: rev = false;

			break;

		default:

			break;

		}

		break;

	case 7: system("cls");

		switch (key) {

		case 1: system("cls");

			lab7task1();

			break;

		/*case 2: system("cls");

			lab7task2();

			break;*/

		/*case 3: system("cls");
		
			lab7task3();
		
			break;*/
		
		/*case 4: system("cls");
		
			lab7task4();
		
			break;*/
		
		/*case 5: system("cls");
		
			lab7task5();
		
			break;*/
		
		/*case 6: system("cls");
		
			lab7task6();
		
			break;*/
		
		/*case 7: system("cls");
		
			lab7task7();
		
			break;*/

		case 8: system("cls");
	
			task666();
	
			break;


		case 0: rev = false;

			break;

		default:

			break;

		}

		break;

	default:

		break;

	}

	return rev;

}