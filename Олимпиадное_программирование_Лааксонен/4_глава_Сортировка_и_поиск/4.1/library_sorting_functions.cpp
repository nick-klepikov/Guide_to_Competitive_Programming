#include <iostream>
#include <vector>
using namespace std;

//создание внешней функции сравнения
bool comp(string a, string b){
    if(a.length() == b.length()) return a < b;
    return a.length() < b.length();
}

int main(){
    //сортировка по возрастанию
    vector<int> v = {4, 2, 5, 3, 5, 8, 3};
    sort(v.begin(), v.end());

    //сортировка по убыванию
    sort(v.rbegin(), v.rend());

    //сортировка обычного массива
    int n = 7;
    int a[] = {4, 2, 5, 3, 5, 8, 3};
    sort(a, a+n);

    //сортировка строки(расположение символов в алфавитном порядке)
    string s = "monkey";
    sort(s.begin(), s.end());

    //сортировка пар
    vector<pair<int, int>> p;
    p.push_back({1, 5});
    p.push_back({2, 3});
    p.push_back({1, 2});
    sort(p.begin(), p.end());

    //сортировка кортежей
    vector<tuple<int, int, int>> t;
    t.push_back({2,1,4});
    t.push_back({1,5,3});
    t.push_back({2,1,3});
    sort(t.begin(), t.end());

    //сортировка пользовательских структур
    struct point {
        int x, y;
        bool operator <(const point &p){
            if(x == p.x) return y < p.y;
            else return x < p.x;
        }
    };

    //сортировка вектора строк с помощью внешенй функции
    vector<string> strV = {"hello", "man", "how", "are", "you", "nice", "to", "see", "you"};
    sort(strV.begin(), strV.end(), comp);

}