#pragma once
# include <Siv3D.hpp>

class Player{

	double x,y,r;
	double a,dy;
	int mode;
	bool alive;
public:
	double GetX(){ return x; }
	double GetY(){ return y; }
	double GetR(){ return r; }
	bool Alive(){ return alive; }
	void Dead(){ alive = false; }
	void init(){
		x = 100;
		y = 400;
		dy = 0.65;
		a = 0;
		alive = true;
	}
	bool Phy(bool f){
		if(f){
			y += a;
			a += dy;
			if(y >= 400){
				y = 400,a = -12;
				return false;
			}
		}
		return true;
	}
	Player(){init();}
};

class Enemy{
	double x,y;
	double diff,difx;
	double GetX(){ return x; }
	double GetY(){ return y; }
	void init(){
		x = 100;
		y = 400;
	}

};