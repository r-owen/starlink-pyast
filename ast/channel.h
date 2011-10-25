/*
*+
*  Name:
*     channel.h

*  Type:
*     C include file.

*  Purpose:
*     Define the interface to the Channel class.

*  Invocation:
*     #include "channel.h"

*  Description:
*     This include file defines the interface to the Channel class and
*     provides the type definitions, function prototypes and macros,
*     etc. needed to use this class.
*
*     A Channel is the basic form of AST I/O channel, through which
*     Objects may be written and later read back. It causes I/O to
*     take place using a textual format via standard input and
*     standard output.
*
*     Writing to a Channel will result in a textual representation of
*     an Object being produced on standard output. Reading from a
*     Channel will causes a textual description of an Object to be
*     read from standard input, and that Object to be
*     re-created. Channel I/O is stream based, and multiple objects
*     may be written or read in succession through the same Channel. A
*     null Object pointer is returned if there is no more input to
*     read.

*  Inheritance:
*     The Channel class inherits from the Object class.

*  Attributes Over-Ridden:
*     None.

*  New Attributes Defined:
*     Comment (integer)
*        A boolean value (0 or 1) which controls whether comments are
*        to be included in textual output generated by a Channel. If
*        this value is non-zero (the default), then comments will be
*        included. If it is zero, comments will be omitted.
*     Full (integer)
*        A three-state flag (taking values -1, 0 or +1) which controls
*        the amount of information included in textual output
*        generated by a Channel. If this value is zero (the default),
*        then a modest amount of non-essential but useful information
*        will be included along with the output. If Full is negative,
*        all non-essential information will be suppressed, while if it
*        is positive, the output will include the maximum amount of
*        information about the Object being written.
*     Skip (integer)
*        A boolean value which indicates whether the Objects being
*        read through a Channel are inter-mixed with other external
*        data. If this value is zero (the default), then the source of
*        input data is expected to contain descriptions of AST Objects
*        and comments and nothing else (if anything else is read, an
*        error will result). If Skip is non-zero, then any non-Object
*        data encountered between Objects will simply be skipped over
*        in order to reach the next Object.

*  Methods Over-Ridden:
*     Public:
*        None.
*
*     Protected:
*        astClearAttrib
*           Clear an attribute value for a Mapping.
*        astGetAttrib
*           Get an attribute value for a Mapping.
*        astSetAttrib
*           Set an attribute value for a Mapping.
*        astTestAttrib
*           Test if an attribute value has been set for a Mapping.

*  New Methods Defined:
*     Public:
*        astRead
*           Read an Object from a Channel.
*        astWrite
*           Write an Object to a Channel.
*
*     Protected:
*        astClearComment
*           Clear the Comment attribute for a Channel.
*        astClearFull
*           Clear the Full attribute for a Channel.
*        astClearSkip
*           Clear the Skip attribute for a Channel.
*        astGetComment
*           Get the value of the Comment attribute for a Channel.
*        astGetFull
*           Get the value of the Full attribute for a Channel.
*        astGetNextData
*           Read the next item of data from a data source.
*        astGetNextText
*           Read the next line of input text from a data source.
*        astGetSkip
*           Get the value of the Skip attribute for a Channel.
*        astPutNextText
*           Write a line of output text to a data sink.
*        astReadClassData
*           Read values from a data source for a class loader.
*        astReadDouble
*           Read a double value as part of loading a class.
*        astReadInt
*           Read an int value as part of loading a class.
*        astReadObject
*           Read a (sub)Object as part of loading a class.
*        astReadString
*           Read a string value as part of loading a class.
*        astSetComment
*           Set the value of the Comment attribute for a Channel.
*        astSetFull
*           Set the value of the Full attribute for a Channel.
*        astSetSkip
*           Set the value of the Skip attribute for a Channel.
*        astTestComment
*           Test whether a value has been set for the Comment attribute of a
*           Channel.
*        astTestFull
*           Test whether a value has been set for the Full attribute of a
*           Channel.
*        astTestSkip
*           Test whether a value has been set for the Skip attribute of a
*           Channel.
*        astWriteBegin
*           Write a "Begin" data item to a data sink.
*        astWriteDouble
*           Write a double value to a data sink.
*        astWriteEnd
*           Write an "End" data item to a data sink.
*        astWriteInt
*           Write an integer value to a data sink.
*        astWriteIsA
*           Write an "IsA" data item to a data sink.
*        astWriteObject
*           Write an Object as a value to a data sink.
*        astWriteString
*           Write a string value to a data sink.

*  Other Class Functions:
*     Public:
*        astChannel
*           Create a Channel.
*        astChannelFor
*           Create a Channel from a foreign language interface.
*        astIsAChannel
*           Test class membership.
*
*     Protected:
*        astCheckChannel
*           Validate class membership.
*        astInitChannel
*           Initialise a Channel.
*        astInitChannelVtab
*           Initialise the virtual function table for the Channel class.
*        astLoadChannel
*           Load a Channel.

*  Type Definitions:
*     Public:
*        AstChannel
*           Channel object type.
*
*     Protected:
*        AstChannelVtab
*           Channel virtual function table type.

*  Feature Test Macros:
*     astCLASS
*        If the astCLASS macro is undefined, only public symbols are
*        made available, otherwise protected symbols (for use in other
*        class implementations) are defined. This macro also affects
*        the reporting of error context information, which is only
*        provided for external calls to the AST library.

*  Copyright:
*     Copyright (C) 1997-2006 Council for the Central Laboratory of the
*     Research Councils

*  Licence:
*     This program is free software; you can redistribute it and/or
*     modify it under the terms of the GNU General Public Licence as
*     published by the Free Software Foundation; either version 2 of
*     the Licence, or (at your option) any later version.
*
*     This program is distributed in the hope that it will be
*     useful,but WITHOUT ANY WARRANTY; without even the implied
*     warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
*     PURPOSE. See the GNU General Public Licence for more details.
*
*     You should have received a copy of the GNU General Public Licence
*     along with this program; if not, write to the Free Software
*     Foundation, Inc., 59 Temple Place,Suite 330, Boston, MA
*     02111-1307, USA

*  Authors:
*     RFWS: R.F. Warren-Smith (Starlink)

*  History:
*     12-AUG-1996 (RFWS):
*        Original version.
*     12-DEC-1996 (RFWS):
*        Added the astChannelFor function.
*     11-NOV-2002 (DSB):
*        Added astWriteInvocations.
*     8-JAN-2003 (DSB):
*        Added protected astInitAxisVtab method.
*-
*/

