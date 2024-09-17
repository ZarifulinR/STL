﻿#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<concrt.h>
#include<fstream>
#include<string>
#include<map>
#include<list>
#include<ctime>
using std::cin;
using std::cout;
using std::endl;
#define tab "\t"
#define delimiter "\n-------------------------------------------------------------------------------------------\n"
//#define reed_char
//#define reed_2
//#define whrite_file
const std::map<int, std::string> VIOLATION =
{
	{1," Ремень безопасности"},
	{2," Парковка в неположеном месте"},
	{3," Пересечение cплошной"},
	{4," Превышение скорости"},
	{5," Отсутствие ВУД"},
	{6," Отсутствие права управления автомобилем"},
	{7," Отсутствие страховки"},
	{8," Проезд на красный"},
	{9," Выезд на встречную полосу"},
	{10,"Дрифт на перекрестке "},
	{11,"Езда в нетрезвом состоянии "},
	{12,"Оскорбление офицера "},
	{13,"Внесение изменений в конструкцию автомобиля "},
	{14,"Перевозка не габаритного груза "},
	{15,"Превыщение максимальной нагрузки на ось "},
	{16,"Перевозка ребенка без автокресла "},
};
class Crime
{
	std::string licence_plate;
	int id;
	std::string place;
	tm time;
public:
	/*const std::string& get_licence_plate()const
	{
		return licence_plate;
	}*/
	int get_violation_id()const
	{
		return id;
	}
		
	const std::string& get_violation()const
	{
		return VIOLATION.at(id);
	}
	const std::string get_time()const
	{
		/*std::string result = asctime(&time);
		result.pop_back();
		return asctime(&time);*/
		const int SIZE = 256;
		char formatted[SIZE]{};
		strftime(formatted, SIZE, "%R,%e.%m.%Y", &time);
			return formatted;
	}
		
	const std::string& get_plase()const
	{
		return place;
	}
	/*void set_licence_plate(const std::string& licence_plate)
	{
		this->licence_plate = licence_plate;
	}*/
	void set_violation_id(int id)
	{
		this->id = id;
	}
	void set_place(const std::string& place)
	{
		this->place = place;
	}
	void set_time(const std::string& time)
	{
		char* time_bufer = new char[time.size() + 1]{};
		strcpy(time_bufer, time.c_str());
		int time_elements[5]{};
		int i = 0;
		char delimeters[] = ":./ ";
		for (char* pch = strtok(time_bufer, delimeters); pch; pch = strtok(NULL, delimeters))
			time_elements[i++] = std::atoi(pch);

		delete[] time_bufer;
		this->time.tm_hour = time_elements[0];
		this->time.tm_min = time_elements[1];
		this->time.tm_mday = time_elements[2];
		this->time.tm_mon = time_elements[3];
		this->time.tm_year = time_elements[4] - 1900;
		//this->time = time;
	}
	/////////   Constructors
	Crime(int violation_id, const std::string& place, const std::string time)
	{
		this->time = {};
		set_violation_id(violation_id);
		set_place(place);
		set_time(time);
		//cout << "Construktor:\t" << this << endl;
	}
	~Crime() 
	{ 
		//cout << "Construktor:\t" << this << endl; 
	}
};

std::ostream& operator<<(std::ostream& os, const Crime& obj)
{
	return os<< " :\t" << obj.get_time()<< " " << obj.get_plase()<<" - " << obj.get_violation();
}
void save(const std::map<std::string, std::list<Crime>>& base, const std::string filename)
{
	std::ofstream fout(filename);
	for
		(
			std::map<std::string, std::list<Crime>>::const_iterator map_it = base.begin();
			map_it != base.end(); ++map_it
			)
	{
		fout << map_it->first << "\n";
		for (std::list<Crime>::const_iterator it = map_it->second.begin(); it != map_it->second.end(); ++it)
		{
			fout << "\t" << *it << endl;
		}
		fout << delimiter << endl;
	}
	std::string command = "notepad " + filename;
	system(command.c_str());
}

void print(const std::map<std::string, std::list<Crime>>& base)
{
	for
		(
			std::map<std::string, std::list<Crime>>::const_iterator map_it = base.begin();
			map_it != base.end(); ++map_it
			)
	{
		cout << map_it->first << "\n";
		for (std::list<Crime>::const_iterator it = map_it->second.begin(); it != map_it->second.end(); ++it)
		{
			cout << "\t" << *it << endl;
		}
		cout << delimiter << endl;
	}

}
void main()
{
	setlocale(LC_ALL, "");
	/*Crime crime(1, "ул. Ленина ", "18:10 1.09.2024");
	cout << crime << endl;*/
	std::map<std::string, std::list<Crime>> base =
	{
		{"a777bb", {Crime(1, "ул.Ленина", "18:10 1.09.2024"), Crime(2,"пл.Свободы", "12:25 20.08.2024")}},
		{"a000bb", {Crime(6, "ул.Космонавтов", "17:50 1.08.2024"), Crime(8,"ул.Космонавтов", "17:45 01.08.2024")}},
		{"a001аа", {Crime(10, "ул.Пролетарская", "21:50 1.08.2024"), Crime(9,"ул.Пролетарская", "21:50 1.08.2024"), Crime(11,"ул.Пролетарская", "21:50 1.08.2024"), Crime(12,"ул.Пролетарская", "22:05 1.08.2024")}},
	};
	

	std::string myfile = "policebase.txt";
	std::ofstream mypolicefile ;
	mypolicefile.open(myfile,std::ofstream::app);
#ifdef whrite_file
	if (!mypolicefile.is_open())
	{
		cout << "Ошибка открытия файла! " << endl;
	}
	else
	{

		for
			(
				std::map<std::string, std::list<Crime>>::iterator map_it = base.begin();
				map_it != base.end(); ++map_it
				)
		{
			mypolicefile << map_it->first << "\n";
			for (std::list<Crime>::iterator it = map_it->second.begin(); it != map_it->second.end(); ++it)
			{
				mypolicefile << "\t" << *it << endl;
			}
			mypolicefile << delimiter << endl;

		}
	}
	mypolicefile.close();
#endif // whrite_file
	std::ifstream fin;
	fin.open(myfile);
#ifdef reed_char
	if (!fin.is_open())
	{
		cout << "Ошибка открытия файйла:!" << endl;
	}
	else
	{
		cout << "Файл открыт:!" << endl;
		char data;
		while (fin.get(data))
		{
			cout << data;
		}

	}
	fin.close();
#endif // reed_char

#ifdef reed_2
	if (!fin.is_open())
	{
		cout << "Ошибка открытия файла:!" << endl;
	}
	else
	{
		cout << "Файл открыт:! " << endl;
		char str[100];
		while (!fin.eof())
		{

			fin.getline(str, 100);
			cout << str << endl;
		}
	}
	fin.close();
#endif // reed_2
	print(base);
	save(base, "base.txt");
}