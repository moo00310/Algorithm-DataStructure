#include <iostream>
#include <vector>
#include <queue>
#include <list>
using namespace std;

//�׷��� / Ʈ�� ����
// �ּ� ���д� Ʈ��(Minimum Spanning Tree)

//��ȣ ��Ÿ�� ����(Disjoint Set)
// -> ���Ͽ� - ���ε� (Union-Find)

// Ʈ�� ������ �̿��� ��ȣ ��Ÿ�� ������ ǥ��
//[0] [1] [2] [3] [4] [5]

struct Node
{
	Node* leader;
};

//[1]	  [3]
//[2]   [4][5]
//           [0]

//�ð� ���⵵ : Ʈ���� ���̿� ����� �ð��� �ɸ�
struct NavieDisjointSet 
{
public:
	NavieDisjointSet(int n) : _parent(n)
	{
		for (int i = 0; i < n; i++)
			_parent[i] = i;
	}

	int Find(int u) //������ ����?
	{
		if (u == _parent[u])
			return u;

		return Find(_parent[u]);
	}

	void Merge(int u, int v)
	{
		u = Find(u);
		v = Find(v);

		if (u = v)
			return;

		_parent[u] = v;
	}

private:
	vector<int> _parent;
};

//Ʈ���� �������� ���� ���� �ذ�
//Ʈ���� ��ĥ��, �׻� [���̰� ���� Ʈ����][���̰� ���� Ʈ��] ������ ��ġ��
//(Union-By-Rank)

//�ð� ���⵵ : Ʈ���� ���̿� ����� �ð��� �ɸ�
//�ð� ���⵵ O(Ackermann(n)) = O(1)

struct DisjointSet 
{
public:
	DisjointSet(int n) : _parent(n), _rank(n, 1)
	{
		for (int i = 0; i < n; i++)
			_parent[i] = i;
	}

	int Find(int u) //������ ����?
	{
		if (u == _parent[u])
			return u;

		_parent[u] = Find(_parent[u]);
		return _parent[u];
	}

	void Merge(int u, int v) //u�� v�� ��ģ��(��)
	{
		u = Find(u);
		v = Find(v);

		if (u == v)
			return;
		
		if (_rank[u] > _rank[v])
			swap(u, v);

		//_rank[u] <= _rank[v] �����
		_parent[u] = v;
		
		//[1]	   [3]
		//[2]   [4][5][1]
		//[6]      [0][2]
		//            [6]

		if (_rank[u] == _rank[v]) //ũ�Ⱑ �ϳ� �þ
			_rank[v]++;
	}

private:
	vector<int> _parent;
	vector<int> _rank;
};


int main()
{
	DisjointSet teams(1000);

	teams.Merge(10, 1);
	int teamId1 = teams.Find(1);
	int teamId2 = teams.Find(10);

	teams.Merge(3, 2);
	int teamId3 = teams.Find(3);
	int teamId4 = teams.Find(2);

	teams.Merge(1, 3);
	int teamId6 = teams.Find(1);
	int teamId7 = teams.Find(3);
}