/**=============================================================================
	@file		FpsController.h
	@brief		FPS�Œ�p�N���X ��`
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
	@brief		FPS�Œ�p�N���X
*/
class FpsController : public Ref
{
	//=====================================================
	// �萔(�񋓌^)�錾
	//=====================================================
public:
	static const LONGLONG FPS_STATS_UNIT;		//!< ���ԒP��
	static const double FPS_STATS_INTERVAL;		//!< �v���Ԋu

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
		@param[in]	fps		�Œ肷��FPS�l(�f�t�H���g:60)
		@return		�Ȃ�
	*/
	FpsController(int fps = 60);
		
	/**
		@brief		�f�X�g���N�^
		@param[in]	�Ȃ�
		@return		�Ȃ�
	*/
	virtual ~FpsController();

	/**
		@brief		�r����FPS��ύX�������ۂɌĂ�
		@param[in]	fps		�Œ肷��FPS�l(�f�t�H���g:60)
		@return		�Ȃ�
	*/
	void SetFPS(int fps);
	
	/**
		@brief		FPS�\��
		@param[in]	x	�`��n�_X
		@param[in]	y	�`��n�_Y
		@return		�Ȃ�
	*/
	void Draw(float x, float y) const;

	/**
		@brief		�ݒ肵��FPS�̒l�ɂȂ�悤��sleep���Ԃ𐧌䂷��		
		@param[in]	�Ȃ�
		@return		�`��\��
		@retval		true	�`��\
		@retval		false	�`��s��
	*/
	bool Wait();
	
	/**
		@brief		�t���[���^�C���̎擾
		@param[in]	�Ȃ�
		@return		�t���[���^�C��
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
		@brief		�x�~���Ԃ��v�Z����
		@param[in]	�Ȃ�
		@return		�Ȃ�
	*/
	void _CalcSleepTime();
	
	/**
		@brief		�ҋ@�����̎��Ԍ덷�𐮂���
		@param[in]	�Ȃ�
		@return		�Ȃ�
	*/
	void _NotifyOverSleepTime();
	
	
	/**
		@brief		FPS�v��,�v�Z
		@param[in]	�Ȃ�
		@return		�Ȃ�
	*/
	void _CalcFPS(void);

	//=====================================================
	// �ϐ��錾
	//=====================================================
//public:
protected:

private:
	int			m_fps;				//!< ���z��FPS
	float		m_waitTime;			//!< ���zFPS����1�t���[���̑҂�����
	//------------------------------------
	// FPS�v�Z�p
	float		m_calcInterval;		//!< fps�␳�Ԋu
	LONGLONG	m_prevCalcTime;		//!< �O��v������

	double		m_actualFPS;		//!< ���ۂ�FPS
	long		m_frameCount;		//!< �t���[����

	//------------------------------------
	// FPS�v��
	LONGLONG	m_beforeTime;		//!< �O�t���[������
	LONGLONG	m_afterTime;		//!< ���t���[��(�Čv����)����
	static LONGLONG	m_sleepTime;		//!< �x�~����

	LONGLONG	m_overSleepTime;	//!< �x�~�����덷

	int			m_noDelays;			//!< �x�~���Ԃ����Ȃ��ꍇ�̉�
	bool		m_skipWait;			//!< �x�~�����X�L�b�v�t���O

};

NS_DLG_END	// namespace ns_DxLibGame

#endif	// __FPS_CONTROLLER_H__