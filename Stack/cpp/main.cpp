#include <iostream>
#include "Stack.h"

using namespace std;
using std::cin;
using std::cout;


int main(int argc, char *argv[])
{

	Stack myStack(10, 5);
	myStack.Push(1);
	myStack.Push(2);
	myStack.Push(3);
	myStack.Push(1);
	myStack.Push(2);
	myStack.Push(3);
	myStack.Push(4);
	myStack.Push(5);
	myStack.Push(6);
	myStack.Push(7);
	myStack.Push(8);
	myStack.Push(9);
	myStack.Push(10);
	myStack.Push(11);
	myStack.Print();
	cout << "mystack.size() = " << myStack.size() << endl;
	cout << endl <<"===============" <<endl;
#if 1
	Stack myStack_2;
	myStack_2 = myStack;
#endif

	//Stack myStack_2 = myStack;
	cout << "mystack_2.size() = " << myStack_2.size() << endl;
	myStack_2.Print();
	cout << endl <<"===============" <<endl;
	Stack myStack_3;
	myStack_3.copy(myStack);
	cout << "mystack_3.size() = " << myStack_3.size() << endl;
	myStack_3.Print();
	
	return 0;
}
