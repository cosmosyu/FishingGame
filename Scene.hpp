#include <SFML/Graphics.hpp>
class Scene
{
   private:
     sf::RenderWindow m_window;
     sf::Sprite m_background;
     sf::Texture m_bg_pic;
   
   public:
     Scene();
     ~Scene();
     void run();
};
