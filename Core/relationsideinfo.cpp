#include "private/relationsideinfo_si.h"
#include "component.h"
#include "relationsideinfo.h"


namespace DiagramModeller {


RelationSideInfoSharedImplementation::RelationSideInfoSharedImplementation()
    : QSharedData(),
      componentId(INVALID_COMPONENT_ID),
      category(RC_None),
      multiplicity(),
      name(),
      visibility(VS_Public)
{
}


RelationSideInfoSharedImplementation::RelationSideInfoSharedImplementation(const RelationSideInfoSharedImplementation &other)
    : QSharedData(other),
      componentId(other.componentId),
      category(other.category),
      multiplicity(other.multiplicity),
      name(other.name),
      visibility(other.visibility)
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


int RelationSideInfo::componentId() const { return m->componentId; }
void RelationSideInfo::setComponentId(int value) { m->componentId = value; }

RelationCategory RelationSideInfo::category() const { return m->category; }
void RelationSideInfo::setCategory(RelationCategory value) { m->category = value; }

QString RelationSideInfo::multiplicity() const { return m->multiplicity; }
void RelationSideInfo::setMultiplicity(const QString &value) { m->multiplicity = value; }

QString RelationSideInfo::name() const { return m->name; }
void RelationSideInfo::setName(const QString &value) { m->name = value; }

VisibilityScope RelationSideInfo::visibility() const { return m->visibility; }
void RelationSideInfo::setVisibility(VisibilityScope value) { m->visibility = value; }


RelationSideInfo &RelationSideInfo::operator =(const RelationSideInfo &other)
{
    m = other.m;
    return *this;
}


} // namespace DiagramModeller
