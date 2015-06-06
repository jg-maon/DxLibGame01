/**=============================================================================
	@file		ClassTemplate.cpp
	@brief		�N���X�L�q��N���X ����
	@author		Masato Yamamoto
	@date		2015-02-20

	@par		[����]
				�N���X��`�t�@�C���̋L�q��

	@note

		Copyright (C) 2015  M.Yamamoto
=============================================================================*/
#include "ClassTemplate.h"

NS_DLG_BEGIN

#pragma region ClassTemplate public methods
/**
	@brief		�R���X�g���N�^
	@param[in]	�Ȃ�
	@return		�Ȃ�
*/
ClassTemplate::ClassTemplate()
{

}
		
/**
	@brief		�f�X�g���N�^
	@param[in]	�Ȃ�
	@return		�Ȃ�
*/
ClassTemplate::~ClassTemplate()
{

}
		
/**
	@brief		�֐��̊T�v
	@param[in]	�Ȃ�
	@return		�Ȃ�
*/
void ClassTemplate::PublicMethod()
{

}

#pragma endregion	// ClassTemplate public methods

//------------------------------------------------
#pragma region ClassTemplate protected methods
/**
	@brief		�֐��̊T�v
	@param[in]	param		�����̐���
	@return		�߂�l�̐���
	@retval		0	���퐬��
	@retval		-1	�G���[
*/
int ClassTemplate::_ProtectedMethod(int param)
{
	return 0;
}


#pragma endregion	// ClassTemplate protected methods
//------------------------------------------------

#pragma region ClassTemplate private methods
/**
	@brief		�֐��̊T�v
	@param[in]	param		�����̐���
	@return		�߂�l�̐���
	@retval		-1	�G���[
*/
int ClassTemplate::_PrivateMethod(int param)
{
	return 0;
}


#pragma endregion	// ClassTemplate private methods


NS_DLG_END	// namespace ns_DxLibGame