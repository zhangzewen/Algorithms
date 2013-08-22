#ifndef __SIMNODE_H_INCLUDED__
#define __SIMNODE_H_INCLUDED__
template<class T>
class SimNode{
	friend SimSpace<T>;
private:
	T data;
	int link;
};

template<class T>
class SimSpace{
public:
	SimSpace(int MaxSpaceSize = 100);
	~SimSpace(){delete[]node;}

	int Allocate();
	void Deallocate(int& i);
private:
	int NumberOfNodes ;
	int first;
	SimNode<T> *node;
};


template<class T>
SimSpace<T>::SimSpace(int MaxSpaceSize)
{
	NumberOfNodes = MaxSpaceSize;
	node = new SimNode<T>[NumberOfNodes];
	for(int i = 0; i < NumberOfNodes - 1; i++){
		node[i].link = i + 1;
	}
	
	node[NumberOfNodes - 1].link = -1;
	first = 0;
}

template<class T>
int SimSpace<T>::Allocate()
{
	if(first == -1)throw NoMem();
	int i = first;
	first = node[i].link;
	return i;
}

template<class T>
void SimSpace<T>::Deallocate(int &i)
{
	node[i].link = first;
	
	first = i;
	
	i = -1;
}

template<class T>
SimSpace<T>::SimSpace(int MaxSpaceSize)
{
	NumberOfNodes = MaxSpaceSize;
	node = new SimNode<T>[NumberOfNodes];
	first1 = 0;
	first2 = -1;
}


template<class T>
int SimSpace<T>::Allocate()
{
	if(first2 == -1){
		if(first1 == NumberOfNode)throw NoMem();
		return first1++;
	}

	int i = first2;
	first2 = node[i].link;
	return i;
}
#endif
