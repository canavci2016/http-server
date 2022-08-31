#include "Response.hpp"

std::string BBWS::Response::text(std::string &content, int statusCode)
{
    std::ostringstream oss;
    oss << "HTTP/1.1 " << statusCode << " OK\r\n";
    oss << "Cache-Control: no-cache, private\r\n";
    oss << "Content-Type: text/plain\r\n";
    oss << "Content-Length: " << content.size() << "\r\n";
    oss << "\r\n";
    oss << content;
    return oss.str();
}

std::string BBWS::Response::html(std::string &content, int statusCode)
{
    std::ostringstream oss;
    oss << "HTTP/1.1 " << statusCode << " OK\r\n";
    oss << "Cache-Control: no-cache, private\r\n";
    oss << "Content-Type: text/html\r\n";
    oss << "Content-Length: " << content.size() << "\r\n";
    oss << "\r\n";
    oss << content;
    return oss.str();
}

std::string BBWS::Response::htmlFile(std::string &path, int statusCode)
{
    std::ifstream fin;
    std::string content;
    std::string line;

    fin.open(path.c_str());

    if (fin.fail())
    {
        std::cerr << "Error - Failed to open " << path << std::endl;
        exit(-1); // Or use a loop to ask for a different file name.
    }

    while (fin >> line)
    {
        content.append(line);
    };

    fin.close();

    return html(content, statusCode);
}