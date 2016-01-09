#ifndef RELATIONSIDEINFO_H
#define RELATIONSIDEINFO_H


#include <QSharedDataPointer>
#include <QString>
#include "Core/shareddefs.h"
#include "dmglobal.h"


namespace DiagramModeller {


class RelationSideInfoSharedImplementation;
class DM_CORE_SHARED RelationSideInfo
{
public:
    RelationSideInfo();
    RelationSideInfo(const RelationSideInfo &);

    ~RelationSideInfo();

    int componentId() const;
    void setComponentId(int);

    RelationCategory category() const;
    void setCategory(RelationCategory);

    QString multiplicity() const;
    void setMultiplicity(const QString &);

    QString name() const;
    void setName(const QString &);

    VisibilityScope visibility() const;
    void setVisibility(VisibilityScope);

    RelationSideInfo &operator =(const RelationSideInfo &);

private:
    QSharedDataPointer<RelationSideInfoSharedImplementation> m;
};


} // namespace DiagramModeller


#endif // RELATIONSIDEINFO_H
