#include "private/component_si.h"
#include "component.h"


namespace DiagramModeller {


const int INVALID_COMPONENT_ID = -1;


ComponentSharedImplementation::ComponentSharedImplementation()
    : QSharedData(),
      category(CC_DiagramRoot),
      id(INVALID_COMPONENT_ID),
      properties()
{
}


ComponentSharedImplementation::ComponentSharedImplementation(const ComponentSharedImplementation &other)
    : QSharedData(other),
      category(other.category),
      id(other.id),
      properties(other.properties)
{
}


ComponentSharedImplementation::~ComponentSharedImplementation()
{
}


Component::Component(int id)
    : m(new ComponentSharedImplementation)
{
    m->id = id;
}


Component::Component(const Component &other)
    : m(other.m)
{
}


Component::~Component()
{
}


ComponentCategory Component::category() const
{ return m->category; }

void Component::setCategory(ComponentCategory value)
{ m->category = value; }

int Component::id() const
{ return m->id; }

bool Component::isValid() const
{ return m->id != INVALID_COMPONENT_ID; }

QVariant Component::property(const QString &key) const
{ return m->properties.value(key, QVariant()); }

bool Component::hasProperty(const QString &key) const
{ return m->properties.contains(key); }

void Component::setProperty(const QString &key, const QVariant &value)
{ m->properties.insert(key, value); }

bool Component::clearProperty(const QString &key)
{ return m->properties.remove(key) > 0; }

void Component::clearProperties()
{ m->properties.clear(); }


Component &Component::operator =(const Component &other)
{
    m = other.m;
    return *this;
}


} // namespace DiagramModeller
