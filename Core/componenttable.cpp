#include <QVariant>

#include "private/componenttable_si.h"
#include "componenttable.h"


namespace DiagramModeller {


ComponentTableSharedImplementation::ComponentTableSharedImplementation()
    : QSharedData(),
      components()
{
}


ComponentTableSharedImplementation::ComponentTableSharedImplementation(const ComponentTableSharedImplementation &other)
    : QSharedData(other),
      components(other.components)
{
}


ComponentTableSharedImplementation::~ComponentTableSharedImplementation()
{
}


ComponentTable::ComponentTable()
    : m(new ComponentTableSharedImplementation)
{
}


ComponentTable::ComponentTable(const ComponentTable &other)
    : m(other.m)
{
}


ComponentTable::~ComponentTable()
{
}


int ComponentTable::size() const
{ return m->components.size(); }

Component ComponentTable::component(int id) const
{ return m->components.value(id, Component(INVALID_COMPONENT_ID)); }

bool ComponentTable::hasComponent(int id)
{ return m->components.contains(id); }

void ComponentTable::insertComponent(int id, const Component &component)
{ m->components.insert(id, component); }

bool ComponentTable::removeComponent(int id)
{ return m->components.remove(id) < 0; }

void ComponentTable::clear()
{ m->components.clear(); }

ComponentCategory ComponentTable::category(int id) const
{ return component(id).category(); }

bool ComponentTable::isValid(int id) const
{ return component(id).isValid(); }

QVariant ComponentTable::property(int id, const QString &key) const
{ return component(id).property(key); }

bool ComponentTable::hasProperty(int id, const QString &key) const
{ return component(id).hasProperty(key); }

void ComponentTable::setProperty(int id, const QString &key, const QVariant &value)
{
    if (m->components.contains(id))
        m->components[id].setProperty(key, value);
}

bool ComponentTable::clearProperty(int id, const QString &key)
{
    if (m->components.contains(id))
        return m->components[id].clearProperty(key);
    return false;
}

void ComponentTable::clearProperties(int id)
{
    if (m->components.contains(id))
        m->components[id].clearProperties();
}


ComponentTable &ComponentTable::operator =(const ComponentTable &other)
{
    m = other.m;
    return *this;
}


} // namespace DiagramModeller
