//
// Created by Nischay on 18/12/2020.
//

#ifndef CONSOLE_H
#define CONSOLE_H


class Console {
private:
    std::string welcome_message;

public:
    void printWelcomeMessage(std::string);
    int requestCharacterSelection();
    int requestBoardDimensions();
    void renderConsoleInterface();
    void renderConsoleWithEmojis();

};


#endif //CONSOLE_H
