#include <iostream>
#include <vector>

using namespace std;

const int N = 6;
int start, ending, counts[N+1];
vector<int> adj[N+1];


int pathsFromAToB(int x){
    if(x == start) return 1;
    int count = 0;
    for(auto u: adj[x]){
        if(!counts[u]) counts[u] = pathsFromAToB(u);
        count += counts[u];
    }
    return count;
}

int main(){
    start = 1, ending = 6;

    //Граф будем предствлять в виде списков смежности, в каждом из которых хранятся вершины, ВХОДЯЩИЕ в нынешнюю
    adj[2].push_back(1);
    adj[2].push_back(5);
    adj[3].push_back(2);
    adj[4].push_back(1);
    adj[5].push_back(4);
    adj[6].push_back(2);
    adj[6].push_back(3);

    cout << pathsFromAToB(ending) << '\n';
}