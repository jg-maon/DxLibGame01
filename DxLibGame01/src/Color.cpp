/**=============================================================================
	@file		Color.cpp
	@brief		色クラス 実装
	@author		Masato Yamamoto
	@date		2015-02-18

	@par		[説明]
				色(RGB,ARGB,HSV)クラス

	@note

		Copyright (C) 2015  M.Yamamoto
=============================================================================*/
#include "Color.h"
#include <cmath>


#ifndef max
#define max(a,b)            (((a) > (b)) ? (a) : (b))
#endif

#ifndef min
#define min(a,b)            (((a) < (b)) ? (a) : (b))
#endif

#ifndef clamp
#define clamp(x, _min, _max) (max((_min), min((x), (_max))))
#endif

namespace color
{
#pragma region Color3B
	/**
		@brief		コンストラクタ
		@param[in]	なし
		@return		なし
	*/
	Color3B::Color3B()
		: r(255)
		, g(255)
		, b(255)
	{}
	/**
		@brief		コンストラクタ
		@param[in]	_r	赤
		@param[in]	_g	緑
		@param[in]	_b	青
		@return		なし
	*/
	Color3B::Color3B(BYTE _r, BYTE _g, BYTE _b)
		: r(_r)
		, g(_g)
		, b(_b)
	{}
	
	/**
		@brief		コンストラクタ
		@param[in]	color	RGBカラー
		@return		なし
	*/
	Color3B::Color3B(const Color3F& color)
		: r(static_cast<BYTE>(color.r*255.f))
		, g(static_cast<BYTE>(color.g*255.f))
		, b(static_cast<BYTE>(color.b*255.f))
	{}
	/**
		@brief		コンストラクタ
		@param[in]	color	ARGBカラー
		@return		なし
	*/
	Color3B::Color3B(const Color4B& color)
		: r(color.r)
		, g(color.g)
		, b(color.b)
	{}
	
	/**
		@brief		コンストラクタ
		@param[in]	color	ARGBカラー
		@return		なし
	*/
	Color3B::Color3B(const Color4F& color)
		: r(static_cast<BYTE>(color.r*255.f))
		, g(static_cast<BYTE>(color.g*255.f))
		, b(static_cast<BYTE>(color.b*255.f))
	{}

	/**
		@brief		コンストラクタ
		@param[in]	color	HSVカラー
		@return		なし
	*/
	Color3B::Color3B(const ColorHSV& color)
	{
		float _r = color.v;
		float _g = color.v;
		float _b = color.v;
		if (color.s > 0.0f)
		{
			float h = color.h * 6.0f;
			int i = static_cast<int>(h);
			float f = h - static_cast<float>(i);
			switch (i)
			{
			default:
			case 0:
				_g *= 1.f - color.s*(1.f - f);
				_b *= 1.f - color.s;
				break;
			case 1:
				_r *= 1.f - color.s*f;
				_b *= 1.f - color.s;
				break;
			case 2:
				_r *= 1.f - color.s;
				_b *= 1.f - color.s*(1.f - f);
				break;
			case 3:
				_r *= 1.f - color.s;
				_g *= 1.f - color.s*f;
				break;
			case 4:
				_r *= 1.f - color.s*(1.f - f);
				_g *= 1.f - color.s;
				break;
			case 5:
				_g *= 1.f - color.s;
				_b *= 1.f - color.s*f;
				break;
			}
		}
		r = static_cast<BYTE>(_r * 255.f);
		g = static_cast<BYTE>(_g * 255.f);
		b = static_cast<BYTE>(_b * 255.f);
	}
	
	/**
		@brief		ノーマライズ(正規範囲内に値を収める)
		@param[in]	なし
		@return		正規化した自身
	*/
	Color3B& Color3B::Normalize()
	{
		return *this;
	}
	

#pragma endregion	// Color3B

#pragma region Color3F
	/**
		@brief		コンストラクタ
		@param[in]	なし
		@return		なし
	*/
	Color3F::Color3F()
		: r(1.f)
		, g(1.f)
		, b(1.f)
	{}
	/**
		@brief		コンストラクタ
		@param[in]	_r	赤
		@param[in]	_g	緑
		@param[in]	_b	青
		@return		なし
	*/
	Color3F::Color3F(FLOAT _r, FLOAT _g, FLOAT _b)
		: r(_r)
		, g(_g)
		, b(_b)
	{}
	
	/**
		@brief		コンストラクタ
		@param[in]	color	RGBカラー
		@return		なし
	*/
	Color3F::Color3F(const Color3B& color)
		: r(color.r / 255.f)
		, g(color.g / 255.f)
		, b(color.b / 255.f)
	{}

