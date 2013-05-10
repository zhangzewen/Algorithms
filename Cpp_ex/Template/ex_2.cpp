#include <iostream>

using namespace std;
using std::cin;
using std::cout;

template<typename TYPE>
TYPE Twice(TYPE data)
{
	return data * 2;
}

int main(int argc , char *argv[])
{
	cout << Twice(10);
	cout << Twice(3.14);
	cout << Twice( Twice(55));
	return 0;
}
