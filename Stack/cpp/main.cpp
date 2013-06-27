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
	myStack.Print();
	cout << endl <<"===============" <<endl;
	myStack.Pop();
	myStack.Pop();
	myStack.Pop();
	cout << endl <<"===============" <<endl;
	myStack.Pop();
	myStack.Print();
	return 0;
}
