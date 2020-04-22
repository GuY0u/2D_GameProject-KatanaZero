#include "stdafx.h"
#include "player.h"

HRESULT player::init()
{
    this->settingImage();       //이미지 초기화(add)


    //플레이어 위치좌표 설정
    _x = 300;
    _y = 300;

    _speed = 10.0f;
    _gravity = 0.0f;


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
    if (INPUT->GetKey(VK_UP))
    {

    }
    if (INPUT->GetKey(VK_DOWN))
    {

    }


	//픽셀충돌 (플레이어 하단부분)
    for (int i = _bottomY - 10; i < _bottomY; i++) //사각형 안의 범주 (_probeY1-50 사각형 위, _probeY1 사각형 아래 만큼의 )
    {
        COLORREF color = GetPixel(getMemDC(), _x, i);
        int r = GetRValue(color);
        int g = GetGValue(color);
        int b = GetBValue(color);



        if (!(r == 255 && g == 0 && b == 255))
        {
            _y += 0.05f;

        }




    }

}

void player::render()
{
    //플레이어 사각형 띄우기
    Rectangle(getMemDC(), _rcPlayer);

    RECT rctemp = RectMakeCenter(_x, _bottomY, 10, 10);
    Rectangle(getMemDC(), rctemp);

}

void player::pixelCollision(image imageName)
{

}

void player::settingImage()
{

}
