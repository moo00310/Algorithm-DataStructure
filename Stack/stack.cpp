#include <iostream>
#include <stack>
#include <vector>
#include <list>

using namespace std;

//Stack (LIFO ���Լ���)


//�迭�� ���� �ǰ� ���Ḯ��Ʈ�� ���� �ȴ�.
template<typename T, typename Container = vector<T>> //�⺻������ vector���� �������
class Stack
{
public:
	void push(const T& value) //������ ����
	{
		_container.push_back(value);
	}

	//T& if_pop() // ����� ���Ÿ� �ѹ��� ���� ���� ���� -> ����
	//{
	//	T ret = _data[_size - 1];  //�ּҰ� ���� �������� �����ؾ��ϴµ� T type�� ���ſ� ���ɼ� / �����ϴ� �������� ����ó�� ������ ������� �ִ�.
	//	_size--;
	//	return ret;
	//}

	void pop() //�ֻ��� ������ ����
	{
		_container.pop_back();
	}

	T& top() //�ֻ��� ������ return
	{
		return _container.back();
	}

	bool empty() { return _container.empty(); }

	int size() { return _container.size(); }

private:
	//vector<T> _container;
	//list<T> _container;
	Container _container;
};

int main()
{
	Stack<int, list<int>> s;  //����Ʈ�� ������ ������̴�.

	//����
	s.push(1);
	s.push(2);
	s.push(3);

	while (s.empty() == false)
	{
		//�ֻ��� ����
		int data = s.top();

		//�ֻ��� ���� ����
		s.pop();

		cout << data << endl;
	}

	int size = s.size();

}