#ifndef YY_ClntParser_h_included
#define YY_ClntParser_h_included
#define YY_USE_CLASS

#line 1 "../bison++/bison.h"
/* before anything */
#ifdef c_plusplus
 #ifndef __cplusplus
  #define __cplusplus
 #endif
#endif


 #line 8 "../bison++/bison.h"
#line 3 "ClntParser.y"

#include <iostream>
#include <string>
#include <malloc.h>
#include "DHCPConst.h"
#include "SmartPtr.h"
#include "Container.h"
#include "ClntParser.h"
#include "ClntParsGlobalOpt.h"
#include "ClntCfgIface.h"
#include "ClntCfgAddr.h"
#include "ClntCfgIA.h"
#include "ClntCfgTA.h"
#include "ClntCfgPD.h"
#include "ClntOptVendorSpec.h"
#include "ClntCfgMgr.h"
#include "Logger.h"
#include "OptGeneric.h"
#include "OptAddr.h"
#include "OptAddrLst.h"
#include "OptString.h"

using namespace std;

#define YY_USE_CLASS
#define YY_ClntParser_MEMBERS  yyFlexLexer * lex;                                          \
/*List of options in scope stack,the most fresh is last in the list*/       \
List(TClntParsGlobalOpt) ParserOptStack;			            \
/*List of parsed interfaces/IAs/Addresses, last */                          \
/*interface/IA/address is just being parsing or have been just parsed*/     \
List(TClntCfgIface) ClntCfgIfaceLst;	                                    \
List(TClntCfgIA)    ClntCfgIALst;		                            \
List(TClntCfgTA)    ClntCfgTALst;                                           \
List(TClntCfgPD)    ClntCfgPDLst;                                           \
List(TClntCfgAddr)  ClntCfgAddrLst;                                         \
List(DigestTypes)   DigestLst;                                              \
/*Pointer to list which should contain either rejected servers or */        \
/*preffered servers*/                                                       \
List(TStationID) PresentStationLst;		                            \
List(TIPv6Addr) PresentAddrLst;			                            \
List(TClntCfgPrefix) PrefixLst;                                             \
List(string) PresentStringLst;	                                            \
List(TOptVendorSpecInfo) VendorSpec;					    \
bool IfaceDefined(int ifaceNr);                                             \
bool IfaceDefined(string ifaceName);                                        \
bool StartIfaceDeclaration(string ifaceName);                               \
bool StartIfaceDeclaration(int ifindex);                                    \
bool EndIfaceDeclaration();                                                 \
void EmptyIface();                                                          \
void StartIADeclaration(bool aggregation);                                  \
void EndIADeclaration();                                                    \
void StartPDDeclaration();                                                  \
bool EndPDDeclaration();                                                    \
void EmptyIA();                                                             \
void EmptyAddr();                                                           \
TClntCfgMgr * CfgMgr;                                                       \
bool iaidSet;                                                               \
unsigned int iaid;                                                          \
virtual ~ClntParser();                                                      \
EDUIDType DUIDType;                                                         \
int DUIDEnterpriseNumber;                                                   \
SPtr<TDUID> DUIDEnterpriseID;
#define YY_ClntParser_CONSTRUCTOR_PARAM  yyFlexLexer * lex
#define YY_ClntParser_CONSTRUCTOR_CODE                                                     \
    this->lex = lex;                                                        \
    ParserOptStack.append(new TClntParsGlobalOpt());                        \
    ParserOptStack.getFirst()->setIAIDCnt(1);                               \
    ParserOptStack.getLast();                                               \
    DUIDType = DUID_TYPE_NOT_DEFINED;                                       \
    DUIDEnterpriseID = 0;

#line 83 "ClntParser.y"
typedef union
{
    int ival;
    char *strval;
    struct SDuid  {
	int length;
	char* duid;
    } duidval;
    char addrval[16];
} yy_ClntParser_stype;
#define YY_ClntParser_STYPE yy_ClntParser_stype

#line 21 "../bison++/bison.h"
 /* %{ and %header{ and %union, during decl */
#ifndef YY_ClntParser_COMPATIBILITY
 #ifndef YY_USE_CLASS
  #define  YY_ClntParser_COMPATIBILITY 1
 #else
  #define  YY_ClntParser_COMPATIBILITY 0
 #endif
#endif

