#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "tree.h"

tree* newtree ()
{
    tree* t = (tree*) malloc (sizeof (tree));
    t->head = newtnode(0);
    t->tail = newtnode(0);
    t->head->lnext = t->tail;
    t->tail->lpre = t->head;
    return t;
}

treenode* newtnode (char data)
{
	treenode* res = (treenode*) malloc (sizeof (treenode));
	res->lpre = res->lnext = NULL;
	res->father = res->son = res->brother = NULL;
	res->data = data;
	return res;
}

void push (tree* t, treenode* node)
{
	t->tail->lpre->lnext = node;
	node->lpre = t->tail->lpre;
	node->lnext = t->tail;
	t->tail->lpre = node;
}

treenode* search (tree* t, char data)
{
	treenode* cur = t->head->lnext;
	for (;cur != t->tail; cur = cur->lnext)
	{
		if (cur->data == data)
		{
			return cur;
		}
	}
	return NULL;
}

int addtoson (tree* t, char fdata, char sdata)
{
	treenode* father = search(t, fdata);
	treenode* son = search (t,sdata);
	if (son != NULL && father != NULL)
	{
		return fresh (father, son);
	}
	if (father == NULL)
	{
		father = newtnode(fdata);
		push (t,father);
	}
	if (son == NULL)
	{
        son = newtnode(sdata);
        push (t,son);
	}
	son->father = father;
	if (father->son == NULL)
	{
		father->son = son;
	}
	else
	{
		treenode* tmp = father->son;
		father->son = son;
		son->brother = tmp;
	}
	return 1;
}

int fresh (treenode* father, treenode* son)
{
	if (son->father == NULL)
	{
		son->father = father;
		if (father->son == NULL)
		{
			father->son = son;
		}
		else
		{
			treenode* tmp = father->son;
			father->son = son;
			son->brother = tmp;
		}
	}
	else if (son->father != father)
	{
		return 0;
	}
	return 1;
}

treenode* searchroot(tree* t)
{
	treenode* cur;
	for (cur = t->head->lnext; cur != t->tail; cur = cur->lnext)
	{
		if (cur->father == NULL)
			return cur;
	}
	return NULL;
}

int _deepin (treenode* root)
{
	if (root == NULL)
		return 0;

	int res = 0;
	treenode* cur = root->son;
	for (;cur != NULL; cur = cur->lnext)
	{
		int tmp = _deepin(cur);
		if (tmp > res)
		{
			res = tmp;
		}
	}
	return res + 1;
}

int deepin (tree* t)
{
	return _deepin(searchroot(t));
}
