/**=============================================================================
	@file		Common.cpp
	@brief		コモン関数 実装
	@author		Masato Yamamoto
	@date		2015-02-28

	@par		[説明]
				演算子のオーバーロードやその他の処理
	@note

		Copyright (C) 2015  M.Yamamoto
=============================================================================*/

#include "Common.h"
#include <sstream>
#include <iomanip>

#include <ctime>

//*
//======================================================
#pragma region 関数のオーバーロード類

#pragma region floatFixed
namespace std
{

	ostream& operator << (ostream& ost, const floatFixed& fx)
	{
		return fx(ost);
	}
	// 引数に与えた数値を有効数字にするの
	floatFixed fixval(int value)
	{
		return floatFixed(value);
	}

	// ostreamを初期設定に戻す
	std::ostream& orgset(std::ostream& ost)
	{
		// 浮動小数点の一般形式表示
		ost.setf((std::ios_base::fmtflags)0, std::ios_base::floatfield);
		ost << dec << nouppercase;	// 10進数、小文字表示
		return ost;
	}

}
#pragma endregion // floatFixed

#pragma endregion // 関数のオーバーロード類
//*/

namespace common
{

	// 有効数字付き浮動小数点を文字列として取得する
	//template<typename T_>
	//::std::string getFloatString(T_ f, int val, int w)
	//{
	//	::std::ostringstream ss;
	//	ss << ::std::right << ::std::setw(w) << ::std::fixval(val) << f;
	//	return ss.str();
	//}
	//// 有効数字付き浮動小数点を文字列として取得する
	//template<typename T_>
	//::std::string getFloatString(T_ f, char fill, int val, int w)
	//{
	//	::std::ostringstream ss;
	//	ss << ::std::right << ::std::setfill(fill) << ::std::setw(w) << ::std::fixval(val) << f;
	//	return ss.str();
	//}

	//  文字列を置換する
	::std::string StrReplace(const ::std::string& str, const ::std::string& search, const ::std::string& replace)
	{
		::std::string ret = str;
		::std::string::size_type  pos(str.find(search));

		while (pos != ::std::string::npos)
		{
			ret.replace(pos, search.length(), replace);
			pos = ret.find(search, pos + replace.length());
		}

		return ret;
	}

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
		bool FindChunk(::std::istream& stream, const ::std::string& find)
		{
			while (!stream.eof())
			{
				::std::string label;
				stream >> label;
				if (find == label)
				{
					return true;
				}
			}
			return false;
		}
		
		/**
			@brief		入力ストリームの位置を先頭に戻す
			@param[out]	stream		先頭に戻す入力ストリーム
			@return		戻した入力ストリーム自身
		*/
		::std::istream& SeekSet(::std::istream& stream)
		{
			stream.clear();
			stream.seekg(0);
			return stream;
		}
		
		/**
			@brief		ストリームの位置を先頭に戻す
			@param[out]	stream		先頭に戻す出力ストリーム
			@return		戻した出力ストリーム自身
		*/
		::std::ostream& SeekSet(::std::ostream& stream)
		{
			stream.clear();
			stream.seekp(0);
			return stream;
		}

	}	// namespace stream

	namespace time
	{
		/**
			@brief		実行時の年を取得(1900～)
			@param[in]	なし
			@return		実行時の年
		*/
		unsigned int GetYear()
		{
			time_t _time;
			::std::time(&_time);
			tm _tm;
#ifdef _WINDOWS
			localtime_s(&_tm, &_time);
#else
			localtime_r(&_time, &_tm);
			//_tm = *localtime(&_time);
#endif
			return (_tm.tm_year + 1900);
		}
		
		/**
			@brief		実行時の日を取得(1～31)
			@param[in]	なし
			@return		実行時の日(1～31)
		*/
		unsigned int GetMonth()
		{
			time_t _time;
			::std::time(&_time);
			tm _tm;
#ifdef _WINDOWS
			localtime_s(&_tm, &_time);
#else
			localtime_r(&_time, &_tm);
			//_tm = *localtime(&_time);
#endif
			return (_tm.tm_mon) + 1;
		}
		
		/**
			@brief		実行時の日を取得(1～31)
			@param[in]	なし
			@return		実行時の日(1～31)
		*/
		unsigned int GetDay()
		{
			time_t _time;
			::std::time(&_time);
			tm _tm;
#ifdef _WINDOWS
			localtime_s(&_tm, &_time);
#else
			localtime_r(&_time, &_tm);
			//_tm = *localtime(&_time);
#endif
			return (_tm.tm_mday);
		}

		/**
			@brief		実行時の時間系構造体の取得
			@param[in]	なし
			@return		時間構造体
		*/
		tm GetTimeData()
		{
			time_t _time;
			::std::time(&_time);
			tm _tm;
#ifdef _WINDOWS
			localtime_s(&_tm, &_time);
#else
			localtime_r(&_time, &_tm);
			//_tm = *localtime(&_time);
#endif
			return _tm;
		}

		//double getSec()
		//{
		//	timeval val;
		//	::cocos2d::gettimeofday(&val, nullptr);
		//	return (val.tv_sec) + (val.tv_usec) * 1e-6;
		//}
		//long getMiliSec()
		//{
		//	auto now = ::std::chrono::system_clock::now();
		//	auto time_since_epoch = now.time_since_epoch();
		//	auto cast_ms = ::std::chrono::duration_cast<::std::chrono::milliseconds>(time_since_epoch);
		//	auto ms = cast_ms.count();
		//	//auto ms = ::std::chrono::duration_cast<::std::chrono::milliseconds>
		//	//			(::std::chrono::system_clock::now().time_since_epoch()).count();
		//	return ms;
		//}

	}		// namespace time


	//======================================================


}	// namespace common
