/**=============================================================================
	@file		Object3D.h
	@brief		3Dオブジェクトクラス 定義
	@author		Masato Yamamoto
	@date		2015-03-01

	@par		[説明]
				3Dオブジェクトクラス定義

	@note

		Copyright (C) 2015  M.Yamamoto
=============================================================================*/
#ifndef __OBJECT_3D_H__
#define __OBJECT_3D_H__

#ifndef __DXLIB_GAME_H__
#include "DxLibGame.h"
#endif

#ifndef __OBJECT_H__
#include "Object.h"
#endif

#ifndef __MATH_H__
#include "Math.h"
#endif


NS_DLG_BEGIN
/**
	@class		Object3D
	@brief		3Dオブジェクトクラス
*/
class Object3D : public Object
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
		@param[in]	fileName	オブジェクトファイル名
		@return		なし
	*/
	Object3D(const ::std::string& fileName);
		
	/**
		@brief		コンストラクタ
		@param[in]	fileName	オブジェクトファイル名
		@param[in]	name	オブジェクト名
		@return		なし
	*/
	Object3D(const ::std::string& fileName, const ::std::string& name);

	/**
		@brief		デストラクタ
		@param[in]	なし
		@return		なし
	*/
	virtual ~Object3D();
		
	/**
		@brief		描画
		@param[in]	delta	フレームタイム
		@return		なし
	*/
	virtual void Draw(float delta) override;
	
	/**
		@brief		オブジェクトのハンドルの取得
		@param[in]	なし
		@return		オブジェクトハンドル
		@retval		FileLoader::<unnamed>::INVALID_HANDLE	ハンドル無し
		@retval		↑以外		オブジェクトハンドル(画像ハンドル、モデルハンドル)
	*/
	virtual int GetHandle() const override
	{
		return m_modelHandle;
	}


	
	/**
		@brief		座標の設定
		@param[in]	position	座標
		@return		なし
	*/
	virtual void SetPosition(const ns_Math::Vector3& position) override
	{
		DxLib::MV1SetPosition(m_modelHandle, position);
	}

	/**
		@brief		座標の取得
		@param[in]	なし
		@return		座標
	*/
	virtual ns_Math::Vector3 GetPosition() const override
	{
		return DxLib::MV1GetPosition(m_modelHandle);
	}

	/**
		@brief		拡大率の設定
		@param[in]	scale	拡大率
		@return		なし
	*/
	virtual void SetScale(const ns_Math::Vector3& scale) override
	{
		DxLib::MV1SetScale(m_modelHandle, scale);
	}

	/**
		@brief		拡大率の取得
		@param[in]	なし
		@return		拡大率
	*/
	virtual ns_Math::Vector3 GetScale() const override
	{
		return DxLib::MV1GetScale(m_modelHandle);
	}

	/**
		@brief		回転角の設定
		@param[in]	rotation	回転角
		@return		なし
	*/
	virtual void SetRotation(const ns_Math::Vector3& rotation) override
	{
		DxLib::MV1SetRotationXYZ(m_modelHandle, rotation);
	}


	/**
		@brief		回転角の取得
		@param[in]	なし
		@return		回転角
	*/
	virtual ns_Math::Vector3 GetRotation() const override
	{
		return DxLib::MV1GetRotationXYZ(m_modelHandle);
	}

	
	/**	
		@brief		描画設定
		@param[in]	isVisible	描画するか
		@return		なし
	*/
	virtual void SetVisible(bool isVisible) override
	{
		DxLib::MV1SetVisible(m_modelHandle, isVisible);
	}

	
	/**	
		@brief		描画設定の取得
		@param[in]	なし
		@return		描画するか
		@retval		true		描画する
		@retval		false		描画しない
	*/
	virtual bool GetVisible() const override
	{
		return DxLib::MV1GetVisible(m_modelHandle) == TRUE;
	}

	//------------------------------------------------
protected:

	/**
		@brief		オブジェクトの初期化
		@param[in]	fileName	ファイル名
		@retrun		なし
	*/
	virtual void _InitWithFile(const ::std::string& fileName);

	//------------------------------------------------
private:

	//=====================================================
	// 変数宣言
	//=====================================================
//public:
protected:

private:
	int			m_modelHandle;			//!< モデルハンドル

};


NS_DLG_END	// namespace ns_DxLibGame

#endif	// __OBJECT_3D_H__