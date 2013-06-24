#include <iostream>
#include "Stack.h"



int Stack::GetTop(Stack& S)const
{
	int *ptr;
	ptr = S.top;
	ptr--;
	return *ptr;
}






Stack& Stack::Push(Stack& S)
{
	if(S.top - S.base >= 0){
	
	}
	
	
	
	return *this;
}

Stack& Stack::Pop(Stack& S)
{
	return *this;
}
