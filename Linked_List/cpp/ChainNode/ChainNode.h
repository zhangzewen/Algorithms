#ifndef _CHAINNODE_H_INCLUDED__
#define _CHAINNODE_H_INCLUDED__

template<class T>
class ChainNode{
	friend Chain<t>;
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
	bool Find(intk, T& x)const;
	int Search(const T& x)const;
	Chain<T>& Delete(int k, T& x);
	Chain<T>& Insert(int k, const T& x);
	void Output(ostream& out)const;
private:
	ChainNode<T> *first;
#endif
