#include <MicroXML/utils.hpp>

bool found(size_t pos)
{
    return pos != std::string::npos;
}

size_t findFirst(const std::string& str, char c, size_t start)
{
    size_t strSize = str.size();
    for (size_t i(start); i<strSize; ++i)
    {
        if (str[i] == c) return i;
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
                //if (c != '\n' && c != '\r' && c != '\t')
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
    StrVec      params  = splitQuote(str, ' ');
    std::string tagName = params[0];

    size_t paramsSize = params.size();
    for (size_t i(1); i<paramsSize; ++i)
    {
        const std::string& param(params[i]);
        size_t equalPos = param.find('=');
        std::string paramName = param.substr(0, equalPos);
        std::string paramData = param.substr(equalPos+1);
        tag._params[paramName] = paramData;
    }

    if (tagName.front() == XML_SLASH)
    {
        tag._type = CLOSE;
        tagName  = tagName.substr(1);
    }
    else if (str.back() == XML_SLASH)
    {
        tag._type = AUTO_CLOSED;
    }
    else if (tagName.compare(XML_DOCUMENT_HEADER) == 0)
    {
        tag._type = SPECIAL;
    }
    else if (tagName.compare(XML_COMMENT_START) == 0)
    {
        tag._type = COMMENTED;
    }
    else
        tag._type = OPEN;

    tag._name = tagName;
}

Tag getNextTag(std::string& str, size_t start)
{
    Tag tag;

    size_t pos1 = findFirst(str, XML_TAG_START, start);
    size_t pos2 = findFirst(str, XML_TAG_END  , pos1);
    if (found(pos1) && found(pos2))
    {
        size_t length = pos2-pos1-1;
        std::string tag_declaration = str.substr(pos1+1, length);

        parseDeclaration(tag_declaration, tag);

        if (tag._type == CLOSE)
        {
            tag._data = str.substr(start, pos1-start);
        }
        else if (tag._type == COMMENTED)
        {
            pos2 = str.find(XML_COMMENT_END)+2;
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

int strToInt(const std::string& str)
{
    int result = 0;

    for (const char& c : str)
    {
        if (c >= '0' && c <= '9')
            result = result*10 + (c-'0');
        else
            break;
    }

    return result;
}

double strToDouble(const std::string& str)
{
    double div = 1.0;
    double result = 0.0;

    for (const char& c : str)
    {
        if (c >= '0' && c <= '9')
        {
            result = result*10 + (c-'0');
            div *= div>1 ? 10 : 1;
        }
        else if (c == '.' && div == 1)
            div = 10.0;
        else
            break;
    }

    return 10.0*result/div;
}
