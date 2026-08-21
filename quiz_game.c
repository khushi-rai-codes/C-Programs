#include <stdio.h>
#include <string.h>
struct Question
{
    char question[200];
    char optionA[100];
    char optionB[100];
    char optionC[100];
    char optionD[100];
    char answer;
};
int main()
{
    struct Question quiz[] = {
        {
            "Which language is used to create web page structure?",
            "A. Python",
            "B. HTML",
            "C. C++",
            "D. Java",
            'B'
        },
        {
            "Which data structure follows LIFO?",
            "A. Queue",
            "B. Array",
            "C. Stack",
            "D. Tree",
            'C'
        },
        {
            "Which keyword is used to define a constant in C?",
            "A. const",
            "B. fixed",
            "C. constant",
            "D. final",
            'A'
        },
        {
            "Which symbol is used for a single-line comment in C?",
            "A. #",
            "B. //",
            "C. <!--",
            "D. **",
            'B'
        }
    };
    int total = sizeof(quiz) / sizeof(quiz[0]);
    int score = 0;
    char answer;
    printf("===== COMPUTER QUIZ =====\n");
    for (int i = 0; i < total; i++)
    {
        printf("\nQuestion %d:\n", i + 1);
        printf("%s\n", quiz[i].question);
        printf("%s\n", quiz[i].optionA);
        printf("%s\n", quiz[i].optionB);
        printf("%s\n", quiz[i].optionC);
        printf("%s\n", quiz[i].optionD);
        printf("Enter your answer: ");
        scanf(" %c", &answer);
        if (answer == quiz[i].answer ||
            answer == quiz[i].answer + 32)
        {
            printf("Correct!\n");
            score++;
        }
        else
        {
            printf("Wrong! Correct answer: %c\n",
                   quiz[i].answer);
        }
    }
    printf("\n===== RESULT =====\n");
    printf("Score: %d/%d\n", score, total);
    return 0;
}
