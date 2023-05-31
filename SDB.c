#include "SDB.h"

student database[MAX_DATABASE_SIZE];
uint8 usedSize = 0;

bool SDB_IsFull()
{
    return usedSize == MAX_DATABASE_SIZE;
}

uint8 SDB_GetUsedSize()
{
    return usedSize;
}

bool SDB_AddEntry()
{
    if (SDB_IsFull())
    {
        return false;
    }
    
    student newStudent;
    
    printf("Enter student ID: ");
    scanf("%u", &newStudent.Student_ID);
    
    // Add code here to get the remaining data from the user
    
    database[usedSize++] = newStudent;
    
    return true;
}

void SDB_DeletEntry(uint32 id)
{
    for (uint8 i = 0; i < usedSize; i++)
    {
        if (database[i].Student_ID == id)
        {
            for (uint8 j = i; j < usedSize - 1; j++)
            {
                database[j] = database[j + 1];
            }
            
            usedSize--;
            printf("Student data with ID %u deleted.\n", id);
            return;
        }
    }
    
    printf("Student data with ID %u not found.\n", id);
}

bool SDB_ReadEntry(uint32 id)
{
    for (uint8 i = 0; i < usedSize; i++)
    {
        if (database[i].Student_ID == id)
        {
            printf("Student ID: %u\n", database[i].Student_ID);
            // Print the remaining data
            return true;
        }
    }
    
    return false;
}

void SDB_GetList(uint8* count, uint32* list)
{
    *count = usedSize;
    
    for (uint8 i = 0; i < usedSize; i++)
    {
        list[i] = database[i].Student_ID;
    }
}

bool SDB_IsIdExist(uint32 id)
{
    for (uint8 i = 0; i < usedSize; i++)
    {
        if (database[i].Student_ID == id)
        {
            return true;
        }
    }
    
    return false;
}

