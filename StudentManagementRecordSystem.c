// #include <stdio.h>
// #include <stdbool.h>
// #include <string.h>
// #include <stdlib.h>

#include <windows.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

struct StudentInfo
{
    char ID[10];
    char Name[20];
    char Email[30];
    char Phone[20];
};

struct StudentInfo Students[100];

// some global variables.
int i, j;
int TotalStudents = 0;
char StudentID[10];
FILE *AllStudents;
FILE *ExistingAllStudents;
FILE *TempAllStudents;
// end global variables declaration.

// Functions declaration.
bool IsRunning = true;
void Menu();
void DataSeed();
void ExitProject();
void GoBackOrExit();
void AboutUs();
void UserGuideline();
void DeleteAllStudents();
void ShowAllStudents();
void AddNewStudent();
int SearchStudent(char StudentID[10]);
void DeleteStudent(int StudentIndex);
void EditStudent(int StudentFoundIndex);
// void DeleteStudentByIndex(int CourseIndex);
// void ErrorAndRestart(char *Error[100]);
// int IsAlreadyExists(char GivenLine[30], char InfoType, char StudentID[300]);
// end fuctions declarations.

// main function.
int main()
{
    // system("Color 06"); // this line of code is used to change color of the background and text.
    DataSeed(); // This function is used to show dummy student data record.

    while (IsRunning)
    {
        Menu();
        int option;
        scanf("%d", &option);
        switch (option)
        {
        case 0:
        {
            IsRunning = false;
            ExitProject();
            break;
        }
        case 1:
        {
            system("cls");
            printf("\n\t\t **** Add A New Student ****\n\n");
            AddNewStudent();
            GoBackOrExit();
            break;
        }
        case 2:
        {
            system("cls");
            printf("\n\t\t **** All Students ****\n\n");
            ShowAllStudents();
            GoBackOrExit();
            break;
        }
        case 3:
        {
            system("cls");
            printf("\n\t\t **** Search Students ****\n\n");
            printf(" Enter The Student ID: ");
            scanf("%s", StudentID);
            int IsFound = SearchStudent(StudentID);
            if (IsFound < 0)
            {
                printf(" No Student Found\n\n");
            }
            printf("\n");
            GoBackOrExit();
            break;
        }
        case 4:
        {
            system("cls");
            printf("\n\t\t **** Edit a Student ****\n\n");
            printf(" Enter The Student ID: ");
            scanf("%s", StudentID);
            int StudentFoundIndex = SearchStudent(StudentID);

            if (StudentFoundIndex >= 0)
            {
                EditStudent(StudentFoundIndex);
            }
            else
            {
                printf(" No Student Found\n\n");
            }
            GoBackOrExit();
            break;
        }
        case 5:
        {
            system("cls");
            printf("\n\t\t **** Delete a Student ****\n\n");
            printf(" Enter The Student ID: ");
            scanf("%s", StudentID);

            int DeleteStudentFoundIndex = SearchStudent(StudentID);

            if (DeleteStudentFoundIndex >= 0)
            {
                char Sure = 'N';
                getchar();
                printf("\n\n");
                printf(" Are you sure want to delete this student? (Y/N): ");
                scanf("%c", &Sure);

                if (Sure == 'Y' || Sure == 'y')
                {
                    DeleteStudent(DeleteStudentFoundIndex);
                }
                else
                {
                    printf(" Your Data is Safe.\n\n");
                    GoBackOrExit();
                }
            }
            else
            {
                printf(" No Student Found\n\n");
                GoBackOrExit();
            }

            break;
        }
        case 6:
        {
            char Sure = 'N';
            getchar();
            system("cls");
            printf("\n\t\t **** Delete ALL Students ****\n\n");

            printf(" Are you sure want to delete all the students? (Y/N): ");
            scanf("%c", &Sure);
            if (Sure == 'Y' || Sure == 'y')
            {
                DeleteAllStudents();
            }
            else
            {
                printf(" Your Data is Safe.\n\n");
                GoBackOrExit();
            }
            break;
        }
        case 7:
        {
            printf("Case 7\n");
            system("cls");
            break;
        }
        case 8:
        {
            printf("Case 8\n");
            system("cls");
            UserGuideline();
            GoBackOrExit();
            break;
        }
        case 9:
        {
            printf("Case 9\n");
            system("cls");
            AboutUs();
            GoBackOrExit();
            break;
        }
        default:
        {
            printf("Invalid Input ........\n");
            break;
        }
        }
    }

    return 0;
} // end main function.

