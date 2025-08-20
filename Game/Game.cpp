#include "stdafx.h"
#include "Game.h"
#include "Player.h"
#include"BackGround.h"
#include"GameCamera.h"
#include "Item.h"
#include"GameClear.h"
#include"GameOver.h"
#include"Title.h"
#include"nature/SkyCube.h"
#include"graphics/RenderingEngine.h"

Game::Game()
{
	InitSky();
	m_player =NewGO<Player>(0, "battleCharacter");
	gameCamera = NewGO<GameCamera>(0,"gamecamera");
	backGround = NewGO<BackGround>(0);
	//Item�̕�������
	Item*item1 = NewGO<Item>(0, "item1");
	item1->m_position = { 0.0f, 25.0f, 1100.0f };
	Item* item2 = NewGO<Item>(0,"item2");
	item2->m_position = { 0.0f, 420.0f, 2460.0f };
	Item* item3 = NewGO<Item>(0, "item3");
	item3->m_position = {0.0f,740.0f,3950.0f };
	Item* item4 = NewGO<Item>(0, "item4");
	item4->m_position = {0.0f,-870.0f,4100.0f };
	Item* item5 = NewGO<Item>(0, "item5");
	item5->m_position = { 0.0f,-380.0f,6500.0f };
	gameCamera->m_player = m_player;

}


Game::~Game()
{
	
	
	//�v���C���[���폜
	DeleteGO(m_player);
	//�Q�[���J�������폜
	DeleteGO(gameCamera);
	//�w�i���폜
	DeleteGO(backGround);

	//�X�J�C�L���[�u���폜
	DeleteGO(m_skyCube);

	DeleteGO(FindGO<Item>("item1"));
	DeleteGO(FindGO<Item>("item2"));
	DeleteGO(FindGO<Item>("item3"));
	DeleteGO(FindGO<Item>("item4"));
	DeleteGO(FindGO<Item>("item5"));

}





void Game::InitSky()
{
	//���݂̃X�J�C�L���[�u���폜
	DeleteGO(m_skyCube);
	m_skyCube = NewGO<SkyCube>(0, "skycube");

	m_skyCube->SetLuminance(1.0f);
	m_skyCube->SetType((EnSkyCubeType)m_skyCubeType);

	g_renderingEngine->SetAmbientByIBLTexture(m_skyCube->GetTextureFilePath(), 1.0f);
	//�����̌v�Z�̂��߂�IBL�e�N�X�`�����Z�b�g
	g_renderingEngine->SetDirectionLight(0, g_vec3Zero, g_vec3Zero);

}

void Game::Update()
{
	////���ύX
	//if (g_pad[0]->IsTrigger(enButtonRight))
	//{
	//	m_skyCubeType++;
	//	m_skyCubeType = m_skyCubeType % enSkyCubeType_Num;
	//	InitSky();
	//}

	//if (g_pad[0]->IsTrigger(enButtonLeft))
	//{
	//	m_skyCubeType--;
	//	if (m_skyCubeType < 0)
	//	{
	//		m_skyCubeType = enSkyCubeType_Num - 1;
	//	}
	//	InitSky();
	//}



	//StarCount���T�ɂȂ�����
	if (m_player->itemCount == 5)
	{
		NewGO<GameClear>(0, "Gameclear");
		DeleteGO(this);
	}
	

	if (m_player->m_position.y <-1000.0f)
	{
		NewGO<GameOver>(0, "GameOver");
		DeleteGO(this);
	}
}

void Game::Render(RenderContext& rc)
{


}