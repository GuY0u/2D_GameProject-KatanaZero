#include "stdafx.h"
#include "inGameScene.h"

HRESULT inGameScene::init()
{
	//백그라운드 이미지 초기화
	//IMAGEMANAGER->addImage("백그라운드", "Images/background.bmp", WINSIZEX, WINSIZEY);
	//UFO 프레임 이미지 초기화
	//IMAGEMANAGER->addFrameImage("ufo", "Images/ufo.bmp", 530, 32, 10, 1);
	//총알 이미지
	//IMAGEMANAGER->addImage("bullet", "Images/bullet.bmp", 21, 21);

	_bgPixel = IMAGEMANAGER->addImage("픽셀충돌배경", "Images/test_bg_apt_pixel.bmp", WINSIZEX, WINSIZEY);


	//플레이어 클래스 초기화
	_player = new player;
	_player->init();



	////상호참조
	//_player->setEMLink(_enemyManager);
	//_enemyManager->setPlayerLink(_player);

	return S_OK;
}

void inGameScene::release()
{
	//플레이어 클래스 해제
	_player->release();
	SAFE_DELETE(_player);

	////적매니져 클래스 해제
	//_enemyManager->release();
	//SAFE_DELETE(_enemyManager);
}

void inGameScene::update()
{
	//플레이어 클래스 업데이트
	_player->update();

	//적매니져 업데이트

	



	if (INPUT->GetKeyDown(VK_RETURN))
	{
		SCENEMANAGER->loadScene("시작화면");
	}
}

void inGameScene::render()
{
	////백그라운드 렌더
	//IMAGEMANAGER->render("백그라운드", getMemDC());
	IMAGEMANAGER->render("픽셀충돌배경", getMemDC());

	//플레이어 클래스 렌더
	_player->render();

	////적매니져 클래스 렌더
	//_enemyManager->render();
}
