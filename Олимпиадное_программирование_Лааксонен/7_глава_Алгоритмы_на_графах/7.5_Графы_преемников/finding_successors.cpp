#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

//У графов преемников есть всего лишь один преемник(их также иногда называют функциональными графами)
//Граф преемников состоит из одной или нескольких компонент связности. Каждая компонента
//содержит один цикл, в который могут вести несколько путей.

const int N = 9;
vector<vector<int>> process(N+1, vector<int>(11));
vector<int> adj(N+1);

int succ(int x, int k) { //x - начальная вершина, k - кол-во вершин
    //Найти значение можно и "в лоб" за время O(k), но усовершенствуем алгоритм до времени O(log k),
    // c некоторой предварительной обработкой
    //О ней подробнее можно узнать в книге, здесь сам код
    if(k == 1) {
        if(!process[x][k]) process[x][k] = adj[x];
        return process[x][k];
    }
    if(!process[x][k]) process[x][k] = succ(process[x][k/2], k/2);
    return process[x][k];
}

int main(){
    int k = 11;

    adj[1] = 3;
    adj[2] = 5;
    adj[3] = 7;
    adj[4] = 6;
    adj[5] = 2;
    adj[6] = 2;
    adj[7] = 1;
    adj[8] = 6;
    adj[9] = 3;
    //Предварительная обработка
    for(int i = 1; i <= N; i++){
        for(int j = 0; j <= log2(k); j++){
            succ(i, int(pow(2, j)));
        }
    }

    //Нахождение преемника через k шагов
    int x = 4, curSuc = x;
    while(k != 0){
        int temp =  pow(2, (int)log2(k));
        curSuc = succ(curSuc, temp);
        k -= temp;
    }
    cout << curSuc;
}
