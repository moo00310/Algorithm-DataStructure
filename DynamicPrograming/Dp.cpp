#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
using namespace std;
#include <thread>
#include <Windows.h>


//동적 계획법(DP)

//n: 공의 수
//r: 공을 뽑는 갯수


//메모이제이션(Memoization)
//n은 50이하로 가정
int cache[50][50];

int combination(int n, int r)
{
	// 기저 사례(더 이상 쪼개지지 않는 작업)
	if (r == 0 || n == r)
		return 1;

	// 이미 답을 구한적이 있으면 바로 반환
	int& ret = cache[n][r];
	if (ret != -1)
		return ret;

	// 새로 답을 구해서 캐시에 저장
	return ret = combination(n - 1, r - 1) + combination(n - 1, r);
}

int main() 
{
	// 캐쉬 값을 -1로 초기화
	::memset(cache, -1, sizeof(cache)); 

	__int64 start = GetTickCount64();
	int Lotto = combination(45, 6);
	__int64 end = GetTickCount64();

	cout << end - start << "ms" << endl;
}