#include <iostream>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL_ttf.h>
#include <SDL2/SDL2_gfx.h>
#include <SDL_mixer.h>
#include <string>
#include <fstream>
#include <sstream>
#include <ctime>
#include <cmath>


//AmirReaza Imani Eimani
//Mohsen Kamalabadi Farahani


struct Brick
{
    int x;
    int y;
    int strength;
};

using namespace std;

void window_color(SDL_Renderer *Renderer, int R, int G, int B);
void textColor(SDL_Renderer *renderer,int x,int y,const char * text,const char * font,int font_size,SDL_Color textColor,double angle,short flip_num);
void textRGBA(SDL_Renderer *renderer,int x,int y,const char * text,const char * font,int font_size,int R,int G,int B, int A,double angle,short flip_num);
bool Name_Existence(string );
string Recent_History(string );
void History(string ,string ,SDL_Renderer*);
int Msgbox_SL();
bool Load_Data(string ,int* ,int* ,int* ,int* ,Brick* ,SDL_Renderer *);
void Load(int ,int ,int ,int ,Brick [],SDL_Renderer *);
void Save(string ,int ,int ,int ,int ,int ,Brick []);
void Edit_Record(string ,int );
void Save_Record(string ,int );
double power(double ,int );
void Random(int ,Brick [],int ,SDL_Renderer* );
void draw(Brick [],int ,SDL_Renderer* );
void Shift(Brick [],int ,SDL_Renderer* );
string Reverse(string );
string int_to_string(int );
int Pause_Game();
int Msgbox_SL2();



