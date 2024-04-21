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

void pbt_leafs(tree *t){
    if (t){
        if (!t -> left && ! t -> right) cout << t -> item << ' ';
        pbt_leafs(t -> left);
        pbt_leafs(t -> right);
    }
}
void pbt_klevel(tree *t, int counter, int k){
    if (t){
        if (counter == k) cout << t -> item << ' ';
        pbt_klevel(t -> left, counter + 1, k);
        pbt_klevel(t -> right, counter + 1, k);
    }
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
void task3(){
    tree *t = NULL;
    int n;

    cout << "Введите количество элементов дерева: ";
    cin >> n;

    create_pbt(t,n); // 4 5 3 7 8 6 9 1 2 0

    pbt_leafs(t);
    cout << endl;
    preorder(t);

}
void task4(){
    tree *t = NULL;
    int n, k;

    cout << "Введите количество элементов дерева: ";
    cin >> n;

    create_pbt(t,n); // 4 5 3 7 8 6 9 1 2 0

    cout << "Введите уровень k, с которого вывести элементы: ";
    cin >> k;

    pbt_klevel(t, 0, k);
    cout << endl;
    preorder(t);

}

int main()
{
    SetConsoleOutputCP( 65001 );
    task4();
    return 0;
}
