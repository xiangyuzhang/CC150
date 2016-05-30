#ifndef CC150_3_5_H
#define CC150_3_5_H
#include "stack.h"
#include <string>
#include <iostream>


template <typename T>
class tower: public Stack<T>
{
public:
	tower() = default;
	tower(std::string i): name(i){}

	std::string name;
};

template <typename T>
void moveTop(tower<T> &original, tower<T> &dest)
{
	auto temp = original.top();
	dest.push(temp);
	original.pop();
}
template <typename T>
void Hanoi(unsigned n, tower<T> & original, tower<T> &dest, tower<T> &buffer) // 数量为n的盘子需要从original 利用buffer，移动到dest
{
	std::cerr << "moving: " << n << " from " << original.name << " to " << dest.name << " using " << buffer.name <<std::endl;
	if(n > 0)
	{
		Hanoi(n - 1, original, buffer, dest);
		moveTop(original, dest);
		Hanoi(n - 1, buffer, dest, original);
	}
}



#endif