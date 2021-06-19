#include <iostream>
#include <conio.h>
#include <cstdlib>
#include "bot.h"
#include "point.h"
#include "checkerboard.h"
using namespace std;

bot::bot()
{
    p;
    for (int i = 0; i < 19; i++)
    {
        for (int j = 0; j < 19; j++)
        {
            chessboard[i][j] = 0;
        }
    }
}

bot::bot(point newPoint)
{
    p = newPoint;
    for (int i = 0; i < 19; i++)
    {
        for (int j = 0; j < 19; j++)
        {
            chessboard[i][j] = 0;
        }
    }
}

point bot::botplayer()
{

    int a = 0, b = 0, c = 0, d = 0;
    point best1(a, b), best2(c, d);
    int a1 = score(best1, 2), b1 = score(best1, 1);
    for (int i = 0; i < 19; i++)
    {

        for (int j = 0; j < 19; j++)
        {

            if (chessboard[i][j] != 0)
            {
                continue;
            }
            point cur;
            cur.setXPoint(i);
            cur.setYPoint(j);
            int m1 = score(cur, 2);

            int m2 = score(cur, 1);

            if (m1 > a1)
            {
                best1 = cur;
                a1 = m1;
                b1 = m2;
            }
            else if (m1 == a1)
            {
                if (m2 > b1)
                {
                    best1 = cur;
                    b1 = m2;
                }
            }

        }

    }
    int a2 = score(best2, 1), b2 = score(best2, 2);
    for (int i = 0; i < 19; i++)
    {
        for (int j = 0; j < 19; j++)
        {
            if (chessboard[i][j] != 0)
            {
                continue;
            }
            point cur;
            cur.setXPoint(i);
            cur.setYPoint(j);
            int m1 = score(cur, 1);
            int m2 = score(cur, 2);
            if (m1 > a2)
            {
                best2 = cur;
                a2 = m1;
                b2 = m2;
            }
            else if (m1 == a2)
            {
                if (m2 > b2)
                {
                    best2 = cur;
                    b2 = m2;
                }
            }
        }
    }
    if (a1 >= a2)
    {
        play = best1;
    }
    else
    {
        play = best2;
    }
    return play;

}

bool bot::isInBoard(point p)
{
    if (p.getYPoint() >= 0 && p.getYPoint() < 19 && p.getXPoint() >= 0 && p.getXPoint() < 19)
    {
        return true;
    }
    else 
    {
        return false;
    }
}

point bot::newPoint(point p, dir d, int lenth)
{
    point p1 = { p.getYPoint() + d.dy * lenth, p.getXPoint() + d.dx * lenth };
    return p1;
}

