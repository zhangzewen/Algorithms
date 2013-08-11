#include <iostream>

using namespace std;
using std::cin;
using std::cout;

template<class T>

Chain<T>::~Chain()
{
	ChainNode<T> *next;
	while(first){
		next = first->next;
		delete first;
		first = next;
	}
}

template<class T>
int Chain<T>::Length()const
{
	ChainNode<t> *current = first;
	int len = 0;
	while(current){
		len++;
		current = current->link;
	}

	return len;
}
	


template<class T>
bool Chain<T>:Find(int k, T& x)const
{
	if(k < 1)
		return false;
	
	ChainNode<T> *current = first;
	int index = 1;
	while(index < k && current){
		current = current->link;
		index++;
	}
	if(current){
		x = current->data;
		return true;
	}

	return false;
}

template<class T>
int Chain<T>::Search(const T& x)const
{
	ChainNode<T> *current = first;
	int index = 1;
	while(current && current->date != x){
		current = current->link;
		index++;
	}
	if(current){
		return index;
	}
	return 0;
}

template<class T>
void Chain<T>::Output(ostream& out) const
{
	ChainNode<t> *current = first;
	while(current){
		cout<< current->data << " ";
		current = current->link;
	}
}


template<class T>
ostream& operator<< (ostream& out, const Chain<T>& x)
{
	x.Output(out);
	return out;
}


template<class T>
Chain<T>& Chain<T>::Delete(int k, T& x)
{
	if(k < 1 || !first){
		throw OutOfBounds();
	}

	ChainNode<T>* current = firs;
	
	if( k == 1){
		first = first->link;
	}else{
		ChainNode<T> *q = first;
		for(int index = 1;index
	}
}

template<class T>
Chain<T>& Chain<T>::Delete(int k, const T& x)

