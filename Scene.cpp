#include "Scene.hpp"
#include <SFML/Window/Event.hpp>
#include <SFML/System/Vector2.hpp>

using namespace sf;
Scene::Scene()
      :m_bg_pic()
      ,m_background()
      ,m_window()
{
   // initialize background texture&sprite
   m_bg_pic.loadFromFile("game_pic/game_pic/res-image-back1-bg1.bmp_556_300.out.png");
   m_background.setTexture(m_bg_pic);
   Vector2u bg_size = m_bg_pic.getSize();
   // initialize window 
   m_window.create(VideoMode(bg_size.x, bg_size.y, 1), "Fishing");
}

Scene::~Scene()
{
}

void Scene::run()
{
   // draw back ground
   m_window.clear();
   m_window.pushGLStates();
   m_window.draw(m_background);
   m_window.popGLStates();

   // draw fish
   Sprite fish;
   Texture fish_pic;
   fish_pic.loadFromFile("game_pic/game_pic/res-image-fish7_1-4.png_6C_38.out.png");
   Vector2u fish_size = fish_pic.getSize();    
   Vector2i pos(0,0);
   Vector2i sz(fish_size.x,fish_size.y);
   fish.setTexture(fish_pic);
   fish.setTextureRect(sf::IntRect(pos, sz));
   fish.setPosition(270, 340);
   m_window.pushGLStates();
   m_window.draw(fish);
   m_window.popGLStates();
   
   while(m_window.isOpen())
   {
      Event event;
      while(m_window.pollEvent(event))
      {
         if(event.type == sf::Event::Closed)
           m_window.close();
      }
      m_window.display();
   }
}

int main()
{
   Scene ascene;
   ascene.run();
   return 0; 
}

