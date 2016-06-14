#ifndef BLOCK_H__
#define BLOCK_H__


typedef char S_Data;

//const Tetris data 공간
namespace CTData{
	//WIDTH(12)
	const S_Data WIDTH = 12;
	//HEIGHT(21)
	const S_Data HEIGHT = 21;
}


//const block data 공간
namespace CBData_1{
	//WIDTH(3)
	const S_Data WIDTH = 3;
	//HEIGHT(3)
	const S_Data HEIGHT = 3;
	//STATE(4)
	const S_Data STATE = 4;
}

//const block data 공간
namespace CBData_2{
	//WIDTH(3)
	const S_Data WIDTH = 3;
	//HEIGHT(3)
	const S_Data HEIGHT = 3;
	//STATE(4)
	const S_Data STATE = 4;
}

//const block data 공간
namespace CBData_3{
	//WIDTH(3)
	const S_Data WIDTH = 3;
	//HEIGHT(3)
	const S_Data HEIGHT = 3;
	//STATE(4)
	const S_Data STATE = 2;
}

//const block data 공간
namespace CBData_4{
	//WIDTH(3)
	const S_Data WIDTH = 3;
	//HEIGHT(3)
	const S_Data HEIGHT = 3;
	//STATE(4)
	const S_Data STATE = 2;
}

//const block data 공간
namespace CBData_5{
	//WIDTH(3)
	const S_Data WIDTH = 3;
	//HEIGHT(3)
	const S_Data HEIGHT = 3;
	//STATE(4)
	const S_Data STATE = 4;
}

//const block data 공간
namespace CBData_6{
	//WIDTH(3)
	const S_Data WIDTH = 2;
	//HEIGHT(3)
	const S_Data HEIGHT = 2;
	//STATE(4)
	const S_Data STATE = 1;
}

//const block data 공간
namespace CBData_7{
	//WIDTH(3)
	const S_Data WIDTH = 4;
	//HEIGHT(3)
	const S_Data HEIGHT = 4;
	//STATE(4)
	const S_Data STATE = 2;
}

class Position{
private:
	S_Data width_index;
	S_Data height_index;

public:
	Position(){ this->width_index = 0; this->height_index = 0; }
	Position(S_Data _xhs, S_Data _yhs){ this->width_index = _xhs; this->height_index = _yhs; }
	Position(Position& _pos){ this->width_index = _pos.width_index; this->height_index = _pos.height_index; }
	S_Data GetPositionX(){ return this->width_index; }
	S_Data GetPositionY(){ return this->height_index; }
	void SetPosition(S_Data _xhs, S_Data _yhs){ this->width_index = _xhs; this->height_index = _yhs; }
	void SetPositionX(S_Data _xhs){ this->width_index = _xhs; }
	void SetPositionY(S_Data _yhs){ this->height_index = _yhs; }
};

class Block{
protected:
	S_Data state_pointer;
	S_Data* position_pointer;
	Position pos;

public:
	virtual ~Block(){};

public:
	S_Data line;

public:
	virtual void KeyBoredHit(int _key_code);
	virtual Position GetPosition();
	virtual void SetPosition(Position _pos);
	virtual void Gravity(S_Data _range);
	virtual void FallAction();

public:
	//충돌하면 true, 아니면 false
	virtual bool SmashCheck() = 0;
	virtual void Rotate() = 0;
	virtual void Show(Position _pos) = 0;
	virtual void ShowRemove(Position _pos) = 0;
	virtual void End() = 0;
};

//└
class Block_1 :public Block{
private:
	//block[블럭의 모양][충동체크 height(y) 범위][충돌체크 width(x) 범위]
	static S_Data block[CBData_1::STATE][CBData_1::HEIGHT][CBData_1::WIDTH];

public:
	Block_1(S_Data* _map_pointer);
	virtual ~Block_1(){}

public:
	virtual bool SmashCheck() override;
	virtual void Rotate() override;
	virtual void Show(Position _pos) override;
	virtual void ShowRemove(Position _pos) override;
	virtual void End() override;
};

//┘
class Block_2 :public Block{
private:
	//block[블럭의 모양][충동체크 height(y) 범위][충돌체크 width(x) 범위]
	static S_Data block[CBData_2::STATE][CBData_2::HEIGHT][CBData_2::WIDTH];

public:
	Block_2(S_Data* _map_pointer);
	virtual ~Block_2(){}

public:
	virtual bool SmashCheck() override;
	virtual void Rotate() override;
	virtual void Show(Position _pos) override;
	virtual void ShowRemove(Position _pos) override;
	virtual void End() override;
};

//z
class Block_3 :public Block{
private:
	//block[블럭의 모양][충동체크 height(y) 범위][충돌체크 width(x) 범위]
	static S_Data block[CBData_3::STATE][CBData_3::HEIGHT][CBData_3::WIDTH];

public:
	Block_3(S_Data* _map_pointer);
	virtual ~Block_3(){}

public:
	virtual bool SmashCheck() override;
	virtual void Rotate() override;
	virtual void Show(Position _pos) override;
	virtual void ShowRemove(Position _pos) override;
	virtual void End() override;
};

//s
class Block_4 :public Block{
private:
	//block[블럭의 모양][충동체크 height(y) 범위][충돌체크 width(x) 범위]
	static S_Data block[CBData_4::STATE][CBData_4::HEIGHT][CBData_4::WIDTH];

public:
	Block_4(S_Data* _map_pointer);
	virtual ~Block_4(){}

public:
	virtual bool SmashCheck() override;
	virtual void Rotate() override;
	virtual void Show(Position _pos) override;
	virtual void ShowRemove(Position _pos) override;
	virtual void End() override;
};

//ㅗ
class Block_5 :public Block{
private:
	//block[블럭의 모양][충동체크 height(y) 범위][충돌체크 width(x) 범위]
	static S_Data block[CBData_5::STATE][CBData_5::HEIGHT][CBData_5::WIDTH];

public:
	Block_5(S_Data* _map_pointer);
	virtual ~Block_5(){}

public:
	virtual bool SmashCheck() override;
	virtual void Rotate() override;
	virtual void Show(Position _pos) override;
	virtual void ShowRemove(Position _pos) override;
	virtual void End() override;
};

//ㅁ
class Block_6 :public Block{
private:
	//block[블럭의 모양][충동체크 height(y) 범위][충돌체크 width(x) 범위]
	static S_Data block[CBData_6::STATE][CBData_6::HEIGHT][CBData_6::WIDTH];

public:
	Block_6(S_Data* _map_pointer);
	virtual ~Block_6(){}

public:
	virtual bool SmashCheck() override;
	virtual void Rotate() override;
	virtual void Show(Position _pos) override;
	virtual void ShowRemove(Position _pos) override;
	virtual void End() override;
};

//ㅡ
class Block_7 :public Block{
private:
	//block[블럭의 모양][충동체크 height(y) 범위][충돌체크 width(x) 범위]
	static S_Data block[CBData_7::STATE][CBData_7::HEIGHT][CBData_7::WIDTH];

public:
	Block_7(S_Data* _map_pointer);
	virtual ~Block_7(){}

public:
	virtual bool SmashCheck() override;
	virtual void Rotate() override;
	virtual void Show(Position _pos) override;
	virtual void ShowRemove(Position _pos) override;
	virtual void End() override;
};



#endif