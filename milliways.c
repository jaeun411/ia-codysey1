#include <stdio.h>
#include <stdlib.h>

#define MAX_CANDIDATES 6
#define MAX_NAME_LENGTH 50
#define MAX_NICKNAME_LENGTH 20
#define MAX_EDUCATION_LENGTH 30
#define MAX_BLOOD_TYPE_LENGTH 3
#define MAX_ALLERGY_LENGTH 30
#define MAX_HOBBY_LENGTH 50
#define MAX_SNS_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    int id; // 고유 ID
    int passed; // 합격 여부
    char nickname[MAX_NICKNAME_LENGTH];
    char education[MAX_EDUCATION_LENGTH];
    float height; // 키 (m)
    float weight; // 몸무게 (kg)
    char blood_type[MAX_BLOOD_TYPE_LENGTH];
    char allergy[MAX_ALLERGY_LENGTH];
    char hobby[MAX_HOBBY_LENGTH];
    char sns[MAX_SNS_LENGTH];
} Candidate;

// 후보자 데이터 초기화
Candidate candidates[MAX_CANDIDATES] = {
    {"박지연", 123456, 1, "Ariel", "고1중퇴", 1.68, 0, "A", "유제품", "댄스 연습, 작곡", "Instagram - @Ariel_Jiyeon"},
    {"Ethan Smith", 234567, 1, "Simba", "중3중퇴", 1.78, 0, "O", "땅콩", "노래 작곡, 헬스 트레이닝", "Twitter - @Simba_Ethan"},
    {"Helena Silva", 345678, 1, "Belle", "중졸", 1.63, 0, "B", "생선", "노래 부르기, 그림 그리기", "Instagram - @Belle_Helena"},
    {"Liam Wilson", 456789, 1, "Aladdin", "중2중퇴", 1.75, 0, "AB", "갑각류", "춤추기, 음악 프로듀싱", "Instagram - @Aladdin_Liam"},
    {"Emma Brown", 567890, 0, "", "", 0, 0, "", "", "", ""},
    {"Oliver Jones", 678901, 0, "", "", 0, 0, "", "", "", ""}
};

void calculate_bmi(Candidate *candidate) {
    if (candidate->weight > 0) {
        float bmi = candidate->weight / (candidate->height * candidate->height);
        printf("이름: %s, BMI: %.2f -> ", candidate->name, bmi);
        switch ((int)(bmi / 10)) {
            case 0: // BMI < 18.5
            case 1: // 18.5 <= BMI < 25
                printf("저체중\n");
                break;
            case 2: // 25 <= BMI < 30
                printf("정상\n");
                break;
            case 3: // 30 <= BMI < 35
                printf("과체중\n");
                break;
            case 4: // 35 <= BMI
            default:
                printf("비만\n");
                break;
        }
    } else {
        printf("이름: %s, 몸무게가 설정되지 않았습니다.\n", candidate->name);
    }
}

int main() {
    // 합격한 후보자에 대한 인터뷰 진행
    Candidate milliways_candidates[MAX_CANDIDATES];
    int milliways_count = 0;

    for (int i = 0; i < MAX_CANDIDATES; i++) {
        if (candidates[i].passed) {
            // 기존 후보자 정보를 복사
            for (int j = 0; j < MAX_NAME_LENGTH; j++)
                milliways_candidates[milliways_count].name[j] = candidates[i].name[j];
            milliways_candidates[milliways_count].id = candidates[i].id;
            milliways_candidates[milliways_count].passed = candidates[i].passed;

            for (int j = 0; j < MAX_NICKNAME_LENGTH; j++)
                milliways_candidates[milliways_count].nickname[j] = candidates[i].nickname[j];
            for (int j = 0; j < MAX_EDUCATION_LENGTH; j++)
                milliways_candidates[milliways_count].education[j] = candidates[i].education[j];

            milliways_candidates[milliways_count].height = candidates[i].height;

            // 몸무게 입력 (여기서는 임의로 설정, 실제로는 인터뷰로 받아야 함)
            printf("%s의 몸무게를 입력하세요 (kg): ", candidates[i].name);
            float weight;
            scanf("%f", &weight);
            milliways_candidates[milliways_count].weight = weight;

            // 혈액형, 알러지, 취미, SNS 복사
            for (int j = 0; j < MAX_BLOOD_TYPE_LENGTH; j++)
                milliways_candidates[milliways_count].blood_type[j] = candidates[i].blood_type[j];
            for (int j = 0; j < MAX_ALLERGY_LENGTH; j++)
                milliways_candidates[milliways_count].allergy[j] = candidates[i].allergy[j];
            for (int j = 0; j < MAX_HOBBY_LENGTH; j++)
                milliways_candidates[milliways_count].hobby[j] = candidates[i].hobby[j];
            for (int j = 0; j < MAX_SNS_LENGTH; j++)
                milliways_candidates[milliways_count].sns[j] = candidates[i].sns[j];

            // BMI 계산
            calculate_bmi(&milliways_candidates[milliways_count]);

            milliways_count++;
        }
    }

    // 밀리웨이즈 멤버 리스트 출력
    printf("\n밀리웨이즈 멤버 리스트:\n");
    for (int i = 0; i < milliways_count; i++) {
        printf("이름: %s, 닉네임: %s, 학력: %s, 키: %.2fm, 몸무게: %.2fkg, 혈액형: %s, 알러지: %s, 취미: %s, SNS: %s\n",
               milliways_candidates[i].name,
               milliways_candidates[i].nickname,
               milliways_candidates[i].education,
               milliways_candidates[i].height,
               milliways_candidates[i].weight,
               milliways_candidates[i].blood_type,
               milliways_candidates[i].allergy,
               milliways_candidates[i].hobby,
               milliways_candidates[i].sns);
    }

    return 0;
}
