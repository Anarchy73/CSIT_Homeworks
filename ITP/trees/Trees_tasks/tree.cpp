#include "tree.h"
#include <iostream>

tree *node(int x){
    tree* t = new tree;
    t -> item = x;
    t -> right = NULL;
    t -> left = NULL;
    return t;
}
