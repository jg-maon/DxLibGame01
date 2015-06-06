/**=============================================================================
	@file		FpsController.cpp
	@brief		FPS固定用クラス 実装
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
#include "FpsController.h"

NS_DLG_BEGIN

const LONGLONG FpsController::FPS_STATS_UNIT = 1000000ll;	//!< 時間単位
const double FpsController::FPS_STATS_INTERVAL = 0.1*10;		//!< 計測間隔

LONGLONG FpsController::m_sleepTime;

#pragma region FpsController public methods

/**
	@brief		コンストラクタ
	@param[in]	fps		固定するFPS値(デフォルト:60)
	@return		なし
*/
FpsController::FpsController(int fps/* = 60*/)
{
	m_calcInterval = 0.f;
	m_actualFPS = 0.0;
	m_frameCount = 0l;
	m_overSleepTime = 0ll;
	m_prevCalcTime = m_beforeTime = 0ll;//GetNowHiPerformanceCount();
	m_noDelays = 0;
	SetFPS(fps);
}
		
/**
	@brief		デストラクタ
	@param[in]	なし
	@return		なし
*/
FpsController::~FpsController()
{

}
	
/**
	@brief		途中でFPSを変更したい際に呼ぶ
	@param[in]	fps		固定するFPS値(デフォルト:60)
	@return		なし
*/
void FpsController::SetFPS(int fps)
{
	m_fps = fps;
	m_waitTime = 1.f / fps;
}
	
/**
	@brief		FPS表示
	@param[in]	x	描画始点X
	@param[in]	y	描画始点Y
	@return		なし
*/
void FpsController::Draw(float x, float y) const
{
	DrawFormatStringF(x, y, GetColor(255, 255, 255), "FPS %.1lf", m_actualFPS);
	//DrawExtendFormatString(450 - 15, 10, 0.8, 0.8,
	//					   GetColor(255, 255, 255), "FrameCount %2ld", m_frameCount);
}

/**
	@brief		設定したFPSの値になるようにsleep時間を制御する		
	@param[in]	なし
	@return		描画可能か
	@retval		true	描画可能
	@retval		false	描画不可
*/
bool FpsController::Wait()
{
	bool flag = false;

	_CalcSleepTime();

	if (!m_skipWait || 0ll < m_sleepTime)
	{
		// 休止時間がとれる場合
		WaitTimer(static_cast<int>(m_sleepTime / 1000LL));	// micro->ms
		flag = true;
	}
	
	// WaitTimer()の誤差を通知  ※GetSleepTime()に反映させる必要があるため
	_NotifyOverSleepTime();

	_CalcFPS();
	return flag || m_skipWait;
}

#pragma endregion	// FpsController public methods

//------------------------------------------------
//------------------------------------------------

#pragma region FpsController private methods

/**
	@brief		休止時間を計算する
	@param[in]	なし
	@return		なし
*/
void FpsController::_CalcSleepTime()
{
	m_beforeTime = m_afterTime;
	m_afterTime = GetNowHiPerformanceCount();
	auto timeDiff = m_afterTime - m_beforeTime;
	// 前回のフレームの休止時間誤差も引いておく
	m_sleepTime = static_cast<LONGLONG>(FPS_STATS_UNIT * m_waitTime) - timeDiff - m_overSleepTime;
}
	
/**
	@brief		待機処理の時間誤差を整える
	@param[in]	なし
	@return		なし
*/
void  FpsController::_NotifyOverSleepTime()
{
	m_skipWait = false;
	if (0ll < m_sleepTime)
	{
		m_overSleepTime = (GetNowHiPerformanceCount() - m_afterTime) - m_sleepTime;
	}
	else
	{
		// 状態更新・レンダリングで時間を使い切ってしまい休止時間がとれない場合
		m_overSleepTime = 0ll;
		// 休止なしが16回以上続いたら
		if (++m_noDelays >= 16)
		{
			m_noDelays = 0;
			m_skipWait = true;
		}
	}
	m_afterTime = GetNowHiPerformanceCount();
}

/**
	@brief		FPS計測,計算
	@param[in]	なし
	@return		なし
*/
void FpsController::_CalcFPS(void)
{
	m_frameCount++;
	m_calcInterval += m_waitTime;

	// FPS再計算するようにする
	if (FPS_STATS_INTERVAL <= m_calcInterval)
	{
		LONGLONG timeNow = GetNowHiPerformanceCount();
		// 実際の経過時間を測定
		LONGLONG realElapsedTime = timeNow - m_prevCalcTime;	  // 単位: us

		// 実際のFPSを計算
		// realElapsedTimeの単位はusなのでsに変換する
		m_actualFPS = (static_cast<double>(m_frameCount) / realElapsedTime) * FPS_STATS_UNIT;
		
		// カウンターリセット
		m_frameCount = 0l;
		m_calcInterval = 0.f;
		m_prevCalcTime = timeNow;
	}
}

#pragma endregion	// FpsController private methods


NS_DLG_END	// namespace ns_DxLibGame