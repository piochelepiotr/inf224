#include "media.h"

Media::Media()
{

}

Media::Media(std::string const& multiMediaName,std::string const& pathToMedia) : m_multiMediaName(multiMediaName), m_pathToMedia(pathToMedia)
{
	
}

Media::~Media()
{

}

void Media::setMultiMediaName(std::string const& multiMediaName)
{
	m_multiMediaName = multiMediaName;
}

void Media::setPathToMedia(std::string const& pathToMedia)
{
	m_pathToMedia = pathToMedia;
}

std::string Media::getMultiMediaName() const
{
	return m_multiMediaName;
}

std::string Media::getPathToMedia() const
{
	return m_pathToMedia;
}

void Media::display(std::ostream &ostream) const
{
	ostream << "Le nom est : " << m_multiMediaName << " et est dans le fichier " << m_pathToMedia << std::endl;
}

