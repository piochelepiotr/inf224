#pragma once
#include "media.h"
/*! Class for modeling video */

class Video : public Media
{
public:
	Video();
	~Video();
	Video(std::string const& name,std::string const& file,int height, int width,int length);
	void play();
	void display(std::ostream &ostream);
	void setHeigth(int height) { m_height = height; }
	void setWidth(int width) { m_width = width; }
	void setLength(int length) { m_length = length; }
	int getHeight() const { return m_height; }
	int getWidth() const { return m_width; }
	int getLength() const { return m_length; }
	

protected:
	int m_height;
	int m_width;
	int m_length;
};

