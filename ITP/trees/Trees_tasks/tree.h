#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED


struct tree{
    int item;
    tree *left;
    tree *right;
    tree *parent;
};

void node_insert(tree *&root, int x);

tree *node(int x);

void tree_input(tree *&root);

void inorder(tree *root);

void preorder(tree *root);

void create_pbt(tree *&root, int n);

#endif // TREE_H_INCLUDED
