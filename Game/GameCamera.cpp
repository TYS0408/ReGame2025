#include "stdafx.h"
#include "GameCamera.h"
#include "Player.h"
GameCamera::GameCamera()
{
	
}

GameCamera::~GameCamera()
{
	
}

bool GameCamera::Start()
{
	//注視点から視点までのベクトルを設定
	m_toCameraPos.Set(0.0f, 125.0f, -250.0f);
	//プレイヤーのインスタンスを探す
	m_player = FindGO<Player>("battleCharacter");
	//カメラのニアクリップとファークリップを設定する
	g_camera3D->SetPosition({ 0.0f,100.0f,400.0f });
	g_camera3D->SetFar(40000.0f);
	return true;
}

void GameCamera::Update()
{

	/*if (m_player == nullptr)
	{
		return;
	}*/
	Vector3 target;
	//注視点をプレイヤーの座標に設定
	target.x = m_player->m_position.x;
	//y座標を少し上げる
	target.y = m_player->m_position.y +=100.0f;
	target.z = m_player->m_position.z;
	//カメラの注視点を変更
	g_camera3D->SetTarget(target);

	Vector3 cameraPos;
	cameraPos = target;
	cameraPos.z -= 300.0f;
	//カメラの視点を変更
	g_camera3D->SetPosition(cameraPos);
	/*g_camera3D->SetNear(250.0f);
	g_camera3D->SetFar(900.0f);*/
//	if (m_player == nullptr)
//	{
//		return;
//	}
//	//注視点を計算
//	Vector3 target = m_player->m_position;
//	//プレイヤーの足元より少し上を注視点にする
//	target.y += 80.0f;
//	Vector3 toCameraPosOld = m_toCameraPos;
//	//パッドの入力を使ってカメラを回す
//	float x = g_pad[0]->GetLStickXF();
//	float y = g_pad[0]->GetLStickYF();
//	//Y軸周りの回転
//	Quaternion qRot;
//	qRot.SetRotationDeg(Vector3::AxisY, 1.3f * x);
//	qRot.Apply(m_toCameraPos);
//	//X軸周りの回転
//	Vector3 axisX;
//	axisX.Cross(Vector3::AxisY, m_toCameraPos);
//	axisX.Normalize();
//	qRot.SetRotationDeg(axisX, 1.3f * y);
//	qRot.Apply(m_toCameraPos);
//	//カメラの回転の上限をチェックする。
//		//注視点から視点までのベクトルを正規化する。
//		//正規化すると、ベクトルの大きさが１になる。
//		//大きさが１になるということは、ベクトルから強さがなくなり、方向のみの情報となるということ。
//	Vector3 toPosDir = m_toCameraPos;
//	toPosDir.Normalize();
//	if (toPosDir.y < -0.2f)
//	{
//		//カメラが上向きすぎ
//		m_toCameraPos = toCameraPosOld;
//	}
//	else if (toPosDir.y > 0.9f)
//	{
//		//カメラが上向きすぎ
//		m_toCameraPos = toCameraPosOld;
//	}
//
//	//視点を計算
//	Vector3 pos = target + m_toCameraPos;
//	//メインカメラに注視点と視点を設定
//	g_camera3D->SetTarget(target);
//	g_camera3D->SetPosition(pos);
//
//	//カメラの更新
//	g_camera3D->Update();

}
