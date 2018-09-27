#pragma once
# include <Siv3D.hpp>
#include <iostream>
#include <fstream>
#include <algorithm>
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
__int64 HighScore;
bool Ad = false;
long long int RW(int x){
	if(Ad)return HighScore;//Admin機能を使ったら弾く
	std::fstream fs,fe;
	long long int S[10];
	fs.open("ranking.txt",std::ios::in);
	//開けなかった場合 100～60までを書き込んだファイルを作る。
	if(!fs.is_open()){
		fs.close();
		std::fstream fw; fw.open("ranking.txt",std::ios::out | std::ios::trunc);
		for(int i = 0; i < 5; i++)fw << 100 - i * 10 << std::endl;
		fw.close();
		fs.open("ranking.txt",std::ios::in);
	}

	for(int i = 0; i < 5; i++)fs >> S[i];
	S[5] = x;
	//得点順にソート
	std::sort(S,S + 6);
	fs.close();
	fe.open("ranking.txt",std::ios::out | std::ios::trunc);
	for(int i = 0; i<5; i++)fe << S[5 - i] << std::endl;
	fe << std::endl;
	fe.close();
	HighScore = S[5];
	return HighScore;
}