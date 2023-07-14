#include <iostream>
#include <Vector>
using namespace std;

//해쉬테이블

//Q) map vs hash_map (C++11 표준 unordered_map)
// 
//-> map은 레드블랙트리 균형이진트리로 이루어져있어 
//트리구조로 관리하고 데이터가 들어오면 군형을 맞춰 한쪽으로쏠리는걸 막는 것이다. 시간복잡도는 O(logN)을 따른다.
//hashmap은 메모리를 내주고 속도를 가져오는 방법으로 속도적인 측면에서는 Hashmap이 빠르다.
//해쉬알고리즘을 통해 나온 키값이 충돌이 되지 않는다고 가정하면 O(1)을 가진다.

//map : Red-Black Tree
// - 추가 / 탐색 / 삭제  O(logN)

//C# dictionary = C++ map (x)
//C# dictionary = C++ unordered_map

//Hash_map (unordered_map)
// - 추가 / 탐색 / 삭제 O(1)

//메모리를 내주고 속도를 취함
// 아파트 우편함
// 
//[201][202][203][204][205]
//[101][102][103][104][105]

//1~999 user(userId =1~999)
//[1][2][3][][][][][] ... [999]

//'해시' '테아블'
void TestTable() //O(1)
{
	struct User
	{
		int userId = 0;
		string username;
	};

	vector<User> users;
	users.resize(1000);

	//777번 유저 정보 세팅
	users[777] = User{ 777, "asd" };

	//777번 유저 이름은?
	string name = users[777].username;
	cout << name << endl;

	//테이블
	//키를 알면, 데이터를 단번에 찾을 수 있다.

	//문제점
	//int32_max (3억~) 이상이라면?
}

//보안
//id:asd + pw:1234
//id:asd + pw:Hash(1234) -> abteqwdcq!@#4113

//DB [asd][abteqwdcq!@#4113]
//비밀번호 찾기 -> 아이디 입력 / 폰인증 -> 새 비밀번호 입력

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
	int key = (userId % 1000);  // hash < 고유번호

	//123456789번 유저 정보 세팅
	users[key] = User{ userId, "asd" };

	//123456789번 유저 이름은?
	User& user = users[key];
	if (user.userId == userId)
	{
		string name = user.username;
		cout << name << endl;
	}
	
	//충돌 문제 (키값이 겹치는 상황)
	//충돌이 발생한 자리를 대신해서 다른 빈자리를 찾는 방법
	// - 선형조사법 (linear probing)
	//   hash(key)+1 -> hash(key)+2
	// - 이차 조사법 (quadratic probing)
	//   hash(key)+1^2 -> hash(key)+2^2
	// - etc

	//체이닝
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
	int key = (userId % 1000);  // hash < 고유번호

	users[key].push_back(User{ userId, "asd" }); //동일한 키값이 들어와도 쌓인다.
	users[789].push_back(User{ 789, "Faker" });

	//123456789 유저 이름은?
	vector<User>& bucket = users[key];
	for (User& user : bucket) //쌓인 버킷을 순회
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