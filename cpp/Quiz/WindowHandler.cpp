#include "WindowHandler.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <fstream>
#include <string>
#include <codecvt>
#include <locale>

using namespace std;

WindowHandler::WindowHandler()
{
    main_font.loadFromFile("Fonts/georgia.ttf");
    result_font.loadFromFile("Fonts/verdana.ttf");
    fstream config;
    config.open("config.ini");
    if(config.good())
    {
        string cur_line;
        getline(config, cur_line);
        sfx_vol = stof(cur_line);
        getline(config, cur_line);
        bgm_vol = stof(cur_line);
    }
    config.close();
}

sf::Text WindowHandler::getText(sf::String text, sf::Font &given_font, int text_size, sf::Color text_color, sf::Vector2f text_pos, bool override_origin)
{
    sf::Text output_text(text, given_font, text_size);
    output_text.setColor(text_color);
    if(override_origin)
    {
        output_text.setOrigin(output_text.getLocalBounds().width / 2, output_text.getLocalBounds().height / 2);
    }
    output_text.setPosition(text_pos);

    return output_text;
}

string WindowHandler::wrapString(string given_str, sf::Font &given_font, int text_size, sf::Vector2f text_pos, bool override_origin, float box_width)
{
    sf::Text t_temp = getText(sf::String(wstring_convert<codecvt_utf8<wchar_t>>().from_bytes(given_str)), given_font,  text_size, sf::Color(255, 211, 60), text_pos, override_origin);
    int times_to_wrap = ceil(t_temp.getLocalBounds().width  / box_width);

    if(times_to_wrap > 0)
    {
        vector<string> parts;
        string str_left = given_str;
        float text_pos_x = t_temp.getPosition().x;
        float quickfix = 0;

        for(int i = 0; i < times_to_wrap; i++)
        {
            for(int j = 0; j < str_left.length(); j++) // For the entire length of the string
            {
                bool comparison;
                if(override_origin)
                {
                    comparison = t_temp.findCharacterPos(j).x/* - quickfix */> text_pos_x - t_temp.getLocalBounds().width / 2 + box_width;// || t_temp.findCharacterPos(j).x - box_width < text_pos_x;
                }
                else
                {
                    comparison = t_temp.findCharacterPos(j).x/* - quickfix  */> text_pos_x + box_width;// || t_temp.findCharacterPos(j).x - box_width - t_temp.getLocalBounds().width / 2 > -text_pos_x;
                }
                if(comparison) // If character is offscreen
                {
                    int wrap_at = str_left.find_last_of(" ", j - 1); // Find last space that isn't offscreen
                    quickfix += t_temp.findCharacterPos(wrap_at).x;
                    if(wrap_at == -1) // If the search didn't return anything
                    {
                        break;
                    }
                    parts.push_back(str_left.substr(0, wrap_at + 1) + '\n'); // Put the part of the string that's on screen + a line break into parts
                    str_left = str_left.substr(wrap_at + 1); // Cut the string to the part that was offscreen
                    break;
                }
            }
        }
        parts.push_back(str_left); // Add the last part

        string output = "";
        for(int i = 0; i < parts.size(); i++)
        {
            output += parts[i];
        }
        return output;
    }
    else
    {
        return given_str;
    }
}
