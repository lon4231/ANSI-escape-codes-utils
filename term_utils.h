#include <iostream>
#include <vector>

#ifdef _WIN32
 #include <windows.h>
#endif


namespace terminal
{
    



void init_screen()
{
#ifdef _WIN32
 HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
 if (hOut == INVALID_HANDLE_VALUE)  {return;}
 DWORD dwMode=0;
 if (!GetConsoleMode(hOut, &dwMode)){return;}
 dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
 if (!SetConsoleMode(hOut, dwMode)) {return;}
#endif
}

void set_color(std::vector<int>text_color,std::vector<int>back_color) 
{
std::cout << "\033[38;2;" << text_color[0]%255 <<";"<< text_color[1]%255 <<";"<<text_color[2]%255 << "m";
std::cout << "\033[48;2;" << back_color[0]%255 <<";"<< back_color[1]%255 <<";"<<back_color[2]%255 << "m";
}


void set_text_size(int size)
{
std::cout<<"\033[6;"<<size<<"m";
}


void reset_text()
{
std::cout<<"\033[0m";
}


void clear_screen(std::vector<int>back_color)
{
reset_text();
set_color({0,0,0},back_color);
std::cout<<"\033[2J\033[H";
}

void print_ansi_code(std::string code)
{
std::cout<<code;
}

void set_terminal_size(int row,int col)
{
std::cout<<"\033[8;"<<row<<";"<<col<<"t";
}
void reset_terminal_size()
{
std::cout<<"\033c";
}


}