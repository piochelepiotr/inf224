#pragma once
#include <string>
#include <iostream>

/*! Class for modeling multimedia objects */

class Media
{
public:
	Media();
	Media(std::string const& multiMediaName,std::string const& pathToMedia);
	~Media();
	void setMultiMediaName(std::string const& multiMediaName);
	void setPathToMedia(std::string const& pathToMedia);
	std::string getMultiMediaName() const;
	std::string getPathToMedia() const;
	virtual void info(std::ostream & ostream) const;
	virtual void play() const=0;
	

protected:
	std::string m_multiMediaName;
	std::string m_pathToMedia;
};
	
