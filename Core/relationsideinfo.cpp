#include "private/relationsideinfo_si.h"
#include "relationsideinfo.h"
#include "component.h"


namespace DiagramModeller {


RelationSideInfoSharedImplementation::RelationSideInfoSharedImplementation()
    : QSharedData(),
      componentId(INVALID_COMPONENT_ID),
      category(RC_None),
      multiplicity(),
      name()
{
}


RelationSideInfoSharedImplementation::RelationSideInfoSharedImplementation(const RelationSideInfoSharedImplementation &other)
    : QSharedData(other),
      componentId(other.componentId),
      category(other.category),
      multiplicity(other.multiplicity),
      name(other.name)
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

QString RelationSideInfo::multiplicity() const { return m->multiplicity; }
void RelationSideInfo::setMultiplicity(QString value) { m->multiplicity = value; }

QString RelationSideInfo::name() const { return m->name; }
void RelationSideInfo::setName(QString value) { m->name = value; }


} // namespace DiagramModeller
