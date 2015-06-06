/**=============================================================================
	@file		Ref.h
	@brief		全クラス基底クラス 定義
	@author		Masato Yamamoto
	@date		2015-02-20

	@par		[説明]
				全クラスの基底クラスの定義

	@note

		Copyright (C) 2015  M.Yamamoto
=============================================================================*/
#ifndef __REF_H__
#define __REF_H__

#ifndef __DXLIB_GAME_H__
#include "DxLibGame.h"
#endif

#ifndef __MATH_H__
#include "Math.h"
#endif

NS_DLG_BEGIN
/**
	@class		Ref
	@brief		全オブジェクト基底クラス
*/
class Ref
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
		@param[in]	なし
		@return		なし
	*/
	Ref();	
		
	/**
		@brief		デストラクタ
		@param[in]	なし
		@return		なし
	*/
	virtual ~Ref();
	
	/**
		@brief		内部保持ウィンドウサイズの設定
		@param[in]	winSize		新規ウィンドウサイズ
		@return		なし
	*/
	void SetWinSize(const ns_Math::Size& winSize)
	{
		m_winSize = winSize;
	}

	/**
		@brief		ウィンドウサイズの取得
		@param[in]	なし
		@return		ウィンドウサイズ
	*/
	ns_Math::Size GetWinSize() const 
	{
		return m_winSize;
	}

	/**
		@brief		ウィンドウの幅を整数値として取得
		@param[in]	なし
		@return		ウィンドウ幅
	*/
	int GetWinWidth() const
	{
		return static_cast<int>(m_winSize.width);
	}

	/**
		@brief		ウィンドウの高さを整数値として取得
		@param[in]	なし
		@return		ウィンドウ高
	*/
	int GetWinHeight() const
	{
		return static_cast<int>(m_winSize.height);
	}

	//------------------------------------------------
protected:

	//------------------------------------------------
private:
	
	//=====================================================
	// 変数宣言
	//=====================================================
//public:
protected:
private:
	static ns_Math::Size	m_winSize;

};
NS_DLG_END	// namespace ns_DxLibGame

#endif	// __REF_H__