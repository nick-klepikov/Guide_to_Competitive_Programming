#include <iostream>
#include <queue>
#include <vector>
#include <limits>

#define INF numeric_limits<int>::max()

using namespace std;

//Алгоритм применим для графов без отрицательных весов

//Для эффективной реализации алгоритма Дейкстры необходимо эффективно находить еще не обработанную вершину, отстоящую
//на минимальное расстояние. Для этого подойдет очередь с приоритетом,
//в которой оставшиеся вершины хранятся, упорядоченные по возрастанию
//расстояния.

//Граф представлен в виде списков смежности, так что adj[a] содержит пары (b, w)

int main(){
    int N = 5;
    vector<pair<int, int>> adj[N+1];
    adj[1].push_back({2, 5});
    adj[1].push_back({4, 9});
    adj[1].push_back({5, 1});
    adj[2].push_back({3, 2});
    adj[5].push_back({4, 2});
    adj[4].push_back({3, 6});

    priority_queue<pair<int, int>> q;
    //Очередь с приоритетом содержит пары вида (−d, x), означающие, что текущее расстояние до вершины x равно d.

    //В очереди хранятся расстояния со знаком минус, так как реализация очереди из библиотеки находит максимальный элемент,
    //а нам нужен минимальный

    //Также в очереди может находиться несколько экземпляров вершины,
    // но обработан будет только тот экземпляр, в котором расстояние минимально.

    int distance[N+1], x = 1;
    bool processed[N+1];
    // Массив distance содержит расстояния до всех вершин, а
    //массив processed позволяет узнать, была ли вершина обработана, x - начальная вершина
    for(int i = 1; i <= N;i++){
        processed[i] = false;
        distance[i] = INF;
    }
    distance[x] = 0;
    q.push({0, x});
    while(!q.empty()){
        int a = q.top().second; q.pop();
        if(processed[a]) continue;
        processed[a] = true;
        for(auto u: adj[a]){
            int b = u.first, w = u.second;
            if(distance[a] + w < distance[b]){
                distance[b] = distance[a] + w;
                q.push({-distance[b], b});
            }
        }
    }
    cout << distance[3];
}