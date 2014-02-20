#include <iostream>
#include <string>

using namespace std;
using std::cin;
using std::cout;

class NoName {
public:
	NoName(){pstring = NULL; ival = 0; dval = 0.0;}
	NoName(string *ptr, int ival, double dval) {
		this->pstring = ptr;
		this->ival = ival;
		this->dval = dval;
	}
private:
	std::string *pstring;
	int ival;
	double dval;
};


int main(int argc, char *argv[])
{
	return 0;
}
