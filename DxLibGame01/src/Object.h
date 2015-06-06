/**=============================================================================
	@file		Object.h
	@brief		�I�u�W�F�N�g��{�N���X ��`
	@author		Masato Yamamoto
	@date		2015-02-20

	@par		[����]
				�I�u�W�F�N�g��{�N���X��`

	@note

		Copyright (C) 2015  M.Yamamoto
=============================================================================*/

#ifndef __OBJECT_H__
#define __OBJECT_H__

#ifndef __DXLIB_GAME_H__
#include "DxLibGame.h"
#endif

#ifndef __REF_H__
#include "Ref.h"
#endif

#ifndef _VECTOR_
#include <vector>
#endif

#ifndef _MEMORY_
#include <memory>
#endif


#ifndef __MATH_H__
#include "Math.h"
#endif

NS_DLG_BEGIN
/**
	@class		Object
	@brief		�N���X�e���v���[�g
*/
class Object : public Ref
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
	typedef Object super;
	typedef std::shared_ptr<Object> _Ptr;
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
	Object();
	/**
		@brief		�R���X�g���N�^
		@param[in]	name	���O
		@return		�Ȃ�
	*/
	Object(const ::std::string& name);
	
		
	/**
		@brief		�f�X�g���N�^
		@param[in]	�Ȃ�
		@return		�Ȃ�
	*/
	~Object();
	

	/**
		@brief		�X�V
		@param[in]	delta	�t���[���^�C��
		@return		�Ȃ�
	*/
	virtual void Update(float delta);

	
	/**
		@brief		�`��
		@param[in]	delta	�t���[���^�C��
		@return		�Ȃ�
	*/
	virtual void Draw(float delta) = 0;
	
	/**
		@brief		�q�I�u�W�F�N�g�܂ߕ`��
		@param[in]	delta	�t���[���^�C��
		@return		�Ȃ�
	*/
	virtual void Visit(float delta) final;

	/**
		@brief		�I�u�W�F�N�g���̐ݒ�
		@param[in]	name	�I�u�W�F�N�g��
		@return		�Ȃ�
	*/
	void SetName(const ::std::string& name)
	{
		m_name = name;
	}
	
	/**
		@brief		�q�I�u�W�F�N�g�̒ǉ�
		@param[in]	child	�q�I�u�W�F�N�g
		@return		�Ȃ�
	*/
	void AddChild(const _Ptr& child);
	
	/**
		@brief		�q�I�u�W�F�N�g�̒ǉ�
		@param[in]	child	�q�I�u�W�F�N�g
		@param[in]	name	�q�I�u�W�F�N�g�̖��O
		@return		�Ȃ�
	*/
	void AddChild(const _Ptr& child, const ::std::string& name);
	/**
		@brief		�q�I�u�W�F�N�g�̑����ǉ�
		@attention	�q�I�u�W�F�N�g�̃��[�v���ɌĂяo���ƃ������Ĕz�u�G���[���o��
		@param[in]	child	�q�I�u�W�F�N�g
		@return		�Ȃ�
	*/
	void AddChildInstant(const _Ptr& child);
	/**
		@brief		�q�I�u�W�F�N�g�̑����ǉ�
		@attention	�q�I�u�W�F�N�g�̃��[�v���ɌĂяo���ƃ������Ĕz�u�G���[���o��
		@param[in]	child	�q�I�u�W�F�N�g
		@param[in]	name	�q�I�u�W�F�N�g�̖��O
		@return		�Ȃ�
	*/
	void AddChildInstant(const _Ptr& child, const ::std::string& name);

	/**
		@brief		���O�w�肵���q�I�u�W�F�N�g�̎擾
		@param[in]	name	�擾����q�I�u�W�F�N�g�̖��O
		@return		�q�I�u�W�F�N�g
	*/
	const _Ptr& GetChildByName(const ::std::string& name) const;

	/**
		@brief		���O�w�肵���q�I�u�W�F�N�g�̎擾
		@param[in]	name	�擾����q�I�u�W�F�N�g�̖��O
		@return		�q�I�u�W�F�N�g
	*/
	template<class T> const T& GetChildByName(const ::std::string& name) const
	{
		return std::dynamic_pointer_cast<T>(this->GetChildByName(name));
	}

	/**
		@brief		�q�I�u�W�F�N�g�̎擾
		@param[in]	�Ȃ�
		@return		�q�I�u�W�F�N�g
	*/
	::std::vector<_Ptr>& GetChildren()
	{
		return m_children;
	}
	
	/**
		@brief		�q�I�u�W�F�N�g�̎擾[const]
		@param[in]	�Ȃ�
		@return		�q�I�u�W�F�N�g
	*/
	const ::std::vector<_Ptr>& GetChildren() const
	{
		return m_children;
	}

	/**
		@brief		�q�I�u�W�F�N�g�̍폜
		@param[in]	�Ȃ�
		@return		�Ȃ�
	*/
	void RemoveChildren()
	{
		this->_RemoveChildren(m_children);
	}

	/**
		@brief		�q�I�u�W�F�N�g�̍폜(���t���[���ǉ����܂�)
		@param[in]	�Ȃ�
		@param[in]	�Ȃ�
	*/
	void RemoveAllChildren()
	{
		this->_RemoveChildren(m_children);
		this->_RemoveChildren(m_insertChildren);
	}
	
	/**
		@brief		�q�I�u�W�F�N�g�̑����폜
		@param[in]	�Ȃ�
		@return		�Ȃ�
	*/
	void ClearChildren()
	{
		m_children.clear();
	}

	/**
		@brief		�q�I�u�W�F�N�g�̑����폜(���t���[���ǉ����܂�)
		@param[in]	�Ȃ�
		@param[in]	�Ȃ�
	*/
	void ClearAllChildren()
	{
		m_children.clear();
		m_insertChildren.clear();
	}


	/**
		@brief		���g�̍폜
		@param[in]	�Ȃ�
		@return		�Ȃ�
	*/
	void Remove()
	{
		this->m_isRemove = true;
	}


	/**
		@brief		�폜�\�肩
		@param[in]	�Ȃ�
		@return		�폜�\�肩
	*/
	bool IsRemove() const
	{
		return m_isRemove;
	}

	/**
		@brief		�I�u�W�F�N�g�̃n���h���̎擾
		@param[in]	�Ȃ�
		@return		�I�u�W�F�N�g�n���h��
		@retval		FileLoader::<unnamed>::INVALID_HANDLE	�n���h������
		@retval		���ȊO		�I�u�W�F�N�g�n���h��(�摜�n���h���A���f���n���h��)
	*/
	virtual int GetHandle() const = 0;

	/**
		@brief		���W�̐ݒ�
		@param[in]	position	���W
		@return		�Ȃ�
	*/
	virtual void SetPosition(const ns_Math::Vector3& position) = 0;

	/**
		@brief		���W�̎擾
		@param[in]	�Ȃ�
		@return		���W
	*/
	virtual ns_Math::Vector3 GetPosition() const = 0;

	/**
		@brief		�g�嗦�̐ݒ�
		@param[in]	scale	�g�嗦
		@return		�Ȃ�
	*/
	virtual void SetScale(const ns_Math::Vector3& scale) = 0;

	/**
		@brief		�g�嗦�̎擾
		@param[in]	�Ȃ�
		@return		�g�嗦
	*/
	virtual ns_Math::Vector3 GetScale() const = 0;

	/**
		@brief		��]�p�̐ݒ�
		@param[in]	rotation	��]�p
		@return		�Ȃ�
	*/
	virtual void SetRotation(const ns_Math::Vector3& rotation) = 0;

	/**
		@brief		��]�p�̎擾
		@param[in]	�Ȃ�
		@return		��]�p
	*/
	virtual ns_Math::Vector3 GetRotation() const = 0;

	/**	
		@brief		�`��ݒ�
		@param[in]	isVisible	�`�悷�邩
		@return		�Ȃ�
	*/
	virtual void SetVisible(bool isVisible) = 0;

	
	/**	
		@brief		�`��ݒ�̎擾
		@param[in]	�Ȃ�
		@return		�`�悷�邩
		@retval		true		�`�悷��
		@retval		false		�`�悵�Ȃ�
	*/
	virtual bool GetVisible() const = 0;
	//------------------------------------------------
