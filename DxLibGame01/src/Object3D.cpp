/**=============================================================================
	@file		Object3D.cpp
	@brief		3Dオブジェクトクラス 実装
	@author		Masato Yamamoto
	@date		2015-03-01

	@par		[説明]
				3Dオブジェクトクラス実装

	@note

		Copyright (C) 2015  M.Yamamoto
=============================================================================*/
#include "Object3D.h"
#include "FileLoader.h"

NS_DLG_BEGIN

#pragma region Object3D public methods
/**
	@brief		コンストラクタ
	@param[in]	fileName	オブジェクトファイル名
	@return		なし
*/
Object3D::Object3D(const ::std::string& fileName)
{
	_InitWithFile(fileName);
}
		
/**
	@brief		コンストラクタ
	@param[in]	fileName	オブジェクトファイル名
	@param[in]	name	オブジェクト名
	@return		なし
*/
Object3D::Object3D(const ::std::string& fileName, const ::std::string& name)
	: Object(name)
{
	_InitWithFile(fileName);
}

		
/**
	@brief		デストラクタ
	@param[in]	なし
	@return		なし
*/
Object3D::~Object3D()
{

}	
/**
	@brief		描画
	@param[in]	delta	フレームタイム
	@return		なし
*/
void Object3D::Draw(float delta)
{
	// モデル表示
	MV1DrawModel(this->GetHandle());
}

#pragma endregion	// Object3D public methods

//------------------------------------------------
#pragma region Object3D protected methods

/**
	@brief		オブジェクトの初期化
	@param[in]	fileName	ファイル名
	@retrun		なし
*/
void Object3D::_InitWithFile(const ::std::string& fileName)
{
	m_modelHandle = FileLoader::GetInstance()->LoadModel(fileName);
}

#pragma endregion	// Object3D protected methods
//------------------------------------------------

#pragma region Object3D private methods


#pragma endregion	// Object3D private methods


NS_DLG_END	// namespace ns_DxLibGame