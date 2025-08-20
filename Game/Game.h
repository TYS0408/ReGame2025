#pragma once
class Player;
class BackGround;
class GameCamera;
class Item;
class Game : public IGameObject
{
public:
	Game();
	~Game();
	//bool Start();
	void Update();
	void Render(RenderContext& rc);
	void InitSky();
	BackGround* backGround;
	GameCamera* gameCamera;
	Player* m_player;
	Item* item;
	SkyCube* m_skyCube; //スカイキューブ
	int m_skyCubeType = enSkyCubeType_Day;
	ModelRender m_modelRender;
	Vector3 m_position;
private:
	

};

