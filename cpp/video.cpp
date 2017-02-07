#include "video.h"

Video::Video() : Media()
{
	m_height = 0;
	m_width = 0;
	m_length = 0;
}

Video::Video(std::string const& name,std::string const& file,int height, int width,int length) : Media(name,file)
{
	m_height = height;
	m_width = width;
	m_length = length;
}

void Video::play() const
{
	std::string cmd = "mpv "+m_file+" &";
	system(cmd.c_str());
}

void Video::display(std::ostream &ostream) const
{
	ostream <<
		"Le nom est : " << m_name <<
		" et est dans le fichier " << m_file <<
		" la dimention est [" << m_width << ";" << m_height <<
		"] et la longueur de la video est " << m_length << std::endl;
}

Video::~Video()
{

}



