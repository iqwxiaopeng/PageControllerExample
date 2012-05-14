/*
	This file is a part of madfish-webtoolkit project.
	http://code.google.com/p/madfish-webtoolkit/

	(c) 2009 Alexander "Mad Fish" Chehovsky
	See License.txt for licensing information.
*/

//#pragma once
#ifndef _SOCKET_H
#define	_SOCKET_H

#include "Stream.h"

#include <string>
#include <memory.h>
#include <sstream>

#ifdef WIN32
#include <Ws2tcpip.h>
#else
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <signal.h>
#include<unistd.h>
#endif

namespace CoreToolkit
{

class BaseSocket
{
protected:
	int sock;
public:
	std::string remoteIP;
	int remotePort;
    BaseSocket():sock(-1){}
	BaseSocket(int socket);
    virtual ~BaseSocket();
    virtual bool Wait(int timeout);
};

class Socket:public BaseSocket,public InputStream,public OutputStream
{
public:
	Socket(int sock);
    Socket(const std::string& host, int portNumber)
    {
        sock=socket(PF_INET,SOCK_STREAM,IPPROTO_TCP);
        if(sock<0)
            throw IOException("Failed to create socket");
        addrinfo *res,*resIter;
        std::ostringstream os;
        os<<portNumber;
        if(getaddrinfo(host.c_str(),os.str().c_str(),NULL,&res)!=0)
            throw IOException("Failed to resolve hostname");
        for(resIter=res;resIter!=NULL;resIter=resIter->ai_next)
        {
            if(connect(sock,resIter->ai_addr,resIter->ai_addrlen)!=0)
                continue;
            else
                break;
        }
        if(resIter==NULL)
            throw IOException("Failed to connect");
    }
	~Socket();
	int ReadSomeUnbuffered(void* buf,int len);
	bool WaitUnbuffered(int timeout);
	int WriteSome(const void* buf,int len);
	using InputStream::Wait;
};

class Listener:public BaseSocket
{
public:
    Listener(int portNumber,const std::string& ip)
    {
        sock=socket(PF_INET,SOCK_STREAM,IPPROTO_TCP);
        if(sock<0)
            throw IOException("Failed to create socket");
        int val=1;
        setsockopt(sock,SOL_SOCKET,SO_REUSEADDR,reinterpret_cast<const char*>(&val),sizeof(val));
        sockaddr_in stSockAddr;
        memset(&stSockAddr,0,sizeof (stSockAddr));
        stSockAddr.sin_family=AF_INET;
        stSockAddr.sin_port=htons(portNumber);
        stSockAddr.sin_addr.s_addr=inet_addr(ip.c_str());
        if(bind(sock,(const sockaddr*)&stSockAddr,sizeof (stSockAddr))<0)
            throw IOException("Failed to bind socket");
        if(listen(sock,100)<0)
            throw IOException("Failed to start listening");
    }

    virtual ~Listener(){}
    virtual Socket* Accept();
};

}

#endif

