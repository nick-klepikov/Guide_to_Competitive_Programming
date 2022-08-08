#include <iostream>
#include <vector>

using namespace std;
//1 вариант
const int n = 3;
vector<int> permutation;
vector<vector<int>> res1, res2;
bool chosen[n+1];

void search1(){
    if(permutation.size() == n){
        res1.push_back(permutation);
        return;
    } else {
        for(int i = 1; i <= n; i++){
            if(chosen[i]) continue;
            chosen[i] = true;
            permutation.push_back(i);
            search1();
            chosen[i] = false;
            permutation.pop_back();
        }
    }
}

//2 вариант со встроенной next_permutation

void search2(){
    permutation.clear();
    for(int i = 1; i <= n; i++) permutation.push_back(i);
    do{
        res2.push_back(permutation);
    } while(next_permutation(permutation.begin(), permutation.end()));
}


int main(){
    search1();
    for(auto i : res1){
        for(auto el: i) cout << el;
        cout << '\n';
    }
    cout << '\n';
    search2();
    for(auto i : res2){
        for(auto el: i) cout << el;
        cout << '\n';
    }
}