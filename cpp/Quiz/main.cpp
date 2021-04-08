#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <fstream>
#include <limits>
#include <vector>
#include <windows.h>
#include <time.h>
#include "WindowHandler.h"
#include "QuizHandler.h"

using namespace std;

int main()
{
    srand (time(NULL));

    WindowHandler* thisWindowHandler = new WindowHandler();
    QuizHandler* thisQuizHandler = new QuizHandler();
    sf::RenderWindow window(sf::VideoMode(800, 600), "Quiz");

    vector<QuizHandler::Question> available_questions = thisQuizHandler->readQuizFile("testbase.txt");

    int sel = 0; // Selected option
    int max_sel = 2;
    int menu_mode = 0; // Main, Solo or Duo, Options, Credits, Quiz, End
    bool two_players = false;
    int p1_correct_answers;
    int p2_correct_answers;

    sf::Texture tex_bg;
    sf::Sprite spr_bg;

    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                window.close();
                return -1;
            }
        }

        window.clear(thisWindowHandler->bg_color);

        switch(menu_mode)
        {
            case 0: // Main Menu
            {
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                {
                    while(sf::Keyboard::isKeyPressed(sf::Keyboard::Up));
                    if(sel > 0) sel--;
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                {
                    while(sf::Keyboard::isKeyPressed(sf::Keyboard::Down));
                    if(sel < max_sel) sel++;
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
                {
                    while(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter));
                    switch(sel)
                    {
                        case 0:
                        {
                            sel = 0;
                            max_sel = 2;
                            menu_mode = 1;
                            continue;
                            break;
                        }

                        case 1:
                        {
                            sel = 0;
                            max_sel = 2;
                            menu_mode = 2;
                            continue;
                            break;
                        }

                        case 2:
                        {
                            sel = 0;
                            window.close();
                            return -1;
                            break;
                        }
                    }
                }

                sf::Text t_gamemode = thisWindowHandler->getText(sf::String(L"Quiz dla programisty"), thisWindowHandler->main_font, 53, sf::Color(255, 211, 60), sf::Vector2f(window.getSize().x / 2, window.getSize().y * 0.15), true);
                sf::Text t_start = thisWindowHandler->getText(sf::String(L"Start"), thisWindowHandler->main_font, 24, sf::Color(255, 211, 60), sf::Vector2f(window.getSize().x / 2, window.getSize().y * 0.49), true);
                if(sel == 0) t_start.setColor(sf::Color::Green);
                sf::Text t_options = thisWindowHandler->getText(sf::String(L"Opcje"), thisWindowHandler->main_font, 24, sf::Color(255, 211, 60), sf::Vector2f(window.getSize().x / 2, window.getSize().y * 0.63), true);
                if(sel == 1) t_options.setColor(sf::Color::Green);
                sf::Text t_exit = thisWindowHandler->getText(sf::String(L"Wyjdź"), thisWindowHandler->main_font, 24, sf::Color(255, 211, 60), sf::Vector2f(window.getSize().x / 2, window.getSize().y * 0.76), true);
                if(sel == 2) t_exit.setColor(sf::Color::Green);

                if(!tex_bg.loadFromFile("Graphics/main_menu.png")) return -1;
                spr_bg.setTexture(tex_bg);

                window.draw(spr_bg);
                window.draw(t_gamemode);
                window.draw(t_start);
                window.draw(t_options);
                window.draw(t_exit);
                break;
            }

            case 1: // Solo or Duo
            {
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                {
                    while(sf::Keyboard::isKeyPressed(sf::Keyboard::Up));
                    if(sel > 0) sel--;
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                {
                    while(sf::Keyboard::isKeyPressed(sf::Keyboard::Down));
                    if(sel < max_sel) sel++;
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
                {
                    while(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter));
                    switch(sel)
                    {
                        case 0:
                        {
                            sel = 0;
                            menu_mode = 3;
                            continue;
                            break;
                        }

                        case 1:
                        {
                            sel = 0;
                            two_players = true;
                            menu_mode = 3;
                            continue;
                            break;
                        }

                        case 2:
                        {
                            sel = 0;
                            menu_mode = 0;
                            continue;
                            break;
                        }
                    }
                }

                sf::Text t_choose = thisWindowHandler->getText(sf::String(L"Wybierz tryb"), thisWindowHandler->main_font, 53, sf::Color(255, 211, 60), sf::Vector2f(window.getSize().x / 2, window.getSize().y / 4), true);
                sf::Text t_solo = thisWindowHandler->getText(sf::String(L"Solo"), thisWindowHandler->main_font, 24, sf::Color(255, 211, 60), sf::Vector2f(window.getSize().x / 2, window.getSize().y * 0.44), true);
                if(sel == 0) t_solo.setColor(sf::Color::Green);
                sf::Text t_duo = thisWindowHandler->getText(sf::String(L"Duo"), thisWindowHandler->main_font, 24, sf::Color(255, 211, 60), sf::Vector2f(window.getSize().x / 2, window.getSize().y * 0.6), true);
                if(sel == 1) t_duo.setColor(sf::Color::Green);
                sf::Text t_exit = thisWindowHandler->getText(sf::String(L"Cofnij"), thisWindowHandler->main_font, 24, sf::Color(255, 211, 60), sf::Vector2f(window.getSize().x * 0.88, window.getSize().y * 0.9), true);
                if(sel == 2) t_exit.setColor(sf::Color::Green);

                if(!tex_bg.loadFromFile("Graphics/gamemode_menu.png")) return -1;
                spr_bg.setTexture(tex_bg);

                window.draw(spr_bg);
                window.draw(t_choose);
                window.draw(t_solo);
                window.draw(t_duo);
                window.draw(t_exit);

                break;
            }

            case 2: // Options
            {
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                {
                    while(sf::Keyboard::isKeyPressed(sf::Keyboard::Up));
                    if(sel > 0) sel--;
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                {
                    while(sf::Keyboard::isKeyPressed(sf::Keyboard::Down));
                    if(sel < max_sel) sel++;
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                {
                    while(sf::Keyboard::isKeyPressed(sf::Keyboard::Left));
                    switch(sel)
                    {
                        case 0:
                        {
                            if(thisWindowHandler->sfx_vol > 0)
                            {
                                thisWindowHandler->sfx_vol -= 10;
                            }
                            continue;
                            break;
                        }

                        case 1:
                        {
                            if(thisWindowHandler->bgm_vol > 0)
                            {
                                thisWindowHandler->bgm_vol -= 10;
                            }
                            continue;
                            break;
                        }
                    }
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                {
                    while(sf::Keyboard::isKeyPressed(sf::Keyboard::Right));
                    switch(sel)
                    {
                        case 0:
                        {
                            if(thisWindowHandler->sfx_vol < 100)
                            {
                                thisWindowHandler->sfx_vol += 10;
                            }
                            continue;
                            break;
                        }

                        case 1:
                        {
                            if(thisWindowHandler->bgm_vol < 100)
                            {
                                thisWindowHandler->bgm_vol += 10;
                            }
                            continue;
                            break;
                        }
                    }
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
                {
                    while(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter));
                    if(sel == 2)
                    {
                        fstream config;
                        config.open("config.ini", ios::out);
                        config << thisWindowHandler->sfx_vol << '\n';
                        config << thisWindowHandler->bgm_vol;
                        config.close();
                        sel = 0;
                        menu_mode = 0;
                        continue;
                        break;
                    }
                }

                window.clear();

                sf::Text t_credits = thisWindowHandler->getText(sf::String(L"Twórcy:\nFranek Domarus, Kacper Formela, Bartosz Okuń,\nMaciej Wasielke, Damian Skrzypczak, Michał Boruszewski"), thisWindowHandler->main_font, 24, sf::Color(255, 211, 60), sf::Vector2f(window.getSize().x * 0.02, window.getSize().y * 0.65), false);

                sf::Text t_sounds = thisWindowHandler->getText(sf::String(L"Dźwięk"), thisWindowHandler->main_font, 36, sf::Color(255, 211, 60), sf::Vector2f(window.getSize().x * 0.12, window.getSize().y * 0.23), true);
                sf::Text t_sfx_sub = thisWindowHandler->getText(sf::String(L"-"), thisWindowHandler->main_font, 36, sf::Color(255, 211, 60), sf::Vector2f(window.getSize().x * 0.085, window.getSize().y * 0.335), true);
                sf::Text t_sfx_add = thisWindowHandler->getText(sf::String(L"+"), thisWindowHandler->main_font, 36, sf::Color(255, 211, 60), sf::Vector2f(window.getSize().x * 0.388, window.getSize().y * 0.345), true); // Percentages are annoying
                if(sel == 0)
                {
                    t_sfx_sub.setColor(sf::Color::Green);
                    t_sfx_add.setColor(sf::Color::Green);
                }
                sf::Text t_bgm_sub = thisWindowHandler->getText(sf::String(L"-"), thisWindowHandler->main_font, 36, sf::Color(255, 211, 60), sf::Vector2f(window.getSize().x * 0.085, window.getSize().y * 0.46), true);
                sf::Text t_bgm_add = thisWindowHandler->getText(sf::String(L"+"), thisWindowHandler->main_font, 36, sf::Color(255, 211, 60), sf::Vector2f(window.getSize().x * 0.388, window.getSize().y * 0.47), true);
                if(sel == 1)
                {
                    t_bgm_sub.setColor(sf::Color::Green);
                    t_bgm_add.setColor(sf::Color::Green);
                }
                sf::Text t_back = thisWindowHandler->getText(sf::String(L"Cofnij"), thisWindowHandler->main_font, 24, sf::Color(255, 211, 60), sf::Vector2f(window.getSize().x * 0.89, window.getSize().y * 0.9), true);
                if(sel == 2) t_back.setColor(sf::Color::Green);
                sf::Text t_sfx = thisWindowHandler->getText(sf::String(L"SFX"), thisWindowHandler->main_font, 24, sf::Color(255, 211, 60), sf::Vector2f(window.getSize().x * 0.237, window.getSize().y * 0.36), true);
                sf::Text t_bgm = thisWindowHandler->getText(sf::String(L"BGM"), thisWindowHandler->main_font, 24, sf::Color(255, 211, 60), sf::Vector2f(window.getSize().x * 0.237, window.getSize().y * 0.49), true);

                sf::RectangleShape bar_sfx(sf::Vector2f(window.getSize().x * 0.375, window.getSize().y * 0.02));
                sf::RectangleShape bar_bgm(sf::Vector2f(window.getSize().x * 0.375, window.getSize().y * 0.02));
                sf::RectangleShape ind_sfx(sf::Vector2f(bar_sfx.getSize().x / 100, bar_sfx.getSize().y * 2.4)); // Indicator of current setting
                sf::RectangleShape ind_bgm(sf::Vector2f(bar_sfx.getSize().x / 100, bar_bgm.getSize().y * 2.4));

                bar_sfx.setFillColor(sf::Color(153, 163, 164));
                bar_bgm.setFillColor(sf::Color(153, 163, 164));
                ind_sfx.setFillColor(sf::Color::White);
                ind_bgm.setFillColor(sf::Color::White);

                bar_sfx.setOrigin(sf::Vector2f(bar_sfx.getLocalBounds().width / 2, bar_sfx.getLocalBounds().height / 2));
                bar_bgm.setOrigin(sf::Vector2f(bar_bgm.getLocalBounds().width / 2, bar_bgm.getLocalBounds().height / 2));
                ind_sfx.setOrigin(sf::Vector2f(ind_sfx.getLocalBounds().width / 2, ind_sfx.getLocalBounds().height / 2));
                ind_bgm.setOrigin(sf::Vector2f(ind_bgm.getLocalBounds().width / 2, ind_bgm.getLocalBounds().height / 2));

                bar_sfx.setPosition(sf::Vector2f(window.getSize().x * 0.75, window.getSize().y * 0.37));
                bar_bgm.setPosition(sf::Vector2f(window.getSize().x * 0.75, window.getSize().y / 2));
                ind_sfx.setPosition(sf::Vector2f(bar_sfx.getPosition().x + (thisWindowHandler->sfx_vol - 50.f) * ind_sfx.getSize().x, window.getSize().y * 0.37));
                ind_bgm.setPosition(sf::Vector2f(bar_bgm.getPosition().x + (thisWindowHandler->bgm_vol - 50.f) * ind_bgm.getSize().x, window.getSize().y / 2));

                if(!tex_bg.loadFromFile("Graphics/options_menu.png")) return -1;
                spr_bg.setTexture(tex_bg);

                window.draw(spr_bg);
                window.draw(t_back);
                window.draw(t_credits);
                window.draw(t_sounds);
                window.draw(t_sfx);
                window.draw(t_sfx_sub);
                window.draw(t_sfx_add);
                window.draw(t_bgm);
                window.draw(t_bgm_sub);
                window.draw(t_bgm_add);
                window.draw(bar_sfx);
                window.draw(bar_bgm);
                window.draw(ind_sfx);
                window.draw(ind_bgm);

                break;
            }

            case 3: // Quiz
            {
                sf::Music music;
                if(!music.openFromFile("Audio/quiz_music.ogg")) return -1;
                music.setVolume(thisWindowHandler->bgm_vol);
                music.play();
                music.setLoop(true);

                p1_correct_answers = thisQuizHandler->doQuiz(window, thisWindowHandler, available_questions, 10, "Audio/correct_sound.wav", "Audio/wrong_sound.wav", "Audio/answer_change.wav");
                if(two_players)
                {
                    p2_correct_answers = thisQuizHandler->doQuiz(window, thisWindowHandler, available_questions, 10, "Audio/correct_sound.wav", "Audio/wrong_sound.wav", "Audio/answer_change.wav");
                }
                if(p1_correct_answers == -2 || p2_correct_answers == -2)
                {
                    p1_correct_answers = 0;
                    p2_correct_answers = 0;
                    menu_mode = 0;
                }
                else
                {
                    menu_mode = 4;
                }
                break;
            }

            case 4: // Quiz End
            {
                sf::SoundBuffer end_buffer;
                sf::Sound end_sound;
                end_sound.setVolume(thisWindowHandler->sfx_vol);
                if(two_players)
                {
                    if(!end_buffer.loadFromFile("Audio/win_sound.wav")) return -1;
                    end_sound.setBuffer(end_buffer);
                    end_sound.play();

                    if(thisQuizHandler->printResults(window, p1_correct_answers, p2_correct_answers))
                    {
                        sel = 0;
                        menu_mode = 0;
                        break;
                    }
                }
                else
                {
                    if(p1_correct_answers < 5)
                    {
                        if(!end_buffer.loadFromFile("Audio/fail_sound.wav")) return -1;
                    }
                    else
                    {
                        if(!end_buffer.loadFromFile("Audio/win_sound.wav")) return -1;
                    }

                    end_sound.setBuffer(end_buffer);
                    end_sound.play();

                    if(thisQuizHandler->printResults(window, p1_correct_answers))
                    {
                        sel = 0;
                        menu_mode = 0;
                        break;
                    }
                }
                break;
            }
        }

        window.display();
    }
    return 0;
}
