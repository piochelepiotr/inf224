#pragma once
#include "media.h"
/*! Class for modeling images */

class Data;

class Image : public Media
{
    friend class Data;
    private:
	Image();
	Image(const std::string & name,const std::string & file,int height = 0, int width = 0);
    Image(std::stringstream & stream);
public:
	void setHeigth(int height) { m_height = height; }
	void setWidth(int width) { m_width = width; }
	int getHeight() const { return m_height; }
	int getWidth() const { return m_width; }
	void play() const;
	~Image();
	void display(std::ostream &ostream) const;
	void serialize(std::ostream &ostream) const;


protected:
	int m_height;
	int m_width;
};