	/**
		@brief		コンストラクタ
		@param[in]	color	ARGBカラー
		@return		なし
	*/
	Color3F::Color3F(const Color4B& color)
		: r(color.r / 255.f)
		, g(color.g / 255.f)
		, b(color.b / 255.f)
	{}
	/**
		@brief		コンストラクタ
		@param[in]	color	ARGBカラー
		@return		なし
	*/
	Color3F::Color3F(const Color4F& color)
		: r(color.r)
		, g(color.g)
		, b(color.b)
	{}
	/**
		@brief		コンストラクタ
		@param[in]	color	HSVカラー
		@return		なし
	*/
	Color3F::Color3F(const ColorHSV& color)
		: r(color.v)
		, g(color.v)
		, b(color.v)
	{
		if (color.s > 0.0f)
		{
			float h = color.h * 6.0f;
			int i = static_cast<int>(h);
			float f = h - static_cast<float>(i);
			switch (i)
			{
			default:
			case 0:
				g *= 1.f - color.s*(1.f - f);
				b *= 1.f - color.s;
				break;
			case 1:
				r *= 1.f - color.s*f;
				b *= 1.f - color.s;
				break;
			case 2:
				r *= 1.f - color.s;
				b *= 1.f - color.s*(1.f - f);
				break;
			case 3:
				r *= 1.f - color.s;
				g *= 1.f - color.s*f;
				break;
			case 4:
				r *= 1.f - color.s*(1.f - f);
				g *= 1.f - color.s;
				break;
			case 5:
				g *= 1.f - color.s;
				b *= 1.f - color.s*f;
				break;
			}
		}
	}
	
	/**
		@brief		ノーマライズ(正規範囲内に値を収める)
		@param[in]	なし
		@return		正規化した自身
	*/
	Color3F& Color3F::Normalize()
	{
		//r = fmodf(r, 1.f);
		//if (r < 0.f) r = 1.f + r;
		//g = fmodf(g, 1.f);
		//if (g < 0.f) g = 1.f + g;
		//b = fmodf(b, 1.f);
		//if (b < 0.f) b = 1.f + b;
		r = clamp(r, 0.f, 1.f);
		g = clamp(g, 0.f, 1.f);
		b = clamp(b, 0.f, 1.f);
		return *this;
	}
	
#pragma endregion	// Color3F

#pragma region Color4B
	/**
		@brief		コンストラクタ
		@param[in]	なし
		@return		なし
	*/
	Color4B::Color4B()
		: a(255)
		, r(255)
		, g(255)
		, b(255)
	{}
	/**
		@brief		コンストラクタ
		@param[in]	_a	透明度
		@param[in]	_r	赤
		@param[in]	_g	緑
		@param[in]	_b	青
		@return		なし
	*/
	Color4B::Color4B(BYTE _a, BYTE _r, BYTE _g, BYTE _b)
		: a(_a)
		, r(_r)
		, g(_g)
		, b(_b)
	{}
	/**
		@brief		コンストラクタ
		@param[in]	color	RGBカラー
		@return		なし
	*/
	Color4B::Color4B(const Color3B& color)
		: a(255)
		, r(color.r)
		, g(color.g)
		, b(color.b)
	{}
	/**
		@brief		コンストラクタ
		@param[in]	color	RGBカラー
		@return		なし
	*/
	Color4B::Color4B(const Color3F& color)
		: a(255)
		, r(static_cast<BYTE>(color.r*255.f))
		, g(static_cast<BYTE>(color.g*255.f))
		, b(static_cast<BYTE>(color.b*255.f))
	{}
	
	/**
		@brief		コンストラクタ
		@param[in]	color	ARGBカラー
		@return		なし
	*/
	Color4B::Color4B(const Color4F& color)
		: a(static_cast<BYTE>(color.a*255.f))
		, r(static_cast<BYTE>(color.r*255.f))
		, g(static_cast<BYTE>(color.g*255.f))
		, b(static_cast<BYTE>(color.b*255.f))
	{}

