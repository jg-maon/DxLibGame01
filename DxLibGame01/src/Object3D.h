/**=============================================================================
	@file		Object3D.h
	@brief		3D�I�u�W�F�N�g�N���X ��`
	@author		Masato Yamamoto
	@date		2015-03-01

	@par		[����]
				3D�I�u�W�F�N�g�N���X��`

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
	@brief		3D�I�u�W�F�N�g�N���X
*/
class Object3D : public Object
{
	//=====================================================
	// �萔(�񋓌^)�錾
	//=====================================================
public:
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

	//=====================================================
	// ���\�b�h�錾
	//=====================================================
public:
	/**
		@brief		�R���X�g���N�^
		@param[in]	fileName	�I�u�W�F�N�g�t�@�C����
		@return		�Ȃ�
	*/
	Object3D(const ::std::string& fileName);
		
	/**
		@brief		�R���X�g���N�^
		@param[in]	fileName	�I�u�W�F�N�g�t�@�C����
		@param[in]	name	�I�u�W�F�N�g��
		@return		�Ȃ�
	*/
	Object3D(const ::std::string& fileName, const ::std::string& name);

	/**
		@brief		�f�X�g���N�^
		@param[in]	�Ȃ�
		@return		�Ȃ�
	*/
	virtual ~Object3D();
		
	/**
		@brief		�`��
		@param[in]	delta	�t���[���^�C��
		@return		�Ȃ�
	*/
	virtual void Draw(float delta) override;
	
	/**
		@brief		�I�u�W�F�N�g�̃n���h���̎擾
		@param[in]	�Ȃ�
		@return		�I�u�W�F�N�g�n���h��
		@retval		FileLoader::<unnamed>::INVALID_HANDLE	�n���h������
		@retval		���ȊO		�I�u�W�F�N�g�n���h��(�摜�n���h���A���f���n���h��)
	*/
	virtual int GetHandle() const override
	{
		return m_modelHandle;
	}


	
	/**
		@brief		���W�̐ݒ�
		@param[in]	position	���W
		@return		�Ȃ�
	*/
	virtual void SetPosition(const ns_Math::Vector3& position) override
	{
		DxLib::MV1SetPosition(m_modelHandle, position);
	}

	/**
		@brief		���W�̎擾
		@param[in]	�Ȃ�
		@return		���W
	*/
	virtual ns_Math::Vector3 GetPosition() const override
	{
		return DxLib::MV1GetPosition(m_modelHandle);
	}

	/**
		@brief		�g�嗦�̐ݒ�
		@param[in]	scale	�g�嗦
		@return		�Ȃ�
	*/
	virtual void SetScale(const ns_Math::Vector3& scale) override
	{
		DxLib::MV1SetScale(m_modelHandle, scale);
	}

	/**
		@brief		�g�嗦�̎擾
		@param[in]	�Ȃ�
		@return		�g�嗦
	*/
	virtual ns_Math::Vector3 GetScale() const override
	{
		return DxLib::MV1GetScale(m_modelHandle);
	}

	/**
		@brief		��]�p�̐ݒ�
		@param[in]	rotation	��]�p
		@return		�Ȃ�
	*/
	virtual void SetRotation(const ns_Math::Vector3& rotation) override
	{
		DxLib::MV1SetRotationXYZ(m_modelHandle, rotation);
	}


	/**
		@brief		��]�p�̎擾
		@param[in]	�Ȃ�
		@return		��]�p
	*/
	virtual ns_Math::Vector3 GetRotation() const override
	{
		return DxLib::MV1GetRotationXYZ(m_modelHandle);
	}

	
	/**	
		@brief		�`��ݒ�
		@param[in]	isVisible	�`�悷�邩
		@return		�Ȃ�
	*/
	virtual void SetVisible(bool isVisible) override
	{
		DxLib::MV1SetVisible(m_modelHandle, isVisible);
	}

	
	/**	
		@brief		�`��ݒ�̎擾
		@param[in]	�Ȃ�
		@return		�`�悷�邩
		@retval		true		�`�悷��
		@retval		false		�`�悵�Ȃ�
	*/
	virtual bool GetVisible() const override
	{
		return DxLib::MV1GetVisible(m_modelHandle) == TRUE;
	}

	//------------------------------------------------
protected:

	/**
		@brief		�I�u�W�F�N�g�̏�����
		@param[in]	fileName	�t�@�C����
		@retrun		�Ȃ�
	*/
	virtual void _InitWithFile(const ::std::string& fileName);

	//------------------------------------------------
private:

	//=====================================================
	// �ϐ��錾
	//=====================================================
//public:
protected:

private:
	int			m_modelHandle;			//!< ���f���n���h��

};


NS_DLG_END	// namespace ns_DxLibGame

#endif	// __OBJECT_3D_H__