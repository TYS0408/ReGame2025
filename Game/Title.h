#pragma once
class Player;
class Title :public IGameObject
{

public:
	Title();
	~Title();
	void Update();
	void Render(RenderContext& rc);

private:
	//�X�v���C�g�����_�[
	SpriteRender titleSpriteRender;
};

