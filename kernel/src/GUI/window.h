#include "../BasicRenderer.h"
#include "../Math.h"
#include "../Framebuffer.h"
#include "../SimpleFonts.h" 
#include "../UserInput/Mouse.h"
#include "../User/user.h"
#include <stdint.h>

 typedef struct {
    /* Variables */
    int posX;
    int posY;
    int Width;
    int Height;
    int z_order;
    const char* windowTitle;
    uint32_t backBuffer[1920*1080];
    uint32_t windowBuffer[1920*1080];
    Point CursorPos;
    bool cursorPosInit = false;

    /* Functions */
    void drawWindow();
    void processWindow();
    void clearWindow();
    void drawWindowContent();
    void PutPix(int X, int Y, uint32_t Colour);
    void PutCharWin(char Char, unsigned int XOffset, unsigned int YOffset, uint32_t Colour);
    void PrintLn(const char* string);
    void NewLn();
    void quitWin();
    void minimizeWin();
}newWindow;