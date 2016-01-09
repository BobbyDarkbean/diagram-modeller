#ifndef COMPONENT_H
#define COMPONENT_H


#include <QSharedDataPointer>
#include <QVariant>
#include <QString>
#include "Core/shareddefs.h"


namespace DiagramModeller {


extern DM_CORE_SHARED const int INVALID_COMPONENT_ID;


class ComponentSharedImplementation;
class DM_CORE_SHARED Component
{
public:
    Component();
    Component(const Component &);

    ~Component();

    bool isValid() const;
    QVariant property(const QString &key) const;
    bool hasProperty(const QString &key) const;
    void setProperty(const QString &key, const QVariant &value);
    bool clearProperty(const QString &key);
    void clearProperties();

    Component &operator =(const Component &);

private:
    QSharedDataPointer<ComponentSharedImplementation> m;
};


} // namespace DiagramModeller


#endif // COMPONENT_H
