
so as to run the server in the directory on the terminal 


// BUILDING
 ```
./run

```

// RUNNING

 ```
 ./hello32
```


# C++ Example

```cpp
#include <iostream>
#include <string>
#include "Servers/HttpServer.hpp"
#include "Servers/Response.hpp"

int main()
{
    int port = 8080;
    std::cout << port << " is being used " << std::endl;

    BBWS::HttpServer testServer(port);
    auto request_callback = [](char request[])
    {
        std::string path = "./views/index.html";
        return BBWS::Response::htmlFile(path);
    };

    testServer.onRequestReceived(request_callback);
    testServer.launch();

    return 0;
}
```



# Benchmarking

```bash

 ab -n 10000 -c 1000   localhost:8080/

This is ApacheBench, Version 2.3 <$Revision: 1879490 $>
Copyright 1996 Adam Twiss, Zeus Technology Ltd, http://www.zeustech.net/
Licensed to The Apache Software Foundation, http://www.apache.org/

Benchmarking localhost (be patient)


Server Software:        
Server Hostname:        localhost
Server Port:            8080

Document Path:          /
Document Length:        0 bytes

Concurrency Level:      1000
Time taken for tests:   1.760 seconds
Complete requests:      10000
Failed requests:        0
Total transferred:      100000 bytes
HTML transferred:       0 bytes
Requests per second:    5681.30 [#/sec] (mean)
Time per request:       176.016 [ms] (mean)
Time per request:       0.176 [ms] (mean, across all concurrent requests)
Transfer rate:          55.48 [Kbytes/sec] received

Connection Times (ms)
              min  mean[+/-sd] median   max
Connect:        0    0   0.1      0       4
Processing:     0    0   3.8      0     377
Waiting:        0    0   0.1      0       3
Total:          0    0   3.8      0     377

Percentage of the requests served within a certain time (ms)
  50%      0
  66%      0
  75%      0
  80%      0
  90%      0
  95%      0
  98%      0
  99%      1
 100%    377 (longest request)

```




