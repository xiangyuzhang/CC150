#include <iostream>
#include "3_6.h"


int main()
{
	Stack<int> orig;
	orig.push(7);
	orig.push(10);
	orig.push(5);
	orig.push(12);
	orig.push(8);
	orig.push(3);
	orig.push(1);
	orig.push(9);
	orig.show_all();
	auto result = sort(orig);
	result.show_all();
	return 0;
}