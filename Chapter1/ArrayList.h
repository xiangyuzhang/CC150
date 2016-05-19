#ifndef CHAPTER1_ARRAY_LIST_H
#define	CHAPTER1_ARRAY_LIST_H
#include <string>
#include <algorithm>
#include <iostream>
#include <memory>


class ArrayList
{
	friend void print_all(const ArrayList&);
public:
	// member function
	ArrayList();							// 构造函数
	ArrayList(const ArrayList &);			// 复制构造函数：基于swap
	ArrayList(ArrayList &&) noexcept;		// 移动构造函数：基于swap
	void swap(ArrayList &, ArrayList &);	// 转换: 基于std::swap
	ArrayList & operator=(ArrayList old);		// 赋值构造函数：不区分参数是左值引用还是右值引用，因为首先要进行复制
//	ArrayList & operator=(const ArrayList &old);

	~ArrayList();							// 析构函数

	// element access
	std::string & at(const unsigned int) const;				
	std::string & operator[](const unsigned int) const ;
	std::string & front() const;
	std::string & back() const;

	// pointer access
	std::string *begin() const;
	std::string *end() const;

	// capacity
	bool empty() const;
	const unsigned int size() const;
	void resize(const unsigned int&);										// change size
	void reserve(const unsigned int&);									// change capacity
	const unsigned int capacity() const;

	// modifier
	void clear();
	void erase(const unsigned int&);
	void push_back(const std::string &);
	std::string * insert(std::string*, const std::string &);		// the position of newly inserted element = (pos, value)
	std::string pop_back();
private:
	void reallocate(const unsigned int &);			// if the desired size is smaller then current, then do nothing, else double space
	void move_forward(std::string *);
	void free();									// 安全删除

	std::string *beg_ptr;		// begin of the current string list
	std::string *end_ptr;		// end + 1 of the current string list
	std::string *cap_ptr;		// end of the whole memory space 
};

inline void print_all(const ArrayList& obj)
{
	for(unsigned int i = 0; i != obj.capacity(); ++i)
		std::cout << *(obj.beg_ptr + i) << std::endl;
}

#endif