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
void push(stque *&h, int x){
    stque *r = new stque;
    r->item = x;
    r->next = h;
    h = r;
}
int pop(stque *&h){

    int x = h->item;
    stque *r = h;
    h = h->next;
    delete r;
    return x;

}
void reverse(stque *&h){
    stque *temp = NULL;
    while (h) {
        push(temp,pop(h));
    }
    h = temp;

}
void input_stack(stque *&st){
    int n;
    cout << "Введите количество элементов стэка n: ";
    cin >> n;
    int x;
    cout << "Введите "<<n<< " элементов стэка:";

    for(int i = 0; i < n; i++){
        cin >> x;
        push(st,x);

    }

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
void output_stack(stque *st){
    while(st){
        cout << pop(st) << ' ';
    }
}
void output_queue(stque *h,stque*t){
    while(h){
        cout << pop_q(h,t) << ' ';
    }
}
bool is_simple(int x){
    if (x <= 1 || x%2 == 0 &&  (x != 2)) return false;
    for(int i = 3; i<=x/2; i+=2)
        if(x%i==0)
            return false;

    return true;
}

void task1(){
    stque *q_h=NULL,*q_t=NULL;
    stque *t_h=NULL,*t_t=NULL;
    int x;
    bool is_there_simp = false;
    input_queue(q_h,q_t);
    while (q_h){
        x = pop_q(q_h,q_t);
        if (is_simple(x))
            is_there_simp = true;
        push_q(t_h,t_t,x);
    }
    while (t_h)
        push_q(q_h,q_t,pop_q(t_h,t_t));

    if (is_there_simp){

            while(!is_simple(q_h -> item))
                push_q(q_h,q_t,pop_q(q_h,q_t));
            output_queue(q_h,q_t);

    } else {
        cout<< "В стэке нет простых чисел.";
    }

}
void task2(){
    stque *q_h=NULL,*q_t=NULL;
    stque *t_h=NULL,*t_t=NULL;
    input_queue(q_h,q_t);
    int first = q_h -> item,x,maxel=-1e9;
    while (q_h){
        x = pop_q(q_h,q_t);
        maxel = max(maxel,x);
        push_q(t_h,t_t,x);
    }
    while (t_h){

        push_q(q_h,q_t,pop_q(t_h,t_t));
        if (q_t -> item == first) push_q(q_h,q_t,maxel);
    }
    output_queue(q_h,q_t);

}
void task3(){
    stque *st = NULL;
    int x,n;
    cout << "Введите x: ";
    cin >> x;


    input_stack(st);

    stque *temp = NULL;
    while(st->item%2!=1 && st){
        push(temp,pop(st));
    }
    if (st){
        push(st,x);
        while(temp){
            push(st,pop(temp));
        }
    }
    reverse(st);
    output_stack(st);


}
void task4(){
    stque *st = NULL,*s_st;
    int min_el = 1e9, max_el = -1e9, x;

    input_stack(st);

    while (st) {
        x = pop(st);
        min_el = min(min_el, x);
        max_el = max(max_el, x);
        push(s_st,x);
    }
    while(s_st){
        push(st,pop(s_st));
        if (st->item == min_el)
            push(st,max_el);
    }
    reverse(st);
    output_stack(st);


}
int main(){
    setlocale(LC_ALL,"Russian");
    task2();


    return 0;
}
