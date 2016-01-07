#ifndef RELATIONSIDEINFO_SI_H
#define RELATIONSIDEINFO_SI_H


#include <QSharedData>


namespace DiagramModeller {


class RelationSideInfoSharedImplementation : public QSharedData
{
public:
    RelationSideInfoSharedImplementation();
    RelationSideInfoSharedImplementation(const RelationSideInfoSharedImplementation &);

    ~RelationSideInfoSharedImplementation();

private:
    RelationSideInfoSharedImplementation &operator =(const RelationSideInfoSharedImplementation &) Q_DECL_EQ_DELETE;
};


} // namespace DiagramModeller


#endif // RELATIONSIDEINFO_SI_H

