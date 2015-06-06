/**=============================================================================
	@file		MyGame.cpp
	@brief		ゲームループクラス 実装
	@author		Masato Yamamoto
	@date		2015-02-20

	@par		[説明]
				ゲームループクラス実装

	@note

		Copyright (C) 2015  M.Yamamoto
=============================================================================*/
#include "MyGame.h"
#include "DxLib.h"
#include "FpsController.h"

#include "FileLoader.h"

#include "Object3D.h"

#include <clocale>
#include <string>
#include <ctime>
//===============================================================//
//
//	DxLib定数定義
//
#define	WINDOW_NAME		"DxLibGame01"

//===============================================================//


NS_DLG_BEGIN

NS_USE_MATH;
#pragma region MyGame public methods

/**
	@brief		コンストラクタ
	@param[in]	なし
	@return		なし
*/
MyGame::MyGame(::HINSTANCE hInstance,
			   ::HINSTANCE hPrevInstance,
			   ::LPSTR lpCmdLine,
			   int nCmdShow)
{
	//=====================================================
	// DxLib設定
	//=====================================================
	if (_Init(Size(1024.f, 576.f)) == -1)
	{	// ＤＸライブラリ初期化処理
		MessageBox(nullptr, "Initializing error", "Error!", MB_ICONERROR | MB_TASKMODAL | MB_TOPMOST);
		return;	// エラーが起きたら直ちに終了
	}

	//-----------------------------------------------
	// 初期化・準備
	//-----------------------------------------------
	::std::setlocale(LC_CTYPE, "JPN");

	// 描画先画面を裏画面にセット
	SetDrawScreen(DX_SCREEN_BACK);

}

/**
	@brief		デストラクタ
	@param[in]	なし
	@return		なし
*/
MyGame::~MyGame()
{
	::DxLib::DxLib_End();
}

