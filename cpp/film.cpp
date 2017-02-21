#include "film.h"
#include <sstream>

Film::Film()
{
    m_chapters = 0;
}

Film::Film(std::stringstream & stream)
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
    std::getline(stream,str,'/');
    m_length = std::stoi(str);
    m_size = 0;
    std::stringstream copyStream(stream.str());
    while(copyStream)
    {
        std::getline(copyStream,str,'/');
        m_size++;
    }
    m_chapters = new int[m_size];
    for(int i = 0; i < m_size; i++)
    {
        std::getline(stream,str,'/');
        m_chapters[i] = std::stoi(str);
    }
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

void Film::serialize(std::ostream &ostream) const
{
	ostream <<
		"film/" << m_name <<
		"/" << m_file <<
		"/" << m_width << "/" << m_height <<
		"/" << m_length << "/";
    for(int i = 0; i < m_size; i++)
    {
        ostream << m_chapters[i] << "/";
    }
    ostream << std::endl;
}
