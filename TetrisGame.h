#ifndef TETRIS_GAME_H__
#define TETRIS_GAME_H__
#include "Block.h"
#include <ctime>

class TetrisGame{
private:
	clock_t start;
	clock_t end;

private:
	S_Data block_next;

	Block* block;
	static S_Data map_tetris[CTData::HEIGHT][CTData::WIDTH];

public:
	TetrisGame();
	~TetrisGame();

public:
	bool GameOver(S_Data _position_y);

public:
	void RandomFunc();
	bool Update();
	void LineCleaning(S_Data _line, S_Data _position_y);
};




#endif