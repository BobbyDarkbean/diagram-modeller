#ifndef RELATION_H
#define RELATION_H


#include <QSharedDataPointer>
#include "Core/shareddefs.h"


namespace DiagramModeller {


extern DM_CORE_SHARED const int INVALID_RELATION_ID;


class RelationSharedImplementation;
class DM_CORE_SHARED Relation
{
public:
    explicit Relation(int id = INVALID_RELATION_ID);
    Relation(const Relation &);

    ~Relation();

    Relation &operator =(const Relation &);

private:
    QSharedDataPointer<RelationSharedImplementation> m;
};


} // namespace DiagramModeller


#endif // RELATION_H
