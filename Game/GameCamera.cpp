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
	//�����_���王�_�܂ł̃x�N�g����ݒ�
	m_toCameraPos.Set(0.0f, 125.0f, -250.0f);
	//�v���C���[�̃C���X�^���X��T��
	m_player = FindGO<Player>("battleCharacter");
	//�J�����̃j�A�N���b�v�ƃt�@�[�N���b�v��ݒ肷��
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
	//�����_���v���C���[�̍��W�ɐݒ�
	target.x = m_player->m_position.x;
	//y���W�������グ��
	target.y = m_player->m_position.y +=100.0f;
	target.z = m_player->m_position.z;
	//�J�����̒����_��ύX
	g_camera3D->SetTarget(target);

	Vector3 cameraPos;
	cameraPos = target;
	cameraPos.z -= 300.0f;
	//�J�����̎��_��ύX
	g_camera3D->SetPosition(cameraPos);
	/*g_camera3D->SetNear(250.0f);
	g_camera3D->SetFar(900.0f);*/
//	if (m_player == nullptr)
//	{
//		return;
//	}
//	//�����_���v�Z
//	Vector3 target = m_player->m_position;
//	//�v���C���[�̑�����菭����𒍎��_�ɂ���
//	target.y += 80.0f;
//	Vector3 toCameraPosOld = m_toCameraPos;
//	//�p�b�h�̓��͂��g���ăJ��������
//	float x = g_pad[0]->GetLStickXF();
//	float y = g_pad[0]->GetLStickYF();
//	//Y������̉�]
//	Quaternion qRot;
//	qRot.SetRotationDeg(Vector3::AxisY, 1.3f * x);
//	qRot.Apply(m_toCameraPos);
//	//X������̉�]
//	Vector3 axisX;
//	axisX.Cross(Vector3::AxisY, m_toCameraPos);
//	axisX.Normalize();
//	qRot.SetRotationDeg(axisX, 1.3f * y);
//	qRot.Apply(m_toCameraPos);
//	//�J�����̉�]�̏�����`�F�b�N����B
//		//�����_���王�_�܂ł̃x�N�g���𐳋K������B
//		//���K������ƁA�x�N�g���̑傫�����P�ɂȂ�B
//		//�傫�����P�ɂȂ�Ƃ������Ƃ́A�x�N�g�����狭�����Ȃ��Ȃ�A�����݂̂̏��ƂȂ�Ƃ������ƁB
//	Vector3 toPosDir = m_toCameraPos;
//	toPosDir.Normalize();
//	if (toPosDir.y < -0.2f)
//	{
//		//�J���������������
//		m_toCameraPos = toCameraPosOld;
//	}
//	else if (toPosDir.y > 0.9f)
//	{
//		//�J���������������
//		m_toCameraPos = toCameraPosOld;
//	}
//
//	//���_���v�Z
//	Vector3 pos = target + m_toCameraPos;
//	//���C���J�����ɒ����_�Ǝ��_��ݒ�
//	g_camera3D->SetTarget(target);
//	g_camera3D->SetPosition(pos);
//
//	//�J�����̍X�V
//	g_camera3D->Update();

}
