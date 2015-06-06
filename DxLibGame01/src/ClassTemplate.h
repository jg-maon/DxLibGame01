/**=============================================================================
	@file		ClassTemplate.h
	@brief		クラス記述例クラス 定義
	@author		Masato Yamamoto
	@date		2015-02-20

	@par		[説明]
				クラス定義ファイルの記述例

	@note

		Copyright (C) 2015  M.Yamamoto
=============================================================================*/
#ifndef __CLASS_TEMPLATE_H__
#define __CLASS_TEMPLATE_H__

#ifndef __DXLIB_GAME_H__
#include "DxLibGame.h"
#endif

#ifndef __REF_H__
#include "Ref.h"
#endif

NS_DLG_BEGIN
/**
	@class		ClassTemplate
	@brief		クラステンプレート
*/
class ClassTemplate : public Ref
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
	ClassTemplate();
		
	/**
		@brief		デストラクタ
		@param[in]	なし
		@return		なし
	*/
	virtual ~ClassTemplate();
		
	/**
		@brief		関数の概要
		@param[in]	なし
		@return		なし
	*/
	void PublicMethod();

	//------------------------------------------------
protected:
	/**
		@brief		関数の概要
		@param[in]	param		引数の説明
		@return		戻り値の説明
		@retval		0	正常成功
		@retval		-1	エラー
	*/
	int _ProtectedMethod(int param);


	//------------------------------------------------
private:
	/**
		@brief		関数の概要
		@param[in]	param		引数の説明
		@return		戻り値の説明
		@retval		-1	エラー
	*/
	int _PrivateMethod(int param);

	//=====================================================
	// 変数宣言
	//=====================================================
//public:
protected:

private:

};


NS_DLG_END	// namespace ns_DxLibGame

#endif	// __CLASS_TEMPLATE_H__