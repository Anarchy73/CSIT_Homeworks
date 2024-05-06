#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

#define graph map<int,list<pair<int,double>>>

#include <list>
#include <map>
#include <utility>

using namespace std;


void slipknot(graph &s, int x, int y, double w , bool orient);

#endif // GRAPH_H_INCLUDED
