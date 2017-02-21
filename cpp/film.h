#ifndef FILM_H
#define FILM_H

#include "video.h"

class Data;

class Film : public Video
{
    friend class Data;
    private:
	    Film();
        Film(std::stringstream & stream);
	    Film(std::string const& name,std::string const& file,int height, int width,int length);
        int *m_chapters;
        int m_size;
    public:
	    ~Film();
        void setChapters(int *chapters, int size);
        int * getChapters();
        int getSize();
	    void serialize(std::ostream &ostream) const;
};

int *copy(int *origin, int size);

#endif
