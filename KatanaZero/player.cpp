#include "stdafx.h"
#include "player.h"

HRESULT player::init()
{
    this->settingImage();       //이미지 초기화(add)


    //플레이어 위치좌표 설정
    _x = 400;
    _y = 450;

    _speed = 3.0f;
    _gravity = 0.0f;


    //플레이어 픽셀충돌(아래부분)
    _bottomY = _y + (_rcPlayer.bottom - _rcPlayer.top) / 2;

    _state = PLAYERIDLE;


    return S_OK;
}

void player::release()
{

}

void player::update()
{
    //플레이어 윤곽 사각형 설정(플레이어가 움직이기때문에 업데이트에서)
    _rcPlayer = RectMakeCenter(_x, _y, 56, 95);

    //플레이어 픽셀충돌(아래부분)
    _bottomY = _y + (_rcPlayer.bottom - _rcPlayer.top) / 2;

    if (INPUT->GetKey(VK_LEFT))
    {
        _x -= _speed;
    }
    if (INPUT->GetKey(VK_RIGHT))
    {
        _x += _speed;
    }
    if (INPUT->GetKeyDown(VK_UP))
    {
        //플레이어 x, y좌표를 90도로 점프해야 한다
        _gravity = -1.5;

        _x += cosf(PI / 2) * _speed;
        _y += -sinf(PI / 2) * _speed + _gravity;

    }
    if (INPUT->GetKey(VK_DOWN))
    {

    }


    if (_state == PLAYERIDLE)
    {
        _gravity = 0;
    }
    //else if (_state != PLAYERIDLE)
    //{
    //    _gravity += 0.1;
    //}

	_gravity = 0.1;

}

void player::render()
{
    //플레이어 사각형 띄우기
    Rectangle(getMemDC(), _rcPlayer);

	//플레이어 사각형 보여주기, 픽셀 충돌 사각형
    RECT rctemp = RectMakeCenter(_x, _bottomY, 10, 10);
    Rectangle(getMemDC(), rctemp);
    LineMake(getMemDC(), _x, _y, _x, _bottomY);


	//상태보여주기
	if (_state == PLAYERIDLE)
	{
		textOut(getMemDC(), 10, 80, "대기", RGB(255, 0, 0));
	}
	else if (_state == PLAYERJUMP)
	{
		textOut(getMemDC(), 10, 80, "점프", RGB(255, 0, 0));
	}
	//else if (_state == HOLD)
	//{
	//	textOut(getMemDC(), 10, 80, "홀딩", RGB(255, 0, 0));
	//}
}

void player::pixelCollision(image* imageName)
{
    //픽셀충돌 (플레이어 하단부분)
    for (int i = _bottomY-3; i < _bottomY+1; i++) //사각형 안의 범주 (_probeY1-50 사각형 위, _probeY1 사각형 아래 만큼의 )
    {
        COLORREF color = GetPixel(imageName->getMemDC(), _x, i);
        int r = GetRValue(color);
        int g = GetGValue(color);
        int b = GetBValue(color);


        //바텀부분이 마젠타 색일때
        if ((r == 255 && g == 0 && b == 255))
        {

			_state = PLAYERJUMP;
			_y += _gravity;
            break;

            // 얘는 좀 이상해요
            //_y = i - (_rcPlayer.bottom - _rcPlayer.top) / 2;
        }
        //마젠타 색이 아닐때
        else if (!(r == 255 && g == 0 && b == 255))
        {
			_state = PLAYERIDLE;
			_y = (i - (_rcPlayer.bottom - _rcPlayer.top) / 2);
            break;
        }
    }
}

void player::settingImage()
{
	IMAGEMANAGER->addFrameImage("대기",);

}
