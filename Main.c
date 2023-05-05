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
    
    if (file == NULL) {
    printf("Error creating log file!\n");
    exit(1);
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
    fclose(file);

printf("Selamat Datang di Game Who wants to be a millionaire, %s!\n\n", u.username);

struct question questions[5] = {
    {"Yang bukan merek mobil Eropa adalah?", {"Ferrari", "Lamborghini", "Honda", "Porsche"}, 3},
    {"Penyejuk ruangan biasa atau biasa disebut AC merupakan kepanjangan dari ?", {"Air Cooler", "Air Conditioner", "Aw so Cool", "Automatic Cooler"}, 2},
    {"Orang buta adalah orang yang tidak dapat melihat. Apakah sebutan untuk orang buta?", {"Tuna Rungu", "Tunawisma", "Tuna Netra", "Tunawicara"}, 3},
    {"Nama ibukota Afganisthan adalah?", {"Ankara", "Aleppo", "Mosul", "Kabul"}, 4},
    {"Pendiri Palang Merah Internasional adalah?", {"J.Hendry Dunant", "Baden Powell", "Virgil van Dijk", "Gordon Ramsy"}, 1},
};

int score = 0;

for (int i = 0; i < 5; i++) {
    printf("Question %d:\n", i+1);
    print_question(questions[i]);
    printf("Masukkan Jawaban (1-4): ");
    int answer;
    scanf("%d", &answer);
    if (answer == questions[i].correct_answer) {
        printf("BENAR!\n\n");
        score += 20;
    } else {
        printf("SALAH!\n\n");
    }
}

printf("Game Selesai!\n\n");
printf("Nilai Anda adalah: %d\n", score);

return 0;

}

