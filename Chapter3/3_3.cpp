#include <iostream>
#include "answers.h"

using namespace std;

int main()
{
	SetOFStacks<int> test;
	test.push(1);
	test.push(2);
	test.push(3);
	test.push(4);
	test.push(5);
	test.push(6);
	test.pop();
	test.pop();
	test.pop();
	test.show_all();
	return 0;
}