#include <iostream>
#include <stack>
#include <vector>
#include <list>
#include <thread>
#include <queue>

using namespace std;

//1) 버블 정렬 (Bubble Sort)
// 둘개씩 크기를 비교하며 정렬 
void BubbleSort(vector<int>& v)
{
	const int n = (int)v.size();

	//(N-1) + (N-2) + ... + 2 + 1
	//등차수열의 합 = N*(N-1)/2
	//O(N^2)

	for (int i = 0; i < n-1; i++)
	{
		for (int j = 0; j < (n - 1 - i); j++)
		{
			if (v[j] > v[j + 1])
			{
				//swap(v[j], v[j + 1]);
				int temp = v[j];
				v[j] = v[j + 1];
				v[j + 1] = temp;
			}
		}
	}
}

//2) 선택정렬 (Selection Sort)
//가장 작은 수를 왼쪽으로 보내가며 정렬
void SelectionSort(vector<int>& v)
{
	const int n = (int)v.size();

	//O(N^2)

	for (int i = 0; i < n-1; i++)
	{
		int bestIdx = i;

		for (int j = i + 1; j < n; j++)
		{
			if (v[j] < v[bestIdx])
				bestIdx = j;
		}

		//교환
		int temp = v[i];
		v[i] = v[bestIdx];
		v[bestIdx] = temp;
	}
}

//3) 삽입정렬 (Insertion Sort)
// 
//임시벡터를 생성해 삽입라는게 아님

void InsertionSort(vector<int>& v)
{
	const int n = (int)v.size();

	//O(N^2)

	for (int i =1; i < n; i++)
	{
		int insertData = v[i];

		int j;
		for (j = i - 1; j >= 0; j--)
		{
			if (v[j] > insertData)
				v[j + 1] = v[i];
			else
				break;
		}

		v[j + 1] = insertData;

	}
}

int main()
{
	vector<int> v{1, 5, 3, 4, 2};

	std::sort(v.begin(), v.end());

	//BubbleSort(v);
	//SelectionSort(v);
	InsertionSort(v);
}