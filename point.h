#ifndef POINT_H
#define POINT_H
#include<iostream>
#include<iomanip>
using namespace std;
class point
{
	

	public:
		point();
		point(int, int);
		int getXPoint();
		int getYPoint();
		void setXPoint(int);
		void setYPoint(int);

	private:
		int x;
		int y;



};
#endif
