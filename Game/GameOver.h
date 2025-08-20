#pragma once
class GameOver:public IGameObject
{
public:
	GameOver();
	~GameOver();
	void Update();
	void Render(RenderContext& rc);
	
private:
	//ƒƒ“ƒo•Ï”
	SpriteRender m_overspriteRender;

};

