#include <iostream>
#include <Vector>
using namespace std;

//Vector 간단히 구현
template<typename T>
class Vector
{
public:
	Vector()
	{

	}
	~Vector()
	{
		if (_data)
			delete[] _data;
	}

	void push_back(const T& value) //왼값 참조
	{
		if (_size == _capacity) //모든공간 사용한다면
		{
			int newCapacity = static_cast<int>(_capacity * 1.5);
			if (newCapacity == _capacity)
				newCapacity++;

			reserve(newCapacity); //증설작업
		}
		_data[_size] = value; //데이터 저장

		_size++; //데이터 개수 증가
	}

	void reserve(int capacity) //메모리 증설
	{
		if (_capacity >= capacity)
		{
			return; //무시
		}
		_capacity = capacity;

		T* newData = new T[_capacity]; //새로운 catacity만큼 메모리 증설

		for (int i = 0; i < _size; i++)
		{
			newData[i] = _data[i];//데이터 복사
		}

		if (_data) //null 체크
		{
			delete[] _data; //데이터 삭제
		}

		_data = newData;		//교체

	}

	T& operator[](const int pos) { return _data[pos]; }

	int size() { return _size; }
	int capacity() { return _capacity; }

	void clear()
	{
		if (_data)
		{
			delete[] _data;
			_data = new T[_capacity]; //모든 소멸자 호출
		}

		_size = 0;
	}

private:
	T* _data = nullptr; //데이터 배열
	int _size = 0;		//현재 사용중인 데이터 개수
	int _capacity = 0;  //할당받은 데이터의 크기
};



int main() //size()와 capacity() 개념이 중요!
{
	vector<int> v; 

	v.resize(10); //실제 데이터 개수(size() 크기) 변화

	v.reserve(100); //데이터 공간 변화(capacity())
	//성능 행상 위해 초반 복사작업을 줄이는 게 좋다

	
	
	for (int i = 0; i < 100; i++)
	{
		v.push_back(i);
		cout << v[i] << " " << v.size() << " " << v.capacity() << endl;
		//size()는 실질적인 사용중인 데이터 갯수
		//capacitiy()는 예약된 공간 갯수 -> 복사를 최소한으로 하기 위해 여유분을 두고 할당
	}

	v.clear();
	cout << v.size() << " " << v.capacity() << endl;
	//clear() 해도 늘어난 capacity()는 줄어들지 않음

}