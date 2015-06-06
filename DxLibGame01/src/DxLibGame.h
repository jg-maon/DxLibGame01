/**=============================================================================
	@file		DxLibGame.h
	@brief		DXライブラリ制作全ソースからincludeする
	@author		Masato Yamamoto
	@date		2015-02-20

	@par		[説明]
				DXライブラリ制作に於いての全ソースからincludeするファイル
				名前空間の定義その他を詰める

	@note

		Copyright (C) 2015  M.Yamamoto
=============================================================================*/
#ifndef __DXLIB_GAME_H__
#define __DXLIB_GAME_H__

// 使用名前空間名
#define NS_NAME	ns_DxLibGame

#if defined(__cplusplus)
#define NS_USE_DXLIBGAME	using namespace NS_NAME
#else 
#define NS_USE_DXLIBGAME
#endif


// 名前空間定義開始
#if defined(__cplusplus)
#define NS_DLG_BEGIN	namespace NS_NAME{
#else
#define NS_DLG_BEGIN
#endif

// 名前空間定義終了
#if defined(__cplusplus)
#define NS_DLG_END	}
#else
#define NS_DLG_END
#endif

#endif	// __DXLIB_GAME_H__