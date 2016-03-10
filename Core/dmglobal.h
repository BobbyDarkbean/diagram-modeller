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


enum MultiplicityRange
{
    MR_ZeroOrOne,
    MR_One,
    MR_ZeroOrMore,
    MR_OneOrMore
};


enum PropertyType
{
    PT_Unknown,
    PT_String,
    PT_Integer,
    PT_Real,
    PT_Boolean,
    PT_Visibility,
    PT_Multiplicity,
    PT_Color,
    PT_Rectangle,
    PT_Path,
    PT_List
};


} // namespace DiagramModeller


#endif // DMGLOBAL_H
