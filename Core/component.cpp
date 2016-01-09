#include "private/component_si.h"
#include "component.h"


namespace DiagramModeller {


const int INVALID_COMPONENT_ID = -1;


ComponentSharedImplementation::ComponentSharedImplementation()
    : QSharedData()
{
}


ComponentSharedImplementation::ComponentSharedImplementation(const ComponentSharedImplementation &other)
    : QSharedData(other)
{
}


ComponentSharedImplementation::~ComponentSharedImplementation()
{
}


Component::Component()
    : m(new ComponentSharedImplementation)
{
}


Component::Component(const Component &other)
    : m(other.m)
{
}


Component::~Component()
{
}


bool Component::isValid() const { }

QVariant Component::property(const QString &key) const { }
bool Component::hasProperty(const QString &key) const { }
void Component::setProperty(const QString &key, const QVariant &value) { }
bool Component::clearProperty(const QString &key) { }
void Component::clearProperties() { }

int Component::childrenCount() const { }
int Component::childAt(int i) { }
int Component::childIndex(int id) const { }
int Component::hasChild(int id) const { }
bool Component::insertChild(int i, int id) { }
bool Component::removeChild(int id) { }
bool Component::removeChildAt(int i) { }
bool Component::moveChild(int from, int to) { }
int Component::relationsCount() const { }
int Component::hasRelation(int id) const { }
bool Component::appendRelaion(int id) { }
bool Component::removeRelation(int id) { }


Component &Component::operator =(const Component &other)
{
    m = other.m;
    return *this;
}


} // namespace DiagramModeller
