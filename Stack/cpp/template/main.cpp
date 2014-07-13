#include <iostream>
#include "Stack.h"

using namespace std;
using std::cin;
using std::cout;


int main(int argc, char *argv[])
{

#if 0
	Stack<int> myStack(10, 5);
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
	Stack<int> myStack_2;
	myStack_2 = myStack;
#endif

	//Stack myStack_2 = myStack;
	cout << "mystack_2.size() = " << myStack_2.size() << endl;
	myStack_2.Print();
	cout << endl <<"===============" <<endl;
	Stack<int> myStack_3;
	myStack_3.copy(myStack);
	cout << "mystack_3.size() = " << myStack_3.size() << endl;
	myStack_3.Print();
#endif

	string v1 = "zhangjie";
	string v2 = "jie";
	string v3 = "guangzhou";
	string v4 = "dalian";
	string v5 = "anyang";
	string v6 = "hefei";
	string v7 = "New York";
	string v8 = "Maiami";
	string ex;
	
	Stack<string> myStack(10, 5);

	myStack.Push(v1);
	myStack.Push(v2);
	myStack.Push(v3);
	myStack.Push(v4);
	myStack.Push(v5);
	myStack.Push(v6);
	myStack.Push(v7);
	myStack.Push(v8);
	myStack.Print();
	
	cout << "mystack.size() = " << myStack.size() << endl;
	cout << endl <<"===============" <<endl;
	myStack.Pop(ex);
	cout << "ex = " << ex << endl;
	cout << "mystack.size() = " << myStack.size() << endl;
	myStack.Print();
	cout << endl <<"===============" <<endl;
#if 1
	Stack<string> myStack_2;
	myStack_2 = myStack;
#endif

	//Stack myStack_2 = myStack;
	cout << "mystack_2.size() = " << myStack_2.size() << endl;
	myStack_2.Print();
	cout << endl <<"===============" <<endl;
	Stack<string> myStack_3;
	myStack_3.copy(myStack);
	cout << "mystack_3.size() = " << myStack_3.size() << endl;
	myStack_3.Print();
	return 0;
}
