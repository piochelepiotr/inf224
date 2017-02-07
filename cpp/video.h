#pragma once
#include "media.h"
/*! Class for modeling video */

class Video : public Media
{
public:
	Video();
	~Video();
	Video(std::string const& name,std::string const& file,int height, int width,int length);
	void play() const;
	void display(std::ostream &ostream) const;
	void setLength(int length) { m_length = length; }
	int getLength() const { return m_length; }
protected:
	int m_length;
};

