#ifndef COMPONENT_H
#define COMPONENT_H


#include <QSharedDataPointer>
#include <QVariant>
#include <QString>
#include "Core/shareddefs.h"
#include "dmglobal.h"


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

    QString name() const;
    void setName(const QString &);

    VisibilityScope visibility() const;
    void setVisibility(VisibilityScope);

    int parentId() const;
    void setParentId(int);

    QString docText() const;
    void setDocText(const QString &);


    bool isValid() const;
    QVariant property(const QString &key) const;
    bool hasProperty(const QString &key) const;
    void setProperty(const QString &key, const QVariant &value);
    bool clearProperty(const QString &key);
    void clearProperties();

    int childrenCount() const;
    int childAt(int i);
    int childIndex(int id) const;
    bool hasChild(int id) const;
    bool insertChild(int i, int id);
    bool removeChild(int id);
    bool removeChildAt(int i);
    bool moveChild(int from, int to);
    int relationsCount() const;
    bool hasRelation(int id) const;
    bool appendRelaion(int id);
    bool removeRelation(int id);

    Component &operator =(const Component &);

private:
    QSharedDataPointer<ComponentSharedImplementation> m;
};


} // namespace DiagramModeller


#endif // COMPONENT_H