// Functions defintion.
void Menu()
{
    printf("\n\n\t***Student Management System Using C***\n\n");
    printf("\t\t\tMAIN MENU\n");
    printf("\t\t=========================\n");
    printf("\t\t[1]-> Add A New student.\n");
    printf("\t\t[2]-> Show All students.\n");
    printf("\t\t[3]-> Search A student.\n");
    printf("\t\t[4]-> Edit A student.\n");
    printf("\t\t[5]-> Delete A student.\n");
    printf("\t\t[6]-> Delete All students.\n");
    printf("\t\t[7]-> Clear The window.\n");
    printf("\t\t[8]-> User Guideline.\n");
    printf("\t\t[9]-> About Us.\n");
    printf("\t\t[0]-> Exit the Program.\n");
    printf("\t\t=========================\n");
    printf("\t\t=== Total student : %d ==\n", TotalStudents);
    printf("\t\t=========================\n");
    printf("\t\tEnter The Choice: ");
} // end menu.

void DataSeed()
{
    //-- store some dummy data
    //-- student 1
    strcpy(Students[0].ID, "St1");
    strcpy(Students[0].Name, "Student 1");
    strcpy(Students[0].Phone, "016111111111");
    strcpy(Students[0].Email, "student-1@gmail.com");

    //-- student 2
    strcpy(Students[1].ID, "St2");
    strcpy(Students[1].Name, "Student 2");
    strcpy(Students[1].Phone, "016111111112");
    strcpy(Students[1].Email, "student-2@gmail.com");

    //-- student 3
    strcpy(Students[2].ID, "St3");
    strcpy(Students[2].Name, "Student 3");
    strcpy(Students[2].Phone, "016111111113");
    strcpy(Students[2].Email, "student-3@gmail.com");

    //-- student 4
    strcpy(Students[3].ID, "St4");
    strcpy(Students[3].Name, "Student 4");
    strcpy(Students[3].Phone, "016111111114");
    strcpy(Students[3].Email, "student-4@gmail.com");

    TotalStudents = 4;
}

void ExitProject()
{
    system("cls");
    int i;
    char ThankYou[100] = " === Thank You Exploring My Software.===\n";
    char SeeYouSoon[100] = " ============= See You Soon =============\n";
    for (i = 0; i < strlen(ThankYou); i++)
    {
        printf("%c", ThankYou[i]);
        Sleep(40);
    }
    for (i = 0; i < strlen(SeeYouSoon); i++)
    {
        printf("%c", SeeYouSoon[i]);
        Sleep(40);
    }
    exit(0);
} // end ExitProject.

void GoBackOrExit()
{
    getchar();
    char Option;
    printf(" Go back(b)? or Exit(0)?: ");
    scanf("%c", &Option);
    if (Option == '0')
    {
        ExitProject();
    }
    else
    {
        system("cls");
    }
}

void AboutUs()
{
    printf("\n\t\t **** About US? ****\n\n");

    printf(" Some important note we should remember.\n");
    printf(" -> This is a simple student record management system project.\n");
    printf(" -> You can modify the source code.\n");
    printf(" -> You can use this project only for personal purpose not for business.\n\n");

    printf(" ->> visit https://sites.google.com/view/codingwill/home for more project like this. <<-\n\n");
}

void UserGuideline()
{
    printf("\n\t\t **** How it Works? ****\n\n");
    printf(" -> You will only able to store the Student's ID, Name, Email, Phone.\n");
    printf(" -> A student can have maximum 4 courses and minimum 1 course.\n");
    printf(" -> Student ID can be maximum 10 characters long and unique for every students.\n");
    printf(" -> Student Name can be maximum 20 characters long.\n");
    printf(" -> Student Email can be maximum 30 characters long and unique for every students.\n");
    printf(" -> Student Phone can be maximum 20 characters long and unique for every students.\n\n");

    printf(" ->> visit https://sites.google.com/view/codingwill/home for more project like this. <<-\n\n");
}

void DeleteAllStudents()
{
    TotalStudents = 0;
    printf(" All Students Deleted Successfully.\n\n");
    GoBackOrExit();
}

