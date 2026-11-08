#include "../include/app.h"
void reset_color() { cout << ESC << "[0m"; }

void move_cursor(int x, int y) { cout << ESC << "[" << x << ";" << y << "H"; }

void print_bg_cell(int row, int col, int color) {
  move_cursor(row, col);
  cout << ESC << "[48;5;" << color << "m ";
  reset_color();
}

int get_width_center(char* text) {
  int count = 0;
  while (text[count] != '\0') {
    count++;
  }

  return (BG_WIDTH - count) / 2;
}

void draw_frame() {
  // printing up and down fram
  for (int i = 0; i < BG_WIDTH; i++) {
    print_bg_cell(0, i, FRAM_COLOR);
    print_bg_cell(BG_HEIGHT, i, FRAM_COLOR);
  }

  // printing left and right fram
  for (int i = 0; i < BG_HEIGHT; i++) {
    print_bg_cell(i, 1, FRAM_COLOR);
    print_bg_cell(i, 2, FRAM_COLOR);
    print_bg_cell(i, BG_WIDTH - 1, FRAM_COLOR);
    print_bg_cell(i, BG_WIDTH - 2, FRAM_COLOR);
  }
}

void print_text(int row, char* text, int color) {
  int col = get_width_center(text);

  move_cursor(row, col);
  cout << ESC << "[1;" << color << "m" << text;
  reset_color();
}

void show_tui_menu(char* text1, int color1, char* text2, int color2,
                   char* text3, int color3) {

  draw_frame();
  int start_row = BG_HEIGHT / 1.5;
  print_text(start_row, text1, color1);
  print_text(start_row + 1, text2, color2);
  print_text(start_row + 2, text3, color3);

  move_cursor(BG_HEIGHT + 1, 1);
}