#ifndef RELATIONSIDEINFO_H
#define RELATIONSIDEINFO_H


#include <QSharedDataPointer>
#include "Core/shareddefs.h"


namespace DiagramModeller {


class RelationSideInfoSharedImplementation;
class DM_CORE_SHARED RelationSideInfo
{
public:
    RelationSideInfo();
    RelationSideInfo(const RelationSideInfo &);

    ~RelationSideInfo();

    RelationSideInfo &operator =(const RelationSideInfo &);

private:
    QSharedDataPointer<RelationSideInfoSharedImplementation> m;
};


} // namespace DiagramModeller


#endif // RELATIONSIDEINFO_H