/* Include files. */
/* ============== */
/* Interface definitions. */
/* ---------------------- */
#include "object.h"              /* Base Object class */

/* Note that the usual setting of the CHANNEL_INCLUDED flag, which
   prevents this file being included more than once, must be deferred
   until after including the "object.h" file. This is because
   "object.h" needs to include the present interface definition (as a
   form of "forward reference") in order to have access to I/O
   Channels itself. */
#if !defined( CHANNEL_INCLUDED )
#define CHANNEL_INCLUDED

/* C header files. */
/* --------------- */
#include <stddef.h>

/* Macros */
/* ====== */
/* Define constants used to size global arrays in this module. */
#define AST__CHANNEL_GETATTRIB_BUFF_LEN 50

/* Define a dummy __attribute__ macro for use on non-GNU compilers. */
#ifndef __GNUC__
#  define  __attribute__(x)  /*NOTHING*/
#endif

/* Type Definitions. */
/* ================= */

/* The astWarnings function returns a KeyMap pointer, but we cannot
   include keymap.h here to define the AstKeyMap type since keymap.h
   itself include sthis file. So we make a temporary declaration which
   will be replaced by the full one when the keymap.h file is included. */
struct AstKeyMap;

/* Channel structure. */
/* ------------------ */
/* This structure contains all information that is unique to each
   object in the class (e.g. its instance variables). */
