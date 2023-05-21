#include "Menu.h"

#include "Temp.h"

#include <iostream>

using namespace std;





int main()
{

	bool rev = true;

	setlocale(0, "");

	while (rev == true) {

		cout << "Выберите задачу (или 0 для выхода): ";

		int key;

		cin >> key;

		rev = menu(key, rev);

	}

}