void ShowAllStudents()
{
    printf("|==========|====================|==============================|====================|\n");
    printf("|    ID    |        Name        |            Email             |       Phone        |\n");
    printf("|==========|====================|==============================|====================|\n");

    for (i = 0; i < TotalStudents; i++)
    {
        printf("|");
        printf("%s", Students[i].ID);
        for (j = 0; j < (10 - strlen(Students[i].ID)); j++)
        {
            printf(" ");
        }
        printf("|");
        printf("%s", Students[i].Name);
        for (j = 0; j < (20 - strlen(Students[i].Name)); j++)
        {
            printf(" ");
        }
        printf("|");
        printf("%s", Students[i].Email);
        for (j = 0; j < (30 - strlen(Students[i].Email)); j++)
        {
            printf(" ");
        }
        printf("|");
        printf("%s", Students[i].Phone);
        for (j = 0; j < (20 - strlen(Students[i].Phone)); j++)
        {
            printf(" ");
        }
        printf("|\n");
        printf("|----------|--------------------|------------------------------|--------------------|\n");
    }
    printf("\n");
}

void AddNewStudent()
{
    char StudentID[300];
    char Name[300];
    char Phone[300];
    char Email[300];

    int IsValidID = 0;
    while (!IsValidID)
    {
        printf(" Enter The ID: ");
        scanf("%s", &StudentID);
        // if(IsAlreadyExists(StudentID,'i',StudentID) > 0)
        // {
        //     printf(" Error: This ID is already exists.\n\n");
        //     IsValidID = 0;
        // }
        // else if(strlen(StudentID) > 10)
        // {
        //     printf(" Error: ID can not be more than 10 characters.\n\n");
        //     IsValidID = 0;
        // }
        // else if(strlen(StudentID) <= 0)
        // {
        //     printf(" Error: ID can not be empty.\n\n");
        //     IsValidID = 0;
        // }
        // else
        // {
        IsValidID = 1;
        // }
    }

    int IsValidName = 0;
    while (!IsValidName)
    {
        printf(" Enter The Name: ");
        scanf(" %[^\n]s", &Name);
        // if(strlen(Name) > 20)
        // {
        //     printf(" Error: Name can not be more than 20 characters.\n\n");
        //     IsValidName = 0;
        // }
        // if(strlen(Name) <= 0)
        // {
        //     printf(" Error: Name can not be empty.\n\n");
        //     IsValidName = 0;
        // }
        // else
        // {
        IsValidName = 1;
        // }
    }

    int IsValidEmail = 0;
    while (!IsValidEmail)
    {
        printf(" Enter The Email: ");
        scanf("%s", &Email);
        // if(IsAlreadyExists(Email,'e',StudentID) > 0)
        // {
        //     printf(" This Email is Already Exists.\n");
        //     IsValidEmail = 0;
        // }
        // else if(strlen(Email) > 30)
        // {
        //     printf(" Error: Email can not be more than 30 characters.\n\n");
        //     IsValidEmail = 0;
        // }
        // else if(strlen(Email) <= 0)
        // {
        //     printf(" Error: Email can not be empty.\n\n");
        //     IsValidEmail = 0;
        // }
        // else
        // {
        IsValidEmail = 1;
        // }
    }

    int IsValidPhone = 0;
    while (!IsValidPhone)
    {
        printf(" Enter The Phone: ");
        scanf("%s", &Phone);
        // if(IsAlreadyExists(Phone,'p',StudentID) > 0)
        // {
        //     printf(" This Phone Number is Already Exists\n");
        //     IsValidPhone = 0;
        // }
        // else if(strlen(Phone) > 20)
        // {
        //     printf(" Error: Phone can not be more than 20 characters.\n\n");
        //     IsValidPhone = 0;
        // }
        // else if(strlen(Phone) <= 0)
        // {
        //     printf(" Error: Phone can not be empty.\n\n");
        //     IsValidPhone = 0;
        // }
        // else
        // {
        IsValidPhone = 1;
        // }
    }

    strcpy(Students[TotalStudents].ID, StudentID);
    strcpy(Students[TotalStudents].Name, Name);
    strcpy(Students[TotalStudents].Phone, Phone);
    strcpy(Students[TotalStudents].Email, Email);
    TotalStudents++;

    printf("\n Student Added Successfully.\n\n");
}

