#ifndef ALIST_H
#define ALIST_H
 struct alist{
    int item;
    alist* next;
    alist* prev;
};

 void pushback(alist *&h,alist *&t, int x);

 void insert_after(alist *&h, alist *&t, alist *r, int x);

 void input_list(alist *&h, alist *&t);

 void print(alist *&h,alist *&t);

 int del_nod(alist *&h, alist *&t, alist *&r);

#endif // ALIST_H
