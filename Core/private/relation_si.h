#ifndef RELATION_SI_H
#define RELATION_SI_H


#include <QSharedData>
#include <QString>
#include <QMap>
#include <QVariant>
#include "dmglobal.h"
#include "relationsideinfo.h"


namespace DiagramModeller {


class RelationSharedImplementation : public QSharedData
{
public:
    RelationSharedImplementation();
    RelationSharedImplementation(const RelationSharedImplementation &);

    ~RelationSharedImplementation();

    int id;
    QString name;
    QMap<QString, QVariant> properties;
    QMap<RelationSide, RelationSideInfo> sides;


private:
    RelationSharedImplementation &operator =(const RelationSharedImplementation &) Q_DECL_EQ_DELETE;
};


} // namespace DiagramModeller


#endif // RELATION_SI_H
