#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
using namespace std;
#include <thread>
#include <Windows.h>


//���� ��ȹ��(DP)

//n: ���� ��
//r: ���� �̴� ����


//�޸������̼�(Memoization)
//n�� 50���Ϸ� ����
int cache[50][50];

int combination(int n, int r)
{
	// ���� ���(�� �̻� �ɰ����� �ʴ� �۾�)
	if (r == 0 || n == r)
		return 1;

	// �̹� ���� �������� ������ �ٷ� ��ȯ
	int& ret = cache[n][r];
	if (ret != -1)
		return ret;

	// ���� ���� ���ؼ� ĳ�ÿ� ����
	return ret = combination(n - 1, r - 1) + combination(n - 1, r);
}

int main() 
{
	// ĳ�� ���� -1�� �ʱ�ȭ
	::memset(cache, -1, sizeof(cache)); 

	__int64 start = GetTickCount64();
	int Lotto = combination(45, 6);
	__int64 end = GetTickCount64();

	cout << end - start << "ms" << endl;
}