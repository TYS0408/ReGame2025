#include "stdafx.h"
#include "BackGround.h"
BackGround::BackGround()
{
	m_modelRender.Init("Assets/modelData/stage.tkm");
	physicsStaticObject.CreateFromModel(m_modelRender.GetModel(),
	m_modelRender.GetModel().GetWorldMatrix());
	//�����蔻���`��
	//PhysicsWorld::GetInstance()->EnableDrawDebugWireFrame();
	
}

BackGround::~BackGround()
{

	
}


void BackGround::Render(RenderContext& rc)
{
	//���f����`��
	m_modelRender.Draw(rc);
}