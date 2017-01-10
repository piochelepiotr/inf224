#pragma once
#include <string>
#include <iostream>

/*! Class for modeling multimedia objects */

class Media
{
public:
	Media();
	Media(std::string const& name,std::string const& file);
	~Media();
	void setName(std::string const& name);
	void setFile(std::string const& file);
	std::string getName() const;
	std::string getFile() const;
	virtual void play() const=0;
	void display(std::ostream &ostream) const;
protected:
	std::string m_name;
	std::string m_file;
};
	