int main( int argc, char * argv[] )
{

    cout<<"                           <<  AMIR REAZA IMANI AND MOHSEN KAMALABADI FARAHANI PROUDLY PRESENT >>  "<<endl;
    int x_line,y_line;
    int level=1,score=0,lives=3;
    int broken=0,quantity=0,Damage=1;
    int billiard;
    string bill;
    Brick brick[360];
    string Name;
    cout<<"Pleas Enter Your Name: ";
    cin>>Name;
    cout<<endl<<endl;
    a:
    cout<<"Pleas choose Game Mode"<<endl<<"   (1) Single Player  (2) Two Players"<<endl;
    int mode;
    cin>>mode;
    if(mode!=1 && mode!=2)
    {
               cout<<"What the faz akhavi?!"<<endl;
               goto a;

    }

    e:
    cout<<"Pleas choose difficulity"<<endl<<"   (1) Easy  (2) Medium (3) Hard "<<endl;
    int diff;
    cin>>diff;
    if( diff!=1 && diff!=2 && diff!=3)
    {
         cout<<"What the faz akhavi?!"<<endl;
               goto e;
    }

    b:
    cout<<"Please Choose Your Game Background "<<endl<<"   (1) Desert  (2) Sea   (3) City   (4) Galaxy   (5) Gym"<<endl<<endl;
    int backg;
    string backgr;
    cin>>backg;
     if(backg==1)
        backgr="AA.png";
    else if(backg==2)
        backgr="sea.jpg";
    else if(backg==3)
        backgr="city.jpg";
    else if(backg==4)
        backgr="galaxy.jpg";
    else if(backg==5)
        backgr="gym.jpg";
        else
          {
               cout<<"What the faz akhavi?!"<<endl;
               goto b;
          }
    c:
    cout<<"Please Choose Your Ball Color"<<endl<<"   (1) Orange   (2) Black   (3) Yellow   (4) Blue   (5) Purple"<<endl<<endl;
    cin>>billiard;
    if(billiard!=1 && billiard!=2 && billiard!=3 && billiard!=4 && billiard!=5 )
    {
       cout<<"What the faz akhavi?!"<<endl;
               goto c;
    }
    int music;
    string musicn;
    d:
    cout<<"Please Choose Music Of The Game"<<endl<<"   (1)  Levan Polka  (2) Metal   (3) Final Fantacy   (4) Super Mario Bros   (5) Sonic "<<endl;
    cin>>music;
     if(music==1)
        musicn="game.mp3";
    else if(music==2)
        musicn="Metal.mp3";
    else if(music==3)
        musicn="Final Fantacy.mp3";
    else if(music==4)
        musicn="Super Mario Bros.mp3";
    else if(music==5)
        musicn="Sonic.mp3";
        else
          {
               cout<<"What the faz akhavi?!"<<endl;
               goto d;
          }
           SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
    Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,2048);
    Mix_Music *GameSound = Mix_LoadMUS(musicn.c_str());

    bool exist=Name_Existence(Name),Ex;
    int Chose;

    if(billiard==1)
        bill="5.png";
    else if(billiard==2)
        bill="8.png";
    else if(billiard==3)
        bill="9.png";
    else if(billiard==4)
        bill="10.png";
    else if(billiard==5)
        bill="12.png";

    int W = 1500;
    int L = 780;
    Uint32 SDL_flags = SDL_INIT_VIDEO | SDL_INIT_TIMER ;
    Uint32 WND_flags = SDL_WINDOW_SHOWN;
    TTF_Init();
    SDL_Window *m_window;
    SDL_Renderer *m_renderer;
    SDL_Texture *mTexture=NULL;
    SDL_Init( SDL_flags );
    SDL_CreateWindowAndRenderer( W, L, WND_flags, &m_window, &m_renderer );
    SDL_RaiseWindow(m_window);
    SDL_DisplayMode DM;
    SDL_GetCurrentDisplayMode(0, &DM);
    window_color(m_renderer,255,255,255);
    SDL_RenderPresent(m_renderer);

    //Mix_PlayMusic(GameSound,-1);
    Mix_Chunk *tick = Mix_LoadWAV("tick.WAV");
    Mix_Chunk *miss = Mix_LoadWAV("miss.WAV");
    Mix_Chunk *Up = Mix_LoadWAV("Up.WAV");
    Mix_Chunk *Save_Load = Mix_LoadWAV("Save.WAV");
    Mix_Chunk *End = Mix_LoadWAV("joone del.mp3");

    int img_w1, img_h1;
    int img_w2, img_h2;
    int img_w3, img_h3;
    int img_w4n, img_h4n;
    int img_w4, img_h4;
    int img_w5, img_h5;
    int img_w6, img_h6;
    int img_w7, img_h7;
    int img_w8, img_h8;
    int img_w9, img_h9;
    int img_w10, img_h10;
    int present_w,present_h;
    int x_ball=650,x_ball2=350,y_ball=625;
    double Vx,Vy;
    if(diff==1)
    Vx=3,Vy=3;
    else if(diff==2)
    Vx=4,Vy=4;
    else if(diff==3)
    Vx=5,Vy=5;
    int V_x=Vx,V_y=Vy;
    int x_plat=600,x_plat2=300,y_plat=670,V=15,V1=7;
    bool Transfer=false,Space=false,shift=false,strike=false,broke=false;
    int a=150,b=40,t,S,i;
    bool quit=false,Stop=false,rocket=false,explode=false;


    SDL_Texture* present_img = NULL;

    SDL_Event *e = new SDL_Event();

    present_img = IMG_LoadTexture(m_renderer, "present.jpg");

    SDL_QueryTexture(present_img, NULL, NULL, &present_w, &present_h);
    SDL_Rect present;
    present.x = 0;
    present.y = 0;
    present.w = 1500;
    present.h = 780;
    SDL_RenderCopy(m_renderer, present_img, NULL, &present);
    SDL_RenderPresent( m_renderer );
    while(e->type != SDL_KEYDOWN)
        SDL_PollEvent(e);

    SDL_DestroyTexture(present_img);




    const char * text1 ;
    const char * font="MAGNETOB.ttf";
    int x1_position=390;
    int y1_position=753;
    int R=255;
    int G =2;
    int B=3;
    int A=0.5;

    const char * text2 ;
    int x2_position=810;
    int y2_position=753;

    const char * text3 ;
    int x3_position=1230;
    int y3_position=753;

    SDL_Texture* m_img1 = NULL;
    m_img1 = IMG_LoadTexture(m_renderer, backgr.c_str());
    SDL_QueryTexture(m_img1, NULL, NULL, &img_w1, &img_h1);
    SDL_Rect texr1;
    texr1.x = 0;
    texr1.y = 0;
    texr1.w = 1500;
    texr1.h = 750;
    SDL_RenderCopy(m_renderer, m_img1, NULL, &texr1);

    SDL_Texture* m_img2 = NULL;
    m_img2 = IMG_LoadTexture(m_renderer, bill.c_str());
    SDL_QueryTexture(m_img2, NULL, NULL, &img_w2, &img_h2);
    SDL_Rect texr2;
    if(mode==1)
    {
    texr2.x = x_ball;
    }
   else if(mode==2)
   {
    texr2.x = x_ball2;
   }
   texr2.y = y_ball;
    texr2.w = 50;
    texr2.h = 50;
    SDL_RenderCopy(m_renderer, m_img2, NULL, &texr2);

          SDL_Texture* m_img3 = NULL;
    m_img3 = IMG_LoadTexture(m_renderer, "plat.png");
    SDL_QueryTexture(m_img3, NULL, NULL, &img_w3, &img_h3);
    SDL_Rect texr3;
    if(mode==1)
    {
       texr3.x = 600;
    texr3.y = 670;
    }
    else if(mode==2)
    {
         texr3.x = 300;
    texr3.y = 670;
    }
    texr3.w = 150;
    texr3.h = 40;
    SDL_RenderCopy(m_renderer, m_img3, NULL, &texr3);


         SDL_Texture* m_img4 = NULL;
    m_img4= IMG_LoadTexture(m_renderer, "plate_2.png");
    SDL_QueryTexture(m_img4, NULL, NULL, &img_w3, &img_h3);
    SDL_Rect texr4;
    texr4.x=1050;
    texr4.y=670;
    texr4.w=150;
     texr4.h=40;


    SDL_Texture* Board = NULL;
    Board = IMG_LoadTexture(m_renderer, "Board.png");
    SDL_QueryTexture(Board, NULL, NULL, &img_w7, &img_h7);
    SDL_Rect Boa;
    Boa.x = 0;
    Boa.y = 750;
    Boa.w = 1500;
    Boa.h = 30;
    SDL_RenderCopy(m_renderer, Board, NULL, &Boa);

    SDL_Texture* Level = NULL;
    Level = IMG_LoadTexture(m_renderer, "Level.png");
    SDL_QueryTexture(Level, NULL, NULL, &img_w4, &img_h4);
    SDL_Rect Lev;
    Lev.x = 300;
    Lev.y = 750;
    Lev.w = 70;
    Lev.h = 30;
    SDL_RenderCopy(m_renderer, Level, NULL, &Lev);

    SDL_Texture* Lives = NULL;
    Lives = IMG_LoadTexture(m_renderer, "Lives.png");
    SDL_QueryTexture(Lives, NULL, NULL, &img_w5, &img_h5);
    SDL_Rect Liv;
    Liv.x = 700;
    Liv.y = 750;
    Liv.w = 90;
    Liv.h = 30;
    SDL_RenderCopy(m_renderer, Lives, NULL, &Liv);

    SDL_Texture* Score = NULL;
    Score = IMG_LoadTexture(m_renderer, "Score.png");
    SDL_QueryTexture(Score, NULL, NULL, &img_w6, &img_h6);
    SDL_Rect Sco;
    Sco.x = 1100;
    Sco.y = 750;
    Sco.w = 100;
    Sco.h = 30;
    SDL_RenderCopy(m_renderer, Score, NULL, &Sco);

    SDL_Texture* Pause = NULL;
    Pause = IMG_LoadTexture(m_renderer, "Pause.png");
    SDL_QueryTexture(Pause, NULL, NULL, &img_w8, &img_h8);
    SDL_Rect Pau;
    Pau.x = 400;
    Pau.y = 150;
    Pau.w = 500;
    Pau.h = 300;


    SDL_Texture* Rocket = NULL;
    Rocket = IMG_LoadTexture(m_renderer, "Rocket.png");
    SDL_QueryTexture(Rocket, NULL, NULL, &img_w8, &img_h8);
    SDL_Rect Roc;

    SDL_Texture *texture=IMG_LoadTexture(m_renderer,"images (5).png");
    SDL_QueryTexture(texture, NULL, NULL, &img_w9, &img_h9);
    SDL_Rect rect1[5];
    SDL_Rect rect2[5];

    rect1[0]={20,10,30,60};
    rect1[1]={64,0,64,90};
    rect1[2]={120,0,90,110};
    rect1[3]={30,110,100,120};
    rect1[4]={135,110,100,120};

    SDL_Texture* Over = NULL;
    Over = IMG_LoadTexture(m_renderer, "Over.png");
    SDL_QueryTexture(Over, NULL, NULL, &img_w10, &img_h10);
    SDL_Rect Ove;
    Ove.x = 400;
    Ove.y = 150;
    Ove.w = 500;
    Ove.h = 300;


    if(exist)
    {
        SDL_RenderCopy(m_renderer, Pause, NULL, &Pau);
        History(Recent_History(Name),Name,m_renderer);
        Chose=Msgbox_SL();
        if(Chose==0)
        {
            cout<<"Start New Game  "<<Name;
        }else if(Chose==1)
        {
            cout<<"Load   "<<Name;
        }
    }else
        Chose=0;

    SDL_RenderCopy(m_renderer, m_img1, NULL, &texr1);
    SDL_RenderCopy(m_renderer, m_img2, NULL, &texr2);
    SDL_RenderCopy(m_renderer, m_img3, NULL, &texr3);
    if(mode==2)
    {
       SDL_RenderCopy(m_renderer, m_img4, NULL, &texr4);
    }
    SDL_RenderCopy(m_renderer, Board, NULL, &Boa);
    SDL_RenderCopy(m_renderer, Level, NULL, &Lev);
    SDL_RenderCopy(m_renderer, Lives, NULL, &Liv);
    SDL_RenderCopy(m_renderer, Score, NULL, &Sco);



    if(Chose==1)
    {
        Ex=Load_Data(Name,&level,&lives,&score,&Damage,&brick[0],m_renderer);
        if(Ex)
        {
            Mix_PlayChannel(-1,Save_Load,0);
            quantity=level*6;
        }
        else
        {
            Random(level,brick,quantity,m_renderer);
            quantity+=6;
            SDL_RenderPresent( m_renderer );
        }
        cout<<level<<" "<<lives<<" "<<score<<endl;
    }
    else
    {
        Random(level,brick,quantity,m_renderer);
        quantity+=6;
        SDL_RenderPresent( m_renderer );
    }

    text1=int_to_string(level).c_str();
    text2=int_to_string(lives).c_str();
    text3=int_to_string(score).c_str();

    textRGBA(m_renderer,x1_position,y1_position,text1,font,24,R,G,B,A,NULL,NULL);
    textRGBA(m_renderer,x2_position,y2_position,text2,font,24,R,G,B,A,NULL,NULL);
    textRGBA(m_renderer,x3_position,y3_position,text3,font,24,R,G,B,A,NULL,NULL);

    const Uint8 *keyboard_state_array = SDL_GetKeyboardState(NULL);
    while(!quit)
    {
        if(Space)
        {
            texr2.x += Vx;
            texr2.y -= Vy;
        }

        if(Vy==0)
            Vy=1;


        if(strike)
        {
            Mix_PlayChannel(-1,tick,0);
            t=brick[S].strength;
            brick[S].strength-=Damage;
            Damage-=t;
            if(brick[S].strength<=0)
                broke=true;
            cout<<"S "<<strike<<" brick "<<S<<" "<<brick[S].strength<<" D "<<Damage<<" L "<<level<<" score "<<score<<endl;
        }
        strike=false;

        if(broke)
        {
            broken++;
            broke=false;
        }

        if(Damage<=0)
        {
            score+=level*broken;
            broken=0;
            level++;
            Space=false;
            texr2.x=x_ball;
            texr2.y=y_ball;
            texr3.x=x_plat;
            texr3.y=y_plat;
            SDL_RenderCopy(m_renderer, m_img1, NULL, &texr1);
            SDL_RenderCopy(m_renderer, m_img2, NULL, &texr2);
            SDL_RenderCopy(m_renderer, m_img3, NULL, &texr3);
            if(mode==2)
            {
            SDL_RenderCopy(m_renderer, m_img4, NULL, &texr4);

            }
            Shift(brick,quantity,m_renderer);
            if(Vy<0)
                Vy*=1;
            shift=true;
            Damage=level;
            SDL_RenderCopy(m_renderer, Board, NULL, &Boa);
            SDL_RenderCopy(m_renderer, Level, NULL, &Lev);
            SDL_RenderCopy(m_renderer, Lives, NULL, &Liv);
            SDL_RenderCopy(m_renderer, Score, NULL, &Sco);
            text1=int_to_string(level).c_str();
            text2=int_to_string(lives).c_str();
            text3=int_to_string(score).c_str();

            textRGBA(m_renderer,x1_position,y1_position,text1,font,24,R,G,B,A,NULL,NULL);
            textRGBA(m_renderer,x2_position,y2_position,text2,font,24,R,G,B,A,NULL,NULL);
            textRGBA(m_renderer,x3_position,y3_position,text3,font,24,R,G,B,A,NULL,NULL);

        }


        if(shift)
        {
            SDL_RenderCopy(m_renderer, m_img1, NULL, &texr1);
            SDL_RenderCopy(m_renderer, m_img2, NULL, &texr2);
            SDL_RenderCopy(m_renderer, m_img3, NULL, &texr3);
              if(mode==2)
    {
       SDL_RenderCopy(m_renderer, m_img4, NULL, &texr4);
    }

            Random(level,brick,quantity,m_renderer);
            quantity+=6;
        }

        if(Space || Transfer || shift || rocket)
        {
        SDL_RenderCopy(m_renderer, m_img1, NULL, &texr1);
        SDL_RenderCopy(m_renderer, m_img2, NULL, &texr2);
        SDL_RenderCopy(m_renderer, m_img3, NULL, &texr3);
        if(mode==2)
        {
       SDL_RenderCopy(m_renderer, m_img4, NULL, &texr4);
        }
        if(rocket)
        {
            SDL_RenderCopy(m_renderer,Rocket,NULL,&Roc);
             Roc.y-=2;
        }
        draw(brick,quantity,m_renderer);
        SDL_RenderPresent( m_renderer );
        SDL_Delay(10);
        }
        Transfer=false;
        shift=false;

        if(mode==1)
        {
            SDL_PollEvent(e);
        if(e->type == SDL_KEYDOWN || e->type == SDL_KEYUP)
        {

               if ((keyboard_state_array[SDL_SCANCODE_D] || keyboard_state_array[SDL_SCANCODE_RIGHT] ))
                {
                    texr3.x+=V;
                    Transfer=true;
                    if(!Space)
                        texr2.x+=V;
                }
                else if ((keyboard_state_array[SDL_SCANCODE_A]) || (keyboard_state_array[SDL_SCANCODE_LEFT]))
                {
                    texr3.x-=V;
                    Transfer=true;
                    if(!Space)
                        texr2.x-=V;
                }
                if(keyboard_state_array[SDL_SCANCODE_SPACE])
                    Space=true;
                if(keyboard_state_array[SDL_SCANCODE_P])
                    Stop=true;
                if (keyboard_state_array[SDL_SCANCODE_LSHIFT] && (keyboard_state_array[SDL_SCANCODE_J]) && keyboard_state_array[SDL_SCANCODE_LALT])
                {
                            lives++;
                            if(lives>3)
                                lives=3;
                            SDL_RenderCopy(m_renderer, Board, NULL, &Boa);
                            SDL_RenderCopy(m_renderer, Level, NULL, &Lev);
                            SDL_RenderCopy(m_renderer, Lives, NULL, &Liv);
                            SDL_RenderCopy(m_renderer, Score, NULL, &Sco);
                            text2=int_to_string(lives).c_str();
                            textRGBA(m_renderer,x2_position,y2_position,text2,font,24,R,G,B,A,NULL,NULL);
                            textRGBA(m_renderer,x1_position,y1_position,text1,font,24,R,G,B,A,NULL,NULL);
                            textRGBA(m_renderer,x3_position,y3_position,text3,font,24,R,G,B,A,NULL,NULL);

                }

                 if (keyboard_state_array[SDL_SCANCODE_LSHIFT] && (keyboard_state_array[SDL_SCANCODE_R]) && keyboard_state_array[SDL_SCANCODE_LALT])
                 {
                     rocket=true;
                     Roc={texr3.x-30,texr3.y-40,30,120};
                     SDL_RenderCopy(m_renderer,Rocket,NULL,&Roc);
                     SDL_RenderPresent(m_renderer);
                 }
                }

        }
        else if(mode==2)
        {
    SDL_PollEvent(e);
        if(e->type == SDL_KEYDOWN || e->type == SDL_KEYUP)
        {

               if (keyboard_state_array[SDL_SCANCODE_D] && !(keyboard_state_array[SDL_SCANCODE_A]))
                {
                    texr3.x+=V;
                    Transfer=true;
                    if(!Space)
                        texr2.x+=V;
                }
                else if (!(keyboard_state_array[SDL_SCANCODE_D]) && (keyboard_state_array[SDL_SCANCODE_A]))
                {
                    texr3.x-=V;
                    Transfer=true;
                    if(!Space)
                        texr2.x-=V;
                }
                if(keyboard_state_array[SDL_SCANCODE_SPACE])
                    Space=true;
                if(keyboard_state_array[SDL_SCANCODE_P])

                              Stop=true;

                }
                    SDL_PollEvent(e);
        if(e->type == SDL_KEYDOWN || e->type == SDL_KEYUP)
        {

               if (keyboard_state_array[SDL_SCANCODE_RIGHT] && !(keyboard_state_array[SDL_SCANCODE_LEFT]))
                {
                    texr4.x+=V1;
                    Transfer=true;
                  //G  if(!Space)
                    //    texr2.x+=V;
                }
                else if (!(keyboard_state_array[SDL_SCANCODE_RIGHT]) && (keyboard_state_array[SDL_SCANCODE_LEFT]))
                {
                    texr4.x-=V1;
                    Transfer=true;
                  //  if(!Space)
                     //   texr2.x-=V;
                }
                if(keyboard_state_array[SDL_SCANCODE_SPACE])
                    Space=true;
                if(keyboard_state_array[SDL_SCANCODE_P])
                    Stop=true;
                if (keyboard_state_array[SDL_SCANCODE_LSHIFT] && (keyboard_state_array[SDL_SCANCODE_J]) && keyboard_state_array[SDL_SCANCODE_LALT])
                {
                            lives++;
                            if(lives>3)
                                lives=3;
                            SDL_RenderCopy(m_renderer, Board, NULL, &Boa);
                            SDL_RenderCopy(m_renderer, Level, NULL, &Lev);
                            SDL_RenderCopy(m_renderer, Lives, NULL, &Liv);
                            SDL_RenderCopy(m_renderer, Score, NULL, &Sco);
                            text2=int_to_string(lives).c_str();
                            textRGBA(m_renderer,x2_position,y2_position,text2,font,24,R,G,B,A,NULL,NULL);
                            textRGBA(m_renderer,x1_position,y1_position,text1,font,24,R,G,B,A,NULL,NULL);
                            textRGBA(m_renderer,x3_position,y3_position,text3,font,24,R,G,B,A,NULL,NULL);

                }
                 if (keyboard_state_array[SDL_SCANCODE_LSHIFT] && (keyboard_state_array[SDL_SCANCODE_R]) && keyboard_state_array[SDL_SCANCODE_LALT])
                 {
                     rocket=true;
                     Roc={texr3.x-30,texr3.y-40,30,120};
                     SDL_RenderCopy(m_renderer,Rocket,NULL,&Roc);
                     SDL_RenderPresent(m_renderer);
                 }
                }
        }

        if(texr2.x>=1450)
            Vx*=-1;
        if(texr2.x<=0)
            Vx*=-1;
        if(texr2.y>=700)
        {
            Mix_PlayChannel(-1,miss,0);
            Space=false;
            if(mode==1)
            {
            texr2.x=x_ball;
            texr2.y=y_ball;
            texr3.x=x_plat;
            texr3.y=y_plat;
            }
          else if(mode==2)
          {
            texr2.x=x_ball2;
            texr2.y=y_ball;
            texr3.x=x_plat2;
            texr3.y=y_plat;
          }
            lives--;
            if(Vy<0)
                Vy*=-1;
            SDL_RenderCopy(m_renderer, Board, NULL, &Boa);
            SDL_RenderCopy(m_renderer, Level, NULL, &Lev);
            SDL_RenderCopy(m_renderer, Lives, NULL, &Liv);
            SDL_RenderCopy(m_renderer, Score, NULL, &Sco);
            rocket=false;
            text1=int_to_string(level).c_str();
            text2=int_to_string(lives).c_str();
            text3=int_to_string(score).c_str();

            textRGBA(m_renderer,x1_position,y1_position,text1,font,24,R,G,B,A,NULL,NULL);
            textRGBA(m_renderer,x2_position,y2_position,text2,font,24,R,G,B,A,NULL,NULL);
            textRGBA(m_renderer,x3_position,y3_position,text3,font,24,R,G,B,A,NULL,NULL);
        }
        if(mode==1)
        {
             if(texr2.y<=0)
            Vy*=-1;
        if(texr2.x>=texr3.x-20 && texr2.x<=texr3.x+130 && texr2.y>=texr3.y-50 && texr2.y<=texr3.y-45 && Vy<0)
            Vy*=-1;
        if(texr2.x>=texr3.x-60 && texr2.x<=texr3.x-20 && texr2.y>=texr3.y-50 && texr2.y<=texr3.y-45 && Vy<0)
        {
            Vx=-(rand()%V_x+1);
            Vy=sqrt(power(V_x,2)*2-power(Vx,2));
        }
        if(texr2.x>=texr3.x+130 && texr2.x<=texr3.x+160 && texr2.y>=texr3.y-50 && texr2.y<=texr3.y-45 && Vy<0)
        {
            Vx=rand()%V_x+1;
            Vy=sqrt(power(V_x,2)*2-power(Vx,2));
        }
        }
        else if(mode==2)
        {
              if(texr2.y<=0)
            Vy*=-1;
        if(((texr2.x>=texr3.x-20 && texr2.x<=texr3.x+130 && texr2.y<=texr3.y-45 && texr2.y>=texr3.y-50 ) || (texr2.x>=texr4.x-20 && texr2.y>=texr4.y-50 && texr2.x<=texr4.x+130 && texr2.y<=texr4.y-45)) && Vy<0)
            Vy*=-1;
        if(((texr2.x>=texr3.x-60 && texr2.y<=texr3.y-45 && texr2.x<=texr3.x-20  && texr2.y>=texr3.y-50)  || (texr2.x>=texr4.x-60 && texr2.y>=texr4.y-50 && texr2.x<=texr4.x-20 && texr2.y<=texr4.y-45)) && Vy<0)
        {
            Vx=-(rand()%V_x+1);
            Vy=sqrt(power(V_x,2)*2-power(Vx,2));
        }
        if(((texr2.x>=texr3.x+130 &&  texr2.x<=texr3.x+160 && texr2.y<=texr3.y-45  &&  texr2.y>=texr3.y-50) || (texr2.x>=texr4.x+130 && texr2.y>=texr4.y-50 && texr2.x<=texr4.x+160 && texr2.y<=texr4.y-45)) && Vy<0)
        {
            Vx=rand()%V_x+1;
            Vy=sqrt(power(V_x,2)*2-power(Vx,2));
        }
        }

        if(mode==1)
        {
            if(texr3.x>1350)
        {
            texr3.x=1350;
            if(!Space)
                texr2.x=1400;
        }
        }
        else if(mode==2)
        {
                if(texr3.x>600)
        {
            texr3.x=600;
            if(!Space)
                texr2.x=650;
        }
                 if(texr4.x>1350)
        {
            texr4.x=1350;

        }
        }
        if(mode==1)
        {
           if(texr3.x<0)
        {
            texr3.x=0;
            if(!Space)
                texr2.x=50;
        }
        }
        else if(mode==2)
        {
                  if(texr3.x<0)
        {
            texr3.x=0;
            if(!Space)
                texr2.x=50;
        }
              if(texr4.x<750)
        {
            texr4.x=750;

        }
        }

        for(i=0;i<quantity;i++)
        {
            if(brick[i].strength>0 && Space)
            {
                if(texr2.x>=brick[i].x-45 && texr2.x<=brick[i].x+a-5 && texr2.y>=brick[i].y+b && texr2.y<=brick[i].y+b+3)
                {
                    strike=true;
                    S=i;
                    Vy*=-1;
                }
                else if(texr2.x>=brick[i].x-43 && texr2.x<=brick[i].x-37 && texr2.y>=brick[i].y-45 && texr2.y<=brick[i].y+b+5)
                {
                    strike=true;
                    S=i;
                    Vx*=-1;
                }
                else if(texr2.x>=brick[i].x+a-3 && texr2.x<=brick[i].x+a+3 && texr2.y>=brick[i].y-45 && texr2.y<=brick[i].y+b+5)
                {
                    strike=true;
                    S=i;
                    Vx*=-1;
                }
                else if(texr2.x>=brick[i].x-45 && texr2.x<=brick[i].x+a-5 && texr2.y>=brick[i].y-52 && texr2.y<=brick[i].y-49)
                {
                    strike=true;
                    S=i;
                    Vy*=-1;
                }
                else if(texr2.x>=brick[i].x-50 && texr2.x<=brick[i].x-47 && texr2.y>=brick[i].y-5 && texr2.y<=brick[i].y)
                {
                    strike=true;
                    S=i;
                    Vx=rand()%(V_x*2+1)-V_x;
                    Vy=sqrt(power(V_x,2)*2-power(Vx,2));
                }
                else if(texr2.x>=brick[i].x+a-3 && texr2.x<=brick[i].x+a+3 && texr2.y>=brick[i].y-5 && texr2.y<=brick[i].y)
                {
                    strike=true;
                    S=i;
                    Vx=rand()%(V_x*2+1)-V_x;
                    Vy=sqrt(power(V_x,2)*2-power(Vx,2));
                }
                else if(texr2.x>=brick[i].x-53 && texr2.x<=brick[i].x-47 && texr2.y>=brick[i].y+b && texr2.y<=brick[i].y+b+5)
                {
                    strike=true;
                    S=i;
                    Vx=rand()%(V_x*2+1)-V_x;
                    Vy=-sqrt(power(V_x,2)*2-power(Vx,2));
                }
                else if(texr2.x>=brick[i].x+a-3 && texr2.x<=brick[i].x+a+3 && texr2.y>=brick[i].y+b-5 && texr2.y<=brick[i].y+b+10)
                {
                    strike=true;
                    S=i;
                    Vx=rand()%(V_x*2+1)-V_x;
                    Vy=-sqrt(power(V_x,2)*2-power(Vx,2));
                }
            }
            if(brick[i].strength>0 && rocket)
            {
                 if(Roc.x>=brick[i].x-30 && Roc.x<=brick[i].x+a && Roc.y>=brick[i].y+b && Roc.y<=brick[i].y+b+3)
                 {
                     rocket=false;
                     explode=true;
                 }
            }
            if(rocket && Roc.y<=-120)
            {
                rocket=false;
            }
        }

        if(explode)
        {
            rect2[0]={Roc.x-40,Roc.y,100,200};
            rect2[1]={Roc.x-100,Roc.y-100,200,400};
            rect2[2]={400,Roc.y-200,400,600};
            rect2[3]={0,0,1400,660};
            rect2[4]={Roc.x-100,Roc.y,300,400};

            int frame=0;
            while(frame<5)
            {
                SDL_RenderCopy(m_renderer, m_img1, NULL, &texr1);
                SDL_RenderCopy(m_renderer, m_img2, NULL, &texr2);
                SDL_RenderCopy(m_renderer, m_img3, NULL, &texr3);
                SDL_RenderCopy(m_renderer, m_img4, NULL, &texr4);
                if(frame<4)
                    draw(brick,quantity,m_renderer);
                SDL_RenderCopy(m_renderer,texture,&rect1[frame],&rect2[frame]);
                frame++;
                SDL_Delay(70);
                SDL_RenderPresent( m_renderer );
            }
            for(i=0;i<quantity;i++)
            {
                if(brick[i].strength>0)
                    broken++;
                brick[i].strength=0;
            }
            explode=false;
            Damage=0;
        }

       for(i=0;i<quantity;i++)
       {
           if((brick[i].y>=650 && brick[i].strength>0) || lives<=0)
           {
               Mix_FreeMusic(GameSound);
               Mix_PlayChannel(-1,End,0);
               SDL_RenderCopy(m_renderer,Pause,NULL,&Pau);
               SDL_RenderCopy(m_renderer,Over,NULL,&Ove);
               SDL_RenderPresent(m_renderer);
                quit=true;
                if(exist)
                    Edit_Record(Name,score);
                else
                    Save_Record(Name,score);
                SDL_RenderCopy(m_renderer,Over,NULL,&Ove);
                SDL_Delay(10000);
                break;
           }
       }

       if(Stop)
       {
            Chose=Pause_Game();
           if(Chose==1)
           {
                Mix_PlayChannel(-1,Save_Load,0);
                if(exist)
                    Edit_Record(Name,score);
                else
                    Save_Record(Name,score);
                Save(Name,lives,quantity,score,level,Damage,brick);
           }else if(Chose==0)
            {
                Chose=Msgbox_SL2();
                if(Chose==2)
                {
                    Mix_FreeMusic(GameSound);
                    Mix_PlayChannel(-1,Save_Load,0);
                    if(exist)
                        Edit_Record(Name,score);
                    else
                        Save_Record(Name,score);
                    Save(Name,lives,quantity,score,level,Damage,brick);
                    quit=true;
                    SDL_Delay(2000);
                }
                else if(Chose==1)
                    quit=true;
            }
            Stop=false;
       }
    }

    SDL_DestroyTexture(m_img1);
    SDL_DestroyTexture(m_img2);
    SDL_DestroyTexture(m_img3);
      if(mode==2)
    {
       SDL_RenderCopy(m_renderer, m_img4, NULL, &texr4);
    }

    SDL_DestroyTexture(Board);
    SDL_DestroyTexture(Level);
    SDL_DestroyTexture(Lives);
    SDL_DestroyTexture(Score);
    SDL_DestroyTexture(Pause);
    SDL_DestroyTexture(Over);
    SDL_DestroyTexture(Rocket);
    SDL_DestroyTexture(texture);
    SDL_DestroyWindow( m_window );
    SDL_DestroyRenderer( m_renderer );
	IMG_Quit();
	SDL_Quit();
    return 0;

}

