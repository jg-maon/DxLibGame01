/**=============================================================================
	@file		Object.cpp
	@brief		�I�u�W�F�N�g��{�N���X ����
	@author		Masato Yamamoto
	@date		2015-02-20

	@par		[����]
				�I�u�W�F�N�g��{�N���X����

	@note

		Copyright (C) 2015  M.Yamamoto
=============================================================================*/
#include "Object.h"
#include "FpsController.h"

#include <algorithm>	// remove_if

NS_DLG_BEGIN
#pragma region Object public methods
/**
	@brief		�R���X�g���N�^
	@param[in]	�Ȃ�
	@return		�Ȃ�
*/
Object::Object()
{

}
/**
	@brief		�R���X�g���N�^
	@param[in]	name	���O
	@return		�Ȃ�
*/
Object::Object(const ::std::string& name)
	: m_name(name)
{

}
		
		
/**
	@brief		�f�X�g���N�^
	@param[in]	�Ȃ�
	@return		�Ȃ�
*/
Object::~Object()
{

}

/**
	@brief		�X�V
	@param[in]	delta	�t���[���^�C��
	@return		�Ȃ�
*/
void Object::Update(float delta)
{

}

/**
	@brief		�q�I�u�W�F�N�g�܂ߕ`��
	@param[in]	delta	�t���[���^�C��
	@return		�Ȃ�
*/
void Object::Visit(float delta)
{
	this->Draw(delta);
	for (auto& _child : m_children)
	{
		_child->Visit(delta);
	}
#ifdef _DEBUG
	if (D_isDrawBoundingBox)
	{
		auto _min = GetPosition() - GetScale() / 2.f;
		auto _max = GetPosition() + GetScale() / 2.f;
		DrawCube3D(_min, _max, -1, 0, FALSE);
	}
#endif
}


/**
	@brief		�q�I�u�W�F�N�g�̒ǉ�
	@param[in]	child	�q�I�u�W�F�N�g
	@return		�Ȃ�
*/
void Object::AddChild(const ObjPtr& child)
{
	child->SetParent(this);
	this->m_insertChildren.push_back(child);
}

/**
	@brief		�q�I�u�W�F�N�g�̒ǉ�
	@param[in]	child	�q�I�u�W�F�N�g
	@param[in]	name	�q�I�u�W�F�N�g�̖��O
	@return		�Ȃ�
*/
void Object::AddChild(const ObjPtr& child, const ::std::string& name)
{
	child->SetParent(this);
	child->SetName(name);
	this->m_insertChildren.push_back(child);
}
/**
	@brief		�q�I�u�W�F�N�g�̑����ǉ�
	@attention	�q�I�u�W�F�N�g�̃��[�v���ɌĂяo���ƃ������Ĕz�u�G���[���o��
	@param[in]	child	�q�I�u�W�F�N�g
	@return		�Ȃ�
*/
void  Object::AddChildInstant(const ObjPtr& child)
{
	child->SetParent(this);
	this->m_children.push_back(child);
}
/**
	@brief		�q�I�u�W�F�N�g�̑����ǉ�
	@attention	�q�I�u�W�F�N�g�̃��[�v���ɌĂяo���ƃ������Ĕz�u�G���[���o��
	@param[in]	child	�q�I�u�W�F�N�g
	@param[in]	name	�q�I�u�W�F�N�g�̖��O
	@return		�Ȃ�
*/
void  Object::AddChildInstant(const ObjPtr& child, const ::std::string& name)
{
	child->SetParent(this);
	child->SetName(name);
	this->m_children.push_back(child);
}
/**
	@brief		���O�w�肵���q�I�u�W�F�N�g�̎擾
	@param[in]	name	�擾����q�I�u�W�F�N�g�̖��O
	@return		�q�I�u�W�F�N�g
*/
const ObjPtr& Object::GetChildByName(const ::std::string& name) const
{
	for (auto& _child : m_children)
	{
		if (name == _child->m_name)
		{
			return _child;
		}
	}
	return (nullptr);
}

#pragma endregion	// Object public methods

//------------------------------------------------
#pragma region Object protected methods
/**
	@brief		�I�u�W�F�N�g�̍X�V
	@param[in]	�Ȃ�
	@return		�Ȃ�
*/
void Object::_UpdateObjects()
{
	//---------------------------
	// �q�I�u�W�F�N�g�̍X�V
	//float delta = FpsController::GetDeltaTime();
	//this->Update(delta);
	//for (auto& _child : m_children)
	//{
	//	_child->_Update();
	//}

	//---------------------------
	// �q�I�u�W�F�N�g�̍폜
	m_children.erase(
		::std::remove_if(
			m_children.begin(),
			m_children.end(),
			[](const ObjPtr& obj)->bool{return obj->IsRemove(); }
		),
		m_children.end()
	);

	//---------------------------
	// �q�I�u�W�F�N�g�ǉ�
	_MergeChildren();
	
}

/**
	@brief		�q�I�u�W�F�N�g�̍폜
	@param[in]	children	�폜����q�I�u�W�F�N�g�Q
	@param[in]	�Ȃ�
*/
void Object::_RemoveChildren(::std::vector<ObjPtr>& children)
{
	for (auto& _child : children)
	{
		_child->m_isRemove = true;
	}
}
#pragma endregion	// Object protected methods
//------------------------------------------------

#pragma region Object private methods

/**
	@brief		�q�I�u�W�F�N�g�̈�Ēǉ�
	@param[in]	�Ȃ�
	@return		�Ȃ�
*/
void Object::_MergeChildren()
{
	if (m_insertChildren.empty())
		return;

	m_children.insert(m_children.end(),
					  m_insertChildren.begin(),
					  m_insertChildren.end());
	m_insertChildren.clear();
}

#pragma endregion	// Object private methods

NS_DLG_END	// namespace ns_DxLibGame