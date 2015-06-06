/**=============================================================================
	@file		Math.h
	@brief		数学的各種クラス 定義
	@author		Masato Yamamoto
	@date		2015-02-20

	@par		[説明]
				数学表現クラス定義
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
		@brief		サイズクラス
	*/
	class Size
	{
		//=====================================================
		// 定数(列挙型)宣言
		//=====================================================
	public:
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
			@param[in]	なし
			@return		なし
		*/
		Size();

		/**
			@brief		コンストラクタ
			@param[in]	_width	幅
			@param[in]	_height	高さ
			@return		なし
		*/
		Size(float _width, float _height);

		
		/**
			@brief		デストラクタ
			@param[in]	なし
			@return		なし
		*/
		virtual ~Size();


		/**
			@brief		キャスト演算子のオーバーロード(Vector3)
			@param[in]	なし
			@return		SizeをVector3に
		*/
		operator Vector3() const;


		/**
			@brief		*演算子のオーバーロード(定数倍)
			@param[in]	v		定数
			@return		定数倍したサイズ
		*/
		Size operator * (float v) const { return Size(width*v, height*v); }
		/**
			@brief		/演算子のオーバーロード(定数倍)
			@param[in]	v		定数
			@return		定数倍したサイズ
		*/
		Size operator / (float v) const	{ return Size(width / v, height / v); }
		
		/**
			@brief		*=演算子のオーバーロード(定数倍)
			@param[in]	v		定数
			@return		定数倍したサイズ
		*/
		Size& operator *= (float v) { width *= v; height *= v; return *this; }
		
		/**
			@brief		/=演算子のオーバーロード(定数倍)
			@param[in]	v		定数
			@return		定数倍したサイズ
		*/
		Size& operator /= (float v)	{ width /= v; height /= v; return *this; }

		//------------------------------------------------
	protected:


		//------------------------------------------------
	private:

		//=====================================================
		// 変数宣言
		//=====================================================
	public:
		float	width;		//!< 幅
		float	height;		//!< 高さ
	protected:

	private:

	};
	
	/**
		@class		Vector3
		@brief		3次元ベクトルクラス
	*/
	typedef class Vector3 : public DxLib::VECTOR
	{
		//=====================================================
		// 定数(列挙型)宣言
		//=====================================================
	public:
		static enum eTmpReplace { X = 0x01, Y = 0x02, Z = 0x04 };
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
		/**
			2点のなす角の取得(ラジアン)
			@param[in]	v1	点1
			@param[in]	v2	点2
			@return		2点のなす角(ラジアン)
		*/
		static float ForAngle(const VECTOR& v1, const VECTOR& v2)
		{
			return ::std::atan2f(Cross(v1, v2).Length(), Dot(v1, v2));
		}
		/**
			@brief		ベクトルの内積を取得
			@param[in]	v1	ベクトル1
			@param[in]	v2	ベクトル2
			@return		内積
		*/
		static float Dot(const VECTOR& v1, const VECTOR& v2)
		{
			return (v1.x*v2.x) + (v1.y*v2.y) + (v1.z*v2.z);
		}

		/**
			@brief		ベクトルの外積を取得
			@param[in]	v1	ベクトル1
			@param[in]	v2	ベクトル2
			@return		外積
		*/
		static Vector3 Cross(const VECTOR& v1, const VECTOR& v2)
		{
			return Vector3(v1.y*v2.z - v1.z*v2.y,
						   v1.z*v2.x - v1.x*v2.z,
						   v1.x*v2.y - v1.y*v2.x);
		}

		/**
			@brief		ベクトルの長さを取得
			@param[in]	v	ベクトル
			@return		ベクトルの長さ
		*/
		static float Length(const VECTOR& v)
		{ 
			return ::std::sqrtf(v.x*v.x + v.y*v.y + v.z*v.z);
		}
		/**
			@brief		ベクトルの長さを取得
			@param[in]	v	ベクトル
			@return		ベクトルの長さ
		*/
		static float Norm(const VECTOR& v)
		{
			return ::std::sqrtf(v.x*v.x + v.y*v.y + v.z*v.z);
		}



		//=====================================================
		// メソッド宣言
		//=====================================================
	public:
		/**
			@brief		コンストラクタ
			@param[in]	なし
			@return		なし
		*/
		Vector3();
		
		/**
			@brief		コンストラクタ
			@param[in]	v	ベクトル
			@return		なし
		*/
		Vector3(const VECTOR& v);
		
		/**
			@brief		コンストラクタ
			@param[in]	c	定数
			@return		なし
		*/
		explicit Vector3(const float c);

		/**
			@brief		コンストラクタ
			@param[in]	_x	X
			@param[in]	_y	Y
			@param[in]	_z	Z
			@return		なし
		*/
		Vector3(float _x, float _y, float _z);

		
		/**
			@brief		デストラクタ
			@param[in]	なし
			@return		なし
		*/
		virtual ~Vector3();

		const Vector3 operator -()const
		{
			return Vector3(-x, -y, -z);
		}

		
		/**
			@brief		キャスト演算子のオーバーロード(Size)
			@param[in]	なし
			@return		Vector3をSizeに
		*/
		operator Size() const { return Size(x, y); }

#pragma region 演算子のオーバーロード(ベクトル)
		/**
			@brief		=演算子のオーバーロード(代入)
			@param[in]	v	ベクトル
			@return		代入した自身
		*/
		Vector3& operator = (const Vector3& v) { x = v.x; y = v.y; z = v.z; return *this; }
		/**
			@brief		=演算子のオーバーロード(代入)
			@param[in]	v	ベクトル
			@return		代入した自身
		*/
		Vector3& operator = (const VECTOR& v)	{ x = v.x; y = v.y; z = v.z; return *this; }
		/**
			@brief		+演算子のオーバーロード(定数加算)
			@param[in]	v	定数
			@return		定数加算後のベクトル
		*/
		Vector3 operator + (const VECTOR& v) const { return Vector3(x + v.x, y + v.y, z + v.z);	}
		
		/**
			@brief		-演算子のオーバーロード(定数減算)
			@param[in]	v	定数
			@return		定数減算後のベクトル
		*/
		Vector3 operator - (const VECTOR& v) const { return Vector3(x - v.x, y - v.y, z - v.z);	}
		
		/**
			@brief		*演算子のオーバーロード(定数倍)
			@param[in]	v	定数
			@return		定数倍後のベクトル
		*/
		Vector3 operator * (const VECTOR& v) const { return Vector3(x * v.x, y * v.y, z * v.z);	}
		
		/**
			@brief		/演算子のオーバーロード(定数倍)
			@param[in]	v	定数
			@return		定数倍後のベクトル
		*/
		Vector3 operator / (const VECTOR& v) const { return Vector3(x / v.x, y / v.y, z / v.z);	}

		
		/**
			@brief		+=演算子のオーバーロード(定数加算)
			@param[in]	v	定数
			@return		定数加算後のベクトル自身
		*/
		Vector3& operator += (const VECTOR& v) { x += v.x; y += v.y; z += v.z; return *this; }
		
		/**
			@brief		-=演算子のオーバーロード(定数減算)
			@param[in]	v	定数
			@return		定数減算後のベクトル自身
		*/
		Vector3& operator -= (const VECTOR& v) { x -= v.x; y -= v.y; z -= v.z; return *this; }
		
		/**
			@brief		*=演算子のオーバーロード(定数倍)
			@param[in]	v	定数
			@return		定数倍後のベクトル自身
		*/
		Vector3& operator *= (const VECTOR& v) { x *= v.x; y *= v.y; z *= v.z; return *this; }
		
		/**
			@brief		/=演算子のオーバーロード(定数倍)
			@param[in]	v	定数
			@return		定数倍後のベクトル自身
		*/
		Vector3& operator /= (const VECTOR& v) { x /= v.x; y /= v.y; z /= v.z; return *this; }

#pragma endregion	// 演算子のオーバーロード(ベクトル)

#pragma region 演算子のオーバーロード(定数)
		/**
			@brief		=演算子のオーバーロード(代入)
			@param[in]	v	ベクトル
			@return		代入した自身
		*/
		Vector3& operator = (const float c)	{ x = c; y = c; z = c; return *this; }
		
		/**
			@brief		+演算子のオーバーロード(定数加算)
			@param[in]	c	定数
			@return		定数加算後のベクトル
		*/
		Vector3 operator + (const float c) const { return Vector3(x + c, y + c, z + c);	}
		
		/**
			@brief		-演算子のオーバーロード(定数減算)
			@param[in]	c	定数
			@return		定数減算後のベクトル
		*/
		Vector3 operator - (const float c) const { return Vector3(x - c, y - c, z - c);	}
		
		/**
			@brief		*演算子のオーバーロード(定数倍)
			@param[in]	c	定数
			@return		定数倍後のベクトル
		*/
		Vector3 operator * (const float c) const { return Vector3(x * c, y * c, z * c);	}
		
		/**
			@brief		/演算子のオーバーロード(定数倍)
			@param[in]	c	定数
			@return		定数倍後のベクトル
		*/
		Vector3 operator / (const float c) const { return Vector3(x / c, y / c, z / c);	}

		
		/**
			@brief		+=演算子のオーバーロード(定数加算)
			@param[in]	c	定数
			@return		定数加算後のベクトル自身
		*/
		Vector3& operator += (const float c) { x += c; y += c; z += c; return *this; }
		
		/**
			@brief		-=演算子のオーバーロード(定数減算)
			@param[in]	c	定数
			@return		定数減算後のベクトル自身
		*/
		Vector3& operator -= (const float c) { x -= c; y -= c; z -= c; return *this; }
		
		/**
			@brief		*=演算子のオーバーロード(定数倍)
			@param[in]	c	定数
			@return		定数倍後のベクトル自身
		*/
		Vector3& operator *= (const float c) { x *= c; y *= c; z *= c; return *this; }
		
		/**
			@brief		/=演算子のオーバーロード(定数倍)
			@param[in]	c	定数
			@return		定数倍後のベクトル自身
		*/
		Vector3& operator /= (const float c) { x /= c; y /= c; z /= c; return *this; }
#pragma endregion	// 演算子のオーバーロード(定数)


		/**
			@brief		対象ベクトルとの内積を取得
			@param[in]	v	対象ベクトル
			@return		内積
		*/
		float Dot(const VECTOR& v) const { return Dot(*this, v); }

		/**
			@brief		対象ベクトルとの外積を取得
			@param[in]	v	対象ベクトル
			@return		外積
		*/
		Vector3 Cross(const VECTOR& v) const { return Cross(*this, v); }

		/**
			@brief		ベクトルの長さを取得
			@param[in]	なし
			@return		ベクトルの長さ
		*/
		float Length() const { return Length(*this); }
		/**
			@brief		ベクトルの長さを取得
			@param[in]	なし
			@return		ベクトルの長さ
		*/
		float Norm() const { return Norm(*this); }


		/**
			@brief		ベクトルを正規化
			@param[in]	なし
			@return		正規化したベクトル自身
		*/
		Vector3& Normalize();

		// 一時的に値を置き換えたベクトルを返す
		Vector3 TmpReplace(int flag, Vector3 v)
		{
			return Vector3((flag&X) ? v.x : x, (flag&Y) ? v.y : y, (flag&Z) ? v.z : z);
		}

		//------------------------------------------------
	protected:


		//------------------------------------------------
	private:

		//=====================================================
		// 変数宣言
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
		@brief		4行4列行列クラス
	*/
	typedef class Matrix4x4 : public DxLib::MATRIX
	{
		//=====================================================
		// 定数(列挙型)宣言
		//=====================================================
	public:
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
		/**
			@brief	3次元ベクトルを4次元に拡張し、4x4の行列に掛ける
			@param[in]	mat	行列
			@param[in]	v	ベクトル
			@return		行列×ベクトル
		*/
		static Vector3 Matrix4x4_Mul_Vector3(const Matrix4x4& mat, const VECTOR& v);

		/**
			@brief		3次元ベクトルを平行移動行列変換する
			@param[in]	shiftX	X成分
			@param[in]	shiftY	Y成分
			@param[in]	shiftZ	Z成分
			@param[in]	orig	元ベクトル
			@return		平行移動変換後のベクトル
		*/
		static Vector3 CalcVector3ShiftXYZ(float shiftX, float shiftY, float shiftZ, const VECTOR& orig);

		/**
			@brief		3次元ベクトルを拡大縮小行列変換する
			@param[in]	scaleX	X成分
			@param[in]	scaleY	Y成分
			@param[in]	scaleZ	Z成分
			@param[in]	orig	元ベクトル
			@return		拡大縮小変換後のベクトル
		*/
		static Vector3 CalcVector3ScaleXYZ(float scaleX, float scaleY, float scaleZ, Vector3 orig);

		/**
			@brief		3次元ベクトルを回転行列変換する
			@param[in]	rotX	Xラジアン
			@param[in]	rotY	Yラジアン
			@param[in]	rotZ	Zラジアン
			@param[in]	orig	元ベクトル
			@return		回転変換後のベクトル
		*/
		static Vector3 CalcVector3RotationXYZ(float rotX, float rotY, float rotZ, const VECTOR& orig);

		/**
			@brief		単位行列の取得
			@param[in]	なし
			@return		なし
		*/
		static Matrix4x4 GetIdentity();
		//=====================================================
		// メソッド宣言
		//=====================================================
	public:
		/**
			@brief		コンストラクタ
			@param[in]	なし
			@return		なし
		*/
		Matrix4x4();

		/**
			@brief		コンストラクタ
			@param[in]	c	定数
			@return		なし
		*/
		Matrix4x4(float c);
		
		/**
			@brief		コンストラクタ
			@param[in]	f	各要素[行*列]
			@return		なし
		*/
		Matrix4x4(const float f[16]);
		
		/**
			@brief		コンストラクタ
			@param[in]	f	各要素[行][列]
			@return		なし
		*/
		Matrix4x4(const float f[4][4]);
		
		/**
			@brief		コンストラクタ
			@param[in]	_11 ~ _44	各要素
			@return		なし
		*/
		Matrix4x4(float _11, float _12, float _13, float _14,
				  float _21, float _22, float _23, float _24,
				  float _31, float _32, float _33, float _34,
				  float _41, float _42, float _43, float _44);

		/**
			@brief		コンストラクタ
			@param[in]	mat		行列
			@return		なし
		*/
		Matrix4x4(const MATRIX& mat);

		
		/**
			@brief		デストラクタ
			@param[in]	なし
			@return		なし
		*/
		virtual ~Matrix4x4();
		
		/**
			@brief		演算子のオーバーロード(代入)
			@param[in]	mat		行列
			@return		行列自身
		*/
		Matrix4x4& operator = (const MATRIX& mat)
		{
			for (int i = 0; i < 4; ++i)
				for (int j = 0; j < 4; ++j)
					m[i][j] = mat.m[i][j];
			return *this;
		}
		
		/**
			@brief		ベクトル変換
			@param[in]	v	ベクトル
			@return		なし
		*/
		Vector3	operator*(const VECTOR& v) { return Matrix4x4_Mul_Vector3(*this, v); }


		//------------------------------------------------
	protected:


		//------------------------------------------------
	private:

		//=====================================================
		// 変数宣言
		//=====================================================
	public:
	protected:

	private:

	}Matrix4x4, Matrix;

}	// namespace ns_Math

NS_DLG_END	// namespace ns_DxLibGame

#endif	// __MATH_H__