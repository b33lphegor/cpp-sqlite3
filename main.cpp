#include <iostream>
#include "dbmanager.hpp"


void start();

int main(void)
{
	
	try
	{
		
	std::unique_ptr<DbManager> db(new DbManager);
	
	}
	catch(...)
	{
		std::cerr << "[!] Program Quitting." << std::endl;
	}

	start();
	
	return 0;
}
// Program Main
void startProgram()
{
	int i;
	for (i = 0; i < 50; i++)
	{
		std::cout << "=";
		int j;
		for (j = 0; j++ < i; j++)
		{
			std::cout << "\\";
		}
		std::cout << "\n";
	}
}
void start()
{
	int i;
	for (i = 0; i < 20; i++)
	{
		std::cout << "•";

		if (i / 2 == 10)
		{
			break;
			std::cout << "\t\tBook Store" << std::endl;
		}
		continue;

		int j;
		for (j = 0; j++ < i; j++)
		{
			std::cout << "•";
		}
		std::cout << std::endl;
	}
}
