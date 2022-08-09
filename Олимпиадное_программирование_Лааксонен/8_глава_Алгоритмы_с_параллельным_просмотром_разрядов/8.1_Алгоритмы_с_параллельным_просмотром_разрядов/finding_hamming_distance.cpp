#include <iostream>
#include <bitset>

using namespace std;

//Задача: дано n битовых строк длины k, вычислить минимальное расстояние Хэмминга между двумя строками.

//Алгоритм "в лоб" с временной сложностью O(n^2*k)
/*
int hamming(string a, string b) {
     int d = 0;
     for (int i = 0; i < k; i++) {
        if (a[i] != b[i]) d++;
     }
     return d;
}
 */

//Но поскольку строки состоят из бит, решение можно оптимизировать,
//если хранить строки в виде целых чисел и вычислять расстояние между
//ними с помощью поразрядных операций:

int hamming(int a, int b){
    return __builtin_popcount(a^b);
}

int main(){
    string a = "01010"; bitset<16> fir(a);
    string b = "11111"; bitset<16> sec(b);

    cout << hamming(fir.to_ulong(), sec.to_ullong());
}
