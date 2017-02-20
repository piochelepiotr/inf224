#include "film.h"

Film::Film()
{
    m_chapters = 0;
}

Film::Film(std::string const& name,std::string const& file,int height, int width,int length) : Video(name,file,height,width, length)
{
    m_chapters = 0;
}

Film::~Film()
{
    if(m_chapters)
        delete m_chapters;
}

void Film::setChapters(int *chapters, int size)
{
    if(m_chapters)
        delete m_chapters;
    m_size = size;
    m_chapters = copy(chapters, size);
}

/** the problem is that you have to use delete each time you use getChapters
 *the optimal way would be to do a function getChapter(i) instead
 */
int * Film::getChapters()
{
    return copy(m_chapters,m_size);
}

int Film::getSize()
{
    return m_size;
}

int *copy(int *origin, int size)
{
    int *newTab = new int[size];
    for(int i = 0; i < size; i++)
    {
        newTab[i] = origin[i];
    }
    return newTab;
}
