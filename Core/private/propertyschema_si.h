#ifndef PROPERTYSCHEMA_SI_H
#define PROPERTYSCHEMA_SI_H


#include <QSharedData>
#include <QList>
#include "propertyfield.h"


namespace DiagramModeller {


class PropertySchemaSharedImplementation : public QSharedData
{
public:
    PropertySchemaSharedImplementation();
    PropertySchemaSharedImplementation(const PropertySchemaSharedImplementation &);

    ~PropertySchemaSharedImplementation();

    void unite(const QList<PropertyField> &);
    void intersect(const QList<PropertyField> &);

    bool unites(const QList<PropertyField> &) const;
    bool intersects(const QList<PropertyField> &) const;

    QList<PropertyField> fields;

private:
    PropertySchemaSharedImplementation &operator =(const PropertySchemaSharedImplementation &) Q_DECL_EQ_DELETE;
};


} // namespace DiagramModeller


#endif // PROPERTYSCHEMA_SI_H
