#pragma once
class GameOver:public IGameObject
{
public:
	GameOver();
	~GameOver();
	void Update();
	void Render(RenderContext& rc);
	
private:
	//�����o�ϐ�
	SpriteRender m_overspriteRender;

};

