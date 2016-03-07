#ifndef COMPONENT_SI_H
#define COMPONENT_SI_H


#include <QSharedData>
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
    QMap<QString, QVariant> properties;

private:
    ComponentSharedImplementation &operator =(const ComponentSharedImplementation &) Q_DECL_EQ_DELETE;
};


} // namespace DiagramModeller


#endif // COMPONENT_SI_H
