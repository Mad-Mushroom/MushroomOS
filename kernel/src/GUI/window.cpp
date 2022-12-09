#include "window.h"

int LeftMouseButton;
int MiddleMouseButton;
int RightMouseButton;

bool canMove = false;

void newWindow::clearWindow(){
    for(int i=0; i<(Height-1)+2; i++){
        for(int j=0; j<Width+2; j++){
            if(i <= 16 && j <= 16){ GlobalRenderer->PutPix(posX+j, posY+i, GlobalRenderer->MouseCursorBuffer[j+(16*i)]); }
            else{ GlobalRenderer->PutPix(posX+j, posY+i, backBuffer[j+(Width*i)]); }
            //GlobalRenderer->PutPix(posX+j, posY+i, backBuffer[j+(Width*i)]);
        }
    }
    //for(int i=0; i<Height+1; i++){
    //    for(int j=0; j<Width+2; j++){
    //        backBuffer[j+(Width*i)] = GlobalRenderer->GetPix(posX+j, posY+i);
    //    }
    //}
}

void newWindow::drawWindowContent(){
    //GlobalRenderer->PutPix(posX+1+Width, posY+16+Height, 0xFFFFFF);
    for(int i=0; i<Height-18; i++){
        for(int j=0; j<Width-2; j++){
            GlobalRenderer->PutPix(posX+1+j, posY+16+i, windowBuffer[j+(Width*i)]);
        }
    }
}

void newWindow::PutPix(int X, int Y, uint32_t Colour){
    windowBuffer[X+(Width*Y)] = Colour;
    //drawWindowContent();
}

void newWindow::PutCharWin(char Char, unsigned int XOffset, unsigned int YOffset, uint32_t Colour){
    unsigned int* PixelPtr = (unsigned int*)GlobalRenderer->TargetFramebuffer->BaseAddress;
    char* FontPtr = (char*)GlobalRenderer->PSF1Font->GlyphBuffer + (Char * GlobalRenderer->PSF1Font->PSF1Header->CharSize);
    for (unsigned long Y = YOffset; Y < YOffset + 16; Y++){
        for (unsigned long X = XOffset; X < XOffset+8; X++){
            if ((*FontPtr & (0b10000000 >> (X - XOffset))) > 0){
                    //*(unsigned int*)(PixelPtr + X + (Y * GlobalRenderer->TargetFramebuffer->PixelsPerScanLine)) = Colour;
                    windowBuffer[X + (Y * Width)] = Colour;
                }

        }
        FontPtr++;
    }
}

void newWindow::PrintLn(const char* String){
    if(!cursorPosInit){ CursorPos = {2, 2}; cursorPosInit=true; }
    //Point TempCursorPosition = GlobalRenderer->CursorPosition;
    //GlobalRenderer->CursorPosition = CursorPos;
    //GlobalRenderer->Print(string);
    //GlobalRenderer->CursorPosition = TempCursorPosition;
    //CursorPos.X = posX+2;
    //CursorPos.Y += 16;
    char* Char = (char*)String;
    while(*Char != 0){
        PutCharWin(*Char, CursorPos.X, CursorPos.Y, 0xFFFFFF);
        CursorPos.X+=8;
        if(CursorPos.X + 8 > Width)
        {
            CursorPos.X = 0;
            CursorPos.Y += 16;
        }
        Char++;
    }
}

void newWindow::NewLn(){
    CursorPos.X = 0;
    CursorPos.Y += 16;
}

void newWindow::drawWindow(){
    for(int i=0; i<(Height-1)+2; i++){
        for(int j=0; j<Width+2; j++){
            backBuffer[j+(Width*i)] = GlobalRenderer->GetPix(posX+j, posY+i);
        }
    }
    GlobalRenderer->drawRectangleNoFill(posX, posY, Width, Height, 0xFFFFFF);
    unsigned int tempColour = GlobalRenderer->Colour;
    //if(UserSettings.theme == 0){ GlobalRenderer->drawRectangle(posX+1, posY+1, Width-1, 14, 0x000000); GlobalRenderer->Colour = 0xFFFFFF; }
    //if(UserSettings.theme == 1){ GlobalRenderer->drawRectangle(posX+1, posY+1, Width-1, 14, 0xFFFFFF); GlobalRenderer->Colour = 0x000000; }
    GlobalRenderer->drawRectangle(posX+1, posY+1, Width-1, 14, 0x000000); GlobalRenderer->Colour = 0xFFFFFF;
    GlobalRenderer->drawHorizontalLine(posX, posY+15, Width, 0xFFFFFF);
    Point TempCursorPosition = GlobalRenderer->CursorPosition;
    GlobalRenderer->CursorPosition = {posX+2, posY};
    GlobalRenderer->Print(windowTitle);
    GlobalRenderer->CursorPosition = {posX+Width-26, posY};
    GlobalRenderer->Print("_ X");
    GlobalRenderer->CursorPosition = TempCursorPosition;
    GlobalRenderer->Colour = tempColour;
    drawWindowContent();
}

void newWindow::quitWin(){
    clearWindow();
}

void newWindow::minimizeWin(){

}

void newWindow::processWindow(){
    if(MousePosition.X > posX+Width-16 && MousePosition.X < posX+Width-0 && MousePosition.Y > posY && MousePosition.Y < posY+15){
        if(LeftMouseButton == 1){
            quitWin();
        }
    }

    if(MousePosition.X > posX && MousePosition.X < posX+Width-35 && MousePosition.Y > posY && MousePosition.Y < posY+15){
        if(LeftMouseButton == 1){
            canMove = true;
        }
    }

    if(LeftMouseButton == 0){
            canMove = false;
    }

    //if(posX + Width >= GlobalRenderer->TargetFramebuffer->Width){ posX = GlobalRenderer->TargetFramebuffer->Width - Width; }
    //if(posY + Height >= GlobalRenderer->TargetFramebuffer->Height){ posY = GlobalRenderer->TargetFramebuffer->Height -Height; }

    if(canMove == true){
        clearWindow();
        posX = MousePosition.X;
        posY = MousePosition.Y;
        drawWindow();
    }
}