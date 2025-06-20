#include <iostream>
using namespace std;
template <typename T>

class SimpleVector
{
private:
	T* data;//타입이 T(어떤 타입이든 될수 있는)인 맴버변수 data
	int currentSize;
	int currentCapacity;

public:
	SimpleVector()//생성자
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
		}	//현재의 사이즈가 용량보다 작다면 value값을 사이즈+1의 자리에 저장
	}

	void pop_back()
	{
		if (currentSize > 0)
		{
			--currentSize;
		}	//현재 배열의 사이즈가 0보다 클때만 제일 뒤의 원소 제거
	}

	int size() const
	{
		return currentSize;
	}	//현재 배열의 크기
	int capacity() const
	{
		return currentCapacity;
	}	//현재 배열의 용량
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
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	SimpleVector<int> vec;

	for (int i = 0; i < 9; i++)
	{
		vec.push_back(i);
	}

	vec.print();

	vec.pop_back();
	vec.print();

	cout << "size: " << vec.size() << endl;
	cout << "capacity: " << vec.capacity() << endl;
}