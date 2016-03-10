#ifndef COMPONENTTABLE_H
#define COMPONENTTABLE_H


#include <QSharedDataPointer>
#include "Core/shareddefs.h"
#include "dmglobal.h"


class QVariant;


namespace DiagramModeller {


class Component;


class ComponentTableSharedImplementation;
class DM_CORE_SHARED ComponentTable
{
public:
    ComponentTable();
    ComponentTable(const ComponentTable &);

    ~ComponentTable();

    int size() const;

    Component component(int id) const;
    bool hasComponent(int id);
    void insertComponent(int id, const Component &component);
    bool removeComponent(int id);
    void clear();

    ComponentCategory category(int id) const;

    bool isValid(int id) const;
    QVariant property(int id, const QString &key) const;
    bool hasProperty(int id, const QString &key) const;
    void setProperty(int id, const QString &key, const QVariant &value);
    bool clearProperty(int id, const QString &key);
    void clearProperties(int id);

    ComponentTable &operator =(const ComponentTable &);

private:
    QSharedDataPointer<ComponentTableSharedImplementation> m;
};


} // namespace DiagramModeller


#endif // COMPONENTTABLE_H
