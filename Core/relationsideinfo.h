#ifndef RELATIONSIDEINFO_H
#define RELATIONSIDEINFO_H


#include <QSharedDataPointer>
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

    RelationSideInfo &operator =(const RelationSideInfo &);

    int componentId() const;
    void setComponentId(int);

    RelationCategory category() const;
    void setCategory(RelationCategory);

private:
    QSharedDataPointer<RelationSideInfoSharedImplementation> m;
};


} // namespace DiagramModeller


#endif // RELATIONSIDEINFO_H
