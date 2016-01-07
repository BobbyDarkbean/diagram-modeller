#include "private/relationsideinfo_si.h"
#include "relationsideinfo.h"
#include "component.h"


namespace DiagramModeller {


RelationSideInfoSharedImplementation::RelationSideInfoSharedImplementation()
    : QSharedData(),
      componentId(INVALID_COMPONENT_ID),
      category(RC_None)
{
}


RelationSideInfoSharedImplementation::RelationSideInfoSharedImplementation(const RelationSideInfoSharedImplementation &other)
    : QSharedData(other),
      componentId(other.componentId),
      category(other.category)
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

RelationCategory RelationSideInfo::category() const { return m->category; }
void RelationSideInfo::setCategory(RelationCategory value) { m->category = value; }


} // namespace DiagramModeller
