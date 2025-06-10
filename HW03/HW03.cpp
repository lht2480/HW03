#include <iostream>
using namespace std;
template <typename T>

class SimpleVector
{
private:
	T* data;
	int currentSize;
	int currentCapacity;

public:
	SimpleVector()
	{
		currentCapacity = 10;
		currentSize = 0;
		data = new T[currentCapacity];
	}
	SimpleVector(int capacity)
	{
		currentCapacity = capacity;
		currentSize = 0;
		data = new T[currentCapacity];
	}
	~SimpleVector()
	{
		delete[] data;
	}
	void push_back(const T& value)
	{
		if (currentSize < currentCapacity)
		{
			data[currentSize++] = value;
		}
	}
	void pop_back()
	{
		if (currentSize > 0)
		{
			--currentSize;
		}
	}
	int size() const
	{
		return currentSize;
	}
	int capacity() const
	{
		return currentCapacity;
	}
	void print() const
	{
		for (int i = 0; i < currentSize; i++)
		{
			cout << data[i] << " ";
		}
		cout << "\n";
	}
};
int main()
{
	SimpleVector<int> vec;

	for (int i = 0; i < 12; i++)
	{
		vec.push_back(i);
	}

	vec.print();

	vec.pop_back();
	vec.print();

	cout << "size: " << vec.size() << endl;
	cout << "capacity: " << vec.capacity() << endl;
}