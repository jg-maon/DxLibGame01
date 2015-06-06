/**=============================================================================
	@file		Color.h
	@brief		色クラス 定義
	@author		Masato Yamamoto
	@date		2015-02-21

	@par		[説明]
				色(RGB,ARGB,HSV)クラス

	@note

		Copyright (C) 2015  M.Yamamoto
=============================================================================*/
#ifndef __COLOR_H__
#define __COLOR_H__

#define USING_NS_COLOR using namespace color

namespace color
{
class Color3F;
class Color4B;
class Color4F;
class ColorHSV;
/**
	@class		Color3B
	@brief		RGBクラス(0~255)
*/
typedef class Color3B
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
	typedef unsigned char BYTE;

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
	Color3B();
	/**
		@brief		コンストラクタ
		@param[in]	_r	赤
		@param[in]	_g	緑
		@param[in]	_b	青
		@return		なし
	*/
	Color3B(BYTE _r, BYTE _g, BYTE _b);
	
	/**
		@brief		コンストラクタ
		@param[in]	color	RGBカラー
		@return		なし
	*/
	explicit Color3B(const Color3F& color);
	/**
		@brief		コンストラクタ
		@param[in]	color	ARGBカラー
		@return		なし
	*/
	explicit Color3B(const Color4B& color);
	/**
		@brief		コンストラクタ
		@param[in]	color	ARGBカラー
		@return		なし
	*/
	explicit Color3B(const Color4F& color);
	/**
		@brief		コンストラクタ
		@param[in]	color	HSVカラー
		@return		なし
	*/
	explicit Color3B(const ColorHSV& color);
	
	/**
		@brief		u_intとしてRGB値の取得
		@param[in]	なし
		@return		RGB(0x00rrggbb)
	*/
	unsigned int GetRGB() const
	{
		return static_cast<unsigned int>((r << 16) | (g << 8) | (b));
	}

	/**
		@brief		u_intとしてXRGB値の取得
		@param[in]	なし
		@return		XRGB(0xFFrrggbb)
	*/
	unsigned int GetXRGB() const
	{
		return static_cast<unsigned int>((0xFF << 24) | (r << 16) | (g << 8) | (b));
	}

	/**
		@brief		ノーマライズ(正規範囲内に値を収める)
		@param[in]	なし
		@return		正規化した自身
	*/
	Color3B& Normalize();
	
protected:



private:

	//=====================================================
	// 変数宣言
	//=====================================================
public:
	BYTE	r;		//!< red
	BYTE	g;		//!< green
	BYTE	b;		//!< blue
protected:

private:


}Color3B, RGB, ColorRGB;

/**
	@class		Color3F
	@brief		RGBクラス(0.0f~1.0f)
*/
typedef class Color3F
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
	typedef float FLOAT;

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
	Color3F();
	/**
		@brief		コンストラクタ
		@param[in]	_r	赤
		@param[in]	_g	緑
		@param[in]	_b	青
		@return		なし
	*/
	Color3F(FLOAT _r, FLOAT _g, FLOAT _b);

	/**
		@brief		コンストラクタ
		@param[in]	color	RGBカラー
		@return		なし
	*/
	explicit Color3F(const Color3B& color);
	/**
		@brief		コンストラクタ
		@param[in]	color	ARGBカラー
		@return		なし
	*/
	explicit Color3F(const Color4B& color);
	/**
		@brief		コンストラクタ
		@param[in]	color	ARGBカラー
		@return		なし
	*/
	explicit Color3F(const Color4F& color);
	/**
		@brief		コンストラクタ
		@param[in]	color	HSVカラー
		@return		なし
	*/
	explicit Color3F(const ColorHSV& color);
	
	/**
		@brief		u_intとしてRGB値の取得
		@param[in]	なし
		@return		RGB(0x00rrggbb)
	*/
	unsigned int GetRGB() const
	{
		unsigned int r = static_cast<unsigned int>(this->r*255.f);
		unsigned int g = static_cast<unsigned int>(this->g*255.f);
		unsigned int b = static_cast<unsigned int>(this->b*255.f);
		return static_cast<unsigned int>((r << 16) | (g << 8) | (b));
	}

	/**
		@brief		u_intとしてXRGB値の取得
		@param[in]	なし
		@return		XRGB(0xFFrrggbb)
	*/
	unsigned int GetXRGB() const
	{
		unsigned int r = static_cast<unsigned int>(this->r*255.f);
		unsigned int g = static_cast<unsigned int>(this->g*255.f);
		unsigned int b = static_cast<unsigned int>(this->b*255.f);
		return static_cast<unsigned int>((0xFF << 24) | (r << 16) | (g << 8) | (b));
	}
	
	/**
		@brief		ノーマライズ(正規範囲内に値を収める)
		@param[in]	なし
		@return		正規化した自身
	*/
	Color3F& Normalize();

	
