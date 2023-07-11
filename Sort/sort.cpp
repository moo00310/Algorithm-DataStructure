#include <iostream>
#include <stack>
#include <vector>
#include <list>
#include <thread>
#include <queue>

using namespace std;

//1) ���� ���� (Bubble Sort)
// �Ѱ��� ũ�⸦ ���ϸ� ���� 
void BubbleSort(vector<int>& v)
{
	const int n = (int)v.size();

	//(N-1) + (N-2) + ... + 2 + 1
	//���������� �� = N*(N-1)/2
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

//2) �������� (Selection Sort)
//���� ���� ���� �������� �������� ����
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

		//��ȯ
		int temp = v[i];
		v[i] = v[bestIdx];
		v[bestIdx] = temp;
	}
}

//3) �������� (Insertion Sort)
// 
//�ӽú��͸� ������ ���Զ�°� �ƴ�

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