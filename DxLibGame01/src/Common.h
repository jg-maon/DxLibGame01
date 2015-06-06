/**=============================================================================
	@file		Common.h
	@brief		コモン関数 定義
	@author		Masato Yamamoto
	@date		2015-02-28

	@par		[説明]
				演算子のオーバーロードやその他の処理
	@note

		Copyright (C) 2015  M.Yamamoto
=============================================================================*/

#ifndef __COMMON_H__
#define __COMMON_H__

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

#ifndef arrayof
#define arrayof(x) (sizeof((x)) / sizeof((x)[0]))
#endif

//*
//======================================================
#pragma region 関数のオーバーロード類

namespace std
{
	class floatFixed
	{
		int m_value;
	public:
		floatFixed(int value){ m_value = value; }
		ostream& operator()(ostream& ost) const
		{
			ost << setprecision(m_value);	// 精度指定
			ost << fixed;					// 固定小数点形式
			return ost;
		}
	};

	ostream& operator << (ostream& ost, const floatFixed& fx);
	// 引数に与えた数値を有効数字にするの
	floatFixed fixval(int value);

	// ostreamを初期設定に戻す
	ostream& orgset(ostream& ost);

}
#pragma endregion	// 関数のオーバーロード類
//*/

namespace common
{
	/**
		@brief		有効数字付き浮動小数点を文字列として取得する
		@param[in]	f	値
		@param[in]	val	有効数字(デフォルト:8)
		@param[in]	w	文字幅(デフォルト:8)
		@return		文字列
	*/
	template<typename T_>	::std::string getFloatString(T_ f, int val, int w)
	{
		::std::ostringstream ss;
		ss << ::std::right << ::std::setw(w) << ::std::fixval(val) << f;
		return ss.str();
	}

	/**
		@brief		有効数字付き浮動小数点を文字列として取得する
		@param[in]	f		値
		@param[in]	fill	埋める文字
		@param[in]	val		有効数字(デフォルト:8)
		@param[in]	w		文字幅(デフォルト:8)
		@return		文字列
	*/
	template<typename T_>		::std::string getFloatString(T_ f, char fill, int val, int w)
	{
		::std::ostringstream ss;
		ss << ::std::right << ::std::setfill(fill) << ::std::setw(w) << ::std::fixval(val) << f;
		return ss.str();
	}

	// 文字画像表示状態
	enum class DispState
	{
		HIDE,					// 非表示
		APPEARING,				// 出現中
		SHOW,					// 表示
		DISAPPEARING,			// 消失中
	};
	// 文字配置
	enum Align
	{
		LEFT,					// 左揃え
		RIGHT,					// 右揃え
	};
	// 文字列の置換
	::std::string StrReplace(const ::std::string& str, const ::std::string& search, const ::std::string& replace);

	namespace stream
	{
		/**
			@brief			最初に文字列が現れるまでストリームを進める
			@param[in/out]	stream	ストリーム
			@param[in]		find	探す文字列
			@return			文字列があったか
			@retval			true	文字列があった(ストリームがそこまで進んでいる)
			@retval			false	文字列がなかった(ストリームの状態はEOF)
		*/
		bool FindChunk(::std::istream& stream, const ::std::string& find);

		/**
			@brief		入力ストリームの位置を先頭に戻す
			@param[out]	stream		先頭に戻す入力ストリーム
			@return		戻した入力ストリーム自身
		*/
		::std::istream& SeekSet(::std::istream& stream);
		
		/**
			@brief		ストリームの位置を先頭に戻す
			@param[out]	stream		先頭に戻す出力ストリーム
			@return		戻した出力ストリーム自身
		*/
		::std::ostream& SeekSet(::std::ostream& stream);
	}

	namespace time
	{
		/**
			@brief		実行時の年を取得(1900～)
			@param[in]	なし
			@return		実行時の年
		*/
		unsigned int GetYear();
		/**
			@brief		実行時の月を取得(1～12)
			@param[in]	なし
			@return		実行時の月(1～12)
		*/
		unsigned int GetMonth();
		/**
			@brief		実行時の日を取得(1～31)
			@param[in]	なし
			@return		実行時の日(1～31)
		*/
		unsigned int GetDay();


		/**
			@brief		実行時の時間系構造体の取得
			@param[in]	なし
			@return		時間構造体
		*/
		tm GetTimeData();

	}


}	// namespace common
#endif	// __COMMON_H__
