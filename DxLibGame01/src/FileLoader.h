/**=============================================================================
	@file		FileLoader.h
	@brief		�t�@�C���ǂݍ��݃N���X ��`
	@author		Masato Yamamoto
	@date		2015-03-02

	@par		[����]
				�t�@�C���ǂݍ��݃N���X��`


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
	@brief		�N���X�e���v���[�g
*/
class FileLoader : public Ref
{
	//=====================================================
	// �萔(�񋓌^)�錾
	//=====================================================
public:
	enum
	{
		INVALID_HANDLE = -1,	//!< �����ȃn���h��
	};
	//=====================================================
	// �����N���X�錾
	//=====================================================
public:
	//=====================================================
	// �^�ʖ���`
	//=====================================================
public:

	//=====================================================
	// �ÓI���\�b�h�錾
	//=====================================================
public:
	/**
		@brief		�C���X�^���X�̎擾
		@param[in]	�Ȃ�
		@return		�C���X�^���X
	*/
	static FileLoader* GetInstance();
	//=====================================================
	// ���\�b�h�錾
	//=====================================================
public:

	FileLoader(const FileLoader&) = delete;
	
		
	/**
		@brief		�f�X�g���N�^
		@param[in]	�Ȃ�
		@return		�Ȃ�
	*/
	virtual ~FileLoader();
	
	
	/**
		@brief		�摜�̓ǂݍ���
		@param[in]	fileName	�t�@�C����
		@return		�摜�n���h��
	*/
	int LoadGraph(const ::std::string& fileName);

	/**
		@brief		���f���f�[�^�̓ǂݍ���
		@param[in]	fileName	�t�@�C����
		@return		���f���n���h��
	*/
	int LoadModel(const ::std::string& fileName);


	//------------------------------------------------
protected:

	//------------------------------------------------
private:
	/**
		@brief		�R���X�g���N�^
		@param[in]	�Ȃ�
		@return		�Ȃ�
	*/
	FileLoader();
	
	//=====================================================
	// �ϐ��錾
	//=====================================================
//public:
protected:

private:
	::std::unordered_map<::std::string, int>		m_imageHandles;		//!< �摜�n���h���f�[�^
	::std::unordered_map<::std::string, int>		m_modelHandles;		//!< ���f���n���h���f�[�^
};


NS_DLG_END	// namespace ns_DxLibGame

#endif	// __FILE_LOADER_H__