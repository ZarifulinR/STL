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
	{1," ������ ������������"},
	{2," �������� � ����������� �����"},
	{3," ����������� c�������"},
	{4," ���������� ��������"},
	{5," ���������� ���"},
	{6," ���������� ����� ���������� �����������"},
	{7," ���������� ���������"},
	{8," ������ �� �������"},
	{9," ����� �� ��������� ������"},
	{10,"����� �� ����������� "},
	{11,"���� � ��������� ��������� "},
	{12,"����������� ������� "},
	{13,"�������� ��������� � ����������� ���������� "},
	{14,"��������� �� ����������� ����� "},
	{15,"���������� ������������ �������� �� ��� "},
	{16,"��������� ������� ��� ���������� "},
};
class Crime
{
	std::string licence_plate;
	int id;
	std::string place;
	std::string time;
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
	const std::string& get_time()const
	{
		return time;
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
	void set_tima(const std::string& time)
	{
		this->time = time;
	}
	/////////   Constructors
	Crime(int violation_id, const std::string& place, const std::string time)
	{
		
		set_violation_id(violation_id);
		set_place(place);
		set_tima(time);

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
void main()
{
	




	setlocale(LC_ALL, "");
	/*Crime crime(1, "��. ������ ", "18:10 1.09.2024");
	cout << crime << endl;*/
	std::map<std::string, std::list<Crime>> base =
	{
		{"a777bb", {Crime(1, "��.������", "18:10 1.09.2024"), Crime(2,"��.�������", "12:25 20.08.2024")}},
		{"a000bb", {Crime(6, "��.�����������", "17:50 1.08.2024"), Crime(8,"��.�����������", "17:45 01.08.2024")}},
		{"a001��", {Crime(10, "��.������������", "21:50 1.08.2024"), Crime(9,"��.������������", "21:50 1.08.2024"), Crime(11,"��.������������", "21:50 1.08.2024"), Crime(12,"��.������������", "22:05 1.08.2024")}},
	};
	
	/*for
		(
			std::map<std::string, std::list<Crime>>::iterator map_it=base.begin();
			map_it !=base.end();++map_it
		)
	{
			cout<<map_it->first<<"\n";
			for (std::list<Crime>::iterator it = map_it->second.begin(); it != map_it->second.end(); ++it)
			{
				cout << "\t" << *it << endl;
			}
			cout << delimiter << endl;
	}*/

	std::string myfile = "policebase.txt";
	std::ofstream mypolicefile ;
	mypolicefile.open(myfile,std::ofstream::app);
#ifdef whrite_file
	if (!mypolicefile.is_open())
	{
		cout << "������ �������� �����! " << endl;
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
		cout << "������ �������� ������:!" << endl;
	}
	else
	{
		cout << "���� ������:!" << endl;
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
		cout << "������ �������� �����:!" << endl;
	}
	else
	{
		cout << "���� ������:! " << endl;
		char str[100];
		while (!fin.eof())
		{

			fin.getline(str, 100);
			cout << str << endl;
		}
	}
	fin.close();
#endif // reed_2

}