/**
	@brief		XZ平面でのラジアンを求める
	@return		HAngle(ラジアン)
*/
static float GetHAngle(const Vector3& eye, const Vector3& targetPos)
{
	// 注視点への方向ベクトル
	Vector3 vDir = targetPos - eye;
	// HAngle(XZ平面での角度)
	float angle = ::std::atan2f(-vDir.z, vDir.x);
	float adj = DX_PI_F / 2.f;	// 角度調整(Z咆哮を基準に回転する)
	angle += adj;

	// -PI~+PIに丸める
	if (angle > DX_PI_F)
		angle -= DX_TWO_PI_F;
	if (angle < -DX_PI_F)
		angle += DX_TWO_PI_F;

	return angle;
}
/**
	@brief		メインループ
	@param[in]	なし
	@return		なし
*/
void MyGame::Loop()
{
	FpsController fps(60);
	SetBackgroundColor(150, 150, 150);
	SetCameraNearFar(1.f, 1000.f);
	while (ProcessMessage() == 0)
	{
		// calc deltaTime
		fps.Wait();
		
		//--------------------------------
		if (CheckHitKey(KEY_INPUT_ESCAPE))
		{
			break;
		}
		// render draw
		ClearDrawScreen();
#ifdef _DEBUG
		fps.Draw(0, 0);
#endif
		{
			static int img = FileLoader::GetInstance()->LoadGraph("res/image/a.png");
			Vector3 center(GetWinSize() / 2.f);
			int w, h;
			GetGraphSize(img, &w, &h);
			//DrawGraphF(center.x - w / 2.f, center.y - h / 2.f, img, TRUE);
		}
		
		{
			static Vector3 targetPos(0.f, 0.f, 0.f);
			static Vector3 cameraRot(0.f, M_PI_4, 0.f);
			static Vector3 vUp(0.f, 1.f, 0.f);
			enum {DIST_NUM = 5};
			const static float distPat[DIST_NUM] = { 10.f, 30.f, 50.f, 75.f, 100.f };
			static int cameraDist = DIST_NUM / 2;
			
			static Vector3 cameraPos = Matrix4x4::CalcVector3RotationXYZ(cameraRot.x, cameraRot.y, cameraRot.z, Vector3(0.f, 0.f, -distPat[cameraDist]));



			static int mouseX, mouseY;

			if (CheckHitKey(KEY_INPUT_LCONTROL) || CheckHitKey(KEY_INPUT_RCONTROL))
			{
				if (CheckHitKey(KEY_INPUT_UP))
				{
					targetPos.y += 0.2f;
					cameraPos.y += 0.2f;
				}
				if (CheckHitKey(KEY_INPUT_DOWN))
				{
					targetPos.y -= 0.2f;
					cameraPos.y -= 0.2f;
				}
			}
			else
			{
				if (CheckHitKey(KEY_INPUT_UP))
				{
					cameraPos.z += 0.2f;
				}
				if (CheckHitKey(KEY_INPUT_DOWN))
				{
					cameraPos.z -= 0.2f;
				}
			}
			if (CheckHitKey(KEY_INPUT_LEFT))
			{
				cameraPos.x -= 0.2f;
			}
			if (CheckHitKey(KEY_INPUT_RIGHT))
			{
				cameraPos.x += 0.2f;
			}
			static const float MOVE_SPEED = 2.5f;
			if (CheckHitKey(KEY_INPUT_W))
			{
				// 前
				targetPos.z += MOVE_SPEED;
			}
			if (CheckHitKey(KEY_INPUT_A))
			{
				// 左
				targetPos.x -= MOVE_SPEED;
			}
			if (CheckHitKey(KEY_INPUT_S))
			{
				// 後
				targetPos.z -= MOVE_SPEED;
			}
			if (CheckHitKey(KEY_INPUT_D))
			{
				// 右
				targetPos.x += MOVE_SPEED;
			}





			const int wheel = GetMouseWheelRotVol();
			if (wheel < 0)
				// - ズームアウト
				cameraDist = min(cameraDist + 1, DIST_NUM - 1);
			else if (wheel > 0)
				// + ズームイン
				cameraDist = max(cameraDist - 1, 0);
			if (GetMouseInput()&(MOUSE_INPUT_RIGHT))
			{
				int nowX, nowY;	// 現フレームのマウス座標
				GetMousePoint(&nowX, &nowY);
				// 移動量の算出
				int deltaX = nowX - mouseX;
				int deltaY = nowY - mouseY;
				Vector3 vDelta(deltaX, deltaY, 0.f);
				
				auto scaleX = 0.01f;
				auto scaleY = 0.01f;

				//------------------------------------
				
				{
					cameraRot.x += deltaX*scaleX;
					// 角度修正(0~360)
					if (cameraRot.x > DX_TWO_PI_F)
						cameraRot.x -= DX_TWO_PI_F;
					if (cameraRot.x < 0.f)
						cameraRot.x += DX_TWO_PI_F;
					 
					cameraRot.y += deltaY*scaleY;
					// 角度修正(0~360)
					if (cameraRot.y > DX_PI_F)
						cameraRot.y -= DX_TWO_PI_F;
					if (cameraRot.y < -DX_PI_F)
						cameraRot.y += DX_TWO_PI_F;
					
				}
				
				mouseX = nowX;
				mouseY = nowY;
			}
			else
			{
				GetMousePoint(&mouseX, &mouseY);	// マウス座標更新

			}
			vUp = Matrix4x4::CalcVector3RotationXYZ(cameraRot.x, cameraRot.y, cameraRot.z, Vector3(0.f, 1.f, 0.f));

			cameraPos = targetPos + Matrix4x4::CalcVector3RotationXYZ(cameraRot.x, cameraRot.y, cameraRot.z, Vector3(0.f, 0.f, -distPat[cameraDist]));


			// カメラの設定
			//DxLib::SetCameraPositionAndTarget_UpVecY(cameraPos, targetPos);
			DxLib::SetCameraPositionAndTargetAndUpVec(cameraPos, targetPos, vUp);
			vUp = GetCameraUpVector();
			cameraPos = GetCameraPosition();
			targetPos = GetCameraTarget();

			static int directionalRight = CreateDirLightHandle(Vector3(0.f, 0.f, -1.f));
			MV1SetPosition(directionalRight, Vector3(0.f, 0.f, 999.f));
			
			DrawCapsule3D(Vector3(5.f, 0.f, 0.f), Vector3(5.f, 10.f, 0.f), 2.f, 8, -1, -1, 1);
			DrawCapsule3D(Vector3(-5.f, 0.f, 0.f), Vector3(-5.f, 0.f, 10.f), 2.f, 8, -1, -1, 1);

			static Object3D obj("res/model/aieltan/aieltan.pmx", "aieltan");
			obj.SetPosition(Vector3(0.f, 0.f, 0.f));
			obj.SetScale(Vector3(1.f));


			{
				Vector3 vertices[2][4]=
				{
					{
						Vector3(-10.f, 0.f, +10.f),		// 左下奥
						Vector3(+10.f, 0.f, +10.f),		// 右下奥
						Vector3(+10.f, 0.f, -10.f),		// 右下前
						Vector3(-10.f, 0.f, -10.f),		// 左下前
					},
					{
						Vector3(-10.f, 20.f, +10.f),	// 左上奥
						Vector3(+10.f, 20.f, +10.f),	// 右上奥
						Vector3(+10.f, 20.f, -10.f),	// 右上前
						Vector3(-10.f, 20.f, -10.f),	// 左上前
					}
				};
				for (int i = 0; i < 2; ++i)
				{
					for (int j = 0; j < 4; ++j)
					{
						int k = (j + 1) % 4;
						DrawLine3D(vertices[i][j], vertices[i][k], -1);
					}
				}
				for (int i = 0; i < 4; ++i)
				{
					DrawLine3D(vertices[0][i], vertices[1][i], -1);
				}
				//DrawCube3D(Vector3(-10.f, -0.f, -10.f), Vector3(10.f, 20.f, 10.f), -1, 0, FALSE);
			}
			// 位置関係が分かるように地面にラインを描画する
			if(0){
				static const float LINE_AREA_SIZE = 100.f;
				static const int LINE_NUM = 50;
				int i;
				VECTOR Pos1;
				VECTOR Pos2;

				SetUseZBufferFlag(TRUE);

				Pos1 = VGet(-LINE_AREA_SIZE / 2.0f, 0.0f, -LINE_AREA_SIZE / 2.0f);
				Pos2 = VGet(-LINE_AREA_SIZE / 2.0f, 0.0f, LINE_AREA_SIZE / 2.0f);
				for (i = 0; i <= LINE_NUM; i++)
				{
					DrawLine3D(Pos1, Pos2, GetColor(255, 255, 255));
					Pos1.x += LINE_AREA_SIZE / LINE_NUM;
					Pos2.x += LINE_AREA_SIZE / LINE_NUM;
				}

				Pos1 = VGet(-LINE_AREA_SIZE / 2.0f, 0.0f, -LINE_AREA_SIZE / 2.0f);
				Pos2 = VGet(LINE_AREA_SIZE / 2.0f, 0.0f, -LINE_AREA_SIZE / 2.0f);
				for (i = 0; i < LINE_NUM; i++)
				{
					DrawLine3D(Pos1, Pos2, GetColor(255, 255, 255));
					Pos1.z += LINE_AREA_SIZE / LINE_NUM;
					Pos2.z += LINE_AREA_SIZE / LINE_NUM;
				}

				SetUseZBufferFlag(FALSE);
			}
			obj.SetPosition(targetPos);
			obj.Draw(fps.GetDeltaTime());
			DrawFormatString(0, 20, -1, "Pos(%3.0f,%3.0f,%3.0f) LookAt(%3.0f,%3.0f,%3.0f) UpVec(%3.2f,%3.2f,%3.2f)", cameraPos.x, cameraPos.y, cameraPos.z, targetPos.x, targetPos.y, targetPos.z, vUp.x, vUp.y, vUp.z);

		}
		//--------------------------------
		if (ScreenFlip() != 0)
		{
			break;
		}
	}
}
#pragma endregion	// MyGame public methods

//------------------------------------------------
#pragma region MyGame private methods
/**
	@brief		DXライブラリ環境初期化
	@param[in]	winSize		ウィンドウサイズ
	@return		DxLib_Init()の戻り値
	@retval		-1	エラー
*/
int MyGame::_Init(const Size& winSize)
{
	int result = ::DxLib::SetGraphMode(
					static_cast<int>(winSize.width),
					static_cast<int>(winSize.height),
					32, 120);
	if (DX_CHANGESCREEN_OK == result)
	{
		SetWinSize(winSize);
	}
	result = ::DxLib::SetWaitVSyncFlag(FALSE);
	result = ::DxLib::ChangeWindowMode(TRUE);	// ウインドウモードに変更
	result = ::DxLib::SetMainWindowText(WINDOW_NAME);
	result = ::DxLib::SetMouseDispFlag(TRUE);		// マウス表示
	result = ::DxLib::DxLib_Init();
	return result;
}

#pragma endregion	// MyGame private methods

NS_DLG_END	// namespace ns_DxLibGame