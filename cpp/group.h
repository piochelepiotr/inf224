#ifndef GROUP_H
#define GROUP_H

#include <list>
#include <string>
#include "media.h"
#include <memory>

typedef std::shared_ptr<Media> MediaPtr;

class Group : public std::list<MediaPtr>
{
    private:
        std::string m_name;
    public:
        Group(std::string const& name);
        void display() const;
        std::string const& getName() const { return m_name; }
};

#endif
