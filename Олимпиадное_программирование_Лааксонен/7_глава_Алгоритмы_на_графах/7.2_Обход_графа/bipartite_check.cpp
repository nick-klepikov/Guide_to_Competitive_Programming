#include <iostream>
#include <vector>

using namespace std;

const int N = 5;
vector<int> adj[N];
bool visited[N];

char colors[N];
int x = 1; //Начальная вершина
bool isBipartite = true;

void biparite_check(int s){
    if(visited[s]) return;
    visited[s] = true;
    for(auto u: adj[s]){
        if(!visited[u]) colors[u] = colors[s] == 'R' ? 'B' : 'R';
        if(colors[u] == colors[s]){
            isBipartite = false;
            return;
        }
        biparite_check(u);
    }
}

int main(){
    colors[x] = 'R'; //Установка значения цвета начальной вершины

    //Создание графа
    adj[1].push_back(2);
    adj[2].push_back(3);
    adj[2].push_back(4);
    adj[3].push_back(4);
    adj[4].push_back(1);

    biparite_check(x);
    cout << isBipartite;
}
