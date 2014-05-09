#include <iostream>
#include <cstdio>
using namespace std;

template <class T>
class node{
public:
    T data;
    node* pre;
    node* next;
    node ()
    {
        pre = next = NULL;
    }
    node (T dat)
    {
        data = dat;
        pre = next = NULL;
    }
};

template <class T>
class que{
public:
    node<T> begin;
    node<T> end;
    int n;
    que()
    {
        begin.next = &end;
        begin.pre = NULL;
        end.next = NULL;
        end.pre = &begin;
        n = 0;
    }
    void push (T data)
    {
        node<T>* add = new node<T>(data);
        add->pre = end.pre;
        add->next = &end;
        end.pre = add;
        add->pre->next = add;
        n++;
    }
    T front ()
    {
        if (!n)
            return -1;
        return begin.next->data;
    }
    void pop ()
    {
        if (!n)
            return;
        node<T>* del = begin.next;
        begin.next = del->next;
        del->next->pre = &begin;
        n--;
        delete del;
    }
};

template <class T>
class arrque
{
public:
    T* data;
    int first;
    int size;
    int n;
    arrque (int gsize)
    {
        size = gsize;
        first = 0;
        data = new T[size];
        n = 0;
    }
    T front ()
    {
        return data[first];
    }
    void push (T source)
    {
        if (n == size)
            return;
        data[(first + n) % size] = source;
        n++;
    }
    void pop ()
    {
        if (!n)
        return;
        data[first] = -1;
        first = (first + 1) % size;
        n--;
    }
};

int main()
{
    arrque<int> q(5);
    char com[10];
    int m;
    while (1){
        scanf ("%s%d",com,&m);
        if (com[0] == 'i')
            q.push (m);
        else
        {
            printf ("%d\n",q.front());
            q.pop();
        }
    }
    return 0;
}
