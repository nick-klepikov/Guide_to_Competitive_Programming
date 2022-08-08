#include <iostream>
#include <queue>
#include <vector>

using namespace std;

//В приведенном ниже коде предполагается, что граф представлен списками смежности
const int N = 5;
vector<int> adj[N];
queue<int> q;
bool visited[N];
int dist[N]; //Хранится информация о расстоянии от начальной вершины графа до всех остальных

int main(){
    //x - начальная вершина
    int x = 1;
    visited[x] = true;
    dist[x] = 0;
    q.push(x);
    while(!q.empty()){
        int s = q.front(); q.pop();
        //Обработать вершину s
        for(auto u: adj[s]){
            if(visited[u]) continue;
            visited[u] = true;
            dist[u] = dist[s] + 1;
            q.push(u);
        }
    }
}