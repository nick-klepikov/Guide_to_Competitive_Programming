#include <iostream>
#include <vector>

using namespace std;

//В приведенном ниже коде предполагается, что граф представлен списками смежности

const int N = 5;
vector<int> adj[N];
bool visited[N];

void dfs(int s){
    if(visited[s]) return;
    visited[s] = true;
    //как-либо обработать вершину s
    //Например
    cout << s << '\n';
    for(auto u: adj[s]){
        dfs(u);
    }

}

int main(){
    adj[1].push_back(2);
    adj[1].push_back(3);
    adj[2].push_back(3);
    dfs(1);
}