#pragma once
#include<iostream>
#include<cstring>
#include "DNSRecord.h"


void DNSRecord::copyFrom(const DNSRecord & rhs)
{
	setDomainName(rhs.domainName);
	setIP(rhs.ipAddress);
}

void DNSRecord::clear()
{
	delete[] ipAddress;
	delete[] domainName;
	ipAddress = nullptr;
	domainName = nullptr;
}

DNSRecord::DNSRecord() : domainName(nullptr), ipAddress(nullptr)
{
}

DNSRecord::DNSRecord(const DNSRecord & rhs)
{
	copyFrom(rhs);
}

DNSRecord & DNSRecord::operator=(const DNSRecord &rhs)
{
	if (this != &rhs)
	{
		clear();
		copyFrom(rhs);
	}

	return *this;
}

DNSRecord::~DNSRecord()
{
	clear();
}

void DNSRecord::setDomainName(const char * domainName)
{
	delete[]this->domainName;
	int len = strlen(domainName);
	this->domainName = new char[len + 1];
	strcpy_s(this->domainName, len + 1, domainName);
}

void DNSRecord::setIP(const char * ip)
{
	delete[]this->ipAddress;
	int len = strlen(ip);
	this->ipAddress = new char[len + 1];
	strcpy_s(this->ipAddress, len + 1, ip);
}

char * DNSRecord::getIP() const
{
	return ipAddress;
}

char * DNSRecord::getDomainIP() const
{
	return domainName;
}

std::istream & operator>>(std::istream & is, DNSRecord & rhs)
{
	char temp1[100], temp2[100];
	is >> temp1 >> temp2;
	
	delete[] rhs.domainName;
	int len = strlen(temp1);
	rhs.domainName = new char[len + 1];
	strcpy_s(rhs.domainName,len + 1, temp1);

	delete[] rhs.ipAddress;
	len = strlen(temp2);
	rhs.ipAddress = new char[len + 1];
	strcpy_s(rhs.ipAddress, len+1, temp2);
	
	return is;
}
