#include <iostream>
#include "SetCursur.h"
#include "Block.h"


#define SMASH_RANGE 2
enum{
	SPACE	 = 32, 
	UP	 	 = 72,
	LEFT	 = 75,
	RIGHT	 = 77,
	DOWN	 = 80
};

S_Data Block_1::block[CBData_1::STATE][CBData_1::HEIGHT][CBData_1::WIDTH] = {
	{
		{ 0, 0, 0 },
		{ 1, 0, 0 },
		{ 1, 1, 1 }
	},
	{
		{ 1, 1, 0 },
		{ 1, 0, 0 },
		{ 1, 0, 0 }
	},
	{
		{ 0, 0, 0 },
		{ 1, 1, 1 },
		{ 0, 0, 1 }
	},
	{
		{ 0, 0, 1 },
		{ 0, 0, 1 },
		{ 0, 1, 1 }
	}
};

S_Data Block_2::block[CBData_2::STATE][CBData_2::HEIGHT][CBData_2::WIDTH] = {
	{
		{ 0, 0, 0 },
		{ 0, 0, 1 },
		{ 1, 1, 1 }
	},
	{
		{ 0, 1, 1 },
		{ 0, 0, 1 },
		{ 0, 0, 1 }
	},
	{
		{ 0, 0, 0 },
		{ 1, 1, 1 },
		{ 1, 0, 0 }
	},
	{
		{ 1, 0, 0 },
		{ 1, 0, 0 },
		{ 1, 1, 0 }
	}
};

S_Data Block_3::block[CBData_3::STATE][CBData_3::HEIGHT][CBData_3::WIDTH] = {
	{
		{ 0, 0, 0 },
		{ 1, 1, 0 },
		{ 0, 1, 1 }
	},
	{
		{ 0, 0, 1 },
		{ 0, 1, 1 },
		{ 0, 1, 0 }
	}
};

S_Data Block_4::block[CBData_4::STATE][CBData_4::HEIGHT][CBData_4::WIDTH] = {
	{
		{ 0, 0, 0 },
		{ 0, 1, 1 },
		{ 1, 1, 0 }
	},
	{
		{ 1, 0, 0 },
		{ 1, 1, 0 },
		{ 0, 1, 0 }
	}
};

S_Data Block_5::block[CBData_1::STATE][CBData_1::HEIGHT][CBData_1::WIDTH] = {
	{
		{ 0, 0, 0 },
		{ 0, 1, 0 },
		{ 1, 1, 1 }
	},
	{
		{ 0, 1, 0 },
		{ 0, 1, 1 },
		{ 0, 1, 0 }
	},
	{
		{ 0, 0, 0 },
		{ 1, 1, 1 },
		{ 0, 1, 0 }
	},
	{
		{ 0, 1, 0 },
		{ 1, 1, 0 },
		{ 0, 1, 0 }
	}
};

S_Data Block_6::block[CBData_6::STATE][CBData_6::HEIGHT][CBData_6::WIDTH] = {
	{
		{ 1, 1},
		{ 1, 1},
	}
};

S_Data Block_7::block[CBData_7::STATE][CBData_7::HEIGHT][CBData_7::WIDTH] = {
	{
		{ 0, 0, 1, 0 },
		{ 0, 0, 1, 0 },
		{ 0, 0, 1, 0 },
		{ 0, 0, 1, 0 }
	},
	{
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 },
		{ 1, 1, 1, 1 }
	}
};

void Block::KeyBoredHit(int _key_code){
	switch (_key_code){
	case SPACE:
		this->FallAction();
		break;
	case UP:
	{
			   S_Data state = this->state_pointer;
			   this->Rotate();
			   if (this->SmashCheck())
				   this->state_pointer = state;
	}
		break;
	case LEFT:
		pos.SetPositionX(pos.GetPositionX() - 1);
		if (this->SmashCheck())
			this->pos.SetPositionX(pos.GetPositionX() + 1);
	
		break;
	case RIGHT:
		pos.SetPositionX(pos.GetPositionX() + 1);
		if (this->SmashCheck())
			this->pos.SetPositionX(pos.GetPositionX() - 1);
		break;
	case DOWN:
	{
				 S_Data value_y = this->pos.GetPositionY();
				 Gravity(1);
				 if (this->SmashCheck())
					 this->pos.SetPositionY(value_y);
	}
	}
}

