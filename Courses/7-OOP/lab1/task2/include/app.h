#include <string>
#include <sys/ioctl.h>

// we'll use Default arguments so the function can be
// called without providing one or more trailing arguments.
// https://en.cppreference.com/cpp/language/default_arguments
void show_tui_menu(std::string text1 = "", std::string color1 = "",
                   std::string text2 = "", std::string color2 = "",
                   std::string text3 = "", std::string color3 = "",
                   std::string text4 = "", std::string color4 = "",
                   std::string text5 = "", std::string color5 = "");

int get_width();
int get_height();
winsize read_terminal_size();

// ---------------------------------------------------
// WT* is this line
// #pragma once