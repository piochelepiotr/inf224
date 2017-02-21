#include "video.h"
#include <sstream>

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

Video::Video(std::stringstream & stream)
{
    std::string str;
    std::getline(stream,str,'/');
    m_name = str;
    std::getline(stream,str,'/');
    m_file = str;
    std::getline(stream,str,'/');
    m_width = std::stoi(str);
    std::getline(stream,str,'/');
    m_height = std::stoi(str);
    std::getline(stream,str,'/');
    m_length = std::stoi(str);
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
		"] et la longueur de la video est " << m_length << ".............";
}

void Video::serialize(std::ostream &ostream) const
{
	ostream <<
		"video/" << m_name <<
		"/" << m_file <<
		"/" << m_width << "/" << m_height <<
		"/" << m_length << "/" << std::endl;
}

Video::~Video()
{

}



