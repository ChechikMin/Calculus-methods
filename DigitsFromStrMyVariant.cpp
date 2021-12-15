#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include<iterator>
using namespace std;




int main()
{

	vector <double> my_vector;

	my_vector = { 1.2, 50.22, 458.265956 };

	vector <double> ::iterator it = my_vector.begin();// это итератор "аля указатель, лучше пользоваться им"

	for (auto &i : my_vector)//
		cout << i << "\n";// так выводяться данные вектора 

	size_t size_vec = my_vector.size();//размер вектора

	string str = "1151 1551";//твоя строка из чисел тебе надо перевести в числа их и сложить

	vector<double> digits;

	string tmp = "";

	for  (string::iterator it = str.begin(); it != str.end(); it++)
	{

		if (isdigit(*it)) 
			tmp += *it;
		else{
			digits.push_back(stoi(tmp));
			tmp = "";}
	}
	digits.push_back(stoi(tmp));

	for (auto &i : digits)//тут уже число не строка
		cout << i << "\n";
	

	return 0;
}
