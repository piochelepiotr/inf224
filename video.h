#pragma once
#include "media.h"
/*! Class for modeling video */

class Video : public Media
{
public:
	Video() : Media()
	{
		m_heigth = 0;
		m_width = 0;
		m_length = 0;
	}

	Video(std::string const& multiMediaName,std::string const& pathToMedia,int height, int width,int length) : Media(multiMediaName,pathToMedia)
	{
		m_height = height;
		m_width = width;
		m_length = length;
	};

	void setHeigth(int height) { m_height = height; }
	void setWidth(int width) { m_width = width; }
	void setLength(int length) { m_length = length; }
	int getHeight() const { return m_height; }
	int getWidth() const { return m_width; }
	int getLength() const { return m_length; }
	void play() const
	{
		std::string cmd = "mpv "+m_pathToMedia+" &";
		system(cmd);
	}
	void display(std::ostream &ostream) const
	{
	ostream << "Le nom est : " << m_multiMediaName << " et est dans le fichier " << m_pathToMedia << " la dimention est [" << m_width << ";" << m_height << "] et la longueur de la video est " << m_length << std::endl;
	}
	~Video()
	{

	}

protected:
	int m_height;
	int m_width;
	int m_length;
};

