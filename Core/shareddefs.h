#ifndef SHAREDDEFS_H
#define SHAREDDEFS_H


#include <qobjectdefs.h>


#ifdef DM_CORE_LIB
#define DM_CORE_SHARED Q_DECL_EXPORT
#else
#define DM_CORE_SHARED Q_DECL_IMPORT
#endif // DM_CORE_LIB


#endif // SHAREDDEFS_H
