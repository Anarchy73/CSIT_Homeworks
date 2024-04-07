#include<iostream>
#include "alist.h"

using namespace std;


int main(){
    setlocale(LC_ALL, "Russian");
    alist *ah = NULL, *ata = NULL, *it;

    input_list(ah,ata);

    int first_el = ah -> item, maxel = -1e9;

    it = ah;
    while (it){
        maxel = max(maxel, it -> item);
        it = it -> next;
    }
    it = ah;
    while (it){
        if (it -> item == first_el){
            insert_after(ah,ata,it,maxel);
            it = it -> next;
        }
        it = it -> next;
    }
    print(ah,ata);
    cout << first_el << ' ' << maxel;
}
