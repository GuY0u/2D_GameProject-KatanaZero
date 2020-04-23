#include "stdafx.h"
#include "player.h"

HRESULT player::init()
{
    this->settingImage();       //�̹��� �ʱ�ȭ(add)


    //�÷��̾� ��ġ��ǥ ����
    _x = 400;
    _y = 450;

    _speed = 3.0f;
    _gravity = 0.0f;


    //�÷��̾� �ȼ��浹(�Ʒ��κ�)
    _bottomY = _y + (_rcPlayer.bottom - _rcPlayer.top) / 2;

    _state = PLAYERIDLE;


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
    if (INPUT->GetKeyDown(VK_UP))
    {
        //�÷��̾� x, y��ǥ�� 90���� �����ؾ� �Ѵ�
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
    //�÷��̾� �簢�� ����
    Rectangle(getMemDC(), _rcPlayer);

	//�÷��̾� �簢�� �����ֱ�, �ȼ� �浹 �簢��
    RECT rctemp = RectMakeCenter(_x, _bottomY, 10, 10);
    Rectangle(getMemDC(), rctemp);
    LineMake(getMemDC(), _x, _y, _x, _bottomY);


	//���º����ֱ�
	if (_state == PLAYERIDLE)
	{
		textOut(getMemDC(), 10, 80, "���", RGB(255, 0, 0));
	}
	else if (_state == PLAYERJUMP)
	{
		textOut(getMemDC(), 10, 80, "����", RGB(255, 0, 0));
	}
	//else if (_state == HOLD)
	//{
	//	textOut(getMemDC(), 10, 80, "Ȧ��", RGB(255, 0, 0));
	//}
}

void player::pixelCollision(image* imageName)
{
    //�ȼ��浹 (�÷��̾� �ϴܺκ�)
    for (int i = _bottomY-3; i < _bottomY+1; i++) //�簢�� ���� ���� (_probeY1-50 �簢�� ��, _probeY1 �簢�� �Ʒ� ��ŭ�� )
    {
        COLORREF color = GetPixel(imageName->getMemDC(), _x, i);
        int r = GetRValue(color);
        int g = GetGValue(color);
        int b = GetBValue(color);


        //���Һκ��� ����Ÿ ���϶�
        if ((r == 255 && g == 0 && b == 255))
        {

			_state = PLAYERJUMP;
			_y += _gravity;
            break;

            // ��� �� �̻��ؿ�
            //_y = i - (_rcPlayer.bottom - _rcPlayer.top) / 2;
        }
        //����Ÿ ���� �ƴҶ�
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
	IMAGEMANAGER->addFrameImage("���",);

}
