#include "Game.h"
#include <iostream>
#include <conio.h>

const clock_t G_TIME = 500;

Game::Game(){
	this->g_nDudagiCount = 0;
	this->ttime = 0;
	this->g_timer = clock();
	for (int i = 0; i < 9; ++i){
		this->g_Dudagi[i] = nullptr;
	}
	this->g_Point[0] = { 10, 15 };
	this->g_Point[1] = { 20, 15 };
	this->g_Point[2] = { 30, 15 };
	this->g_Point[3] = { 10, 10 };
	this->g_Point[4] = { 20, 10 };
	this->g_Point[5] = { 30, 10 };
	this->g_Point[6] = { 10, 5 };
	this->g_Point[7] = { 20, 5 };
	this->g_Point[8] = { 30, 5 };
}

void Game::MangchiAttack(int _x, int _y){
	this->Print(_x - 4, _y - 1, "☆┏━┓");
	this->Print(_x - 4, _y, "⊂┃쾅┃〓〓⊂⊃");
	this->Print(_x - 4, _y + 1, "☆┗━┛");
}

void Game::MangchiReady(int _x = 38, int _y = 10){
	this->Print(_x - 4, _y - 2, "    ∩");
	this->Print(_x - 4, _y - 1, "  ┏━┓");
	this->Print(_x - 4, _y, "  ┃  ┃");
	this->Print(_x - 4, _y + 1, "  ┗━┛");
	this->Print(_x - 4, _y + 2, "    ∥");
	this->Print(_x - 4, _y + 3, "    ∥");
	this->Print(_x - 4, _y + 4, "    ∩");
	this->Print(_x - 4, _y + 5, "    ∪");
}

void Game::Ready(){
	this->Clear();
	this->Print(0, 0, "┏━━━━━━━━━━━━━━━━━━━━┓");
	this->Print(0, 1, "┃                                        ┃");
	this->Print(0, 2, "┃                                        ┃");
	this->Print(0, 3, "┃                                        ┃");
	this->Print(0, 4, "┃                                        ┃");
	this->Print(0, 5, "┃                                        ┃");
	this->Print(0, 6, "┃                                        ┃");
	this->Print(0, 7, "┃                                        ┃");
	this->Print(0, 8, "┃             ////////                   ┃");
	this->Print(0, 9, "┃             ┃＼ /┃ ＼│/             ┃");
	this->Print(0, 10, "┃             ┃··┃┏┳┳┓           ┃");
	this->Print(0, 11, "┃             ┗┓┏┛┗┓┏┛           ┃");
	this->Print(0, 12, "┃                                        ┃");
	this->Print(0, 13, "┃                                        ┃");
	this->Print(0, 14, "┃                                        ┃");
	this->Print(0, 15, "┃             두더지 잡기 게임           ┃");
	this->Print(0, 16, "┃                                        ┃");
	this->Print(0, 17, "┃          space 키를 눌러주세요         ┃");
	this->Print(0, 18, "┃                                        ┃");
	this->Print(0, 19, "┃                                        ┃");
	this->Print(0, 20, "┃                                        ┃");
	this->Print(0, 21, "┃                                        ┃");
	this->Print(0, 22, "┃                                        ┃");
	this->Print(0, 23, "┗━━━━━━━━━━━━━━━━━━━━┛");
	this->Flipping();
}

