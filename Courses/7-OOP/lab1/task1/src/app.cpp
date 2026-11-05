#include "../include/app.h"
void reset_color() { cout << ESC << "[0m"; }

void move_cursor(int x, int y) { cout << ESC << "[" << x << ";" << y << "H"; }

void cout_bg_cell(int row, int col, int color) {
  move_cursor(row, col);
  cout << ESC << "[48;5;" << color << "m ";
  reset_color();
}

int get_width_center(char* text) {
  int len = 0;
  while (text[len] != '\0') {
    len++;
  }

  return (BG_WIDTH - 2 - len) / 2;
}

void draw_frame() {
  // printing up and down fram
  for (int col = 1; col <= BG_WIDTH; col++) {
    cout_bg_cell(1, col, FRAM_COLOR);
    cout_bg_cell(BG_HEIGHT, col, FRAM_COLOR);
  }

  // printing left and right fram
  for (int row = 2; row < BG_HEIGHT; row++) {
    cout_bg_cell(row, 1, FRAM_COLOR);
    cout_bg_cell(row, 2, FRAM_COLOR);
    cout_bg_cell(row, BG_WIDTH - 1, FRAM_COLOR);
    cout_bg_cell(row, BG_WIDTH, FRAM_COLOR);
  }
}

void cout_text(int row, char* text, int color) {
  int col = get_width_center(text);

  move_cursor(row, col);
  cout << ESC << "[1;" << color << "m" << text;
  reset_color();
}

void show_tui_menu(char* text1, int color1, char* text2, int color2,
                   char* text3, int color3) {
  draw_frame();

  int start_row = BG_HEIGHT / 2;

  cout_text(start_row, text1, color1);
  cout_text(start_row + 1, text2, color2);
  cout_text(start_row + 2, text3, color3);

  move_cursor(BG_HEIGHT + 1, 1);
}