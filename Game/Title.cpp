#include "stdafx.h"
#include "Title.h"
#include"Game.h"
#include"Player.h"
#include "GameCamera.h"
#include"BackGround.h"
Title::Title()
{
	//‰æ‘œ‚ð“Ç‚Ýž‚Þ
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
	//‰æ‘œ‚ð•`‰æ
	titleSpriteRender.Draw(rc);
}
