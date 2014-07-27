#ifndef __CPP_STACK_H_
#define __CPP_STACK_H_
#include <stdint.h>
#include <iostream>
#include <stdexcept>

#define DEFAULT_STACKSIZE 10
using namespace std;

template<class T>
class Stack{
public:
	Stack<T>():base(NULL), top(NULL), stacksize(0), current(0),  step(0) {}

	Stack<T>(int size, int step_val):base(NULL), top(NULL), stacksize(0), current(0), step(0){
		base = new T[size];
		top = base;
		stacksize = size;
		step = step_val;
	}

	T GetTop()const;

	Stack<T>& Pop(T &);

	Stack<T>& Push(T const &val);

	void Print()const;

	bool empty() const;

	Stack<T>& operator= (Stack<T> const&);

	uint32_t size() const;

	Stack<T>& copy(Stack<T> const&);

	T operator[] (uint32_t) const;
	
	Stack<T>& operator()(void *begin, void *end);

	~Stack<T>(){
		delete [] base;
		base = NULL;
		top = NULL;
		stacksize = 0;
		step = 0;
	}
private:
	T *base;
	T *top;
	uint32_t stacksize;
	uint32_t current;
	uint32_t  step;
};

template<class T>
T Stack<T>::GetTop()const
{
	T *ptr;
	ptr = top;
	ptr--;
	return *ptr;
}

template<class T>
Stack<T>& Stack<T>::Push(T const &val)
{
	T *tmp = NULL;
	T *ptr = NULL;
	T *base_ptr = NULL;
	if(top - base >= stacksize){
		stacksize += step;
		tmp = new T[stacksize];
		ptr = tmp;
		base_ptr = base;
		while(base_ptr != top){
			*ptr = *base_ptr;
			base_ptr++;
			ptr++;
		}
		delete [] base;
		base = tmp;
		top = ptr;
	}
		
	if(top == base)	{
		*base = val;
		top++;
	}else{
		*top = val;
		top++;
	}
	current++;
	return *this;
}

template<class T>
Stack<T>& Stack<T>::Pop(T &x)
{
	if(empty()) {
		throw std::out_of_range("Stack<>::Pop(): empty stack");
	}
	--top;
	x = *top;
	current--;
	
	return *this;
}

template<class T>
void Stack<T>::Print()const
{
	T *ptr;

	ptr = base;

	while(ptr != top) {
		cout <<" " <<*ptr << " ";
		ptr++;
	}	

	cout << endl;
}

template<class T>
bool Stack<T>::empty() const
{
	return base == top;
}

template<class T>
uint32_t Stack<T>::size()const
{
	return current;
}

template<class T>
Stack<T>& Stack<T>::operator= (Stack<T> const&x)
{
	cout << "call this!" << endl;
	base = new T[x.stacksize];
	current = 0;
	T *ptr;

	ptr = x.base;

	while(ptr != x.top) {
		base[current] = *ptr;	
		ptr++;
		current++;
	}	

	top = base + x.current;
	stacksize = x.stacksize;
	step = x.step;
	
	return *this;
}

template<class T>
Stack<T>& Stack<T>::copy(Stack<T> const& x)
{
	cout << "call copy fun" << endl;
	*this = x;
	return *this;
}

template<class T>
T Stack<T>::operator[](uint32_t index)const
{
	if (index > current) {
		throw std::out_of_range("Stack<>::[index]: out of range");
	}
	return base[index];
}
#if 0
template<class T>
Stack<T>& Stack<T>::operator()(void *begin, void *end)
{
	assert(NULL != begin);
	assert(NULL != end);
	assert(begin >= end);
	
	if (begin == end) {
		
	}
}
#endif
#endif
