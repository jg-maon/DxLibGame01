/**=============================================================================
	@file		Math.cpp
	@brief		���w�I�e��N���X ����
	@author		Masato Yamamoto
	@date		2015-02-20

	@par		[����]
				���w�\���N���X����
				Size
				Vector3
				Matrix4x4

	@note

		Copyright (C) 2015  M.Yamamoto
=============================================================================*/
#include "Math.h"
#include <float.h>

NS_DLG_BEGIN

namespace ns_Math
{
#pragma region Size public methods
	/**
		@brief		�R���X�g���N�^
		@param[in]	�Ȃ�
		@return		�Ȃ�
	*/
	Size::Size()
		: width(0.f)
		, height(0.f)
	{

	}
		
	/**
		@brief		�R���X�g���N�^
		@param[in]	_width	��
		@param[in]	_height	����
		@return		�Ȃ�
	*/
	Size::Size(float _width, float _height)
		: width(_width)
		, height(_height)
	{

	}

	/**
		@brief		�f�X�g���N�^
		@param[in]	�Ȃ�
		@return		�Ȃ�
	*/
	Size::~Size()
	{

	}

	/**
		@brief		�L���X�g���Z�q�̃I�[�o�[���[�h(Vector3)
		@param[in]	�Ȃ�
		@return		Size��Vector3��
	*/
	Size::operator Vector3() const { return Vector3(width, height, 0.0f); }


	
#pragma endregion	// Size public methods
	
#pragma region Vector3 public methods
	
	/**
		@brief		�R���X�g���N�^
		@param[in]	�Ȃ�
		@return		�Ȃ�
	*/
	Vector3::Vector3()
	{
		x = y = z = 0.f;
	}
	
	/**
		@brief		�R���X�g���N�^
		@param[in]	v	�x�N�g��
		@return		�Ȃ�
	*/
	Vector3::Vector3(const VECTOR& v)
	{
		x = v.x;
		y = v.y;
		z = v.z;
	}
		
	/**
		@brief		�R���X�g���N�^
		@param[in]	c	�萔
		@return		�Ȃ�
	*/
	Vector3::Vector3(const float c)
	{
		x = c;
		y = c;
		z = c;
	}
		
	/**
		@brief		�R���X�g���N�^
		@param[in]	_x	X
		@param[in]	_y	Y
		@param[in]	_z	Z
		@return		�Ȃ�
	*/
	Vector3::Vector3(float _x, float _y, float _z)
	{
		x = _x;
		y = _y;
		z = _z;
	}

	/**
		@brief		�f�X�g���N�^
		@param[in]	�Ȃ�
		@return		�Ȃ�
	*/
	Vector3::~Vector3()
	{

	}

	
	/**
		@brief		�x�N�g���𐳋K��
		@param[in]	�Ȃ�
		@return		���K�������x�N�g�����g
	*/
	Vector3& Vector3::Normalize()
	{
		float length = Norm();
		x /= length;
		y /= length;
		z /= length;
		return *this;
	}
		
#pragma endregion	// Vector3 public methods
	
#pragma region Matrix4x4 public methods

	/**
		@brief	3�����x�N�g����4�����Ɋg�����A4x4�̍s��Ɋ|����
		@param[in]	mat	�s��
		@param[in]	v	�x�N�g��
		@return		�s��~�x�N�g��
	*/
	Vector3 Matrix4x4::Matrix4x4_Mul_Vector3(const Matrix4x4& mat, const VECTOR& v) 
	{
		float v4[4] = { v.x, v.y, v.z, 1.0f };
		float rv4[4] = { 0.0f };
		for (int y = 0; y<4; y++)
			for (int x = 0; x<4; x++)
				rv4[y] += mat.m[y][x] * v4[x];
		return Vector3(rv4[0], rv4[1], rv4[2]);
	}

