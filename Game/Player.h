#pragma once
class Player:public IGameObject
{
public:
	Player();
	~Player();
	//更新処理。
	void Update();
	void Render(RenderContext& renderContext);
	void Move();
	void Rotation(); //回転処理
	//ステート管理
	void ManageState();
	//アニメーションの再生
	void PlayAnimation();
	ModelRender m_modelRender;  //モデルレンダー。
	Vector3 m_position;         //座標。
	int itemCount = 0; //集めたアイテムの数をカウント
	Vector3 moveSpeed; //移動速度
private:
	//メンバ変数。
	//配列に似たようなもの
	enum EnAnimationClip
	{  //アニメーション。
		enAnimationClip_Idle,
		enAnimationClip_Walk,
		enAnimationClip_Jump,
		enAnimationClip_Run,
		enAnimationClip_Num
	};
	int m_JumpCount = 0;//現在のジャンプ回数
	int m_maxJumpCount = 1; //最大ジャンプ回数
	CharacterController characterController; //キャラクターコントローラー
	
	Quaternion rotation;//クォータニオン
	int playerState = 0;//プレイヤーの状態を表す変数
	
	AnimationClip animationClips[enAnimationClip_Num];
};



