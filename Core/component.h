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

    int childrenCount() const;
    int childAt(int i);
    int childIndex(int id) const;
    int hasChild(int id) const;
    bool insertChild(int i, int id);
    bool removeChild(int id);
    bool removeChildAt(int i);
    bool moveChild(int from, int to);
    int relationsCount() const;
    int hasRelation(int id) const;
    bool appendRelaion(int id);
    bool removeRelation(int id);

    Component &operator =(const Component &);

private:
    QSharedDataPointer<ComponentSharedImplementation> m;
};


} // namespace DiagramModeller


#endif // COMPONENT_H
