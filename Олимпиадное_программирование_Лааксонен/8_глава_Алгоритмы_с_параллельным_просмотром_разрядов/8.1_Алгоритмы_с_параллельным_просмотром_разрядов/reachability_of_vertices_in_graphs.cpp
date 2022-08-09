#include <iostream>
#include <vector>

using namespace std;

const int n = 5;
vector<int> reachArr(n+1), adj[n+1];


int reach(int x){ //Функция для нахождение достигаемых из вершины x вершин
    return __builtin_popcount(reachArr[x]);
}

//Алгоритм за O(n^2)

//Но при больших n алгоритм потребляет очень много памяти. Во многих соревнованиях объем памяти не
//превышает 512 Мб.

int main(){
    adj[2].push_back(1);
    adj[3].push_back(1);
    adj[4].push_back(2);
    adj[4].push_back(3);
    adj[5].push_back(2);
    adj[5].push_back(4);

    for(int i = 5; i >= 1; i--){
        reachArr[i] |= (1 << i);
        for(auto el: adj[i]){
            reachArr[el] |= reachArr[i];
        }
    }
    cout << reach(1);
}