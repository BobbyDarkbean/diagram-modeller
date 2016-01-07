#ifndef RELATION_SI_H
#define RELATION_SI_H


#include <QSharedData>


namespace DiagramModeller {


class RelationSharedImplementation : public QSharedData
{
public:
    RelationSharedImplementation();
    RelationSharedImplementation(const RelationSharedImplementation &);

    ~RelationSharedImplementation();

private:
    RelationSharedImplementation &operator =(const RelationSharedImplementation &) Q_DECL_EQ_DELETE;
};


} // namespace DiagramModeller


#endif // RELATION_SI_H
