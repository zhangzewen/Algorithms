#ifndef _ALGORITHMS_CPP_LINEARLIST_INCLUDE_H
#define _ALGORITHMS_CPP_LINEARLIST_INCLUDE_H

template<class T>
class LinearList{
public:
	LinearList(int MaxListSize = 10);
	~LinearList(){delete [] element;}
	bool IsEmpty()const{return length == 0}
	int Length()const{return length}
	bool Find(int k, T& x)const;
	int Search(const T& x)const;
	LinearList<T>& Delete(int k, T&x);
	LinearList<T>& Insert(int k, const T& x);
	void Output(ostream& out)const;
private:
	int length;
	int MaxSize;
	T* element;
};

#endif
