#ifndef COMPONENT_SI_H
#define COMPONENT_SI_H


#include <QSharedData>


namespace DiagramModeller {


class ComponentSharedImplementation : public QSharedData
{
public:
    ComponentSharedImplementation();
    ComponentSharedImplementation(const ComponentSharedImplementation &);

    ~ComponentSharedImplementation();

private:
    ComponentSharedImplementation &operator =(const ComponentSharedImplementation &) Q_DECL_EQ_DELETE;
};


} // namespace DiagramModeller


#endif // COMPONENT_SI_H
