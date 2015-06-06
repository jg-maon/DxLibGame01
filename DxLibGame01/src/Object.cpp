/**=============================================================================
	@file		Object.cpp
	@brief		オブジェクト基本クラス 実装
	@author		Masato Yamamoto
	@date		2015-02-20

	@par		[説明]
				オブジェクト基本クラス実装

	@note

		Copyright (C) 2015  M.Yamamoto
=============================================================================*/
#include "Object.h"
#include "FpsController.h"

#include <algorithm>	// remove_if

NS_DLG_BEGIN
#pragma region Object public methods
/**
	@brief		コンストラクタ
	@param[in]	なし
	@return		なし
*/
Object::Object()
{

}
/**
	@brief		コンストラクタ
	@param[in]	name	名前
	@return		なし
*/
Object::Object(const ::std::string& name)
	: m_name(name)
{

}
		
		
/**
	@brief		デストラクタ
	@param[in]	なし
	@return		なし
*/
Object::~Object()
{

}

/**
	@brief		更新
	@param[in]	delta	フレームタイム
	@return		なし
*/
void Object::Update(float delta)
{

}

/**
	@brief		子オブジェクト含め描画
	@param[in]	delta	フレームタイム
	@return		なし
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
	@brief		子オブジェクトの追加
	@param[in]	child	子オブジェクト
	@return		なし
*/
void Object::AddChild(const ObjPtr& child)
{
	child->SetParent(this);
	this->m_insertChildren.push_back(child);
}

/**
	@brief		子オブジェクトの追加
	@param[in]	child	子オブジェクト
	@param[in]	name	子オブジェクトの名前
	@return		なし
*/
void Object::AddChild(const ObjPtr& child, const ::std::string& name)
{
	child->SetParent(this);
	child->SetName(name);
	this->m_insertChildren.push_back(child);
}
/**
	@brief		子オブジェクトの即時追加
	@attention	子オブジェクトのループ中に呼び出すとメモリ再配置エラーが出る
	@param[in]	child	子オブジェクト
	@return		なし
*/
void  Object::AddChildInstant(const ObjPtr& child)
{
	child->SetParent(this);
	this->m_children.push_back(child);
}
/**
	@brief		子オブジェクトの即時追加
	@attention	子オブジェクトのループ中に呼び出すとメモリ再配置エラーが出る
	@param[in]	child	子オブジェクト
	@param[in]	name	子オブジェクトの名前
	@return		なし
*/
void  Object::AddChildInstant(const ObjPtr& child, const ::std::string& name)
{
	child->SetParent(this);
	child->SetName(name);
	this->m_children.push_back(child);
}
/**
	@brief		名前指定した子オブジェクトの取得
	@param[in]	name	取得する子オブジェクトの名前
	@return		子オブジェクト
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
	@brief		オブジェクトの更新
	@param[in]	なし
	@return		なし
*/
void Object::_UpdateObjects()
{
	//---------------------------
	// 子オブジェクトの更新
	//float delta = FpsController::GetDeltaTime();
	//this->Update(delta);
	//for (auto& _child : m_children)
	//{
	//	_child->_Update();
	//}

	//---------------------------
	// 子オブジェクトの削除
	m_children.erase(
		::std::remove_if(
			m_children.begin(),
			m_children.end(),
			[](const ObjPtr& obj)->bool{return obj->IsRemove(); }
		),
		m_children.end()
	);

	//---------------------------
	// 子オブジェクト追加
	_MergeChildren();
	
}

/**
	@brief		子オブジェクトの削除
	@param[in]	children	削除する子オブジェクト群
	@param[in]	なし
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
	@brief		子オブジェクトの一斉追加
	@param[in]	なし
	@return		なし
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