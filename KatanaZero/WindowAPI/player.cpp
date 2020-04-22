#include "stdafx.h"
#include "player.h"

HRESULT player::init()
{
    this->settingImage();       //�̹��� �ʱ�ȭ(add)


    //�÷��̾� ��ġ��ǥ ����
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
    //�÷��̾� ���� �簢�� ����(�÷��̾ �����̱⶧���� ������Ʈ����)
    _rcPlayer = RectMakeCenter(_x, _y, 56, 95);

    //�÷��̾� �ȼ��浹(�Ʒ��κ�)
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


	//�ȼ��浹 (�÷��̾� �ϴܺκ�)
    for (int i = _bottomY - 10; i < _bottomY; i++) //�簢�� ���� ���� (_probeY1-50 �簢�� ��, _probeY1 �簢�� �Ʒ� ��ŭ�� )
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
    //�÷��̾� �簢�� ����
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
