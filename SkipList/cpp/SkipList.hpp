#ifndef __ALGORITHMS_SKIPLIST_H_INCLUDED_
#define __ALGORITHMS_SKIPLIST_H_INCLUDED_

template<class E, class K>
class SkipNode{
	friend SkipList<E, K>;
private:
	SkipNode(int size)
	{
		line = new SkipNode<E,K> *[size];
	}

	~SkipNode()
	{
		delete []link;
	}

	E data;
	SkipNode<E, K> **link;
};	



template<class E, class K>

class SkipList{
public:
	SkipList(K Larg, int MaxE = 10000, float p = 0.5);
	~SkipList();
	bool Search(const K& k, E& e) const;
	SkipList<E, K>& Insert(const E& e);
	SkipList<E, K>& Delete(const K& k, E& e);
private:
	int Level();
	SkipNode<E, K> *SaveSearch(const K& k);
	int MaxLevel;
	int Levels;
	int CutOff;
	K TailKey;
	SkipNode<E,K> *hea;
	SkipNode<E,K> *tail;
	SkipNode<E,K> **last;
};


#endif
