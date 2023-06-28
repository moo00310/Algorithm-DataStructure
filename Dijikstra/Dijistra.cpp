#include <iostream>
#include <vector>
#include <queue>
#include <list>
using namespace std;

//인접한 노드중 누적 값이 적은 순서로 길을 찾는 알고리즘
//시작점을 기준으로 길을 찾되 목적지는 정하지 않음

struct Vertex
{
    //int data

};

vector<Vertex> vertices;
vector<vector<int>> adjacent;

void CreateGraph()
{
    vertices.resize(6);

    adjacent = vector<vector<int>>(6, vector<int>(6, -1));

    // -1 15 -1 35 -1 -1
    // 15 -1 5 10 -1 -1
    // -1 -1 -1 -1 -1 -1
    // -1 -1 -1 -1 5 -1
    // -1 -1 -1 -1 -1 -1
    // -1 -1 -1 -1 5 -1

    adjacent[0][1] = 15;
    adjacent[0][3] = 35;

    adjacent[1][0] = 15;
    adjacent[1][2] = 5;
    adjacent[1][3] = 10;

    adjacent[3][4] = 5;
    adjacent[5][4] = 5;

}

void Dijistra(int here)
{
    struct VertexCost
    {
        int vertex;
        int cost;
    };
    //std::pair<int, int>로 해도 됨

    list<VertexCost> discovered; //발견목록
    vector<int> best(6, INT32_MAX); //각 정점별로 지금까지 발견한 최소 거리
    vector<int> parent(6, -1);

    discovered.push_back(VertexCost{ here, 0 });
    best[here] = 0;
    parent[here] = here;

    while (discovered.empty()== false)  //while문과 for문 두개 때문에 느림
    {
        //제일 좋은 후보를 찾는다.
        list<VertexCost>::iterator bestIt; //모든애들을 모두 검사하는 방식대신 "우선순위 큐"를 이용하는게 빠르다.
        int bestCost = INT32_MAX;

        for (auto it = discovered.begin(); it != discovered.end(); it++)
        {
            if (it->cost < bestCost)
            {
                bestCost = it->cost;
                bestIt = it;
            }
        }

        int cost = bestIt->cost;
        here = bestIt->vertex;
        discovered.erase(bestIt);


        //더 짧은 경로를 뒤는게 찾았다면 스킵.
        if (best[here] < cost)
            continue;

        for (int there = 0; there < 6; there++)
        {
            //연결되지 않았다면 스킵
            if (adjacent[here][there] == -1)
                continue;

            //더좋은 경로를 과거에 찾았다면 스킵
            int nextCost = best[here] + adjacent[here][there];
            if (nextCost >= best[there])
                continue;

            discovered.push_back(VertexCost{ there, nextCost });
            best[there] = nextCost;
            parent[there] = here; 
        }

    }

}



int main()
{
    CreateGraph();

    Dijistra(0);

}