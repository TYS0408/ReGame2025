#pragma once
class Player;
class Item :public IGameObject
{
public:
	Item();
	~Item();
	//�X�V����
	void Update();
	//�`�揈��
	void Render(RenderContext& rc);
	//��]����
	void Rotation();
	Player* player;//�v���C���[
	Vector3 m_position;//���W
private:
	ModelRender m_modelRender;//���f�������_�[
	Quaternion m_rotation;//�N�H�[�^�j�I��
	
};

