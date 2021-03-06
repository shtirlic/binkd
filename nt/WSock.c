/*--------------------------------------------------------------------*/
/*       W S o c k . c                                                */
/*                                                                    */
/*       Part of BinkD project                                        */
/*       WinSock Initialisation/Deinitialisation module               */
/*--------------------------------------------------------------------*/

/*--------------------------------------------------------------------*/
/*       Copyright (c) 1996 by Fydodor Ustinov                        */
/*                             FIDONet 2:5020/79                      */
/*                                                                    */
/*  This program is  free software;  you can  redistribute it and/or  */
/*  modify it  under  the terms of the GNU General Public License as  */ 
/*  published  by the  Free Software Foundation; either version 2 of  */
/*  the License, or (at your option) any later version. See COPYING.  */
/*--------------------------------------------------------------------*/

/*--------------------------------------------------------------------*/
/*                        System include files                        */
/*--------------------------------------------------------------------*/

/*--------------------------------------------------------------------*/
/*                        Local include files                         */
/*--------------------------------------------------------------------*/

#include "../sys.h"
#include "../iphdr.h"
#include "../readcfg.h"
#include "../tools.h"

/*--------------------------------------------------------------------*/
/*                         Global definitions                         */
/*--------------------------------------------------------------------*/

/*--------------------------------------------------------------------*/
/*                          Global variables                          */
/*--------------------------------------------------------------------*/

/*--------------------------------------------------------------------*/
/*                           Local variables                          */
/*--------------------------------------------------------------------*/

/*--------------------------------------------------------------------*/
/*                    Local functions prototypes                      */
/*--------------------------------------------------------------------*/

/*--------------------------------------------------------------------*/
/*    int WinsockIni(void)                                            */
/*                                                                    */
/*    Initialise Winsock.                                             */
/*--------------------------------------------------------------------*/

int WinsockIni(void) {
    WORD wVersionRequested;
    WSADATA wsaData;
    int Err;

    wVersionRequested = MAKEWORD( 1, 1 );

    Err = WSAStartup(wVersionRequested, &wsaData);
    if (Err != 0) {
       Log (0, "Cannot initialise WinSock");
       return (-1);
    }
    /*----------------------------------------------------------------*/
    /* than 1.1 in addition to 1.1, it will still return 1.1 in       */
    /* wVersion since that is the version we requested                */
    /*----------------------------------------------------------------*/

    if (LOBYTE(wsaData.wVersion) != 1 || HIBYTE(wsaData.wVersion) != 1) {
       Log (0, "WinSock %d.%d detected. Required version 1.1",LOBYTE(wsaData.wVersion), HIBYTE(wsaData.wVersion));
       WSACleanup( );
       return (-1);
    }
    return 0;
}

/*--------------------------------------------------------------------*/
/*    int WinsockClean(void)                                          */
/*                                                                    */
/*    Initialise Winsock.                                             */
/*--------------------------------------------------------------------*/

int WinsockClean(void) {
    WSACleanup();
    return 0;
}
