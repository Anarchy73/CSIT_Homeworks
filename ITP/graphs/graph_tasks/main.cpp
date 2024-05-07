


#include <iostream>
#include "graph.h"
#include <windows.h>


using namespace std;


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