typedef struct AstChannel {

/* Attributes inherited from the parent class. */
   AstObject object;             /* Parent class structure */

/* Attributes specific to objects in this class. */
   const char *(* source)( void ); /* Pointer to source function */
   char *(* source_wrap)( const char *(*)(void), int * );
                                 /* Source wrapper function pointer */
   void (* sink)( const char * ); /* Pointer to sink function */
   void (* sink_wrap)( void (*)( const char *), const char *, int * );
                                 /* Sink wrapper function pointer */
   int comment;                  /* Output comments? */
   int full;                     /* Set max/normal/min information level */
   int skip;                     /* Skip data between Objects? */
   int indent;                   /* Indentation increment in astWrite output */
   int report_level;             /* Skip data between Objects? */
   int strict;                   /* Report unexpected data items? */
   void *data;                   /* Data to pass to source/sink functions */
   char **warnings;              /* Array of warning strings */
   int nwarn;                    /* Size of warnings array */
   FILE *fd_in;                  /* Descriptor for source text file */
   char *fn_in;                  /* Full path for source text file */
   FILE *fd_out;                 /* Descriptor for sink text file */
   char *fn_out;                 /* Full path for sink text file */
} AstChannel;

/* Virtual function table. */
/* ----------------------- */
/* This table contains all information that is the same for all
   objects in the class (e.g. pointers to its virtual functions). */
#if defined(astCLASS)            /* Protected */
typedef struct AstChannelVtab {

/* Properties (e.g. methods) inherited from the parent class. */
   AstObjectVtab object_vtab;    /* Parent class virtual function table */

/* A Unique identifier to determine class membership. */
   AstClassIdentifier id;

/* Properties (e.g. methods) specific to this class. */
   struct AstKeyMap *(* Warnings)( AstChannel *, int * );
   AstObject *(* Read)( AstChannel *, int * );
   AstObject *(* ReadObject)( AstChannel *, const char *, AstObject *, int * );
   char *(* GetNextText)( AstChannel *, int * );
   char *(* ReadString)( AstChannel *, const char *, const char *, int * );
   double (* ReadDouble)( AstChannel *, const char *, double, int * );
   int (* GetComment)( AstChannel *, int * );
   int (* GetFull)( AstChannel *, int * );
   int (* GetStrict)( AstChannel *, int * );
   int (* ReadInt)( AstChannel *, const char *, int, int * );
   int (* TestComment)( AstChannel *, int * );
   int (* TestFull)( AstChannel *, int * );
   int (* TestStrict)( AstChannel *, int * );
   int (* Write)( AstChannel *, AstObject *, int * );
   void (* AddWarning)( AstChannel *, int, const char *, const char *, int * );
   void (* ClearComment)( AstChannel *, int * );
   void (* ClearFull)( AstChannel *, int * );
   void (* ClearStrict)( AstChannel *, int * );
   void (* GetNextData)( AstChannel *, int, char **, char **, int * );
   void (* PutChannelData)( AstChannel *, void *, int * );
   void (* PutNextText)( AstChannel *, const char *, int * );
   void (* ReadClassData)( AstChannel *, const char *, int * );
   void (* SetComment)( AstChannel *, int, int * );
   void (* SetFull)( AstChannel *, int, int * );
   void (* SetStrict)( AstChannel *, int, int * );
   void (* WriteBegin)( AstChannel *, const char *, const char *, int * );
   void (* WriteDouble)( AstChannel *, const char *, int, int, double, const char *, int * );
   void (* WriteEnd)( AstChannel *, const char *, int * );
   void (* WriteInt)( AstChannel *, const char *, int, int, int, const char *, int * );
   void (* WriteIsA)( AstChannel *, const char *, const char *, int * );
   void (* WriteObject)( AstChannel *, const char *, int, int, AstObject *, const char *, int * );
   void (* WriteString)( AstChannel *, const char *, int, int, const char *, const char *, int * );

   int (* GetSkip)( AstChannel *, int * );
   int (* TestSkip)( AstChannel *, int * );
   void (* ClearSkip)( AstChannel *, int * );
   void (* SetSkip)( AstChannel *, int, int * );

   int (* GetReportLevel)( AstChannel *, int * );
   int (* TestReportLevel)( AstChannel *, int * );
   void (* ClearReportLevel)( AstChannel *, int * );
   void (* SetReportLevel)( AstChannel *, int, int * );

   int (* GetIndent)( AstChannel *, int * );
   int (* TestIndent)( AstChannel *, int * );
   void (* ClearIndent)( AstChannel *, int * );
   void (* SetIndent)( AstChannel *, int, int * );

   const char *(* GetSourceFile)( AstChannel *, int * );
   int (* TestSourceFile)( AstChannel *, int * );
   void (* ClearSourceFile)( AstChannel *, int * );
   void (* SetSourceFile)( AstChannel *, const char *, int * );

   const char *(* GetSinkFile)( AstChannel *, int * );
   int (* TestSinkFile)( AstChannel *, int * );
   void (* ClearSinkFile)( AstChannel *, int * );
   void (* SetSinkFile)( AstChannel *, const char *, int * );
} AstChannelVtab;

