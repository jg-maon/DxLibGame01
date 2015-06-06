/**=============================================================================
	@file		FpsController.h
	@brief		FPS固定用クラス 定義
	@author		Masato Yamamoto
	@date		2015-02-27

	@par		[説明]
				FPS固定用処理
				デフォルト60FPS
				※	DxLib::SetWaitVSyncFlag(FALSE)を
					DxLib::DxLib_Init()前に呼ばないと垂直同期待ちされる

	@note

		Copyright (C) 2015  M.Yamamoto
=============================================================================*/
#ifndef __FPS_CONTROLLER_H__
#define __FPS_CONTROLLER_H__

#ifndef __DXLIB_GAME_H__
#include "DxLibGame.h"
#endif

#ifndef __REF_H__
#include "Ref.h"
#endif

NS_DLG_BEGIN
/**
	@class		FpsController
	@brief		FPS固定用クラス
*/
class FpsController : public Ref
{
	//=====================================================
	// 定数(列挙型)宣言
	//=====================================================
public:
	static const LONGLONG FPS_STATS_UNIT;		//!< 時間単位
	static const double FPS_STATS_INTERVAL;		//!< 計測間隔

	//=====================================================
	// 内部クラス宣言
	//=====================================================
public:
	//=====================================================
	// 型別名定義
	//=====================================================
public:

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
		@param[in]	fps		固定するFPS値(デフォルト:60)
		@return		なし
	*/
	FpsController(int fps = 60);
		
	/**
		@brief		デストラクタ
		@param[in]	なし
		@return		なし
	*/
	virtual ~FpsController();

	/**
		@brief		途中でFPSを変更したい際に呼ぶ
		@param[in]	fps		固定するFPS値(デフォルト:60)
		@return		なし
	*/
	void SetFPS(int fps);
	
	/**
		@brief		FPS表示
		@param[in]	x	描画始点X
		@param[in]	y	描画始点Y
		@return		なし
	*/
	void Draw(float x, float y) const;

	/**
		@brief		設定したFPSの値になるようにsleep時間を制御する		
		@param[in]	なし
		@return		描画可能か
		@retval		true	描画可能
		@retval		false	描画不可
	*/
	bool Wait();
	
	/**
		@brief		フレームタイムの取得
		@param[in]	なし
		@return		フレームタイム
	*/
	static float GetDeltaTime()
	{
		return static_cast<float>(m_sleepTime) / FPS_STATS_UNIT;
	}
	//------------------------------------------------
protected:
	
	//------------------------------------------------
private:
	/**
		@brief		休止時間を計算する
		@param[in]	なし
		@return		なし
	*/
	void _CalcSleepTime();
	
	/**
		@brief		待機処理の時間誤差を整える
		@param[in]	なし
		@return		なし
	*/
	void _NotifyOverSleepTime();
	
	
	/**
		@brief		FPS計測,計算
		@param[in]	なし
		@return		なし
	*/
	void _CalcFPS(void);

	//=====================================================
	// 変数宣言
	//=====================================================
//public:
protected:

private:
	int			m_fps;				//!< 理想のFPS
	float		m_waitTime;			//!< 理想FPS時の1フレームの待ち時間
	//------------------------------------
	// FPS計算用
	float		m_calcInterval;		//!< fps補正間隔
	LONGLONG	m_prevCalcTime;		//!< 前回計測時刻

	double		m_actualFPS;		//!< 実際のFPS
	long		m_frameCount;		//!< フレーム数

	//------------------------------------
	// FPS計測
	LONGLONG	m_beforeTime;		//!< 前フレーム時刻
	LONGLONG	m_afterTime;		//!< 現フレーム(再計測時)時刻
	static LONGLONG	m_sleepTime;		//!< 休止時間

	LONGLONG	m_overSleepTime;	//!< 休止処理誤差

	int			m_noDelays;			//!< 休止時間が取れない場合の回数
	bool		m_skipWait;			//!< 休止処理スキップフラグ

};

NS_DLG_END	// namespace ns_DxLibGame

#endif	// __FPS_CONTROLLER_H__