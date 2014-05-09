#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

typedef struct treenode{
    char data;
    treenode* lpre;
    treenode* lnext;
    treenode* father;
    treenode* son;
    treenode* brother;
}treenode;

typedef struct tree{
    treenode* head;
    treenode* tail;
}tree;

tree* newtree ();

treenode* newtnode (char data);

void push (tree* t, treenode* node);

treenode* search (tree* t, char data);

int addtoson (tree* t, char fdata, char sdata);

int fresh (treenode* father, treenode* son);

treenode* searchroot(tree* t);

int deepin (tree* t);

#endif // TREE_H_INCLUDED