/* Define a private structure type used to store linked lists of
   name-value associations. */
typedef struct AstChannelValue {
   struct AstChannelValue *flink; /* Link to next element */
   struct AstChannelValue *blink; /* Link to previous element */
   char *name;                    /* Pointer to name string */
   union {                        /* Holds pointer to value */
      char *string;               /* Pointer to string value */
      AstObject *object;          /* Pointer to Object value */
   } ptr;
   int is_object;                 /* Whether value is an Object (else string) */
} AstChannelValue;

#if defined(THREAD_SAFE)

/* Define a structure holding all data items that are global within this
   class. */
typedef struct AstChannelGlobals {
   AstChannelVtab Class_Vtab;
   int Class_Init;
   int AstReadClassData_Msg;
   char GetAttrib_Buff[ AST__CHANNEL_GETATTRIB_BUFF_LEN + 1 ];
   int Items_Written;
   int Current_Indent;
   int Nest;
   int Nwrite_Invoc;
   char **Object_Class;
   AstChannelValue **Values_List;
   char **Values_Class;
   int *Values_OK;
   int *End_Of_Object;
   void *Channel_Data;
} AstChannelGlobals;

#endif



#endif

/* Function prototypes. */
/* ==================== */
/* Prototypes for standard class functions. */
/* ---------------------------------------- */
astPROTO_CHECK(Channel)          /* Check class membership */
astPROTO_ISA(Channel)            /* Test class membership */

/* Constructor. */
#if defined(astCLASS)            /* Protected. */
AstChannel *astChannel_( const char *(*)( void ), void (*)( const char * ),
                         const char *, int *, ...);
#else
AstChannel *astChannelId_( const char *(*)( void ), void (*)( const char * ),
                           const char *, ... )__attribute__((format(printf,3,4)));
AstChannel *astChannelForId_( const char *(*)( void ),
                              char *(*)( const char *(*)( void ), int * ),
                              void (*)( const char * ),
                              void (*)( void (*)( const char * ),
                                        const char *, int * ),
                              const char *, ... );
#endif


#if defined(astCLASS)            /* Protected */

/* Initialiser. */
AstChannel *astInitChannel_( void *, size_t, int, AstChannelVtab *,
                             const char *, const char *(*)( void ),
                             char *(*)( const char *(*)( void ), int * ),
                             void (*)( const char * ),
                             void (*)( void (*)( const char * ),
                             const char *, int * ), int * );


/* Vtab initialiser. */
void astInitChannelVtab_( AstChannelVtab *, const char *, int * );

/* Loader. */
AstChannel *astLoadChannel_( void *, size_t, AstChannelVtab *,
                             const char *, AstChannel *channel, int * );

/* Thread-safe initialiser for all global data used by this module. */
#if defined(THREAD_SAFE)
void astInitChannelGlobals_( AstChannelGlobals * );
#endif
#endif

/* Prototypes for member functions. */
/* -------------------------------- */
AstObject *astRead_( AstChannel *, int * );
int astWrite_( AstChannel *, AstObject *, int * );
void astPutChannelData_( AstChannel *, void *, int * );
void *astChannelData_( void );
struct AstKeyMap *astWarnings_( AstChannel *, int * );

char *astSourceWrap_( const char *(*)( void ), int * );
void astSinkWrap_( void (*)( const char * ), const char *, int * );

