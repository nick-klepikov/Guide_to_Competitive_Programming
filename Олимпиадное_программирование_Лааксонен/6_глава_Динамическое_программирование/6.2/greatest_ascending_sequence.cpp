#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

#define INF numeric_limits<int>::max()
#define MININF numeric_limits<int>::min()

//Решение O(n^2) (Только нахождение длины максимальной последовательности)
int find_max_siq_1(int n, int array[]){
    int length[n], m = 0;
    for(int k = 0; k < n; k++){
        length[k] = 1;
        for(int i = 0; i < k; i++){
            if(array[i] < array[k]){
                length[k] = max(length[k], length[i]+1);
                if(length[k] > m) m = length[k];
            }
        }
    }
    return m;
}

//Решение 0(n log n) (С выводом самой последовательности)

void find_max_siq_2(int n, int array[n]){
    vector<int> d(n, INF), p(1), prev(n);
    d[0] = MININF, p[0] = -1; prev[0] = -1;
    for (int i=0; i<n; i++){
        int j = int(upper_bound(d.begin(), d.end(), array[i]) - d.begin());
        if(j > p.size()-1) p.push_back(-1);
        if(d[j-1] < array[i] && array[i] < d[j]){
            d[j] = array[i];
            p[j] = i;
            prev[i] = p[j-1];
        }
    }

    int len = (int)p.size()-1, cur = p[len];
    vector<int> resArr(len);
    while(len != 0){
        resArr[len-1] = array[cur];
        cur = prev[cur];
        len--;
    } ;
    for(auto i: resArr) cout << i << ' ';
}

int main(){
    int n = 8;
    int array[] = {6, 2,5, 1, 7,   4, 8, 3};

    find_max_siq_2(n, array);

}