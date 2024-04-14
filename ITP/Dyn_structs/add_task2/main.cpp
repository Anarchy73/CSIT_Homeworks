#include <iostream>

using namespace std;

struct stque{
    int item;
    stque *next;
};


void push_q(stque *&h,stque*&t,int x){
    stque *r = new stque;
    r -> item = x;
    r -> next = NULL;
    if (!h && !t)
        h = t = r;
    else {
        t -> next = r;
        t = r;
    }

}
int pop_q (stque *&h,stque *&t){
    stque *r = h;
    int i = h -> item;
    h = h -> next;
    if (!h){
        t = NULL;
    }
    delete r;
    return i;
}

void input_queue( stque *&h,stque*&t){
    int n;
    cout << "Введите количество элементов очереди n: ";
    cin >> n;
    int x;
    cout << "Введите "<<n<< " элементов очереди:";

    for(int i = 0; i < n; i++){
        cin >> x;
        push_q(h,t,x);

    }

}

void output_queue(stque *h,stque*t){
    while(h){
        cout << pop_q(h,t) << ' ';
    }
}

int main()
{

    return 0;
}
