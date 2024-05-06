


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

    }

    return 0;
}
