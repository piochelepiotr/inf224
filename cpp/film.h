#ifndef FILM_H
#define FILM_H

#include "video.h"

class Film : public Video
{
    private:
        int *m_chapters;
        int m_size;
    public:
	    Film();
        Film(std::stringstream & stream);
	    ~Film();
	    Film(std::string const& name,std::string const& file,int height, int width,int length);
        void setChapters(int *chapters, int size);
        int * getChapters();
        int getSize();
};

int *copy(int *origin, int size);

#endif
