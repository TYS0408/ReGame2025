#include "stdafx.h"
#include "Item.h"
#include"Player.h"
#include"sound/SoundEngine.h"
#include"sound/SoundSource.h"
Item::Item()
{
	m_modelRender.Init("Assets/modelData/Item.tkm");
	//プレイヤーのオブジェクトを取得
	player = FindGO<Player>("battleCharacter");
	//waveファイルを読み込む
	g_soundEngine->ResistWaveFileBank(1,"Assets/SE/Item_se.wav");
}

Item::~Item()
{

}

 void Item::Update()
{
	 //回転処理
	 Rotation();
	//プレイヤーからアイテムに向かうベクトルを計算
	 Vector3 diff = player->m_position - m_position;
	 if (diff.Length() <= 120.0f)
	 {
		 player->itemCount += 1; //カウントを増やす
		 SoundSource* se = NewGO<SoundSource>(0);
		 se->Init(1);
         //効果音はループさせないのでfalseにする
		 se->Play(false);
		 //音量を上げる
		 se->SetVolume(3.5f);
		 //自身を削除
		 DeleteGO(this);

	 }

	 //絵描きさんに座標を教える
	 m_modelRender.SetPosition(m_position);

	 //絵描きさんの更新処理
	 m_modelRender.Update();
}

 void Item::Rotation()
 {
	 //回転を加算
	 m_rotation.AddRotationDegY(2.0f);
	 //絵描きさんに回転を教える
	 m_modelRender.SetRotation(m_rotation);
 }



 void Item::Render(RenderContext& rc)
 {
	 //アイテムを描画
	 m_modelRender.Draw(rc);
 }
