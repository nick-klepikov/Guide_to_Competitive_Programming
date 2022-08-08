#include <iostream>
#include <vector>
#include <limits>

#define INF numeric_limits<int>::max()

using namespace std;

//Алгоритм применим к любым графам, не содержащим цикла с отрицательной длиной

//Предполагается, что граф представлен списком ребер, содержащим кортежи вида (a,b,w);

int main(){
    vector<tuple<int,int,int>> edges;
    int n = 5, dist[n+1], x = 1; //x - начальная вершина графа. n - кол-во вершин
    edges.push_back({1, 2, 2});
    edges.push_back({1, 3, 3});
    edges.push_back({1, 4, 7});
    edges.push_back({2, 5, 5});
    edges.push_back({3, 4, -2});
    edges.push_back({4, 5, 2});

    for(int i = 1; i <= n; i++){
        dist[i] = INF;
    }
    dist[x] = 0;
    for(int i = 1; i <= n-1; i++){
        //Алгоритм можно улучшить, добавив код для остановки цикла, при условии,
        // что за раунд не удалось уменьшить не одно расстояние
        for(auto e: edges){
            int a, b, w;
            tie(a, b, w) = e;
            dist[b] = min(dist[b], dist[a] + w);
        }
    }
    cout << dist[5];
}