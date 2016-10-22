#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
using namespace std;

/**
Rule File Maybe Like This:

name Dick
pack unit
{
int hp;
int att;
int speed;
}
pack player
{
unit data;
string name;
}

C++ Header Maybe Like This:

namespace Dick
{

struct unit
{
    int hp;
    int att;
    int speed;
};
int parseFromString(string inc,unit* out)
{
    memcpy(&out->hp,inc.c_str(),sizeof(out->hp));
    memcpy(&out->att,inc.c_str()+4,sizeof(out->att));

    return 0;
}
string toString(unit inc)
{

}
struct player
{
    struct unit data;
    string name;
};
int parseFromString(string inc,player* out)
{

}

}/// End of namespace Dick

*/

int Compile(const char* FileName,const char* OutFile)
{
    FILE* fin=fopen(FileName,"r");
    if(!fin) return -1;

    char tbuffer[1024];
    memset(tbuffer,0,1024);
    string text;
    while(fgets(tbuffer,1024,fp)!=NULL)
    {
        int sz=strlen(tbuffer);
        if(tbuffer[sz-1]=='\n') tbuffer[sz-1]=0;
        text+=tbuffer;
        memset(tbuffer,0,1024);
    }
    fclose(fin);

    char* ptext=(char*)text.c_str();

    string packname;
    {
        char* p=strstr(ptext,"name ");
        if(p==NULL) return -2;/// Error while parse name.
        char* q=strstr(p,";");

    }

    return 0;
}

int main()
{
    printf("%d\n",sizeof(string));
}
