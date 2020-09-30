#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <iomanip>



using namespace std;



bool checking_data(double M_PI, double l_border, double r_border)
{
	if (l_border >= 0 && r_border > l_border && M_PI > r_border)
	{
		return true;
	}
	else
	{
		system("cls");
		cout << "Веденные данные некорректны, повторите ввод:" << endl;
		return false;
	}
};

double func(double x)
{
	return sin(x);
};

double Simpsons_method(stringstream A[25], int temp, double l_border, double r_border)
{ 
	const double height = abs(r_border - l_border) / temp;
	double odd_indexes = 0, even_indexes = 0;
	for (int i = 1; i < temp; i += 2)
	{
		odd_indexes += func(l_border + i * height);
		even_indexes += func(l_border + (i + 1) * height);
	}
	return height / 3 * (func(l_border) + 4 * odd_indexes + 2 * even_indexes);			
};

double medium_rect_method(stringstream A[25], int a, double l_border, double r_border)
{
	double coord;
	double length_of_one_section, half_length, square_sum=0, square, temp;
		length_of_one_section = (r_border - l_border) / a;
		half_length = length_of_one_section / 2;
		coord = l_border + half_length;
		square =abs(sin(coord))*length_of_one_section;
		for (int i = 0; i <= a; i++)
		{
			square_sum += square;
			coord += length_of_one_section;
			square = abs(sin(coord)) * length_of_one_section;
		}
		return square_sum;
	
};


void output_data(stringstream A[25], int a[6], double l_border, double r_border, int i)
{
	A[0] << left << fixed << setprecision(5) << setw(10) << a[i] << setw(10) << medium_rect_method(A, a[i], l_border, r_border) << setw(10) << Simpsons_method(A, a[i], l_border, r_border);
	cout << A->str() << endl;
	A->str("");
};


int main()
{
	setlocale(LC_ALL, "rus");
	const double M_PI = 3.14159265358979323846;
	double l_border, r_border;
	int Breakdowns[6] = { 5, 10, 20, 100, 500, 1000 };
	stringstream Results[25];
	A:
	cout << "Введите левую границу, большую 0: ";
	cin >> l_border;
	cout << "Введите правую границу, которая будет менше значения 'Пи', и большую левой границы: ";
	cin >> r_border;
	if (checking_data(M_PI, l_border, r_border) == true)
		for (int i = 0; i < 6; i++)
		{
			output_data(Results, Breakdowns, l_border, r_border, i);
		}
	else goto A;
	return 0;
}

