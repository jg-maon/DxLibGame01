/**=============================================================================
	@file		Object.h
	@brief		オブジェクト基本クラス 定義
	@author		Masato Yamamoto
	@date		2015-02-20

	@par		[説明]
				オブジェクト基本クラス定義

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
	@brief		クラステンプレート
*/
class Object : public Ref
{
	//=====================================================
	// 定数(列挙型)宣言
	//=====================================================
public:
	//=====================================================
	// 内部クラス宣言
	//=====================================================
public:
	//=====================================================
	// 型別名定義
	//=====================================================
public:
	typedef Object super;
	typedef std::shared_ptr<Object> _Ptr;
	//=====================================================
	// 静的メソッド宣言
	//=====================================================
public:

	//=====================================================
	// メソッド宣言
	//=====================================================
public:
	/**
		@brief		コンストラクタ
		@param[in]	なし
		@return		なし
	*/
	Object();
	/**
		@brief		コンストラクタ
		@param[in]	name	名前
		@return		なし
	*/
	Object(const ::std::string& name);
	
		
	/**
		@brief		デストラクタ
		@param[in]	なし
		@return		なし
	*/
	~Object();
	

	/**
		@brief		更新
		@param[in]	delta	フレームタイム
		@return		なし
	*/
	virtual void Update(float delta);

	
	/**
		@brief		描画
		@param[in]	delta	フレームタイム
		@return		なし
	*/
	virtual void Draw(float delta) = 0;
	
	/**
		@brief		子オブジェクト含め描画
		@param[in]	delta	フレームタイム
		@return		なし
	*/
	virtual void Visit(float delta) final;

	/**
		@brief		オブジェクト名の設定
		@param[in]	name	オブジェクト名
		@return		なし
	*/
	void SetName(const ::std::string& name)
	{
		m_name = name;
	}
	
	/**
		@brief		子オブジェクトの追加
		@param[in]	child	子オブジェクト
		@return		なし
	*/
	void AddChild(const _Ptr& child);
	
	/**
		@brief		子オブジェクトの追加
		@param[in]	child	子オブジェクト
		@param[in]	name	子オブジェクトの名前
		@return		なし
	*/
	void AddChild(const _Ptr& child, const ::std::string& name);
	/**
		@brief		子オブジェクトの即時追加
		@attention	子オブジェクトのループ中に呼び出すとメモリ再配置エラーが出る
		@param[in]	child	子オブジェクト
		@return		なし
	*/
	void AddChildInstant(const _Ptr& child);
	/**
		@brief		子オブジェクトの即時追加
		@attention	子オブジェクトのループ中に呼び出すとメモリ再配置エラーが出る
		@param[in]	child	子オブジェクト
		@param[in]	name	子オブジェクトの名前
		@return		なし
	*/
	void AddChildInstant(const _Ptr& child, const ::std::string& name);

	/**
		@brief		名前指定した子オブジェクトの取得
		@param[in]	name	取得する子オブジェクトの名前
		@return		子オブジェクト
	*/
	const _Ptr& GetChildByName(const ::std::string& name) const;

	/**
		@brief		名前指定した子オブジェクトの取得
		@param[in]	name	取得する子オブジェクトの名前
		@return		子オブジェクト
	*/
	template<class T> const T& GetChildByName(const ::std::string& name) const
	{
		return std::dynamic_pointer_cast<T>(this->GetChildByName(name));
	}

	/**
		@brief		子オブジェクトの取得
		@param[in]	なし
		@return		子オブジェクト
	*/
	::std::vector<_Ptr>& GetChildren()
	{
		return m_children;
	}
	
	/**
		@brief		子オブジェクトの取得[const]
		@param[in]	なし
		@return		子オブジェクト
	*/
	const ::std::vector<_Ptr>& GetChildren() const
	{
		return m_children;
	}

	/**
		@brief		子オブジェクトの削除
		@param[in]	なし
		@return		なし
	*/
	void RemoveChildren()
	{
		this->_RemoveChildren(m_children);
	}