void window_color(SDL_Renderer *Renderer, int R, int G, int B)
{
    SDL_SetRenderDrawColor( Renderer, R, G, B, 255 );
    SDL_RenderClear( Renderer );
    SDL_RenderPresent( Renderer );
}

void textColor(SDL_Renderer *renderer,int x,int y,const char * text,const char * font,int font_size,SDL_Color textColor,double angle,short flip_num)
{
    int mWidth = 0;
	int mHeight = 0;
    SDL_Rect* clip = NULL;
    TTF_Font *gFont = NULL;
    SDL_Point* center = NULL;

    SDL_RendererFlip flip;
    switch(flip_num){
        case 0:
            flip = SDL_FLIP_NONE;
            break;
        case 1:
            flip = SDL_FLIP_HORIZONTAL;
            break;
        case 2:
            flip = SDL_FLIP_VERTICAL;
            break;
        case 3:
            flip = (SDL_RendererFlip) (SDL_FLIP_HORIZONTAL | SDL_FLIP_VERTICAL);
            break;
        default:
            flip = SDL_FLIP_NONE;
    }

    SDL_Texture* mTexture = NULL;
    gFont = TTF_OpenFont(font, font_size);

    SDL_Surface* textSurface = TTF_RenderText_Solid(gFont, text, textColor);

    mWidth = textSurface->w;
    mHeight = textSurface->h;
    mTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    SDL_FreeSurface(textSurface);


    SDL_Rect renderQuad = {x , y, mWidth, mHeight};
    SDL_RenderCopyEx(renderer, mTexture, clip, &renderQuad, angle, center, flip);

    SDL_DestroyTexture(mTexture);
    SDL_RenderPresent(renderer);
}