#if YY_ClntParser_COMPATIBILITY != 0
/* backward compatibility */
 #ifdef YYLTYPE
  #ifndef YY_ClntParser_LTYPE
   #define YY_ClntParser_LTYPE YYLTYPE
/* WARNING obsolete !!! user defined YYLTYPE not reported into generated header */
/* use %define LTYPE */
  #endif
 #endif
/*#ifdef YYSTYPE*/
  #ifndef YY_ClntParser_STYPE
   #define YY_ClntParser_STYPE YYSTYPE
  /* WARNING obsolete !!! user defined YYSTYPE not reported into generated header */
   /* use %define STYPE */
  #endif
/*#endif*/
 #ifdef YYDEBUG
  #ifndef YY_ClntParser_DEBUG
   #define  YY_ClntParser_DEBUG YYDEBUG
   /* WARNING obsolete !!! user defined YYDEBUG not reported into generated header */
   /* use %define DEBUG */
  #endif
 #endif 
 /* use goto to be compatible */
 #ifndef YY_ClntParser_USE_GOTO
  #define YY_ClntParser_USE_GOTO 1
 #endif
#endif

/* use no goto to be clean in C++ */
#ifndef YY_ClntParser_USE_GOTO
 #define YY_ClntParser_USE_GOTO 0
#endif

#ifndef YY_ClntParser_PURE

 #line 65 "../bison++/bison.h"

#line 65 "../bison++/bison.h"
/* YY_ClntParser_PURE */
#endif


 #line 68 "../bison++/bison.h"

#line 68 "../bison++/bison.h"
/* prefix */

#ifndef YY_ClntParser_DEBUG

 #line 71 "../bison++/bison.h"
#define YY_ClntParser_DEBUG 1

#line 71 "../bison++/bison.h"
/* YY_ClntParser_DEBUG */
#endif

#ifndef YY_ClntParser_LSP_NEEDED

 #line 75 "../bison++/bison.h"

#line 75 "../bison++/bison.h"
 /* YY_ClntParser_LSP_NEEDED*/
#endif

/* DEFAULT LTYPE*/
#ifdef YY_ClntParser_LSP_NEEDED
 #ifndef YY_ClntParser_LTYPE
  #ifndef BISON_YYLTYPE_ISDECLARED
   #define BISON_YYLTYPE_ISDECLARED
typedef
  struct yyltype
    {
      int timestamp;
      int first_line;
      int first_column;
      int last_line;
      int last_column;
      char *text;
   }
  yyltype;
  #endif

  #define YY_ClntParser_LTYPE yyltype
 #endif
#endif

/* DEFAULT STYPE*/
#ifndef YY_ClntParser_STYPE
 #define YY_ClntParser_STYPE int
#endif

/* DEFAULT MISCELANEOUS */
#ifndef YY_ClntParser_PARSE
 #define YY_ClntParser_PARSE yyparse
#endif

#ifndef YY_ClntParser_LEX
 #define YY_ClntParser_LEX yylex
#endif

#ifndef YY_ClntParser_LVAL
 #define YY_ClntParser_LVAL yylval
#endif

#ifndef YY_ClntParser_LLOC
 #define YY_ClntParser_LLOC yylloc
#endif

#ifndef YY_ClntParser_CHAR
 #define YY_ClntParser_CHAR yychar
#endif

#ifndef YY_ClntParser_NERRS
 #define YY_ClntParser_NERRS yynerrs
#endif

#ifndef YY_ClntParser_DEBUG_FLAG
 #define YY_ClntParser_DEBUG_FLAG yydebug
#endif

#ifndef YY_ClntParser_ERROR
 #define YY_ClntParser_ERROR yyerror
#endif

#ifndef YY_ClntParser_PARSE_PARAM
 #ifndef __STDC__
  #ifndef __cplusplus
   #ifndef YY_USE_CLASS
    #define YY_ClntParser_PARSE_PARAM
    #ifndef YY_ClntParser_PARSE_PARAM_DEF
     #define YY_ClntParser_PARSE_PARAM_DEF
    #endif
   #endif
  #endif
 #endif
 #ifndef YY_ClntParser_PARSE_PARAM
  #define YY_ClntParser_PARSE_PARAM void
 #endif
#endif

