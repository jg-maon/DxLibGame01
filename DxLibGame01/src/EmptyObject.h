/**=============================================================================
	@file		EmptyObject.h
	@brief		空オブジェクトクラス 定義
	@author		Masato Yamamoto
	@date		2015-03-01

	@par		[説明]
				空オブジェクトクラス定義

	@note

		Copyright (C) 2015  M.Yamamoto
=============================================================================*/
#ifndef __EMPTY_OBJECT_H__
#define __EMPTY_OBJECT_H__

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
	@class		EmptyObject
	@brief		空3Dオブジェクトクラス
*/
class EmptyObject : public Object
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
	EmptyObject();
		
	/**
		@brief		デストラクタ
		@param[in]	なし
		@return		なし
	*/
	virtual ~EmptyObject();
		
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
	virtual int GetHandle() const override;


	
	/**
		@brief		座標の設定
		@param[in]	position	座標
		@return		なし
	*/
	virtual void SetPosition(const ns_Math::Vector3& position) override
	{
		m_position = position;
	}

	/**
		@brief		座標の取得
		@param[in]	なし
		@return		座標
	*/
	virtual ns_Math::Vector3 GetPosition() const override
	{
		return m_position;
	}

	/**
		@brief		拡大率の設定
		@param[in]	scale	拡大率
		@return		なし
	*/
	virtual void SetScale(const ns_Math::Vector3& scale) override
	{
		m_scale = scale;
	}

	/**
		@brief		拡大率の取得
		@param[in]	なし
		@return		拡大率
	*/
	virtual ns_Math::Vector3 GetScale() const override
	{
		return m_scale;
	}

	/**
		@brief		回転角の設定
		@param[in]	rotation	回転角
		@return		なし
	*/
	virtual void SetRotation(const ns_Math::Vector3& rotation) override
	{
		m_rotation = rotation;
	}


	/**
		@brief		回転角の取得
		@param[in]	なし
		@return		回転角
	*/
	virtual ns_Math::Vector3 GetRotation() const override
	{
		return m_rotation;
	}

	
	/**	
		@brief		描画設定
		@param[in]	isVisible	描画するか
		@return		なし
	*/
	virtual void SetVisible(bool isVisible) override
	{
		// 何もしない
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
		// 表示しない
		return false;
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
	ns_Math::Vector		m_position;			//!< 座標
	ns_Math::Vector		m_scale;			//!< 拡大率
	ns_Math::Vector		m_rotation;			//!< 回転角


private:

};


NS_DLG_END	// namespace ns_DxLibGame

#endif	// __EMPTY_OBJECT_H__