void textRGBA(SDL_Renderer *renderer,int x,int y,const char * text,const char * font,int font_size,int R,int G,int B, int A,double angle,short flip_num)
{
    SDL_Color text_color = { R, G, B, A};
    int mWidth = 0;
	int mHeight = 0;
    SDL_Rect* clip = NULL;
    TTF_Font *gFont = NULL;
    SDL_Point* center = NULL;

    SDL_RendererFlip flip;
    switch(flip_num){
        case 0:
            flip = SDL_FLIP_NONE;
            break;
        case 1:
            flip = SDL_FLIP_HORIZONTAL;
            break;
        case 2:
            flip = SDL_FLIP_VERTICAL;
            break;
        case 3:
            flip = (SDL_RendererFlip) (SDL_FLIP_HORIZONTAL | SDL_FLIP_VERTICAL);
            break;
        default:
            flip = SDL_FLIP_NONE;
    }

    SDL_Texture* mTexture = NULL;
    gFont = TTF_OpenFont(font, font_size);

    SDL_Surface* textSurface = TTF_RenderText_Solid(gFont, text, text_color);

    mWidth = textSurface->w;
    mHeight = textSurface->h;
    mTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    SDL_FreeSurface(textSurface);


    SDL_Rect renderQuad = {x, y , mWidth, mHeight};
    SDL_RenderCopyEx(renderer, mTexture, clip, &renderQuad, angle, center, flip);

    SDL_DestroyTexture(mTexture);
    SDL_RenderPresent(renderer);
}

