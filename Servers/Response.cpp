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
    fin.open(path.c_str());

    if (fin.fail())
    {
        std::cerr << "Error - Failed to open " << path << std::endl;
        exit(-1); // Or use a loop to ask for a different file name.
    }
    /*
    std::istreambuf_iterator<char>(fin) = makes an input stream iterator from an input stream
    You can access its elements going forward until you reach the end of the stream.
     Once you reach the end of stream, the iterator becomes equivalent to an iterator created using the default constructor:
     std::istreambuf_iterator<char>()
    */
    std::string content((std::istreambuf_iterator<char>(fin)), std::istreambuf_iterator<char>());

    fin.close();

    return html(content, statusCode);
}