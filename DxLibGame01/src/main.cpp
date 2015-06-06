/**=============================================================================
	@file		main.cpp
	@brief		エントリーポイント記述
	@author		Masato Yamamoto
	@date		2015-02-20

	@par		[説明]
				エントリーポイント

	@note

		Copyright (C) 2014  M.Yamamoto
=============================================================================*/
#include "DxLib.h"
#include "MyGame.h"
NS_USE_DXLIBGAME;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	MyGame g(hInstance, hPrevInstance, lpCmdLine, nCmdShow);
	g.Loop();
	return 0;
}