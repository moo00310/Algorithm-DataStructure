#include <iostream>
#include <stack>
#include <vector>
#include <list>

using namespace std;

//Stack (LIFO 후입선출)


//배열로 만들어도 되고 연결리스트로 만들어도 된다.
template<typename T, typename Container = vector<T>> //기본값으로 vector으로 만들어짐
class Stack
{
public:
	void push(const T& value) //데이터 삽입
	{
		_container.push_back(value);
	}

	T& if_pop() // 복사와 제거를 한번에 하지 않은 이유 -> 성능
	{
		T ret = _data[_size - 1];  //주소값 전달 과정에서 복사해야하는데 T type이 무거울 가능성 / 복사하는 과정에서 예외처리 문제가 생길수도 있다.
		_size--;
		return ret;
	}

	void pop() //최상위 데이터 제거
	{
		_container.pop_back();
	}

	T& top() //최상위 데이터 return
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
	Stack<int, list<int>> s;  //리스트로 스택을 만들것이다.

	//삽입
	s.push(1);
	s.push(2);
	s.push(3);

	while (s.empty() == false)
	{
		//최상위 원소
		int data = s.top();

		//최상위 원소 삭제
		s.pop();

		cout << data << endl;
	}

	int size = s.size();

}