	/**
		@brief		3�����x�N�g���𕽍s�ړ��s��ϊ�����
		@param[in]	shiftX	X����
		@param[in]	shiftY	Y����
		@param[in]	shiftZ	Z����
		@param[in]	orig	���x�N�g��
		@return		���s�ړ��ϊ���̃x�N�g��
	*/
	Vector3 Matrix4x4::CalcVector3ShiftXYZ(float shiftX, float shiftY, float shiftZ, const VECTOR& orig)
	{
		Matrix4x4 matShift(1.0f, 0.0f, 0.0f, shiftX,
							0.0f, 1.0f, 0.0f, shiftY,
							0.0f, 0.0f, 1.0f, shiftZ,
							0.0f, 0.0f, 0.0f, 1.0f);
		return matShift * orig;
	}
	/**
		@brief		3�����x�N�g�����g��k���s��ϊ�����
		@param[in]	scaleX	X����
		@param[in]	scaleY	Y����
		@param[in]	scaleZ	Z����
		@param[in]	orig	���x�N�g��
		@return		�g��k���ϊ���̃x�N�g��
	*/
	Vector3 Matrix4x4::CalcVector3ScaleXYZ(float scaleX, float scaleY, float scaleZ, Vector3 orig)
	{
		Matrix4x4 matScale(scaleX, 0.0f, 0.0f, 0.0f,
							0.0f, scaleY, 0.0f, 0.0f,
							0.0f, 0.0f, scaleZ, 0.0f,
							0.0f, 0.0f, 0.0f, 1.0f);
		return matScale * orig;
	}
	/**
		@brief		3�����x�N�g������]�s��ϊ�����
		@param[in]	rotX	X���W�A��
		@param[in]	rotY	Y���W�A��
		@param[in]	rotZ	Z���W�A��
		@param[in]	orig	���x�N�g��
		@return		��]�ϊ���̃x�N�g��
	*/
	Vector3 Matrix4x4::CalcVector3RotationXYZ(float rotX, float rotY, float rotZ, const VECTOR& orig)
	{
		Matrix4x4 matRotation(
			::std::cosf(rotZ)*::std::cosf(rotX), ::std::cosf(rotZ)*::std::sinf(rotX)*::std::sinf(rotY) - ::std::sinf(rotZ)*::std::cosf(rotY), ::std::cosf(rotZ)*::std::sinf(rotX)*::std::cosf(rotY) + ::std::sinf(rotZ)*::std::sinf(rotY), 0.0f,
			::std::sinf(rotZ)*::std::cosf(rotX), ::std::sinf(rotZ)*::std::sinf(rotX)*::std::sinf(rotY) + ::std::cosf(rotZ)*::std::cosf(rotY), ::std::sinf(rotZ)*::std::sinf(rotX)*::std::cosf(rotY) - ::std::cosf(rotZ)*::std::sinf(rotY), 0.0f,
			-::std::sinf(rotX), ::std::cosf(rotX)*::std::sinf(rotY), ::std::cosf(rotX)*::std::cosf(rotY), 0.0f,
			0.0f, 0.0f, 0.0f, 1.0f);
		return matRotation * orig;
	}

	/**
		@brief		�P�ʍs��̎擾
		@param[in]	�Ȃ�
		@return		�Ȃ�
	*/
	Matrix4x4 Matrix4x4::GetIdentity()
	{
		Matrix4x4 mat;
		for (int i = 0; i < 4; ++i)
		{
			mat.m[i][i] = 1.0f;
		}
		return mat;
	}



	/**
		@brief		�R���X�g���N�^
		@param[in]	�Ȃ�
		@return		�Ȃ�
	*/
	Matrix4x4::Matrix4x4()
	{
		for (int i = 0; i<16; i++)
			m[i / 4][i % 4] = 0.0f;
	}

	/**
		@brief		�R���X�g���N�^
		@param[in]	c	�萔
		@return		�Ȃ�
	*/
	Matrix4x4::Matrix4x4(float c)
	{
		for (int i = 0; i < 16; i++)
			m[i / 4][i % 4] = c;
	}

	/**
		@brief		�R���X�g���N�^
		@param[in]	f	�e�v�f[�s*��]
		@return		�Ȃ�
	*/
	Matrix4x4::Matrix4x4(const float f[16])
	{
		for (int i = 0; i<16; i++)
			m[i / 4][i % 4] = f[i];
	}

	/**
		@brief		�R���X�g���N�^
		@param[in]	f	�e�v�f[�s][��]
		@return		�Ȃ�
	*/
	Matrix4x4::Matrix4x4(const float f[4][4])
	{
		for (int i = 0; i<4; i++)
			for (int j = 0; j<4; j++)
				m[i][j] = f[i][j];
	}
	/**
		@brief		�R���X�g���N�^
		@param[in]	_11 ~ _44	�e�v�f
		@return		�Ȃ�
	*/
	Matrix4x4::Matrix4x4(float _11, float _12, float _13, float _14,
						 float _21, float _22, float _23, float _24,
						 float _31, float _32, float _33, float _34,
						 float _41, float _42, float _43, float _44)
	{
		m[0][0] = _11; m[0][1] = _12; m[0][2] = _13; m[0][3] = _14;
		m[1][0] = _21; m[1][1] = _22; m[1][2] = _23; m[1][3] = _24;
		m[2][0] = _31; m[2][1] = _32; m[2][2] = _33; m[2][3] = _34;
		m[3][0] = _41; m[3][1] = _42; m[3][2] = _43; m[3][3] = _44;
	}
	
	/**
		@brief		�R���X�g���N�^
		@param[in]	mat		�s��
		@return		�Ȃ�
	*/
	Matrix4x4::Matrix4x4(const MATRIX& mat)
	{
		for (int i = 0; i < 4; ++i)
			for (int j = 0; j < 4; ++j)
				m[i][j] = mat.m[i][j];
	}
	/**
		@brief		�f�X�g���N�^
		@param[in]	�Ȃ�
		@return		�Ȃ�
	*/
	Matrix4x4::~Matrix4x4()
	{

	}
		
#pragma endregion	// Matrix4x4 public methods

}	// namespace ns_Math

NS_DLG_END