
# include <Siv3D.hpp>

void Main()
{
	const Font font(30);
	double y=400,a=0,dy=0.45;
	bool mf = false;
	while (System::Update())
	{
		font(L"ようこそ、Siv3D の世界へ！").draw();
		if(!Input::KeyDown.pressed||mf)Circle(100,y,30).draw(Palette::Yellowgreen);
		else Rect(75,y+20,50,25).draw(Palette::Yellowgreen);
		if(mf){
			y += a;
			a += dy;
			if(y > 400)y = 400,mf = false;
		} else if(Input::KeyUp.pressed && !Input::KeyDown.pressed){
			mf = true;
			a = -12;
		}
		Circle(Mouse::Pos(), 50).draw({ 255, 0, 0, 127 });
	}
}