Position Block::GetPosition(){
	return this->pos;
}

void Block::SetPosition(Position _pos){
	this->pos = _pos;
}

void Block::Gravity(S_Data _range){
	this->pos.SetPositionY(this->pos.GetPositionY() + _range);
}

void Block::FallAction(){
	while (!this->SmashCheck())
		this->Gravity(1);
	this->Gravity(-1);
}


Block_1::Block_1(S_Data* _map_pointer){
	this->position_pointer = _map_pointer;
	this->pos.SetPosition(6, 1);
	this->state_pointer = 0;
	this->line = CBData_1::HEIGHT;
}

void Block_1::End(){
	for (S_Data y = 0; CBData_1::HEIGHT > y; ++y){
		for (S_Data x = 0; CBData_1::WIDTH > x; ++x){
			if (this->block[this->state_pointer][y][x]){
				this->position_pointer[
					(this->pos.GetPositionY() + y)*CTData::WIDTH
						+ (this->pos.GetPositionX() + x)
				] = this->block[this->state_pointer][y][x];
			}
		}
	}
}

bool Block_1::SmashCheck(){
	for (S_Data y = 0; CBData_1::HEIGHT > y; ++y)
	{
		for (S_Data x = 0; CBData_1::WIDTH > x; ++x)
		{
			if (0!=this->block[this->state_pointer][y][x] &
				this->position_pointer
				[
					(this->pos.GetPositionY() + y)*CTData::WIDTH + 
					(this->pos.GetPositionX() + x)
				]
			)
				return true;
		}
	}
	return false;
}

void Block_1::Rotate(){
	++(this->state_pointer);
	if (CBData_1::STATE <= this->state_pointer)
		this->state_pointer = 0;
}

void Block_1::Show(Position _pos){
	using namespace std;
	for (S_Data y = 0; CBData_1::HEIGHT > y; ++y){
		for (S_Data x = 0; CBData_1::WIDTH > x; ++x){
			if (this->block[this->state_pointer][y][x]){
				SetCursurPosition((_pos.GetPositionX() + x) * 2, _pos.GetPositionY() + y);
				cout << "¢Ã";
			}
		}
	}
}

void Block_1::ShowRemove(Position _pos){
	using namespace std;
	for (S_Data y = 0; CBData_1::HEIGHT > y; ++y){
		for (S_Data x = 0; CBData_1::WIDTH > x; ++x){
			if (this->block[this->state_pointer][y][x]){
				SetCursurPosition((_pos.GetPositionX() + x) * 2, _pos.GetPositionY() + y);
				cout << "  ";
			}
		}
	}
}


Block_2::Block_2(S_Data* _map_pointer){
	this->position_pointer = _map_pointer;
	this->pos.SetPosition(6, 1);
	this->state_pointer = 0;
	this->line = CBData_2::HEIGHT;
}

void Block_2::End(){
	for (S_Data y = 0; CBData_2::HEIGHT > y; ++y){
		for (S_Data x = 0; CBData_2::WIDTH > x; ++x){
			if (this->block[this->state_pointer][y][x]){
				this->position_pointer[
					(this->pos.GetPositionY() + y)*CTData::WIDTH
						+ (this->pos.GetPositionX() + x)
				] = this->block[this->state_pointer][y][x];
			}
		}
	}
}

bool Block_2::SmashCheck(){
	for (S_Data y = 0; CBData_2::HEIGHT > y; ++y)
	{
		for (S_Data x = 0; CBData_2::WIDTH > x; ++x)
		{
			if (0 != this->block[this->state_pointer][y][x] &
				this->position_pointer
				[
					(this->pos.GetPositionY() + y)*CTData::WIDTH +
					(this->pos.GetPositionX() + x)
				]
			)
				return true;
		}
	}
	return false;
}

