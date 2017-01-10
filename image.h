#pragma once
#include "media.h"
/*! Class for modeling images */

class Image : public Media
{
public:
	Image();
	Image(std::string const& name,std::string const& file,int height = 0, int width = 0);
	void setHeigth(int height) { m_height = height; }
	void setWidth(int width) { m_width = width; }
	int getHeight() const { return m_height; }
	int getWidth() const { return m_width; }
	void play() const;
	~Image();
	void display(std::ostream &ostream) const;


protected:
	int m_height;
	int m_width;
};

