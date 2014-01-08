#ifndef CODE_H
#define CODE_H

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>

class Code {
public:
    Code(std::string FileName);
    char GiveCh();
    char ShowCh();
    int getStrNum();
    bool IsEnd();
private:
    std::string text;
    std::vector<char> buf;
    int vectLen;
    int ChNum;
    int Num;
    int StrNum;
};

#endif // CODE_H
