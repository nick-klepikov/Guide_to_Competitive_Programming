#include <iostream>
#include <vector>

using namespace std;

//Работает только если в массиве неотрицательные элементы

int main(){
    vector<int> arr = {1, 3, 6, 9, 9, 3, 5, 9}, extraArr, res;
    int max = 0, curInd = 0;
    for(int i: arr){
        if(i > max) max = i;
    }
    extraArr.resize(max+1, 0);
    for(int i: arr) extraArr[i]++;
    while(curInd != extraArr.size()){
        if(extraArr[curInd] > 0){
            res.push_back(curInd);
            extraArr[curInd]--;
        }
        else curInd++;
    }
    for(int i: res) cout << i << ' ';
}