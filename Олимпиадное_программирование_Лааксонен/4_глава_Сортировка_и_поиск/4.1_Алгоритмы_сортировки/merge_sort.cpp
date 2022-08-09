#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &arr){
    if(arr.size() == 1) return;

    int k = arr.size()/2, curFir = 0, curSec = 0;
    vector<int> first, second, res;
    for(int i = 0; i < (int)arr.size(); i++){
        if(i < k) first.push_back(arr[i]);
        else second.push_back(arr[i]);
    }

    merge(first);
    merge(second);

    while(curFir != first.size() && curSec != second.size()){
        if(first[curFir] > second[curSec]) {
            res.push_back(second[curSec]);
            curSec++;
        } else {
            res.push_back(first[curFir]);
            curFir++;
        }
    }
    if(curFir == first.size()) for(int i = curSec; i < second.size(); i++) res.push_back(second[i]);
    else if(curSec == second.size()) for(int i = curFir; i < first.size(); i++) res.push_back(first[i]);

    arr = res;
}

int main(){
    vector<int> arr = {1, 3, 6, 2, 8, 2, 5, 9};
    merge(arr);
    for(auto el: arr) cout << el << ' ';
}