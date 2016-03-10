#ifndef PROPERTYFIELD_H
#define PROPERTYFIELD_H


#include <QSharedDataPointer>
#include "Core/shareddefs.h"
#include "dmglobal.h"


namespace DiagramModeller {


class PropertyFieldSharedImplementation;
class DM_CORE_SHARED PropertyField
{
public:
    PropertyField();
    PropertyField(const PropertyField &);

    ~PropertyField();

    bool isValid() const;

    QString name() const;
    void setName(const QString &);

    PropertyType type() const;
    void setType(PropertyType);

    PropertyField &operator =(const PropertyField &);

private:
    QSharedDataPointer<PropertyFieldSharedImplementation> m;
};


bool operator ==(const PropertyField &a, const PropertyField &b);
bool operator !=(const PropertyField &a, const PropertyField &b);


} // namespace DiagramModeller


#endif // PROPERTYFIELD_H
