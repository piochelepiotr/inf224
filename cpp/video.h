#ifndef MEDIA_H
#define MEDIA_H
#include "media.h"
/*! Class for modeling video */

class Data;

class Video : public Media
{
    friend class Data;
public:
	~Video();
	void play() const;
	void display(std::ostream &ostream) const;
	void setLength(int length) { m_length = length; }
	int getLength() const { return m_length; }
	void serialize(std::ostream &ostream) const;
protected:
	Video();
	Video(std::string const& name,std::string const& file,int height, int width,int length);
    Video(std::stringstream & stream);
	int m_length;
};

#endif
