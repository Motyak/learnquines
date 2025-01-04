#include <iostream>

std::string replace_all(const std::string& str, const std::string& from, const std::string& to)
{
    std::string _str = str; // working variable, needs to be mutable for ::replace() to work

    size_t start_pos = 0;
    while ((start_pos = _str.find(from, start_pos)) != std::string::npos)
    {
        _str.replace(start_pos, from.length(), to);
        start_pos += to.length(); // Handles case where 'to' is a substring of 'from'
    }
    return _str;
}

#define escape_antislashes(str) \
    replace_all(str, std::string(1, '\\'), "\\\\")

#define escape_newlines(str) \
    replace_all(str, std::string(1, '\n'), "\\n")

#define escape_double_quotes(str) \
    replace_all(str, std::string(1, '"'), "\\\"")

std::string quote(const std::string& str) {
    return "\"" +
    escape_newlines(
        escape_double_quotes(
            escape_antislashes(str)
        )
    )
    + "\"";
}

#define _QUOTE(x) #x
#define QUOTE(x) _QUOTE(x)
