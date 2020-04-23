#pragma once
#include "gameNode.h"

enum PlayerMotion
{
    PLAYERIDLE=1,
    PLAYERWALK,
    PLAYERJUMP,
    PLAYERATK,
    PLAYERRUN,
    PLAYERHIT,
};

////상호참조용 클래스 전방선언
//class enemyManager;

class player : public gameNode
{
private:

	RECT _rcPlayer;             //플레이어 충돌사각형
    float _x, _y;               //플레이어 중점
    float _gravity;             //플레이어 중력
    float _speed;               //플레이어 속도
    PlayerMotion _state;        //플레이어 상태

    int _bottomY;               //픽셀충돌 아랫부분




public:
	HRESULT init();
	void release();
	void update();
	void render();

    void pixelCollision(image * imageName);//배경 픽셀충돌


    void settingImage();							//플레이어 이미지를 담아둘 공간

    float getPlayerX() { return _x; }
    void setPlayerX(float x) { _x = x; }

    float getPlayerY() { return _y; }
    void setPlayerY(float y) { _y = y; }


    int getPixelBtmY() { return _bottomY; }
    void setPixelBtmY(int bottomY) { _bottomY = bottomY; }


	player() {}
	~player() {}
};

