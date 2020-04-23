#pragma once
#include "gameNode.h"
#include "player.h"

class inGameScene : public gameNode
{
private:
	player* _player;		//플레이어 클래스

	image* _bgPixel;
    image* _bgImg;


public:
	HRESULT init();
	void release();
	void update();
	void render();


	inGameScene() {}
	~inGameScene() {}
};

