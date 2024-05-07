


#include <iostream>
#include "graph.h"
#include <windows.h>


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

void dfs(graph &s,  std::map<int,int> &used, int x){
    used[x] = 1;
    stque *h = NULL, *t = NULL;
    push_q(h,t,x);
    while(h){
        int x = pop_q(h,t);
        for (auto it_y = s.find(x)->second.begin(); it_y != s.find(x)->second.end(); it_y++){
            used[it_y->first] = 1;
            push_q(q,t,it_y->first);
        }
    }
}


void task1(){ // Выход из ввода Ctrl + c
    graph s;
    int x;
    cout << "Введите вершину x:";
    cin >> x;


    graph_input(s,false);

    auto it_x = s.find(x);
    for (auto it = it_x->second.begin(); it != it_x->second.end(); it++) cout << it->first << ' ';

}

void task2(){
    graph s;

    int a,b;
    cout << "Введите вершины a,b:";
    cin >> a >> b;

    slipknot(s,a,b,1.0,false);

}
void task3(){
    graph s;
    int counter;

    graph_input(s,false);

    for (auto it_x = s.begin(); it_x != s.end(); it_x++){
        counter = 0;
        cout << "степень вершины " << it_x->first << " равна ";
        for (auto it_y = it_x->second.begin(); it_y != it_x->second.end(); it_y++){
            counter++;
        }
        cout << counter << endl;
    }
}
void task4(){
    graph s;
    map<int,int> used;
    bool sv = true;

    graph_input(s,false);


    dfs(s,used,s.begin()->first);


    for(auto it_x = s.begin(); it_x!=s.end();it_x++){
        if (!used.count(it_x->first)){
            sv = false;
            break;
        }
    }
    if (sv){
        cout << "Граф связный";
    } else{
        cout << "Граф несвязный";
    }

/*
4
1 2 1
2 3 1
3 4 1
4 1 1
5 6 1
*/

}
int main()
{
    SetConsoleOutputCP( 65001 );

    int t;

    cout << "Выберите задание (1-4):";
    cin >> t;

    switch(t){
    case 1:
        task1();
        break;
    case 2:
        task2();
        break;
    case 3:
        task3();
        break;
    case 4:
        task4();
        break;
    }

    return 0;
}
