#include <iostream>
#include <vector>

using namespace std;

int main() {
    const int n = 5;
    int sum[n][n], value[n][n] = {{3, 7, 9, 2, 7}, {9, 8, 3, 5, 5}, {1, 7, 9, 8, 5}, {3, 8, 6, 4, 10}, {6, 3, 9, 7, 8}};
    sum[0][0] = value[0][0];
    for(int y = 0; y < n; y++){
        for(int x = 0; x < n; x++){
            if(y == 0 && x == 0) continue;
            if(y == 0) sum[y][x] = sum[y][x-1] + value[y][x];
            else if(x == 0) sum[y][x] = sum[y-1][x] + value[y][x];
            else sum[y][x] = max(sum[y-1][x], sum[y][x-1]) + value[y][x];
        }
    }
    cout << sum[n-1][n-1];
}