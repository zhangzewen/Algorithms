#include <iostream>
#include <string.h>
#include "Stack.h"

using namespace std;
using std::cout;
using std::cin;

int Stack::GetTop()const
{
	int *ptr;
	ptr = top;
	ptr--;
	return *ptr;
}


Stack& Stack::Push(int val)
{
	int *tmp = NULL;
	int *ptr = NULL;
	int *base_ptr = NULL;
	if(top - base >= stacksize){
		stacksize += step;
		tmp = new int[stacksize];
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

Stack& Stack::Pop()
{
	if(top == base) {
		cout << endl <<"no elements" << endl;
		return *this;
	}
	--top;
	cout << endl << *top << endl;
	current--;
	
	return *this;
}

void Stack::Print()const
{
	int *ptr;

	ptr = base;

	while(ptr != top) {
		cout <<" " <<*ptr << " ";
		ptr++;
	}	

	cout << endl;

}

bool Stack::empty() const
{
	return base == top;
}

int Stack::size()const
{
	return current;
}

Stack& Stack::operator= (Stack const&x)
{
	cout << "call this!" << endl;
	base = new int[x.stacksize];
	current = 0;
	int *ptr;

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

Stack& Stack::copy(Stack const& x)
{
	cout << "call copy fun" << endl;
	*this = x;
	return *this;
}
