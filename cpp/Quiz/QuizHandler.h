#ifndef QUIZHANDLER_H
#define QUIZHANDLER_H
#include "WindowHandler.h"
#include <vector>

class QuizHandler
{
    public:
        struct Question
        {
            std::string question = "Error";
            std::vector<std::string> answers;
            int correct_answer = 0;
        };

        WindowHandler* thisWindowHandler;
        int padding_h = 6;
        int padding_v = 45;

        std::vector<Question> readQuizFile(std::string file_path);
        void drawAnswers(sf::RenderWindow &window, std::vector<std::string> answers, int sel[2]);
        int doQuiz(sf::RenderWindow &window, WindowHandler* &WindowHandler, std::vector<Question> questions, int question_amount, std::string correct_sound_path, std::string wrong_sound_path, std::string answer_change_sound_path);
        bool printResults(sf::RenderWindow &window, int p1_results);
        bool printResults(sf::RenderWindow &window, int p1_results, int p2_results);
};

#endif // QUIZHANDLER_H