void Block_2::Rotate(){
	++(this->state_pointer);
	if (CBData_2::STATE <= this->state_pointer)
		this->state_pointer = 0;
}

void Block_2::Show(Position _pos){
	using namespace std;
	for (S_Data y = 0; CBData_2::HEIGHT > y; ++y){
		for (S_Data x = 0; CBData_2::WIDTH > x; ++x){
			if (this->block[this->state_pointer][y][x]){
				SetCursurPosition((_pos.GetPositionX() + x) * 2, _pos.GetPositionY() + y);
				cout << "¢Ã";
			}
		}
	}
}

void Block_2::ShowRemove(Position _pos){
	using namespace std;
	for (S_Data y = 0; CBData_2::HEIGHT > y; ++y){
		for (S_Data x = 0; CBData_2::WIDTH > x; ++x){
			if (this->block[this->state_pointer][y][x]){
				SetCursurPosition((_pos.GetPositionX() + x) * 2, _pos.GetPositionY() + y);
				cout << "  ";
			}
		}
	}
}

Block_3::Block_3(S_Data* _map_pointer){
	this->position_pointer = _map_pointer;
	this->pos.SetPosition(6, 1);
	this->state_pointer = 0;
	this->line = CBData_3::HEIGHT;
}

void Block_3::End(){
	for (S_Data y = 0; CBData_3::HEIGHT > y; ++y){
		for (S_Data x = 0; CBData_3::WIDTH > x; ++x){
			if (this->block[this->state_pointer][y][x]){
				this->position_pointer[
					(this->pos.GetPositionY() + y)*CTData::WIDTH
						+ (this->pos.GetPositionX() + x)
				] = this->block[this->state_pointer][y][x];
			}
		}
	}
}

bool Block_3::SmashCheck(){
	for (S_Data y = 0; CBData_3::HEIGHT > y; ++y)
	{
		for (S_Data x = 0; CBData_3::WIDTH > x; ++x)
		{
			if (0 != this->block[this->state_pointer][y][x] &
				this->position_pointer
				[
					(this->pos.GetPositionY() + y)*CTData::WIDTH +
					(this->pos.GetPositionX() + x)
				]
			)
				return true;
		}
	}
	return false;
}

void Block_3::Rotate(){
	++(this->state_pointer);
	if (CBData_3::STATE <= this->state_pointer)
		this->state_pointer = 0;
}

void Block_3::Show(Position _pos){
	using namespace std;
	for (S_Data y = 0; CBData_3::HEIGHT > y; ++y){
		for (S_Data x = 0; CBData_3::WIDTH > x; ++x){
			if (this->block[this->state_pointer][y][x]){
				SetCursurPosition((_pos.GetPositionX() + x) * 2, _pos.GetPositionY() + y);
				cout << "¢Ã";
			}
		}
	}
}

void Block_3::ShowRemove(Position _pos){
	using namespace std;
	for (S_Data y = 0; CBData_3::HEIGHT > y; ++y){
		for (S_Data x = 0; CBData_3::WIDTH > x; ++x){
			if (this->block[this->state_pointer][y][x]){
				SetCursurPosition((_pos.GetPositionX() + x) * 2, _pos.GetPositionY() + y);
				cout << "  ";
			}
		}
	}
}

Block_4::Block_4(S_Data* _map_pointer){
	this->position_pointer = _map_pointer;
	this->pos.SetPosition(6, 1);
	this->state_pointer = 0;
	this->line = CBData_4::HEIGHT;
}

void Block_4::End(){
	for (S_Data y = 0; CBData_4::HEIGHT > y; ++y){
		for (S_Data x = 0; CBData_4::WIDTH > x; ++x){
			if (this->block[this->state_pointer][y][x]){
				this->position_pointer[
					(this->pos.GetPositionY() + y)*CTData::WIDTH
						+ (this->pos.GetPositionX() + x)
				] = this->block[this->state_pointer][y][x];
			}
		}
	}
}

