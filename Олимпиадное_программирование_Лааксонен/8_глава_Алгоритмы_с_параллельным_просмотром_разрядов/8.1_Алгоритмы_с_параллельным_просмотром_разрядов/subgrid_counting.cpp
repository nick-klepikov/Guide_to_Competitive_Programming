#include <iostream>
#include <vector>

using namespace std;

int n = 5;

//Представление сетки для первого алгоритма
vector<vector<int>> colors = {{0, 1, 0, 0, 1},
                              {0, 1, 1, 0, 0},
                              {1, 0, 0, 0, 0},
                              {0, 1, 1, 0, 1},
                              {0, 0, 0, 0, 0}};

//Представление сетки для алгоритма с параллельныи просмотром рарзрядов
vector<string> row = { "01001",
                       "01100",
                       "10000",
                       "01101",
                       "00000"};

//Функция для первого алгоритма
int countVars(int a, int b){
    int count = 0;
    for(int i = 0; i < n; i++){
        if(colors[a][i] == 1 && colors[b][i] == 1) count++;
    }
    return count + count*(count-1)/2;

}

//Функция для алгоритма с параллельным просмотром разрядов
int countVarsOptim(int a, int b){
    bitset<16> fir(row[a]);
    bitset<16> sec(row[b]);
    int count = __builtin_popcount(fir.to_ulong() & sec.to_ulong());
    return count + count*(count-1)/2;
}

int main(){
    int cnt = 0;

    //Алгоритм со временем выполнения O(n^3)
//    for(int i = 0; i < n; i++){
//        for(int j = i+1; j < n; j++){
//            cnt += countVars(i, j);
//        }
//     }

    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            cnt += countVarsOptim(i, j);
        }
     }

    cout << cnt;
}