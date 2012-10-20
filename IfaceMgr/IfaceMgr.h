/*
 * Dibbler - a portable DHCPv6
 *
 * authors: Tomasz Mrugalski <thomson@klub.com.pl>
 *          Marek Senderski <msend@o2.pl>
 *
 * released under GNU GPL v2 only licence
 *
 */

class TIfaceMgr;
#ifndef IFACEMGR_H
#define IFACEMGR_H

#include "SmartPtr.h"
#include "Container.h"
#include "ScriptParams.h"

#include "Iface.h"

class TMsg;
class TOpt;

class TIfaceMgr {
  public:
    friend ostream & operator <<(ostream & strum, TIfaceMgr &x);

    TIfaceMgr(string xmlFile, bool getIfaces);

    // ---Iface related---
    void firstIface();
    SPtr<TIfaceIface> getIface();
    SPtr<TIfaceIface> getIfaceByName(string name);
    SPtr<TIfaceIface> getIfaceByID(int id);
    SPtr<TIfaceIface> getIfaceBySocket(int fd);
    int countIface();

    // ---other---
    int select(unsigned long time, char *buf, int &bufsize, SPtr<TIPv6Addr> peer);
    string printMac(char * mac, int macLen);
    void dump();
    bool isDone();

    void notifyScripts(std::string scriptName, SPtr<TMsg> question, SPtr<TMsg> answer);
    void notifyScripts(std::string scriptName, SPtr<TMsg> question, SPtr<TMsg> answer,
                       TNotifyScriptParams& params);
    void notifyScript(std::string scriptName, std::string action, TNotifyScriptParams& params);

    virtual ~TIfaceMgr();

 protected:
    virtual void optionToEnv(TNotifyScriptParams& params, SPtr<TOpt> opt, std::string txtPrefix );

    string XmlFile;
    List(TIfaceIface) IfaceLst; //Interface list
    bool IsDone; 
};

#endif
