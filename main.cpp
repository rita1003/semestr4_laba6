/*
stl - библиотека стандартных шаблонов. По сути, это набор решений для часто используемых задач.

vector - контейнер библиотеки stl. По сути, это "умный" динамический массив. 

lower_bound - функция, которая за логарифмическое время в отсортированном массиве находит наименьший
элемент, который больше заданного значения k или равен ему. В качестве аргументов принимает границы
массива и значение k.

upper_bound - функция, которая за логарифмическое время в отсортированном массиве находит наименьший
элемент, который строго больше заданного значения k.

auto - ключевое слово, используется для автоматического вывода типа данных компилятором. Это 
позволяет программисту избежать явного указания типа переменной, делая код более читаемым и гибким.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm> //для reverse 

using namespace std;

int main() {
	//задание 1. чтение фектора из файла

	ifstream file("input.txt");
	vector<int> v; //целочисленный вектор
	string S; //считываемое число из файла 

	while (getline(file, S, ' ')) v.push_back(atoi(S.c_str()));  //считывание в вектор

	cout << "The vector is:" << endl;
	for (int i = 0; i < v.size(); i++) cout << v.at(i) << " "; //вывод вектора на экран

	//задание 2. реверсировать последовательность элементов вектора 

	reverse(v.begin(), v.end());

	cout << endl << endl << "The reverse vector is:" << endl;
	for (int i = 0; i < v.size(); i++) cout << v.at(i) << " "; //вывод вектора на экран

	//задание 3. найти минимальный элемент 

	int min_v = *min_element(begin(v), end(v));

	cout << endl << endl << "The min element is:" << endl; //вывод элемента на экран
	cout << min_v << endl;

	//задание 4. удалить все чётные элементы

	//будем применять условное удаление элементов вектора

	v.erase(remove_if(v.begin(), v.end(), [](const int& x) {return x % 2 == 0; }), v.end());

	cout << endl << "The vector without even numbers:" << endl;
	for (int i = 0; i < v.size(); i++) cout << v.at(i) << " "; //вывод вектора на экран

	//задание 5. отсортировать вектор в убывающей/возрастающей последовательности

	sort(v.begin(), v.end(), greater<int>()); //сортировка в убывающей последовательности

	cout << endl << endl << "The vector sorted in descending order:" << endl;
	for (int i = 0; i < v.size(); i++) cout << v.at(i) << " "; //вывод вектора на экран

	sort(v.begin(), v.end()); //сортировка в возрастающей последовательности

	cout << endl << endl << "The vector sorted in ascending order:" << endl;
	for (int i = 0; i < v.size(); i++) cout << v.at(i) << " "; //вывод вектора на экран

	//задание 6. вставить в вектор произвольный элемент, не нарушая сортировку

	int num = 32; //число для вставки
	auto it = lower_bound(v.begin(), v.end(), num);
	v.insert(it, num);

	cout << endl << endl << "The vector with adding element:" << endl;
	for (int i = 0; i < v.size(); i++) cout << v.at(i) << " "; //вывод вектора на экран

	//задание 7. определить индекс заданного элемента

	//будем искать элемент 32
	
	//личное наблюдение: в случае, если элементов несколько, функция find выдает индекс первого 
	//такого найденного элемента
	auto n = find(v.begin(), v.end(), num);

	cout << endl << endl << "The index of element " << num << " is:";
	cout << endl << n - v.begin();

	//задание 8. удалить из вектора дублированные элементы

	//erase работает только с отсортированным массивом!!!
	v.erase(unique(v.begin(), v.end()), v.end());

	cout << endl << endl << "The new vector:" << endl;
	for (int i = 0; i < v.size(); i++) cout << v.at(i) << " "; //вывод вектора на экран

}