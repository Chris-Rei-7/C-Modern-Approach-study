#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
bool test_extension(const char *file_name,
const char *extension);
int main(void)
{
 char str[100];
 char ext[100];
 printf("Enter a file name: ");
 fgets(str, sizeof(str), stdin); 
 printf("Enter a file name: "); 
 fgets(ext, sizeof(ext), stdin);
 if(test_extension(str, ext)) {
     printf("true");
 } else {
     printf("false");
 }
 return 0;

}
bool test_extension(const char *file_name,
const char *extension){
    int f_len = strlen(file_name);
    int e_len = strlen(extension);
    for (int i = f_len - 1,j = e_len - 1; j >= 0; i--,j--) {
            if (toupper(*(file_name+i)) != toupper(*(extension+j))) {
                return false;
            
        }
}
return true;
}   
