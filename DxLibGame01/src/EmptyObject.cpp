/**=============================================================================
	@file		EmptyObject.cpp
	@brief		��I�u�W�F�N�g�N���X ����
	@author		Masato Yamamoto
	@date		2015-03-01

	@par		[����]
				��I�u�W�F�N�g�N���X����

	@note

		Copyright (C) 2015  M.Yamamoto
=============================================================================*/
#include "EmptyObject.h"
#include "FileLoader.h"

NS_DLG_BEGIN

#pragma region EmptyObject public methods
/**
	@brief		�R���X�g���N�^
	@param[in]	�Ȃ�
	@return		�Ȃ�
*/
EmptyObject::EmptyObject()
: Object("EmptyObject")
{

}
		
/**
	@brief		�f�X�g���N�^
	@param[in]	�Ȃ�
	@return		�Ȃ�
*/
EmptyObject::~EmptyObject()
{

}	
/**
	@brief		�`��
	@param[in]	delta	�t���[���^�C��
	@return		�Ȃ�
*/
inline void EmptyObject::Draw(float delta)
{
	// �������Ȃ�

}

/**
	@brief		�I�u�W�F�N�g�̃n���h���̎擾
	@param[in]	�Ȃ�
	@return		�I�u�W�F�N�g�n���h��
	@retval		FileLoader::<unnamed>::INVALID_HANDLE	�n���h������
	@retval		���ȊO		�I�u�W�F�N�g�n���h��(�摜�n���h���A���f���n���h��)
*/
inline int EmptyObject::GetHandle() const
{
	// �n���h���Ȃ�
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