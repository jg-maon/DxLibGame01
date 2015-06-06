/**=============================================================================
	@file		Math.h
	@brief		���w�I�e��N���X ��`
	@author		Masato Yamamoto
	@date		2015-02-20

	@par		[����]
				���w�\���N���X��`
				Size
				Vector3
				Matrix4x4

	@note

		Copyright (C) 2015  M.Yamamoto
=============================================================================*/
#ifndef __MATH_H__
#define __MATH_H__

#ifndef __DXLIB_GAME_H__
#include "DxLibGame.h"
#endif

#ifndef __DXLIB
#include "DxLib.h"
#endif

#ifndef _CMATH_
#include <cmath>
#endif

#ifndef M_PI
#define M_PI	3.14159265358979323846f
#endif
#ifndef M_PI_D
#define M_PI_D	3.14159265358979323846
#endif
#ifndef M_PI_2
#define M_PI_2	1.57079632679489661923f
#endif
#ifndef M_PI_2_D
#define M_PI_2_D	1.57079632679489661923
#endif
#ifndef M_PI_4
#define M_PI_4	0.785398163397448309616f
#endif
#ifndef M_PI_4_D
#define M_PI_4_D	0.785398163397448309616
#endif

NS_DLG_BEGIN
#define NS_USE_MATH	using namespace ns_Math
namespace ns_Math
{
	class Vector3;
	class Matrix4x4;

	/**
		@class		Size
		@brief		�T�C�Y�N���X
	*/
	class Size
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
		Size();

		/**
			@brief		�R���X�g���N�^
			@param[in]	_width	��
			@param[in]	_height	����
			@return		�Ȃ�
		*/
		Size(float _width, float _height);

		
		/**
			@brief		�f�X�g���N�^
			@param[in]	�Ȃ�
			@return		�Ȃ�
		*/
		virtual ~Size();


		/**
			@brief		�L���X�g���Z�q�̃I�[�o�[���[�h(Vector3)
			@param[in]	�Ȃ�
			@return		Size��Vector3��
		*/
		operator Vector3() const;


		/**
			@brief		*���Z�q�̃I�[�o�[���[�h(�萔�{)
			@param[in]	v		�萔
			@return		�萔�{�����T�C�Y
		*/
		Size operator * (float v) const { return Size(width*v, height*v); }
		/**
			@brief		/���Z�q�̃I�[�o�[���[�h(�萔�{)
			@param[in]	v		�萔
			@return		�萔�{�����T�C�Y
		*/
		Size operator / (float v) const	{ return Size(width / v, height / v); }
		
		/**
			@brief		*=���Z�q�̃I�[�o�[���[�h(�萔�{)
			@param[in]	v		�萔
			@return		�萔�{�����T�C�Y
		*/
		Size& operator *= (float v) { width *= v; height *= v; return *this; }
		
		/**
			@brief		/=���Z�q�̃I�[�o�[���[�h(�萔�{)
			@param[in]	v		�萔
			@return		�萔�{�����T�C�Y
		*/
		Size& operator /= (float v)	{ width /= v; height /= v; return *this; }

		//------------------------------------------------
	protected:


		//------------------------------------------------
	private:

		//=====================================================
		// �ϐ��錾
		//=====================================================
	public:
		float	width;		//!< ��
		float	height;		//!< ����
	protected:

