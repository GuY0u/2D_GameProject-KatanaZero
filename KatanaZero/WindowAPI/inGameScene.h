#pragma once
#include "gameNode.h"
#include "player.h"

class inGameScene : public gameNode
{
private:
	player* _player;		//�÷��̾� Ŭ����

	image* _bgPixel;

public:
	HRESULT init();
	void release();
	void update();
	void render();


	inGameScene() {}
	~inGameScene() {}
};

