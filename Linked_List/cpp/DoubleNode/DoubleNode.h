#ifndef __DOUBLENODE_H_INCLUDE_
#define __DOUBLENODE_H_INCLUDE_

template<class T>
class DoubleNode{
	friend Double<T>;
private:
	T data;
	DoubleNode<T> *left, *right;
};

template<class T>
class Double{
public:
	Double(){
		next = prev = NULL;
	}
	~Double();
	int Length()const;
	bool Find(int k, T& x)const;
	int Search(const T& x)const;
	Double<T>& Delete(int k, T& x);
	Double<T>& Insert(int k, const T& x);
	void Output(ostream& out)const;
private:
	DoubleNode<T> *next;
	DoubleNode<T> *prev;
};
	

#endif
