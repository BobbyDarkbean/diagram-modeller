#include "private/relationsideinfo_si.h"
#include "relationsideinfo.h"


namespace DiagramModeller {


RelationSideInfoSharedImplementation::RelationSideInfoSharedImplementation()
    : QSharedData()
{
}


RelationSideInfoSharedImplementation::RelationSideInfoSharedImplementation(const RelationSideInfoSharedImplementation &other)
    : QSharedData(other)
{
}


RelationSideInfoSharedImplementation::~RelationSideInfoSharedImplementation()
{
}


RelationSideInfo::RelationSideInfo()
    : m(new RelationSideInfoSharedImplementation)
{
}


RelationSideInfo::RelationSideInfo(const RelationSideInfo &other)
    : m(other.m)
{
}


RelationSideInfo::~RelationSideInfo()
{
}


RelationSideInfo &RelationSideInfo::operator =(const RelationSideInfo &other)
{
    m = other.m;
    return *this;
}


} // namespace DiagramModeller
