#pragma once
#include<iostream>
#include "DNSRecord.h"
using namespace std;

class DNSCache//: public DNSRecord
{
private:
	DNSRecord* arr;//ukazateli, a kato sa ukazateli e ->
	int size;
	int capacity;

	void resize();
	void copyFrom(const DNSCache &rhs);
	void clear();
public:
	DNSCache();
	DNSCache(const DNSCache&);
	DNSCache& operator=(const DNSCache&);
	~DNSCache();

	void add(const DNSRecord&);
	char *lookup(char* name) const;
	void flush();
	void print() const;
};

