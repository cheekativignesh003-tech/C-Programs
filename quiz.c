#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Question {
    char question[256];
    char optionA[100];
    char optionB[100];
    char optionC[100];
    char optionD[100];
    char correctAnswer;
};

void createQuizFile() {
    FILE *fp = fopen("quiz.txt", "w");
    if (fp == NULL) {
        printf("Error creating file!\n");
        exit(1);
    }

    struct Question q[3] = {
        {"What is the capital of India?", "A. Delhi", "B. Mumbai", "C. Chennai", "D. Kolkata", 'A'},
        {"Which language is used for system programming?", "A. Java", "B. Python", "C. C", "D. HTML", 'C'},
        {"Which data structure uses FIFO?", "A. Stack", "B. Queue", "C. Tree", "D. Graph", 'B'}
    };

    for (int i = 0; i < 3; i++)
        fwrite(&q[i], sizeof(struct Question), 1, fp);

    fclose(fp);
    printf("Quiz file created successfully!\n");
}

void playQuiz() {
    FILE *fp = fopen("quiz.txt", "r");
    if (fp == NULL) {
        printf("Quiz file not found. Please create it first.\n");
        return;
    }

    struct Question q;
    int score = 0, total = 0;
    char answer;

    printf("\n=== Welcome to the Quiz Game ===\n");

    while (fread(&q, sizeof(struct Question), 1, fp)) {
        printf("\n%s\n", q.question);
        printf("%s\n%s\n%s\n%s\n", q.optionA, q.optionB, q.optionC, q.optionD);
        printf("Enter your answer (A/B/C/D): ");
        scanf(" %c", &answer);

        if (answer == q.correctAnswer) {
            printf("✅ Correct!\n");
            score++;
        } else {
            printf("❌ Wrong! Correct answer is %c\n", q.correctAnswer);
        }
        total++;
    }

    fclose(fp);
    printf("\nYour Score: %d / %d\n", score, total);
}

int main() {
    int choice;
    while (1) {
        printf("\n=== QUIZ MENU ===\n");
        printf("1. Create Quiz File\n");
        printf("2. Play Quiz\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: createQuizFile(); break;
            case 2: playQuiz(); break;
            case 3: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}
