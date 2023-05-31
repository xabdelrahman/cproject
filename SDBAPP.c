#include <stdio.h>
#include "SDB.h"

void SDB_action(uint8 choice)
{
    switch (choice)
    {
        case 1:
            if (SDB_AddEntry())
            {
                printf("Student data added successfully.\n");
            }
            else
            {
                printf("Failed to add student data. Database is full.\n");
            }
            break;
        case 2:
            printf("Number of students in the database: %u\n", SDB_GetUsedSize());
            break;
        case 3:
            {
                uint32 id;
                printf("Enter student ID: ");
                scanf("%u", &id);
                if (SDB_ReadEntry(id))
                {
                    printf("Student data found!\n");
                }
                else
                {
                    printf("Student data not found!\n");
                }
            }
            break;
        case 4:
            {
                uint8 count = 0;
                uint32 list[MAX_DATABASE_SIZE];
                SDB_GetList(&count, list);
                printf("List of student IDs:\n");
                for (uint8 i = 0; i < count; i++)
                {
                    printf("%u\n", list[i]);
                }
            }
            break;
        case 5:
            {
                uint32 id;
                printf("Enter student ID: ");
                scanf("%u", &id);
                if (SDB_IsIdExist(id))
                {
                    printf("ID exists in the database!\n");
                }
                else
                {
                    printf("ID does not exist in the database!\n");
                }
            }
            break;
        case 6:
            {
                uint32 id;
                printf("Enter student ID to delete: ");
                scanf("%u", &id);
                SDB_DeletEntry(id); 
            }
            break;
        case 7:
            if (SDB_IsFull())
            {
                printf("Database is full!\n");
            }
            else
            {
                printf("Database is not full!\n");
            }
            break;
        case 0:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice! Please try again.\n");
            break;
    }
}

void SDB_APP()
{
    uint8 choice;
    bool exit = false;
    
    while (!exit)
    {
        printf("\nPlease choose an option:\n");
        printf("1. Add entry\n");
        printf("2. Get used size in database\n");
        printf("3. Read student data\n");
        printf("4. Get the list of all student IDs\n");
        printf("5. Check if ID exists\n");
        printf("6. Delete student data\n");
        printf("7. Check if database is full\n");
        printf("0. Exit\n");
        
        scanf("%hhu", &choice);
        
        if (choice == 0)
        {
            exit = true;
        }
        else
        {
            SDB_action(choice);
        }
    }
}

int main()
{
    SDB_APP();
    return 0;
}
