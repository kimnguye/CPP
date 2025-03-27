/*
    ne pas utiliser printf, alloc, free
    ne pas utiliser using namespace <ns_name> et friend
*/

#include <cstring>
#include <iostream>

void    megaphone(char *str)
{
    int n = strlen(str);

    for (int i = 0; i < n; i++)
		str[i] = std::toupper(str[i]);
}

int main(int argc, char *argv[])
{
    int n = argc;

    if (argc < 2)
    std::cout << "*  LOUD AND UNBEARABLE FEEDBACK NOISE  *";
    else
        while (--argc > 0)
        {
            megaphone(argv[n - argc]);
            std::cout << argv[n - argc];
        }
    std::cout << std::endl;
    return (0);
}
