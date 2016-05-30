#ifndef CC150_CHAPTER3_ANSWER_H
#define CC150_CHAPTER3_ANSWER_H

#include <iostream>
//#include "queue.h"
#include "stack.h"



//=======================================================================
//3_3
template <typename T>
class SetOFStacks  // 假设：每一个stack只能存放3个元素，这个本身就是一个stack
{
public:
	SetOFStacks():cap(0),pos(1),current_size(0),num_stack(0){}

	void push(const T& value)
	{
		if(pos > cap)
		{
			std::cerr << "create new stack" << std::endl;
			Stack<T> *new_stack = new Stack<T>;
			main_stack.push(new_stack);
			std::cerr << "here" << std::endl;

			main_stack.top()->push(value);

			current_size = 1;
			++pos;
			++num_stack;
			cap+=3;
		}
		else
		{
			std::cerr << "use existed stack" << std::endl;
			main_stack.top()->push(value);
			++current_size;
			++pos;
		}
	}

	void pop()
	{
		if(!empty())
		{
			if(current_size != 0)
			{
				main_stack.top()->pop();
				--current_size;
				--pos;
			}
			else
			{
				main_stack.pop();
				cap-=3;
				--num_stack;
				main_stack.top()->pop();
				--pos;
				current_size = 2;
			}
		}			
	}

	bool empty() const 
	{
		if(cap == 0) return true;
		else return false;
	}


	void show_all()
	{
		while(!main_stack.empty())
		{
			main_stack.top()->show_all();
			main_stack.pop();
		}
	}


private:
	unsigned cap;   	// 记录现在的最大容量
	unsigned pos;		// 记录当前top的位置
	unsigned current_size;	// 记录当前这个stack存放的容量
	unsigned num_stack;		// number of stack
	Stack<Stack<T>*> main_stack;
};


//=======================================================================
//3_4

template <typename T>
void move_to_stack(Stack<T> &one, Stack<T> &ano)
{
	ano.push(one.top());
	one.pop();
}
template <typename T>
void Hanoi(Stack<T> &first, Stack<T> &second, Stack<T> &third)
{
	std::cout << "first: " ;
	first.show_all();
	std::cout << "second:" ;
	second.show_all();
	std::cout << "third: " ;
	third.show_all();

	move_to_stack(first, third);
	move_to_stack(first, second);
	move_to_stack(third, second);
	move_to_stack(first, third);
	move_to_stack(second, first);
	move_to_stack(second, third);
	move_to_stack(first, third);

	std::cout << "first: " ;
	first.show_all();
	std::cout << "second:" ;
	second.show_all();
	std::cout << "third: " ;
	third.show_all();
}
#endif 