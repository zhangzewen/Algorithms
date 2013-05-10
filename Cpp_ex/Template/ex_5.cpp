#include <iostream>
#include <string>
using namespace std;
using std::cin;
using std::cout;

template<class T>
void TwiceIt(T&tData)
{
	tData *= 2;
}


int main(int argc, char *argv[])
{
	int x = 40;
	cout << TwiceIt(x);
}
