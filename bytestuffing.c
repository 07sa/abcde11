#include <stdio.h>
#include <string.h>

char data[100];     // to store data entered by user
char prepData[400]; // to store data to be transmitted from sender to receiver

char flag[8] = {'0', '1', '1', '1', '1', '1', '1', '0'};
char esc[6] = {'1', '1', '0', '1', '1'};

int i = 0; // for tracking each bit of data
int j = 0; // for keeping track of prepData

// Function to check if data segment is flag
int isFlag(char data[], int i)
{
    int count = 0;
    for (int k = 0; k < 8; k++)
    {
        if (data[i + k] == flag[k])
        {
            count++;
        }
    }
    if (count == 8)
    {
        return 1; // It's a flag
    }
    return 0; // It's not a flag
}

// Function to check if data segment is esc
int isEsc(char data[], int i)
{
    int count = 0;
    for (int k = 0; k < 5; k++)
    {
        if (data[i + k] == esc[k])
        {
            count++;
        }
    }
    if (count == 5)
    {
        return 1; // It's an esc
    }
    return 0; // It's not an esc
}

void sender()
{
    // take data from user
    printf("Enter the data: ");
    scanf("%s", data);

    i = 0;
    j = 0;
    int len = strlen(data);

    while (i < len)
    {
        if (isFlag(data, i) == 1)
        {
            // Appending esc
            for (int k = 0; k < 5; k++)
            {
                prepData[j++] = esc[k];
            }
            // Appending flag
            for (int k = 0; k < 8; k++)
            {
                prepData[j++] = flag[k];
            }
            i += 8; // Move i past the flag
        }
        else if (isEsc(data, i) == 1)
        {
            // Appending esc
            for (int k = 0; k < 5; k++)
            {
                prepData[j++] = esc[k];
            }
            // Appending esc
            for (int k = 0; k < 5; k++)
            {
                prepData[j++] = esc[k];
            }
            i += 5; // Move i past the esc
        }
        else
        {
            prepData[j++] = data[i++];
        }
    }
    prepData[j] = '\0'; // Null-terminate prepData

    printf("\nEntered Data: %s", data);
    printf("\nPrepared Data: %s\n", prepData);
}

int main()
{
    sender();
    return 0;
}
