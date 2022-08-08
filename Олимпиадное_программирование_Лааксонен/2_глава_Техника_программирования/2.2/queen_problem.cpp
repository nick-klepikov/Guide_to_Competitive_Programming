#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int n = 8, cnt = 0;

vector<int> col(n), diag1(n*n), diag2(n*n);

void search(int y){
    if(y == n) {
        cnt++;
        return;
    }
    for(int x = 0; x < n; x++){
        if(col[x] || diag1[x+y] || diag2[x-y+n-1]) continue;
        col[x] = diag1[x+y] = diag2[x-y+n-1] = 1;
        search(y+1);
        col[x] = diag1[x+y] = diag2[x-y+n-1] = 0;
    }
}

int main(){
    search(0);
    cout << cnt;
}