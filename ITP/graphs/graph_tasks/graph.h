#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

#include <list>
#include <map>
#include <utility>

#define graph map<int,list<pair<int,double>>>

void slipknot(graph &s, int x, int y, double w = 1.0, bool orient = false){
    bool fl = true;
    auto it_x = s.find(x);
    if (it_x != s.end()){
        for (auto it_y = it_x->second.begin(); it_y != it_x->second.end(); it_y++){
            if (it_y->first == y){
                fl = false;
                break;
            }
        }
    }
    if(fl && orient){
        s[x].pushback(make_pair(y,w));

        if (s.find(y) == s.end()){
            s[y].pushback(make_pair(0,0));
            s[y].erase(s[y].begin);
        }

    } else if (fl){
        s[x].pushback(make_pair(y,w));
        it_y = s.find(y);
        fl = true;
        if (it_y != s.end()){
            for (auto it_x0 = it_y->second.begin(); it_x0 != it_y->second.end(); it_x0++){
                if (it_x0->first == x){
                    fl = false;
                    break;
                }
            }
        }
        if (fl){
            s[y].pushback(make_pair(x,w));
        }

    }



}


#endif // GRAPH_H_INCLUDED
