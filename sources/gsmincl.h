//
// FILE: gsmincl.h   header file for GSM components
//
// @(#)gsmincl.h	2.5 19 Jul 1997
//



#ifndef GSMINCL_H
#define GSMINCL_H

#include "gstring.h"
#include "gmisc.h"

class gString;
class gOutput;

typedef enum
{ 
  opERROR,

  opNEG,
  opADD, opSUB, opMUL, opDIV, 
  opINTDIV, opMOD,

  opEXP, opLOG,
  opPOW_INT, opPOW_FLOAT,

  opEQU, opNEQ, opGTN, opLTN, opGEQ, opLEQ,

  opAND, opOR, opNOT,

  opSUBSCRIPT,

  opINTEGER, opFLOAT, opRATIONAL
} OperationMode;



#define rcFAIL     0
#define rcSUCCESS -1
#define rcQUIT    -2


#define  porNULLSPEC  true



#define  porERROR              ( 0x00000000 )
#define  porBOOL               ( 0x00000001 )
#define  porPRECISION          ( 0x00000002 )
#define  porINTEGER            ( 0x00000004 )
#define  porNUMBER             ( 0x00000008 )
#define  porTEXT               ( 0x00000010 )

#define  porNFOUTCOME          ( 0x00000020 )

#define  porNFG                ( 0x00000040 )
#define  porEFG                ( 0x00000100 )
#define  porMIXED_FLOAT        ( 0x00000400 )
#define  porMIXED_RATIONAL     ( 0x00000800 )
#define  porMIXED              ( porMIXED_FLOAT | porMIXED_RATIONAL )
#define  porBEHAV_FLOAT        ( 0x00001000 )
#define  porBEHAV_RATIONAL     ( 0x00002000 )
#define  porBEHAV              ( porBEHAV_FLOAT | porBEHAV_RATIONAL )

#define  porEFOUTCOME          ( 0x00004000 )

#define  porINFOSET            ( 0x00010000 )

#define  porNFSUPPORT          ( 0x00040000 )

#define  porEFSUPPORT          ( 0x00100000 )

#define  porNFPLAYER           ( 0x00400000 )
#define  porEFPLAYER           ( 0x00800000 )
#define  porNODE               ( 0x01000000 )
#define  porACTION             ( 0x02000000 )
#define  porREFERENCE          ( 0x04000000 )
#define  porOUTPUT             ( 0x08000000 )
#define  porINPUT              ( 0x10000000 )
#define  porSTRATEGY           ( 0x20000000 )

#define  porNULL               ( 0x40000000 )
#define  porUNDEFINED          ( 0x80000000 )

#define  porANYTYPE            ( 0xFFFFFFFF )

#define  NLIST 32767


class PortionSpec
{
public:
  unsigned long Type;
  unsigned short ListDepth;
  bool Null;

  PortionSpec(const PortionSpec& spec)
    : Type(spec.Type), ListDepth(spec.ListDepth), Null(spec.Null)
    {}
  PortionSpec(unsigned long type = porERROR,
	      signed short listdepth = 0,
	      bool null = false )
    : Type(type), ListDepth(listdepth), Null(null)
    {}
  ~PortionSpec()
  {}

  bool operator==(const PortionSpec& spec) const
  {
    return (Type==spec.Type &&
	    ListDepth==spec.ListDepth &&
	    Null==spec.Null);
  }
};


bool PortionSpecMatch( const PortionSpec& t1, const PortionSpec& t2 );


gString PortionSpecToText( const PortionSpec& type );
PortionSpec TextToPortionSpec( const gString& text );
void PrintPortionSpec( gOutput& s, PortionSpec type );
gOutput& operator << ( gOutput& s, PortionSpec spec );

#endif // GSMINCL_H

