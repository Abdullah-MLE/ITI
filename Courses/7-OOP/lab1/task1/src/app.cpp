#include "../include/app.h"

#include <sys/ioctl.h>
// sys/ioctl.h is a C header file
// in POSIX-compliant OSs
// -- POSIX: Portable Operating System Interface

// ioctl, TIOCGWINSZ, winsize
#include <unistd.h>
// the unistd or Unix Standard is
// provides wrapper functions for
// core system calls
// ------------------------------
// we importing it to use: STDOUT_FILENO

#include <iostream>

winsize read_terminal_size() {
    winsize size;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &size);
    return size;
}

int get_width() {
    return read_terminal_size().ws_col;
}

int get_height() {
    return read_terminal_size().ws_row;
}

int calculate_left_padding(int width, int text_length) {
    if (text_length >= width) {
        return 0;
    }
    return (width - text_length) / 2;
}

std::string make_spaces(int count) {
    return std::string(count, ' ');
}

void print_centered(std::string text) {
    int padding = calculate_left_padding(get_width(), text.length());
    std::cout << make_spaces(padding) << text << '\n';
}

void show_tui_menu(
     std::string text1,  std::string color1,
     std::string text2,  std::string color2,
     std::string text3,  std::string color3,
     std::string text4,  std::string color4,
     std::string text5,  std::string color5)
{
    print_centered(text1);
}