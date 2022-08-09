#include <iostream>
#include <vector>

using namespace std;
//Алгоритм для поиска мин. остовных деревьев, но можнл модифицировать для поиск макс.

//В алгоритме используется union-find_structure

//Графы представлены списком ребер

const int n = 6;

vector<tuple<int, int, int>> edges;

int link[n+1], size[n+1];

int find(int x) {
    while (x != link[x]) x = link[x];
    return x;
}

bool same(int a, int b){
    return find(a) == find(b);
}

void unite(int a, int b){
    a = find(a);
    b = find(b);
    if(size[a] < size[b]) swap(a, b);
    size[a] += size[b];
    link[b] = a;
}

//кортежи вида (w, a, b), где w - вес ребра

int main(){

    int minWeig = 0;

    edges.push_back({3, 1, 2});
    edges.push_back({5, 1, 5});
    edges.push_back({6, 2, 5});
    edges.push_back({5, 2, 3});
    edges.push_back({9, 3, 4});
    edges.push_back({3, 3, 6});
    edges.push_back({7, 4, 6});
    edges.push_back({2, 5, 6});

    sort(edges.begin(), edges.end());
    for(int i = 1; i <= n; i++) link[i] = i;
    for(int i = 1; i <= n; i++) size[i] = 1;

    for(auto el: edges){
        if(!same(get<1>(el), get<2>(el))){
            unite(get<1>(el), get<2>(el));
            minWeig += get<0>(el);
        }
    }
    cout << minWeig;
}