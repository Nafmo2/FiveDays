
# include <Siv3D.hpp>

void Main()
{
	const Font font(30);
	double y=400,a=0,dy=0.65;
	double ex=0,ey;
	int Time = 0,em=0;
	bool mf = false,ef = false,dead = false;
	Circle PC(100,y,20),EC(ex,360,50);
	Rect ER(ex,380,30,100);
	while (System::Update())
	{
		
	//	font(L"ようこそ、Siv3D の世界へ！").draw();
		if(!Input::KeyDown.pressed || mf){
			PC.y = y,PC.r = 20;
		}
		else{
			PC.y=y+25,PC.r=10;
		} 
		PC.draw(Palette::Yellowgreen);
		if(mf){
			y += a;
			a += dy;
			if(y > 400)y = 400,mf = false;
		} else if(Input::KeyUp.pressed && !Input::KeyDown.pressed){
			mf = true;
			a = -12;
		}
		if(ef){
			if(em == 0){
				EC.x = ex;
				EC.draw(Palette::Red);
				if(EC.intersects(PC)){ dead = true; }
			}
			else{
				ER.x = ex;
				ER.draw(Palette::Red);
				if(ER.intersects(PC)){ dead = true; }
			}
			ex -= 5;
			
			if(ex < 0)ef = false;
		}
		if(!ef){
			ef = true;
			ex = 640,ey = 400;
			em=Random<int>(0,1);
		}
		if(!Input::KeyR.pressed)font(dead).draw();
		else{ font(L"Reset Dead").draw(200,210,Palette::White,1.0); dead = false; }
		//Circle(Mouse::Pos(), 50).draw({ 255, 0, 0, 127 });
		Time++;
	}
}
