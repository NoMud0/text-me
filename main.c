#include <stdio.h>
#include <malloc.h>

char *copyToken(char *string, int pointer, int size)
{
    if(size != 0)
    {
        char *temparray = malloc((size + 1) * sizeof(char));
        if(temparray == NULL)
        {
            printf("Failed to allocate memory\n");
            return NULL;
        }
        for(int j = 0; j < size; j++)
        {
            temparray[j] = string[pointer + j];
        }
        temparray[size] = '\0'; // add null terminator
        return temparray;
    }
}

char *csplit(char string[])
{
    int i = 0;
    int tokenTrue = 0;
    int nPointer = 0;
    int nSize = 0;
    while(string[i])
    {
        if(string[i] != ' ') // if it is a char
        {
            if(i == nPointer + nSize)
            {
                nSize++;
            }
            else
            {
                nPointer = i;
                nSize = 1;
            }
            tokenTrue = 1;
        }
        else // if it is a space TODO
        {
            if(tokenTrue == 1)
            {
                char *Token = copyToken(string, nPointer, nSize);
                return Token;
            }
        }
        i++;
    }
    if(tokenTrue == 1)
    {
        char *Token = copyToken(string, nPointer, nSize);
        return Token;
    }
    return NULL;
}


int main()
{
    char string[] = "   hello   ";
    char *array = csplit(string);
    printf("%s\n", array);
    //test for each character in the array
    /*for(int i = 0; i < 6 ;i++)
    {
        printf("%d\n", array[i]);
    }
    */
    free(array);
    return 0;
}
