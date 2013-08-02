#include <iostream>

using namespace std;
using std::cin;
using std::cout;

void my_new_handler()
{
	throw NoMem();
}

new_handler Old_Handler = set_new_handler(my_new_handler);


template<class T>
LinearList<T>::LinearList(int MaxListSize)
{
	MaxSize = MaxListSize;
	element = new T[MaxSize];
	length = 0;
}

template<class T>
bool LinearList<T>::Find(int k, T& x)const
{
	if(k < 1 || k > length) return false;
	x = element[k - 1];
	return true;
}

template<class T>
int LinearList<T>::Search(const T& x)const
{
	for(int i = 0; i < length; i++)
		if(element[i] == x) return ++i;
	return 0;
}


template<class T>
LinearList<T>& LinearList<T>::Delete(int k, T& x)
{
	if(Find(k, x)){
		for(int i = k; i < length; i++)
			element[i - 1] = element[i];
		length--;
		return *this;
	}
	else throw OutOfBounds();
}


template<class T>
LinearList<T>& LinearList<T>::Insert(int k, const T& x)
{
	if(k < 0 || k > length) throw OutOfBounds();
	if(length == MaxSize) throw NoMem();
	
	for(int i = length - i; i >= k; i--)
		element[i + 1] = element[i];
	element[k] = x;
	length++;
	return *this;
}


template<class T>
void LinearList<T>::Output(ostream &out)const
{
	for(int i = 0; i< length; i++)
		out << element[i] << "";
}

template<class T>
ostream& operator<<(ostream& out, const LinearList<T>& x)
{
	x.Output(out);
	return out;
}

