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

int Relation::id() const { return m->id; }

QString Relation::name() const { return m->name; }
void Relation::setName(const QString &value) { m->name = value; }

bool Relation::isValid() const { return m->id != INVALID_RELATION_ID; }

QVariant Relation::property(const QString &key) const { return m->properties.value(key, QVariant()); }
bool Relation::hasProperty(const QString &key) const { return m->properties.contains(key); }
void Relation::setProperty(const QString &key, const QVariant &value) { m->properties.insert(key, value); }
bool Relation::clearProperty(const QString &key) { return m->properties.remove(key) > 0; }
void Relation::clearProperties() { m->properties.clear(); }

RelationSideInfo Relation::sideInfo(RelationSide side) const { return m->sides.value(side, RelationSideInfo()); }

void Relation::setRelationSideComponent(RelationSide side, int componentId)
{ m->sides[side].setComponentId(componentId); }

void Relation::setRelationSideCategory(RelationSide side, RelationCategory cat)
{  m->sides[side].setCategory(cat); }

void Relation::setRelationSideMultiplicity(RelationSide side, const QString &multiplicity)
{ m->sides[side].setMultiplicity(multiplicity); }

void Relation::setRelationSideName(RelationSide side, const QString &name)
{ m->sides[side].setName(name); }

void Relation::setRelationSideVisibility(RelationSide side, VisibilityScope visibility)
{ m->sides[side].setVisibility(visibility); }


Relation &Relation::operator =(const Relation &other)
{
    m = other.m;
    return *this;
}


} // namespace DiagramModeller
