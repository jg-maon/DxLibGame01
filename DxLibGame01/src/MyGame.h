/**=============================================================================
	@file		MyGame.h
	@brief		�Q�[�����[�v�N���X ��`
	@author		Masato Yamamoto
	@date		2015-02-20

	@par		[����]
				�Q�[�����[�v�N���X��`

	@note

		Copyright (C) 2015  M.Yamamoto
=============================================================================*/
#ifndef __MY_GAME_H__
#define __MY_GAME_H__


#ifndef __DXLIB
#include "DxLib.h"
#endif

#ifndef __DXLIB_GAME_H__
#include "DxLibGame.h"
#endif

#ifndef __REF_H__
#include "Ref.h"
#endif

NS_DLG_BEGIN
/**
	@class		MyGame
	@brief		�Q�[�����[�v�N���X
*/
class MyGame : public Ref
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
		@param[in]	hInstance
		@param[in]	hPrevInstance
		@param[in]	lpCmdLine
		@param[in]	nCmdShow
		@return		�Ȃ�
	*/
	MyGame(HINSTANCE hInstance,
		   HINSTANCE hPrevInstance,
		   LPSTR lpCmdLine,
		   int nCmdShow);
		
	/**
		@brief		�f�X�g���N�^
		@param[in]	�Ȃ�
		@return		�Ȃ�
	*/
	~MyGame();

private:
		
	/**
		@brief		���C�����[�v
		@param[in]	�Ȃ�
		@return		�Ȃ�
	*/
public:
	void Loop();
		
protected:



private:
	/**
		@brief		DX���C�u������������
		@param[in]	winSize		�E�B���h�E�T�C�Y
		@return		DxLib_Init()�̖߂�l
		@retval		-1	�G���[
	*/
	int _Init(const ns_Math::Size& winSize);

	//=====================================================
	// �ϐ��錾
	//=====================================================
public:

protected:

private:

};




NS_DLG_END	// namespace ns_DxLibGame

#endif	// __MY_GAME_H__