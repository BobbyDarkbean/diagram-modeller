#ifndef DMGLOBAL_H
#define DMGLOBAL_H


namespace DiagramModeller {


enum ComponentCategory
{
    CC_DiagramRoot,
    CC_Class,
    CC_Interface,
    CC_Enumeration,
    CC_Literal,
    CC_Attribute,
    CC_Operation,
    CC_Parameter,
    CC_Return
};

enum VisibilityScope
{
    VS_Public,
    VS_Protected,
    VS_Private,
    VS_Package
};

enum RelationCategory
{
    RC_None,
    RC_Generalization,
    RC_Realization,
    RC_Composition,
    RC_Aggregation,
    RC_Association,
    RC_DirectedAssociation,
    RC_Dependency
};

enum RelationSide
{
    RS_1,
    RS_2
};


} // namespace DiagramModeller


#endif // DMGLOBAL_H
