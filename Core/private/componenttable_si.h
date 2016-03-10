#ifndef COMPONENTTABLE_SI_H
#define COMPONENTTABLE_SI_H


#include <QSharedData>
#include <QHash>
#include "component.h"


namespace DiagramModeller {


class ComponentTableSharedImplementation : public QSharedData
{
public:
    ComponentTableSharedImplementation();
    ComponentTableSharedImplementation(const ComponentTableSharedImplementation &);

    ~ComponentTableSharedImplementation();

    QHash<int, Component> components;

private:
    ComponentTableSharedImplementation &operator =(const ComponentTableSharedImplementation &) Q_DECL_EQ_DELETE;
};


} // namespace DiagramModeller


#endif // COMPONENTTABLE_SI_H
