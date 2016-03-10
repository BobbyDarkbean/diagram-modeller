#include "private/propertyfield_si.h"
#include "propertyfield.h"


namespace DiagramModeller {


PropertyFieldSharedImplementation::PropertyFieldSharedImplementation()
    : QSharedData(),
      name(),
      type(PT_Unknown)
{
}


PropertyFieldSharedImplementation::PropertyFieldSharedImplementation(const PropertyFieldSharedImplementation &other)
    : QSharedData(other),
      name(other.name),
      type(other.type)
{
}


PropertyFieldSharedImplementation::~PropertyFieldSharedImplementation()
{
}


PropertyField::PropertyField()
    : m(new PropertyFieldSharedImplementation)
{
}


PropertyField::PropertyField(const PropertyField &other)
    : m(other.m)
{
}


PropertyField::~PropertyField()
{
}


bool PropertyField::isValid() const
{ return m->type != PT_Unknown; }

QString PropertyField::name() const
{ return m->name; }

void PropertyField::setName(const QString &value)
{ m->name = value; }

PropertyType PropertyField::type() const
{ return m->type; }

void PropertyField::setType(PropertyType value)
{ m->type = value; }


PropertyField &PropertyField::operator =(const PropertyField &other)
{
    m = other.m;
    return *this;
}


bool operator ==(const PropertyField &a, const PropertyField &b)
{ return a.type() == b.type() && a.name() == b.name(); }

bool operator !=(const PropertyField &a, const PropertyField &b)
{ return a.type() != b.type() || a.name() != b.name(); }


} // namespace DiagramModeller
