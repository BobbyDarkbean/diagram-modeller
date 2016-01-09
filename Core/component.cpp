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

QVariant property(const QString &key) const { }
bool hasProperty(const QString &key) const { }
void setProperty(const QString &key, const QVariant &value) { }
bool clearProperty(const QString &key) { }
void clearProperties() { }

Component &Component::operator =(const Component &other)
{
    m = other.m;
    return *this;
}


} // namespace DiagramModeller
