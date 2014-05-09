
#ifndef MARTRIX_INCLUDED
#define MARTRIX_INCLUDED
#define INITSIZE 10
#define ADDSIZE 5

typedef struct{
    int indexx;
    int indexy;
    int value;
}element;

typedef struct{
    element* data;
    int size;
    int num;
    int ordered;
    int sizex,sizey;

}martrix;

int mar_init (martrix* A, int x, int y);

int addElement (int x, int y, int val, martrix* A);

void transposition (martrix* A);

void print (martrix* A);

#endif // MARTRIX_INCLUDED
