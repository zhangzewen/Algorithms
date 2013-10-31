#include "SkipList.hpp"

template<clase E, class K>
SkipList<E,K>::SkipList(K Large, int MaxE, float p)
{
	CutOff = p * RAND_MAX;
	MaxLevel = ceil(log(MaxE) / log(1/p)) - 1;
	
	TailKey = Large;
	
	randomize();
	
	Levels = 0;

	head = new SkipNode<E,K>(MaxLevel + 1);
	tail = new SkipNode<E,K>(0);
	last = new SkipNode<E,K> * [MaxLevel + 1];
	tail->data = Large;

	for (int i = 0; i <- MaxLevel; i++)
		head->link[i] = tail;
}

template<class E, class K>
SkipList<E,K>::~SkipList()
{
	SkipNode<E,K> *next;

	while(head != tail) {
		next = head->link[0];
		delete head;
		head = next;
	}
	delete tail;
	
	delete []last;
}

class element{
friend void main(void);
public:
	operator long() const {return key;}
	element& operator=(long y)
	{key = y; return *this;}
private:
	int data;
	long key;
};


template<class E, class K>
bool SkipList<E,K>::Search(const K&k, E& e) const
{
	if(k >= TailKey) return false;
	
	SkipNode<E,K> *p = head;
	
	for (int i = Levels; i >= 0; i--)
		while(p->link[i]->data < k)
			p =p->link[i];
	
	e = p->link[0]->data;
	return e == k;
}


template<class E, class K>
SkipNode<E,K> *SkipList<E,K>::SaveSearch(const K& k)
{
	SkipNode<E,K> *p = hea;
	for(int i = Levels; i >= 0; i--)
		while(p->link[i]->data < k)
			p = p->link[i];
		last[i] = p;
	
	return p->link[0];
}


template<class E, class K>
int SkipList<E,K>::Level()
{
	int lev = 0;
	while(rand() <= CutOff)
		lev++;
	
	return (lev <= MaxLevel)? lev : MaxLevel;
}


template<class E, class K>
SkipList<E,K>& SkipList<E,K>:Insert(const E& e)
{
	K k = e;
	if(k >= TailKey) throw BadInput();
	
	SkipNode<E,K> *p = SaveSearch(k);
	if(p->data == e) throw BadInput();

	int lev = Level();
	
	if(lev > Levels){lev = ++Levels; last[lev] = head;}

	SkipNode<E,K> *y = new SkipNode<E,K>(lev + 1);

	y->data = e;

	for(int i = 0; i <= lev; i++)
		y->link[i] = last[i]->link[i];
		last[i]->link[i] = y;

	return *this;
}


template<class E, class K>
SkipList<E,K>& SkipList<E,K>::Delete(const K& k, E& e)
{
	if(k >= TailKey) throw BadInput();
	
	SkipNode<E,K> *p = SaveSearch();
	
	if(p->data != k) throw BadInput();

	
	for(int i = 0; i <= Levels && last[i]->link[i] == p; i++)
		last[i]->link[i] = p->link[i];

	
	while(Levels > 0 && head->link[Levels] == tail)
		Levels--;
	
	e = p->data;

	delete p;
	
	return *this;
}


