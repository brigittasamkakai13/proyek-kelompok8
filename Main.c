#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_USERNAME_LENGTH 20
#define MAX_PASSWORD_LENGTH 20

struct user {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

int main(int banyakArgumen, char *Argumen[]) // ./Main Username Password
{
    if(banyakArgumen < 2){
        printf("Usage: %s <login.bin>\n", Argumen[0]);
        exit(1);
    }

    struct user u;
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    int logged_in = 0;
    
    
   FILE *fpr = fopen(Argumen[1], "ab");

   if((fpr = fopen("database/login.bin", "rb")) == NULL){
    printf("Gagal membuka file !");
    return EXIT_FAILURE;
   }

   char akun[20];
   fread(akun, sizeof(char), sizeof(akun)/sizeof(char), fpr);

   fclose(fpr);

   char *string[3];
   char username[20], password[20];
   int ctrl = 0;

   string[0] = strtok(akun, "@");
   while(string[ctrl++] != NULL){
    string[ctrl] = strtok(NULL, "@");
   }

   strcpy(username, string[0]);
   strcpy(password, string[1]);

   printf("Username : %s\nPassword : %s", username, password);
   
    return 0;
}