bool Name_Existence(string Name)
{
    bool Exist=false;
    string N;
    ifstream file1("file\\File_Name.txt");
    if(file1.good())
    {
         while(!file1.eof())
        {
            getline(file1,N);
            if(N==Name)
            {
                Exist=true;
                break;
            }
        }
    }
    file1.close();
    return(Exist);
}

string Recent_History(string Name)
{
    string N;
    string H="",H1,H2,H3,H4,H5;
    ifstream file2("file\\History.txt");
    if(file2.good())
    {
         while(!file2.eof())
        {
            getline(file2,N);
            if(N==Name)
            {
                getline(file2,H1);
                getline(file2,H2);
                getline(file2,H3);
                getline(file2,H4);
                getline(file2,H5);
                break;
            }
        }
    }
    H+=H1+"        "+H2+"        "+H3+"        "+H4+"        "+H5;
    file2.close();
    return H;
}

void History(string H,string Name,SDL_Renderer *m_renderer)
{
    const char * text1 ="Your Last 5 Records";
    const char * text2 =H.c_str();
    const char * text3 =Name.c_str();
    const char * font="MAGNETOB.ttf";
    int x1_position=560;
    int y1_position=150;
    int x2_position=440;
    int y2_position=270;
    int x3_position=620;
    int y3_position=210;
    int R=255;
    int G =0;
    int B=0;
    int A=0.7;
    SDL_Color text_color = { R, G, B};
    textColor(m_renderer,x1_position,y1_position,text1,font,18,text_color,NULL,NULL);
    textColor(m_renderer,x2_position,y2_position,text2,font,18,text_color,NULL,NULL);
    textColor(m_renderer,x3_position,y3_position,text3,font,18,text_color,NULL,NULL);
}

