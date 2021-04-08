#ifndef WINDOWHANDLER.H
#define WINDOWHANDLER.H
#include <windows.h>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class WindowHandler
{
    public:
        sf::Color bg_color = sf::Color::Black;
        sf::Font main_font;
        sf::Font result_font;
        float sfx_vol = 100.f;
        float bgm_vol = 100.f;

        WindowHandler();
        sf::Text getText(sf::String text, sf::Font &given_font, int text_size, sf::Color text_color, sf::Vector2f text_pos, bool override_origin);
        std::string wrapString(std::string given_str, sf::Font &given_font, int text_size, sf::Vector2f text_pos, bool override_origin, float box_width);
};

#endif WINDOWHANDLER.H
