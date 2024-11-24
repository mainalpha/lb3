#include <fstream>
#include <iostream>
#include <locale>
#include <string>
using namespace std;

void checkValidInput() // додана додаткова перев≥рка введених параметр≥в
{  
	if (cin.fail())
	{
		throw "Incorrect input";
	}
}

void checkValidParams(int n) // додана додаткова перев≥рка n
{
	checkValidInput();
	if (n < 1)
	{
		throw "Input correct data";
	}
}

void checkValidParamsAB(int a, int b)	// додана додаткова перев≥рка ≥нтервала
{
	checkValidInput();
	if (a > b) {
		throw "Input correct data";
	}
}

void checkValidParamH(int h) // додана додаткова перев≥рка h
{
	checkValidInput();
	if (h < 0)
	{
		throw "Input correct data";
	}
}


int calculate(std::string saveToFile, double a, int n, double h, double b) // вин≥с в окрему функц≥ю обчисленн€
{
	ofstream fout("result.txt"); // запис результату в файл "result.txt"
	if (saveToFile == "yes") {
		int y = 0;

		for (int x = a; x <= b; x += h) {
			if (x <= 0) {
				y = 1;
				for (int i = 0; i <= n - 1; i++)
					y *= (i * i) + i;
				fout << "x =" << x << "; " << "y = " << y << "; " << endl;
				cout << "x = " << x << "; " << "y = " << y << "; " << endl;
			}
			else {
				for (int i = 0; i <= n - 1; i++)
					for (int j = 0; j <= n + 1; j++)
						if ((i + j) != 0)
							y += x / (i + j);
				fout << "x =" << x << "; " << "y = " << y << "; " << endl;
				cout << "x = " << x << "; " << "y = " << y << "; " << endl;
			};
		


		}
		
		return y;
	}
	else {
		int y = 0;
		for (int x = a; x <= b; x += h) {
			if (x <= 0) {
				y = 1;
				for (int i = 0; i <= n - 1; i++)
					y *= (i * i) + i;
				cout << "x = " << x << "; " << "y = " << y << "; " << endl;


			}
			else {
				for (int i = 0; i <= n - 1; i++)
					for (int j = 0; j <= n + 1; j++)
						if ((i + j) != 0)
							y += x / (i + j);
				cout << "x = " << x << "; " << "y = " << y << "; " << endl;


			};
			

		};

		return y;
	};

}


int main()
{
	setlocale(LC_ALL, "Ukrainian");

	int n;
	double x;
	double a, b, h, y = 0;

	try
	{
		cout << "¬ведiть значенн€ n>=1, n=";
		cin >> n;
		checkValidParams(n);
		cout << "¬ведiть початкове значенн€ iнтервалу a = ";
		cin >> a;
		cout << "¬ведiть кiнцеве значенн€ iнтервалу b = ";
		cin >> b;
		checkValidParamsAB(a, b);
		cout << "¬ведiть крок h = ";
		cin >> h;
		checkValidParamH(h);


		std::string saveToFile;
		cout << "ЅажаЇте зберегти результат обчисленн€? (yes/no):";
		cin >> saveToFile;

		calculate(saveToFile, a, n, h, b);
	}
	catch (const char* ex)  // пошук помилок
	{
		cout << ex << endl;
		return -1;
	}
	catch (...) // пошук помилок
	{
		cout << "Unknown err" << endl;
		return -2;
	}


}