int Msgbox_SL()
{
    int Chose;
    const SDL_MessageBoxButtonData buttons[] = {
        {0, 0, "New Game" },
        { SDL_MESSAGEBOX_BUTTON_RETURNKEY_DEFAULT, 1, "Load" },
    };
    const SDL_MessageBoxColorScheme colorScheme = {
    };
    const SDL_MessageBoxData messageboxdata = {
        SDL_MESSAGEBOX_INFORMATION,
        NULL,
        "Start Game",
        "Would you want to load the previous game or start a new game?",
        SDL_arraysize(buttons),
        buttons,
        &colorScheme
    };
    int buttonid;
    if (SDL_ShowMessageBox(&messageboxdata, &buttonid) < 0) {
        return 1;
    }else {
        if(buttons[buttonid].text=="New Game")
            Chose=0;
        else if(buttons[buttonid].text=="Load")
            Chose=1;
        else
            Chose=-1;
    }
    return Chose;
}

void Edit_Record(string Name,int record)
{
    int n=1;
    bool Start=false;
    string N="file\\",s;
    N+="History.txt";
    ifstream file1;
    ofstream file2;
    file1.open(N.c_str());
    file2.open("file\\temporary.txt");
    if(file1.good() && file2.good())
    {
        while(!file1.eof())
        {
            if(Start)
                n++;
            getline(file1,s);
            if(s!=Name && n!=5)
                file2<<s<<endl;
            else if(s==Name && n!=5)
            {
                file2<<s<<endl;
                Start=true;
                getline(file1,s);
                file2<<record<<endl<<s<<endl;
            }
        }
    }
    file1.close();
    file2.close();
    file1.open("file\\temporary.txt");
    file2.open(N.c_str());
    if(file1.good() && file2.good())
    {
        while(!file1.eof())
        {
            getline(file1,s);
            file2<<s<<endl;
        }
    }
    file1.close();
    file2.close();
}

