#pragma once
class Player;
class Item :public IGameObject
{
public:
	Item();
	~Item();
	//更新処理
	void Update();
	//描画処理
	void Render(RenderContext& rc);
	//回転処理
	void Rotation();
	Player* player;//プレイヤー
	Vector3 m_position;//座標
private:
	ModelRender m_modelRender;//モデルレンダー
	Quaternion m_rotation;//クォータニオン
	
};

