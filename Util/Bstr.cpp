/*=============================================================================
# Filename: Bstr.cpp
# Author: Bookug Lobert 
# Mail: 1181955272@qq.com
# Last Modified: 2015-10-16 13:18
# Description: achieve functions in Bstr.h
=============================================================================*/

#include "Bstr.h"

using namespace std;

//default construct function
Bstr::Bstr()
{
	this->length = 0;
	this->str = NULL;
}

Bstr::Bstr(const char* _str, unsigned _len)
{
	//WARN: if need a string .please add '\0' in your own!
	this->length = _len;
	//DEBUG:if copy memory?
	//this->str = _str; //not valid:const char* -> char*
	this->str = (char*)malloc(_len);
	memcpy(this->str, _str, sizeof(char) * _len);
	//this->str[_len]='\0';
}

//Bstr::Bstr(char* _str, unsigned _len)
//{
//	this->length = _len;
//	this->str = _str;
//}

//copy construct function
Bstr::Bstr(const Bstr& _bstr)
{
	//DEBUG:if copy memory here
	this->length = _bstr.length;
	this->str = _bstr.str;
}

//assign function for class
//Bstr& Bstr::operate =(const Bstr& _bstr)
//{
//	if(*this == _bstr)
//		return *this;		//a=a
//	//WARN:not copy memory. if need to copy, delete original first!
//	this->length = _bstr.length;
//	this->str = _bstr.str;
//	return *this;
//}

bool 
Bstr::operator > (const Bstr& _bstr)
{
	int res = Util::compare(this->str, this->length, _bstr.str, _bstr.length);
	if(res == 1)
		return true;
	else
		return false;
}

bool 
Bstr::operator < (const Bstr& _bstr)
{
	int res = Util::compare(this->str, this->length, _bstr.str, _bstr.length);
	if(res == -1)
		return true;
	else
		return false;
}

bool
Bstr::operator == (const Bstr& _bstr)
{
	int res = Util::compare(this->str, this->length, _bstr.str, _bstr.length);
	if(res == 0)
		return true;
	else
		return false;
}

bool
Bstr::operator <= (const Bstr& _bstr)
{
	int res = Util::compare(this->str, this->length, _bstr.str, _bstr.length);
	if(res <= 0)
		return true;
	else
		return false;
}

bool
Bstr::operator >= (const Bstr& _bstr)
{
	int res = Util::compare(this->str, this->length, _bstr.str, _bstr.length);
	if(res >= 0)
		return true;
	else
		return false;
}

bool
Bstr::operator != (const Bstr& _bstr)
{
	int res = Util::compare(this->str, this->length, _bstr.str, _bstr.length);
	if(res != 0)
		return true;
	else
		return false;
}

unsigned
Bstr::getLen() const
{
	return length;
}

void
Bstr::setLen(unsigned _len)
{
	this->length = _len;
}

char*
Bstr::getStr() const
{
	return str;
}

void 
Bstr::setStr(char* _str)
{
	this->str = _str;
}

void
Bstr::copy(const Bstr* _bp)
{
	this->length = _bp->getLen();
	this->str = (char*)malloc(this->length);
	memcpy(this->str, _bp->getStr(), this->length);
}

void
Bstr::copy(const char* _str, unsigned _len)
{
	this->length = _len;
	this->str = (char*)malloc(this->length);
	memcpy(this->str, _str, this->length);
}

void
Bstr::clear()	
{
	this->str = NULL;
	this->length = 0;
}

void
Bstr::release()
{
	free(this->str);	//ok to be null, do nothing
	clear();
}

Bstr::~Bstr()	
{	//avoid mutiple delete
	release();
}

void
Bstr::print(string s) const
{
//TODO: add a new debug file in Util(maybe a total?)
//#ifdef DEBUG
//	Util::showtime();
//	fputs("Class Bstr\n", Util::logsfp);
//	fputs("Message: ", Util::logsfp);
//	fputs(s.c_str(), Util::logsfp);
//	fputs("\n", Util::logsfp);
//	if(s == "BSTR")
//	{	//total information, providing accurate debugging
//		fprintf(Util::logsfp, "length: %u\t the string is:\n", this->length);
//		unsigned i;
//		for(i = 0; i < this->length; ++i)
//			fputc(this->str[i], Util::logsfp);
//		fputs("\n", Util::logsfp);
//	}
//	else if(s == "bstr")
//	{	//only length information, needed when string is very long
//		fprintf(Util::logsfp, "length: %u\n", this->length);
//	}
//	else;
//#endif
}

