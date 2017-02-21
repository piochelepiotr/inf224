#include "group.h"

Group::Group(std::string const& name)
{
    m_name = name;
}

void Group::display(std::ostream &ostream) const
{
    for(std::list<MediaPtr>::const_iterator it = cbegin(); it != cend(); it++)
    {
        (*it)->display(ostream);
    }
}
