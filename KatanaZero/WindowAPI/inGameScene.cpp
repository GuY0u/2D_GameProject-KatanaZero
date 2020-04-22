#include "stdafx.h"
#include "inGameScene.h"

HRESULT inGameScene::init()
{
	//��׶��� �̹��� �ʱ�ȭ
	//IMAGEMANAGER->addImage("��׶���", "Images/background.bmp", WINSIZEX, WINSIZEY);
	//UFO ������ �̹��� �ʱ�ȭ
	//IMAGEMANAGER->addFrameImage("ufo", "Images/ufo.bmp", 530, 32, 10, 1);
	//�Ѿ� �̹���
	//IMAGEMANAGER->addImage("bullet", "Images/bullet.bmp", 21, 21);

	_bgPixel = IMAGEMANAGER->addImage("�ȼ��浹���", "Images/test_bg_apt_pixel.bmp", WINSIZEX, WINSIZEY);


	//�÷��̾� Ŭ���� �ʱ�ȭ
	_player = new player;
	_player->init();



	////��ȣ����
	//_player->setEMLink(_enemyManager);
	//_enemyManager->setPlayerLink(_player);

	return S_OK;
}

void inGameScene::release()
{
	//�÷��̾� Ŭ���� ����
	_player->release();
	SAFE_DELETE(_player);

	////���Ŵ��� Ŭ���� ����
	//_enemyManager->release();
	//SAFE_DELETE(_enemyManager);
}

void inGameScene::update()
{
	//�÷��̾� Ŭ���� ������Ʈ
	_player->update();

	//���Ŵ��� ������Ʈ

	



	if (INPUT->GetKeyDown(VK_RETURN))
	{
		SCENEMANAGER->loadScene("����ȭ��");
	}
}

void inGameScene::render()
{
	////��׶��� ����
	//IMAGEMANAGER->render("��׶���", getMemDC());
	IMAGEMANAGER->render("�ȼ��浹���", getMemDC());

	//�÷��̾� Ŭ���� ����
	_player->render();

	////���Ŵ��� Ŭ���� ����
	//_enemyManager->render();
}
