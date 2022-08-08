#include <iostream>
#include <vector>
using namespace std;

int main(){
    //weights - [1, 3, 3, 5] -> total is 12, possible taken counts of weights are [], [1], [1, 3], [1, 3, 3], [1, 3, 3, 5]
    int w[] = {0, 1, 3, 3, 5};
    int n = 4, m = 12;
    /*1 способ с двумерным массивом
    vector<vector<int>> possible(m+1, vector<int>(n+1));
    possible[0][0] = true;
    for(int k = 1; k <= n; k++){
        for(int x = 0; x <= m; x++){
            if(x-w[k] >= 0){
                possible[x][k] |= possible[x-w[k]][k-1];
            }
            possible[x][k] |= possible[x][k-1];
        }
    }

    Вывод
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            cout << possible[j][i] << ' ';
        }
        cout << '\n';
    }
     */

    //2 способ с одномерным
    vector<int> possible(m+1);
    possible[0] = true;
    for(int k = 1; k <= n; k++){
        for(int x = m-w[k]; x >= 0; x--){
            possible[x+w[k]] |= possible[x];
        }
    }
    for(auto i : possible){
        cout << i << ' ';
    }

}