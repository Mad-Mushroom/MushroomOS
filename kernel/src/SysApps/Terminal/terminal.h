#pragma once
#include "../../GUI/window.h"
#include "../../UserInput/Keyboard.h"

class Terminal{
public:
    newWindow TerminalWindow;
    void initTerminal();
    void startTerminal();
    void PrintStartText();
    void ClearWindowScreen();
};

extern Terminal terminal;