	/**
		@brief		コンストラクタ
		@param[in]	color	HSVカラー
		@return		なし
	*/
	Color4B::Color4B(const ColorHSV& color)
		: a(255)
	{
		float _r = color.v;
		float _g = color.v;
		float _b = color.v;
		if (color.s > 0.0f)
		{
			float h = color.h * 6.0f;
			int i = static_cast<int>(h);
			float f = h - static_cast<float>(i);
			switch (i)
			{
			default:
			case 0:
				_g *= 1.f - color.s*(1.f - f);
				_b *= 1.f - color.s;
				break;
			case 1:
				_r *= 1.f - color.s*f;
				_b *= 1.f - color.s;
				break;
			case 2:
				_r *= 1.f - color.s;
				_b *= 1.f - color.s*(1.f - f);
				break;
			case 3:
				_r *= 1.f - color.s;
				_g *= 1.f - color.s*f;
				break;
			case 4:
				_r *= 1.f - color.s*(1.f - f);
				_g *= 1.f - color.s;
				break;
			case 5:
				_g *= 1.f - color.s;
				_b *= 1.f - color.s*f;
				break;
			}
		}
		r = static_cast<BYTE>(_r * 255.f);
		g = static_cast<BYTE>(_g * 255.f);
		b = static_cast<BYTE>(_b * 255.f);
	}

	
	/**
		@brief		ノーマライズ(正規範囲内に値を収める)
		@param[in]	なし
		@return		正規化した自身
	*/
	Color4B& Color4B::Normalize()
	{
		return *this;
	}

#pragma endregion	// Color4B
	
#pragma region Color4F
	/**
		@brief		コンストラクタ
		@param[in]	なし
		@return		なし
	*/
	Color4F::Color4F()
		: a(1.0f)
		, r(1.0f)
		, g(1.0f)
		, b(1.0f)
	{}
	/**
		@brief		コンストラクタ
		@param[in]	_a	透明度
		@param[in]	_r	赤
		@param[in]	_g	緑
		@param[in]	_b	青
		@return		なし
	*/
	Color4F::Color4F(FLOAT _a, FLOAT _r, FLOAT _g, FLOAT _b)
		: a(_a)
		, r(_r)
		, g(_g)
		, b(_b)
	{}

	
	/**
		@brief		コンストラクタ
		@param[in]	color	RGBカラー
		@return		なし
	*/
	Color4F::Color4F(const Color3B& color)
		: a(1.0f)
		, r(color.r / 255.f)
		, g(color.g / 255.f)
		, b(color.b / 255.f)
	{}
	/**
		@brief		コンストラクタ
		@param[in]	color	ARGBカラー
		@return		なし
	*/
	Color4F::Color4F(const Color3F& color)
		: a(1.0f)
		, r(color.r)
		, g(color.g)
		, b(color.b)
	{}
	/**
		@brief		コンストラクタ
		@param[in]	color	ARGBカラー
		@return		なし
	*/
	Color4F::Color4F(const Color4B& color)
		: a(color.a / 255.f)
		, r(color.r / 255.f)
		, g(color.g / 255.f)
		, b(color.b / 255.f)
	{}
	/**
		@brief		コンストラクタ
		@param[in]	color	HSVカラー
		@return		なし
	*/
	Color4F::Color4F(const ColorHSV& color)
		: a(1.0f)
		, r(color.v)
		, g(color.v)
		, b(color.v)
	{
		if (color.s > 0.0f)
		{
			float h = color.h * 6.0f;
			int i = static_cast<int>(h);
			float f = h - static_cast<float>(i);
			switch (i)
			{
			default:
			case 0:
				g *= 1.f - color.s*(1.f - f);
				b *= 1.f - color.s;
				break;
			case 1:
				r *= 1.f - color.s*f;
				b *= 1.f - color.s;
				break;
			case 2:
				r *= 1.f - color.s;
				b *= 1.f - color.s*(1.f - f);
				break;
			case 3:
				r *= 1.f - color.s;
				g *= 1.f - color.s*f;
				break;
			case 4:
				r *= 1.f - color.s*(1.f - f);
				g *= 1.f - color.s;
				break;
			case 5:
				g *= 1.f - color.s;
				b *= 1.f - color.s*f;
				break;
			}
		}
	}
	
	/**
		@brief		ノーマライズ(正規範囲内に値を収める)
		@param[in]	なし
		@return		正規化した自身
	*/
	Color4F& Color4F::Normalize()
	{
		//a = fmodf(a, 1.f);
		//if (a < 0.f) a = 1.f + a;
		//r = fmodf(r, 1.f);
		//if (r < 0.f) r = 1.f + r;
		//g = fmodf(g, 1.f);
		//if (g < 0.f) g = 1.f + g;
		//b = fmodf(b, 1.f);
		//if (b < 0.f) b = 1.f + b;
		a = clamp(a, 0.f, 1.f);
		r = clamp(r, 0.f, 1.f);
		g = clamp(g, 0.f, 1.f);
		b = clamp(b, 0.f, 1.f);
		return *this;
	}

#pragma endregion	// Color4F

#pragma region ColorHSV
	/**
		@brief		コンストラクタ
		@param[in]	なし
		@return		なし
	*/
	ColorHSV::ColorHSV()
		: h(0.0f)
		, s(1.0f)
		, v(1.0f)
	{}
	/**
		@brief		コンストラクタ
		@param[in]	_h	色相
		@param[in]	_s	彩度
		@param[in]	_v	明度
		@return		なし
	*/
	ColorHSV::ColorHSV(FLOAT _h, FLOAT _s, FLOAT _v)
		: h(_h)
		, s(_s)
		, v(_v)
	{}

