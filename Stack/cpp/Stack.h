#ifndef __CPP_STACK_H_
#define __CPP_STACK_H_
class Stack{
public:
	Stack():base(NULL), top(NULL), stacksize(0), current(0),  step(0) {}
	Stack(int size, int step_val):base(NULL), top(NULL), stacksize(0), current(0), step(0){
		base = new int[size];
		top = base;
		stacksize = size;
		step = step_val;
	}
	int GetTop()const;
	Stack& Pop();
	Stack& Push(int val);
	void Print()const;
	~Stack(){
		delete [] base;
		base = NULL;
		top = NULL;
		stacksize = 0;
		step = 0;
	}
	bool empty() const;
	Stack& operator= (Stack const&);
	int size() const;
	Stack& copy(Stack const&);
private:
	int *base;
	int *top;
	int stacksize;
	int current;
	int step;
};


#endif
