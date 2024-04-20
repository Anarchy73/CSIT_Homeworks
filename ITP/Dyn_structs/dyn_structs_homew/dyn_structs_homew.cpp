#include <iostream>
#include <vector>
#include <windows.h>
#include <stdlib.h>
#include <string>
using namespace std;

struct stque{
    string item;
    stque *next;
};


void push_q(stque *&h,stque*&t,string x){
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
string pop_q (stque *&h,stque *&t){
    stque *r = h;
    string i = h -> item;
    h = h -> next;
    if (!h){
        t = NULL;
    }
    delete r;
    return i;
}
int *str_to_coord(string tile){
    string alph = "ABCDEFGH";
    int* coord = new int[2];
    coord[0] = alph.find_first_of(tile[0]);
    coord[1] = stoi(tile.substr(1)) - 1;
    return coord;
}
string coord_to_str(int* coord){
    string alph = "ABCDEFGH";
    string tile = "";
    tile += alph[coord[0]];
    tile += to_string(coord[1]+1);
    return tile;
}
void jump_around(vector<vector <string>> &c_m, string tile, stque *&h, stque *&t){
    int *start = str_to_coord(tile), *tmp = new int[2];
    for (int i = 1, j = 2; i <= 2; i++, j--){
        tmp[0] = start[0] + i;
        tmp[1] = start[1] + j;
        if (start[0] + i < 8 && start[1] + j < 8 && c_m[tmp[0]][tmp[1]] == "0"){
            c_m[start[0] + i][start[1] + j] = tile;
            push_q(h,t,coord_to_str(tmp));
        }

        tmp[0] = start[0] - i;
        tmp[1] = start[1] + j;
        if (start[0] - i >= 0 && start[1] + j < 8 && c_m[tmp[0]][tmp[1]] == "0"){
            c_m[start[0] - i][start[1] + j] = tile;
            push_q(h,t,coord_to_str(tmp));
        }

        tmp[0] = start[0] + i;
        tmp[1] = start[1] - j;
        if (start[0] + i < 8 && start[1] - j >= 0 && c_m[tmp[0]][tmp[1]] == "0"){
            c_m[start[0] + i][start[1] - j] = tile;
            push_q(h,t,coord_to_str(tmp));
        }

        tmp[0] = start[0] - i;
        tmp[1] = start[1] - j;
        if (start[0] - i >= 0 && start[1] - j >= 0 && c_m[tmp[0]][tmp[1]] == "0"){
            c_m[start[0] - i][start[1] - j] = tile;
            push_q(h,t,coord_to_str(tmp));
        }

    }
}

void wayback(vector<vector <string>> &c_m, int *&coord){
    vector<string> way;
    while (c_m[coord[0]][coord[1]] != coord_to_str(coord)){

        way.push_back(coord_to_str(coord));
        coord = str_to_coord(c_m[coord[0]][coord[1]]);
    }
    way.push_back(coord_to_str(coord));
    cout << endl;
    for (int i = way.size() - 1; i>=0 ; --i ) cout <<  way[i] << ' ';
}

int main()
{
    SetConsoleOutputCP( 65001 );

    stque *qh = NULL, *qt = NULL;
    string tile1,tile2,tmp;
    vector<vector <string>> chess_map(8, {"0","0","0","0","0","0","0","0"});


    cout << "Введите клетки А и B: ";
    cin >> tile1 >> tile2;
    int *coord1,*coord2;
    coord1 = str_to_coord(tile1);
    coord2 = str_to_coord(tile2);

    chess_map[coord1[0]][coord1[1]] = tile1;

    push_q(qh,qt, tile1);

    while (chess_map[coord2[0]][coord2[1]] == "0"){

        jump_around(chess_map, pop_q(qh,qt), qh, qt);
    }



    wayback(chess_map, coord2);


}