# if defined(astCLASS)           /* Protected */
void astStoreChannelData_( AstChannel *, int * );
AstObject *astReadObject_( AstChannel *, const char *, AstObject *, int * );
char *astGetNextText_( AstChannel *, int * );
char *astReadString_( AstChannel *, const char *, const char *, int * );
double astReadDouble_( AstChannel *, const char *, double, int * );
int astGetComment_( AstChannel *, int * );
int astGetFull_( AstChannel *, int * );
int astGetStrict_( AstChannel *, int * );
int astReadInt_( AstChannel *, const char *, int, int * );
int astTestComment_( AstChannel *, int * );
int astTestFull_( AstChannel *, int * );
int astTestStrict_( AstChannel *, int * );
void astAddWarning_( void *, int, const char *, const char *, int *, ... )__attribute__((format(printf,3,6)));
void astClearComment_( AstChannel *, int * );
void astClearFull_( AstChannel *, int * );
void astClearStrict_( AstChannel *, int * );
void astGetNextData_( AstChannel *, int, char **, char **, int * );
void astPutNextText_( AstChannel *, const char *, int * );
void astReadClassData_( AstChannel *, const char *, int * );
void astSetComment_( AstChannel *, int, int * );
void astSetFull_( AstChannel *, int, int * );
void astSetStrict_( AstChannel *, int, int * );
void astWriteBegin_( AstChannel *, const char *, const char *, int * );
void astWriteDouble_( AstChannel *, const char *, int, int, double, const char *, int * );
void astWriteEnd_( AstChannel *, const char *, int * );
void astWriteInt_( AstChannel *, const char *, int, int, int, const char *, int * );
int astWriteInvocations_( int * );
void astWriteIsA_( AstChannel *, const char *, const char *, int * );
void astWriteObject_( AstChannel *, const char *, int, int, AstObject *, const char *, int * );
void astWriteString_( AstChannel *, const char *, int, int, const char *, const char *, int * );

int astGetSkip_( AstChannel *, int * );
int astTestSkip_( AstChannel *, int * );
void astClearSkip_( AstChannel *, int * );
void astSetSkip_( AstChannel *, int, int * );

int astGetReportLevel_( AstChannel *, int * );
int astTestReportLevel_( AstChannel *, int * );
void astClearReportLevel_( AstChannel *, int * );
void astSetReportLevel_( AstChannel *, int, int * );

int astGetIndent_( AstChannel *, int * );
int astTestIndent_( AstChannel *, int * );
void astClearIndent_( AstChannel *, int * );
void astSetIndent_( AstChannel *, int, int * );

const char *astGetSourceFile_( AstChannel *, int * );
int astTestSourceFile_( AstChannel *, int * );
void astClearSourceFile_( AstChannel *, int * );
void astSetSourceFile_( AstChannel *, const char *, int * );

const char *astGetSinkFile_( AstChannel *, int * );
int astTestSinkFile_( AstChannel *, int * );
void astClearSinkFile_( AstChannel *, int * );
void astSetSinkFile_( AstChannel *, const char *, int * );

#endif

/* Function interfaces. */
/* ==================== */
/* These macros are wrap-ups for the functions defined by this class
   to make them easier to invoke (e.g. to avoid type mis-matches when
   passing pointers to objects from derived classes). */

/* Interfaces to standard class functions. */
/* --------------------------------------- */
/* Some of these functions provide validation, so we cannot use them to
   validate their own arguments. We must use a cast when passing object
   pointers (so that they can accept objects from derived classes). */

/* Check class membership. */
#define astCheckChannel(this) astINVOKE_CHECK(Channel,this,0)
#define astVerifyChannel(this) astINVOKE_CHECK(Channel,this,1)

/* Test class membership. */
#define astIsAChannel(this) astINVOKE_ISA(Channel,this)

/* Constructor. */
#if defined(astCLASS)            /* Protected. */
#define astChannel astINVOKE(F,astChannel_)
#else
#define astChannel astINVOKE(F,astChannelId_)
#define astChannelFor astINVOKE(F,astChannelForId_)
#endif

#if defined(astCLASS)            /* Protected */

