#pragma once

#include <iostream>
#include <string>
#include <sstream>

namespace BBWS
{
    class Response
    {
    public:
        static std::string text(std::string &content, int statusCode = 200);
        static std::string html(std::string &content, int statusCode = 200);
    };
}