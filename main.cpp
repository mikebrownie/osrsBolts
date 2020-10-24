#include <windows.h>
#include <iostream>


void LeftClick ( )
{
  INPUT    Input={0};
  // left down
  Input.type      = INPUT_MOUSE;
  Input.mi.dwFlags  = MOUSEEVENTF_LEFTDOWN;
  ::SendInput(1,&Input,sizeof(INPUT));

  // left up
  ::ZeroMemory(&Input,sizeof(INPUT));
  Input.type      = INPUT_MOUSE;
  Input.mi.dwFlags  = MOUSEEVENTF_LEFTUP;
  ::SendInput(1,&Input,sizeof(INPUT));
}


void PressOne()
{
  const UINT VKey = 0x31;
  INPUT Input = { 0 };
  // Keydown
  ::ZeroMemory(&Input,sizeof(INPUT));
  Input.type = INPUT_KEYBOARD;
  Input.ki.dwFlags = KEYEVENTF_SCANCODE;
  Input.ki.wScan = ::MapVirtualKey(VKey, 0 );
  Input.ki.dwExtraInfo = 0;
  ::SendInput(1,&Input,sizeof(INPUT));
}


void ReleaseOne(){
  const UINT VKey = 0x31;

  INPUT Input = { 0 };
  // Keyup
  ::ZeroMemory(&Input,sizeof(INPUT));
  Input.type = INPUT_KEYBOARD;
  Input.ki.dwFlags = KEYEVENTF_SCANCODE | KEYEVENTF_KEYUP;
  Input.ki.wScan = ::MapVirtualKey(VKey, 0 );
  Input.ki.dwExtraInfo = 0;
  ::SendInput(1,&Input,sizeof(INPUT));
}



int main()
{
  std::cout<<"Running... Press [SPACE BAR] once to toggle on/off. System Interupts (ex. CTRL+C) to stop entirely";
  bool running = true;
  bool clicking = false;
  while(running){
    if(GetKeyState(VK_SPACE) < 0){ //Could use a better state switcher here
      clicking = !clicking;
      Sleep(500); //Don't read multiple times
    }
    if(clicking){
      LeftClick();
      Sleep(600);
      PressOne();
      //Maybe random sleep
    }
  }
std::cout<<"Done";
  return 0;
}
