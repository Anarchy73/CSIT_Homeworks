#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

#include <list>
#include <map>
#include <utility>

#define graph std::map<int,std::list<std::pair<int,double>>>



void slipknot(graph &s, int x, int y, double w , bool orient);

void graph_input(graph &s, bool orient);

#endif // GRAPH_H_INCLUDED