/* TOKEN C */
#ifndef YY_USE_CLASS

 #ifndef YY_ClntParser_PURE
  #ifndef yylval
   extern YY_ClntParser_STYPE YY_ClntParser_LVAL;
  #else
   #if yylval != YY_ClntParser_LVAL
    extern YY_ClntParser_STYPE YY_ClntParser_LVAL;
   #else
    #warning "Namespace conflict, disabling some functionality (bison++ only)"
   #endif
  #endif
 #endif


 #line 169 "../bison++/bison.h"
#define	T1_	258
#define	T2_	259
#define	PREF_TIME_	260
#define	DNS_SERVER_	261
#define	VALID_TIME_	262
#define	UNICAST_	263
#define	NTP_SERVER_	264
#define	DOMAIN_	265
#define	TIME_ZONE_	266
#define	SIP_SERVER_	267
#define	SIP_DOMAIN_	268
#define	NIS_SERVER_	269
#define	NISP_SERVER_	270
#define	NIS_DOMAIN_	271
#define	NISP_DOMAIN_	272
#define	FQDN_	273
#define	FQDN_S_	274
#define	DDNS_PROTOCOL_	275
#define	DDNS_TIMEOUT_	276
#define	LIFETIME_	277
#define	VENDOR_SPEC_	278
#define	IFACE_	279
#define	NO_CONFIG_	280
#define	REJECT_SERVERS_	281
#define	PREFERRED_SERVERS_	282
#define	IA_	283
#define	TA_	284
#define	IAID_	285
#define	ADDRESS_	286
#define	NAME_	287
#define	IPV6ADDR_	288
#define	WORKDIR_	289
#define	RAPID_COMMIT_	290
#define	OPTION_	291
#define	SCRIPT_	292
#define	LOGNAME_	293
#define	LOGLEVEL_	294
#define	LOGMODE_	295
#define	LOGCOLORS_	296
#define	STRING_	297
#define	HEXNUMBER_	298
#define	INTNUMBER_	299
#define	DUID_	300
#define	STRICT_RFC_NO_ROUTING_	301
#define	SKIP_CONFIRM_	302
#define	PD_	303
#define	PREFIX_	304
#define	DOWNLINK_PREFIX_IFACES_	305
#define	DUID_TYPE_	306
#define	DUID_TYPE_LLT_	307
#define	DUID_TYPE_LL_	308
#define	DUID_TYPE_EN_	309
#define	AUTH_ENABLED_	310
#define	AUTH_ACCEPT_METHODS_	311
#define	DIGEST_NONE_	312
#define	DIGEST_PLAIN_	313
#define	DIGEST_HMAC_MD5_	314
#define	DIGEST_HMAC_SHA1_	315
#define	DIGEST_HMAC_SHA224_	316
#define	DIGEST_HMAC_SHA256_	317
#define	DIGEST_HMAC_SHA384_	318
#define	DIGEST_HMAC_SHA512_	319
#define	STATELESS_	320
#define	ANON_INF_REQUEST_	321
#define	INSIST_MODE_	322
#define	INACTIVE_MODE_	323
#define	EXPERIMENTAL_	324
#define	ADDR_PARAMS_	325
#define	REMOTE_AUTOCONF_	326
#define	AFTR_	327
#define	ROUTING_	328
#define	ADDRESS_LIST_	329
#define	STRING_KEYWORD_	330
#define	REQUEST_	331
#define	RECONFIGURE_	332


#line 169 "../bison++/bison.h"
 /* #defines token */
/* after #define tokens, before const tokens S5*/
#else
 #ifndef YY_ClntParser_CLASS
  #define YY_ClntParser_CLASS ClntParser
 #endif

 #ifndef YY_ClntParser_INHERIT
  #define YY_ClntParser_INHERIT
 #endif

 #ifndef YY_ClntParser_MEMBERS
  #define YY_ClntParser_MEMBERS 
 #endif

 #ifndef YY_ClntParser_LEX_BODY
  #define YY_ClntParser_LEX_BODY  
 #endif

 #ifndef YY_ClntParser_ERROR_BODY
  #define YY_ClntParser_ERROR_BODY  
 #endif

 #ifndef YY_ClntParser_CONSTRUCTOR_PARAM
  #define YY_ClntParser_CONSTRUCTOR_PARAM
 #endif
 /* choose between enum and const */
 #ifndef YY_ClntParser_USE_CONST_TOKEN
  #define YY_ClntParser_USE_CONST_TOKEN 0
  /* yes enum is more compatible with flex,  */
  /* so by default we use it */ 
 #endif
 #if YY_ClntParser_USE_CONST_TOKEN != 0
  #ifndef YY_ClntParser_ENUM_TOKEN
   #define YY_ClntParser_ENUM_TOKEN yy_ClntParser_enum_token
  #endif
 #endif

