#include "image.h"
#include <sstream>


Image::Image() : Media()
{
	m_height = 0;
	m_width = 0;
}

Image::~Image()
{

}

Image::Image(std::stringstream & stream)
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
}

Image::Image(const std::string & name,const std::string & file,int height, int width) : Media(name,file)
{
	m_height = height;
	m_width = width;
}

void Image::play() const
{
	std::string cmd = "ristretto "+m_file+" &";
	system(cmd.c_str());
}

void Image::display(std::ostream &ostream) const
{
	ostream << "Le nom est : " << m_name << " et est dans le fichier " << m_file << " la dimention est [" << m_width << ";" << m_height << "]" << "............";
}

void Image::serialize(std::ostream &ostream) const
{
	ostream << "image/" << m_name << "/" << m_file << "/" << m_width << "/" << m_height << "/" << std::endl;
}