bool Block_4::SmashCheck(){
	for (S_Data y = 0; CBData_4::HEIGHT > y; ++y)
	{
		for (S_Data x = 0; CBData_4::WIDTH > x; ++x)
		{
			if (0 != this->block[this->state_pointer][y][x] &
				this->position_pointer
				[
					(this->pos.GetPositionY() + y)*CTData::WIDTH +
					(this->pos.GetPositionX() + x)
				]
			)
				return true;
		}
	}
	return false;
}

void Block_4::Rotate(){
	++(this->state_pointer);
	if (CBData_4::STATE <= this->state_pointer)
		this->state_pointer = 0;
}

void Block_4::Show(Position _pos){
	using namespace std;
	for (S_Data y = 0; CBData_4::HEIGHT > y; ++y){
		for (S_Data x = 0; CBData_4::WIDTH > x; ++x){
			if (this->block[this->state_pointer][y][x]){
				SetCursurPosition((_pos.GetPositionX() + x) * 2, _pos.GetPositionY() + y);
				cout << "¢Ã";
			}
		}
	}
}

void Block_4::ShowRemove(Position _pos){
	using namespace std;
	for (S_Data y = 0; CBData_4::HEIGHT > y; ++y){
		for (S_Data x = 0; CBData_4::WIDTH > x; ++x){
			if (this->block[this->state_pointer][y][x]){
				SetCursurPosition((_pos.GetPositionX() + x) * 2, _pos.GetPositionY() + y);
				cout << "  ";
			}
		}
	}
}

Block_5::Block_5(S_Data* _map_pointer){
	this->position_pointer = _map_pointer;
	this->pos.SetPosition(6, 1);
	this->state_pointer = 0;
	this->line = CBData_5::HEIGHT;
}

void Block_5::End(){
	for (S_Data y = 0; CBData_5::HEIGHT > y; ++y){
		for (S_Data x = 0; CBData_5::WIDTH > x; ++x){
			if (this->block[this->state_pointer][y][x]){
				this->position_pointer[
					(this->pos.GetPositionY() + y)*CTData::WIDTH
						+ (this->pos.GetPositionX() + x)
				] = this->block[this->state_pointer][y][x];
			}
		}
	}
}

bool Block_5::SmashCheck(){
	for (S_Data y = 0; CBData_5::HEIGHT > y; ++y)
	{
		for (S_Data x = 0; CBData_5::WIDTH > x; ++x)
		{
			if (0 != this->block[this->state_pointer][y][x] &
				this->position_pointer
				[
					(this->pos.GetPositionY() + y)*CTData::WIDTH +
					(this->pos.GetPositionX() + x)
				]
			)
				return true;
		}
	}
	return false;
}

void Block_5::Rotate(){
	++(this->state_pointer);
	if (CBData_5::STATE <= this->state_pointer)
		this->state_pointer = 0;
}

void Block_5::Show(Position _pos){
	using namespace std;
	for (S_Data y = 0; CBData_5::HEIGHT > y; ++y){
		for (S_Data x = 0; CBData_5::WIDTH > x; ++x){
			if (this->block[this->state_pointer][y][x]){
				SetCursurPosition((_pos.GetPositionX() + x) * 2, _pos.GetPositionY() + y);
				cout << "¢Ã";
			}
		}
	}
}

void Block_5::ShowRemove(Position _pos){
	using namespace std;
	for (S_Data y = 0; CBData_5::HEIGHT > y; ++y){
		for (S_Data x = 0; CBData_5::WIDTH > x; ++x){
			if (this->block[this->state_pointer][y][x]){
				SetCursurPosition((_pos.GetPositionX() + x) * 2, _pos.GetPositionY() + y);
				cout << "  ";
			}
		}
	}
}

Block_6::Block_6(S_Data* _map_pointer){
	this->position_pointer = _map_pointer;
	this->pos.SetPosition(6, 1);
	this->state_pointer = 0;
	this->line = CBData_6::HEIGHT;
}