class YY_ClntParser_CLASS YY_ClntParser_INHERIT
{
public: 
 #if YY_ClntParser_USE_CONST_TOKEN != 0
  /* static const int token ... */
  
 #line 212 "../bison++/bison.h"
static const int T1_;
static const int T2_;
static const int PREF_TIME_;
static const int DNS_SERVER_;
static const int VALID_TIME_;
static const int UNICAST_;
static const int NTP_SERVER_;
static const int DOMAIN_;
static const int TIME_ZONE_;
static const int SIP_SERVER_;
static const int SIP_DOMAIN_;
static const int NIS_SERVER_;
static const int NISP_SERVER_;
static const int NIS_DOMAIN_;
static const int NISP_DOMAIN_;
static const int FQDN_;
static const int FQDN_S_;
static const int DDNS_PROTOCOL_;
static const int DDNS_TIMEOUT_;
static const int LIFETIME_;
static const int VENDOR_SPEC_;
static const int IFACE_;
static const int NO_CONFIG_;
static const int REJECT_SERVERS_;
static const int PREFERRED_SERVERS_;
static const int IA_;
static const int TA_;
static const int IAID_;
static const int ADDRESS_;
static const int NAME_;
static const int IPV6ADDR_;
static const int WORKDIR_;
static const int RAPID_COMMIT_;
static const int OPTION_;
static const int SCRIPT_;
static const int LOGNAME_;
static const int LOGLEVEL_;
static const int LOGMODE_;
static const int LOGCOLORS_;
static const int STRING_;
static const int HEXNUMBER_;
static const int INTNUMBER_;
static const int DUID_;
static const int STRICT_RFC_NO_ROUTING_;
static const int SKIP_CONFIRM_;
static const int PD_;
static const int PREFIX_;
static const int DOWNLINK_PREFIX_IFACES_;
static const int DUID_TYPE_;
static const int DUID_TYPE_LLT_;
static const int DUID_TYPE_LL_;
static const int DUID_TYPE_EN_;
static const int AUTH_ENABLED_;
static const int AUTH_ACCEPT_METHODS_;
static const int DIGEST_NONE_;
static const int DIGEST_PLAIN_;
static const int DIGEST_HMAC_MD5_;
static const int DIGEST_HMAC_SHA1_;
static const int DIGEST_HMAC_SHA224_;
static const int DIGEST_HMAC_SHA256_;
static const int DIGEST_HMAC_SHA384_;
static const int DIGEST_HMAC_SHA512_;
static const int STATELESS_;
static const int ANON_INF_REQUEST_;
static const int INSIST_MODE_;
static const int INACTIVE_MODE_;
static const int EXPERIMENTAL_;
static const int ADDR_PARAMS_;
static const int REMOTE_AUTOCONF_;
static const int AFTR_;
static const int ROUTING_;
static const int ADDRESS_LIST_;
static const int STRING_KEYWORD_;
static const int REQUEST_;
static const int RECONFIGURE_;


#line 212 "../bison++/bison.h"
 /* decl const */
 #else
  enum YY_ClntParser_ENUM_TOKEN { YY_ClntParser_NULL_TOKEN=0
  
