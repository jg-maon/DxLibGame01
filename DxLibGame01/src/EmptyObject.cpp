/**=============================================================================
	@file		EmptyObject.cpp
	@brief		空オブジェクトクラス 実装
	@author		Masato Yamamoto
	@date		2015-03-01

	@par		[説明]
				空オブジェクトクラス実装

	@note

		Copyright (C) 2015  M.Yamamoto
=============================================================================*/
#include "EmptyObject.h"
#include "FileLoader.h"

NS_DLG_BEGIN

#pragma region EmptyObject public methods
/**
	@brief		コンストラクタ
	@param[in]	なし
	@return		なし
*/
EmptyObject::EmptyObject()
: Object("EmptyObject")
{

}
		
/**
	@brief		デストラクタ
	@param[in]	なし
	@return		なし
*/
EmptyObject::~EmptyObject()
{

}	
/**
	@brief		描画
	@param[in]	delta	フレームタイム
	@return		なし
*/
inline void EmptyObject::Draw(float delta)
{
	// 何もしない

}

/**
	@brief		オブジェクトのハンドルの取得
	@param[in]	なし
	@return		オブジェクトハンドル
	@retval		FileLoader::<unnamed>::INVALID_HANDLE	ハンドル無し
	@retval		↑以外		オブジェクトハンドル(画像ハンドル、モデルハンドル)
*/
inline int EmptyObject::GetHandle() const
{
	// ハンドルなし
	return FileLoader::INVALID_HANDLE;
}

#pragma endregion	// EmptyObject public methods

//------------------------------------------------
#pragma region EmptyObject protected methods


#pragma endregion	// EmptyObject protected methods
//------------------------------------------------

#pragma region EmptyObject private methods


#pragma endregion	// EmptyObject private methods


NS_DLG_END	// namespace ns_DxLibGame