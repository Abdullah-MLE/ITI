#include "../include/app.h"
void show_tui_menu(char* text1, int color1, char* text2, int color2,
                   char* text3, int color3) {
  draw_frame();
  int start_row = BG_HEIGHT / 1.5;
  print_text(start_row, text1, color1);
  print_text(start_row + 1, text2, color2);
  print_text(start_row + 2, text3, color3);

  move_cursor(BG_HEIGHT + 1, 1);
}
int main() {
  char text1[] = "text1";
  char text2[] = "text2";
  char text3[] = "text3";
  show_tui_menu(text1, Red, text2, Green, text3, Blue);
  print_text(, , Red);

  return 0;
}