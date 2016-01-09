#ifndef COMPONENT_SI_H
#define COMPONENT_SI_H


#include <QSharedData>
#include <QMap>
#include <QList>
#include <QSet>
#include <QVariant>
#include "dmglobal.h"


namespace DiagramModeller {


class ComponentSharedImplementation : public QSharedData
{
public:
    ComponentSharedImplementation();
    ComponentSharedImplementation(const ComponentSharedImplementation &);

    ~ComponentSharedImplementation();

    ComponentCategory category;
    int id;
    QString name;
    VisibilityScope visibility;
    int parentId;
    QString docText;
    QMap<QString, QVariant> properties;
    QList<int> children;
    QSet<int> relations;

private:
    ComponentSharedImplementation &operator =(const ComponentSharedImplementation &) Q_DECL_EQ_DELETE;
};


} // namespace DiagramModeller


#endif // COMPONENT_SI_H
