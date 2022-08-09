#include <iostream>
#include <limits>

#define INF numeric_limits<int>::max()

using namespace std;

const int n = 10, coins[] = {1, 3, 4};
int value[n];

//Реализация с запоминанием
bool ready[n];
int solve(int x){
    if(x < 0) return INF;
    if(x == 0) return 0;
    if(ready[x]) return value[x];
    int best = INF;
    for(auto c: coins){
        best = min(best, solve(x-c)+1);
    }
    ready[x] = true;
    value[x] = best;
    return best;
}

//Реализация с итеративным заполнением value
int iter_solve(int x){
    if(x < 0) return INF;
    value[0] = 0;
    for(int i = 1; i <= x; i++){
        value[i] = INF;
        for(auto c: coins){
            if(i-c >= 0){
                value[i] = min(value[i], value[i-c]+1);
            }
        }
    }
    return value[x];
}


//Построение решения
void solution_building(int n){
    int first[n];
    value[0] = 0;
    for(int x = 1; x <= n; x++){
        value[x] = INF;
        for(auto c: coins){
            if(x-c >= 0 && value[x-c]+1 < value[x]){
                value[x] = value[x-c]+1;
                first[x] = c;
            }
        }
    }
    int copy = n;
    while (copy > 0) {
        cout << first[copy] << "\n";
        copy -= first[copy];
    }
}

//Подсчет количества решений по модулю 1e9+7
int count_solutions(int x){
    int count[x+1];
    count[0] = 1;
    for(int i = 1; i <= x; i++){
        count[i] = 0;
        for(auto c: coins){
            if(i-c >= 0){
                count[i] += count[i-c] % int(1e9+7);
            }
        }
    }
    for(auto el: count) cout << el << ' ';
}



int main(){
     count_solutions(n);
}