/*
stl - ���������� ����������� ��������. �� ����, ��� ����� ������� ��� ����� ������������ �����.

vector - ��������� ���������� stl. �� ����, ��� "�����" ������������ ������. 

lower_bound - �������, ������� �� ��������������� ����� � ��������������� ������� ������� ����������
�������, ������� ������ ��������� �������� k ��� ����� ���. � �������� ���������� ��������� �������
������� � �������� k.

upper_bound - �������, ������� �� ��������������� ����� � ��������������� ������� ������� ����������
�������, ������� ������ ������ ��������� �������� k.

auto - �������� �����, ������������ ��� ��������������� ������ ���� ������ ������������. ��� 
��������� ������������ �������� ������ �������� ���� ����������, ����� ��� ����� �������� � ������.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm> //��� reverse 

using namespace std;

int main() {
	//������� 1. ������ ������� �� �����

	ifstream file("input.txt");
	vector<int> v; //������������� ������
	string S; //����������� ����� �� ����� 

	while (getline(file, S, ' ')) v.push_back(atoi(S.c_str()));  //���������� � ������

	cout << "The vector is:" << endl;
	for (int i = 0; i < v.size(); i++) cout << v.at(i) << " "; //����� ������� �� �����

	//������� 2. ������������� ������������������ ��������� ������� 

	reverse(v.begin(), v.end());

	cout << endl << endl << "The reverse vector is:" << endl;
	for (int i = 0; i < v.size(); i++) cout << v.at(i) << " "; //����� ������� �� �����

	//������� 3. ����� ����������� ������� 

	int min_v = *min_element(begin(v), end(v));

	cout << endl << endl << "The min element is:" << endl; //����� �������� �� �����
	cout << min_v << endl;

	//������� 4. ������� ��� ������ ��������

	//����� ��������� �������� �������� ��������� �������

	v.erase(remove_if(v.begin(), v.end(), [](const int& x) {return x % 2 == 0; }), v.end());

	cout << endl << "The vector without even numbers:" << endl;
	for (int i = 0; i < v.size(); i++) cout << v.at(i) << " "; //����� ������� �� �����

	//������� 5. ������������� ������ � ���������/������������ ������������������

	sort(v.begin(), v.end(), greater<int>()); //���������� � ��������� ������������������

	cout << endl << endl << "The vector sorted in descending order:" << endl;
	for (int i = 0; i < v.size(); i++) cout << v.at(i) << " "; //����� ������� �� �����

	sort(v.begin(), v.end()); //���������� � ������������ ������������������

	cout << endl << endl << "The vector sorted in ascending order:" << endl;
	for (int i = 0; i < v.size(); i++) cout << v.at(i) << " "; //����� ������� �� �����

	//������� 6. �������� � ������ ������������ �������, �� ������� ����������

	int num = 32; //����� ��� �������
	auto it = lower_bound(v.begin(), v.end(), num);
	v.insert(it, num);

	cout << endl << endl << "The vector with adding element:" << endl;
	for (int i = 0; i < v.size(); i++) cout << v.at(i) << " "; //����� ������� �� �����

	//������� 7. ���������� ������ ��������� ��������

	//����� ������ ������� 32
	
	//������ ����������: � ������, ���� ��������� ���������, ������� find ������ ������ ������� 
	//������ ���������� ��������
	auto n = find(v.begin(), v.end(), num);

	cout << endl << endl << "The index of element " << num << " is:";
	cout << endl << n - v.begin();

	//������� 8. ������� �� ������� ������������� ��������

	//erase �������� ������ � ��������������� ��������!!!
	v.erase(unique(v.begin(), v.end()), v.end());

	cout << endl << endl << "The new vector:" << endl;
	for (int i = 0; i < v.size(); i++) cout << v.at(i) << " "; //����� ������� �� �����

}