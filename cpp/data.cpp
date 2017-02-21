#include "data.h"
#include "film.h"
#include "image.h"

Data::Data()
{

}

Data::~Data()
{

}

void Data::createImage(const std::string & name,const std::string & file,int height, int width)
{
    MediaPtr p(new Image(name, file,height, width));
    m_medias[name] = p;
}

void Data::createVideo(std::string const& name,std::string const& file,int height, int width,int length)
{
    MediaPtr p(new Video(name, file, height, width,length));
    m_medias[name] = p;
}

void Data::createFilm(std::string const& name,std::string const& file,int height, int width,int length)
{
    MediaPtr p(new Film(name,file,height, width, length));
    m_medias[name] = p;
}

void Data::createGroup(std::string const& name)
{
    GroupPtr p(new Group(name)); 
    m_groups[name] = p;
}
void Data::addMediaToGroup(std::string const& media, std::string const& group)
{
    if(m_groups.find(group) != m_groups.end() && m_medias.find(media) != m_medias.end())
    {
        m_groups[group]->push_back(m_medias[media]);
    }
    else
    {
        std::cout << "le groupe "<<group << " ou le media "<<media << " n'existe pas"<<std::endl;
    }
}

void Data::displayMedia(std::string const& name) const
{
    std::map<std::string,MediaPtr>::const_iterator it = m_medias.find(name);
    if(it != m_medias.end())
    {
        it->second->display(std::cout);
    }
    else
    {
        std::cout << "Media " << name << " introuvable" << std::endl;
    }
}

void Data::displayGroup(std::string const& name) const
{
    std::map<std::string,GroupPtr>::const_iterator it = m_groups.find(name);
    if(it != m_groups.end())
    {
        it->second->display();
    }
    else
    {
        std::cout << "Groupe " << name << " introuvable" << std::endl;
    }
}

void Data::playMedia(std::string const& name) const
{
    std::map<std::string,MediaPtr>::const_iterator it = m_medias.find(name);
    if(it != m_medias.end())
    {
        it->second->play();
    }
    else
    {
        std::cout << "Media " << name << " introuvable" << std::endl;
    }

}

void Data::deleteGroup(std::string const& name)
{
    if(m_groups.find(name) != m_groups.end())
    {
        m_groups.erase(name);
    }
    else
    {
        std::cout << "pas de groupe à supprimer" << std::endl;
    }
}

void Data::deleteMedia(std::string const& name)
{
    if(m_medias.find(name) == m_medias.end())
    {
        return;
    }
    for(std::map<std::string, GroupPtr>::iterator it = m_groups.begin(); it != m_groups.end(); it++)
    {
        it->second->remove(m_medias[name]);
    }
    m_medias.erase(name);
}
