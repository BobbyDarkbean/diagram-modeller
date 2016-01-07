#ifndef RELATIONSIDEINFO_SI_H
#define RELATIONSIDEINFO_SI_H


#include <QSharedData>
#include <QString>
#include "dmglobal.h"


namespace DiagramModeller {


class RelationSideInfoSharedImplementation : public QSharedData
{
public:
    RelationSideInfoSharedImplementation();
    RelationSideInfoSharedImplementation(const RelationSideInfoSharedImplementation &);

    ~RelationSideInfoSharedImplementation();

    int componentId;
    RelationCategory category;
    QString multiplicity;
    QString name;
    VisibilityScope visibility;

private:
    RelationSideInfoSharedImplementation &operator =(const RelationSideInfoSharedImplementation &) Q_DECL_EQ_DELETE;
};


} // namespace DiagramModeller


#endif // RELATIONSIDEINFO_SI_H
