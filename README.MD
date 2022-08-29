
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

int main()
{
    int port = 8080;
    std::cout << port << " is being used " << std::endl;
    BBWS::HttpServer testServer(port);
    
    auto request_callback = [](char request[])
    {
                                    std::cout << request << std::endl;
                                     std::string hello_message = "hello worl";
                                     return hello_message; };

//  // it is triggered whenever we receive request from client
    testServer.onRequestReceived(request_callback); 
    testServer.launch();

    return 0;
}
```