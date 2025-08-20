#pragma once

class BackGround:public IGameObject
{
public:
	BackGround();
	~BackGround();
	void Render(RenderContext& rc);
private:
	//静的物理オブジェクトを保持させる。
	PhysicsStaticObject physicsStaticObject;
	ModelRender m_modelRender;
};

