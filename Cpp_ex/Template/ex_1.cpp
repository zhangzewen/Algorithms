#include <iostream>
#include <string>

using namespace std;
using std::cin;
using std::cout;

template<class TYPE>
void PrintTwice(TYPE data)
{
	cout << "Twice: " << data * 2 << endl;
}


int main(int argc, char *argv[])
{
	PrintTwice(124);
	PrintTwice(124.5);
	PrintTwice(124.3);
}
