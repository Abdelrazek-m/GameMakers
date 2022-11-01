#include<SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include<string>
#include<iostream>

using namespace sf;
using namespace std;

int main(){
    int dx=0,dy=0;

    RenderWindow window(VideoMode(800,600),"Task Day 3");
    window.setFramerateLimit(60);

    RectangleShape rec(Vector2f(100,100));
    //rec.setPosition(Vector2f(200,150));
    rec.setFillColor(Color(40,80,200));
    RectangleShape rec2(Vector2f(40,300));
    rec2.setPosition(Vector2f(400,300));
    rec2.setOrigin(Vector2f(20,150));
    rec2.setFillColor(Color(200,80,600));

    SoundBuffer buffer;
    buffer.loadFromFile("audio.ogg");
    Sound sound ;
    sound.setBuffer(buffer);
    //sound.play();

    Music music;
    if (!music.openFromFile("audio2.wav"))
        return -1; // error
    //music.play();

    while(window.isOpen()){
        Event e;
        while(window.pollEvent(e)){
            if(e.type==Event::Closed)
                window.close();

            if(e.type==Event::KeyPressed){
                if(e.key.code==Keyboard::Up){
                    dx=-5;
                }
                if(e.key.code==Keyboard::Down){
                    dx=5;
                }
                if(e.key.code==Keyboard::Left){
                    dy=-5;
                }
                if(e.key.code==Keyboard::Right){
                    dy=5;
                }
            }

            if(e.type==Event::KeyReleased){
                if(e.key.code==Keyboard::Up){
                    dx=0;
                }
                if(e.key.code==Keyboard::Down){
                    dx=0;
                }
                if(e.key.code==Keyboard::Left){
                    dy=0;
                }
                if(e.key.code==Keyboard::Right){
                    dy=0;
                }
            }

        }

        rec.move(Vector2f(dy,dx));
        if(rec.getGlobalBounds().intersects(rec2.getGlobalBounds())){
            music.play();
            music.setPlayingOffset(seconds(33.5f));
            rec.move(Vector2f(-dy*2,-dx*2));
        }

        window.clear();
        window.draw(rec);
        window.draw(rec2);
        window.display();

    }


    return 0;
}