protected:
	/**
		@brief		�I�u�W�F�N�g�̍X�V
		@param[in]	�Ȃ�
		@return		�Ȃ�
	*/
	virtual void _UpdateObjects();
	/**
		@brief		�e�I�u�W�F�N�g�̐ݒ�
		@param[in]	pParent
		@return		�Ȃ�
	*/
	virtual void SetParent(const Object* pParent)
	{
		this->m_pParent = pParent;
	}

	/**
		@brief		�q�I�u�W�F�N�g�̍폜
		@param[in]	children	�폜����q�I�u�W�F�N�g�Q
		@param[in]	�Ȃ�
	*/
	void _RemoveChildren(::std::vector<_Ptr>& children);
	//------------------------------------------------
private:


	/**
		@brief		�q�I�u�W�F�N�g�̈�Ēǉ�
		@param[in]	�Ȃ�
		@return		�Ȃ�
	*/
	void _MergeChildren();

	//=====================================================
	// �ϐ��錾
	//=====================================================
#ifdef _DEBUG
public:
	bool				D_isDrawBoundingBox;		//!< �o�E���f�B���O�{�b�N�X�̕\��
#endif
protected:

private:
	::std::string		m_name;				//!< ���O
	const Object*		m_pParent;			//!< �e�I�u�W�F�N�g
	::std::vector<_Ptr> m_children;			//!< �q�I�u�W�F�N�g
	::std::vector<_Ptr> m_insertChildren;	//!< ��t���[����ǉ��\��̎q�I�u�W�F�N�g

	bool				m_isRemove;			//!< �폜���邩
};

typedef ::std::shared_ptr<Object> ObjPtr;





NS_DLG_END	// namespace ns_DxLibGame

#endif	// __OBJECT_H__