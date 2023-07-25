#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
using namespace std;

//������ȹ��
//LIS (Longest Increasing Sequence)

//Seq : 1 9 2 5 7
//�κ� ���� : �Ϻ�(0�� �̻�) ���ڸ� ����� ���� ����
//ex) 1 2 5
//ex) 1 9 5 7

//�� ���� �κ� ����
//ex) 1 2 5
 
//LIS : ���� ��[�� ���� �κ� ����]�� ����
// 1 2 5 7 ����->  4

vector<int> seq;
int cache[100];

int LIS(int pos)
{
	//���� ����
	/*if (pos == seq.size() - 1)
		return 1;*/

	//ĳ�� Ȯ��
	int& ret = cache[pos];
	if (ret != -1)
		return ret;

	//���ϱ�
	//Seq : 1 9 2 5 7
	
	//1 9
	//1 2 5 7
	//1 5 7
	//1 7
	ret = 1;

	for (int next = pos + 1; next < seq.size(); next++)
	{
		if (seq[pos] < seq[next])
			ret = max(ret, 1 + LIS(next));
	}

	return ret;
}

int main()
{
	::memset(cache, -1, sizeof(cache));

	seq = vector<int>{ 1, 9, 2, 5, 7 };

	int ret = 0;
	for (int pos = 0; pos < seq.size(); pos++)
		ret = max(ret, LIS(pos));


}