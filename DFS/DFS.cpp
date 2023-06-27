#include <iostream>
#include <vector>
using namespace std;

struct Vertex
{
 //int data
};

vector <Vertex> vertices;
vector <vector<int>> adjecent; //이차 벡터
vector <bool> visited;

void CreateGraph()
{
    vertices.resize(6);
    adjecent = vector<vector<int>>(6);

    //인접 리스트.ver
    //adjecent[0] = { 1, 3 };
    /*
    adjecent[0].push_back(1);
    adjecent[0].push_back(3);

    adjecent[1].push_back(0);
    adjecent[1].push_back(2);
    adjecent[1].push_back(3);

    adjecent[3].push_back(4);
    adjecent[5].push_back(4); 
    */

    //인접 행렬.ver
    adjecent = vector<vector<int>>
    {
        {0, 1, 0, 1, 0, 0},
        {1, 0, 1, 1, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0},
    };

    //방문검사
    visited = vector<bool>(6, false);
}

void Dfs(int here) 
{
    visited[here] = true;
    cout << "Visited: " << here << endl;

    //인접 리스트.ver
    /*
    for (int i = 0; i < adjecent[here].size(); i++)
    {
        int there = adjecent[here][i];
        if (visited[there] == false)
        {
            Dfs(there); //재귀함수 활용
        }
    }
    */

    //인접행렬.ver
    for (int there = 0; there < 6; there++)
    {
        if (adjecent[here][there] == 0)
            continue;
        //방문하지 않은 곳이있으면 방문
        if (visited[there] == false)
            Dfs(there);
    }
}

void DfsAll() //끊어진 노드 까지 모두 검사
{
    for (int i = 0; i < 6; i++)
    {
        if (visited[i] == false)
            Dfs(i);
    }
}

int main()
{
    CreateGraph();

    DfsAll();
}