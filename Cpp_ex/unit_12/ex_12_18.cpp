#include <iostream>
#include <string>

using namespace std;
using std::cin;
using std::cout;


typedef string Type;

Type initVal();


class Exercise {
public:
	typedef double Type;
	Type setVal(Type);
	Type initVal(){};
private:
	Type val;
};

Exercise::Type Exercise::setVal(Type parm) {
	val = parm + initVal();
}


int main(int argc, char *argv[])
{
	return 0;
}