	private:

	};
	
	/**
		@class		Vector3
		@brief		3�����x�N�g���N���X
	*/
	typedef class Vector3 : public DxLib::VECTOR
	{
		//=====================================================
		// �萔(�񋓌^)�錾
		//=====================================================
	public:
		static enum eTmpReplace { X = 0x01, Y = 0x02, Z = 0x04 };
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
		/**
			2�_�̂Ȃ��p�̎擾(���W�A��)
			@param[in]	v1	�_1
			@param[in]	v2	�_2
			@return		2�_�̂Ȃ��p(���W�A��)
		*/
		static float ForAngle(const VECTOR& v1, const VECTOR& v2)
		{
			return ::std::atan2f(Cross(v1, v2).Length(), Dot(v1, v2));
		}
		/**
			@brief		�x�N�g���̓��ς��擾
			@param[in]	v1	�x�N�g��1
			@param[in]	v2	�x�N�g��2
			@return		����
		*/
		static float Dot(const VECTOR& v1, const VECTOR& v2)
		{
			return (v1.x*v2.x) + (v1.y*v2.y) + (v1.z*v2.z);
		}

		/**
			@brief		�x�N�g���̊O�ς��擾
			@param[in]	v1	�x�N�g��1
			@param[in]	v2	�x�N�g��2
			@return		�O��
		*/
		static Vector3 Cross(const VECTOR& v1, const VECTOR& v2)
		{
			return Vector3(v1.y*v2.z - v1.z*v2.y,
						   v1.z*v2.x - v1.x*v2.z,
						   v1.x*v2.y - v1.y*v2.x);
		}

		/**
			@brief		�x�N�g���̒������擾
			@param[in]	v	�x�N�g��
			@return		�x�N�g���̒���
		*/
		static float Length(const VECTOR& v)
		{ 
			return ::std::sqrtf(v.x*v.x + v.y*v.y + v.z*v.z);
		}
		/**
			@brief		�x�N�g���̒������擾
			@param[in]	v	�x�N�g��
			@return		�x�N�g���̒���
		*/
		static float Norm(const VECTOR& v)
		{
			return ::std::sqrtf(v.x*v.x + v.y*v.y + v.z*v.z);
		}



		//=====================================================
		// ���\�b�h�錾
		//=====================================================
	public:
		/**
			@brief		�R���X�g���N�^
			@param[in]	�Ȃ�
			@return		�Ȃ�
		*/
		Vector3();
		
		/**
			@brief		�R���X�g���N�^
			@param[in]	v	�x�N�g��
			@return		�Ȃ�
		*/
		Vector3(const VECTOR& v);
		
		/**
			@brief		�R���X�g���N�^
			@param[in]	c	�萔
			@return		�Ȃ�
		*/
		explicit Vector3(const float c);

		/**
			@brief		�R���X�g���N�^
			@param[in]	_x	X
			@param[in]	_y	Y
			@param[in]	_z	Z
			@return		�Ȃ�
		*/
		Vector3(float _x, float _y, float _z);

		
		/**
			@brief		�f�X�g���N�^
			@param[in]	�Ȃ�
			@return		�Ȃ�
		*/
		virtual ~Vector3();

		const Vector3 operator -()const
		{
			return Vector3(-x, -y, -z);
		}

		
		/**
			@brief		�L���X�g���Z�q�̃I�[�o�[���[�h(Size)
			@param[in]	�Ȃ�
			@return		Vector3��Size��
		*/
		operator Size() const { return Size(x, y); }

#pragma region ���Z�q�̃I�[�o�[���[�h(�x�N�g��)
		/**
			@brief		=���Z�q�̃I�[�o�[���[�h(���)
			@param[in]	v	�x�N�g��
			@return		����������g
		*/
		Vector3& operator = (const Vector3& v) { x = v.x; y = v.y; z = v.z; return *this; }
		/**
			@brief		=���Z�q�̃I�[�o�[���[�h(���)
			@param[in]	v	�x�N�g��
			@return		����������g
		*/
		Vector3& operator = (const VECTOR& v)	{ x = v.x; y = v.y; z = v.z; return *this; }
		/**
			@brief		+���Z�q�̃I�[�o�[���[�h(�萔���Z)
			@param[in]	v	�萔
			@return		�萔���Z��̃x�N�g��
		*/
		Vector3 operator + (const VECTOR& v) const { return Vector3(x + v.x, y + v.y, z + v.z);	}
		
		/**
			@brief		-���Z�q�̃I�[�o�[���[�h(�萔���Z)
			@param[in]	v	�萔
			@return		�萔���Z��̃x�N�g��
		*/
		Vector3 operator - (const VECTOR& v) const { return Vector3(x - v.x, y - v.y, z - v.z);	}
		
		/**
			@brief		*���Z�q�̃I�[�o�[���[�h(�萔�{)
			@param[in]	v	�萔
			@return		�萔�{��̃x�N�g��
		*/
		Vector3 operator * (const VECTOR& v) const { return Vector3(x * v.x, y * v.y, z * v.z);	}
		
		/**
			@brief		/���Z�q�̃I�[�o�[���[�h(�萔�{)
			@param[in]	v	�萔
			@return		�萔�{��̃x�N�g��
		*/
		Vector3 operator / (const VECTOR& v) const { return Vector3(x / v.x, y / v.y, z / v.z);	}

		
		/**
			@brief		+=���Z�q�̃I�[�o�[���[�h(�萔���Z)
			@param[in]	v	�萔
			@return		�萔���Z��̃x�N�g�����g
		*/
		Vector3& operator += (const VECTOR& v) { x += v.x; y += v.y; z += v.z; return *this; }
		
		/**
			@brief		-=���Z�q�̃I�[�o�[���[�h(�萔���Z)
			@param[in]	v	�萔
			@return		�萔���Z��̃x�N�g�����g
		*/
		Vector3& operator -= (const VECTOR& v) { x -= v.x; y -= v.y; z -= v.z; return *this; }
		
		/**
			@brief		*=���Z�q�̃I�[�o�[���[�h(�萔�{)
			@param[in]	v	�萔
			@return		�萔�{��̃x�N�g�����g
		*/
		Vector3& operator *= (const VECTOR& v) { x *= v.x; y *= v.y; z *= v.z; return *this; }
		
		/**
			@brief		/=���Z�q�̃I�[�o�[���[�h(�萔�{)
			@param[in]	v	�萔
			@return		�萔�{��̃x�N�g�����g
		*/
		Vector3& operator /= (const VECTOR& v) { x /= v.x; y /= v.y; z /= v.z; return *this; }

#pragma endregion	// ���Z�q�̃I�[�o�[���[�h(�x�N�g��)

#pragma region ���Z�q�̃I�[�o�[���[�h(�萔)
		/**
			@brief		=���Z�q�̃I�[�o�[���[�h(���)
			@param[in]	v	�x�N�g��
			@return		����������g
		*/
		Vector3& operator = (const float c)	{ x = c; y = c; z = c; return *this; }
		
		/**
			@brief		+���Z�q�̃I�[�o�[���[�h(�萔���Z)
			@param[in]	c	�萔
			@return		�萔���Z��̃x�N�g��
		*/
		Vector3 operator + (const float c) const { return Vector3(x + c, y + c, z + c);	}
		
		/**
			@brief		-���Z�q�̃I�[�o�[���[�h(�萔���Z)
			@param[in]	c	�萔
			@return		�萔���Z��̃x�N�g��
		*/
		Vector3 operator - (const float c) const { return Vector3(x - c, y - c, z - c);	}
		
		/**
			@brief		*���Z�q�̃I�[�o�[���[�h(�萔�{)
			@param[in]	c	�萔
			@return		�萔�{��̃x�N�g��
		*/
		Vector3 operator * (const float c) const { return Vector3(x * c, y * c, z * c);	}
		
		/**
			@brief		/���Z�q�̃I�[�o�[���[�h(�萔�{)
			@param[in]	c	�萔
			@return		�萔�{��̃x�N�g��
		*/
		Vector3 operator / (const float c) const { return Vector3(x / c, y / c, z / c);	}

		
		/**
			@brief		+=���Z�q�̃I�[�o�[���[�h(�萔���Z)
			@param[in]	c	�萔
			@return		�萔���Z��̃x�N�g�����g
		*/
		Vector3& operator += (const float c) { x += c; y += c; z += c; return *this; }
		
		/**
			@brief		-=���Z�q�̃I�[�o�[���[�h(�萔���Z)
			@param[in]	c	�萔
			@return		�萔���Z��̃x�N�g�����g
		*/
		Vector3& operator -= (const float c) { x -= c; y -= c; z -= c; return *this; }
		
		/**
			@brief		*=���Z�q�̃I�[�o�[���[�h(�萔�{)
			@param[in]	c	�萔
			@return		�萔�{��̃x�N�g�����g
		*/
		Vector3& operator *= (const float c) { x *= c; y *= c; z *= c; return *this; }
		
		/**
			@brief		/=���Z�q�̃I�[�o�[���[�h(�萔�{)
			@param[in]	c	�萔
			@return		�萔�{��̃x�N�g�����g
		*/
		Vector3& operator /= (const float c) { x /= c; y /= c; z /= c; return *this; }
#pragma endregion	// ���Z�q�̃I�[�o�[���[�h(�萔)


		/**
			@brief		�Ώۃx�N�g���Ƃ̓��ς��擾
			@param[in]	v	�Ώۃx�N�g��
			@return		����
		*/
		float Dot(const VECTOR& v) const { return Dot(*this, v); }

		/**
			@brief		�Ώۃx�N�g���Ƃ̊O�ς��擾
			@param[in]	v	�Ώۃx�N�g��
			@return		�O��
		*/
		Vector3 Cross(const VECTOR& v) const { return Cross(*this, v); }

		/**
			@brief		�x�N�g���̒������擾
			@param[in]	�Ȃ�
			@return		�x�N�g���̒���
		*/
		float Length() const { return Length(*this); }
		/**
			@brief		�x�N�g���̒������擾
			@param[in]	�Ȃ�
			@return		�x�N�g���̒���
		*/
		float Norm() const { return Norm(*this); }


		/**
			@brief		�x�N�g���𐳋K��
			@param[in]	�Ȃ�
			@return		���K�������x�N�g�����g
		*/
		Vector3& Normalize();

		// �ꎞ�I�ɒl��u���������x�N�g����Ԃ�
		Vector3 TmpReplace(int flag, Vector3 v)
		{
			return Vector3((flag&X) ? v.x : x, (flag&Y) ? v.y : y, (flag&Z) ? v.z : z);
		}

		//------------------------------------------------
	protected:


		//------------------------------------------------
	private:

		//=====================================================
		// �ϐ��錾
		//=====================================================
	public:
		/**
			float	x;
			float	y;
			float	z;
		*/
	protected:

	private:

	}Vector3, Vector;
	
	/**
		@class		Matrix4x4
		@brief		4�s4��s��N���X
	*/
	typedef class Matrix4x4 : public DxLib::MATRIX
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
		/**
			@brief	3�����x�N�g����4�����Ɋg�����A4x4�̍s��Ɋ|����
			@param[in]	mat	�s��
			@param[in]	v	�x�N�g��
			@return		�s��~�x�N�g��
		*/
		static Vector3 Matrix4x4_Mul_Vector3(const Matrix4x4& mat, const VECTOR& v);

		/**
			@brief		3�����x�N�g���𕽍s�ړ��s��ϊ�����
			@param[in]	shiftX	X����
			@param[in]	shiftY	Y����
			@param[in]	shiftZ	Z����
			@param[in]	orig	���x�N�g��
			@return		���s�ړ��ϊ���̃x�N�g��
		*/
		static Vector3 CalcVector3ShiftXYZ(float shiftX, float shiftY, float shiftZ, const VECTOR& orig);

		/**
			@brief		3�����x�N�g�����g��k���s��ϊ�����
			@param[in]	scaleX	X����
			@param[in]	scaleY	Y����
			@param[in]	scaleZ	Z����
			@param[in]	orig	���x�N�g��
			@return		�g��k���ϊ���̃x�N�g��
		*/
		static Vector3 CalcVector3ScaleXYZ(float scaleX, float scaleY, float scaleZ, Vector3 orig);

		/**
			@brief		3�����x�N�g������]�s��ϊ�����
			@param[in]	rotX	X���W�A��
			@param[in]	rotY	Y���W�A��
			@param[in]	rotZ	Z���W�A��
			@param[in]	orig	���x�N�g��
			@return		��]�ϊ���̃x�N�g��
		*/
		static Vector3 CalcVector3RotationXYZ(float rotX, float rotY, float rotZ, const VECTOR& orig);

		/**
			@brief		�P�ʍs��̎擾
			@param[in]	�Ȃ�
			@return		�Ȃ�
		*/
		static Matrix4x4 GetIdentity();
		//=====================================================
		// ���\�b�h�錾
		//=====================================================
	public:
		/**
			@brief		�R���X�g���N�^
			@param[in]	�Ȃ�
			@return		�Ȃ�
		*/
		Matrix4x4();

		/**
			@brief		�R���X�g���N�^
			@param[in]	c	�萔
			@return		�Ȃ�
		*/
		Matrix4x4(float c);
		
		/**
			@brief		�R���X�g���N�^
			@param[in]	f	�e�v�f[�s*��]
			@return		�Ȃ�
		*/
		Matrix4x4(const float f[16]);
		
		/**
			@brief		�R���X�g���N�^
			@param[in]	f	�e�v�f[�s][��]
			@return		�Ȃ�
		*/
		Matrix4x4(const float f[4][4]);
		
		/**
			@brief		�R���X�g���N�^
			@param[in]	_11 ~ _44	�e�v�f
			@return		�Ȃ�
		*/
		Matrix4x4(float _11, float _12, float _13, float _14,
				  float _21, float _22, float _23, float _24,
				  float _31, float _32, float _33, float _34,
				  float _41, float _42, float _43, float _44);

		/**
			@brief		�R���X�g���N�^
			@param[in]	mat		�s��
			@return		�Ȃ�
		*/
		Matrix4x4(const MATRIX& mat);

		
		/**
			@brief		�f�X�g���N�^
			@param[in]	�Ȃ�
			@return		�Ȃ�
		*/
		virtual ~Matrix4x4();
		
		/**
			@brief		���Z�q�̃I�[�o�[���[�h(���)
			@param[in]	mat		�s��
			@return		�s�񎩐g
		*/
		Matrix4x4& operator = (const MATRIX& mat)
		{
			for (int i = 0; i < 4; ++i)
				for (int j = 0; j < 4; ++j)
					m[i][j] = mat.m[i][j];
			return *this;
		}
		
		/**
			@brief		�x�N�g���ϊ�
			@param[in]	v	�x�N�g��
			@return		�Ȃ�
		*/
		Vector3	operator*(const VECTOR& v) { return Matrix4x4_Mul_Vector3(*this, v); }


		//------------------------------------------------
	protected:


		//------------------------------------------------
	private:

		//=====================================================
		// �ϐ��錾
		//=====================================================
	public:
	protected:

	private:

	}Matrix4x4, Matrix;

}	// namespace ns_Math

NS_DLG_END	// namespace ns_DxLibGame

#endif	// __MATH_H__