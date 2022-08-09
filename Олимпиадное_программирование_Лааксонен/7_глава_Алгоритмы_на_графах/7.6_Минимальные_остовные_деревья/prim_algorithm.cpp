#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int n = 6;
vector<tuple<int, int, int>> adj[n+1]; //Содержит пары вида (-w, -b, a) - где w - вес ребра, a - вершина из которой ИСХОДИТ ребро
// w и b отрицательны, так как реализация из библоитеки находит наибольший элемент, а нам нужен наименьший


//Для работы необходимо, чтобы граф был неориентированным(т.е. на каждое ребро записывается в обе вершины

int main() {


    adj[1].push_back({3, 2, 1});
    adj[1].push_back({5, 5, 1});
    adj[2].push_back({3, 1, 2});
    adj[2].push_back({5, 3, 2});
    adj[2].push_back({6, 5, 2});
    adj[3].push_back({5, 2, 3});
    adj[3].push_back({9, 4, 3});
    adj[3].push_back({3, 6, 3});
    adj[4].push_back({9, 3, 4});
    adj[4].push_back({7, 6, 4});
    adj[5].push_back({5, 1, 5});
    adj[5].push_back({6, 2, 5});
    adj[5].push_back({2, 6, 5});
    adj[6].push_back({3, 3, 6});
    adj[6].push_back({2, 5, 6});
    adj[6].push_back({7, 4, 6});


    priority_queue<tuple<int, int, int>> q;
    int x = 1, minWeig = 0, cur = x; //x - начальная вершина

    for(auto el: adj[x]){
            q.push({-get<0>(el), -get<1>(el), get<2>(el)});
    }
    bool inTree[n+1];
    for(int i = 1; i <= n; i++) inTree[i] = false;
    inTree[x] = true;

    while(!q.empty()){
        int w, a, b;
        tie(w, b,a) = q.top(); w = -w; b = -b; q.pop();
        if(inTree[b]) continue;
        inTree[b] = true;
        minWeig += w;
        for(auto el: adj[b]){
            q.push({-get<0>(el), -get<1>(el), get<2>(el)});
        }
    }
    cout << minWeig;
}
