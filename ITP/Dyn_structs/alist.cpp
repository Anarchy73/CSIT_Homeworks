#include <iostream>
#include "alist.h"

using namespace std;



 void pushback(alist *&h,alist *&t, int x){
    alist *r = new alist;

    r -> item = x;

    r -> next = NULL;
    if (!h && !t){
        r -> prev = NULL;
        h = r;
    } else {
        t -> next = r;
        r -> prev = t;
    }
    t = r;

}
void pushforward(alist *&h,alist *&t, int x){
    alist *r = new alist;

    r -> item = x;
    r -> prev = NULL;

    if (!h && !t){
        r -> next = NULL;
        t = r;
    } else {
        r -> next = h;
        h -> prev = r;
    }
    h = r;
}
void insert_after(alist *&h, alist *&t, alist *r, int x){
    alist *p = new alist;
    p -> item = x;

    if (r == t){
        p -> next = NULL;
        p -> prev = t;
        t -> next = p;
        t = p;
    } else {
        p -> next = r -> next;
        p -> prev = r;
        r -> next -> prev = p;

        r -> next = p;

    }

}

 void input_list(alist *&h, alist *&t){

    int n,x;

    cout << "Введите количество элементов списка n: ";
    cin >> n;

    for (int i = 0; i < n; i++){
        cin >> x;
        pushback(h,t,x);
    }

 }


 void print(alist *&h,alist *&t){
    alist *r = h;
    while (r) {
        cout << r -> item << ' ';
        r = r -> next;
    }
    cout << endl;
}

int del_nod(alist *&h, alist *&t, alist *&r){
    int x = r -> item;
    if (r==h && r==t){
        t = h = NULL;
    } else if ( r == h){
        h = r -> next;
        h -> prev = NULL;

    } else if ( r == t){
        t = r -> prev;
        t -> next = NULL;

    } else {
        r -> next -> prev = r -> prev;
        r -> prev -> next = r -> next;

    }
    delete r;
    return x;
}

