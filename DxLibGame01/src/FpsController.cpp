/**=============================================================================
	@file		FpsController.cpp
	@brief		FPS�Œ�p�N���X ����
	@author		Masato Yamamoto
	@date		2015-02-27

	@par		[����]
				FPS�Œ�p����
				�f�t�H���g60FPS
				��	DxLib::SetWaitVSyncFlag(FALSE)��
					DxLib::DxLib_Init()�O�ɌĂ΂Ȃ��Ɛ��������҂������

	@note

		Copyright (C) 2015  M.Yamamoto
=============================================================================*/
#include "FpsController.h"

NS_DLG_BEGIN

const LONGLONG FpsController::FPS_STATS_UNIT = 1000000ll;	//!< ���ԒP��
const double FpsController::FPS_STATS_INTERVAL = 0.1*10;		//!< �v���Ԋu

LONGLONG FpsController::m_sleepTime;

#pragma region FpsController public methods

/**
	@brief		�R���X�g���N�^
	@param[in]	fps		�Œ肷��FPS�l(�f�t�H���g:60)
	@return		�Ȃ�
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
	@brief		�f�X�g���N�^
	@param[in]	�Ȃ�
	@return		�Ȃ�
*/
FpsController::~FpsController()
{

}
	
/**
	@brief		�r����FPS��ύX�������ۂɌĂ�
	@param[in]	fps		�Œ肷��FPS�l(�f�t�H���g:60)
	@return		�Ȃ�
*/
void FpsController::SetFPS(int fps)
{
	m_fps = fps;
	m_waitTime = 1.f / fps;
}
	
/**
	@brief		FPS�\��
	@param[in]	x	�`��n�_X
	@param[in]	y	�`��n�_Y
	@return		�Ȃ�
*/
void FpsController::Draw(float x, float y) const
{
	DrawFormatStringF(x, y, GetColor(255, 255, 255), "FPS %.1lf", m_actualFPS);
	//DrawExtendFormatString(450 - 15, 10, 0.8, 0.8,
	//					   GetColor(255, 255, 255), "FrameCount %2ld", m_frameCount);
}

/**
	@brief		�ݒ肵��FPS�̒l�ɂȂ�悤��sleep���Ԃ𐧌䂷��		
	@param[in]	�Ȃ�
	@return		�`��\��
	@retval		true	�`��\
	@retval		false	�`��s��
*/
bool FpsController::Wait()
{
	bool flag = false;

	_CalcSleepTime();

	if (!m_skipWait || 0ll < m_sleepTime)
	{
		// �x�~���Ԃ��Ƃ��ꍇ
		WaitTimer(static_cast<int>(m_sleepTime / 1000LL));	// micro->ms
		flag = true;
	}
	
	// WaitTimer()�̌덷��ʒm  ��GetSleepTime()�ɔ��f������K�v�����邽��
	_NotifyOverSleepTime();

	_CalcFPS();
	return flag || m_skipWait;
}

#pragma endregion	// FpsController public methods

//------------------------------------------------
//------------------------------------------------

#pragma region FpsController private methods

/**
	@brief		�x�~���Ԃ��v�Z����
	@param[in]	�Ȃ�
	@return		�Ȃ�
*/
void FpsController::_CalcSleepTime()
{
	m_beforeTime = m_afterTime;
	m_afterTime = GetNowHiPerformanceCount();
	auto timeDiff = m_afterTime - m_beforeTime;
	// �O��̃t���[���̋x�~���Ԍ덷�������Ă���
	m_sleepTime = static_cast<LONGLONG>(FPS_STATS_UNIT * m_waitTime) - timeDiff - m_overSleepTime;
}
	
/**
	@brief		�ҋ@�����̎��Ԍ덷�𐮂���
	@param[in]	�Ȃ�
	@return		�Ȃ�
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
		// ��ԍX�V�E�����_�����O�Ŏ��Ԃ��g���؂��Ă��܂��x�~���Ԃ��Ƃ�Ȃ��ꍇ
		m_overSleepTime = 0ll;
		// �x�~�Ȃ���16��ȏ㑱������
		if (++m_noDelays >= 16)
		{
			m_noDelays = 0;
			m_skipWait = true;
		}
	}
	m_afterTime = GetNowHiPerformanceCount();
}

/**
	@brief		FPS�v��,�v�Z
	@param[in]	�Ȃ�
	@return		�Ȃ�
*/
void FpsController::_CalcFPS(void)
{
	m_frameCount++;
	m_calcInterval += m_waitTime;

	// FPS�Čv�Z����悤�ɂ���
	if (FPS_STATS_INTERVAL <= m_calcInterval)
	{
		LONGLONG timeNow = GetNowHiPerformanceCount();
		// ���ۂ̌o�ߎ��Ԃ𑪒�
		LONGLONG realElapsedTime = timeNow - m_prevCalcTime;	  // �P��: us

		// ���ۂ�FPS���v�Z
		// realElapsedTime�̒P�ʂ�us�Ȃ̂�s�ɕϊ�����
		m_actualFPS = (static_cast<double>(m_frameCount) / realElapsedTime) * FPS_STATS_UNIT;
		
		// �J�E���^�[���Z�b�g
		m_frameCount = 0l;
		m_calcInterval = 0.f;
		m_prevCalcTime = timeNow;
	}
}

#pragma endregion	// FpsController private methods


NS_DLG_END	// namespace ns_DxLibGame