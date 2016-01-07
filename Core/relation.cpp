#include "private/relation_si.h"
#include "relation.h"


namespace DiagramModeller {


const int INVALID_RELATION_ID = -1;


RelationSharedImplementation::RelationSharedImplementation()
    : QSharedData()
{
}


RelationSharedImplementation::RelationSharedImplementation(const RelationSharedImplementation &other)
    : QSharedData(other)
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
