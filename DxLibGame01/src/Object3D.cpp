/**=============================================================================
	@file		Object3D.cpp
	@brief		3D�I�u�W�F�N�g�N���X ����
	@author		Masato Yamamoto
	@date		2015-03-01

	@par		[����]
				3D�I�u�W�F�N�g�N���X����

	@note

		Copyright (C) 2015  M.Yamamoto
=============================================================================*/
#include "Object3D.h"
#include "FileLoader.h"

NS_DLG_BEGIN

#pragma region Object3D public methods
/**
	@brief		�R���X�g���N�^
	@param[in]	fileName	�I�u�W�F�N�g�t�@�C����
	@return		�Ȃ�
*/
Object3D::Object3D(const ::std::string& fileName)
{
	_InitWithFile(fileName);
}
		
/**
	@brief		�R���X�g���N�^
	@param[in]	fileName	�I�u�W�F�N�g�t�@�C����
	@param[in]	name	�I�u�W�F�N�g��
	@return		�Ȃ�
*/
Object3D::Object3D(const ::std::string& fileName, const ::std::string& name)
	: Object(name)
{
	_InitWithFile(fileName);
}

		
/**
	@brief		�f�X�g���N�^
	@param[in]	�Ȃ�
	@return		�Ȃ�
*/
Object3D::~Object3D()
{

}	
/**
	@brief		�`��
	@param[in]	delta	�t���[���^�C��
	@return		�Ȃ�
*/
void Object3D::Draw(float delta)
{
	// ���f���\��
	MV1DrawModel(this->GetHandle());
}

#pragma endregion	// Object3D public methods

//------------------------------------------------
#pragma region Object3D protected methods

/**
	@brief		�I�u�W�F�N�g�̏�����
	@param[in]	fileName	�t�@�C����
	@retrun		�Ȃ�
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