#include "stdafx.h"
#include "GameClear.h"
#include"Title.h"
GameClear::GameClear()
{
	m_spriteRender.Init("Assets/Title/GameClear.dds",  1920.0f, 1080.0f);
}


GameClear::~GameClear()
{
	
}


void GameClear::Update()
{
	if (g_pad[0]->IsTrigger(enButtonA))
	{
		NewGO<Title>(0, "title");
		DeleteGO(this);
	}
}


void GameClear::Render(RenderContext& rc)
{
	//スプライトを描画
	m_spriteRender.Draw(rc);
}