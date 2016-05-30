#include <iostream>
#include <string>
#include "queue.h"
//#include "stack.h"
#include "answers.h"
using namespace std;

int main()
{
	Stack<int> first;
	Stack<int> second;
	Stack<int> third;

	first.push(3);
	first.push(2);
	first.push(1);


	Hanoi(first,second,third);


	return 0;
}