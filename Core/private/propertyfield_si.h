#ifndef PROPERTYFIELD_SI_H
#define PROPERTYFIELD_SI_H


#include <QSharedData>
#include <QString>
#include "dmglobal.h"


namespace DiagramModeller {


class PropertyFieldSharedImplementation : public QSharedData
{
public:
    PropertyFieldSharedImplementation();
    PropertyFieldSharedImplementation(const PropertyFieldSharedImplementation &);

    ~PropertyFieldSharedImplementation();

    QString name;
    PropertyType type;

private:
    PropertyFieldSharedImplementation &operator =(const PropertyFieldSharedImplementation &) Q_DECL_EQ_DELETE;
};


} // namespace DiagramModeller


#endif // PROPERTYFIELD_SI_H
