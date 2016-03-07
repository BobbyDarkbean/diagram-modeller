#ifndef DMGLOBAL_H
#define DMGLOBAL_H


namespace DiagramModeller {


enum ComponentCategory
{
    CC_None,
    CC_DiagramRoot,
    CC_Class,
    CC_Interface,
    CC_Enumeration,
    CC_Literal,
    CC_Attribute,
    CC_Operation,
    CC_Parameter,
    CC_Return,
    CC_Signal,
    CC_Generalization,
    CC_Realization,
    CC_Association,
    CC_Dependency
};


enum VisibilityScope
{
    VS_Public,
    VS_Protected,
    VS_Private,
    VS_Package
};


} // namespace DiagramModeller


#endif // DMGLOBAL_H
