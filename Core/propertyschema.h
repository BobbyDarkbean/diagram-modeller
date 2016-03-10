#ifndef PROPERTYSCHEMA_H
#define PROPERTYSCHEMA_H


#include <QSharedDataPointer>
#include "Core/shareddefs.h"


namespace DiagramModeller {


class PropertyField;


class PropertySchemaSharedImplementation;
class DM_CORE_SHARED PropertySchema
{
public:
    PropertySchema();
    PropertySchema(const PropertySchema &);

    ~PropertySchema();

    int size() const;

    PropertyField field(int i) const;
    bool contains(const PropertyField &field) const;
    void append(const PropertyField &field);
    void remove(const PropertyField &field);

    bool unites(const PropertySchema &other) const;
    void unite(const PropertySchema &other);
    PropertySchema united(const PropertySchema &other) const;
    bool intersects(const PropertySchema &other) const;
    void intersect(const PropertySchema &other);
    PropertySchema intersected(const PropertySchema &other) const;

    PropertySchema &operator |=(const PropertySchema &other);
    PropertySchema operator |(const PropertySchema &other) const;
    PropertySchema &operator &=(const PropertySchema &other);
    PropertySchema operator &(const PropertySchema &other) const;

    PropertyField &operator [](int i);
    const PropertyField &operator [](int i) const;

    PropertySchema &operator =(const PropertySchema &);

private:
    QSharedDataPointer<PropertySchemaSharedImplementation> m;
};


} // namespace DiagramModeller


#endif // PROPERTYSCHEMA_H
