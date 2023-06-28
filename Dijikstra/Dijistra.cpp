#include <iostream>
#include <vector>
#include <queue>
#include <list>
using namespace std;

//������ ����� ���� ���� ���� ������ ���� ã�� �˰���
//�������� �������� ���� ã�� �������� ������ ����

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
    //std::pair<int, int>�� �ص� ��

    list<VertexCost> discovered; //�߰߸��
    vector<int> best(6, INT32_MAX); //�� �������� ���ݱ��� �߰��� �ּ� �Ÿ�
    vector<int> parent(6, -1);

    discovered.push_back(VertexCost{ here, 0 });
    best[here] = 0;
    parent[here] = here;

    while (discovered.empty()== false)  //while���� for�� �ΰ� ������ ����
    {
        //���� ���� �ĺ��� ã�´�.
        list<VertexCost>::iterator bestIt; //���ֵ��� ��� �˻��ϴ� ��Ĵ�� "�켱���� ť"�� �̿��ϴ°� ������.
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


        //�� ª�� ��θ� �ڴ°� ã�Ҵٸ� ��ŵ.
        if (best[here] < cost)
            continue;

        for (int there = 0; there < 6; there++)
        {
            //������� �ʾҴٸ� ��ŵ
            if (adjacent[here][there] == -1)
                continue;

            //������ ��θ� ���ſ� ã�Ҵٸ� ��ŵ
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