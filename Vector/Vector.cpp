#include <iostream>
#include <Vector>
using namespace std;

//Vector ������ ����
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

	void push_back(const T& value) //�ް� ����
	{
		if (_size == _capacity) //������ ����Ѵٸ�
		{
			int newCapacity = static_cast<int>(_capacity * 1.5);
			if (newCapacity == _capacity)
				newCapacity++;

			reserve(newCapacity); //�����۾�
		}
		_data[_size] = value; //������ ����

		_size++; //������ ���� ����
	}

	void reserve(int capacity) //�޸� ����
	{
		if (_capacity >= capacity)
		{
			return; //����
		}
		_capacity = capacity;

		T* newData = new T[_capacity]; //���ο� catacity��ŭ �޸� ����

		for (int i = 0; i < _size; i++)
		{
			newData[i] = _data[i];//������ ����
		}

		if (_data) //null üũ
		{
			delete[] _data; //������ ����
		}

		_data = newData;		//��ü

	}

	T& operator[](const int pos) { return _data[pos]; }

	int size() { return _size; }
	int capacity() { return _capacity; }

	void clear()
	{
		if (_data)
		{
			delete[] _data;
			_data = new T[_capacity]; //��� �Ҹ��� ȣ��
		}

		_size = 0;
	}

private:
	T* _data = nullptr; //������ �迭
	int _size = 0;		//���� ������� ������ ����
	int _capacity = 0;  //�Ҵ���� �������� ũ��
};



int main() //size()�� capacity() ������ �߿�!
{
	vector<int> v; 

	v.resize(10); //���� ������ ����(size() ũ��) ��ȭ

	v.reserve(100); //������ ���� ��ȭ(capacity())
	//���� ��� ���� �ʹ� �����۾��� ���̴� �� ����

	
	
	for (int i = 0; i < 100; i++)
	{
		v.push_back(i);
		cout << v[i] << " " << v.size() << " " << v.capacity() << endl;
		//size()�� �������� ������� ������ ����
		//capacitiy()�� ����� ���� ���� -> ���縦 �ּ������� �ϱ� ���� �������� �ΰ� �Ҵ�
	}

	v.clear();
	cout << v.size() << " " << v.capacity() << endl;
	//clear() �ص� �þ capacity()�� �پ���� ����

}