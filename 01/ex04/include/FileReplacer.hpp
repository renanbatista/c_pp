#ifndef FILEREPLACER_HPP
#define FILEREPLACER_HPP

#include <fstream>
#include <iostream>
#include <string>

class FileReplacer
{
  public:
    FileReplacer(const std::string& filename, const std::string& s1, const std::string& s2);
    ~FileReplacer(void);
    bool replaceInFile();

  private:
    std::string _filename;
    std::string _s1;
    std::string _s2;

    bool readFile(std::string& content);
    void replaceAll(std::string& content, const std::string& search, const std::string& replace);
    bool writeFile(const std::string& content);
};

#endif
