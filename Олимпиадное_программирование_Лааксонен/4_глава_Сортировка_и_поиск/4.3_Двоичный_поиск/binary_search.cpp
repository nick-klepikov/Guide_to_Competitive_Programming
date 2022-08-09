#include <iostream>

using namespace std;

int bin_search_fir(int array[], int n, int x){
    int a = 0, b = n - 1;
    while(a <= b){
        int k = (a+b)/2;
        if(array[k] == x) return k;
        if(array[k] < x) a = k+1;
        else b = k - 1;
    }
    return -1;
}

int bin_search_sec(int array[], int n, int x){
    int k = 0;
    for(int b = n/2; b >= 1; b/=2){
        while(k+b < n && array[k+b] <= x) k += b;
    }
    if(array[k] == x) return k;
    return -1;
}

int main(){
    int array[] = {1, 3, 3, 4, 5, 5, 6, 9, 10, 12, 12, 15};
    int n = 12, x = 5;
    //1 вариант
    cout << bin_search_fir(array, n, x) << '\n';
    //2 вариант(просмотр массива слева направо, с совершением прыжков)
    cout << bin_search_sec(array, n, x);
}
