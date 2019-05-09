#pragma once
#include<iostream>
#include "DNSCache.h"
using namespace std;

DNSCache::DNSCache() : capacity(0), size(0), arr(nullptr)
{
}

DNSCache::DNSCache(const DNSCache & rhs)
{
	copyFrom(rhs);
}

DNSCache & DNSCache::operator=(const DNSCache & rhs)
{
	if (this != &rhs)
	{
		clear();
		copyFrom(rhs);
	}
	return *this;
}

void DNSCache::add(const DNSRecord& record)//& za da ne se napravi kopie
{
	if (size >= capacity)
	{
		capacity *= 2;
		if (capacity == 0) capacity = 2;
		resize();
	}
	arr[size++] = record;
}

char * DNSCache::lookup(char * name) const
{
	for (int i = 0; i < size; i++)
	{
		if (strcmp(arr[i].getDomainIP(), name) == 0)
			return arr[i].getIP();
	}
	return nullptr;
}



void DNSCache::resize()
{
	DNSRecord* newArr = new DNSRecord[capacity];
	for (int i = 0; i < size; i++)
	{
		newArr[i] = arr[i];
	}
	delete[] arr;
	arr = newArr;
}

void DNSCache::copyFrom(const DNSCache & rhs)
{
	size = rhs.size;
	capacity = rhs.capacity;
	arr = new DNSRecord[capacity];
	for (int i = 0; i < size; i++)
	{
		arr[i] = rhs.arr[i];
	}
}

void DNSCache::clear()
{
	delete[]arr;
	arr = nullptr;
	size = 0;
	capacity = 0;
}



void DNSCache::flush()
{
	clear();
}

void DNSCache::print() const
{
	for (int i = 0; i < size; i++)
	{
		cout << "Domain: " << arr[i].getDomainIP() << endl;
		cout << "IP address: " << arr[i].getIP() << endl;
	}
	cout << endl;
}

DNSCache::~DNSCache()
{
	clear();
}