void Game::Result(){
	this->Clear();
	char string[100];
	sprintf(string, "%d", this->g_nDudagiCount * 10);
	this->Print(14, 19, string);
	this->Print(0, 0, "┏━━━━━━━━━━━━━━━━━━━━┓");
	this->Print(0, 1, "┃                                        ┃");
	this->Print(0, 2, "┃                                        ┃");
	this->Print(0, 3, "┃                                        ┃");
	this->Print(0, 4, "┃             // / // ＼＼＼             ┃");
	this->Print(0, 5, "┃             │/＼    /＼│♬           ┃");
	this->Print(0, 6, "┃             │≡  ▽  ≡│○           ┃");
	this->Print(0, 7, "┃              ＼_________///            ┃");
	this->Print(0, 8, "┃                                        ┃");
	this->Print(0, 9, "┃                                        ┃");
	this->Print(0, 10, "┃                                        ┃");
	this->Print(0, 11, "┃                                        ┃");
	this->Print(0, 12, "┃                                        ┃");
	this->Print(0, 13, "┃                                        ┃");
	this->Print(0, 14, "┃                                        ┃");
	this->Print(0, 15, "┃       다시 하시겠습니까? ( y/n )       ┃");
	this->Print(0, 16, "┃                                        ┃");
	this->Print(0, 17, "┃                                        ┃");
	this->Print(0, 18, "┃                                        ┃");
	this->Print(0, 19, "┃     총점 :                             ┃");
	this->Print(0, 20, "┃                                        ┃");
	this->Print(0, 21, "┃                                        ┃");
	this->Print(0, 22, "┃                                        ┃");
	this->Print(0, 23, "┗━━━━━━━━━━━━━━━━━━━━┛");
	this->Flipping();
}

void Game::Update(){
	clock_t CurTime = clock();
	if (CurTime - this->g_timer > G_TIME){
		int k;
		for (int i = 0; i < 9; ++i){
			k = rand() % 2;
			if (this->g_Dudagi[i] == nullptr){
				if (k){
					this->g_Dudagi[i] = new DUDAGI;
				}
			}
			else{
				delete this->g_Dudagi[i];
				this->g_Dudagi[i] = nullptr;
				k = rand() % 2;
				if (k==0){
					this->g_Dudagi[i] = new DUDAGI;
				}
			}
		}
		this->g_Mangchi.SetState(0);
		++this->ttime;
		this->g_timer = clock();
	}
	if (this->g_Mangchi.GetState()){
		for (int i = 0; i < 9; ++i){
			if (this->g_Dudagi[this->g_Mangchi.GetState()-1] != nullptr){
				delete this->g_Dudagi[this->g_Mangchi.GetState()-1];
				g_Dudagi[this->g_Mangchi.GetState()-1] = nullptr;
				++this->g_nDudagiCount;
			}
		}
	}
}

void Game::Render(){
	this->Clear();
	switch (this->g_Mangchi.GetState()){
	case 0:
		this->MangchiReady();
		break;
	case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 9:
		this->MangchiAttack(this->g_Point[this->g_Mangchi.GetState()-1].nX, this->g_Point[this->g_Mangchi.GetState()-1].nY);
	}

	char string[100];
	sprintf(string, "잡은 두더지 : %d", this->g_nDudagiCount);
	this->Print(2, 1, string);
	sprintf(string, "점수 : %d 남은 시간 : %d ", this->g_nDudagiCount * 10, this->ttime);
	this->Print(2, 2, string);

	for (int i = 0; i < 9; i++)
	{
		if (this->g_Dudagi[i] != nullptr){
			this->Print(g_Point[i].nX, g_Point[i].nY, "●");
		}
		this->Print(g_Point[i].nX, g_Point[i].nY + 1, "♨");
	}
	this->Flipping();
}

int Game::GetTime(){
	return this->ttime;
}

void Game::KBHit(){
	switch (_getch()){
	case 49:
		this->g_Mangchi.SetState(1);
		return;
	case 50:
		this->g_Mangchi.SetState(2);
		return;
	case 51:
		this->g_Mangchi.SetState(3);
		return;
	case 52:
		this->g_Mangchi.SetState(4);
		return;
	case 53:
		this->g_Mangchi.SetState(5);
		return;
	case 54:
		this->g_Mangchi.SetState(6);
		return;
	case 55:
		this->g_Mangchi.SetState(7);
		return;
	case 56:
		this->g_Mangchi.SetState(8);
		return;
	case 57:
		this->g_Mangchi.SetState(9);
		return;
	}
	return;
}