int bot::score(point p, int who) //point p是被傳進去的點
{
    int win5 = 0,
        alive4 = 0, die4 = 0, ddie4 = 0,
        alive3 = 0, dalive3 = 0, die3 = 0,
        alive2 = 0, dalive2 = 0, die2 = 0,
        nothing = 0;

    int opp;
    if (who == 1)
    {
        opp = 2;
    }
    else
    {
        opp = 1;
    }


    for (int i = 1; i <= 4; i++)
    {
        dir d;
        switch (i) //個別判斷直向，橫向，右斜，左斜的情況
        {
        case 1:
            d = d1;
            break;
        case 2:
            d = d2;
            break;
        case 3:
            d = d3;
            break;
        case 4:
            d = d4;
            break;
        }

        int l = 1;
        point le, ri, p1;
        int left[5], right[5];
        p1 = newPoint(p, d, -1);
        le = p;

        while (isInBoard(p1) && chessboard[p1.getYPoint()][p1.getXPoint()] == who)
        {

            le = p1;
            p1 = newPoint(p1, d, l);
            l++;
        }

        p1 = newPoint(p, d, 1);
        ri = p;
        while (isInBoard(p1) && chessboard[p1.getYPoint()][p1.getXPoint()] == who) {
            ri = p1;
            p1 = newPoint(p1, d, l);
            l++;
        }

        for (int j = 1; j <= 4; j++)
        {
            p1 = newPoint(le, d, -j);
            if (isInBoard(p1))
            {
                left[j] = chessboard[p1.getYPoint()][p1.getXPoint()];
            }
            else
            {
                left[j] = opp;
            }
            p1 = newPoint(ri, d, j);
            if (isInBoard(p1))
            {
                right[j] = chessboard[p1.getYPoint()][p1.getXPoint()];
            }
            else
            {
                right[j] = opp;
            }
        }

        //看棋譜
        if (l == 5)
        {
            win5++;
        }
        else if (l == 4)
        {
            if (left[1] == 0 && right[1] == 0)
            {//alive4 
                alive4++;
            }
            else if (left[1] == 0 || right[1] == 0)
            {//die4
                die4++;
            }
            else
            {//nothing
                nothing++;
            }
        }
        else if (l == 3)
        {
            if ((left[1] == 0 && left[2] == who) || (right[1] == 0 && right[2] == who))
            {//ddie4
                ddie4++;
            }
            else if (left[1] == 0 && right[1] == 0 && (left[2] == 0 || right[2] == 0))
            {//alive3
                alive3++;
            }
            else if ((left[1] == 0 && left[2] == 0) || (right[1] == 0 && right[2] == 0))
            {//die3
                die3++;
            }
            else if (left[1] == 0 && right[1] == 0)
            {//die3
                die3++;
            }
            else
            {//nothing
                nothing++;
            }
        }
        else if (l == 2)
        {
            if ((left[1] == 0 && left[2] == who && left[3] == who) &&
                (right[1] == 0 && right[2] == who && right[3] == who))
            {//die4
                ddie4++;
            }
            else if (left[1] == 0 && right[1] == 0 &&
                ((left[2] == who && left[3] == 0) || (right[2] == who && right[3] == 0)))
            {//dalive3
                dalive3++;
            }
            else if ((left[1] == 0 && left[3] == 0 && left[2] == who) ||
                (right[1] == 0 && right[3] == 0 && right[2] == who))
            {//die3
                die3++;
            }
            else if ((left[1] == 0 && right[1] == 0) &&
                (left[2] == who || right[2] == who))
            {//die3
                die3++;
            }
            else if ((left[1] == 0 && left[2] == 0 && left[3] == who) ||
                (right[1] == 0 && right[2] == 0 && right[3] == who))
            {//die3
                die3++;
            }
            else if ((left[1] == 0 && right[1] == 0 && right[2] == 0 && right[3] == 0) ||
                (left[1] == 0 && left[2] == 0 && right[1] == 0 && right[2] == 0) ||
                (left[1] == 0 && left[2] == 0 && left[3] == 0 && right[1] == 0))
            {//alive2
                alive2++;
            }
            else if ((left[1] == 0 && left[2] == 0 && left[3] == 0) ||
                (right[1] == 0 && right[2] == 0 && right[3] == 0))
            {//die2
                die2++;
            }
            else
            {//nothing
                nothing++;
            }
        }
        else if (l == 1)
        {
            if ((left[1] == 0 && left[2] == who && left[3] == who && left[4] == who) ||
                (right[1] == 0 && right[2] == who && right[3] == who && right[4] == who))
            {//ddie4
                ddie4++;
            }
            else if ((left[1] == 0 && right[1] == 0) && ((left[2] == who && left[3] == who && left[4] == 0) ||
                (right[2] == who && right[3] == who && right[4] == 0)))
            {//dalive3
                dalive3++;
            }
            else if ((left[1] == 0 && right[1] == 0) &&
                ((left[2] == who && left[3] == who) || (right[2] == who && right[3] == who)))
            {//die3
                die3++;
            }
            else if ((left[1] == 0 && left[4] == 0 && left[2] == who && left[3] == who) ||
                (right[1] == 0 && right[4] == 0 && right[2] == who && right[3] == who))
            {//die3
                die3++;
            }
            else if ((left[1] == 0 && left[2] == 0 && left[3] == who && left[4] == who) ||
                (right[1] == 0 && right[2] == 0 && right[3] == who && right[4] == who))
            {//die3
                die3++;
            }
            else if ((left[1] == 0 && left[3] == 0 && left[2] == who && left[4] == who) ||
                (right[1] == 0 && right[3] == 0 && right[2] == who && right[4] == who))
            {//die3
                die3++;
            }
            else if ((left[1] == 0 && right[1] == 0 && right[3] == 0 && right[2] == who) && (left[2] == 0 || right[4] == 0))
            {//dalive2
                dalive2++;
            }
            else if ((right[1] == 0 && left[1] == 0 && left[3] == 0 && left[2] == who) &&
                (right[2] == 0 || left[4] == 0))
            {//dalive2
                dalive2++;
            }
            else if ((left[1] == 0 && right[1] == 0 && right[2] == 0 && right[4] == 0 && right[3] == who) ||
                (right[1] == 0 && left[1] == 0 && left[2] == 0 && left[4] == 0 && left[3] == who))
            {//dalive2
                dalive2++;
            }
            else if ((left[1] == 0 && left[3] == 0 && left[4] == 0 && left[2] == who) ||
                (right[1] == 0 && right[3] == 0 && right[4] == 0 && right[2] == who))
            {//die2
                die2++;
            }
            else if ((left[1] == 0 && right[1] == 0 && right[2] == 0 && left[2] == who) ||
                (right[1] == 0 && left[1] == 0 && left[2] == 0 && right[2] == who))
            {//die2
                die2++;
            }
            else if ((left[1] == 0 && left[2] == 0 && left[4] == 0 && left[3] == who) ||
                (right[1] == 0 && right[2] == 0 && right[4] == 0 && right[3] == who))
            {//die2
                die2++;
            }
            else if ((left[1] == 0 && left[2] == 0 && right[1] == 0 && left[3] == who) ||
                (right[1] == 0 && right[2] == 0 && left[1] == 0 && right[3] == who))
            {//die2
                die2++;
            }
            else if ((left[1] == 0 && left[2] == 0 && left[3] == 0 && left[4] == who) ||
                (right[1] == 0 && right[2] == 0 && right[3] == 0 && right[4] == who))
            {//die2
                die2++;
            }
            else
            {//nothing
                nothing++;
            }
        }
    }

    if (win5 >= 1)
        return 14;//5個連一條線win

    if (alive4 >= 1 || die4 >= 2 || (die4 >= 1 && alive3 >= 1))
        return 13;//活4,兩個死4,一個死4一個活3

    if (alive3 >= 2)
        return 12;//兩個活三

    if (die3 >= 1 && alive3 >= 1)
        return 11;//死3和高級一點的活三

    if (die4 >= 1)
        return 10;//比較危險的死4

    if (ddie4 >= 1)
        return 9;//比較不危險的死4

    if (alive3 >= 1)
        return 8;//一個活3

    if (dalive3 >= 1)
        return 7;//跳著的活3

    if (alive2 >= 2)
        return 6;//兩個活2

    if (alive2 >= 1)
        return 5;//活2

    if (dalive2 >= 1)
        return 4;//低威脅活2

    if (die3 >= 1)
        return 3;//死3

    if (die2 >= 1)
        return 2;//死2

    return 1;//没有威脅
}

void bot::botsee(point p, int a)//後面int判斷玩家or電腦的棋
{
    if (a == 1)
    {
        chessboard[p.getXPoint()][p.getYPoint()] = 1;
    }
    else
    {
        chessboard[p.getXPoint()][p.getYPoint()] = 2;
    }
}