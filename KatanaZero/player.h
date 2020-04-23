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

////��ȣ������ Ŭ���� ���漱��
//class enemyManager;

class player : public gameNode
{
private:

	RECT _rcPlayer;             //�÷��̾� �浹�簢��
    float _x, _y;               //�÷��̾� ����
    float _gravity;             //�÷��̾� �߷�
    float _speed;               //�÷��̾� �ӵ�
    PlayerMotion _state;        //�÷��̾� ����

    int _bottomY;               //�ȼ��浹 �Ʒ��κ�




public:
	HRESULT init();
	void release();
	void update();
	void render();

    void pixelCollision(image * imageName);//��� �ȼ��浹


    void settingImage();							//�÷��̾� �̹����� ��Ƶ� ����

    float getPlayerX() { return _x; }
    void setPlayerX(float x) { _x = x; }

    float getPlayerY() { return _y; }
    void setPlayerY(float y) { _y = y; }


    int getPixelBtmY() { return _bottomY; }
    void setPixelBtmY(int bottomY) { _bottomY = bottomY; }


	player() {}
	~player() {}
};

