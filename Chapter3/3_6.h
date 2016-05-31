#ifndef CC150_3_5_H
#define CC150_3_5_H
#include "stack.h"
#include <iostream>

template <typename T>
void moveTop(Stack<T> &from, Stack<T> &to)
{
	auto temp = from.top();
	to.push(temp);
	from.pop();

}

template <typename T>
Stack<T> sort(Stack<T> & orig)
{
	unsigned counter = 0;
	Stack<T> result;
	while(!orig.empty())
	{
		std::cerr << "sort: " << orig.top() << std::endl;
		auto temp = orig.top();
		orig.pop();
		while(temp <= result.top())
		{
			std::cerr << temp << " is smaller then " << result.top() << " so need to move top" <<std::endl;
			moveTop(result, orig);
			std::cerr << "after moving " << std::endl;
			std::cerr << "orig:   "; orig.show_all();
			std::cerr << "result: "; result.show_all();
			++counter;
		}
		result.push(temp);
		while(counter != 0)
		{
			moveTop(orig, result);
			--counter;
		}
		std::cerr << "====result for this iteration====" << std::endl;
		std::cerr << "orig:   "; orig.show_all();
		std::cerr << "result: "; result.show_all();
		std::cerr << "=================================" << std::endl;
	}


	return result;
}
#endif