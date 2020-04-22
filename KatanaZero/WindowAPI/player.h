#pragma once
#include "gameNode.h"

enum PlayerMotion
{
    PLAYERIDLE,
    PLAYERWALK,
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

    int _bottomY;               //�ȼ��浹 �Ʒ��κ�




public:
	HRESULT init();
	void release();
	void update();
	void render();


	void pixelCollision(image imageName);			//��� �ȼ��浹

    void settingImage();							//�÷��̾� �̹����� ��Ƶ� ����


	player() {}
	~player() {}
};

