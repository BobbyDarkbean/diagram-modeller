#include "private/propertyschema_si.h"
#include "propertyschema.h"


namespace DiagramModeller {


PropertySchemaSharedImplementation::PropertySchemaSharedImplementation()
    : QSharedData(),
      fields()
{
}


PropertySchemaSharedImplementation::PropertySchemaSharedImplementation(const PropertySchemaSharedImplementation &other)
    : QSharedData(other),
      fields(other.fields)
{
}


PropertySchemaSharedImplementation::~PropertySchemaSharedImplementation()
{
}


void PropertySchemaSharedImplementation::unite(const QList<PropertyField> &list)
{
    QList<PropertyField> extraFields;
    foreach (const PropertyField &field, list) {
        if (!fields.contains(field))
            extraFields << field;
    }
    fields << extraFields;
}

void PropertySchemaSharedImplementation::intersect(const QList<PropertyField> &list)
{
    QList<PropertyField> filteredFields;
    foreach (const PropertyField &field, list) {
        if (fields.contains(field))
            filteredFields << field;
    }
    fields = filteredFields;
}

bool PropertySchemaSharedImplementation::unites(const QList<PropertyField> &list) const
{
    foreach (const PropertyField &field, list) {
        if (!fields.contains(field))
            return false;
    }
    return true;
}

bool PropertySchemaSharedImplementation::intersects(const QList<PropertyField> &list) const
{
    foreach (const PropertyField &field, list) {
        if (fields.contains(field))
            return true;
    }
    return false;
}


PropertySchema::PropertySchema()
    : m(new PropertySchemaSharedImplementation)
{
}


PropertySchema::PropertySchema(const PropertySchema &other)
    : m(other.m)
{
}


PropertySchema::~PropertySchema()
{
}


int PropertySchema::size() const
{ return m->fields.size(); }

PropertyField PropertySchema::field(int i) const
{ return m->fields.value(i, PropertyField()); }

bool PropertySchema::contains(const PropertyField &field) const
{ return m->fields.contains(field); }

void PropertySchema::append(const PropertyField &field)
{ m->fields.append(field); }

void PropertySchema::remove(const PropertyField &field)
{ m->fields.removeOne(field); }

bool PropertySchema::unites(const PropertySchema &other) const
{ return m->unites(other.m->fields); }

void PropertySchema::unite(const PropertySchema &other)
{ *this |= other; }

PropertySchema PropertySchema::united(const PropertySchema &other) const
{ return *this | other; }

bool PropertySchema::intersects(const PropertySchema &other) const
{ return m->intersects(other.m->fields); }

void PropertySchema::intersect(const PropertySchema &other)
{ *this &= other; }

PropertySchema PropertySchema::intersected(const PropertySchema &other) const
{ return *this & other; }


PropertySchema &PropertySchema::operator |=(const PropertySchema &other)
{
    m->unite(other.m->fields);
    return *this;
}

PropertySchema PropertySchema::operator |(const PropertySchema &other) const
{ return PropertySchema(*this) |= other; }

PropertySchema &PropertySchema::operator &=(const PropertySchema &other)
{
    m->intersect(other.m->fields);
    return *this;
}

PropertySchema PropertySchema::operator &(const PropertySchema &other) const
{ return PropertySchema(*this) &= other; }

PropertyField &PropertySchema::operator [](int i)
{ return m->fields[i]; }

const PropertyField &PropertySchema::operator [](int i) const
{ return m->fields[i]; }


PropertySchema &PropertySchema::operator =(const PropertySchema &other)
{
    m = other.m;
    return *this;
}


} // namespace DiagramModeller