/* Initialiser. */
#define astInitChannel(mem,size,init,vtab,name,source,source_wrap,sink,sink_wrap) \
astINVOKE(O,astInitChannel_(mem,size,init,vtab,name,source,source_wrap,sink,sink_wrap,STATUS_PTR))

/* Vtab Initialiser. */
#define astInitChannelVtab(vtab,name) astINVOKE(V,astInitChannelVtab_(vtab,name,STATUS_PTR))
/* Loader. */
#define astLoadChannel(mem,size,vtab,name,channel) \
astINVOKE(O,astLoadChannel_(mem,size,vtab,name,astCheckChannel(channel),STATUS_PTR))
#endif

/* Interfaces to member functions. */
/* ------------------------------- */
/* Here we make use of astCheckChannel to validate Channel pointers
   before use.  This provides a contextual error report if a pointer
   to the wrong sort of Object is supplied. */

#define astRead(this) \
astINVOKE(O,astRead_(astCheckChannel(this),STATUS_PTR))
#define astWrite(this,object) \
astINVOKE(V,astWrite_(astCheckChannel(this),astCheckObject(object),STATUS_PTR))
#define astPutChannelData(this,data) \
astINVOKE(V,astPutChannelData_(astCheckChannel(this),data,STATUS_PTR))
#define astWarnings(this) \
astINVOKE(O,astWarnings_(astCheckChannel(this),STATUS_PTR))

#define astSourceWrap astSourceWrap_
#define astSinkWrap astSinkWrap_
#define astChannelData astChannelData_()

#if defined(astCLASS)            /* Protected */
#define astAddWarning astAddWarning_
#define astStoreChannelData(this) \
astStoreChannelData_(astCheckChannel(this),STATUS_PTR)

#define astClearComment(this) \
astINVOKE(V,astClearComment_(astCheckChannel(this),STATUS_PTR))
#define astClearFull(this) \
astINVOKE(V,astClearFull_(astCheckChannel(this),STATUS_PTR))
#define astClearStrict(this) \
astINVOKE(V,astClearStrict_(astCheckChannel(this),STATUS_PTR))
#define astGetComment(this) \
astINVOKE(V,astGetComment_(astCheckChannel(this),STATUS_PTR))
#define astGetFull(this) \
astINVOKE(V,astGetFull_(astCheckChannel(this),STATUS_PTR))
#define astGetNextData(this,begin,name,val) \
astINVOKE(V,astGetNextData_(astCheckChannel(this),begin,name,val,STATUS_PTR))
#define astGetNextText(this) \
astINVOKE(V,astGetNextText_(astCheckChannel(this),STATUS_PTR))
#define astGetStrict(this) \
astINVOKE(V,astGetStrict_(astCheckChannel(this),STATUS_PTR))
#define astPutNextText(this,line) \
astINVOKE(V,astPutNextText_(astCheckChannel(this),line,STATUS_PTR))
#define astReadClassData(this,class) \
astINVOKE(V,astReadClassData_(astCheckChannel(this),class,STATUS_PTR))
#define astReadDouble(this,name,def) \
astINVOKE(V,astReadDouble_(astCheckChannel(this),name,def,STATUS_PTR))
#define astReadInt(this,name,def) \
astINVOKE(V,astReadInt_(astCheckChannel(this),name,def,STATUS_PTR))
#define astReadObject(this,name,def) \
astINVOKE(O,astReadObject_(astCheckChannel(this),name,(def)?astCheckObject(def):NULL,STATUS_PTR))
#define astReadString(this,name,def) \
astINVOKE(V,astReadString_(astCheckChannel(this),name,def,STATUS_PTR))
#define astSetComment(this,value) \
astINVOKE(V,astSetComment_(astCheckChannel(this),value,STATUS_PTR))
#define astSetFull(this,value) \
astINVOKE(V,astSetFull_(astCheckChannel(this),value,STATUS_PTR))
#define astSetStrict(this,value) \
astINVOKE(V,astSetStrict_(astCheckChannel(this),value,STATUS_PTR))
#define astTestComment(this) \
astINVOKE(V,astTestComment_(astCheckChannel(this),STATUS_PTR))
#define astTestFull(this) \
astINVOKE(V,astTestFull_(astCheckChannel(this),STATUS_PTR))
#define astTestStrict(this) \
astINVOKE(V,astTestStrict_(astCheckChannel(this),STATUS_PTR))
#define astWriteBegin(this,class,comment) \
astINVOKE(V,astWriteBegin_(astCheckChannel(this),class,comment,STATUS_PTR))
#define astWriteDouble(this,name,set,helpful,value,comment) \
astINVOKE(V,astWriteDouble_(astCheckChannel(this),name,set,helpful,value,comment,STATUS_PTR))
#define astWriteEnd(this,class) \
astINVOKE(V,astWriteEnd_(astCheckChannel(this),class,STATUS_PTR))
#define astWriteInt(this,name,set,helpful,value,comment) \
astINVOKE(V,astWriteInt_(astCheckChannel(this),name,set,helpful,value,comment,STATUS_PTR))
#define astWriteIsA(this,class,comment) \
astINVOKE(V,astWriteIsA_(astCheckChannel(this),class,comment,STATUS_PTR))
#define astWriteObject(this,name,set,helpful,value,comment) \
astINVOKE(V,astWriteObject_(astCheckChannel(this),name,set,helpful,astCheckObject(value),comment,STATUS_PTR))
#define astWriteString(this,name,set,helpful,value,comment) \
astINVOKE(V,astWriteString_(astCheckChannel(this),name,set,helpful,value,comment,STATUS_PTR))

