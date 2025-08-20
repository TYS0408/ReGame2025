#include "stdafx.h"
#include "BackGround.h"
BackGround::BackGround()
{
	m_modelRender.Init("Assets/modelData/stage.tkm");
	physicsStaticObject.CreateFromModel(m_modelRender.GetModel(),
	m_modelRender.GetModel().GetWorldMatrix());
	//“–‚½‚è”»’è‚ð•`‰æ
	//PhysicsWorld::GetInstance()->EnableDrawDebugWireFrame();
	
}

BackGround::~BackGround()
{

	
}


void BackGround::Render(RenderContext& rc)
{
	//ƒ‚ƒfƒ‹‚ð•`‰æ
	m_modelRender.Draw(rc);
}