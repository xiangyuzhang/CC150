#include <string>
#include <algorithm>
#include <iostream>
#include <memory>

#include "ArrayList.h"
ArrayList::ArrayList()		// 最初的Arraylist是一个size = 0的数组
{
	beg_ptr = new std::string[0];
	end_ptr = beg_ptr;
	cap_ptr = beg_ptr;
}


ArrayList::ArrayList(const ArrayList & old)
{
	std::cout << "call copy constructor" << std::endl;
	beg_ptr = new std::string[old.size()];
	for(unsigned int i = 0; i != old.size(); ++i)
		*(beg_ptr+i) = *(old.beg_ptr + i);
	end_ptr = beg_ptr + old.size();
	cap_ptr = beg_ptr + old.capacity();

}

ArrayList::ArrayList(ArrayList && old) noexcept
{
	std::cout << "call move constructor" << std::endl;
	beg_ptr = new std::string[old.size()];
	for(unsigned int i = 0; i != old.size(); ++i)
		*(beg_ptr+i) = *(old.beg_ptr + i);
	end_ptr = beg_ptr + old.size();
	cap_ptr = beg_ptr + old.capacity();
	old.beg_ptr = nullptr;
	old.end_ptr = nullptr;
	old.cap_ptr = nullptr;
}

void ArrayList::swap(ArrayList & lhs, ArrayList & rhs)
{
	std::cout << "call swap" << std::endl;
	std::swap(lhs.beg_ptr, rhs.beg_ptr);
	std::swap(lhs.end_ptr, rhs.end_ptr);
	std::swap(lhs.cap_ptr, rhs.cap_ptr);
}

ArrayList & ArrayList::operator=(ArrayList old)
{
	std::cout << "call operator=" << std::endl;
	swap(old, *this);
	return *this;
}

/*
ArrayList & ArrayList::operator=(const ArrayList &old)
{
	std::cout << "call operator=" << std::endl;
	if(this != &old)
	{
		free();
		beg_ptr = new std::string[old.size()];
		for(unsigned int i = 0; i != old.size(); ++i)
			*(beg_ptr+i) = *(old.beg_ptr + i);
		end_ptr = beg_ptr + old.size();
		cap_ptr = beg_ptr + old.capacity();
	}

}
*/
ArrayList::~ArrayList() {free();}


void ArrayList::push_back(const std::string & item)
{
	// ask for current size + 1 
	reserve(size() + 1);	
	// do construction in the current end pointer and move back
	*(end_ptr++) = item;	
}

void ArrayList::erase(const unsigned int& index)
{
	// 其实就是将后面的元素覆盖到前面，然后移动end
	for(auto start = begin() + index + 1; start != end(); ++start)		// 所以start永远不会是end(),
		move_forward(start);
	--end_ptr;
}

void ArrayList::reserve(const unsigned int & cap) 
{
	// 如果需要的cap大于等于目前的容量，则加倍赋予
	if(cap >= capacity())
		reallocate(2*cap);
}

std::string ArrayList::pop_back()
{
	if(!empty())
	{
		auto dum = back();
		move_forward(end_ptr);
		return dum;
	}
	else
	{
		std::cerr << "pop_back: container is already empty" << std::endl;
	}
}

bool ArrayList::empty() const 
{
	if (begin() == end()) return true;
	else return false;
}
std::string & ArrayList::back() const
{
	if(!empty()) return *(end() - 1);
	else std::cerr << "back: container is empty" << std::endl;
}

std::string & ArrayList::front() const
{
	if(!empty()) return *begin();
	else std::cerr << "front: container is empty" << std::endl;
}
void ArrayList::move_forward(std::string * pos){*(pos - 1) = *pos;}
void ArrayList::free(){delete [] beg_ptr;}




void ArrayList::reallocate(const unsigned int & cap)
{
	auto new_beg = new std::string[cap];
	auto new_end = new_beg;
	auto pos = beg_ptr;
	for(unsigned int i = 0; i != size(); ++i)
		*(new_end++) = *(pos++);
	free();
	beg_ptr = new_beg;
	end_ptr = new_end;
	cap_ptr = new_beg + cap;
}

const unsigned int ArrayList::size() const {return end_ptr - beg_ptr;}
const unsigned int ArrayList::capacity() const {return cap_ptr - beg_ptr;}


std::string * ArrayList::begin() const {return beg_ptr;}
std::string * ArrayList::end() const {return end_ptr;}