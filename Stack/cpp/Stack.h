#ifndef __CPP_STACK_H_
#define __CPP_STACK_H_

class Stack{
public:
	Stack(int size, int step):base(NULL), top(NULL), stacksize(0), step(0){
		base = new int[size];
		top = base;
		stacksize = size;
		step = step;
	}
	int GetTop(Stack& S)const;
	Stack& Pop(Stack& S){return *this;}
	Stack& Push(Stack& S){return *this;}
	~Stack(){
		for(;base != top; base++){
			free(base);
		}
		free(top);
		base = NULL;
		top = NULL;
		stacksize = 0;
		step = 0;
	}
private:
	int *base;
	int *top;
	int stacksize;
	int step;
};


#endif