	/**
		@brief		コンストラクタ
		@param[in]	color	RGBカラー
		@return		なし
	*/
	ColorHSV::ColorHSV(const Color3B& color)
	{
		float r = color.r / 255.f;
		float g = color.g / 255.f;
		float b = color.b / 255.f;
		float _max = max(max(r, g), b);
		float _min = min(min(r, g), b);
		h = _max - _min;
		if (h > 0.0f)
		{
			if (_max == r)
			{
				h = (g - b) / h;
				if (h < 0.0f)
				{
					h += 6.0f;
				}
			}
			else if (_max == g)
			{
				h = 2.0f + (b - r) / h;
			}
			else
			{
				h = 4.0f + (r - g) / h;
			}
		}

		h /= 6.0f;
		s = _max - _min;
		if (_max != 0.0f)
		{
			s /= _max;
		}
		v = _max;
	}
	/**
		@brief		コンストラクタ
		@param[in]	color	RGBカラー
		@return		なし
	*/
	ColorHSV::ColorHSV(const Color3F& color)
	{
		float _max = max(max(color.r, color.g), color.b);
		float _min = min(min(color.r, color.g), color.b);
		h = _max - _min;
		if (h > 0.0f)
		{
			if (_max == color.r)
			{
				h = (color.g - color.b) / h;
				if (h < 0.0f)
				{
					h += 6.0f;
				}
			}
			else if (_max == color.g)
			{
				h = 2.0f + (color.b - color.r) / h;
			}
			else
			{
				h = 4.0f + (color.r - color.g) / h;
			}
		}

		h /= 6.0f;
		s = _max - _min;
		if (_max != 0.0f)
		{
			s /= _max;
		}
		v = _max;
	}

	/**
		@brief		コンストラクタ
		@param[in]	color	ARGBカラー
		@return		なし
	*/
	ColorHSV::ColorHSV(const Color4B& color)
	{
		float r = color.r / 255.f;
		float g = color.g / 255.f;
		float b = color.b / 255.f;
		float _max = max(max(r, g), b);
		float _min = min(min(r, g), b);
		h = _max - _min;
		if (h > 0.0f)
		{
			if (_max == r)
			{
				h = (g - b) / h;
				if (h < 0.0f)
				{
					h += 6.0f;
				}
			}
			else if (_max == g)
			{
				h = 2.0f + (b - r) / h;
			}
			else
			{
				h = 4.0f + (r - g) / h;
			}
		}

		h /= 6.0f;
		s = _max - _min;
		if (_max != 0.0f)
		{
			s /= _max;
		}
		v = _max;
	}
	/**
		@brief		コンストラクタ
		@param[in]	color	ARGBカラー
		@return		なし
	*/
	ColorHSV::ColorHSV(const Color4F& color)
	{
		float _max = max(max(color.r, color.g), color.b);
		float _min = min(min(color.r, color.g), color.b);
		h = _max - _min;
		if (h > 0.0f)
		{
			if (_max == color.r)
			{
				h = (color.g - color.b) / h;
				if (h < 0.0f)
				{
					h += 6.0f;
				}
			}
			else if (_max == color.g)
			{
				h = 2.0f + (color.b - color.r) / h;
			}
			else
			{
				h = 4.0f + (color.r - color.g) / h;
			}
		}

		h /= 6.0f;
		s = _max - _min;
		if (_max != 0.0f)
		{
			s /= _max;
		}
		v = _max;
	}

	
	/**
		@brief		ノーマライズ(正規範囲内に値を収める)
		@param[in]	なし
		@return		正規化した自身
	*/
	ColorHSV& ColorHSV::Normalize()
	{
		h = fmodf(h, 1.f);
		if (h < 0.f) h = 1.f + h;
		s = clamp(s, 0.0f, 1.0f);
		v = clamp(v, 0.0f, 1.0f);
		return *this;
	}

#pragma endregion	// ColorHSV



}	// namespace color