protected:



private:

	//=====================================================
	// 変数宣言
	//=====================================================
public:
	FLOAT	r;		//!< red
	FLOAT	g;		//!< green
	FLOAT	b;		//!< blue
protected:

private:


}Color3F;

/**
	@class		Color4B
	@brief		ARGBクラス(0~255)
*/
typedef class Color4B
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
	typedef unsigned char BYTE;

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
	Color4B();
	/**
		@brief		コンストラクタ
		@param[in]	_a	透明度
		@param[in]	_r	赤
		@param[in]	_g	緑
		@param[in]	_b	青
		@return		なし
	*/
	Color4B(BYTE _a, BYTE _r, BYTE _g, BYTE _b);
	
	/**
		@brief		コンストラクタ
		@param[in]	color	RGBカラー
		@return		なし
	*/
	explicit Color4B(const Color3B& color);
	/**
		@brief		コンストラクタ
		@param[in]	color	RGBカラー
		@return		なし
	*/
	explicit Color4B(const Color3F& color);
	/**
		@brief		コンストラクタ
		@param[in]	color	ARGBカラー
		@return		なし
	*/
	explicit Color4B(const Color4F& color);
	/**
		@brief		コンストラクタ
		@param[in]	color	HSVカラー
		@return		なし
	*/
	explicit Color4B(const ColorHSV& color);

	
	/**
		@brief		u_intとしてRGB値の取得
		@param[in]	なし
		@return		RGB(0x00rrggbb)
	*/
	unsigned int GetRGB() const
	{
		return static_cast<unsigned int>((r << 16) | (g << 8) | (b));
	}

	/**
		@brief		u_intとしてXRGB値の取得
		@param[in]	なし
		@return		XRGB(0xFFrrggbb)
	*/
	unsigned int GetXRGB() const
	{
		return static_cast<unsigned int>((0xFF << 24) | (r << 16) | (g << 8) | (b));
	}
	
	/**
		@brief		u_intとしてARGB値の取得
		@param[in]	なし
		@return		ARGB(0xaarrggbb)
	*/
	unsigned int GetARGB() const
	{
		return static_cast<unsigned int>((a << 24) | (r << 16) | (g << 8) | (b));
	}
	/**
		@brief		u_intとしてRGBA値の取得
		@param[in]	なし
		@return		RGBA(0xrrggbbaa)
	*/
	unsigned int GetRGBA() const
	{
		return static_cast<unsigned int>((r << 24) | (g << 16) | (b << 8) | (a));
	}
	/**
		@brief		u_intとしてBGRA値の取得
		@param[in]	なし
		@return		BGRA(0xbbggrraa)
	*/
	unsigned int GetBGRA() const
	{
		return static_cast<unsigned int>((b << 24) | (g << 16) | (r << 8) | (a));
	}


	/**
		@brief		ノーマライズ(正規範囲内に値を収める)
		@param[in]	なし
		@return		正規化した自身
	*/
	Color4B& Normalize();
	
	
protected:



private:

	//=====================================================
	// 変数宣言
	//=====================================================
public:
	BYTE	a;		//!< alpha
	BYTE	r;		//!< red
	BYTE	g;		//!< green
	BYTE	b;		//!< blue
	
protected:

private:


}Color4B, ARGB, ColorARGB;

