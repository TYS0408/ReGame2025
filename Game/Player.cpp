#include "stdafx.h"
#include "Player.h"
Player::Player()
{
	
	//�A�j���[�V�������N���b�v���[�h����
	animationClips[enAnimationClip_Idle].Load("Assets/animData/idle.tka");
	animationClips[enAnimationClip_Idle].SetLoopFlag(true);
	animationClips[enAnimationClip_Walk].Load("Assets/animData/walk.tka");
	animationClips[enAnimationClip_Walk].SetLoopFlag(true);
	animationClips[enAnimationClip_Jump].Load("Assets/animData/jump.tka");
	animationClips[enAnimationClip_Jump].SetLoopFlag(false);
	animationClips[enAnimationClip_Run].Load("Assets/animData/run.tka");
	animationClips[enAnimationClip_Run].SetLoopFlag(true);

	//���f����������
	m_modelRender.Init("Assets/modelData/unityChan.tkm",animationClips,enAnimationClip_Num,enModelUpAxisY);

	//�L�����R����������
	characterController.Init(25.0f, 75.0f, m_position);

}

Player::~Player()
{

}

//�X�V�����B
void Player::Update()
{
	//�ړ������B
	Move();

	//��]����
	Rotation();

	//�X�e�[�g�Ǘ�
	ManageState();

	//�A�j���[�V�����̍Đ�
	PlayAnimation();
	//���W���G�`������ɋ�����B
	m_modelRender.SetPosition(m_position);

	//���f�����X�V
	m_modelRender.Update();
}


void Player::Move()
{
	//xz�̈ړ����x��0.0f�ɂ���B
	moveSpeed.x = 0.0f;
	moveSpeed.z = 0.0f;

	//���X�e�B�b�N����͗ʂ����Z
	Vector3 stickL;
	stickL.x = g_pad[0]->GetLStickXF();
	stickL.y = g_pad[0]->GetLStickYF();

	//�ړ����x�ɃX�e�B�b�N�̓��͗ʂ����Z
	moveSpeed.x += stickL.x * 120.0f;
	moveSpeed.z += stickL.y * 120.0f;

	//�J�����̑O�����ƉE�����̃x�N�g���������Ă���
	Vector3 forward = g_camera3D->GetForward();
	Vector3 right = g_camera3D->GetRight();

	//y�����ɂ͈ړ������Ȃ�
	forward.y = 0.0f;
	right.y = 0.0f;
	//���X�e�B�b�N�̓��͗ʂ�120.0f����Z
	right*= stickL.x * 120.0f;
	 forward*= stickL.y * 120.0f;

	//�ړ����x�ɏ�L�Ōv�Z�����x�N�g�������Z����
	moveSpeed += right + forward;

	//�n�ʂɂ��Ă�����B
	if (characterController.IsOnGround())
	{
		//�d�͂𖳂���
		moveSpeed.y = 0.0f;
		//B�{�^��(K�j�������ꂽ��
		if (g_pad[0]->IsPress(enButtonB))
		{
			//�ړ����x��2�{����
			moveSpeed *= 2.0f;
			//�d�͂𖳂���
			//moveSpeed.y -=2.5f;
		}
	}

	//�n�ʂɂ��Ă��Ȃ�������
	else
	{
		//�d�͂𔭐�
		moveSpeed.y -= 2.5f;
	}


	//��i�W�����v����
	if (g_pad[0]->IsTrigger(enButtonA))
	{
		
		if (m_JumpCount < m_maxJumpCount)
		{
			moveSpeed.y = 350.0f;
			m_JumpCount++;
		}
	}
	if (characterController.IsOnGround())
	{
	
		m_JumpCount = 0;
	}


	//�n�ʂɂ��Ă��Ȃ�������
	else
	{
		//�d�͂𔭐�
		moveSpeed.y -= 2.5f;
	}

	//�L�����N�^�[�R���g���[�����g���č��W���ړ�
	m_position = characterController.Execute(moveSpeed, 1.0f / 60.0f);

	//�G�`������ɍ��W��������
	m_modelRender.SetPosition(m_position);
}

void Player::Rotation()
{
	//x�����̈ړ����x����������(�X�e�B�b�N�̓��͂���������)
	if (fabsf(moveSpeed.x) >= 0.001f || fabsf(moveSpeed.z) >= 0.001f)
	{
		//�L�����N�^�[�̕�����ς���
		rotation.SetRotationYFromDirectionXZ(moveSpeed);
		//�G�`������ɉ�]��������
		m_modelRender.SetRotation(rotation);
	}
}

void Player::ManageState()
{
	//�n�ʂɂ��Ă��Ȃ�������
	if (characterController.IsOnGround() == false)
	{
		//�X�e�[�g��1(�W�����v)�ɂ���
		playerState = 1;
		//������ManageState�𔲂���֐����������I��点��
		return;
	}

	//�n�ʂɂ��Ă�����
	//x��z�̈ړ����x����������(�X�e�B�b�N�̓��͂���������)
	if (fabsf(moveSpeed.x) >= 0.001f || fabsf(moveSpeed.z) >= 0.001f)
	{//��fabsf�͐�Βl�����֐�
		//�X�e�[�g��2(����)�ɂ���
		playerState = 2;
	}
	//x��z�̈ړ����x���Ȃ�������(�X�e�B�b�N�̓��͂��Ȃ�������)
	else
	{
		//�X�e�[�g��0(�ҋ@)�ɂ���
		playerState = 0;
	}



	//�ړ����x��2�{�Ȃ�
	if (moveSpeed.Length() >= 300.0f)
	{
		//�X�e�[�g��3(����)�ɂ���
		playerState = 3;
		moveSpeed.y -= 2.5f;//�d�͂𔭐�
	}
}

//�A�j���[�V�����̍Đ�
void Player::PlayAnimation()
{
	if(playerState == 0)
	{
		m_modelRender.PlayAnimation(enAnimationClip_Idle);
	}

	if(playerState == 1)
	{
		m_modelRender.PlayAnimation(enAnimationClip_Jump);
	}

	if(playerState == 2)
	{
		m_modelRender.PlayAnimation(enAnimationClip_Walk);
	}

	if (playerState == 3)
	{
		m_modelRender.PlayAnimation(enAnimationClip_Run);
	}
}


void Player::Render(RenderContext& renderContext)
{
	//���f����\��
	m_modelRender.Draw(renderContext);
}
