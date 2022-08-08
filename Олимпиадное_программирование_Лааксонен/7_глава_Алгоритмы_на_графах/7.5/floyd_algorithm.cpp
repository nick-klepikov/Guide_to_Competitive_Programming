#include <iostream>
#include <vector>

using namespace std;

int N = 6;
vector<int> adj(N+1);

//Этот алгоритм позволяет обнаружить цикл в графе преемников за время O(n) и затраты памяти O(1)
//Он проходит по графу и использует два указателя a и b. Вначале оба указывают на начальную вершину x.
// На каждой итерации a сдвигается вперед на один шаг, а b – на два
//шага. Процесс продолжается, пока оба указателя не встретятся

int succ(int x){
    return adj[x];
}

int main(){
    int x = 1; //Начальная вершина

    adj[1] = 2;
    adj[2] = 3;
    adj[3] = 4;
    adj[4] = 5;
    adj[5] = 6;
    adj[6] = 4;

    int a = succ(x), b = succ(a);
    while(a != b){
        a = succ(a);
        b = succ(succ(b));
    }
    //Нахождение первой вершины цикла
    a = x;
    while(a != b){
        a = succ(a);
        b = succ(b);
    }
    int first = a;

    //Нахождение длины цикла
    int length = 1;
    b = succ(a);
    while(a != b){
        b = succ(b);
        length++;
    }
    cout << first << ' ' << length;
}
