#ifndef _CHAINNODE_H_INCLUDED__
#define _CHAINNODE_H_INCLUDED__

using namespace std;
using std::cin;
using std::cout;


class NoMem
{
public:
	NoMem(){}
};

void OutOfBounds()
{
	throw NoMem();
}

template<class T>
class Chain;

template<class T>
class ChainNode{
	friend class Chain<T>;
private:
	T data;
	ChainNode<T> *link;
};

template<class T>
class Chain{
public:
	Chain(){first = 0;}
	~Chain();
	bool IsEmpty()const{return first = 0;}
	int Length() const;
	bool Find(int k, T& x)const;
	int Search(const T& x)const;
	Chain<T>& Delete(int k, T& x);
	Chain<T>& Insert(int k, const T& x);
	void Output(ostream& out)const;
private:
	ChainNode<T> *first;
};


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
	ChainNode<T> *current = first;
	int len = 0;
	while(current){
		len++;
		current = current->link;
	}

	return len;
}
	


template<class T>
bool Chain<T>::Find(int k, T& x)const
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
	ChainNode<T> *current = first;
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
		for(int index = 1;index < k - 1 && q; index++){
			q = q->link;
		}
		if(!q || !q->link){
			throw OutOfBounds();
		}

		current = q->link;
		q->link = p->link;
	}

	x = p->data;
	delete p;
	return *this;
}

template<class T>
Chain<T>& Chain<T>::Insert(int k, const T& x)
{
	if(k < 0){
		throw OutOfBounds();
	}

	ChainNode<T> *current = first;

	for(int index = 1; index < k && current; index++)
	{
		current = current->link;
	}

	if(k > 0 && !p) {
		throw OutOfBounds();
	}

	ChainNode<T> *y = new ChainNode<T>;
	y->data = x;
	if(k){
		y->link = p->link;
		p->link = y;
	}else{
		y->link = first;
		p->link = y;
	}
	return *this;
}

template<class T>
void Chain<T>::Erase()
{
	ChainNode<T> *next;
	while(first){
		next = first->link;
		delete first;
		first = next;
	}
}


template<class T>
Chain<T>& Chain<T>::Append(const T&x)
{
	ChainNode<T> *y;
	y = new ChainNode<T>;
	y->data = x;
	y->link = 0;
	if(first){
		last->link = y;
		last = y;
	}else{
		first = last = y;
	}
	return *this;
}


template<class T>
class ChainIterator{
public:
	T* Initialize(const Chain<T>& c){
		location = c.first;
		if(location){
			return &location->data;
		}
		return 0;
	}
 	T* Next(){
		if(!location){
			return 0;
		}
		location = location->link;
		if(location){
			return &location->data;
		}
		return 0;
	}
private:
	ChainNode<T> *location;
}

#endif
