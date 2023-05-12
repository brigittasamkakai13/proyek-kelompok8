#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_USERNAME_LENGTH 20
#define MAX_PASSWORD_LENGTH 20
#define MAX_QUESTION_LENGTH 100
#define MAX_ANSWER_LENGTH 50

struct user {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

struct question {
char text[MAX_QUESTION_LENGTH];
char answers[4][MAX_ANSWER_LENGTH];
int correct_answer;
};
    
    void print_question(struct question q) {
    printf("%s\n", q.text);
    for (int i = 0; i < 4; i++) {
    printf("%d. %s\n", i+1, q.answers[i]);
        }
    }

    int main(int argc, char *argv[]) {
    if (argc < 2) {
    printf("Usage: %s <login.bin>\n", argv[0]);
    exit(1);
    }
    
    struct user u;
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    int logged_in = 0;
    
    
   FILE *file = fopen(argv[1], "ab");
    
    if (file == NULL) {
    printf("Error creating log file!\n");
    exit(1);
        
   }
    
   int is_register = 0;
   printf("Do you want to register? (y/n): ");
   char choice;
   scanf(" %c", &choice);
        
    if (choice == 'y') {
    is_register = 1;

    printf("Enter username: ");
    scanf("%s", u.username);

    printf("Enter password: ");
    scanf("%s", u.password);

    // tulis data pengguna ke file
    fwrite(&u, sizeof(struct user), 1, file);

    printf("User data has been saved to log file.\n");
}

fclose(file);

    if (is_register) {
    printf("Please login to continue.\n");
    file = fopen(argv[1], "rb");

    if (file == NULL) {
        printf("Error opening log file!\n");
        exit(1);
    }

    printf("Enter username: ");
    scanf("%s", username);

    while (fread(&u, sizeof(struct user), 1, file)) {
        if (strcmp(u.username, username) == 0) {
            printf("Enter password: ");
            scanf("%s", password);

            if (strcmp(u.password, password) == 0) {
                printf("Login successful!\n\n");
                logged_in = 1;
                break;
            } else {
                printf("Invalid password!\n\n");
                break;
            }
        }
    }

    if (!logged_in) {
        printf("User not found!\n");
    }

    fclose(file);
}

if (!logged_in) {
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

