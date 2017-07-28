#include "utils.hpp"

bool found(size_t pos)
{
    return pos != std::string::npos;
}

size_t findFirst(const std::string& str, char c, size_t start)
{
    size_t strSize = str.size();
    for (size_t i(start); i<strSize; ++i)
    {
        if (str[i] == c)
            return i;
    }

    return std::string::npos;
}

std::string purge(std::string& str)
{
    std::string result = "";

    bool quoted = false;
    for (const char& c : str)
    {
        if (c == '"')
            quoted = !quoted;
        else
        {
            if (!quoted)
            {
                if (c != '\n' && c != '\r' && c != '\t')
                    result += c;
            }
            else
                result += c;
        }
    }

    return result;
}

void parseDeclaration(const std::string& str, Tag& tag)
{
    std::vector<std::string> params = splitQuote(str, ' ');
    std::string tag_name = params[0];

    size_t paramsSize = params.size();
    for (size_t i(1); i<paramsSize; ++i)
    {
        const std::string& param(params[i]);
        size_t equalPos = param.find('=');
        std::string paramName = param.substr(0, equalPos);
        std::string paramData = param.substr(equalPos+1);
        tag._params[paramName] = paramData;
    }

    if (tag_name[0] == '/')
    {
        tag._type = CLOSE;
        tag_name  = tag_name.substr(1);
    }
    else if (tag_name.back() == '/')
    {
        tag._type = AUTO_CLOSED;
        tag_name  = tag_name.substr(0, str.size()-1);
    }
    else
        tag._type = OPEN;

    tag._name = tag_name;
}

Tag getNextTag(std::string& str, size_t start)
{
    Tag tag;

    size_t pos1 = findFirst(str, '<', start);
    size_t pos2 = findFirst(str, '>', pos1);
    if (found(pos1) && found(pos2))
    {
        size_t length = pos2-pos1-1;
        std::string tag_declaration = str.substr(pos1+1, length);

        parseDeclaration(tag_declaration, tag);

        if (tag._type == CLOSE)
        {
            tag._data = str.substr(start, pos1-start);
        }

        tag._isValid = true;
        tag._pos     = pos2;
    }
    else
        tag._isValid = false;

    return tag;
}

std::vector<std::string> split(const std::string& str, std::string sep)
{
    std::vector<std::string> result;

    std::string strcp(str);

    size_t sepPos = strcp.find(sep);
    while (sepPos != std::string::npos)
    {
        std::string cut = strcp.substr(0, sepPos);
        if (!cut.empty())
        {
            result.push_back(cut);
        }

        strcp = strcp.substr(sepPos+sep.size());
        sepPos = strcp.find(sep);
    }

    if (!strcp.empty())
        result.push_back(strcp);

    return result;
}

std::vector<std::string> splitQuote(const std::string& str, char sep)
{
    std::vector<std::string> result;

    std::string strcp(str+' ');

    bool   inQuote = false;
    size_t lastCut = -1;
    size_t strLength = strcp.size();
    for (size_t i(0); i<strLength; ++i)
    {
        if (strcp[i] == sep && !inQuote)
        {
            if (i - lastCut > 1)
            {
                result.push_back(strcp.substr(lastCut+1, i-lastCut-1));
            }
            lastCut = i;
        }
        else if (strcp[i] == '"')
        {
            inQuote = !inQuote;
        }
    }

    return result;
}
