#include "Keyboard.h"

bool IsLeftShiftPressed;
bool IsRightShiftPressed;

uint8_t scanner;

char GetInput(){
    switch (scanner){
        case LeftShift:
            IsLeftShiftPressed = true;
            return 0;
        case LeftShift + 0x80:
            IsLeftShiftPressed = false;
            return 0;
        case RightShift:
            IsRightShiftPressed = true;
            return 0;
        case RightShift + 0x80:
            IsRightShiftPressed = false;
            return 0;
        case Enter:
            GlobalRenderer->Next();
            return 0;
        case Spacebar:
            GlobalRenderer->PutChar(' ');
            return 0;
        case BackSpace:
           GlobalRenderer->ClearChar();
           return 0;
    }

    char ASCII = QWERTYKeyboard::Translate(scanner, IsLeftShiftPressed | IsRightShiftPressed);

    if (ASCII != 0){
        return ASCII;
    }
}

void HandleKeyboard(uint8_t Scancode){
    scanner = Scancode;
    switch (Scancode){
        case LeftShift:
            IsLeftShiftPressed = true;
            return;
        case LeftShift + 0x80:
            IsLeftShiftPressed = false;
            return;
        case RightShift:
            IsRightShiftPressed = true;
            return;
        case RightShift + 0x80:
            IsRightShiftPressed = false;
            return;
        case Enter:
            GlobalRenderer->Next();
            return;
        case Spacebar:
            GlobalRenderer->PutChar(' ');
            return;
        case BackSpace:
           GlobalRenderer->ClearChar();
           return;
    }

    char ASCII = QWERTYKeyboard::Translate(Scancode, IsLeftShiftPressed | IsRightShiftPressed);

    if (ASCII != 0){
        //GlobalRenderer->PutChar(ASCII);
    }

}