#include "GameHandler.h"
#include "CursurControl.h"
#include <Windows.h>

#define KeyboardInputTIme 20

GameHandler::GameHandler(){
	game = new TBoard();

}

void GameHandler::GameStart(){
	while (true){
		if (_kbhit() != 0){
			_getch();
			system("cls");
			break;
		}
	}
	

	GameInit();
	ShowScore();
	Sleep(100);
	while (GameOver()){
		PressKey();
	}
	system("cls");

	gotoxy(30, 12); puts("G A M E  O V E R");
	Sleep(100);
	_getch();


}

void GameHandler::GameInit(){

	game->drawBoard();
	game->PrintBrickToBoard(true);

}

bool GameHandler::GameOver(){
	int y = game->GetCurrentY();
	int x = game->GetCurrentX();
	int shape = game->GetCurrentBrick().GetShape();
	int rot = game->GetCurrentBrick().GetRot();
	if (!game->CollisionCheck(x, y , shape, rot)){
		game->FullBelowCheck();
		game->PrintBrickToBoard(true);
		//game->drawBoard();
		return false;
	}

	return true;
}
bool GameHandler::MoveDown(){
	int y = game->GetCurrentY();
	int x = game->GetCurrentX();
	int shape = game->GetCurrentBrick().GetShape();
	int rot = game->GetCurrentBrick().GetRot();
	if (!game->CollisionCheck(x, y + 1, shape, rot)){
		int plus=game->FullBelowCheck();
		score += plus * 10;
		if (plus != 0 && score % 100 == 0){
			GameSpeedUp();
		}
		//system("cls");
		game->PrintBrickToBoard(true);
		game->drawBoard();
		ShowScore();
		return false;
	}
	game->PrintBrickToBoard(false);
	game->ChangeCurrentY(1);
	game->PrintBrickToBoard(true);
	//game->CollisionCheck(x, y , shape, rot);
	return true;
}
void GameHandler::PressLeft(){
	int y = game->GetCurrentY();
	int x = game->GetCurrentX();
	int shape = game->GetCurrentBrick().GetShape();
	int rot = game->GetCurrentBrick().GetRot();
	if (!game->CollisionCheck(x - 1, y, shape, rot)){
		//game->FullCheck(x, y-1, shape, rot);
		//game->PrintBrickToBoard(false);
		//game->drawBoard();
		return;
	}
	game->PrintBrickToBoard(false);
	game->ChangeCurrentX(-1);
	game->PrintBrickToBoard(true);
	//game->CollisionCheck(x, y , shape, rot);
}
void GameHandler::PressRight(){
	int y = game->GetCurrentY();
	int x = game->GetCurrentX();
	int shape = game->GetCurrentBrick().GetShape();
	int rot = game->GetCurrentBrick().GetRot();
	if (!game->CollisionCheck(x + 1, y, shape, rot)){
		//game->FullCheck(x, y-1, shape, rot);
		//game->PrintBrickToBoard(false);
		//game->drawBoard();
		return;
	}
	game->PrintBrickToBoard(false);
	game->ChangeCurrentX(1);
	game->PrintBrickToBoard(true);
	//game->CollisionCheck(x, y , shape, rot);
}
void GameHandler::PressUp(){
	int y = game->GetCurrentY();
	int x = game->GetCurrentX();
	int shape = game->GetCurrentBrick().GetShape();
	int rot = game->GetCurrentBrick().GetRot();
	if (!game->CollisionCheck(x, y, shape, rot > 3 ? 0 : rot + 1)){
		//game->FullCheck(x, y-1, shape, rot);
		//game->PrintBrickToBoard(false);
		//game->drawBoard();
		return;
	}
	game->PrintBrickToBoard(false);
	game->GetCurrentBrick().RotateBrick();
	game->PrintBrickToBoard(true);
	//game->CollisionCheck(x, y , shape, rot);
}

void GameHandler::PressKey(){
	for (int i = 0; i < KeyboardInputTIme; i++){
		if (_kbhit() != 0)
		{
			switch (_getch())
			{
			case LEFT:
				PressLeft();
				break;
			case RIGHT:
				PressRight();
				break;
			case UP:
				PressUp();
				break;
			case SPACE:
				while (MoveDown()){}
				break;
			}
		}
		if (i% gamespeed == 0){ //  Gamespeed변수때마다 sleep 호출
			Sleep(20);

		}
	}
	MoveDown();
}

void GameHandler::GameSpeedUp(){
	gamespeed += 1;
}

void GameHandler::ShowScore(){
	gotoxy(45,10);
	printf("SCORE : %d", score);
	gotoxy(45,12);
	printf("LEVEL : %d", gamespeed%2);
	
	game->ShowNextBrick(true);
}