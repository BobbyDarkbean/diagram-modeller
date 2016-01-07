#include "private/relationsideinfo_si.h"
#include "relationsideinfo.h"
#include "component.h"


namespace DiagramModeller {


RelationSideInfoSharedImplementation::RelationSideInfoSharedImplementation()
    : QSharedData(),
      componentId(INVALID_COMPONENT_ID)
{
}


RelationSideInfoSharedImplementation::RelationSideInfoSharedImplementation(const RelationSideInfoSharedImplementation &other)
    : QSharedData(other),
      componentId(other.componentId)
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


int RelationSideInfo::componentId() const { return m->componentId; }
void RelationSideInfo::setComponentId(int value) { m->componentId = value; }


} // namespace DiagramModeller
