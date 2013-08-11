#include <iostream>
#include <string>
#include "LinearList.h"

using namespace std;
using std::cin;
using std::cout;

int main(int argc ,char *argv[])
{
	LinearList<int> L(5);
	cout << "Length = " << L.Length() << endl;
	cout << "IsEmpty = " << L.IsEmpty() << endl;
	L.Insert(0,6).Insert(1,6);
	cout << "List is" << L <<endl;
	cout << "IsEmpty" << L.IsEmpty() << endl;
	int z;
	L.Find(1, z);
	cout << "first element is" << z <<endl;
	cout << "length = " << L.Length <<endl;
	L.Delete(1, z);
	cout << "Deleted element is" << z <<endl;
	cout << "List is" << L << endl;
	return 0;
}
