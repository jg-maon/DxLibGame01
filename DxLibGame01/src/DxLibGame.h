/**=============================================================================
	@file		DxLibGame.h
	@brief		DX���C�u��������S�\�[�X����include����
	@author		Masato Yamamoto
	@date		2015-02-20

	@par		[����]
				DX���C�u��������ɉ����Ă̑S�\�[�X����include����t�@�C��
				���O��Ԃ̒�`���̑����l�߂�

	@note

		Copyright (C) 2015  M.Yamamoto
=============================================================================*/
#ifndef __DXLIB_GAME_H__
#define __DXLIB_GAME_H__

// �g�p���O��Ԗ�
#define NS_NAME	ns_DxLibGame

#if defined(__cplusplus)
#define NS_USE_DXLIBGAME	using namespace NS_NAME
#else 
#define NS_USE_DXLIBGAME
#endif


// ���O��Ԓ�`�J�n
#if defined(__cplusplus)
#define NS_DLG_BEGIN	namespace NS_NAME{
#else
#define NS_DLG_BEGIN
#endif

// ���O��Ԓ�`�I��
#if defined(__cplusplus)
#define NS_DLG_END	}
#else
#define NS_DLG_END
#endif

#endif	// __DXLIB_GAME_H__