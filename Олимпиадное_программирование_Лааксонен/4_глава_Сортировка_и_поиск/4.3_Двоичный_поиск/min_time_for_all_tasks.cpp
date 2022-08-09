#include <iostream>

using namespace std;

//k - count of tasks; n - count of computers; arrP - array of counts of time each computer need to finish one task

int k = 8, n = 3;
int arrP[] = {2, 3, 7};

bool valid(int time){
    int resTime = 0;
    for(int i: arrP) resTime += time / i;
    if(resTime >= k) return 1;
    return 0;
}

int min_valid_x(){
    int x = -1;
    for(int b = k; b >= 1; b/=2){
        while(!valid(x+b)) x += b;
    }
    return x+1;
}

int main(){
    cout << min_valid_x();
}
