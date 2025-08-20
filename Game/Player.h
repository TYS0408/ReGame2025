#pragma once
class Player:public IGameObject
{
public:
	Player();
	~Player();
	//�X�V�����B
	void Update();
	void Render(RenderContext& renderContext);
	void Move();
	void Rotation(); //��]����
	//�X�e�[�g�Ǘ�
	void ManageState();
	//�A�j���[�V�����̍Đ�
	void PlayAnimation();
	ModelRender m_modelRender;  //���f�������_�[�B
	Vector3 m_position;         //���W�B
	int itemCount = 0; //�W�߂��A�C�e���̐����J�E���g
	Vector3 moveSpeed; //�ړ����x
private:
	//�����o�ϐ��B
	//�z��Ɏ����悤�Ȃ���
	enum EnAnimationClip
	{  //�A�j���[�V�����B
		enAnimationClip_Idle,
		enAnimationClip_Walk,
		enAnimationClip_Jump,
		enAnimationClip_Run,
		enAnimationClip_Num
	};
	int m_JumpCount = 0;//���݂̃W�����v��
	int m_maxJumpCount = 1; //�ő�W�����v��
	CharacterController characterController; //�L�����N�^�[�R���g���[���[
	
	Quaternion rotation;//�N�H�[�^�j�I��
	int playerState = 0;//�v���C���[�̏�Ԃ�\���ϐ�
	
	AnimationClip animationClips[enAnimationClip_Num];
};



