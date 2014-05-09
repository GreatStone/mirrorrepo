#ifndef BINARYTREE_H
#define BINARYTREE_H

typedef struct node {
  char data;
  node* left;
  node* right;
  node* father;
}node;

node* search (char data, node* tree);

node* newnode (char data);

int insertleft (char data, node* father);

int insertright (char data, node* father);

node* buildfromarray(char* source);

void previs (node* root, void (*vis) (node*));

void midvis (node* root, void (*vis) (node*));

void _midvis (node* root, void (*vis) (node*));

void postvis (node* root, void (*vis) (node*));

void levelvis (node* root, void (*vis) (node*));

int getdeepin (node* root);

#endif
