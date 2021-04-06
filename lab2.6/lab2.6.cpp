// Варіант 23
#include <iostream>
#include<iomanip>
#include <locale>
#include "windows.h"
#include "SolutionC.h"
using namespace std;
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	SolutionC s1;
		cout << "SolutionC : " << SolutionC::getCounter() << endl;
	cout << "SolutionC::Liquid : " << SolutionC::Liquid::getCounter() << endl;
	SolutionC::Liquid m1;
	cout << "SolutionC::Liquid +1 : " << SolutionC::Liquid::getCounter() << endl;
	{
		SolutionC s4("Цукровий");
		cout << "SolutionC local : " << SolutionC::getCounter() << endl;
		cout << "SolutionC::Liquid local : " << SolutionC::Liquid::getCounter() << endl;
		SolutionC::Liquid m1("Сірчастий", 5);
		cout << "SolutionC::Liquid local +1 : " << SolutionC::Liquid::getCounter() << endl;
	}
	cout << "SolutionC : " << SolutionC::getCounter() << endl;
	cout << "SolutionC::Liquid : " << SolutionC::Liquid::getCounter() << endl;
	return 0;
}