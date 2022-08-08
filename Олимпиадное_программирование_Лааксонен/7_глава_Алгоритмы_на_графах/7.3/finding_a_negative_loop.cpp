#include <iostream>
#include <vector>
#include <limits>

#define INF numeric_limits<int>::max()

using namespace std;

//Алгоритм реализован с использованием алгоритма Беллмана-Форда

int main(){
        vector<tuple<int,int,int>> edges;
        bool hasNegativeLoop = false;
        int n = 4, dist[n+1], x = 1; //x - начальная вершина графа. n - кол-во вершин
        edges.push_back({1, 2, 3});
        edges.push_back({1, 3, 5});
        edges.push_back({2, 1, 3});
        edges.push_back({3, 1, 5});
        edges.push_back({2, 4, 1});
        edges.push_back({3, 4, -7});
        edges.push_back({4, 2, 1});
        edges.push_back({4, 3, -7});

        for(int i = 1; i <= n; i++){
            dist[i] = INF;
        }

        dist[x] = 0;
        for(int i = 1; i <= n; i++){
            for(auto e: edges){
                int a, b, w;
                tie(a, b, w) = e;
                if(i == n && dist[b] > dist[a] + w){
                    hasNegativeLoop = true;
                    break;
                }
                dist[b] = min(dist[b], dist[a] + w);
            }
        }
        cout << hasNegativeLoop;
}