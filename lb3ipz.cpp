#include <fstream>
#include <iostream>
#include <locale>
#include <string>
using namespace std;

void checkValidInput() // ������ ��������� �������� �������� ���������
{  
	if (cin.fail())
	{
		throw "Incorrect input";
	}
}

void checkValidParams(int n) // ������ ��������� �������� n
{
	checkValidInput();
	if (n < 1)
	{
		throw "Input correct data";
	}
}

void checkValidParamsAB(int a, int b)	// ������ ��������� �������� ���������
{
	checkValidInput();
	if (a > b) {
		throw "Input correct data";
	}
}

void checkValidParamH(int h) // ������ ��������� �������� h
{
	checkValidInput();
	if (h < 0)
	{
		throw "Input correct data";
	}
}


int calculate(std::string saveToFile, double a, int n, double h, double b) // ���� � ������ ������� ����������
{
	ofstream fout("result.txt"); // ����� ���������� � ���� "result.txt"
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
		cout << "����i�� �������� n>=1, n=";
		cin >> n;
		checkValidParams(n);
		cout << "����i�� ��������� �������� i�������� a = ";
		cin >> a;
		cout << "����i�� �i����� �������� i�������� b = ";
		cin >> b;
		checkValidParamsAB(a, b);
		cout << "����i�� ���� h = ";
		cin >> h;
		checkValidParamH(h);


		std::string saveToFile;
		cout << "������ �������� ��������� ����������? (yes/no):";
		cin >> saveToFile;

		calculate(saveToFile, a, n, h, b);
	}
	catch (const char* ex)  // ����� �������
	{
		cout << ex << endl;
		return -1;
	}
	catch (...) // ����� �������
	{
		cout << "Unknown err" << endl;
		return -2;
	}


}