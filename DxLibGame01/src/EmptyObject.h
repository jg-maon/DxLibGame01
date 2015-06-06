/**=============================================================================
	@file		EmptyObject.h
	@brief		��I�u�W�F�N�g�N���X ��`
	@author		Masato Yamamoto
	@date		2015-03-01

	@par		[����]
				��I�u�W�F�N�g�N���X��`

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
	@brief		��3D�I�u�W�F�N�g�N���X
*/
class EmptyObject : public Object
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
		@param[in]	�Ȃ�
		@return		�Ȃ�
	*/
	EmptyObject();
		
	/**
		@brief		�f�X�g���N�^
		@param[in]	�Ȃ�
		@return		�Ȃ�
	*/
	virtual ~EmptyObject();
		
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
	virtual int GetHandle() const override;


	
	/**
		@brief		���W�̐ݒ�
		@param[in]	position	���W
		@return		�Ȃ�
	*/
	virtual void SetPosition(const ns_Math::Vector3& position) override
	{
		m_position = position;
	}

	/**
		@brief		���W�̎擾
		@param[in]	�Ȃ�
		@return		���W
	*/
	virtual ns_Math::Vector3 GetPosition() const override
	{
		return m_position;
	}

	/**
		@brief		�g�嗦�̐ݒ�
		@param[in]	scale	�g�嗦
		@return		�Ȃ�
	*/
	virtual void SetScale(const ns_Math::Vector3& scale) override
	{
		m_scale = scale;
	}

	/**
		@brief		�g�嗦�̎擾
		@param[in]	�Ȃ�
		@return		�g�嗦
	*/
	virtual ns_Math::Vector3 GetScale() const override
	{
		return m_scale;
	}

	/**
		@brief		��]�p�̐ݒ�
		@param[in]	rotation	��]�p
		@return		�Ȃ�
	*/
	virtual void SetRotation(const ns_Math::Vector3& rotation) override
	{
		m_rotation = rotation;
	}


	/**
		@brief		��]�p�̎擾
		@param[in]	�Ȃ�
		@return		��]�p
	*/
	virtual ns_Math::Vector3 GetRotation() const override
	{
		return m_rotation;
	}

	
	/**	
		@brief		�`��ݒ�
		@param[in]	isVisible	�`�悷�邩
		@return		�Ȃ�
	*/
	virtual void SetVisible(bool isVisible) override
	{
		// �������Ȃ�
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
		// �\�����Ȃ�
		return false;
	}

	//------------------------------------------------
protected:


	//------------------------------------------------
private:

	//=====================================================
	// �ϐ��錾
	//=====================================================
//public:
protected:
	ns_Math::Vector		m_position;			//!< ���W
	ns_Math::Vector		m_scale;			//!< �g�嗦
	ns_Math::Vector		m_rotation;			//!< ��]�p


private:

};


NS_DLG_END	// namespace ns_DxLibGame

#endif	// __EMPTY_OBJECT_H__