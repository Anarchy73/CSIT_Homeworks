#include "tree.h"
#include <iostream>
using namespace std;
tree *node(int x){
    tree* t = new tree;
    t -> item = x;
    t -> right = NULL;
    t -> left = NULL;
    t -> parent = NULL;
    return t;
}
void node_insert(tree *&root, int x){
    tree *t = node(x);
    if (!root) root = t;
    else {
        tree *tmp = root;
        while (tmp){
            if (t -> item > tmp -> item){
                if (tmp -> right){
                    tmp = tmp -> right;
                } else {
                    t -> parent = tmp;
                    tmp -> right = t;
                    break;
                }

            } else if (t -> item < tmp -> item){
                if (tmp -> left){
                    tmp = tmp -> left;
                } else {
                    t -> parent = tmp;
                    tmp -> left = t;
                    break;
                }

            }
        }
    }
}

void tree_input(tree *&root){
    int n,x;
    cout << "Введите количество элементов дерева:";
    cin >> n;

    cout << "Введите элементы дерева:";

    for (int i = 0; i < n; i++){
        cin >> x;
        node_insert(root,x);
    }
}


void inorder(tree *root){
    if (root){
        inorder(root -> left);
        cout << root -> item <<' ';
        inorder(root -> right);

    }

}
