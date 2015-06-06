/**=============================================================================
	@file		Ref.h
	@brief		�S�N���X���N���X ��`
	@author		Masato Yamamoto
	@date		2015-02-20

	@par		[����]
				�S�N���X�̊��N���X�̒�`

	@note

		Copyright (C) 2015  M.Yamamoto
=============================================================================*/
#ifndef __REF_H__
#define __REF_H__

#ifndef __DXLIB_GAME_H__
#include "DxLibGame.h"
#endif

#ifndef __MATH_H__
#include "Math.h"
#endif

NS_DLG_BEGIN
/**
	@class		Ref
	@brief		�S�I�u�W�F�N�g���N���X
*/
class Ref
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
	Ref();	
		
	/**
		@brief		�f�X�g���N�^
		@param[in]	�Ȃ�
		@return		�Ȃ�
	*/
	virtual ~Ref();
	
	/**
		@brief		�����ێ��E�B���h�E�T�C�Y�̐ݒ�
		@param[in]	winSize		�V�K�E�B���h�E�T�C�Y
		@return		�Ȃ�
	*/
	void SetWinSize(const ns_Math::Size& winSize)
	{
		m_winSize = winSize;
	}

	/**
		@brief		�E�B���h�E�T�C�Y�̎擾
		@param[in]	�Ȃ�
		@return		�E�B���h�E�T�C�Y
	*/
	ns_Math::Size GetWinSize() const 
	{
		return m_winSize;
	}

	/**
		@brief		�E�B���h�E�̕��𐮐��l�Ƃ��Ď擾
		@param[in]	�Ȃ�
		@return		�E�B���h�E��
	*/
	int GetWinWidth() const
	{
		return static_cast<int>(m_winSize.width);
	}

	/**
		@brief		�E�B���h�E�̍����𐮐��l�Ƃ��Ď擾
		@param[in]	�Ȃ�
		@return		�E�B���h�E��
	*/
	int GetWinHeight() const
	{
		return static_cast<int>(m_winSize.height);
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
private:
	static ns_Math::Size	m_winSize;

};
NS_DLG_END	// namespace ns_DxLibGame

#endif	// __REF_H__