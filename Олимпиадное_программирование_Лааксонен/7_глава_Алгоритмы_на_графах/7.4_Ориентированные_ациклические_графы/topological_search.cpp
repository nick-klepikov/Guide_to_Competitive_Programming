#include <iostream>
#include <vector>

using namespace std;

//поиск в глубину позволяет как
//проверить наличие циклов в ориентированном графе,
// так и построить топологическую сортировку, если циклов нет.

const int N = 6;
bool isLoop, visited[N+1];
vector<int> adj[N+1], topologOrder(N+1);
int processed[N+1], lastUnused = 1;

void dfs(int s){
    if(processed[s] == 1) isLoop = true;
    if(isLoop || visited[s]) return;
    visited[s] = true;
    processed[s] = 1;
    for(auto u: adj[s]){
        dfs(u);
    }
    processed[s] = 2;
    topologOrder[lastUnused++] = s;
}


int main(){
    adj[1].push_back(2);
    adj[2].push_back(3);
    adj[3].push_back(6);
    adj[4].push_back(1);
    adj[4].push_back(5);
    adj[5].push_back(2);
    adj[5].push_back(3);

    for(int i = 1; i <= N; i++){
        if(!processed[i]) dfs(i);
    }

    reverse(topologOrder.begin(), topologOrder.end());
    topologOrder.pop_back();

    if(!isLoop){
        for(auto el: topologOrder) cout << el << ' ';
    } else cout << "Loop!";
}