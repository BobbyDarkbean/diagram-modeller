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


Relation::Relation(int id)
    : m(new RelationSharedImplementation)
{
    m->id = id;
}


Relation::Relation(const Relation &other)
    : m(other.m)
{
}


Relation::~Relation()
{
}

QString Relation::name() const { return m->name; }
void Relation::setName(QString value) { m->name = value; }

int Relation::id() const { return m->id; }


Relation &Relation::operator =(const Relation &other)
{
    m = other.m;
    return *this;
}


} // namespace DiagramModeller
