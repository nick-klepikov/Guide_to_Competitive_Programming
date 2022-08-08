#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n = 8, best = 0, sum = 0;
    vector<int> array = {-1, 2, 4, -3, 5, 2, -5, 2};
    for(int i = 0; i < n; i++){
        sum = max(array[i], sum+array[i]);
        best = max(sum, best);
    }
    cout << best;
}