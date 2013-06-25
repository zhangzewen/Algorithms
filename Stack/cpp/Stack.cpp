#include <iostream>
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
	if(top - base >= stacksize){
		stacksize =+ step;
		tmp = new int[stacksize];
		ptr = tmp;
		while(base != top){
			*ptr = *base;
			base++;
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
	return *this;
}

Stack& Stack::Pop(int *val)
{
	--top;
	val = top;
	
	return *this;
}

void Stack::Print()const
{
	int *ptr;

	ptr = base;

	while(ptr != top) {
		cout << endl <<*ptr << endl;
		ptr++;
	}	

}
