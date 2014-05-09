#ifndef HISTORY_H_INCLUDED#define HISTORY_H_INCLUDEDtypedef struct info{    int login;    int charge;    info* ppre;    info* pnext;}info;typedef struct history{    char id[20];    info* head;    info* tail;    int size;
    history* ppre;
    history* pnext;}history;typedef struct{    history* head;    history* tail;    int size;}hisbook;

void bookinit (hisbook* book);

void hisinit (history* his);
void pushinfo (history* his, info* source);void addinfo (hisbook* book, info* source, char* id);history* searchId (hisbook* book, char* id);void printInfo (info* source);void printHis (history* source);#endif // HISTORY_H_INCLUDED