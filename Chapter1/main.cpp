#include <iostream>
#include <string>
#include "ArrayList.h"

using namespace std;
int main()
{
	ArrayList Arr;
	cout << "Test begin" << endl;
	cout << "capacity is:" << Arr.capacity() << endl;
	cout << "size is: " << Arr.size() << endl;
	
//	print_all(Arr);
	Arr.push_back("Hello1,");
	Arr.push_back("Hello2,");
	Arr.push_back("Hello3,");
	Arr.push_back("Hello4,");
	Arr.push_back("Hello5,");
	Arr.push_back("Hello6,");
	Arr.push_back("Hello7,");
	Arr.push_back("Hello8,");

	cout << "Test result" << endl;
	cout << "capacity is:" << Arr.capacity() << endl;
	cout << "size is: " << Arr.size() << endl;
	print_all(Arr);

	ArrayList new_Arr;
	new_Arr = move(Arr);
	cout << "The following is new_Arr" << endl;
	print_all(new_Arr);

	new_Arr.erase(5);
	print_all(new_Arr);
	cout << "Test pop_back" << endl;
//	print_all(new_Arr);
	cout << "capacity is:" << new_Arr.capacity() << endl;
	cout << "size is: " << new_Arr.size() << endl;
	cout << "back is:" << new_Arr.pop_back() << endl;
	print_all(new_Arr);
	cout << "front is " << new_Arr.front() << endl;
	new_Arr.insert(5, "good");
	print_all(new_Arr);

	ArrayList ater_Arr;
	ater_Arr.insert(0,"test");
	print_all(ater_Arr);
	ater_Arr.resize(10);
	ater_Arr.clear();
	cout << "capacity is:" << ater_Arr.capacity() << endl;
	cout << "size is: " << ater_Arr.size() << endl;
	return 0;
}