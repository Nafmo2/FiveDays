

# include "Head.h"
void Main()
{
	const Font font(20);
	const Font fox(30);
	const Font Foo(40);
	const Texture texture(L"Title.png");
	const Texture back(L"Back.jpg");
	const Texture PL(L"Pl.png");
	const Texture toge(L"toge.png");
	const Texture sav(L"sav.png");
	double y=400,a=0,dy=0.65,ex=0,ey;
	double diff = 10,difx=10;
	int Time = 0,em=0,extra=0;
	int Ix,Iy;
	//mf Jump
	bool mf = false,ef = false,exf = true,rw = false,mode = true;
	Circle PC(100,y,20),EC(ex,360,50);
	Rect ER(ex,380,40,100);
	Player P;
	//Graphics::SetBackground(Color(L"#7f7f7f"));
	Window::SetTitle(L"Jump & Crouch");
	auto Ene = Color(L"#EE873D");
	RW(-1);
	while (System::Update())
	{
		back.draw();
		if(mode){
			texture.draw();
			Time = 0; diff = 10,difx = 10,extra = 0;
			mf = false,ef = false; P.init();
			if(Input::KeySpace.pressed)mode = false;
			continue;
		}
		//font(rw).draw(300,0,Palette::Red);
		if(!Input::KeyR.pressed){/*font(P.Alive()).draw();*/}
		else{
			
			//font(L"Reset Dead").draw(200,210,Palette::White,1.0);
			P.init(); 
			Time = 0; diff = 10,difx = 10,extra=0;
			mf = false,ef = false;
		}
		if(!P.Alive()){
			fox(L"Your Score is ",Time+extra).drawCenter(50,Palette::Aqua);
			font(L"Retry:Press R-Key! Exit:Press Enter").drawCenter(425);
			if(rw)RW(Time + extra);
			TextReader Read(L"ranking.txt",unspecified);
			for(int i = 1; i <= 5; i++){
				String st;
				Read.readLine(st);
				font(i,L":",st).drawCenter(110 + i * 50);
			}
			if(Input::KeyEnter.pressed){
				mode = true;
			}
			rw = false;
			continue;
		}
		exf = true;
		if(!Input::KeyDown.pressed || mf){
			PC.y = P.GetY(),PC.r = 20;
			Iy = P.GetY()-20;
		}else{
			PC.y=P.GetY()+25,PC.r=10;
			Iy = P.GetY()-20;
			exf = false;
		} 
		if(exf)PL.draw(P.GetX()-20,Iy);
		else PC.draw(Color(L"#FFFFFF"));
		if(Input::KeyUp.pressed && !Input::KeyDown.pressed && !mf){
			mf = true;
		}
		if(!P.Phy(mf))mf = false;
		if(ef){
			if(em == 0){
				EC.x = ex;
				//EC.draw(Ene);
				toge.draw(ex - 50,360 - 50);
				//1と同じ内容。
				if(EC.intersects(PC)){ 
					P.Dead();
					rw = true;
				}
			}
			else{
				ER.x = ex;
				ER.draw(em == 1?Ene:Palette::Aqua);
				sav.draw(ex,380);
				if(20<ex - P.GetX()&&ex - P.GetX()<20+50 && Input::KeyRight.clicked && !mf&& em==2){
					extra += 500;
					ef = false; 
				}
				//どうじょう
				if(ER.intersects(PC)){
					P.Dead(); 
					rw = true;
				}
			}
			ex -= difx;
			
			if(ex < 0)ef = false;
		}
		Rect(P.GetX()+50,0,1,480).drawFrame();
		//font(ex - P.GetX()).draw(400,20);
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
		font(L" Score:",Time+extra,L" HighScore:",HighScore).draw(220,20,Palette::White,1.0);
	}
}
