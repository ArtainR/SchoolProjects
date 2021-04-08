#include <fstream>
#include <vector>
#include <windows.h>
#include <string>
#include <codecvt>
#include <locale>
#include <SFML/Audio.hpp>
#include "QuizHandler.h"
#include "WindowHandler.h"

using namespace std;

vector<QuizHandler::Question> QuizHandler::readQuizFile(string file_path)
{
    fstream quiz;
    quiz.open(file_path);
    vector<QuizHandler::Question> questions;
    string cur_line;
    Question cur_question = Question();
    int answers_count = 0;
    if(quiz.good())
    {
        while(getline(quiz, cur_line))
        {
            if(cur_line.substr(0, 4) == "//##")
            {
                continue;
            }
            else
            {
                if(cur_line.substr(0, 1) == "-")
                {
                    if(cur_question.question != "Error")
                    {
                        questions.push_back(cur_question);
                        cur_question.question = "";
                        cur_question.answers.clear();
                        answers_count = 0;
                    }
                    cur_question.question = cur_line.substr(1);
                }
                else
                {
                    if(cur_line.substr(0, 1) == "=")
                    {
                        cur_question.answers.push_back(cur_line.substr(1));
                        cur_question.correct_answer = answers_count;
                    }
                    else
                    {
                        cur_question.answers.push_back(cur_line);
                    }
                    answers_count++;
                }
            }
        }
    }

    quiz.close();
    return questions;
}

void QuizHandler::drawAnswers(sf::RenderWindow &window, vector<string> answers, int sel[2])
{
    for(int i = 0; i < answers.size(); i++)
    {
        float ans_x = window.getSize().x * 1/4;
        if(i % 2 != 0)
        {
            ans_x += window.getSize().x / 2;
        }
        float ans_y = window.getSize().y * 0.57;
        if(i > 1)
        {
            ans_y = window.getSize().y * 0.77;
        }

        string s_answer = thisWindowHandler->wrapString(answers[i], thisWindowHandler->main_font, 18, sf::Vector2f(ans_x, ans_y), true, window.getSize().x / 2 * 0.90);
        sf::Text t_answer = thisWindowHandler->getText(sf::String(wstring_convert<codecvt_utf8<wchar_t>>().from_bytes(s_answer)), thisWindowHandler->main_font, 18, sf::Color(255, 211, 60), sf::Vector2f(ans_x, ans_y), true);
        if(i == sel[1] * 2 + sel[0])
        {
            t_answer.setColor(sf::Color::Green);
        }

        window.draw(t_answer);
    }
}