int SearchStudent(char StudentID[10])
{
    system("cls");
    int StudentFoundIndex = -1;

    int i;
    for (i = 0; i < TotalStudents; i++)
    {
        if (strcmp(StudentID, Students[i].ID) == 0)
        {
            StudentFoundIndex = i;
            printf("\n One Student Found for ID: %s\n\n", StudentID);
            printf(" Student Informations\n");
            printf("-------------------------\n");

            printf(" ID:    %s\n", Students[i].ID);
            printf(" Name:  %s\n", Students[i].Name);
            printf(" Email: %s\n", Students[i].Email);
            printf(" Phone: %s\n", Students[i].Phone);
        }
    }

    return StudentFoundIndex;
}

// void DeleteStudentByIndex(int StudentIndex)
// {
//     int s;
//     for(s=0; s<TotalStudents-1; s++)
//     {
//         if(s>=StudentIndex)
//         {
//             Students[s] = Students[s+1];
//         }
//     }
//     TotalStudents--;
// }

void DeleteStudent(int StudentIndex)
{
    int s;
    for (s = 0; s < TotalStudents - 1; s++)
    {
        if (s >= StudentIndex)
        {
            Students[s] = Students[s + 1];
        }
    }
    TotalStudents--;
    printf(" Student Deleted Successfully.\n\n");
    GoBackOrExit();
}

void EditStudent(int StudentFoundIndex)
{
    printf("\n\t\t **** Update The New Student ****\n\n");

    char NewName[300];
    char NewPhone[300];
    char NewEmail[300];
    char StudentID[300];
    strcpy(StudentID, Students[StudentFoundIndex].ID);

    int IsValidName = 0;
    while (!IsValidName)
    {
        printf(" Enter The New Name(0 for skip): ");
        scanf(" %[^\n]s", &NewName);
        // if(strlen(NewName) > 20)
        // {
        //     printf(" Error: Name can not be more than 20 characters.\n\n");
        //     IsValidName = 0;
        // }
        // else if(strlen(NewName) <= 0)
        // {
        //     printf(" Error: Name can not be empty.\n\n");
        //     IsValidName = 0;
        // }
        // else
        // {
        IsValidName = 1;
        // }
    }

    int IsValidEmail = 0;
    while (!IsValidEmail)
    {
        printf(" Enter The New Email(0 for skip): ");
        scanf("%s", &NewEmail);

        // if(strlen(NewEmail) > 30)
        // {
        //     printf(" Error: Email can not be more than 30 characters.\n\n");
        //     IsValidEmail = 0;
        // }
        // else if(strlen(NewEmail) <= 0)
        // {
        //     printf(" Error: Email can not be empty.\n\n");
        //     IsValidEmail = 0;
        // }
        // else if(IsAlreadyExists(NewEmail,'e',StudentID) > 0)
        // {
        //     printf(" Error: This Email Already Exists.\n\n");
        //     IsValidEmail = 0;
        // }
        // else
        // {
        IsValidEmail = 1;
        // }
    }

    int IsValidPhone = 0;
    while (!IsValidPhone)
    {
        printf(" Enter The New Phone(0 for skip): ");
        scanf("%s", &NewPhone);

        // if (strlen(NewPhone) > 20)
        // {
        //     printf(" Error: Phone can not be more than 20 characters.\n\n");
        //     IsValidPhone = 0;
        // }
        // else if (strlen(NewPhone) <= 0)
        // {
        //     printf(" Error: Phone can not be empty.\n\n");
        //     IsValidPhone = 0;
        // }
        // else if (IsAlreadyExists(NewPhone, 'p', StudentID) > 0)
        // {
        //     printf(" Error: This Phone Number is Already Exists.\n\n");
        //     IsValidPhone = 0;
        // }
        // else
        // {
            IsValidPhone = 1;
        // }
    }

    if (strcmp(NewName, "0") != 0)
    {
        strcpy(Students[StudentFoundIndex].Name, NewName);
    }

    if (strcmp(NewEmail, "0") != 0)
    {
        strcpy(Students[StudentFoundIndex].Email, NewEmail);
    }

    if (strcmp(NewPhone, "0") != 0)
    {
        strcpy(Students[StudentFoundIndex].Phone, NewPhone);
    }

    printf(" Student Updated Successfully.\n\n");
}