/**
	@class		Color4F
	@brief		ARGBクラス(0.0f~1.0f)
*/
typedef class Color4F
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
	typedef float FLOAT;

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
	Color4F();
	/**
		@brief		コンストラクタ
		@param[in]	_a	透明度
		@param[in]	_r	赤
		@param[in]	_g	緑
		@param[in]	_b	青
		@return		なし
	*/
	Color4F(FLOAT _a, FLOAT _r, FLOAT _g, FLOAT _b);

	
	/**
		@brief		コンストラクタ
		@param[in]	color	RGBカラー
		@return		なし
	*/
	explicit Color4F(const Color3B& color);
	/**
		@brief		コンストラクタ
		@param[in]	color	ARGBカラー
		@return		なし
	*/
	explicit Color4F(const Color3F& color);
	/**
		@brief		コンストラクタ
		@param[in]	color	ARGBカラー
		@return		なし
	*/
	explicit Color4F(const Color4B& color);
	/**
		@brief		コンストラクタ
		@param[in]	color	HSVカラー
		@return		なし
	*/
	explicit Color4F(const ColorHSV& color);

	
	/**
		@brief		u_intとしてRGB値の取得
		@param[in]	なし
		@return		RGB(0x00rrggbb)
	*/
	unsigned int GetRGB() const
	{
		unsigned int r = static_cast<unsigned int>(this->r*255.f);
		unsigned int g = static_cast<unsigned int>(this->g*255.f);
		unsigned int b = static_cast<unsigned int>(this->b*255.f);
		return static_cast<unsigned int>((r << 16) | (g << 8) | (b));
	}

	/**
		@brief		u_intとしてXRGB値の取得
		@param[in]	なし
		@return		XRGB(0xFFrrggbb)
	*/
	unsigned int GetXRGB() const
	{
		unsigned int r = static_cast<unsigned int>(this->r*255.f);
		unsigned int g = static_cast<unsigned int>(this->g*255.f);
		unsigned int b = static_cast<unsigned int>(this->b*255.f);
		return static_cast<unsigned int>((0xFF << 24) | (r << 16) | (g << 8) | (b));
	}
	
	/**
		@brief		u_intとしてARGB値の取得
		@param[in]	なし
		@return		ARGB(0xaarrggbb)
	*/
	unsigned int GetARGB() const
	{
		unsigned int a = static_cast<unsigned int>(this->a*255.f);
		unsigned int r = static_cast<unsigned int>(this->r*255.f);
		unsigned int g = static_cast<unsigned int>(this->g*255.f);
		unsigned int b = static_cast<unsigned int>(this->b*255.f);
		return static_cast<unsigned int>((a << 24) | (r << 16) | (g << 8) | (b));
	}
	/**
		@brief		u_intとしてRGBA値の取得
		@param[in]	なし
		@return		RGBA(0xrrggbbaa)
	*/
	unsigned int GetRGBA() const
	{
		unsigned int a = static_cast<unsigned int>(this->a*255.f);
		unsigned int r = static_cast<unsigned int>(this->r*255.f);
		unsigned int g = static_cast<unsigned int>(this->g*255.f);
		unsigned int b = static_cast<unsigned int>(this->b*255.f);
		return static_cast<unsigned int>((r << 24) | (g << 16) | (b << 8) | (a));
	}
	/**
		@brief		u_intとしてBGRA値の取得
		@param[in]	なし
		@return		BGRA(0xbbggrraa)
	*/
	unsigned int GetBGRA() const
	{
		unsigned int a = static_cast<unsigned int>(this->a*255.f);
		unsigned int r = static_cast<unsigned int>(this->r*255.f);
		unsigned int g = static_cast<unsigned int>(this->g*255.f);
		unsigned int b = static_cast<unsigned int>(this->b*255.f);
		return static_cast<unsigned int>((b << 24) | (g << 16) | (r << 8) | (a));
	}
	/**
		@brief		ノーマライズ(正規範囲内に値を収める)
		@param[in]	なし
		@return		正規化した自身
	*/
	Color4F& Normalize();
	
protected:



private:

	//=====================================================
	// 変数宣言
	//=====================================================
public:
	FLOAT	a;		//!< alpha
	FLOAT	r;		//!< red
	FLOAT	g;		//!< green
	FLOAT	b;		//!< blue
	
protected:

private:


}Color4F;

/**
	@class		ColorHSV
	@brief		HSVクラス(0.0f~1.0f)
*/
typedef class ColorHSV
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
	typedef float FLOAT;

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
	ColorHSV();
	/**
		@brief		コンストラクタ
		@param[in]	_h	色相
		@param[in]	_s	彩度
		@param[in]	_v	明度
		@return		なし
	*/
	ColorHSV(FLOAT _h, FLOAT _s, FLOAT _v);

	/**
		@brief		コンストラクタ
		@param[in]	color	RGBカラー
		@return		なし
	*/
	explicit ColorHSV(const Color3B& color);
	/**
		@brief		コンストラクタ
		@param[in]	color	RGBカラー
		@return		なし
	*/
	explicit ColorHSV(const Color3F& color);
	/**
		@brief		コンストラクタ
		@param[in]	color	ARGBカラー
		@return		なし
	*/
	explicit ColorHSV(const Color4B& color);
	/**
		@brief		コンストラクタ
		@param[in]	color	ARGBカラー
		@return		なし
	*/
	explicit ColorHSV(const Color4F& color);

	
	/**
		@brief		ノーマライズ(正規範囲内に値を収める)
		@param[in]	なし
		@return		正規化した自身
	*/
	ColorHSV& Normalize();
	


protected:



private:

	//=====================================================
	// 変数宣言
	//=====================================================
public:
	FLOAT	h;		//!< Hue 色相
	FLOAT	s;		//!< Saturation 彩度
	FLOAT	v;		//!< Value 明度
	
protected:

private:


}ColorHSV;



}	// namespace color
//USING_NS_COLOR;



#endif	// __COLOR_H__