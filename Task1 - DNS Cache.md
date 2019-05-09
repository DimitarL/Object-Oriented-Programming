# Task 1 - DNS Cache

Operating systems and browsers use DNS Cache - a time table that records all last visited Websites and other Web domains. 
To model DNS Cache as follows:
- Create class structures DNSRecord, which has the following data elements:
  domainName-domain name (string);
  ipAddress-IP address of the domain (string).
  
- Create a DNSCache class that:
  Supports dynamic expanding array of DNS records
  Relevant constructors, destructor, and assignment operator;
  Method add to add a DNS record
  Method lookup, which by domain name returns the IP address of the domain if it is in the cache or NULL if it does not exist;
  Method flush - a cache clearing method;
  A print method that outputs all cache entries.
  
- Write a major class testing program.
