/*
 * Dibbler - a portable DHCPv6
 *
 * authors: Tomasz Mrugalski <thomson@klub.com.pl>
 *          Marek Senderski <msend@o2.pl>
 *
 * released under GNU GPL v2 only licence
 *
 * $Id: SrvTransMgr.h,v 1.12 2008-10-12 20:10:25 thomson Exp $
 *
 */

#ifndef SRVTRANSMGR_H
#define SRVTRANSMGR_H

#include <string>
#include <vector>
#include "SmartPtr.h"
#include "Container.h"
#include "Opt.h"
#include "SrvMsg.h"
#include "SrvIfaceMgr.h"
#include "SrvCfgIface.h"
#include "SrvAddrMgr.h"

#define SrvTransMgr() (TSrvTransMgr::instance())

class TSrvTransMgr
{
    friend ostream & operator<<(ostream &strum, TSrvTransMgr &x);
  public:
    static void instanceCreate(const std::string config);
    static TSrvTransMgr &instance();

    bool openSocket(SPtr<TSrvCfgIface> confIface);
    SPtr<TSrvMsg> getCurrentRequest();

    long getTimeout();
    void relayMsg(SPtr<TSrvMsg> msg);
    void doDuties();
    void dump();

    bool isDone();
    void shutdown();

    void removeExpired(std::vector<TSrvAddrMgr::TExpiredInfo>& addrLst,
                       std::vector<TSrvAddrMgr::TExpiredInfo>& tempAddrLst,
                       std::vector<TSrvAddrMgr::TExpiredInfo>& prefixLst);

    void notifyExpireInfo(TNotifyScriptParams& params, const TSrvAddrMgr::TExpiredInfo& exp,
                          TAddrIA::TIAType type);

    char * getCtrlAddr();
    int    getCtrlIface();

  private:
    TSrvTransMgr(string xmlFile);
    ~TSrvTransMgr();

    string XmlFile;
    List(TSrvMsg) MsgLst;
    bool IsDone;

    int ctrlIface;
    char ctrlAddr[48];

    SPtr<TSrvMsg> requestMsg; /// @todo: Remove this field and do the REQUEST handling properly

    static TSrvTransMgr * Instance;
};



#endif


