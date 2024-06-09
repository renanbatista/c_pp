#include "../include/FileReplacer.hpp"

FileReplacer::FileReplacer(const std::string& filename,
                           const std::string& s1,
                           const std::string& s2)
  : _filename(filename)
  , _s1(s1)
  , _s2(s2)
{
}

FileReplacer::~FileReplacer(void) {}

bool
FileReplacer::replaceInFile()
{
    std::string content;
    if (!readFile(content))
    {
        std::cerr << "Error: Could not read the file or the file is empty." << std::endl;
        return false;
    }
    replaceAll(content, _s1, _s2);
    if (!writeFile(content))
    {
        std::cerr << "Error: Could not write to the file." << std::endl;
        return false;
    }
    return true;
}

bool
FileReplacer::readFile(std::string& content)
{
    std::ifstream file(_filename.c_str());
    if (!file.is_open())
    {
        return false;
    }
    std::string line;
    while (std::getline(file, line))
    {
        content += line + '\n';
    }
    file.close();
    if (content.empty())
    {
        return false;
    }
    return true;
}

void
FileReplacer::replaceAll(std::string&       content,
                         const std::string& search,
                         const std::string& replace)
{
    size_t pos = 0;
    while ((pos = content.find(search, pos)) != std::string::npos)
    {
        content.erase(pos, search.length());
        content.insert(pos, replace);
        pos += replace.length();
    }
}

bool
FileReplacer::writeFile(const std::string& content)
{
    std::string   newFilename = _filename + ".replace";
    std::ofstream file(newFilename.c_str());
    if (!file.is_open())
    {
        return false;
    }
    file << content;
    file.close();
    return true;
}
