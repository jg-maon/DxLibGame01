/**=============================================================================
	@file		FileLoader.h
	@brief		ファイル読み込みクラス 定義
	@author		Masato Yamamoto
	@date		2015-03-02

	@par		[説明]
				ファイル読み込みクラス定義


	@note

		Copyright (C) 2015  M.Yamamoto
=============================================================================*/
#ifndef __FILE_LOADER_H__
#define __FILE_LOADER_H__

#ifndef __DXLIB_GAME_H__
#include "DxLibGame.h"
#endif

#ifndef __REF_H__
#include "Ref.h"
#endif

#ifndef _UNORDERED_MAP_
#include <unordered_map>
#endif

NS_DLG_BEGIN
/**
	@class		FileLoader
	@brief		クラステンプレート
*/
class FileLoader : public Ref
{
	//=====================================================
	// 定数(列挙型)宣言
	//=====================================================
public:
	enum
	{
		INVALID_HANDLE = -1,	//!< 無効なハンドル
	};
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
	/**
		@brief		インスタンスの取得
		@param[in]	なし
		@return		インスタンス
	*/
	static FileLoader* GetInstance();
	//=====================================================
	// メソッド宣言
	//=====================================================
public:

	FileLoader(const FileLoader&) = delete;
	
		
	/**
		@brief		デストラクタ
		@param[in]	なし
		@return		なし
	*/
	virtual ~FileLoader();
	
	
	/**
		@brief		画像の読み込み
		@param[in]	fileName	ファイル名
		@return		画像ハンドル
	*/
	int LoadGraph(const ::std::string& fileName);

	/**
		@brief		モデルデータの読み込み
		@param[in]	fileName	ファイル名
		@return		モデルハンドル
	*/
	int LoadModel(const ::std::string& fileName);


	//------------------------------------------------
protected:

	//------------------------------------------------
private:
	/**
		@brief		コンストラクタ
		@param[in]	なし
		@return		なし
	*/
	FileLoader();
	
	//=====================================================
	// 変数宣言
	//=====================================================
//public:
protected:

private:
	::std::unordered_map<::std::string, int>		m_imageHandles;		//!< 画像ハンドルデータ
	::std::unordered_map<::std::string, int>		m_modelHandles;		//!< モデルハンドルデータ
};


NS_DLG_END	// namespace ns_DxLibGame

#endif	// __FILE_LOADER_H__