void Block_6::End(){
	for (S_Data y = 0; CBData_6::HEIGHT > y; ++y){
		for (S_Data x = 0; CBData_6::WIDTH > x; ++x){
			if (this->block[this->state_pointer][y][x]){
				this->position_pointer[
					(this->pos.GetPositionY() + y)*CTData::WIDTH
						+ (this->pos.GetPositionX() + x)
				] = this->block[this->state_pointer][y][x];
			}
		}
	}
}

bool Block_6::SmashCheck(){
	for (S_Data y = 0; CBData_6::HEIGHT > y; ++y)
	{
		for (S_Data x = 0; CBData_6::WIDTH > x; ++x)
		{
			if (0 != this->block[this->state_pointer][y][x] &
				this->position_pointer
				[
					(this->pos.GetPositionY() + y)*CTData::WIDTH +
					(this->pos.GetPositionX() + x)
				]
			)
				return true;
		}
	}
	return false;
}

void Block_6::Rotate(){
	++(this->state_pointer);
	if (CBData_6::STATE <= this->state_pointer)
		this->state_pointer = 0;
}

void Block_6::Show(Position _pos){
	using namespace std;
	for (S_Data y = 0; CBData_6::HEIGHT > y; ++y){
		for (S_Data x = 0; CBData_6::WIDTH > x; ++x){
			if (this->block[this->state_pointer][y][x]){
				SetCursurPosition((_pos.GetPositionX() + x) * 2, _pos.GetPositionY() + y);
				cout << "¢Ã";
			}
		}
	}
}

void Block_6::ShowRemove(Position _pos){
	using namespace std;
	for (S_Data y = 0; CBData_6::HEIGHT > y; ++y){
		for (S_Data x = 0; CBData_6::WIDTH > x; ++x){
			if (this->block[this->state_pointer][y][x]){
				SetCursurPosition((_pos.GetPositionX() + x) * 2, _pos.GetPositionY() + y);
				cout << "  ";
			}
		}
	}
}

Block_7::Block_7(S_Data* _map_pointer){
	this->position_pointer = _map_pointer;
	this->pos.SetPosition(6, 1);
	this->state_pointer = 0;
	this->line = CBData_7::HEIGHT;
}

void Block_7::End(){
	for (S_Data y = 0; CBData_7::HEIGHT > y; ++y){
		for (S_Data x = 0; CBData_7::WIDTH > x; ++x){
			if (this->block[this->state_pointer][y][x]){
				this->position_pointer[
					(this->pos.GetPositionY() + y)*CTData::WIDTH
						+ (this->pos.GetPositionX() + x)
				] = this->block[this->state_pointer][y][x];
			}
		}
	}
}

bool Block_7::SmashCheck(){
	for (S_Data y = 0; CBData_7::HEIGHT > y; ++y)
	{
		for (S_Data x = 0; CBData_7::WIDTH > x; ++x)
		{
			if (0 != this->block[this->state_pointer][y][x] &
				this->position_pointer
				[
					(this->pos.GetPositionY() + y)*CTData::WIDTH +
					(this->pos.GetPositionX() + x)
				]
			)
				return true;
		}
	}
	return false;
}

void Block_7::Rotate(){
	++(this->state_pointer);
	if (CBData_7::STATE <= this->state_pointer)
		this->state_pointer = 0;
}

void Block_7::Show(Position _pos){
	using namespace std;
	for (S_Data y = 0; CBData_7::HEIGHT > y; ++y){
		for (S_Data x = 0; CBData_7::WIDTH > x; ++x){
			if (this->block[this->state_pointer][y][x]){
				SetCursurPosition((_pos.GetPositionX() + x) * 2, _pos.GetPositionY() + y);
				cout << "¢Ã";
			}
		}
	}
}

void Block_7::ShowRemove(Position _pos){
	using namespace std;
	for (S_Data y = 0; CBData_7::HEIGHT > y; ++y){
		for (S_Data x = 0; CBData_7::WIDTH > x; ++x){
			if (this->block[this->state_pointer][y][x]){
				SetCursurPosition((_pos.GetPositionX() + x) * 2, _pos.GetPositionY() + y);
				cout << "  ";
			}
		}
	}
}




















