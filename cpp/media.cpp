#include "media.h"

Media::Media()
{

}

Media::Media(std::string const& name,std::string const& file) : m_name(name), m_file(file)
{
	
}

Media::~Media()
{
    std::cout << "destruction de l'objet " << m_name << std::endl;
}

void Media::setName(std::string const& name)
{
	m_name = name;
}

void Media::setFile(std::string const& file)
{
	m_file = file;
}

std::string Media::getName() const
{
	return m_name;
}

std::string Media::getFile() const
{
	return m_file;
}

void Media::display(std::ostream &ostream) const
{
	ostream << "Le nom est : " << m_name << " et est dans le fichier " << m_file << std::endl;
}