int QuizHandler::doQuiz(sf::RenderWindow &window, WindowHandler* &windowHandler, vector<QuizHandler::Question> questions, int question_amount, string correct_sound_path, string wrong_sound_path, string answer_change_sound_path)
{
    thisWindowHandler = windowHandler;

    sf::SoundBuffer correct_sound;
    if(!correct_sound.loadFromFile(correct_sound_path)) return -1;
    sf::SoundBuffer wrong_sound;
    if(!wrong_sound.loadFromFile(wrong_sound_path)) return -1;
    sf::SoundBuffer answer_change;
    if(!answer_change.loadFromFile(answer_change_sound_path)) return -1;

    sf::Sound quiz_sound;
    quiz_sound.setVolume(thisWindowHandler->sfx_vol);

    sf::Texture tex_bg;
    if(!tex_bg.loadFromFile("Graphics/quiz_bg.png")) return -1;
    sf::Sprite spr_bg;
    spr_bg.setTexture(tex_bg);

    int correct_answers = 0;
    int sel[2] = {0, 0};
    for(int i = 0; i < question_amount; i++)
    {
        int sel_answer = 0;
        int question_index = rand() % questions.size();
        QuizHandler::Question cur_question = questions[question_index];

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

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            {
                while(sf::Keyboard::isKeyPressed(sf::Keyboard::Left));
                if(sel[0] > 0 && sel[1] != 2)
                {
                    sel[0] = 0;
                }
                else if (sel[1] == 2)
                {
                    sel[0] = 0;
                    sel[1] = 1;
                }
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            {
                while(sf::Keyboard::isKeyPressed(sf::Keyboard::Right));
                if(sel[0] < 1 && sel[1] != 2)
                {
                    sel[0] = 1;
                }
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            {
                while(sf::Keyboard::isKeyPressed(sf::Keyboard::Up));
                if(sel[1] == 2)
                {
                    sel[0] = 1;
                    sel[1] = 1;
                }
                else if(sel[1] > 0)
                {
                    sel[1]--;
                }
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            {
                while(sf::Keyboard::isKeyPressed(sf::Keyboard::Down));
                if(sel[1] < 2)
                {
                    sel[1]++;
                }
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
            {
                while(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter));
                if(sel[1] == 2)
                {
                    return -2;
                }
                if(sel[1] * 2 + sel[0] == cur_question.correct_answer)
                {
                    quiz_sound.setBuffer(correct_sound);
                    quiz_sound.play();
                    correct_answers++;
                }
                else
                {
                    quiz_sound.setBuffer(wrong_sound);
                    quiz_sound.play();
                }
                break;
            }

            sf::Text t_back = thisWindowHandler->getText(sf::String(L"Cofnij"), thisWindowHandler->main_font, 24, sf::Color(255, 211, 60), sf::Vector2f(window.getSize().x * 0.89, window.getSize().y * 0.95), true);
            if(sel[1] == 2) t_back.setColor(sf::Color::Green);
            sf::Text t_left;
            if(question_amount - i != 1)
            {
                t_left = thisWindowHandler->getText(L"Zostało " + wstring_convert<codecvt_utf8<wchar_t>>().from_bytes(to_string(question_amount - i)) + L" pytań", thisWindowHandler->main_font, 18, sf::Color(255, 211, 60), sf::Vector2f(padding_h, 2), false);
            }
            else
            {
                t_left = thisWindowHandler->getText(L"Zostało 1 pytanie", thisWindowHandler->main_font, 18, sf::Color(255, 211, 60), sf::Vector2f(padding_h, 2), false);
            }
            sf::Text t_correct = thisWindowHandler->getText(sf::String("Liczba poprawnych odpowiedzi: " + to_string(correct_answers) + " / " + to_string(question_amount - (i - correct_answers))), thisWindowHandler->main_font, 18, sf::Color(255, 211, 60), sf::Vector2f(padding_h, 0.8 * padding_v), false);

            string s_question = thisWindowHandler->wrapString(cur_question.question, thisWindowHandler->main_font, 28, sf::Vector2f(padding_h, window.getSize().y * 0.2), false, window.getSize().x * 0.97);
            sf::Text t_question = thisWindowHandler->getText(sf::String(wstring_convert<codecvt_utf8<wchar_t>>().from_bytes(s_question)), thisWindowHandler->main_font, 28, sf::Color(255, 211, 60), sf::Vector2f(padding_h, window.getSize().y * 0.2), false);

            window.draw(spr_bg);
            window.draw(t_left);
            window.draw(t_correct);
            window.draw(t_question);
            window.draw(t_back);
            drawAnswers(window, cur_question.answers, sel);

            window.display();
        }
        questions.erase(questions.begin() + question_index);
    }
    while(quiz_sound.getStatus() == 2);
    return correct_answers;
}

bool QuizHandler::printResults(sf::RenderWindow &window, int p1_results)
{
    sf::Texture tex_bg;
    if(!tex_bg.loadFromFile("Graphics/1p_end.png")) return true;
    sf::Sprite spr_bg;
    spr_bg.setTexture(tex_bg);

    int sel = 0;
    int max_sel = 1;

    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                window.close();
                return false;
            }
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            while(sf::Keyboard::isKeyPressed(sf::Keyboard::Right));
            if(sel < max_sel)
            {
                sel++;
            }
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            while(sf::Keyboard::isKeyPressed(sf::Keyboard::Left));
            if(sel > 0)
            {
                sel--;
            }
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
        {
            while(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter));
            if(sel == 0)
            {
                return true;
            }
            if(sel == 1)
            {
                window.close();
                return false;
            }
        }

        window.clear(thisWindowHandler->bg_color);

        sf::Text t_back = thisWindowHandler->getText(sf::String(L"Cofnij"), thisWindowHandler->main_font, 18, sf::Color(255, 211, 60), sf::Vector2f(window.getSize().x * 0.75, window.getSize().y * 0.95), true);
        if(sel == 0) t_back.setColor(sf::Color::Green);
        sf::Text t_exit = thisWindowHandler->getText(sf::String(L"Wyjdź"), thisWindowHandler->main_font, 18, sf::Color(255, 211, 60), sf::Vector2f(window.getSize().x * 0.91, window.getSize().y * 0.95), true);
        if(sel == 1) t_exit.setColor(sf::Color::Green);
        sf::Text t_p1 = thisWindowHandler->getText(sf::String(L"Twój wynik"), thisWindowHandler->main_font, 36, sf::Color(255, 211, 60), sf::Vector2f(window.getSize().x / 2, window.getSize().y * 0.19), true);
        sf::Text t_p1_points = thisWindowHandler->getText(sf::String(to_string(p1_results)), thisWindowHandler->result_font, 250, sf::Color(255, 211, 60), sf::Vector2f(window.getSize().x * 0.47, window.getSize().y * 0.4), true);

        window.draw(spr_bg);
        window.draw(t_back);
        window.draw(t_exit);
        window.draw(t_p1);
        window.draw(t_p1_points);

        window.display();
    }
}

