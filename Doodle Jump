#include<SFML/Graphics.hpp>
#include<time.h>
#include <SFML/Audio.hpp>
#include<string>
#include<iostream>

using namespace sf;
using namespace std;

struct point{
    int x,y;
};

int main(){
    srand(time(0));
    int cou=0;

    RenderWindow window(VideoMode(400,533),"Doodly Jump");
    window.setFramerateLimit(60);

    Music music;
    if (!music.openFromFile("audio2.wav"))
        return -1;

    Texture t1,t2,t3;
    t1.loadFromFile("images/background.png");
    t2.loadFromFile("images/platform.png");
    t3.loadFromFile("images/doodle.png");

    Font font;
    font.loadFromFile("Arial.ttf");
    Text score;
    score.setFont(font);
    score.setColor(Color(60,120,200));
    score.setString("0");

    Sprite sBack(t1),sPlat(t2),sPerson(t3);

    //sPerson.setPosition(Vector2f(200,200));

    point plat[20];
    for(int i=0;i<10;i++){
        plat[i].x=rand()%400;
        plat[i].y=rand()%533;
    }
    int x=100,y=100,h=200;
    float dx=0,dy=0;
    while(window.isOpen()){
        Event e;
        while(window.pollEvent(e)){
            if(e.type==Event::Closed)
                window.close();
            if(e.type==Event::KeyPressed){
                if(e.key.control&&e.key.code==Keyboard::X)
                    window.close();
//                if(e.key.code==Keyboard::Left)
//                    x+=3;
//                if(e.key.code==Keyboard::Right)
//                    x-=3;

            }
        }
        if(Keyboard::isKeyPressed(Keyboard::Right)&&x<330)x+=3;
        if(Keyboard::isKeyPressed(Keyboard::Left)&&x>0)x-=3;

        dy+=0.2;
        y+=dy;
        if(y>500)dy=-10;

        if(y<h){
            for(int i=0;i<10;i++){
                y=h;
                plat[i].y -=dy;
                if(plat[i].y>533){
                    plat[i].y=0;
                    plat[i].x=rand()%400;
                }
            }
        }
        int co=0;
        for(int i=0;i<10;i++){
            if((x+50>plat[i].x)&&(x+20<plat[i].x+68)&&(y+70>plat[i].y)&&(y+70<plat[i].y+14)&&dy>0){
                dy=-10;
                cou++;
                music.play();
                music.setPlayingOffset(seconds(33.4f));

            }
            if(y>=500&&((x<=plat[i].x)||(plat[i].y<=450)||(x>=plat[i].x+48)))co++;
        }
        if(co==10){
            cout<<"game over\n";
            while(true){
                if(Keyboard::isKeyPressed(Keyboard::R)){cou=0;break;}
            }
        }
        sPerson.setPosition(Vector2f(x,y));

        score.setString(to_string(cou));
        window.clear();
        window.draw(sBack);
        window.draw(sPerson);
        for(int i=0;i<10;i++){
            sPlat.setPosition(plat[i].x,plat[i].y);
            window.draw(sPlat);
        }
        window.draw(score);

        window.display();
    }




    return 0;
}
