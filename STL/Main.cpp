#include <iostream>
#include <array>
#include<vector>
#include<list>
#include <iterator>

using std::cin;
using std::cout;
using std::endl;
#define tab "\t"
#define delimeter "\n----------------------- \n"
//#define STL_VECTOR
//#define STL_ARRAY
//#define STL_VEC

template <typename T>void vector_info(const std::vector<T>& vec)
{
	cout << "size : " << vec.size() << endl;
	cout << "Capacity : " << vec.capacity() << endl;
	cout << "MaxSize : " << vec.max_size() << endl;
}
void main()
{
	setlocale(LC_ALL, "RUS");
	//cout << " Hello STL";
#ifdef STL_ARRAY

	const int N = 5;
	std::array<int, N>  arr = {3,5,8,13,21};
	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl;
#endif  STL_ARRAY



#ifdef STL_VECTOR
	std::vector<int> vec = { 0,1,1,2,3,5,8,13,21,34 };
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i]; cout << tab;

	}
	cout << endl;
	vector_info(vec);
	vec.push_back(55);
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec.at(i) << tab;
	}
	cout << endl;
	//vec.reserve(20);
	vec.shrink_to_fit(); ///”резает вместительность до фактического размера(size)
	//это можно сделать в цел€х экономии пам€ти это можно сделать если мы уверены что в вектор 
	// больше не будет ничего добавл€тьс€.
	vec.resize(8); //«адает фактический размер вектора .
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
	{
		cout << *it << tab;
	}
	cout << endl;

	vector_info(vec);
	for (int i : vec)cout << i << tab;  cout << endl;
	vec.insert(vec.begin() + 4, { 1024,2048,3072,4096 });
	for (int i : vec)cout << i << tab; cout << endl;

	int index;
	int count;
	int value;
	cout << "¬ведите индекс добавл€емого элемента:"; cin >> index;
	cout << "¬ведите колличество добавл€емых элементов:"; cin >> count;
	cout << "¬ведите значение добавл€емого элемента:"; cin >> value;
	vec.insert(vec.begin() + index, count, value);

	for (int i : vec)cout << i << tab; cout << endl;
	vector_info(vec);
	cout << "¬ведите индекс удал€емого элемента:"; cin >> index;
	cout << "¬ведите колличество удал€емого элементов:"; cin >> count;
	vec.erase(vec.begin() + index, vec.begin() + index + count);

	for (int i : vec)cout << i << tab; cout << endl;
	vector_info(vec);
#endif // STL_VECTOR
	std::list<int>list = { 3,5,8,13,21 };
	for (std::list<int>::iterator it = list.begin(); it != list.end(); it++)
		cout << *it << tab;
	cout << endl;

		list.push_front(2);
		list.push_back(3);
		int index;
		int value;
		cout << "¬ведите индекс добавл€уього элемента: "; cin >> index;
		cout << "¬ведите значение добавл€уього элемента: "; cin >> value;
		std::list<int>::iterator position = list.begin();
		//for (int i = 0; i < index; i++)position++;
		std::advance(position, value);
		list.insert(position, value);
		for (int i : list)cout << i << tab; cout << endl;

}