#ifndef BOT_H
#define BOT_H
#include "point.h"
#include "checkerboard.h"
#include<iostream>
#include<iomanip>
using namespace std;
class bot 
{
    struct dir
    {
        int dx;
        int dy;
    };
    const dir d1 = { 0, 1 };//����(y�b)
    const dir d2 = { 1, 0 };//����(x�b)
    const dir d3 = { 1, -1 };//���W��k�U
    const dir d4 = { 1, 1 };//�k�W�쥪�U

    private:
        point p;
        point play;
        int chessboard[19][19];

    public:
        bool isInBoard(point);
        int score( point, int);//��X��:point(x,y) , int�q��or�H(���F��K�A�T�w�q�����), �q��2, �H1
        point newPoint(point , dir , int );
        point botplayer();
        bot();
        bot(point);
        void botsee( point, int);

        
        
};
#endif
