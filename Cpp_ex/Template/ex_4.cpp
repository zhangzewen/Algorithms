#include <iostream>
using namespace std;
using std::cin;
using std::cout;

template<class T>
double GetAverage(T tArray[], int nElements)
{
	T tSum = T();

	for (int nIndex = 0; nIndex < nElements; ++nIndex)
	{
		tSum += tArray[nIndex];
	}

	return double(tSum) / nElements;
}

int main()
{
	int InArray[5] = {100, 200, 400, 500, 1000};
	float FloatArray[3] = {1.55f, 5.44f, 12.36f};

	cout << GetAverage(InArray, 5) << endl;
	cout << GetAverage(FloatArray, 3) << endl;
}
