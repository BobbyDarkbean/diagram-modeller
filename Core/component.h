#ifndef COMPONENT_H
#define COMPONENT_H


#include <QSharedDataPointer>
#include "Core/shareddefs.h"
#include "dmglobal.h"


class QVariant;


namespace DiagramModeller {


extern DM_CORE_SHARED const int INVALID_COMPONENT_ID;


class ComponentSharedImplementation;
class DM_CORE_SHARED Component
{
public:
    explicit Component(int id = INVALID_COMPONENT_ID);
    Component(const Component &);

    ~Component();

    ComponentCategory category() const;
    void setCategory(ComponentCategory);

    int id() const;

    bool isValid() const;
    QVariant property(const QString &key) const;
    bool hasProperty(const QString &key) const;
    void setProperty(const QString &key, const QVariant &value);
    bool clearProperty(const QString &key);
    void clearProperties();

    QVariant &operator [](const QString &key);
    QVariant operator [](const QString &key) const;

    Component &operator =(const Component &);

private:
    QSharedDataPointer<ComponentSharedImplementation> m;
};


} // namespace DiagramModeller


#endif // COMPONENT_H
