#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
using namespace std;

//������ȹ��
//Triangle_Path

// -(0, 0)���� �����ؼ� �Ʒ� or �Ʒ��������� �̵� ����
// - ������ ���ڸ� ��� ����
// - ���� ���ڰ� �ִ밡 �Ǵ� ���? ��?

// 6
// 1 2
// 3 7 4
// 9 4 1 7
// 2 7 5 9 4

int N;
vector<vector<int>> board;

vector<vector<int>> cache;
vector<vector<int>> nextX;

int path(int y, int x)
{
	//��������
	/*if (y == N - 1)
		return board[N - 1][x];*/
	if (y == N)
		return 0;

	//ĳ�� Ȯ��
	int& ret = cache[y][x];
	if (ret != -1)
	{
		return ret;
	}


	//��α��
	{
		int nextBottom = path(y + 1, x);
		int nextBottomRight = path(y + 1, x + 1);
		if (nextBottom > nextBottomRight)
			nextX[y][x] = x;
		else
			nextX[y][x] = x + 1;
	}

	//����
	//board[y][x] + path(y + 1, x);
	//board[y][x] + path(y+1, x + 1);

	return ret = board[y][x] + max(path(y + 1, x), path(y + 1, x + 1));
}

int main()
{
	board = vector<vector<int>>
	{
		{6},
		{1, 2},
		{3, 7, 4},
		{9, 4, 1, 7},
		{2, 7, 5, 9, 4}
	};

	N = board.size();
	cache = vector<vector<int>>(N, vector<int>(N, - 1));
	nextX = vector<vector<int>>(N, vector<int>(N));

	int ret = path(0, 0);
	cout << ret << endl;

	//��� �����
	int y = 0;
	int x = 0;

	while (y < N)
	{
		cout << board[y][x] << "->";
		x = nextX[y][x];
		y++;
	}
}