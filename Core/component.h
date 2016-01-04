#ifndef COMPONENT_H
#define COMPONENT_H


#include <QSharedDataPointer>
#include "Core/shareddefs.h"


namespace DiagramModeller {


class ComponentSharedImplementation;
class DM_CORE_SHARED Component
{
public:
    Component();
    Component(const Component &);

    ~Component();

    Component &operator =(const Component &);

private:
    QSharedDataPointer<ComponentSharedImplementation> m;
};


} // namespace DiagramModeller


#endif // COMPONENT_H
