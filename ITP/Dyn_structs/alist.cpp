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