	/**
		@brief		子オブジェクトの削除(次フレーム追加分含め)
		@param[in]	なし
		@param[in]	なし
	*/
	void RemoveAllChildren()
	{
		this->_RemoveChildren(m_children);
		this->_RemoveChildren(m_insertChildren);
	}
	
	/**
		@brief		子オブジェクトの即時削除
		@param[in]	なし
		@return		なし
	*/
	void ClearChildren()
	{
		m_children.clear();
	}

	/**
		@brief		子オブジェクトの即時削除(次フレーム追加分含め)
		@param[in]	なし
		@param[in]	なし
	*/
	void ClearAllChildren()
	{
		m_children.clear();
		m_insertChildren.clear();
	}


	/**
		@brief		自身の削除
		@param[in]	なし
		@return		なし
	*/
	void Remove()
	{
		this->m_isRemove = true;
	}


	/**
		@brief		削除予定か
		@param[in]	なし
		@return		削除予定か
	*/
	bool IsRemove() const
	{
		return m_isRemove;
	}

	/**
		@brief		オブジェクトのハンドルの取得
		@param[in]	なし
		@return		オブジェクトハンドル
		@retval		FileLoader::<unnamed>::INVALID_HANDLE	ハンドル無し
		@retval		↑以外		オブジェクトハンドル(画像ハンドル、モデルハンドル)
	*/
	virtual int GetHandle() const = 0;

	/**
		@brief		座標の設定
		@param[in]	position	座標
		@return		なし
	*/
	virtual void SetPosition(const ns_Math::Vector3& position) = 0;

	/**
		@brief		座標の取得
		@param[in]	なし
		@return		座標
	*/
	virtual ns_Math::Vector3 GetPosition() const = 0;

	/**
		@brief		拡大率の設定
		@param[in]	scale	拡大率
		@return		なし
	*/
	virtual void SetScale(const ns_Math::Vector3& scale) = 0;

	/**
		@brief		拡大率の取得
		@param[in]	なし
		@return		拡大率
	*/
	virtual ns_Math::Vector3 GetScale() const = 0;

	/**
		@brief		回転角の設定
		@param[in]	rotation	回転角
		@return		なし
	*/
	virtual void SetRotation(const ns_Math::Vector3& rotation) = 0;

	/**
		@brief		回転角の取得
		@param[in]	なし
		@return		回転角
	*/
	virtual ns_Math::Vector3 GetRotation() const = 0;

	/**	
		@brief		描画設定
		@param[in]	isVisible	描画するか
		@return		なし
	*/
	virtual void SetVisible(bool isVisible) = 0;

	
	/**	
		@brief		描画設定の取得
		@param[in]	なし
		@return		描画するか
		@retval		true		描画する
		@retval		false		描画しない
	*/
	virtual bool GetVisible() const = 0;
	//------------------------------------------------
protected:
	/**
		@brief		オブジェクトの更新
		@param[in]	なし
		@return		なし
	*/
	virtual void _UpdateObjects();
	/**
		@brief		親オブジェクトの設定
		@param[in]	pParent
		@return		なし
	*/
	virtual void SetParent(const Object* pParent)
	{
		this->m_pParent = pParent;
	}

	/**
		@brief		子オブジェクトの削除
		@param[in]	children	削除する子オブジェクト群
		@param[in]	なし
	*/
	void _RemoveChildren(::std::vector<_Ptr>& children);
	//------------------------------------------------
private:


	/**
		@brief		子オブジェクトの一斉追加
		@param[in]	なし
		@return		なし
	*/
	void _MergeChildren();

	//=====================================================
	// 変数宣言
	//=====================================================
#ifdef _DEBUG
public:
	bool				D_isDrawBoundingBox;		//!< バウンディングボックスの表示
#endif
protected:

private:
	::std::string		m_name;				//!< 名前
	const Object*		m_pParent;			//!< 親オブジェクト
	::std::vector<_Ptr> m_children;			//!< 子オブジェクト
	::std::vector<_Ptr> m_insertChildren;	//!< 一フレーム後追加予定の子オブジェクト

	bool				m_isRemove;			//!< 削除するか
};

typedef ::std::shared_ptr<Object> ObjPtr;





NS_DLG_END	// namespace ns_DxLibGame

#endif	// __OBJECT_H__