void Save_Record(string Name,int record)
{
    string N="file\\",s;
    N+="History.txt";
    ifstream file1;
    ofstream file2;
    file1.open("file\\File_Name.txt");
    file2.open("file\\temporary.txt");
    if(file1.good() && file2.good())
    {
        while(!file1.eof())
        {
            getline(file1,s);
            file2<<s<<endl;
        }
        file2<<Name;
    }
    file1.close();
    file2.close();
    file1.open("file\\temporary.txt");
    file2.open("file\\File_Name.txt");
    if(file1.good() && file2.good())
    {
        while(!file1.eof())
        {
            getline(file1,s);
            file2<<s<<endl;
        }
    }
    file1.close();
    file2.close();

    file1.open(N.c_str());
    file2.open("file\\temporary.txt");
    if(file1.good() && file2.good())
    {
        while(!file1.eof())
        {
            getline(file1,s);
            file2<<s<<endl;
        }
        file2<<Name<<endl<<record<<"\n0\n0\n0\n0\n";
    }
    file1.close();
    file2.close();
    file1.open("file\\temporary.txt");
    file2.open(N.c_str());
    if(file1.good() && file2.good())
    {
        while(!file1.eof())
        {
            getline(file1,s);
            file2<<s<<endl;
        }
    }
    file1.close();
    file2.close();
}

bool Load_Data(string Name,int *level,int *lives,int *score,int *Damage,Brick *brick,SDL_Renderer *m_renderer)
{
    int x,B_x,B_y,B_s,i=0,Quantity;
    bool Ex=true;
    int Level,Lives,Score;
    Brick B[360];
    ifstream file;
    string N="load\\"+Name+".txt",s;
    file.open(N.c_str());
    if(file.good())
    {
        while(!file.eof())
        {
            getline(file,s);
            if(s=="level")
            {
                file>>x;
                *level=x;
                Level=x;
            }else if(s=="lives")
            {
                file>>x;
                *lives=x;
                Lives=x;
            }if(s=="score")
            {
                file>>x;
                *score=x;
                Score=x;
            }if(s=="damage")
            {
                file>>x;
                *Damage=x;
            }if(s=="bricks")
            {
                for(i=0;i<Level*6;i++)
                {
                file>>B_x>>B_y>>B_s;
                cout<<B_s<<endl;
                *(brick+i)={B_x,B_y,B_s};
                B[i]={B_x,B_y,B_s};
                }
            }
        }
    }
    else
        Ex=false;
    Quantity=i-1;
    Load(Lives,Score,Level,Quantity,B,m_renderer);
    file.close();
    return Ex;
}


void Load(int lives,int score,int level,int Quantity,Brick brick[],SDL_Renderer *m_renderer)
{
    int i,a=150,b=40;
    for(int i=0;i<Quantity;i++)
    {
        if(brick[i].strength>0 && brick[i].strength<=12)
            boxRGBA(m_renderer,brick[i].x,brick[i].y,brick[i].x+a,brick[i].y+b,255-brick[i].strength*20,0,0,255);
        else if(brick[i].strength>12 && brick[i].strength<=24)
            boxRGBA(m_renderer,brick[i].x,brick[i].y,brick[i].x+a,brick[i].y+b,0,255-brick[i].strength*20,0,255);
        else if(brick[i].strength>24 && brick[i].strength<=36)
            boxRGBA(m_renderer,brick[i].x,brick[i].y,brick[i].x+a,brick[i].y+b,0,0,255-brick[i].strength*20,255);
        else if(brick[i].strength>36 && brick[i].strength<=48)
            boxRGBA(m_renderer,brick[i].x,brick[i].y,brick[i].x+a,brick[i].y+b,0,brick[i].strength*20,255-brick[i].strength*20,255);
        else if(brick[i].strength>48 && brick[i].strength)
            boxRGBA(m_renderer,brick[i].x,brick[i].y,brick[i].x+a,brick[i].y+b,brick[i].strength*20,255-brick[i].strength*20,0,255);
    }
}

void Save(string Name,int lives,int quantity,int score,int level,int Damage,Brick brick[])
{
    ofstream file;
    string N="load\\"+Name+".txt";
    file.open(N.c_str());
    if(file.good())
    {
    file<<"level\n"<<level<<endl<<"lives\n"<<lives<<endl<<"score\n"<<score<<endl<<"damage\n"<<Damage<<endl<<"bricks\n";
    for(int i=0;i<quantity;i++)
        file<<brick[i].x<<" "<<brick[i].y<<" "<<brick[i].strength<<endl;
    }
}

double power(double x,int n)
{
    double P=1;
    for(int i=1;i<=n;i++)
    P*=x;
    return P;
}

