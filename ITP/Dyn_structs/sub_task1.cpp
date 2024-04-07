#include <iostream>
#include <string>


using namespace std;

struct stque{
    string item;
    stque *next;
};

string pop(stque *&h){
    stque *r = h;

    string x = r -> item;
    h = h ->next;

    delete r;
    return x;

}

void push(stque *&h, string x){
    stque *r = new stque;
    r -> next = h;
    r -> item = x;

    h = r;

}

string operation(string op, string a, string b){
    if (op == "+"){
        return to_string(stoi(a) + stoi(b));
    } else if (op == "-"){
        return to_string(stoi(a) - stoi(b));
    } else if (op == "*"){
        return to_string(stoi(a) * stoi(b));
    } else{
        return to_string(stoi(a) / stoi(b));
    }


}

int main() {
    stque *st = NULL;
    string s,num1,num2,op;
    cin >> s;

    for (int i = 0; i<s.length();i++){

        if (!isdigit(s[i])){
            push(st,s.substr(i,1));
        } else if (isdigit(s[i]) && !(isdigit(st -> item[0]) || isdigit(st -> item[1]) )){
            push(st,s.substr(i,1));
        } else {
                num1 = s[i];
                while(st && (isdigit(st -> item[0]) || isdigit(st -> item[1]) )) {
                    num2 = pop(st);
                    op = pop(st);

                    num1 = operation(op,num2,num1);


            }
            push(st,num1);


        }

    }
    cout << st -> item;

    return 0;
}
// -*3+4/822
