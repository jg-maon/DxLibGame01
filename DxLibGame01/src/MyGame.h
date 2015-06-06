/**=============================================================================
	@file		MyGame.h
	@brief		ゲームループクラス 定義
	@author		Masato Yamamoto
	@date		2015-02-20

	@par		[説明]
				ゲームループクラス定義

	@note

		Copyright (C) 2015  M.Yamamoto
=============================================================================*/
#ifndef __MY_GAME_H__
#define __MY_GAME_H__


#ifndef __DXLIB
#include "DxLib.h"
#endif

#ifndef __DXLIB_GAME_H__
#include "DxLibGame.h"
#endif

#ifndef __REF_H__
#include "Ref.h"
#endif

NS_DLG_BEGIN
/**
	@class		MyGame
	@brief		ゲームループクラス
*/
class MyGame : public Ref
{
	//=====================================================
	// 定数(列挙型)宣言
	//=====================================================
public:
	//=====================================================
	// 内部クラス宣言
	//=====================================================
public:
	//=====================================================
	// 型別名定義
	//=====================================================
public:

	//=====================================================
	// 静的メソッド宣言
	//=====================================================
public:

	//=====================================================
	// メソッド宣言
	//=====================================================
public:
	/**
		@brief		コンストラクタ
		@param[in]	hInstance
		@param[in]	hPrevInstance
		@param[in]	lpCmdLine
		@param[in]	nCmdShow
		@return		なし
	*/
	MyGame(HINSTANCE hInstance,
		   HINSTANCE hPrevInstance,
		   LPSTR lpCmdLine,
		   int nCmdShow);
		
	/**
		@brief		デストラクタ
		@param[in]	なし
		@return		なし
	*/
	~MyGame();

private:
		
	/**
		@brief		メインループ
		@param[in]	なし
		@return		なし
	*/
public:
	void Loop();
		
protected:



private:
	/**
		@brief		DXライブラリ環境初期化
		@param[in]	winSize		ウィンドウサイズ
		@return		DxLib_Init()の戻り値
		@retval		-1	エラー
	*/
	int _Init(const ns_Math::Size& winSize);

	//=====================================================
	// 変数宣言
	//=====================================================
public:

protected:

private:

};




NS_DLG_END	// namespace ns_DxLibGame

#endif	// __MY_GAME_H__