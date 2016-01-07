#include "private/relation_si.h"
#include "relation.h"


namespace DiagramModeller {


const int INVALID_RELATION_ID = -1;


RelationSharedImplementation::RelationSharedImplementation()
    : QSharedData(),
      id(INVALID_RELATION_ID),
      name(),
      properties(),
      sides()
{
}


RelationSharedImplementation::RelationSharedImplementation(const RelationSharedImplementation &other)
    : QSharedData(other),
      id(other.id),
      name(other.name),
      properties(other.properties),
      sides(other.sides)
{
}


RelationSharedImplementation::~RelationSharedImplementation()
{
}


Relation::Relation()
    : m(new RelationSharedImplementation)
{
}


Relation::Relation(const Relation &other)
    : m(other.m)
{
}


Relation::~Relation()
{
}


Relation &Relation::operator =(const Relation &other)
{
    m = other.m;
    return *this;
}


} // namespace DiagramModeller
