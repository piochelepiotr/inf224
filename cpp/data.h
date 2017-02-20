#ifndef DATA_H
#define DATA_H

class Data
{
    private:
        std::map<std::string, MediaPtr>m_medias;
        std::map<std::string, Group>m_groups;
    public:
        Data();
        ~Data();
        void addImage(const std::string & name,const std::string & file,int height, int width);
        void addVideo(std::string const& name,std::string const& file,int height, int width,int length);
        void addFilm(std::string const& name,std::string const& file,int height, int width,int length);
        void addGroup(std::string const& name);

