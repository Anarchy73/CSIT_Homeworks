#include <iostream>
#include "tree.h"
#include <windows.h>
using namespace std;

int inordert1(tree *t,int counter){
    if (t){
        counter = inordert1(t -> left, counter);
        if (t -> left && t -> right == NULL) {

                counter++;}
        counter = inordert1(t -> right, counter);
    }
    return counter;

}
int trees_height(tree *&t, int counter){
    if (t){
        counter++;
        counter = max(trees_height(t -> right, counter), trees_height(t -> left,counter));

    }
    return counter;
}

void task1(){
    tree *t = NULL;

    tree_input(t); // 5 3 7 1 9 4 2 8 6 0



    cout << inordert1(t,0) << endl;
    inorder(t);
}
void task2(){
    tree *t = NULL;

    tree_input(t); // 5 3 7 1 9 4 2 8 6 0

    cout << "Высота дерева: " << trees_height(t,-1) << endl;
    inorder(t);
}

int main()
{
    SetConsoleOutputCP( 65001 );
    task2();
    return 0;
}
