#ifndef RELATION_H
#define RELATION_H


#include <QSharedDataPointer>
#include <QString>
#include <QVariant>
#include "Core/shareddefs.h"
#include "relationsideinfo.h"
#include "dmglobal.h"


namespace DiagramModeller {


extern DM_CORE_SHARED const int INVALID_RELATION_ID;


class RelationSharedImplementation;
class DM_CORE_SHARED Relation
{
public:
    explicit Relation(int id = INVALID_RELATION_ID);
    Relation(const Relation &);

    ~Relation();

    int id() const;

    QString name() const;
    void setName(const QString &);

    bool isValid() const;

    QVariant property(const QString &key) const;
    bool hasProperty(const QString &key) const;
    void setProperty(const QString &key, const QVariant &value);
    bool clearProperty(const QString &key);
    void clearProperties();

    RelationSideInfo sideInfo(RelationSide side) const;
    void setRelationSideComponent(RelationSide side, int componentId);
    void setRelationSideCategory(RelationSide side, RelationCategory cat);
    void setRelationSideMultiplicity(RelationSide side, const QString &multiplicity);
    void setRelationSideName(RelationSide side, const QString &name);
    void setRelationSideVisibility(RelationSide side, VisibilityScope visibility);

    Relation &operator =(const Relation &);

private:
    QSharedDataPointer<RelationSharedImplementation> m;
};


} // namespace DiagramModeller


#endif // RELATION_H
