#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
using namespace std;

//������ȹ��
//TIC-TAE-TOE

//[.][.][.]
//[.][.][.]
//[.][.][.]

vector<vector<char>> board;

// [.][o][x][.][.][.][.][.][012] =>  3^9 =19683
//                 27 9  3  0   ����ũ�� ���ڸ� ����� ���� 3���� ó�� ����

int HashKey(const vector<vector<char>>& board)
{
	int ret = 0;

	for (int y = 0; y < 3; y++)
	{
		for (int x = 0; x < 3; x++)
		{
			ret = ret * 3;

			if (board[y][x] == 'o')
				ret += 1;
			else if(board[y][x] == 'x')
				ret += 2;
		}
	}


	return ret;
}

int cache[19683];

bool IsFinished(vector<vector<char>>& board, char turn)
{
	//�¿�
	for (int i = 0; i < 3; i++)
		if (board[i][0] == turn && board[i][1] == turn && board[i][2] == turn)
			return true;

	//����
	for (int i = 0; i < 3; i++)
		if (board[0][i] == turn && board[1][i] == turn && board[2][i] == turn)
			return true;

	//�밢��
	if(board[0][0] ==turn && board[1][1] == turn && board[2][2] == turn)
		return true;
	if(board[0][2] == turn && board[1][1] == turn && board[2][0] == turn)
		return true;

	return false;
}

enum
{
	DEFAULT = 2,
	WIN = 1,
	DRAW = 0,
	LOSE = -1
};

int CanWin(vector<vector<char>>& board , char turn)
{
	//���� ���
	if (IsFinished(board, 'o' + 'x' - turn))
		return LOSE;

	//ĳ��Ȯ��
	int key = HashKey(board);
	int& ret = cache[key];
	if (ret != DEFAULT)
		return ret;

	//Ǯ��
	int minValue = DEFAULT;
	for (int y = 0; y < 3; y++)
	{
		for (int x = 0; x < 3; x++)
		{
			if (board[y][x] != '.')
				continue;

			//����
			board[y][x] = turn;

			//Ȯ��
			minValue = min(minValue, CanWin(board, 'o' + 'x' - turn)); 

			//���
			board[y][x] = '.';
		}
	}

	if (minValue == DRAW || minValue == DEFAULT)
		return ret = DRAW;

	return ret = -minValue;
}

int main()
{
	board = vector<vector<char>>
	{
		{'o', 'x', 'x'},
		{'.', 'o', '.'},
		{'o', '.', '.'}
	};

	//meset(cache. -1, sizeof(cache)); //0 0 0 0 0000
	//meset(cache. 0, sizeof(cache)); //0b11111111111    �� ��밡��

	//meset(cache. (char)-2, sizeof(cache));
	//meset -2(4����Ʈ)�� �ʱ�ȭ �Ұ�

	for (int i = 0; i < 19683; i++)
		cache[i] = DEFAULT;

	int win = CanWin(board, 'x');

	switch (win)
	{
	case WIN:
		cout << "Win" << endl;
		break;

	case DRAW:
		cout << "Draw" << endl;
		break;

	case LOSE:
		cout << "Lose" << endl;
		break;
	}

}