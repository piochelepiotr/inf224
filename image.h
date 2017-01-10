#pragma once
#include "media.h"
/*! Class for modeling images */

class Image : public Media
{
public:
	Image() : Media()
	{
		m_height = 0;
		m_width = 0;
	}
	Image(std::string const& multiMediaName,std::string const& pathToMedia,int height = 0, int width = 0) : Media(multiMediaName,pathToMedia)
	{
		m_height = height;
		m_width = width;
	};
	void setHeigth(int height) { m_height = height; }
	void setWidth(int width) { m_width = width; }
	int getHeight() const { return m_height; }
	int getWidth() const { return m_width; }
	void play() const
	{
		std::string cmd = "imagej "+m_pathToMedia+" &";
		system(cmd.c_str());
	}
	~Image();
	void display(std::ostream &ostream) const
	{
		ostream << "Le nom est : " << m_multiMediaName << " et est dans le fichier " << m_pathToMedia << " la dimention est [" << m_width << ";" << m_height << "]" << std::endl;
	}


protected:
	int m_height;
	int m_width;
};

