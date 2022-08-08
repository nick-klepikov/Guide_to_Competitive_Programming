#include <iostream>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>

using namespace std;

int main(){
    //Множества

    //Set - операции работают за время O(log n), unordered_set - в среднем O(1)

    set<int> s;
    s.insert(3);
    s.insert(2);
    s.insert(5);
    cout << s.count(3) << '\n'; // 1
    cout << s.count(4) << '\n'; // 0
    s.erase(3);
    s.insert(4);
    cout << s.count(3) << '\n'; // 0
    cout << s.count(4) << '\n'; // 1

    //Все элементы множества уникальны, поэтому элемент нельзя добавить если он уже присутствует
    s.insert(3);
    s.insert(3);
    cout << s.count(3) << "\n"; // 1

    //Вывод размера множества и перебор его элементов
    cout << s.size() << '\n';
    for(int x: s) cout << x << ' ';

    //find(x) возвращает итератор на элемент со значением x, а если его нет, то на end()
    auto it = s.find(3);

    //Set - упорядоченное множество, unordered_set - неупорядоченное

    //Поиск наибольшего и наименьшего элемента
    auto first = s.begin();
    auto last = s.end(); last--;
    cout << *first << " " << *last << "\n";

    //Также присутствуют следующие функции
    cout << *s.lower_bound(3) << "\n";
    cout << *s.upper_bound(3) << "\n";





    //Мультимножества(в него один и тот же элемент может входить несколько раз

    multiset<int> m;
    m.insert(5);
    m.insert(5);
    m.insert(5);
    cout << m.count(5) << "\n"; // 3

    //Удаление всех копий значения
    m.erase(5);
    cout << m.count(     5) << "\n"; // 0

    //Удаление одного значения
    m.erase(m.find(5));
    cout << m.count(5) << "\n"; // 2
    //В частности, подсчитывать количество копий значения в мультимножестве с помощью функции count неэффективно.





    //Отображения

    //map - время доступа к элементам O(log n), unordered_map - O(1)

    map<string, int> mp;
    mp["monkey"] = 4;
    mp["banana"] = 3;
    mp["harpsichord"] = 9;
    cout << mp["banana"] << '\n'; //3

    //В случае отстутствия запрашиваемого ключа, он автоматически добавляется со значением по умолчанию
    cout << mp["aybabtu"] << "\n"; // 0

    //Проверка на существование ключа
    cout << mp.count("hello") << '\n';
    //Перебор всех ключей и значений
    for(auto x: mp) cout << x.first << ' ' << x.second << '\n';





    //Очередь с приоритетом

    //Вставка и удаление занимают время O(log n), а извлечение – время O(1)

    //У очереди с приоритетом меньшие постоянные коэффициенты, поэтому для поиска макс и мин элементов лучше использовать её

    //По умолчанию отсортрованы в порядке убывания

    priority_queue<int> q;
    q.push(3);
    q.push(5);
    q.push(7);
    q.push(2);
    cout << q.top() << '\n'; // 7
    q.pop();
    cout << q.top() << '\n'; // 5
    q.pop();
    q.push(6);
    cout << q.top() << '\n'; // 6

    //Для создания очереди с приоритетом, поддерживающей поиск и удаление наименьшего элемента, нужно поступить так:
    priority_queue<int,vector<int>,greater<int>> qu;





    //Множества, основанные на политиках(только для компилятора g++)

    //Для их использования
    //в программу нужно включить такие строки:
    //#include <ext/pb_ds/assoc_container.hpp>
    //using namespace __gnu_pbds;

    //Далее можно включить структуру indexed_set, которая похожа на множество, но допускает индексирование

    //Для значений типа int определение выглядит так:
    //typedef tree<int,null_type,less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

    //Создание:
    //indexed_set s;
    //s.insert(2);
    //s.insert(3);
    //s.insert(7);
    //s.insert(9);

    //Особенность этого множества состоит в том, что доступ можно осуществлять по индексу, который элемент имел бы в отсортированном массиве.
    //Функция find_by_order возвращает итератор, указывающий на элемент в заданной позиции:
    //auto x = s.find_by_order(2);
    //cout << *x << "\n"; // 7

    //А функция order_of_key возвращает позицию заданного элемента:
    //cout << s.order_of_key(7) << "\n"; // 2

    //Если элемент отсутствует во множестве, то мы получим позицию, в которой он находился бы, если бы присутствовал:
    //cout << s.order_of_key(6) << "\n"; // 2
    //cout << s.order_of_key(8) << "\n"; // 3

    //Время работы обеих функций логарифмическое.
}

