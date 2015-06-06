/**=============================================================================
	@file		FileLoader.cpp
	@brief		ファイル読み込みクラス 実装
	@author		Masato Yamamoto
	@date		2015-03-02

	@par		[説明]
				ファイル読み込みクラス実装


	@note

		Copyright (C) 2015  M.Yamamoto
=============================================================================*/
#include "FileLoader.h"
#include <sstream>

NS_DLG_BEGIN

#pragma region FileLoader public methods

/**
	@brief		インスタンスの取得
	@param[in]	なし
	@return		インスタンス
*/
FileLoader* FileLoader::GetInstance()
{
	static FileLoader fileLoader;
	return &fileLoader;
}
		
/**
	@brief		デストラクタ
	@param[in]	なし
	@return		なし
*/
FileLoader::~FileLoader()
{
	//---------------------------
	// 画像ハンドルの解放
	InitGraph();
	m_imageHandles.clear();
	//---------------------------
	// モデルハンドルの解放
	MV1InitModel();
	m_modelHandles.clear();
	//---------------------------
}

/**
	@brief		画像データの読み込み
	@param[in]	fileName	ファイル名
	@return		画像ハンドル
*/
int FileLoader::LoadGraph(const ::std::string& fileName)
{
	int handle;
	if (m_imageHandles.count(fileName) == 0)
	{
		m_imageHandles[fileName] = DxLib::LoadGraph(fileName.c_str());
		handle = m_imageHandles[fileName];
		if (handle == -1)
		{
			// 読み込みエラー
			handle = FileLoader::INVALID_HANDLE;
			// エラーメッセージ
			::std::stringstream msg;
			msg << "LoadImage error file:" << fileName;
			MessageBox(DxLib::GetMainWindowHandle(), msg.str().c_str(), "FileLoader error", MB_ICONERROR);
		}
	}
	else
	{
		handle = m_imageHandles[fileName];
	}
	return handle;
}

/**
	@brief		モデルデータの読み込み
	@param[in]	fileName	ファイル名
	@return		モデルハンドル
*/
int FileLoader::LoadModel(const ::std::string& fileName)
{
	int handle;
	if (m_modelHandles.count(fileName) == 0)
	{
		m_modelHandles[fileName] = DxLib::MV1LoadModel(fileName.c_str());
		handle = m_modelHandles[fileName];
	}
	else
	{
		handle = DxLib::MV1DuplicateModel(m_modelHandles[fileName]);
	}
	if (handle == -1)
	{
		// 読み込みエラー
		handle = FileLoader::INVALID_HANDLE;
		// エラーメッセージ
		::std::stringstream msg;
		msg << "LoadModel error file:" << fileName;
		MessageBox(DxLib::GetMainWindowHandle(), msg.str().c_str(), "FileLoader error", MB_ICONERROR);
	}
	return handle;
}

#pragma endregion	// FileLoader public methods

//------------------------------------------------
#pragma region FileLoader protected methods

#pragma endregion	// FileLoader protected methods
//------------------------------------------------

#pragma region FileLoader private methods


/**
	@brief		コンストラクタ
	@param[in]	なし
	@return		なし
*/
FileLoader::FileLoader()
{

}

#pragma endregion	// FileLoader private methods


NS_DLG_END	// namespace ns_DxLibGame