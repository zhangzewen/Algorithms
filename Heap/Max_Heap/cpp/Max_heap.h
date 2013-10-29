#ifndef __ALGORITHMS_HEAP_MAXHEAP_CPP_H_INCLUDED__
#define __ALGORITHMS_HEAP_MAXHEAP_CPP_H_INCLUDED__



template<class T>
class MaxHeap{
public:
	MaxHeap(int MaxHeapSize = 10);
	~MaxHeap() {delete [] heap;}
	
	int Size() const {return CurrentSize;}
	T Max()
	{
		if (CurrentSize == 0) throw OutOfBounds();
		return heap[1];
	}

	MaxHeap<T>& Insert(const T& x);

	MaxHeap<T>& DeleteMax(T& x);
	void Initialize(T a[], int size, int ArraySize);
private:
	int CurrentSize;
	int MaxSize;
	T *heap;
};

template<class T>
MaxHeap<T>::MaxHeap(int MaxHeapSize)
{
	MaxSize = MaxHeapSize;
	heap = new T[MaxSize + 1];
	CurrentSize = 0;
}


template<class T>
MaxHeap<T>& MaxHeap<T>::Insert(const T&x)
{
	if (CurrentSize == MaxSize)
		throw NoMem();
	
	int i = ++ CurrentSize;
	
	while (i != 1 && x > heap[i/2]) {
		heap[i] = heap[i/2];
		i /= 2;
	}

	heap[i] = x;
	return *this;
}

template<class T>
MaxHeap<T>& MaxHeap<T>::DeleteMax(T& x)
{
	if (CurrentSize == 0)
		throw OutOfBounds();
	
	x = heap[1];
	
	T y = heap[CurrentSize--];

	int i = 1;
	ci = 2;
	while (ci <= CurrentSize) {
		if (ci < CurrentSize &&
			heap[c] < heap[ci + 1])
			ci++;
	}	
}





#endif
