#ifndef CC150_ITERATOR_H
#define CC150_ITERATOR_H
template <typename T>class iter
{
public:
	iter();
	virtual ~iter();
	iter(const iter &);
	iter(iter &&) noexcept;
	//iter& operator=(iter<T>);
	virtual void swap(iter<T> &);

	virtual bool operator!=(const iter&);
	virtual bool operator==(const iter&);
	virtual bool operator++() = 0;
	virtual bool operator--() = 0;
	virtual bool operator++(int) = 0;
	virtual bool operator--(int) = 0;

private:
	T* pointer;
};

template <typename T>
iter<T>::iter():pointer(nullptr){}

template <typename T>
iter<T>::~iter(){delete pointer;}

template <typename T>
iter<T>::iter(const iter<T> & old):pointer(new T(*(old.pointer))){}

template <typename T>
iter<T>::iter(iter<T> && old) noexcept:pointer(new T(*(old.pointer))){pointer = nullptr;}

template <typename T>
void iter<T>::swap(iter<T> &rhs) {swap(this->pointer, rhs.pointer);}

template <typename T>
bool iter<T>::operator!=(const iter& rhs)
{
	if(pointer != rhs.pointer) return true;
	else return false;
}

template <typename T>
bool iter<T>::operator==(const iter& rhs)
{
	if(*this != rhs) return true;
	else return true;
}
#endif