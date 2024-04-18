#include <iostream>
#include <string>
#include <windows.h>
#include <vector>
#include <algorithm>
using namespace std;

struct stque{
    int item;
    stque *next;
};


void push_q(stque *&h,stque*&t,int x){
    stque *r = new stque;
    r -> item = x;
    r -> next = NULL;
    if (!h && !t)
        h = t = r;
    else {
        t -> next = r;
        t = r;
    }

}
int pop_q (stque *&h,stque *&t){
    stque *r = h;
    int i = h -> item;
    h = h -> next;
    if (!h){
        t = NULL;
    }
    delete r;
    return i;
}

void input_queue( stque *&h,stque*&t){
    int n;
    cout << "Введите количество элементов очереди n: ";
    cin >> n;
    int x;
    cout << "Введите "<<n<< " элементов очереди:";

    for(int i = 0; i < n; i++){
        cin >> x;
        push_q(h,t,x);

    }

}

void output_queue(stque *h,stque*t){
    while(h){
        cout << pop_q(h,t) << ' ';
    }
}

vector <vector <int>> vect_smezh_input(int n){
    vector <vector <int>> v(n);
    int a, x;
    cout << "Введите n строк, в которых первое число a - количество соседних вершин, \nследующие a чисел - вершины смежные данной. \n";
    for (int i = 0; i < n; i++){
        cout << i << "-ая вершина: ";
        cin >> a;
        for (int j = 0; j < a; j++) {
            cin >> x;
            v[i].push_back(x);
        }
    }
    return v;
}

int main()
{

    SetConsoleOutputCP( 65001 );
    int n,x,y;
    stque *qh = NULL,*qt = NULL;

    cout << "Введите число вершин графа n: ";
    cin >> n;

    vector <vector <int>> v = vect_smezh_input(n);

    vector <int> A(n,0);


    cout << "Введите номер начальной вершины: ";
    cin >> x;

    A[x] = 1;
    cout << "Порядок обхода вершин: ";

    while (count(A.begin(),A.end(),1) < n){
        push_q(qh,qt,x);
        cout << x << ' ';
        while (qh){
            x = pop_q(qh,qt);
            for (int i = 0; i < v[x].size(); i++){
                if (A[v[x][i]] == 0){
                    y = v[x][i];
                    A[v[x][i]] = 1;
                    push_q(qh,qt,y);
                    cout << y << ' ';
                }

            }

        }
        for (int i = 0; i < n; i++) if (A[i] == 0) x = i;
    }



    return 0;
}
/*

Пример входных данных (граф взят из теории), вершины от 0 до 6 :
7
4 1 2 4 5
2 0 3
2 0 5
1 1
2 0 6
3 0 2 6
2 4 5
0

*/

