#include<iostream>
#include "alist.h"

using namespace std;

void task1(){
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

void task2(){
    alist *ah = NULL, *ata = NULL, *it, *itp;
    int x,n,tp;

    cout << "¬ведите x : ";
    cin >> x;

    n = input_list(ah,ata);
    it = ata;
    for (int i = 0; i < n && it; i++){
        itp = it -> prev;
        if (it -> item < x){

            pushforward(ah,ata,del_nod(ah,ata,it));

        }
        it = itp;
    }
    print(ah,ata);
}
void task3(){
    alist *ah = NULL, *ata = NULL,*ittmp,*itj;
    int n,x;
    n = input_list(ah,ata);

    for (alist *iti = ah -> next; iti; ){

        itj = iti;
        iti = iti -> next;

        for (; itj!=ah && ((itj -> item) < (itj -> prev -> item)); itj = itj -> prev){

            ittmp = itj -> prev;
            if (itj -> prev == ah){

                x = del_nod(ah,ata,itj);

                pushforward(ah,ata,x);

                break;
            } else {

                insert_after(ah,ata,itj -> prev -> prev,del_nod(ah,ata,itj));

            }
            itj = ittmp;

        }

    }
    print(ah,ata);
}
int main(){
    setlocale(LC_ALL, "Russian");
    task3();
}
