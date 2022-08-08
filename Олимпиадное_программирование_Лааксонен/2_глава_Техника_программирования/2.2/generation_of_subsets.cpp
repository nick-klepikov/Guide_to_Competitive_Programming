#include <iostream>
#include <vector>
using namespace std;

vector <int> subset;
vector <vector<int>> res;
const int n = 3;

//В качестве первого применения рекурсии рассмотрим порождение всех
//подмножеств множества из n элементов. Например, подмножествами
//{1, 2, 3} являются 0, {1}, {2}, {3}, {1, 2}, {1, 3}, {2, 3} и {1, 2, 3}.
// Следующая рекурсивная функция search генерирует подмножества.

void search(int k){
    if(k == n+1){
        res.push_back(subset);
        return;
    } else {
        subset.push_back(k);
        search(k+1);
        subset.pop_back();
        search(k+1);
    }
}

int main(){
    search(1);
    for(int i = 0; i < (int)res.size(); i++) {
        for (int j = 0; j < (int) res[i].size(); j++) {
            cout << res[i][j];
        }
        cout << '\n';
    }
}
