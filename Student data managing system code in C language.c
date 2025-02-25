#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAX_STUDENTS 65

struct sinfo {
	char fname[50];
	char lname[50];
	long int roll;
	float cgpa;
	char Dept[4];//Enter Short form
}st[65];
int i=0;
//Add Student Details ---
void add_student() {
    if (i < MAX_STUDENTS) {
        FILE *filePointer = fopen("student_database2.txt", "a");
        if (filePointer == NULL) {
            printf("Failed to open the file.\n");
            return;
        }

        printf("Add the Students Details\n");
        printf("-------------------------\n");
        printf("Enter the firstname of student :-\n");
        scanf("%s", st[i].fname);
        printf("Enter the last name of student :-\n");
        scanf("%s", st[i].lname);
        printf("Enter the Roll Number\n");
        scanf("%ld", &st[i].roll);
        printf("Enter the CGPA you obtained\n");
        scanf("%f", &st[i].cgpa);
        printf("Enter the college Department :\n");
        scanf("%s", st[i].Dept);

        fprintf(filePointer, "%s %s %ld %f %s\n", st[i].fname, st[i].lname, st[i].roll, st[i].cgpa, st[i].Dept);
        fclose(filePointer);
        printf("Student details added to the database.\n");

        i++;
    } else {
        printf("The Database is Full ...\n");
    }
}
//Attendance count 
void attendance() {
    long int roll;
    int totalClasses, attendedClasses;
    printf("Enter the roll number: ");
    scanf("%ld", &roll);
    printf("Total classes held in the last semester: ");
    scanf("%d", &totalClasses);
    printf("Total classes attended by the student: ");
    scanf("%d", &attendedClasses);

    float attendancePercentage = (float)attendedClasses / totalClasses * 100;
    char filename[30];
    sprintf(filename, "%ld_attendance.txt", roll);

    FILE *filePointer = fopen(filename, "a");
    if (filePointer == NULL) {
        printf("Failed to open the file.\n");
        return;
    }

    fprintf(filePointer, "Total classes held: %d, Total classes attended: %d, Attendance: %.2f%%\n",
            totalClasses, attendedClasses, attendancePercentage);
    fclose(filePointer);

    if (attendancePercentage > 90) {
        printf("You have excellent attendance ...\n");
    } else if (attendancePercentage > 75) {
        printf("You have good attendance.\n");
    } else {
        printf("You don't have enough attendance ... also, you are not able to attend the semester exam. Contact principal.\n");
    }
    printf("YOUR Attendance: %.2f%%\n", attendancePercentage);
}
// check attedance 
void check_attendance() {
	long int roll;
	 printf("Enter the roll number: ");
    scanf("%ld", &roll);
    char filename[30];
    sprintf(filename, "%ld_attendance.txt", roll);

    FILE *filePointer = fopen(filename, "r");
    if (filePointer == NULL) {
        printf("No attendance records found for roll number %ld.\n", roll);
        return;
    }

    char line[100];
    printf("\nAttendance details for roll number %ld:\n", roll);
    while (fgets(line, sizeof(line), filePointer)) {
        printf("%s", line);
    }

    fclose(filePointer);
}
//Subject combination :-
void subject() {
    long int x;
    printf("Enter the roll number: ");
    scanf("%ld", &x);

    FILE *filePointer = fopen("student_database2.txt", "r");
    if (filePointer == NULL) {
        printf("Failed to open the file.\n");
        return;
    }

    char fname[50], lname[50], Dept[4];
    long int rollNumber;
    float cgpa;
    int found = 0;

    while (fscanf(filePointer, "%s %s %ld %f %s", fname, lname, &rollNumber, &cgpa, Dept) != EOF) {
        if (rollNumber == x) {
            printf("\nCommon Subjects:\n");
            printf("ESC EC 301\n");
            printf("ESC CSE 301\n");
            printf("PCC IT 301\n");
            printf("PCC IT 302\n");
            printf("ESC EC 351\n");
            printf("ESC CSE 351\n");

            if (strcmp(Dept, "CSE") == 0 || strcmp(Dept, "cse") == 0) {
                printf("\nCSE Specific Subjects:\n");
                printf("PCC CSE 301\n");
                printf("PCC CSE 302\n");
                printf("ESC CSE 351\n");
            }
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("No student found with the roll number %ld.\n", x);
    }

    fclose(filePointer);
}
//All Over result
void res() {
    FILE *filePointer = fopen("student_database2.txt", "r");
    if (filePointer == NULL) {
        printf("Failed to open the file.\n");
        return;
    }

    char fname[50], lname[50], Dept[4];
    long int rollNumber;
    float cgpa;

    printf("\n_Roll_____________Name______________CGPA_____________Dept\n");

    while (fscanf(filePointer, "%s %s %ld %f %s", fname, lname, &rollNumber, &cgpa, Dept) != EOF) {
        printf("%ld ------%s  %s---------->:%.2f------>%s\n", rollNumber, fname, lname, cgpa, Dept);
    }

    fclose(filePointer);
}

// Cirtificate Maker 
void generate_certificate() {
	long int roll;
	   printf("Enter your roll number :");
	   scanf("%ld",&roll);
    FILE *filePointer = fopen("student_database2.txt", "r");
    if (filePointer == NULL) {
        printf("Failed to open the file.\n");
        return;
    }

    char fname[50], lname[50], Dept[4];
    long int rollNumber;
    float cgpa;
    int found = 0;

    while (fscanf(filePointer, "%s %s %ld %f %s", fname, lname, &rollNumber, &cgpa, Dept) != EOF) {
        if (rollNumber == roll) {
            found = 1;
            printf("*****************************************\n");
            printf("*           CERTIFICATE OF COMPLETION   *\n");
            printf("*****************************************\n\n");
            printf("This is to certify that\n\n");
            printf("      %s   %s\n\n", fname, lname);
            printf("has successfully completed the course\n\n");
            printf("  of Engineering in   %s\n\n", Dept);
            printf("on\n");
            printf(" **/**/2024   \n\n");
            printf("Congratulations on this achievement!\n\n");
            printf("*****************************************\n");
            break;
        }
    }

    if (!found) {
        printf("Student with roll number %ld not found.\n", roll);
    }

    fclose(filePointer);
}
// Find By roll Number 
void find_rl() {
    long int x;
    printf("Enter the Roll Number of the student\n");
    scanf("%ld", &x);

    FILE *filePointer = fopen("student_database2.txt", "r");
    if (filePointer == NULL) {
        printf("Failed to open the file.\n");
        return;
    }

    char fname[50], lname[50], Dept[4];
    long int rollNumber;
    float cgpa;
    int found = 0;

    while (fscanf(filePointer, "%s %s %ld %f %s", fname, lname, &rollNumber, &cgpa, Dept) != EOF) {
        if (rollNumber == x) {
            found = 1;
            printf("The Students Details are\n");
            printf("The First name is %s\n", fname);
            printf("The Last name is %s\n", lname);
            printf("The CGPA is %2f\n", cgpa);
            printf("The dept is %s\n", Dept);
            break;
        }
    }

    if (!found) {
        printf("Student with roll number %ld not found.\n", x);
    }

    fclose(filePointer);
}

//fees pyment

void fees_sem() {
	long int roll;
	printf("Enter the roll number of the student :-");
	scanf("%ld",&roll);
    char filename[20];
    sprintf(filename, "%ld_fees.txt", roll);

    FILE *filePointer = fopen(filename, "a");
    if (filePointer == NULL) {
        printf("Failed to open the file.\n");
        return;
    }
    printf("ENTER P OR p FOR UPDATE PAYMENT DETAILS :--\n");
    char c;
    printf("Semester 1 :");
    c = getche();
    if (c == 'p' || c == 'P') {
        fprintf(filePointer, "Semester 1: Payment Complete\n");
        printf("\nThe First sem payment is Complete..\n");
    } else {
        fprintf(filePointer, "Semester 1: Payment Due\n");
        printf("\nThe payment is Due..\n");
    }

    printf("Semester 2 :");
    c = getche();
    if (c == 'p' || c == 'P') {
        fprintf(filePointer, "Semester 2: Payment Complete\n");
        printf("\nThe Second sem payment is Complete..\n");
    } else {
        fprintf(filePointer, "Semester 2: Payment Due\n");
        printf("\nThe payment is Due..\n");
    }

    printf("Semester 3 :");
    c = getche();
    if (c == 'p' || c == 'P') {
        fprintf(filePointer, "Semester 3: Payment Complete\n");
        printf("\nThe Third sem payment is Complete..\n");
    } else {
        fprintf(filePointer, "Semester 3: Payment Due\n");
        printf("\nThe payment is Due..\n");
    }

    printf("Semester 4 :");
    c = getche();
    if (c == 'p' || c == 'P') {
        fprintf(filePointer, "Semester 4: Payment Complete\n");
        printf("\nThe Fourth sem payment is Complete..\n");
    } else {
        fprintf(filePointer, "Semester 4: Payment Due\n");
        printf("\nThe payment is Due..\n");
    }

    fclose(filePointer);
}
// check fees 
void check_fees() {
	long int roll;
		printf("Enter the roll number of the student :-");
	scanf("%ld",&roll);
    char filename[20];
    sprintf(filename, "%ld_fees.txt", roll);

    FILE *filePointer = fopen(filename, "r");
    if (filePointer == NULL) {
        printf("No fee details found for roll number %ld.\n", roll);
        return;
    }

    char line[100];
    printf("\nFee details for roll number %ld:\n", roll);
    while (fgets(line, sizeof(line), filePointer)) {
        printf("%s", line);
    }

    fclose(filePointer);
}
// by the first name
void find_fn() {
    char a[50];
    printf("Enter the First Name of the student\n");
    scanf("%s", a);

    FILE *filePointer = fopen("student_database2.txt", "r");
    if (filePointer == NULL) {
        printf("Failed to open the file.\n");
        return;
    }

    char fname[50], lname[50], Dept[4];
    long int rollNumber;
    float cgpa;
    int found = 0;

    while (fscanf(filePointer, "%s %s %ld %f %s", fname, lname, &rollNumber, &cgpa, Dept) != EOF) {
        if (strcmp(fname, a) == 0) {
            printf("The Students Details are:-----\n");
            printf("The First name is %s\n", fname);
            printf("The Last name is %s\n", lname);
            printf("The Roll Number is %ld\n", rollNumber);
            printf("The CGPA is %f\n", cgpa);
            printf("The dept is %s\n", Dept);
            found = 1;
            printf("\n---------------------------\n");
        }
    }

    if (!found) {
        printf("The First Name not Found\n");
    }

    fclose(filePointer);
}

// Function to find by Dept
void find_dept() {
    char id[4];
    printf("Enter the Department: \n");
    scanf("%s", id);
printf("\n---------------------------\n");
    FILE *filePointer = fopen("student_database2.txt", "r");
    if (filePointer == NULL) {
        printf("Failed to open the file.\n");
        return;
    }

    char fname[50], lname[50], Dept[4];
    long int rollNumber;
    float cgpa;
    int found = 0;

    while (fscanf(filePointer, "%s %s %ld %f %s", fname, lname, &rollNumber, &cgpa, Dept) != EOF) {
        if (strcmp(Dept, id) == 0) {
            printf("The Students Details :-----\n");
            printf("The First name is : %s\n", fname);
            printf("The Last name is : %s \n", lname);
            printf("The Roll Number is : %ld \n", rollNumber);
            printf("The CGPA is : %f\n ", cgpa);
            printf("The dept is : %s\n", Dept);
            found = 1;
            printf("\n---------------------------\n");
        }
    }

    if (!found) {
        printf("No students found in the Department: %s\n", id);
    }

    fclose(filePointer);
}

//Total Number of Students 
void tot_s() {
    FILE *filePointer = fopen("student_database2.txt", "r");
    if (filePointer == NULL) {
        printf("Failed to open the file.\n");
        return;
    }

    char fname[50], lname[50], Dept[4];
    long int rollNumber;
    float cgpa;
    int count = 0;

    while (fscanf(filePointer, "%s %s %ld %f %s", fname, lname, &rollNumber, &cgpa, Dept) != EOF) {
        count++;
    }

    fclose(filePointer);

    printf("\n----------------------------------------\n");
    printf("\tThe total number of Students is %d\n", count);
    printf("\t\nyou can have a max of 65 students\n");
    printf("\tyou can have %d more students\n", 65 - count);
}
// Delete details by roll Number 
void del_s() {
    long int a;
    printf("Enter the Roll Number which you want to delete\n");
    scanf("%ld", &a);

    FILE *filePointer = fopen("student_database2.txt", "r");
    FILE *tempFilePointer = fopen("temp_student_database.txt", "w");
    if (filePointer == NULL || tempFilePointer == NULL) {
        printf("Failed to open the file.\n");
        return;
    }

    char fname[50], lname[50], Dept[4];
    long int rollNumber;
    float cgpa;
    int found = 0;

    while (fscanf(filePointer, "%s %s %ld %f %s", fname, lname, &rollNumber, &cgpa, Dept) != EOF) {
        if (rollNumber == a) {
            found = 1;
            continue; // Skip writing this student's details to the temp file
        }
        fprintf(tempFilePointer, "%s %s %ld %f %s\n", fname, lname, rollNumber, cgpa, Dept);
    }

    fclose(filePointer);
    fclose(tempFilePointer);

    if (found) {
        remove("student_database2.txt");
        rename("temp_student_database.txt", "student_database2.txt");
        printf("The Roll Number %ld is removed Successfully\n", a);
    } else {
        remove("temp_student_database.txt");
        printf("No student found with the Roll Number %ld.\n", a);
    }
}
// Function to update a students data
void up_s() {
    printf("Enter the roll number to update the entry: ");
    long int x;
    scanf("%ld", &x);

    FILE *filePointer = fopen("student_database2.txt", "r");
    FILE *tempFilePointer = fopen("temp_student_database.txt", "w");
    if (filePointer == NULL || tempFilePointer == NULL) {
        printf("Failed to open the file.\n");
        return;
    }

    char fname[50], lname[50], Dept[4];
    long int rollNumber;
    float cgpa;
    int found = 0;

    while (fscanf(filePointer, "%s %s %ld %f %s", fname, lname, &rollNumber, &cgpa, Dept) != EOF) {
        if (rollNumber == x) {
            found = 1;
            printf("1. first name\n2. last name\n3. roll no.\n4. CGPA\n5. Department\n");
            int choice;
            scanf("%d", &choice);
            switch (choice) {
                case 1:
                    printf("Enter the new first name: \n");
                    scanf("%s", fname);
                    break;
                case 2:
                    printf("Enter the new last name: \n");
                    scanf("%s", lname);
                    break;
                case 3:
                    printf("Enter the new roll number: \n");
                    scanf("%ld", &rollNumber);
                    break;
                case 4:
                    printf("Enter the new CGPA: \n");
                    scanf("%f", &cgpa);
                    break;
                case 5:
                    printf("Enter the new Department: \n");
                    scanf("%s", Dept);
                    break;
                default:
                    printf("Invalid choice\n");
                    break;
            }
            printf("UPDATED SUCCESSFULLY.\n");
        }
        fprintf(tempFilePointer, "%s %s %ld %f %s\n", fname, lname, rollNumber, cgpa, Dept);
    }

    fclose(filePointer);
    fclose(tempFilePointer);

    if (found) {
        remove("student_database2.txt");
        rename("temp_student_database.txt", "student_database2.txt");
    } else {
        remove("temp_student_database.txt");
        printf("No student found with the roll number %ld.\n", x);
    }
}
void functioning(){
	printf("\n-------------------------------------------\n");
	printf("\nThe Task that you want to perform\n");
	printf("1. Add the Student Details\n");
	printf("2. Find the Student Details by Roll Number\n");
    printf("3. Find the Student Details by First Name\n");
 	printf("4. Find the Student Details by Department\n");
	printf("5. Find the Total number of Students\n");
	printf("6. Delete the Students Details by Roll Number\n");
    printf("7. Update the Students Details by Roll Number\n");
    printf("8. Check the fees details of the Stuent\n");
    printf("9. Check the Result of the full Class \n");
    printf("10. To Generate the Cirtificate of a Specific Student \n");
    printf("11. Subject of the Dept...\n");
    printf("12. To count students Attendence ...\n");
	printf("13. Update the fees details of the Stuent\n");
	printf("14. Check Student attendance \n");
	printf("15. Exit \n");
	printf("Enter your choice to find the task :---\n");
	int choice;
	scanf("%d",&choice);
	switch(choice){
		    case 1:add_student();
		    	break;
		    case 2: find_rl();
		        break;
		    case 3: find_fn();
			    break;
			case 4:find_dept();
			    break;
		    case 5:tot_s();
			    break;
			case 6: del_s()	;
			    break;
			case 7:up_s();
		     	break;
		    case 8:check_fees();
				break;
			case 9:res();
			    break;	
		    case 10:generate_certificate();
		        break;
		    case 11: subject();
			    break;    
			case 12:attendance();
				break;
			case 13:fees_sem();
			    break;
			case 14:check_attendance() ;
			    break;    
			case 15:exit(0);
					 	    
	}
}
int main(){
	char ch;
	printf("You want to access Student Databse [Y/y or N/n]:\n");
	ch=getche();
	do{
    functioning();
	printf("\nAgain You want to access Student Databse [Y/y or N/n]:\n");
	ch=getche();
	}while(ch=='y'||ch=='Y');
	return 0;
}
