#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void input_data()
{
    double l_border, r_border;
    printf( "Enter left border, greater than or equal to 0: ");
    scanf("%lf", &l_border);
    printf("Enter a right border, that is less than Pi value and greater than left border: ");
    scanf("%lf", &r_border);
    validation(l_border, r_border);
};

void validation(double l_border, double r_border)
{
    int Breakdowns[6] = {6, 10, 20, 100, 500, 1000};
    if(l_border >= 0 && r_border > l_border && M_PI > r_border)
    {
        for(int i = 0; i < 6; i++)
        {
            output_data(Breakdowns[i], l_border, r_border);
        }
    }
    else
    {
        system("cls");
        printf( "The entered data is incorrect. Please re-enter:\n" );
        input_data();
    }
};

double medium_rect_method(int a, double l_border, double r_border)
{
    double height = (r_border - l_border) / a, result;
	double odd_indexes = 0, even_indexes = 0;
	for (int i = 1; i < a; i += 2)
	{
		odd_indexes += sin(l_border + i * height);
		even_indexes += sin(l_border + (i + 1) * height);
	}
   result = height / 3 * (sin(l_border) + 4 * odd_indexes + 2 * even_indexes);
    return result;
};

double Simpsons_method(int a, double l_border, double r_border)
{
	double coord, length_of_one_section, half_length, square_sum = 0, square, temp;
	length_of_one_section = (r_border - l_border) / a;
	half_length = length_of_one_section / 2;
	coord = l_border + half_length;
	square = abs(sin(coord)) * length_of_one_section;
	for (int i = 0; i <= a; i++)
	{
		square_sum += square;
		coord += length_of_one_section;
		square = sin(coord) * length_of_one_section;
	}

	return square_sum;
};


void output_data(int Breakdowns, double l_border, double r_border)
{
    printf("%6d%10.5lf%10.5lf\n", Breakdowns, medium_rect_method(Breakdowns, l_border, r_border), Simpsons_method(Breakdowns, l_border, r_border));
};


int main()
{
   input_data();
   return 0;
}
