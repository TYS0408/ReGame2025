#include "stdafx.h"
#include "Player.h"
Player::Player()
{
	
	//アニメーションをクリップロードする
	animationClips[enAnimationClip_Idle].Load("Assets/animData/idle.tka");
	animationClips[enAnimationClip_Idle].SetLoopFlag(true);
	animationClips[enAnimationClip_Walk].Load("Assets/animData/walk.tka");
	animationClips[enAnimationClip_Walk].SetLoopFlag(true);
	animationClips[enAnimationClip_Jump].Load("Assets/animData/jump.tka");
	animationClips[enAnimationClip_Jump].SetLoopFlag(false);
	animationClips[enAnimationClip_Run].Load("Assets/animData/run.tka");
	animationClips[enAnimationClip_Run].SetLoopFlag(true);

	//モデルを初期化
	m_modelRender.Init("Assets/modelData/unityChan.tkm",animationClips,enAnimationClip_Num,enModelUpAxisY);

	//キャラコンを初期化
	characterController.Init(25.0f, 75.0f, m_position);

}

Player::~Player()
{

}

//更新処理。
void Player::Update()
{
	//移動処理。
	Move();

	//回転処理
	Rotation();

	//ステート管理
	ManageState();

	//アニメーションの再生
	PlayAnimation();
	//座標を絵描きさんに教える。
	m_modelRender.SetPosition(m_position);

	//モデルを更新
	m_modelRender.Update();
}


void Player::Move()
{
	//xzの移動速度を0.0fにする。
	moveSpeed.x = 0.0f;
	moveSpeed.z = 0.0f;

	//左スティックを入力量を加算
	Vector3 stickL;
	stickL.x = g_pad[0]->GetLStickXF();
	stickL.y = g_pad[0]->GetLStickYF();

	//移動速度にスティックの入力量を加算
	moveSpeed.x += stickL.x * 120.0f;
	moveSpeed.z += stickL.y * 120.0f;

	//カメラの前方向と右方向のベクトルを持ってくる
	Vector3 forward = g_camera3D->GetForward();
	Vector3 right = g_camera3D->GetRight();

	//y方向には移動させない
	forward.y = 0.0f;
	right.y = 0.0f;
	//左スティックの入力量と120.0fを乗算
	right*= stickL.x * 120.0f;
	 forward*= stickL.y * 120.0f;

	//移動速度に上記で計算したベクトルを加算する
	moveSpeed += right + forward;

	//地面についていたら。
	if (characterController.IsOnGround())
	{
		//重力を無くす
		moveSpeed.y = 0.0f;
		//Bボタン(K）が押されたら
		if (g_pad[0]->IsPress(enButtonB))
		{
			//移動速度を2倍する
			moveSpeed *= 2.0f;
			//重力を無くす
			//moveSpeed.y -=2.5f;
		}
	}

	//地面についていなかったら
	else
	{
		//重力を発生
		moveSpeed.y -= 2.5f;
	}


	//二段ジャンプ処理
	if (g_pad[0]->IsTrigger(enButtonA))
	{
		
		if (m_JumpCount < m_maxJumpCount)
		{
			moveSpeed.y = 350.0f;
			m_JumpCount++;
		}
	}
	if (characterController.IsOnGround())
	{
	
		m_JumpCount = 0;
	}


	//地面についていなかったら
	else
	{
		//重力を発生
		moveSpeed.y -= 2.5f;
	}

	//キャラクターコントロールを使って座標を移動
	m_position = characterController.Execute(moveSpeed, 1.0f / 60.0f);

	//絵描きさんに座標を教える
	m_modelRender.SetPosition(m_position);
}

void Player::Rotation()
{
	//xかｚの移動速度があったら(スティックの入力があったら)
	if (fabsf(moveSpeed.x) >= 0.001f || fabsf(moveSpeed.z) >= 0.001f)
	{
		//キャラクターの方向を変える
		rotation.SetRotationYFromDirectionXZ(moveSpeed);
		//絵描きさんに回転を教える
		m_modelRender.SetRotation(rotation);
	}
}

void Player::ManageState()
{
	//地面についていなかったら
	if (characterController.IsOnGround() == false)
	{
		//ステートを1(ジャンプ)にする
		playerState = 1;
		//ここでManageStateを抜ける関数を処理を終わらせる
		return;
	}

	//地面についていたら
	//xかzの移動速度があったら(スティックの入力があったら)
	if (fabsf(moveSpeed.x) >= 0.001f || fabsf(moveSpeed.z) >= 0.001f)
	{//↑fabsfは絶対値を取る関数
		//ステートを2(歩き)にする
		playerState = 2;
	}
	//xかzの移動速度がなかったら(スティックの入力がなかったら)
	else
	{
		//ステートを0(待機)にする
		playerState = 0;
	}



	//移動速度が2倍なら
	if (moveSpeed.Length() >= 300.0f)
	{
		//ステートを3(走る)にする
		playerState = 3;
		moveSpeed.y -= 2.5f;//重力を発生
	}
}

//アニメーションの再生
void Player::PlayAnimation()
{
	if(playerState == 0)
	{
		m_modelRender.PlayAnimation(enAnimationClip_Idle);
	}

	if(playerState == 1)
	{
		m_modelRender.PlayAnimation(enAnimationClip_Jump);
	}

	if(playerState == 2)
	{
		m_modelRender.PlayAnimation(enAnimationClip_Walk);
	}

	if (playerState == 3)
	{
		m_modelRender.PlayAnimation(enAnimationClip_Run);
	}
}


void Player::Render(RenderContext& renderContext)
{
	//モデルを表示
	m_modelRender.Draw(renderContext);
}
