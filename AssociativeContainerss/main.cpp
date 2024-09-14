#include <iostream>
#include <map>
#include <string>
#include<fstream>
#include <conio.h>
using namespace std;
using  std::cin;
using  std::cout;
using  std::endl;
#define tab '\t'
#define delimeter "\n-------------------------------------------\n"
//#define STL_MAP
/*
--------------------------
map,set,multimao,multiset
------------------------
*/
int main()
{
	setlocale(LC_ALL, "RUS");
#ifdef STL_MAP
	/*map-это контейнер каждый элемент которого хранит пару "ключ-значение"
	(pair<key,value>).Ключ и значение могут быть любых типов как одинаковых
	 так и разных.*/
	std::multimap<int, std::string>week
	{
		std::pair<int, std::string>(0, "Sunday"),
			std::pair<int, std::string>(1,"Monday"),
			std::pair<int, std::string>(2,"Tuesday"),
			std::pair<int, std::string>(3,"Wednesday"),


	};
	for (std::map<int, std::string>::iterator it = week.begin(); it != week.end(); ++it)
	{
		cout << it->first << tab << it->second << endl;
	}
#endif // STL_MAP
	
	string a, b;
	std::multimap<std::string, std::string>car
	{
		std::pair<std::string,std::string>()
	};

	int m=0 ;
	for (;;)
	{
		cout << " Выберите действие: "; cout << " \n";
		cout << "1) Внести нарушителя:  "; cout << " \n";
		cout << "3) Удалить нарушителя: "; cout << endl;
		cout << "2) Выход:"; cout << endl; cout << " \n";
		
		
		cin >> m;
		
		switch (m)
		{
		case 1:
			cout << "insert number of car: "; cin >> a; cout << endl;
			cout << "insert violation: "; cin >> b; cout << endl;

			car.insert({ a,b });
			for (std::multimap<std::string, std::string>::iterator it = car.begin(); it != car.end(); it++)
			{
				cout << it->first << tab << it->second << endl;
			}
			cout << endl;
			return 0;
			break;
		case 2:
			car.size();
			cout << car.size() << endl;


		default:
			
			cout << " error" << endl;
			cout<<delimeter;
			
			
			
		}
		_getch();
	}

	





}
