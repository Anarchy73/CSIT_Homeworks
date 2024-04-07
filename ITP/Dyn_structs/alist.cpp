#include <iostream>
#include "alist.h"

using namespace std;

 struct alist {
    int item;
    alist* next;
    alist* prev;
};

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
 void print(alist *&h,alist *&t){
    alist *r = h;
    while (r) {
        cout << r -> item << ' ';
        r = r -> next;
    }
    cout << endl;
}

