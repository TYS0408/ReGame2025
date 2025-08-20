#include "stdafx.h"
#include "GameOver.h"
#include"Player.h"
#include"Game.h"
#include"Title.h"

GameOver::GameOver()
{
	//ゲームオーバーの画像を読み込む
	m_overspriteRender.Init("Assets/Title/GameOver2.dds",1920.0f,1080.0f);
}

GameOver::~GameOver()
{

}

void GameOver::Update()
{
	if (g_pad[0]->IsTrigger(enButtonA))
	{
		NewGO<Title>(0, "title");
		DeleteGO(this);
	}
}

void GameOver::Render(RenderContext& rc)
{
		//スプライトを描画
	m_overspriteRender.Draw(rc);
}