 #line 215 "../bison++/bison.h"
	,T1_=258
	,T2_=259
	,PREF_TIME_=260
	,DNS_SERVER_=261
	,VALID_TIME_=262
	,UNICAST_=263
	,NTP_SERVER_=264
	,DOMAIN_=265
	,TIME_ZONE_=266
	,SIP_SERVER_=267
	,SIP_DOMAIN_=268
	,NIS_SERVER_=269
	,NISP_SERVER_=270
	,NIS_DOMAIN_=271
	,NISP_DOMAIN_=272
	,FQDN_=273
	,FQDN_S_=274
	,DDNS_PROTOCOL_=275
	,DDNS_TIMEOUT_=276
	,LIFETIME_=277
	,VENDOR_SPEC_=278
	,IFACE_=279
	,NO_CONFIG_=280
	,REJECT_SERVERS_=281
	,PREFERRED_SERVERS_=282
	,IA_=283
	,TA_=284
	,IAID_=285
	,ADDRESS_=286
	,NAME_=287
	,IPV6ADDR_=288
	,WORKDIR_=289
	,RAPID_COMMIT_=290
	,OPTION_=291
	,SCRIPT_=292
	,LOGNAME_=293
	,LOGLEVEL_=294
	,LOGMODE_=295
	,LOGCOLORS_=296
	,STRING_=297
	,HEXNUMBER_=298
	,INTNUMBER_=299
	,DUID_=300
	,STRICT_RFC_NO_ROUTING_=301
	,SKIP_CONFIRM_=302
	,PD_=303
	,PREFIX_=304
	,DOWNLINK_PREFIX_IFACES_=305
	,DUID_TYPE_=306
	,DUID_TYPE_LLT_=307
	,DUID_TYPE_LL_=308
	,DUID_TYPE_EN_=309
	,AUTH_ENABLED_=310
	,AUTH_ACCEPT_METHODS_=311
	,DIGEST_NONE_=312
	,DIGEST_PLAIN_=313
	,DIGEST_HMAC_MD5_=314
	,DIGEST_HMAC_SHA1_=315
	,DIGEST_HMAC_SHA224_=316
	,DIGEST_HMAC_SHA256_=317
	,DIGEST_HMAC_SHA384_=318
	,DIGEST_HMAC_SHA512_=319
	,STATELESS_=320
	,ANON_INF_REQUEST_=321
	,INSIST_MODE_=322
	,INACTIVE_MODE_=323
	,EXPERIMENTAL_=324
	,ADDR_PARAMS_=325
	,REMOTE_AUTOCONF_=326
	,AFTR_=327
	,ROUTING_=328
	,ADDRESS_LIST_=329
	,STRING_KEYWORD_=330
	,REQUEST_=331
	,RECONFIGURE_=332


#line 215 "../bison++/bison.h"
 /* enum token */
     }; /* end of enum declaration */
 #endif
public:
 int YY_ClntParser_PARSE(YY_ClntParser_PARSE_PARAM);
 virtual void YY_ClntParser_ERROR(char *msg) YY_ClntParser_ERROR_BODY;
 #ifdef YY_ClntParser_PURE
  #ifdef YY_ClntParser_LSP_NEEDED
   virtual int  YY_ClntParser_LEX(YY_ClntParser_STYPE *YY_ClntParser_LVAL,YY_ClntParser_LTYPE *YY_ClntParser_LLOC) YY_ClntParser_LEX_BODY;
  #else
   virtual int  YY_ClntParser_LEX(YY_ClntParser_STYPE *YY_ClntParser_LVAL) YY_ClntParser_LEX_BODY;
  #endif
 #else
  virtual int YY_ClntParser_LEX() YY_ClntParser_LEX_BODY;
  YY_ClntParser_STYPE YY_ClntParser_LVAL;
  #ifdef YY_ClntParser_LSP_NEEDED
   YY_ClntParser_LTYPE YY_ClntParser_LLOC;
  #endif
  int YY_ClntParser_NERRS;
  int YY_ClntParser_CHAR;
 #endif
 #if YY_ClntParser_DEBUG != 0
  public:
   int YY_ClntParser_DEBUG_FLAG;	/*  nonzero means print parse trace	*/
 #endif
public:
 YY_ClntParser_CLASS(YY_ClntParser_CONSTRUCTOR_PARAM);
public:
 YY_ClntParser_MEMBERS 
};
/* other declare folow */
#endif


#if YY_ClntParser_COMPATIBILITY != 0
 /* backward compatibility */
 /* Removed due to bison problems
 /#ifndef YYSTYPE
 / #define YYSTYPE YY_ClntParser_STYPE
 /#endif*/

 #ifndef YYLTYPE
  #define YYLTYPE YY_ClntParser_LTYPE
 #endif
 #ifndef YYDEBUG
  #ifdef YY_ClntParser_DEBUG 
   #define YYDEBUG YY_ClntParser_DEBUG
  #endif
 #endif

#endif
/* END */

 #line 267 "../bison++/bison.h"
#endif
