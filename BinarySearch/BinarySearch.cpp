#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
using namespace std;

//이진 탐색 (Binary Search) 시간복잡도는 O(logN)
//(up /down 게임)

//정렬된 배열을 이용해서 이진탐색 가능(numbers[mid])
//정렬되었어도 연결 리스트로는 불가(임의 접근x)

vector<int> numbers;

void BinarySearch(int N)
{
	int left = 0; //시작점
	int right = numbers.size() - 1; //끝점

	while (left <= right)
	{
		cout << "탐색범위:" << left << "~" << right << endl;
		int mid = (left + right) / 2; //내림적용

		if (N < numbers[mid])
		{
			cout << N << "<" << numbers[mid] << endl;
			right = mid - 1;
		}
		else if(N > numbers[mid])
		{
			cout << N << ">" << numbers[mid] << endl;
			left = mid + 1;
		}
		else
		{
			cout << "찾음!" << endl;
			break;
		}
	}
}

int main()
{
	numbers = vector<int>{ 1, 8, 11, 15, 32, 44, 56, 63, 81, 91 };
	BinarySearch(81);
}