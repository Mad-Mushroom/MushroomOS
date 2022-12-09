#include "KernelUtil.h"
#include "Memory/Heap.h"
#include "Scheduling/PIT/PIT.h"
#include "BasicRenderer.h"
#include "Framebuffer.h"
#include "UserInput/Mouse.h"
#include "SysApps/Terminal/terminal.h"

bool mcanMove;

void showLoadScreen(){
    mcanMove = false;
    GlobalRenderer->ClearColour = 0x000000;
    GlobalRenderer->Clear();
    GlobalRenderer->CursorPosition = {0,0};
    GlobalRenderer->Print("Starting MushroomOS Alpha...");
    GlobalRenderer->drawRectangle((GlobalRenderer->TargetFramebuffer->Width/2)-50, (GlobalRenderer->TargetFramebuffer->Height/2), 100, 10, 0xffffff);
    for(int i=0; i<100; i++){
        GlobalRenderer->drawRectangle((GlobalRenderer->TargetFramebuffer->Width/2)-50, (GlobalRenderer->TargetFramebuffer->Height/2), 100, 10, 0xffffff);
        GlobalRenderer->drawRectangle(((GlobalRenderer->TargetFramebuffer->Width/2)-50)+i, (GlobalRenderer->TargetFramebuffer->Height/2)-1, 100-i, 8, 0x000000);
        if(i >= 1 && i < 10){ PIT::Sleep(100); }
        if(i >= 10 && i < 30){ PIT::Sleep(400); }
        if(i >= 30 && i < 70){ PIT::Sleep(300); }
        if(i >= 70 && i < 90){ PIT::Sleep(500); }
        if(i >= 98 && i < 100){ PIT::Sleep(300); }
    }
    PIT::Sleep(600);
    mcanMove = true;
}

void startup(){
    GlobalRenderer->ClearColour = 0x2188bf;
    GlobalRenderer->Clear();
    GlobalRenderer->CursorPosition = {0,0};
    GlobalRenderer->Print("MushroomOS Alpha [v0.05]");
    GlobalRenderer->Next();
    GlobalRenderer->Print("Made by MadMushroom");
    GlobalRenderer->Next(); GlobalRenderer->Next();
}

extern "C" void KernelStart(BootInfo* BootInfo){
    KernelInfo KernelInfo = InitializeKernel(BootInfo);

    mcanMove = true;
    //showLoadScreen();
    startup();
    
    //GlobalRenderer->drawRectangle(1000,500,100,100,0xffffff);
    //GlobalRenderer->drawRectangle(500,500,200,100,0xffffff);
    
    //terminal.initTerminal();
    terminal.startTerminal();

    while(true){
        asm ("hlt");
    }

}