/**=============================================================================
	@file		ClassTemplate.cpp
	@brief		クラス記述例クラス 実装
	@author		Masato Yamamoto
	@date		2015-02-20

	@par		[説明]
				クラス定義ファイルの記述例

	@note

		Copyright (C) 2015  M.Yamamoto
=============================================================================*/
#include "ClassTemplate.h"

NS_DLG_BEGIN

#pragma region ClassTemplate public methods
/**
	@brief		コンストラクタ
	@param[in]	なし
	@return		なし
*/
ClassTemplate::ClassTemplate()
{

}
		
/**
	@brief		デストラクタ
	@param[in]	なし
	@return		なし
*/
ClassTemplate::~ClassTemplate()
{

}
		
/**
	@brief		関数の概要
	@param[in]	なし
	@return		なし
*/
void ClassTemplate::PublicMethod()
{

}

#pragma endregion	// ClassTemplate public methods

//------------------------------------------------
#pragma region ClassTemplate protected methods
/**
	@brief		関数の概要
	@param[in]	param		引数の説明
	@return		戻り値の説明
	@retval		0	正常成功
	@retval		-1	エラー
*/
int ClassTemplate::_ProtectedMethod(int param)
{
	return 0;
}


#pragma endregion	// ClassTemplate protected methods
//------------------------------------------------

#pragma region ClassTemplate private methods
/**
	@brief		関数の概要
	@param[in]	param		引数の説明
	@return		戻り値の説明
	@retval		-1	エラー
*/
int ClassTemplate::_PrivateMethod(int param)
{
	return 0;
}


#pragma endregion	// ClassTemplate private methods


NS_DLG_END	// namespace ns_DxLibGame