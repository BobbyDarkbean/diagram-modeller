#include "private/component_si.h"
#include "component.h"


namespace DiagramModeller {


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


Component &Component::operator =(const Component &other)
{
    m = other.m;
    return *this;
}


} // namespace DiagramModeller
