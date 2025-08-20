#include "stdafx.h"
#include "Item.h"
#include"Player.h"
#include"sound/SoundEngine.h"
#include"sound/SoundSource.h"
Item::Item()
{
	m_modelRender.Init("Assets/modelData/Item.tkm");
	//�v���C���[�̃I�u�W�F�N�g���擾
	player = FindGO<Player>("battleCharacter");
	//wave�t�@�C����ǂݍ���
	g_soundEngine->ResistWaveFileBank(1,"Assets/SE/Item_se.wav");
}

Item::~Item()
{

}

 void Item::Update()
{
	 //��]����
	 Rotation();
	//�v���C���[����A�C�e���Ɍ������x�N�g�����v�Z
	 Vector3 diff = player->m_position - m_position;
	 if (diff.Length() <= 120.0f)
	 {
		 player->itemCount += 1; //�J�E���g�𑝂₷
		 SoundSource* se = NewGO<SoundSource>(0);
		 se->Init(1);
         //���ʉ��̓��[�v�����Ȃ��̂�false�ɂ���
		 se->Play(false);
		 //���ʂ��グ��
		 se->SetVolume(3.5f);
		 //���g���폜
		 DeleteGO(this);

	 }

	 //�G�`������ɍ��W��������
	 m_modelRender.SetPosition(m_position);

	 //�G�`������̍X�V����
	 m_modelRender.Update();
}

 void Item::Rotation()
 {
	 //��]�����Z
	 m_rotation.AddRotationDegY(2.0f);
	 //�G�`������ɉ�]��������
	 m_modelRender.SetRotation(m_rotation);
 }



 void Item::Render(RenderContext& rc)
 {
	 //�A�C�e����`��
	 m_modelRender.Draw(rc);
 }
