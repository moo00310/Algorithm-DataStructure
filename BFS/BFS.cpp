#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Vertex
{
    //int data
};

vector<Vertex> vertices;
vector<vector<int>> adjacent;
vector<bool> discovered;

void CreateGraph()
{
    vertices.resize(6);

    vertices.resize(6);
    adjacent = vector<vector<int>>(6);
    
    adjacent[0].push_back(1);
    adjacent[0].push_back(3);

    adjacent[1].push_back(0);
    adjacent[1].push_back(2);
    adjacent[1].push_back(3);

    adjacent[3].push_back(4);
    adjacent[5].push_back(4);
    
}

void Bfs(int here)
{
    //누구에의해 발견되었는지
    vector<int> parent(6, -1);
    //시작점에서 얼마나 떨어져 있는지
    vector<int> distance(6, -1);

    queue<int> q;
    q.push(here);
    discovered[here] = true;

    parent[here] = here;
    distance[here] = 0;

    while (q.empty() == false)
    {
        here = q.front();
        q.pop();

        cout << "Visited : " << here << endl;

        for (int there : adjacent[here])
        {
            if (discovered[there])
                continue;

            q.push(there);
            discovered[there] = true;

            parent[there] = here;
            distance[there] = distance[here] + 1;
        }

    }

}

void BfsAlll()
{
    for (int i = 0; i < 6; i++)
    {
        if (discovered[i] == false)
            Bfs(i);
    }
}

int main()
{
    CreateGraph();

    discovered = vector<bool>(6, false);

    BfsAlll();

}