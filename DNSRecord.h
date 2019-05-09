#pragma once
#include<iostream>
using namespace std;

class DNSRecord
{
private:
	char* domainName;
	char* ipAddress;

	void copyFrom(const DNSRecord &rhs);
	void clear();
public:
	DNSRecord();
	DNSRecord(const DNSRecord &rhs);
	DNSRecord& operator=(const DNSRecord &rhs);
	~DNSRecord();

	void setDomainName(const char *domainName);
	void setIP(const char *ip);

	char *getIP() const;
	char *getDomainIP() const;

	friend std::istream& operator>> (istream& is, DNSRecord&);
};