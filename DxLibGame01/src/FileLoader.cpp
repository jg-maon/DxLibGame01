/**=============================================================================
	@file		FileLoader.cpp
	@brief		�t�@�C���ǂݍ��݃N���X ����
	@author		Masato Yamamoto
	@date		2015-03-02

	@par		[����]
				�t�@�C���ǂݍ��݃N���X����


	@note

		Copyright (C) 2015  M.Yamamoto
=============================================================================*/
#include "FileLoader.h"
#include <sstream>

NS_DLG_BEGIN

#pragma region FileLoader public methods

/**
	@brief		�C���X�^���X�̎擾
	@param[in]	�Ȃ�
	@return		�C���X�^���X
*/
FileLoader* FileLoader::GetInstance()
{
	static FileLoader fileLoader;
	return &fileLoader;
}
		
/**
	@brief		�f�X�g���N�^
	@param[in]	�Ȃ�
	@return		�Ȃ�
*/
FileLoader::~FileLoader()
{
	//---------------------------
	// �摜�n���h���̉��
	InitGraph();
	m_imageHandles.clear();
	//---------------------------
	// ���f���n���h���̉��
	MV1InitModel();
	m_modelHandles.clear();
	//---------------------------
}

/**
	@brief		�摜�f�[�^�̓ǂݍ���
	@param[in]	fileName	�t�@�C����
	@return		�摜�n���h��
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
			// �ǂݍ��݃G���[
			handle = FileLoader::INVALID_HANDLE;
			// �G���[���b�Z�[�W
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
	@brief		���f���f�[�^�̓ǂݍ���
	@param[in]	fileName	�t�@�C����
	@return		���f���n���h��
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
		// �ǂݍ��݃G���[
		handle = FileLoader::INVALID_HANDLE;
		// �G���[���b�Z�[�W
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
	@brief		�R���X�g���N�^
	@param[in]	�Ȃ�
	@return		�Ȃ�
*/
FileLoader::FileLoader()
{

}

#pragma endregion	// FileLoader private methods


NS_DLG_END	// namespace ns_DxLibGame