#include "data.h"
#include "film.h"
#include "image.h"
#include <sstream>

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

void Data::display(std::ostream &ostream, std::string const& name) const
{
    auto it = m_medias.find(name);
    if(it != m_medias.end())
    {
        it->second->display(ostream);
    }
    else
    {
        auto it = m_groups.find(name);
        if(it != m_groups.end())
        {
            it->second->display(ostream);
        }
        else
        {
            std::cout << "Groupe " << name << " introuvable" << std::endl;
        }
    }
}

void Data::play(std::string const& name) const
{
    auto it = m_medias.find(name);
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


bool Data::processRequest(cppu::TCPConnection& cnx, const std::string& request, std::string& response)
{ 
    std::cout << "request = " << request << std::endl;
    std::stringstream requestStream(request);
    std::string action, name;
    std::getline(requestStream,action,'/');
    std::getline(requestStream,name,'/');
    if(action.compare("play") == 0)
    {
        play(name);
        response = "playing...";
    }
    else if(action.compare("display") == 0)
    {
        std::stringstream responseStream;
        display(responseStream, name);
        response = responseStream.str();
    }
    else
    {
        std::cout << "commande inconnue : " << action << std::endl;
    }
    return true;
}

void Data::fromString(std::string const& medias)
{
    std::stringstream mediasStream(medias);
    while(mediasStream)
    {
        std::string mediaString;
        std::getline(mediasStream,mediaString,'\n');
        std::cout << "media : "<<mediaString<< std::endl;
        if(mediaString.compare("") != 0)
        {
            MediaPtr media;
            std::string classOfMedia;
            std::stringstream mediaStream(mediaString);
            std::getline(mediaStream,classOfMedia,'/');
            if(classOfMedia.compare("film") == 0)
            {
                media = MediaPtr(new Film(mediaStream));
            }
            else if(classOfMedia.compare("video") == 0)
            {
                media = MediaPtr(new Video(mediaStream));
            }
            else if(classOfMedia.compare("image") == 0)
            {
                media = MediaPtr(new Image(mediaStream));
            }
            else
            {
                std::cerr << "classe inconnue : "<< classOfMedia << std::endl;
            }
            m_medias[media->getName()] = media;
        }
    }
}

std::string Data::serialize()
{
    std::stringstream serialized;
    for(auto it : m_medias)
    {
        it.second->serialize(serialized);
    }
    return serialized.str();
}
