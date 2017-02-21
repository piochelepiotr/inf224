#ifndef DATA_H
#define DATA_H

#include "group.h"
#include <map>
#include "tcpserver.h"

class Data
{
    private:
        std::map<std::string, MediaPtr>m_medias;
        std::map<std::string, GroupPtr>m_groups;
    public:
        Data();
        ~Data();
        void createImage(const std::string & name,const std::string & file,int height, int width);
        void createVideo(std::string const& name,std::string const& file,int height, int width,int length);
        void createFilm(std::string const& name,std::string const& file,int height, int width,int length);
        void createGroup(std::string const& name);
        void deleteGroup(std::string const& name);
        void deleteMedia(std::string const& name);
        void addMediaToGroup(std::string const& media, std::string const& group);
        void displayMedia(std::ostream &ostream, std::string const& name) const;
        void displayGroup(std::ostream &ostream, std::string const& name) const;
        void playMedia(std::string const& name) const;
        bool processRequest(cppu::TCPConnection& cnx, const std::string& request, std::string& response);
        void loadFromFile(std::string const& fileName);
        void saveToFile(std::string const& fileName);
};

#endif
