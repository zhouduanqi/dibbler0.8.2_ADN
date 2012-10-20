/*
 * Dibbler - a portable DHCPv6
 *
 * authors: Tomasz Mrugalski <thomson@klub.com.pl>
 *          Marek Senderski <msend@o2.pl>
 *
 * released under GNU GPL v2 only licence
 *
 * $Id: SrvOptFQDN.cpp,v 1.3 2008-08-29 00:07:36 thomson Exp $
 *
 * $Log: not supported by cvs2svn $
 * Revision 1.2  2006-03-03 20:49:54  thomson
 * FQDN support improved.
 *
 * Revision 1.1  2004/11/02 01:30:54  thomson
 * Initial version.
 *
 */

#include "SrvOptFQDN.h"

TSrvOptFQDN::TSrvOptFQDN(string fqdn, TMsg* parent)
    :TOptFQDN(fqdn, parent) {
	this->setNFlag(false);
}

TSrvOptFQDN::TSrvOptFQDN(char *buf, int bufsize, TMsg* parent)
    :TOptFQDN(buf, bufsize, parent) {

}

bool TSrvOptFQDN::doDuties() {
    return true;
}
