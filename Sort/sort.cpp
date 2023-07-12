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

//4) �� ���� (Heap Sort)
void HeapSort(vector<int>& v)
{
	priority_queue<int, vector<int>, greater<int>> pq;

	//O(N * logN)
	for (int num : v)
	{
		pq.push(num);
	}

	v.clear();

	//O(NlogN)
	while (pq.empty() == false)
	{
		v.push_back(pq.top());
		pq.pop();
	}
}

//5) ���� ���� (MergeSort)
// ���� ���� (Divide and Conquer)
// - ���� (Divide)		 ������ �� �ܼ��ϰ� ����
// - ���� (Conquer)		���ҵ� ������ �ذ�
// - ���� (Combine)		����� �����Ͽ� ������

//[3][k][7][2][j][4][8][9]		8��*1 -> 4��*2 -> 2��*4 -> 1��*8 -> 2��*4 -> 4��*2 -> 8��*1
//[3][k][7][2]  [j][4][8][9] 

// ������/���� ������ ����
//[2][3][7][k]  [4][8][9][j]

//�� �տ� �� ���ڸ� ���Ͽ� ����
// [2][3][4][7][8][9][j][k]

void MergeResult(vector<int>& v, int left, int mid, int right)
{
	//[2][3][7][K]  [4][8][9][J] 
	//			[l]		        [r]
	int leftIdx = left;
	int rightIdx = mid + 1;

	vector<int> temp;

	while (leftIdx <= mid && rightIdx <= right)
	{
		if (v[leftIdx] <= v[rightIdx])
		{
			temp.push_back(v[leftIdx]);
			leftIdx++;
		}
		else
		{
			temp.push_back(v[rightIdx]);
			rightIdx++;
		}
	}
	//������ ���� ��������, ������ ������ ������ ����
	if (leftIdx >= mid)
	{
		while (rightIdx <= right)
		{
			temp.push_back(v[rightIdx]);
			rightIdx++;
		}
	}
	else //�������� ���� ��������, ���� ������ ������ ����
	{
		while (leftIdx <= mid)
		{
			temp.push_back(v[leftIdx]);
			leftIdx++;
		}
	}

	for (int i = 0; i < (int)temp.size(); i++)
	{
		v[left + i] = temp[i];
	}
}

void MergeSort(vector<int>& v, int left, int right)
{
	if (left >= right)
		return;

	int mid = (left + right) / 2;

	MergeSort(v, left, mid); //4
	MergeSort(v, mid +1, right); //4

	MergeResult(v, left, mid, right);
	//O(N logN)
}

int main()
{
	vector<int> v;

	srand(time(0));

	for (int i = 0; i < 50; i++)
	{
		int randValue = rand() % 100;
		v.push_back(randValue);
	}

	//BubbleSort(v);
	//SelectionSort(v);
	//InsertionSort(v);
	//HeapSort(v);
	MergeSort(v, 0, (int)v.size() - 1);
} 