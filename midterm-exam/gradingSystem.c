/*
 * Copyright (c) 2023 Kenneth C.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <stdio.h>

/*
 * Instructions
 * ============
 * Its the end of the semester and to help the admin see who has garnered passing
 * remarks this semester, they have decided to get a system built to check who
 * has passed or failed this semester. The system will ask how many subjects the
 * student is taking as well as how many exams per subject, after which the user
 * will input the scores of each exam of the subject. To help the student as
 * well, the system will also determine which subject the student performed the
 * best and worst in.
 *
 * Create a program that will ask the user for the number of subjects as well as
 * number of exams, the user will then input the scores of each exam per subject
 * (e.g Score of Subject 1 - Exam 1 then Subject 1 - Exam 2, etc). The Program
 * will then average the scores of all the exams, and display the average. The
 * Program should also determine which subject the student performed the best and
 * worst in. After all of these, finally display if the student was able to pass
 * the semester, the basis for passing the semester is if the students Average
 * Grade is greater than 75.
 * 
 * In the event the student has a grade of 0 in all of his exam, then the student
 * will not have a best subject and will instead display "No Best Subject"
 * 
 * Sample Output 1
 * ===============
 * Input number of Subjects: 0
 * Input number of Exams: 0
 * 
 * Sample Output 2
 * ===============
 * Input number of Subjects: 1
 * Input number of Exams: 1
 * Input Grade for Subject 1 - Exam 1 : 0
 * 
 * 
 * Average Grade for 1 Exams : 0
 * 
 * No Best Subject
 * Worst Subject: Subject 1
 * 
 * Failed this Semester
 * 
 * Sample Output 3
 * ===============
 * Input number of Subjects: 2
 * Input number of Exams: 2
 * Input Grade for Subject 1 - Exam 1 : 90
 * Input Grade for Subject 1 - Exam 2 : 90
 * Input Grade for Subject 2 - Exam 1 : 80
 * Input Grade for Subject 2 - Exam 2 : 80
 * 
 * 
 * Average Grade for 4 Exams : 85
 * 
 * Best Subject: Subject 1
 * Worst Subject: Subject 2
 * 
 * Passed this Semester
 */

int main() {
    int subjects, exams, bestSubject, worstSubject, currentGrade, averageGrade;
    int bestGrade = 0, worstGrade = 100, totalGrade = 0;
    printf("Input number of Subjects: ");
    scanf("%d", &subjects);

    printf("Input number of Exams: ");
    scanf("%d", &exams);

    for (int i = 1; i < subjects + 1; ++i) {
        for (int j = 1; j < exams + 1; ++j) {
            printf("Input Grade for Subject %d - Exam %d : ", i, j);
            scanf("%d", &currentGrade);
            totalGrade +=  currentGrade;

            if (currentGrade < worstGrade) {
                worstGrade = currentGrade;
                worstSubject = i;
            }

            if (currentGrade > bestGrade) {
                bestGrade = currentGrade;
                bestSubject = i;
            }
        }
    }
    
    if (subjects > 0 && exams > 0) {
        averageGrade = totalGrade / (subjects * exams);
        printf("\n\nAverage Grade for %d Exams : %d\n\n", subjects * exams, averageGrade);
        
        if (averageGrade == 0) {
            printf("No Best Subject\n");
        } else {
            printf("Best Subject: Subject %d\n", bestSubject);
        }
        printf("Worst Subject: Subject %d\n\n", worstSubject);
        
        if (averageGrade > 75) {
            printf("Passed this Semester");
        } else {
            printf("Failed this Semester");
        }
    }

    return 0;
}