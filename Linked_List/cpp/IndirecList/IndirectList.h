#ifndef __INDIRECTLIST_H_INCLUDED__
#define __INDIRECTLIST_H_INCLUDED__
template<class T>
class IndirectList{
pulic:
	IndirectList(int MaxListSize = 10);
	~IndirectList();
	bool IsEmpty()const {return length == 0}
	bool Find(int k, T& k)const;
	int Search(const T& x)const;
	IndirectList<T>& Delete(int k, T& x);
	IndirectList<T>& Insert(int k, const T& x);
	void Output(ostream& out) const;
private:
	T **table;
	int lenght;
	int MaxSize;
};


template<class T>
IndirecList<T>::IndirectList(int MaxListSize)
{
	MaxSize = MaxListSize;
	table = new T*[MaxSize];
	length = 0;
}

template<class T>
IndirectList<T>::~IndirectList()
{
	for(int i = 0; i < length; i++){
		delete table[i];
	}
	delete[] table;
}

template<class T>
bool IndirectList<T>::Find(int k, T& k)const
{
	if(k < 1 || k > length) return false;
	x = *table[k - 1];
	return true;
}

template<class T>
IndirectList<T>& IndirectList<T>::Delete(int k, T& x)
{
	if(Find(k, x)){
		for(int i = k; i < length; i++){
			table[i - 1] = table[i];
		}
		length--;
		return *this;
	}

	else throw OutofBounds();
}

template<class T>
IndirectList<T>& IndirectList<T>::Insert(int k, const T& x)
{
	if(k < 0 || k > length)throw OutOfBounds();
	if(length == MaxSize) throw NoMem();
	
	for(int i = length - i; i >= k; i--){
		table[i + 1] = table[i];
	}
	table[k] = new T;
	*table[k] = x;
	length++;
	return *this;
}
#endif
