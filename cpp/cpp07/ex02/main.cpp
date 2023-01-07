#include <iostream>
#include <cstdlib>
#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
    {
		Array<int> empty;
		Array<int> numbers(MAX_VAL);
		int* mirror = new int[MAX_VAL]();
		for (int i = 0; i < MAX_VAL; i++)
		{
			if (mirror[i] != numbers[i])
			{
				std::cerr << mirror[i] << std::endl;
				std::cerr << numbers[i] << std::endl;
				std::cerr << "didn't initialise the same value!!" << std::endl;
				return 1;
			}
		}
		srand(time(NULL));
		for (int i = 0; i < MAX_VAL; i++)
		{
			const int value = rand();
			numbers[i] = value;
			mirror[i] = value;
		}
		//SCOPE
		{
			Array<int> tmp = numbers;
			Array<int> test(tmp);
		}

		for (int i = 0; i < MAX_VAL; i++)
		{
			if (mirror[i] != numbers[i])
			{
				std::cerr << mirror[i] << std::endl;
				std::cerr << numbers[i] << std::endl;
				std::cerr << "didn't save the same value!!" << std::endl;
				return 1;
			}
		}
		try
		{
			std::cout << numbers[0] << ", ";
			std::cout << mirror[0] << std::endl; 
			std::cout << numbers[10] << ", ";
			std::cout << mirror[10] << std::endl; 
			numbers[-2] = 0;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			numbers[MAX_VAL] = 0;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		for (int i = 0; i < MAX_VAL; i++)
		{
			numbers[i] = rand();
		}
		delete [] mirror;
	}
	{
		Array<double> empty;
		Array<double> numbers(MAX_VAL);
		double* mirror = new double[MAX_VAL]();
		for (int i = 0; i < MAX_VAL; i++)
		{
			if (mirror[i] != numbers[i])
			{
				std::cerr << mirror[i] << std::endl;
				std::cerr << numbers[i] << std::endl;
				std::cerr << "didn't initialise the same value!!" << std::endl;
				return 1;
			}
		}
		srand(time(NULL));
		for (int i = 0; i < MAX_VAL; i++)
		{
			const int value = rand();
			numbers[i] = value;
			mirror[i] = value;
		}
		//SCOPE
		{
			Array<double> tmp = numbers;
			Array<double> test(tmp);
		}

		for (int i = 0; i < MAX_VAL; i++)
		{
			if (mirror[i] != numbers[i])
			{
				std::cerr << mirror[i] << std::endl;
				std::cerr << numbers[i] << std::endl;
				std::cerr << "didn't save the same value!!" << std::endl;
				return 1;
			}
		}
		try
		{
			std::cout << numbers[0] << ", ";
			std::cout << mirror[0] << std::endl; 
			std::cout << numbers[10] << ", ";
			std::cout << mirror[10] << std::endl; 
			numbers[-2] = 0;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			numbers[MAX_VAL] = 0;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		for (int i = 0; i < MAX_VAL; i++)
		{
			numbers[i] = rand();
		}
		delete [] mirror;
	}
    return 0;
}
