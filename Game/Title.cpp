#include "stdafx.h"
#include "Title.h"
#include"Game.h"
#include"Player.h"
#include "GameCamera.h"
#include"BackGround.h"
Title::Title()
{
	//�摜��ǂݍ���
	titleSpriteRender.Init("Assets/Title/Title.dds", 1920.0f, 1080.0f);
}

Title::~Title()
{

}

void Title::Update()
{
	if (g_pad[0]->IsTrigger(enButtonStart))
	{
		NewGO<Game>(0, "Game");
		DeleteGO(this);
	}
}

void Title::Render(RenderContext& rc)
{
	//�摜��`��
	titleSpriteRender.Draw(rc);
}
