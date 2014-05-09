#include <cstdio>
#include <cstring>
#include <cstdlib>
#include "binarytree.h"
#include "stack.h"
#include "queue.h"

node* search (int data, node* root)
{
  if (root == NULL)
    return NULL;
  if (root->data == data)
    return root;
  node * tmp = search (data, root->left);
  if (tmp != NULL)
    return tmp;
  else
    return search (data,root->right);
}

node* newnode (char data)
{
  node* res = (node*) malloc (sizeof (node));
  res->left = res->right = res->father = NULL;
  res->data = data;
  return res;
}

int insertleft (char data, node* father)
{
  if (father == NULL || father->left != NULL)
    return 0;
  node* cur = newnode(data);
  cur->father = father;
  father->left = cur;
  return 1;
}

int insertright (char data, node* father)
{
  if (father == NULL || father->right != NULL)
    return 0;
  node* cur = newnode (data);
  cur->father = father;
  father->right = cur;
  return 1;
}

node* buildfromarray (char* source)
{
  stack _s;
  stack* s = &_s;
  stack_init(s);
  int len = strlen (source);
  int i;
  node* root = newnode(source[0]);
  stack_push(s,root);
  for (i = 1; i < len; i++)
  {
    if (source[i] == '.')
    {
      node* father = stack_top(s);
      if (father == NULL)
        return NULL;
      if (father->left == NULL)
      {
        insertleft (source[i], father);
      }
      else if (father->right == NULL)
      {
        insertright (source[i], father);
        stack_pop (s);
      }
      else
      {
        stack_pop(s);
        i--;
      }
    }
    else
    {
      node* father = stack_top(s);
      if (father == NULL)
        return NULL;
      if (father->left == NULL)
      {
        insertleft (source[i], father);
        stack_push (s,father->left);
      }
      else if (father->right == NULL)
      {
        insertright (source[i], father);
        stack_push (s,father->right);
      }
      else
      {
        stack_pop(s);
        i--;
      }
    }
  }
  return root;
}

void previs (node* root, void (*vis) (node*))
{
  if (root == NULL)
    return;
  vis (root);
  previs(root->left,vis);
  previs(root->right,vis);
}

void midvis (node* root, void (*vis) (node*))
{
  if (root == NULL)
    return;
  midvis(root->left,vis);
  vis (root);
  midvis(root->right,vis);
}

//unrecusive middle visit;
void _midvis (node* root, void (*vis) (node*))
{
  if (root == NULL)
    return;
  stack _s;
  stack* s = &_s;
  stack_init(s);
  stack_push(s,root);
  node* cur = root;
  for (;cur != NULL || stack_top(s) != NULL;)
  {
    for (;stack_top(s) != NULL;)
    {
      vis (cur);
      stack_push(s,cur);
      cur = cur->left;
    }
    if (stack_top(s) != NULL)
    {
      node* tmp = stack_top(s);
      stack_pop(s);
      cur = tmp->right;
    }
  }
}

void postvis (node* root, void (*vis) (node*))
{
  if (root == NULL)
    return;
  postvis(root->left,vis);
  postvis(root->right,vis);
  vis (root);
}

void levelvis (node* root, void (*vis) (node*))
{
    queue _q;
    queue* q = &_q;
    queue_init(q);
    queue_push(q,root);
    vis (root);
    for (;q->front->next != q->tail;)
    {
        node* cur = queue_front(q);
        queue_pop(q);
        vis (cur->left);
        if (cur->left->data != '.')
            queue_push(q,cur->left);
        vis (cur->right);
        if (cur->right->data != '.')
            queue_push(q,cur->right);
    }
}

int getdeepin (node* root)
{
  if (root == NULL || root->data == '.')
    return 0;
  int l = getdeepin (root->left);
  int r = getdeepin (root->right);
  return l > r ? l+1 : r+1;
}
