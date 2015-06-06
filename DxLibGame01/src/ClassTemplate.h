/**=============================================================================
	@file		ClassTemplate.h
	@brief		�N���X�L�q��N���X ��`
	@author		Masato Yamamoto
	@date		2015-02-20

	@par		[����]
				�N���X��`�t�@�C���̋L�q��

	@note

		Copyright (C) 2015  M.Yamamoto
=============================================================================*/
#ifndef __CLASS_TEMPLATE_H__
#define __CLASS_TEMPLATE_H__

#ifndef __DXLIB_GAME_H__
#include "DxLibGame.h"
#endif

#ifndef __REF_H__
#include "Ref.h"
#endif

NS_DLG_BEGIN
/**
	@class		ClassTemplate
	@brief		�N���X�e���v���[�g
*/
class ClassTemplate : public Ref
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
	ClassTemplate();
		
	/**
		@brief		�f�X�g���N�^
		@param[in]	�Ȃ�
		@return		�Ȃ�
	*/
	virtual ~ClassTemplate();
		
	/**
		@brief		�֐��̊T�v
		@param[in]	�Ȃ�
		@return		�Ȃ�
	*/
	void PublicMethod();

	//------------------------------------------------
protected:
	/**
		@brief		�֐��̊T�v
		@param[in]	param		�����̐���
		@return		�߂�l�̐���
		@retval		0	���퐬��
		@retval		-1	�G���[
	*/
	int _ProtectedMethod(int param);


	//------------------------------------------------
private:
	/**
		@brief		�֐��̊T�v
		@param[in]	param		�����̐���
		@return		�߂�l�̐���
		@retval		-1	�G���[
	*/
	int _PrivateMethod(int param);

	//=====================================================
	// �ϐ��錾
	//=====================================================
//public:
protected:

private:

};


NS_DLG_END	// namespace ns_DxLibGame

#endif	// __CLASS_TEMPLATE_H__