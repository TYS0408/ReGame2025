#pragma once

class BackGround:public IGameObject
{
public:
	BackGround();
	~BackGround();
	void Render(RenderContext& rc);
private:
	//�ÓI�����I�u�W�F�N�g��ێ�������B
	PhysicsStaticObject physicsStaticObject;
	ModelRender m_modelRender;
};

