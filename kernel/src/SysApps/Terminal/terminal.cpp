#include "terminal.h"

//newWindow TerminalWindow;
Terminal terminal;

void Terminal::initTerminal(){
    terminal.TerminalWindow.posX = 500;
    terminal.TerminalWindow.posY = 100;
    terminal.TerminalWindow.Width = 400;
    terminal.TerminalWindow.Height = 500;
    terminal.TerminalWindow.windowTitle = "Terminal";
}

void Terminal::PrintStartText(){
    terminal.TerminalWindow.PrintLn("MushroomOS Terminal [v0.01]");
    terminal.TerminalWindow.NewLn();
    terminal.TerminalWindow.PrintLn("Copyright (c) 2022 MadMushroom");
    terminal.TerminalWindow.NewLn();
    terminal.TerminalWindow.NewLn();
    terminal.TerminalWindow.PrintLn("The Terminal and Operating System is NOT finished yet. Please do NOT use it as your native System!");
    terminal.TerminalWindow.NewLn();
}

void Terminal::ClearWindowScreen(){
    for(int i=0; i<terminal.TerminalWindow.Width; i++){
        for(int j=0; j<terminal.TerminalWindow.Height; j++){
            terminal.TerminalWindow.PutPix(i, j, 0x000000);
        }
    }
}

void Terminal::startTerminal(){
    ClearWindowScreen();
    PrintStartText();
    terminal.TerminalWindow.drawWindow();
    while(true){
        terminal.TerminalWindow.processWindow();
    }
    //newWindow TerminalWindow;
    //TerminalWindow.posX = 500;
    //TerminalWindow.posY = 100;
    //TerminalWindow.Width = 400;
    //TerminalWindow.Height = 500;
    //TerminalWindow.windowTitle = "Terminal";
    //for(int i=0; i<TerminalWindow.Width; i++){
    //    for(int j=0; j<TerminalWindow.Height; j++){
    //        TerminalWindow.PutPix(i, j, 0x000000);
    //    }
    //}
    //TerminalWindow.PrintLn("MushroomOS Terminal [v0.01]");
    //TerminalWindow.NewLn();
    //TerminalWindow.PrintLn("Copyright (c) 2022 MadMushroom");
    //TerminalWindow.NewLn();
    //TerminalWindow.NewLn();
    //TerminalWindow.PrintLn("The Terminal and Operating System is NOT finished yet. Please do NOT use it as your native System!");
    //TerminalWindow.NewLn();
    //TerminalWindow.drawWindow();
    //while(true){
    //    TerminalWindow.processWindow();
    //}
}