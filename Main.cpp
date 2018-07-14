
# include <Siv3D.hpp>

void Main()
{
	const Font font(30);
	double y=400,a=0,dy=0.65;
	double ex,ey;
	//ソースの汚さより速さでｗ
	int Time = 0,em=0;
	bool mf = false,ef = false;
	while (System::Update())
	{
		font(L"ようこそ、Siv3D の世界へ！").draw();
		if(!Input::KeyDown.pressed||mf)Circle(100,y,20).draw(Palette::Yellowgreen);
		else Rect(75,y+20,50,25).draw(Palette::Yellowgreen);
		if(mf){
			y += a;
			a += dy;
			if(y > 400)y = 400,mf = false;
		} else if(Input::KeyUp.pressed && !Input::KeyDown.pressed){
			mf = true;
			a = -12;
		}
		if(ef){
			if(em==0)Circle(ex,360,50).draw(Palette::Red);
			else Rect(ex,380,30,100).draw(Palette::Red);
			ex -= 5;
			if(ex < 0)ef = false;
		}
		if(!ef){
			ef = true;
			ex = 640,ey = 400;
			em=Random<int>(0,1);
		}
		font(ef).draw();
		//Circle(Mouse::Pos(), 50).draw({ 255, 0, 0, 127 });
		Time++;
	}
}
