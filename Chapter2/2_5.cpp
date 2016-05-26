#include <iostream>
#include "forward_list.h"
using namespace std;

int main()
{
	forward_list<int> left;
	forward_list<int> right;
	forward_list<int> result;
	left.push_front(1);
	left.push_front(2);
	left.push_front(3);
	cout << "left = ";
	left.show_all();
	right.push_front(4);
	right.push_front(5);
	right.push_front(6);
	cout << "right = ";
	right.show_all();
	result = add_reverse(left, right);
	cout << "result = ";
	result.show_all();

	return 0;
}