#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED


struct tree{
    int item;
    tree *left;
    tree *right;
    tree *parent;
};

tree *node(int x);

#endif // TREE_H_INCLUDED
