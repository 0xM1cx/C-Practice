#include <stdio.h>
#include <string.h>

struct Teacher {
    char name[50];
};

struct Student {
    char name[50];
    int present;
};

struct Attendance {
    char course[20];
    char date[15];
    int year;
    char section;
    int num_students;
    struct Student students[50];
};

void enterTeacherInfo(struct Teacher *teacher) {
    printf("Enter teacher's name: ");
    scanf("%s", teacher->name);
}

void enterAttendance(struct Attendance *attendance) {
    printf("Enter course code/name: ");
    scanf("%s", attendance->course);
    printf("Enter date (DD/MM/YYYY): ");
    scanf("%s", attendance->date);
    printf("Enter year of the class: ");
    scanf("%d", &attendance->year);
    printf("Enter section: ");
    scanf(" %c", &attendance->section);
    printf("Enter number of students: ");
    scanf("%d", &attendance->num_students);

    for (int i = 0; i < attendance->num_students; i++) {
        printf("Enter full name of student %d: ", i + 1);
        scanf("%s", attendance->students[i].name);
        printf("Is %s present? (1 for present, 0 for absent): ", attendance->students[i].name);
        scanf("%d", &attendance->students[i].present);
    }
}

void displayAttendance(struct Attendance attendance) {
    printf("Attendance for %s on %s\n", attendance.course, attendance.date);
    for (int i = 0; i < attendance.num_students; i++) {
        printf("%s: %s\n", attendance.students[i].name, attendance.students[i].present ? "Present" : "Absent");
    }
}

void displayStudentAttendance(struct Attendance attendance, char student_name[]) {
    printf("Attendance for %s in %s on %s\n", student_name, attendance.course, attendance.date);
    for (int i = 0; i < attendance.num_students; i++) {
        if (strcmp(attendance.students[i].name, student_name) == 0) {
            printf("%s: %s\n", attendance.students[i].name, attendance.students[i].present ? "Present" : "Absent");
            return;
        }
    }
    printf("Student not found.\n");
}

void displayClassAttendance(struct Attendance attendance[], int num_attendance, char course[], char date[]) {
    printf("Attendance for %s on %s\n", course, date);
    for (int i = 0; i < num_attendance; i++) {
        if (strcmp(attendance[i].course, course) == 0 && strcmp(attendance[i].date, date) == 0) {
            displayAttendance(attendance[i]);
            return;
        }
    }
    printf("Attendance not found.\n");
}

void editAttendance(struct Attendance *attendance, char course[], char date[]) {
    if (strcmp(attendance->course, course) == 0 && strcmp(attendance->date, date) == 0) {
        printf("Enter new attendance:\n");
        for (int i = 0; i < attendance->num_students; i++) {
            printf("Is %s present? (1 for present, 0 for absent): ", attendance->students[i].name);
            scanf("%d", &attendance->students[i].present);
        }
        printf("Attendance edited successfully.\n");
    } else {
        printf("Attendance not found.\n");
    }
}

void editTeacherInfo(struct Teacher *teacher) {
    printf("Enter new teacher's name: ");
    scanf("%s", teacher->name);
}

int main() {
    int option;
    struct Teacher teacher;
    struct Attendance attendance[50];
    int num_attendance = 0;

    do {
        printf("\n1. Enter teacher's information\n");
        printf("2. Enter attendance\n");
        printf("3. Display attendance\n");
        printf("4. Display attendance of a student\n");
        printf("5. Display attendance of a class\n");
        printf("6. Edit attendance\n");
        printf("7. Edit teacher's information\n");
        printf("8. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &option);

        switch (option) {
        case 1:
            enterTeacherInfo(&teacher);
            break;
        case 2:
            enterAttendance(&attendance[num_attendance++]);
            break;
        case 3: {
            char course[20], date[15];
            printf("Enter course code/name: ");
            scanf("%s", course);
            printf("Enter date (DD/MM/YYYY): ");
            scanf("%s", date);
            for (int i = 0; i < num_attendance; i++) {
                if (strcmp(attendance[i].course, course) == 0 && strcmp(attendance[i].date, date) == 0) {
                    displayAttendance(attendance[i]);
                    break;
                }
            }
            break;
        }
        case 4: {
            char course[20], student_name[50];
            printf("Enter course code/name: ");
            scanf("%s", course);
            printf("Enter student's name: ");
            scanf("%s", student_name);
            for (int i = 0; i < num_attendance; i++) {
                if (strcmp(attendance[i].course, course) == 0) {
                    displayStudentAttendance(attendance[i], student_name);
                    break;
                }
            }
            break;
        }
        case 5: {
            char course[20], date[15];
            printf("Enter course code/name: ");
            scanf("%s", course);
            printf("Enter date (DD/MM/YYYY): ");
            scanf("%s", date);
            displayClassAttendance(attendance, num_attendance, course, date);
            break;
        }
        case 6: {
            char course[20], date[15];
            printf("Enter course code/name: ");
            scanf("%s", course);
            printf("Enter date (DD/MM/YYYY): ");
            scanf("%s", date);
            for (int i = 0; i < num_attendance; i++) {
                editAttendance(&attendance[i], course, date);
            }
            break;
        }
        case 7:
            editTeacherInfo(&teacher);
            break;
        case 8:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid option. Please try again.\n");
        }
    } while (option != 8);

    return 0;
}