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
    const dir d1 = { 0, 1 };//垂直(y軸)
    const dir d2 = { 1, 0 };//水平(x軸)
    const dir d3 = { 1, -1 };//左上到右下
    const dir d4 = { 1, 1 };//右上到左下

    private:
        point p;
        point play;
        int chessboard[19][19];

    public:
        bool isInBoard(point);
        int score( point, int);//算幾分:point(x,y) , int電腦or人(為了方便，固定電腦後手), 電腦2, 人1
        point newPoint(point , dir , int );
        point botplayer();
        bot();
        bot(point);
        void botsee( point, int);

        
        
};
#endif
