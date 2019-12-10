#include <iostream>
#include <cstring>

int main(int argc, char** argv)
{
    if (argc != 3)
        return -1;

    const char* sub = argv[1];
    const char* str = argv[2];

    size_t sublen = strlen(sub);
    size_t pos = 0;
    int i = 0;

    while(*str != '\0')
    {
        if(*str == sub[pos])
            pos++;
        else 
        {
            // pos = 0;
            if(pos != 0)
            {
                pos = 0;
                if(*str == sub[pos])
                    pos++;
            }
        }
        
        if(pos == sublen)
        {
            std::cout << "find str " << i << std::endl;
            break;
        }

        str++;
        i++;
    }


    return 0;
}