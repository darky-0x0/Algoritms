#include "SearchStringsAlgorithms.h"





void lab2task1() {



	string filename = "input_search.txt";

	int n, m, ind1, ind2, ind3, ind4, count1, count2, count3, count4, hash;

	string** str = new string*;

	str = FileReader2(filename, n, m);



	ofstream file;

	file.open("STR_SEARCH_DATA.txt");



	file << "#\tПримеры\t\t\t\t\t\tАлгоритмы поиска подстроки в строке, количество сравнений символов\tКомментарии\n";

	file << " \t\t\t\t\t\t\t\tЛинейный\tБойлера-Мура\tКнута–Морриса–Пратта\tКарпа–Рабина\t" << "\n";



	for (int i = 0; i < 10; i++) {

		count1 = 0;

		count2 = 0;

		count3 = 0;

		count4 = 0;

		hash = 0;

		ind1 = LineSearchStr(str[i][0], str[i][1], count1);

		ind2 = boyerMoore(str[i][0], str[i][1], count2);

		ind3 = KnutMorrisPratt(str[i][0], str[i][1], count3);

		ind4 = karpRabin(str[i][0], str[i][1], count4, hash);

		file << i + 1 << "\t" << str[i][0] << "\n";

		file << " \t" << str[i][1] << "\t" << "\n";

		file << "\t\t\t\t\t\t\t\t\t" << count1 << "\t\t" << count2 << "\t\t\t" << count3 << "\t\t\t\t" << count4 + hash << "\t\t" << "\n";

	}



	//	ind = KnutMorrisPratt(str[i][0], str[i][1], count);
	//	ind = boyerMoore(str[i][0], str[i][1], count);
	//	ind = LineSearchStr(str[i][0], str[i][1], count);


}


string** FileReader2(string filename, int& n, int& m) {

	ifstream file;

	string line;

	file.open(filename);

	file >> n;

	file >> m;

	getline(file, line);

	string** a = new string * [n];

	for (int i = 0; i < n; i++) {

		a[i] = new string[m];

		for (int j = 0; j < m; j++) {

			getline(file, line);

			a[i][j] = line;

		}

		getline(file, line);

	}

	return a;

}

int LineSearchStr(string str, string substr, int& count) {

	int tmp(0), tmpI(0);

	for (int i = 0; i < str.length() - substr.length() + 1; i++) {

		tmpI = i;

		for (int j = 0; j < substr.length(); j++) {

			if (str[tmpI++] != substr[j]) {

				count++;

				break;

			}

			tmp = j + 1;

			count++;

		}

		if (tmp == (substr.length())) return i;

	}

	return -1;

}

int boyerMoore(string& s, string& x, int& count) {

	int index = -1;

	count = 0;

	int* ind = createArr(x);

	int i(x.size() - 1), j(x.size() - 1);

	int sum = 0;

	while (i < s.size()) {

		while (j != -1 && ++count && s[i] == x[j]) {

			j--;

			i--;

			sum++;

		}

		if (j == -1) {

			index = i + 1;

			break;

		}

		j = x.size() - 1;

		i += ind[s[i]] + sum;

		sum = 0;

	}

	return index;

}

int* createArr(string& s) {

	int tmp[500];

	int k = 1;

	for (int i = 0; i < 500; ++i) {

		tmp[i] = s.size();

	}

	for (int i = s.size() - 2; i >= 0; --i) {

		if (tmp[s[i]] == s.size()) {



			tmp[s[i]] = k;



		}

		k++;

	}

	return tmp;

}

int KnutMorrisPratt(string& s, string& x, int& c)

{

	c = 0;

	int m = s.size();

	int n = x.size();

	vector<int> next(n + 1, 0);

	for (int i = 1; i < n; ++i)

	{

		int j = next[i + 1];

		while (j > 0 && x[j] != x[i]) {

			j = next[j];

		}

		if (j > 0 || x[j] == x[i]) {

			next[i + 1] = j + 1;

		}

	}

	for (int i = 0, j = 0; i < m; ++i) {

		if (++c && s[i] == x[j]) {

			if (++j == n) {

				return i - j + 1;

			}

		}

		else if (j > 0) {

			j = next[j];

			i--;

		}

	}

	return -1;

}

int karpRabin(string& s, string& x, int& c, int& hashs) {

	c = 0;

	hashs = 0;

	int patHash = SymbolHash(x);

	int n = s.size();

	int m = x.size();

	int i = m - 1;

	while (i < n) {

		string temp = s.substr(i, m);

		if (++hashs && SymbolHash(temp) == patHash) {

			int j = 0;

			while (j < m && ++c && x[j] == s[i + j]) {

				j++;

			}

			if (j == m) {

				return i;

			}

		}

		i++;

	}

	return -1;

}

int SymbolHash(string& s) {

	int hash = 0;

	for (int i = 0; i != s.size(); ++i) {

		hash += s[i];

	}

	return hash;

}