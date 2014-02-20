#include <iostream>
#include <string>

using namespace std;
using std::cin;
using std::cout;
using std::string;

ifstream file("ex_12_18.cpp");
class NoName{
private:
	const string str;
	int val;
	double *ptr;
	ifstream &instream;
public:
	NoName(string name): str(name), val(0), ptr(NULL), instream(file){}
};

int main(int argc, char *argv[])
{
	
}
