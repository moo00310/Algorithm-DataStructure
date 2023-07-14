#include <iostream>
#include <Vector>
using namespace std;

//�ؽ����̺�

//Q) map vs hash_map (C++11 ǥ�� unordered_map)
// 
//-> map�� �����Ʈ�� ��������Ʈ���� �̷�����־� 
//Ʈ�������� �����ϰ� �����Ͱ� ������ ������ ���� �������ν򸮴°� ���� ���̴�. �ð����⵵�� O(logN)�� ������.
//hashmap�� �޸𸮸� ���ְ� �ӵ��� �������� ������� �ӵ����� ���鿡���� Hashmap�� ������.
//�ؽ��˰����� ���� ���� Ű���� �浹�� ���� �ʴ´ٰ� �����ϸ� O(1)�� ������.

//map : Red-Black Tree
// - �߰� / Ž�� / ����  O(logN)

//C# dictionary = C++ map (x)
//C# dictionary = C++ unordered_map

//Hash_map (unordered_map)
// - �߰� / Ž�� / ���� O(1)

//�޸𸮸� ���ְ� �ӵ��� ����
// ����Ʈ ������
// 
//[201][202][203][204][205]
//[101][102][103][104][105]

//1~999 user(userId =1~999)
//[1][2][3][][][][][] ... [999]

//'�ؽ�' '�׾ƺ�'
void TestTable() //O(1)
{
	struct User
	{
		int userId = 0;
		string username;
	};

	vector<User> users;
	users.resize(1000);

	//777�� ���� ���� ����
	users[777] = User{ 777, "asd" };

	//777�� ���� �̸���?
	string name = users[777].username;
	cout << name << endl;

	//���̺�
	//Ű�� �˸�, �����͸� �ܹ��� ã�� �� �ִ�.

	//������
	//int32_max (3��~) �̻��̶��?
}

//����
//id:asd + pw:1234
//id:asd + pw:Hash(1234) -> abteqwdcq!@#4113

//DB [asd][abteqwdcq!@#4113]
//��й�ȣ ã�� -> ���̵� �Է� / ������ -> �� ��й�ȣ �Է�

void TestHash()
{
	struct User
	{
		int userId = 0; //1~int32_max
		string username;
	};

	//[][][][][][]

	vector<User> users;
	users.resize(1000);

	const int userId = 123456789;
	int key = (userId % 1000);  // hash < ������ȣ

	//123456789�� ���� ���� ����
	users[key] = User{ userId, "asd" };

	//123456789�� ���� �̸���?
	User& user = users[key];
	if (user.userId == userId)
	{
		string name = user.username;
		cout << name << endl;
	}
	
	//�浹 ���� (Ű���� ��ġ�� ��Ȳ)
	//�浹�� �߻��� �ڸ��� ����ؼ� �ٸ� ���ڸ��� ã�� ���
	// - ��������� (linear probing)
	//   hash(key)+1 -> hash(key)+2
	// - ���� ����� (quadratic probing)
	//   hash(key)+1^2 -> hash(key)+2^2
	// - etc

	//ü�̴�
}

void HashTableChaining() //O(1)
{
	struct User
	{
		int userId = 0; //1~int32_max
		string username;
	};

	vector<vector<User>> users;
	users.resize(1000);

	const int userId = 123456789;
	int key = (userId % 1000);  // hash < ������ȣ

	users[key].push_back(User{ userId, "asd" }); //������ Ű���� ���͵� ���δ�.
	users[789].push_back(User{ 789, "Faker" });

	//123456789 ���� �̸���?
	vector<User>& bucket = users[key];
	for (User& user : bucket) //���� ��Ŷ�� ��ȸ
	{
		if (user.userId == userId)
		{
			string name = user.username;
			cout << name << endl;
		}
	}
}

int main()
{
	//TestTable();
	//TestHash();
	HashTableChaining();
}