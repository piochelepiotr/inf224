#pragma once
#include <string>
#include <iostream>
#include <memory>

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
	void setHeigth(int height) { m_height = height; }
	void setWidth(int width) { m_width = width; }
	int getHeight() const { return m_height; }
	int getWidth() const { return m_width; }
	virtual void play() const=0;
	void display(std::ostream &ostream) const;
protected:
	std::string m_name;
	std::string m_file;
	int m_height;
	int m_width;
};
	
typedef std::shared_ptr<Media> MediaPtr;