bool QuizHandler::printResults(sf::RenderWindow &window, int p1_results, int p2_results)
{
    sf::Texture tex_bg;
    if(!tex_bg.loadFromFile("Graphics/2p_end.png")) return true;
    sf::Sprite spr_bg;
    spr_bg.setTexture(tex_bg);

    int sel = 0;
    int max_sel = 1;

    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                window.close();
                return false;
            }
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            while(sf::Keyboard::isKeyPressed(sf::Keyboard::Right));
            if(sel < max_sel)
            {
                sel++;
            }
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            while(sf::Keyboard::isKeyPressed(sf::Keyboard::Left));
            if(sel > 0)
            {
                sel--;
            }
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
        {
            while(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter));
            if(sel == 0)
            {
                return true;
            }
            if(sel == 1)
            {
                window.close();
                return false;
            }
        }

        window.clear(thisWindowHandler->bg_color);

        sf::Text t_back = thisWindowHandler->getText(sf::String(L"Cofnij"), thisWindowHandler->main_font, 18, sf::Color(255, 211, 60), sf::Vector2f(window.getSize().x * 0.75, window.getSize().y * 0.95), true);
        if(sel == 0) t_back.setColor(sf::Color::Green);
        sf::Text t_exit = thisWindowHandler->getText(sf::String(L"Wyjdź"), thisWindowHandler->main_font, 18, sf::Color(255, 211, 60), sf::Vector2f(window.getSize().x * 0.91, window.getSize().y * 0.95), true);
        if(sel == 1) t_exit.setColor(sf::Color::Green);
        sf::Text t_p1 = thisWindowHandler->getText(sf::String(L"Wynik P1"), thisWindowHandler->main_font, 36, sf::Color(255, 211, 60), sf::Vector2f(window.getSize().x * 0.25, window.getSize().y * 0.19), true);
        sf::Text t_p2 = thisWindowHandler->getText(sf::String(L"Wynik P2"), thisWindowHandler->main_font, 36, sf::Color(255, 211, 60), sf::Vector2f(window.getSize().x * 0.73, window.getSize().y * 0.19), true);
        sf::Text t_p1_points = thisWindowHandler->getText(sf::String(to_string(p1_results)), thisWindowHandler->result_font, 250, sf::Color(255, 211, 60), sf::Vector2f(window.getSize().x * 0.23, window.getSize().y * 0.4), true);
        sf::Text t_p2_points = thisWindowHandler->getText(sf::String(to_string(p2_results)), thisWindowHandler->result_font, 250, sf::Color(255, 211, 60), sf::Vector2f(window.getSize().x * 0.72, window.getSize().y * 0.4), true);

        window.draw(spr_bg);
        window.draw(t_back);
        window.draw(t_exit);
        window.draw(t_p1);
        window.draw(t_p2);
        window.draw(t_p1_points);
        window.draw(t_p2_points);

        window.display();
    }
}
