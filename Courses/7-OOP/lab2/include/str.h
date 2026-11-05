#define ToUpper 0
#define ToLower 1
#define StringCompaare 2
#define StringCopy 3
#define NotEqule 4
#define SizeDiff 5

int toupper(char* str1);
int tolower(char* str1);
int stringcompare(char* str1, char* str2);
int stringcopy(char* str1, char* str2);
int str(int fun, char str1[], char str2[] = {0});