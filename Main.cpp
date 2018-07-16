

# include "Head.h"
void Main()
{
	const Font font(20);
	double y=400,a=0,dy=0.65,ex=0,ey;
	double diff = 10,difx=10;
	int Time = 0,em=0,extra=0;
	bool mf = false,ef = false;
	Circle PC(100,y,20),EC(ex,360,50);
	Rect ER(ex,380,30,100);
	Player P;
	//Graphics::SetBackground(Color(L"#7f7f7f"));
	auto Ene = Color(L"#EE873D");
	while (System::Update())
	{
		if(!Input::KeyR.pressed)font(P.Alive()).draw();
		else{
			font(L"Reset Dead").draw(200,210,Palette::White,1.0); P.init(); 
			Time = 0; diff = 10,difx = 10,extra=0;
			mf = false,ef = false;
		}
		if(!P.Alive()){
			font(L"Your Score is ",Time+extra).drawCenter(240);
			continue;
		}
		if(!Input::KeyDown.pressed || mf){
			PC.y = P.GetY(),PC.r = 20;
		}
		else{
			PC.y=P.GetY()+25,PC.r=10;
		} 
		PC.draw(Color(L"#FFFFFF"));
		if(Input::KeyUp.pressed && !Input::KeyDown.pressed && !mf){
			mf = true;
		}
		if(!P.Phy(mf))mf = false;
		if(ef){
			if(em == 0){
				EC.x = ex;
				EC.draw(Ene);
				if(EC.intersects(PC)){ P.Dead(); }
			}
			else{
				ER.x = ex;
				ER.draw(em == 1?Ene:Palette::Aqua);
				if(20<ex - P.GetX()&&ex - P.GetX()<20+50 && Input::KeyRight.clicked && !mf&& em==2){
					extra += 1000;
					ef = false; 
				}
				if(ER.intersects(PC)){ P.Dead(); }
			}
			ex -= difx;
			
			if(ex < 0)ef = false;
		}
		//Rect(P.GetX(),0,50,480).drawFrame();
		font(ex - P.GetX()).draw(400,20);
		if(!ef){
			ef = true;
			ex = 640,ey = 400;
			em = Random<int>(0,1);
			if(em == 1)em+=Random<int>(0,1);
			difx=Random<int>(Max<int>(10,diff-6),diff)/2.0;
		}
		Time++;
		if(!(Time % 120) && diff < 32){
			diff += 2; 
		}
		font(L"D:",diff,L" Dx:",difx,L" S:",Time+extra).draw(0,50,Palette::White,1.0);
	}
}
