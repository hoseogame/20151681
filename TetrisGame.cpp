#include <iostream>
#include <conio.h>
#include "TetrisGame.h"
#include "SetCursur.h"
#define FALLACTION 32
const clock_t rearrange = 150;

S_Data TetrisGame::map_tetris[CTData::HEIGHT][CTData::WIDTH] = {
	{ 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3 },
	{ 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3 },
	{ 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3 },
	{ 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3 },
	{ 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3 },
	{ 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3 },
	{ 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3 },
	{ 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3 },
	{ 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3 },
	{ 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3 },
	{ 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3 },
	{ 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3 },
	{ 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3 },
	{ 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3 },
	{ 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3 },
	{ 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3 },
	{ 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3 },
	{ 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3 },
	{ 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3 },
	{ 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3 },
	{ 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3 },
};


TetrisGame::TetrisGame(){
	this->start = clock();
	this->block = new Block_1(&this->map_tetris[0][0]);
}

TetrisGame::~TetrisGame(){
	delete this->block;
}

bool TetrisGame::GameOver(S_Data _position_y){
	if (1==_position_y){
		system("cls");
		std::cout << "게임오버" << std::endl;
		return true;
	}
	return false;
}

void TetrisGame::RandomFunc(){
	this->block_next = rand() % 7;
	if (0 == block_next){
		this->block = new Block_1(&this->map_tetris[0][0]);
	}
	else if (1 == block_next){
		this->block = new Block_2(&this->map_tetris[0][0]);
	}
	else if (2 == block_next){
		this->block = new Block_3(&this->map_tetris[0][0]);
	}
	else if (3 == block_next){
		this->block = new Block_4(&this->map_tetris[0][0]);
	}
	else if (4 == block_next){
		this->block = new Block_5(&this->map_tetris[0][0]);
	}
	else if (5 == block_next){
		this->block = new Block_6(&this->map_tetris[0][0]);
	}
	else{
		this->block = new Block_7(&this->map_tetris[0][0]);
	}
}

bool TetrisGame::Update(){
	this->end = clock();
	if (rearrange < (this->end) - (this->start)){
		this->start = clock();
		if (_kbhit()){
			this->block->ShowRemove(this->block->GetPosition());
			int key_code = getch();
			if (224 == key_code){
				key_code = getch();
			}
			this->block->KeyBoredHit(key_code);
			this->block->Show(this->block->GetPosition());
			if (FALLACTION == key_code){
				this->block->End();
				if (this->GameOver(this->block->GetPosition().GetPositionY()))
					return false;
				this->LineCleaning(this->block->line, this->block->GetPosition().GetPositionY());
				delete block;
				this->RandomFunc();
			}
		}

		this->block->ShowRemove(this->block->GetPosition());
		this->block->Gravity(1);
		if (this->block->SmashCheck()){
			this->block->Gravity(-1);
			this->block->Show(this->block->GetPosition());
			this->block->End();
			if (this->GameOver(this->block->GetPosition().GetPositionY()))
				return false;
			this->LineCleaning(this->block->line, this->block->GetPosition().GetPositionY());
			delete block;
			this->RandomFunc();
			return true;
		}
		this->block->Show(this->block->GetPosition());
	}
	return true;
}

void TetrisGame::LineCleaning(S_Data _line, S_Data _position_y){
	S_Data sum = 0;
	S_Data count = 0;
	S_Data position_y = _position_y;
	for (S_Data line = _line - 1; 0 <= line; --line){
		for (S_Data row = 1; CTData::WIDTH-1 > row; ++row){
			sum += this->map_tetris[position_y + line][row];
		}
		if (CTData::WIDTH - 2 <= sum){
			++count;
			++position_y;
			for (S_Data loop = 0; line > loop; ++loop){
				for (S_Data row = 1; CTData::WIDTH - 1 > row; ++row){
					this->map_tetris[_position_y + line - loop][row] = this->map_tetris[_position_y + line - 1 - loop][row];
				}
			}
		}
		sum = 0;
	}

	if (count){
		for (S_Data line = _position_y - 1; 1 < line; --line){
			for (S_Data row = 1; CTData::WIDTH - 1 > row; ++row){
				this->map_tetris[line + count][row] = this->map_tetris[line][row];
			}
		}
		for (count; 0 < count; --count){
			for (S_Data row = 1; CTData::WIDTH - 1 > row; ++row){
				this->map_tetris[count][row] = this->map_tetris[1][row];
			}
		}

		for (S_Data line = _position_y + _line - 1; 1 < line; --line){
			for (S_Data row = 1; CTData::WIDTH - 1 > row; ++row){
				SetCursurPosition(row*2, line);
				if (this->map_tetris[line][row])
					std::cout << "▣";
				else
					std::cout << "  ";
			}
		}
	}
}