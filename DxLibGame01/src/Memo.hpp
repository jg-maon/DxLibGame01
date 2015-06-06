#pragma once
#include <vector>
#include <string>
template<class T> ::std::vector<int> ConvertBinary(const T value)
{
	::std::vector<int> ret;
	auto size = sizeof(value) * 8;
	for (size_t i = 0; i < size; ++i)
	{
		const int v = (value >> (size - 1 - i)) & 0x01;
		ret.push_back(v);
	}
	return ret;
}
template<class T> ::std::string ConvertBinaryString(const T value)
{
	::std::string ret;
	auto size = sizeof(value) * 8;
	for (size_t i = 0; i < size; ++i)
	{
		const int v = (value >> (size - 1 - i)) & 0x01;
		ret += ('0' + v);
	}
	return ret;
}
#define SetRed(color, red)		((color) |= ((red)& 0xff))
#define SetGreen(color, green)	((color) |= ((green)& 0xff) << 8)
#define SetBlue(color, blue)	((color) |= ((blue)& 0xff) << 16)
#define Red(red)				(((red)& 0xff))
#define Green(green)			(((green)& 0xff) << 8)
#define Blue(blue)				(((blue)& 0xff) << 16)