void Random(int level,Brick brick[],int quantity,SDL_Renderer *m_renderer)
{
    int strength,i,x,y,a=150,b=40,emp=55,s,n=0;
    srand(time(NULL));
    for(i=0;i<6;i++)
    {
        s=rand()%9;
        if(s>3)
            strength=rand()%level+1;
        else
        {
            strength=0;
            n++;
        }
        if(i==0)
             brick[quantity+i].x=emp;
        else
            brick[quantity+i].x=2*i*(a+emp)-i*a;
        brick[quantity+i].y=50;
        brick[quantity+i].strength=strength;
        if(strength>0 && strength<=12)
            boxRGBA(m_renderer,brick[quantity+i].x,50,brick[quantity+i].x+a,50+b,255-strength*20,0,0,255);
        else if(strength>12 && strength<=24)
            boxRGBA(m_renderer,brick[quantity+i].x,50,brick[quantity+i].x+a,50+b,0,255-strength*20,0,255);
        else if(strength>24 && strength<=36)
            boxRGBA(m_renderer,brick[quantity+i].x,50,brick[quantity+i].x+a,50+b,0,0,255-strength*20,255);
        else if(brick[i].strength>36 && brick[i].strength<=48)
            boxRGBA(m_renderer,brick[i].x,brick[i].y,brick[i].x+a,brick[i].y+b,0,strength*20,255-strength*20,255);
        else if(brick[i].strength>48 && brick[i].strength)
            boxRGBA(m_renderer,brick[i].x,brick[i].y,brick[i].x+a,brick[i].y+b,strength*20,255-strength*20,0,255);
    }
    if(n>=6)
    {
        brick[quantity].strength=1;
        brick[quantity+2].strength=1;
        boxRGBA(m_renderer,brick[quantity].x,50,brick[quantity].x+a,50+b,255-brick[quantity].strength*20,0,0,255);
        boxRGBA(m_renderer,brick[quantity+2].x,50,brick[quantity+2].x+a,50+b,255-brick[quantity+2].strength*20,0,0,255);
    }

}

void draw(Brick brick[],int quantity,SDL_Renderer *m_renderer)
{
    int i,a=150,b=40,emp=55;
    for(i=0;i<quantity;i++)
    {
        if(brick[i].strength>0 && brick[i].strength<=12)
            boxRGBA(m_renderer,brick[i].x,brick[i].y,brick[i].x+a,brick[i].y+b,255-brick[i].strength*20,0,0,255);
        else if(brick[i].strength>12 && brick[i].strength<=24)
            boxRGBA(m_renderer,brick[i].x,brick[i].y,brick[i].x+a,brick[i].y+b,0,255-brick[i].strength*20,0,255);
        else if(brick[i].strength>24 && brick[i].strength<=36)
            boxRGBA(m_renderer,brick[i].x,brick[i].y,brick[i].x+a,brick[i].y+b,0,0,255-brick[i].strength*20,255);
        else if(brick[i].strength>36 && brick[i].strength<=48)
            boxRGBA(m_renderer,brick[i].x,brick[i].y,brick[i].x+a,brick[i].y+b,0,brick[i].strength*20,255-brick[i].strength*20,255);
        else if(brick[i].strength>48 && brick[i].strength)
            boxRGBA(m_renderer,brick[i].x,brick[i].y,brick[i].x+a,brick[i].y+b,brick[i].strength*20,255-brick[i].strength*20,0,255);
    }
}

void Shift(Brick brick[],int quantity,SDL_Renderer *m_renderer)
{
    int i,a=150,b=40,emp=55;
    for(i=0;i<quantity;i++)
    {
        brick[i].y+=50;
        if(brick[i].strength>0 && brick[i].strength<=12)
            boxRGBA(m_renderer,brick[i].x,brick[i].y,brick[i].x+a,brick[i].y+b,255-brick[i].strength*20,0,0,255);
        else if(brick[i].strength>12 && brick[i].strength<=24)
            boxRGBA(m_renderer,brick[i].x,brick[i].y,brick[i].x+a,brick[i].y+b,0,255-brick[i].strength*20,0,255);
        else if(brick[i].strength>24 && brick[i].strength<=36)
            boxRGBA(m_renderer,brick[i].x,brick[i].y,brick[i].x+a,brick[i].y+b,0,0,255-brick[i].strength*20,255);
        else if(brick[i].strength>36 && brick[i].strength<=48)
            boxRGBA(m_renderer,brick[i].x,brick[i].y,brick[i].x+a,brick[i].y+b,0,brick[i].strength*20,255-brick[i].strength*20,255);
        else if(brick[i].strength>48 && brick[i].strength)
            boxRGBA(m_renderer,brick[i].x,brick[i].y,brick[i].x+a,brick[i].y+b,brick[i].strength*20,255-brick[i].strength*20,0,255);
    }
}

string Reverse(string S)
{
    for(int i=0;i<S.length()/2;i++)
        swap(S[i],S[S.length()-i-1]);
    return S;
}

string int_to_string(int x)
{
    string S="";
    char ch;
    if(x==0)
        S="0";
    else
    {
        while(x>0)
        {
            ch=(x%10)+'0';
            x/=10;
            S+=ch;
        }
    }
    return Reverse(S);
}

int Pause_Game()
{
    int Chose;
    const SDL_MessageBoxButtonData buttons[] = {
        {0, 0, "Exit" },
        { SDL_MESSAGEBOX_BUTTON_RETURNKEY_DEFAULT, 1, "Save" },
        { SDL_MESSAGEBOX_BUTTON_ESCAPEKEY_DEFAULT, 2, "Resume" },
    };
    const SDL_MessageBoxColorScheme colorScheme = {
    };
    const SDL_MessageBoxData messageboxdata = {
        SDL_MESSAGEBOX_INFORMATION,
        NULL,
        "Pause",
        "Chose",
        SDL_arraysize(buttons),
        buttons,
        &colorScheme
    };
    int buttonid;
    if (SDL_ShowMessageBox(&messageboxdata, &buttonid) < 0) {
        return 1;
    }else {
        if(buttons[buttonid].text=="Exit")
            Chose=0;
        else if(buttons[buttonid].text=="Save")
            Chose=1;
        else if(buttons[buttonid].text=="Resume")
            Chose=2;
        else
            Chose=-1;
    }
    return Chose;
}

int Msgbox_SL2()
{
    int Chose;
    const SDL_MessageBoxButtonData buttons[] = {
        {0, 0, "Cancel" },
        { SDL_MESSAGEBOX_BUTTON_RETURNKEY_DEFAULT, 1, "No" },
        { SDL_MESSAGEBOX_BUTTON_ESCAPEKEY_DEFAULT, 2, "Yes" },

    };
    const SDL_MessageBoxColorScheme colorScheme = {
    };
    const SDL_MessageBoxData messageboxdata = {
        SDL_MESSAGEBOX_INFORMATION,
        NULL,
        "Save",
        "Would you want to save the game?",
        SDL_arraysize(buttons),
        buttons,
        &colorScheme
    };
    int buttonid;
    if (SDL_ShowMessageBox(&messageboxdata, &buttonid) < 0) {
        return 1;
    }else {
        if(buttons[buttonid].text=="No")
            Chose=1;
        else if(buttons[buttonid].text=="Yes")
            Chose=2;
        else if(buttons[buttonid].text=="Cancel")
            Chose=0;
        else
            Chose=-1;
    }
    return Chose;
}



