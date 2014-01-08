#include "code.h"

Code::Code(std::string FileName){
    std::ifstream file(FileName.c_str(), std::ifstream::in);
    if(!file){
        std::cout<<"Error opening file";
        exit(1);
    }
    file.seekg(0,std::ios::end);
    std::streampos length = file.tellg();
    file.seekg(0,std::ios::beg);
    vectLen=length;
    buf.reserve(length);
    file.read(&buf[0],length);
    ChNum=Num=StrNum=0;
}

char Code::GiveCh(){
    if(StrNum!=Num)
        StrNum=Num;
    if(buf[ChNum]=='\n')
        Num++;
    return buf[ChNum++];
}

char Code::ShowCh(){
    return buf[ChNum];
}

bool Code::IsEnd(){
    if(ChNum==vectLen)
        return true;
    else return false;
}
int Code::getStrNum(){
	return StrNum + 1;
}

