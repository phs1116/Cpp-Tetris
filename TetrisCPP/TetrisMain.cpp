#include "TetrisBoard.h"
#include "CursurControl.h"
#include "GameHandler.h"
#include "TetrisCommon.h"
using namespace std;
void ShowLogo(){


	puts("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬");
	puts("早收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收早");
	puts("早收﹣﹣﹣﹣﹣收﹣﹣﹣﹣﹣收﹣﹣﹣﹣﹣收﹣﹣﹣﹣﹣收﹣﹣﹣﹣﹣收早");
	puts("早收收收﹣收收收﹣收收收收收收收﹣收收收﹣收收收﹣收﹣收收收收收早");
	puts("早收收收﹣收收收﹣收收收收收收收﹣收收收﹣收收收﹣收﹣收收收收收早");
	puts("早收收收﹣收收收﹣﹣﹣﹣﹣收收收﹣收收收﹣﹣﹣﹣﹣收﹣﹣﹣﹣﹣收早");
	puts("早收收收﹣收收收﹣收收收收收收收﹣收收收﹣收收﹣收收收收收收﹣收早");
	puts("早收收收﹣收收收﹣收收收收收收收﹣收收收﹣收收收﹣收收收收  ﹣收早");
	puts("早收收收﹣收收收﹣﹣﹣﹣﹣收收收﹣收收收﹣收收收﹣收﹣﹣﹣﹣﹣收早");
	puts("早收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收早");
	puts("早收收收收收收收收收收收收收收收收收收VER 0.1  Made By.HS PARK收早");
	puts("早收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收早");
	puts("早收收收收收收收收收收 Press Any key to start 收收收收收收收收收早");
	puts("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭");
}

int main(){
	nocursor();
	GameHandler tetris;
	ShowLogo();
	tetris.GameStart();

}