#define astWriteInvocations astWriteInvocations_(STATUS_PTR)

#define astClearSkip(this) \
astINVOKE(V,astClearSkip_(astCheckChannel(this),STATUS_PTR))
#define astGetSkip(this) \
astINVOKE(V,astGetSkip_(astCheckChannel(this),STATUS_PTR))
#define astSetSkip(this,value) \
astINVOKE(V,astSetSkip_(astCheckChannel(this),value,STATUS_PTR))
#define astTestSkip(this) \
astINVOKE(V,astTestSkip_(astCheckChannel(this),STATUS_PTR))

#define astClearReportLevel(this) \
astINVOKE(V,astClearReportLevel_(astCheckChannel(this),STATUS_PTR))
#define astGetReportLevel(this) \
astINVOKE(V,astGetReportLevel_(astCheckChannel(this),STATUS_PTR))
#define astSetReportLevel(this,value) \
astINVOKE(V,astSetReportLevel_(astCheckChannel(this),value,STATUS_PTR))
#define astTestReportLevel(this) \
astINVOKE(V,astTestReportLevel_(astCheckChannel(this),STATUS_PTR))

#define astClearIndent(this) \
astINVOKE(V,astClearIndent_(astCheckChannel(this),STATUS_PTR))
#define astGetIndent(this) \
astINVOKE(V,astGetIndent_(astCheckChannel(this),STATUS_PTR))
#define astSetIndent(this,value) \
astINVOKE(V,astSetIndent_(astCheckChannel(this),value,STATUS_PTR))
#define astTestIndent(this) \
astINVOKE(V,astTestIndent_(astCheckChannel(this),STATUS_PTR))

#define astClearSourceFile(this) \
astINVOKE(V,astClearSourceFile_(astCheckChannel(this),STATUS_PTR))
#define astGetSourceFile(this) \
astINVOKE(V,astGetSourceFile_(astCheckChannel(this),STATUS_PTR))
#define astSetSourceFile(this,value) \
astINVOKE(V,astSetSourceFile_(astCheckChannel(this),value,STATUS_PTR))
#define astTestSourceFile(this) \
astINVOKE(V,astTestSourceFile_(astCheckChannel(this),STATUS_PTR))

#define astClearSinkFile(this) \
astINVOKE(V,astClearSinkFile_(astCheckChannel(this),STATUS_PTR))
#define astGetSinkFile(this) \
astINVOKE(V,astGetSinkFile_(astCheckChannel(this),STATUS_PTR))
#define astSetSinkFile(this,value) \
astINVOKE(V,astSetSinkFile_(astCheckChannel(this),value,STATUS_PTR))
#define astTestSinkFile(this) \
astINVOKE(V,astTestSinkFile_(astCheckChannel(this),STATUS_PTR))

#endif
#endif





