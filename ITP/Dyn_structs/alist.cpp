#include "alist.h"
#include <iostream>
using namespace std;
template <typename T> struct alist {
    T item;
    alist<T>* next;
    alist<T>* prev;
};

template <typename T> void pushback(alist<T> *&h,alist<T> *&t, T x){
    alist<T> *r = new alist<T>;

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
template <typename T> void print(alist<T> *&h,alist<T> *&t){
    alist<T> *r = h;
    while (r) {
        cout << r -> item << ' ';
        r = r -> next;
    }
    cout << endl;
}
