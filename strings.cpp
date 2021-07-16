#include <stdio.h>
#include <stdlib.h>

#define LEN 100

void gets(char * str)
{
    for (int i = 0; i < LEN-1; i++)
    {
        str[i] = getchar();
        if (str[i] == '\n')
        {
            str[i] = '\0';
            break;
        }
    }
}

int slen(char* str)
{
    int len = 0, i = 0;
    while (str[i] != '\0')
    {
        len++;
        i++;
    }
    return len;
}
//5.1
int c_counter(char str[]) 
{
    int counter = 0, i = 0;
    while(str[i] != '\0')
    {
        if (str[i] == 'c')
            counter++;
        i++;
    }
    return counter;
}
//5.2
void b_to_a(char* str) 
{
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] == 'A')
            str[i] = 'B';
        i++;
    }
}
//5.3
void smirror(char* str) 
{
    int tmp, size = slen(str);
    for(int i = 0; i < size - i - 1; i++)
    {
        tmp = str[i];
        str[i] = str[size - i - 1];
        str[size - i - 1] = tmp;
    }
}
//5.4
void palindr(char* str) 
{
    int size = slen(str), count = 0;
    for (int i = 0; i < size - i - 1; i++)
    {
        if (str[i] != str[size - i - 1])
            count++;
    }
    if (count == 0)
        printf("Palindrome\n");
    else
        printf("No palindrome\n");
}
//5.5
void _delete(char* str) 
{
    int size = slen(str);
    for (int i = 0; i < size; i++)
    {
        if (str[i] == ' ')
        {
            for (int j = i; j < size; j++)
                str[j] = str[j + 1];
        }
    }
}
//5.6
void extra_delete(char* str) 
{
    int size = slen(str);
    for (int i = 0; i < size; i++)
    {
        if (str[i] == ' ')
        {
            while (str[i + 1] == ' ')
            {
                for (int j = i + 1; j < size; j++)
                    str[j] = str[j + 1];
            }
        }
    }
}

int count_words(char* str) 
{
    int size = slen(str), count = 0;
    for (int i = 0; i < size; i++)
    {
        if ((str[i + 1] == ' ') || (str[i + 1] == '\0'))
            count++;
    }
    return count;
}
//5.7
char** words(char* str) 
{
    int len = slen(str);
    int wcount = count_words(str);
    int count = 0;
    char** word = (char**)calloc(wcount, sizeof(char*));
    for (int i = 0; i < wcount; i++)
    {
        word[i] = (char*)calloc(len + 1, sizeof(char));
        for (int j = 0; j < len; j++)
        {
            if ((str[count] == ' ') || (str[count] == '\0'))
            {
                word[i][j] = '\0';
                count++;
                break;
            }
            else
            {
                word[i][j] = str[count];
                count++;
            }
        }
    }
    return word;
}
//5.8
bool scmp_symb(char* str, char* str1) 
{
    int i = 0, count = 0;
    while ((str[i] != '\0') || (str1[i] != '\0'))
    {
        if (str[i] != str1[i])
        {
            count++;
            break;
        }
        else
            i++;
    }
    if (count == 0)
        return true;
    else
        return false;
}
//5.9
char* abc(char** wA, int cwA, char** wB, int cwB) 
{
    int count = 0;
    char* C = (char*)calloc(LEN, sizeof(char));
    for (int i = 0; i < cwA; i++)
    {
        for (int j = 0; j < cwB; j++)
        {
            if (scmp_symb(wA[i],wB[j]) == true)
            {
                for (int k = 0; k <= slen(wA[i]); k++)
                {
                    if (wA[i][k] == '\0')
                    {
                        C[count] = ' ';
                        count++;
                        break;
                    }
                    else
                    {
                        C[count] = wA[i][k];
                        count++;
                    }
                }
            }
        }
    }
    C[slen(C)] = '\0';
    return C;
}
//5.10
int toInt(char* ints) 
{
    int result = 0;
    int sign = 1;
    while (((*ints) == '-') || ((*ints) == '+'))
    {
        if (*ints == '-')
            sign = sign * (-1);
        ints++;
    }
    while ((*ints >= '0') && (*ints <= '9'))
    {
        result = (result * 10) + ((*ints) - '0');
        ints++;
    }
    return (result * sign);
}
//5.11
float toFloat(char* floats) 
{
    float result = 0, fact = 1;
    if ((*floats) == '-') 
    {
        floats++;
        fact = -1;
    };
    for (int point_seen = 0; *floats; floats++) 
    {
        if (*floats == '.') 
        {
            point_seen = 1;
            continue;
        };
        int d = *floats - '0';
        if (d >= 0 && d <= 9) {
            if (point_seen) fact /= 10.0f;
            result = result * 10.0f + (float)d;
        };
    };
    return (result * fact);
}
//5.12
int soccur(char* str1, char* str2) 
{
    int k, count = 0;
    for (int i = 0; i < slen(str1); i++)
    {
        char tmp[LEN] = "";
        k = 0;
        if (str1[i] == str2[0])
        {
            int j = i;
            while (str1[j] == str2[k])
            {
                tmp[k] = str1[j];
                j++; 
                k++;
            }
            if (scmp_symb(str2,tmp))
                count++;
        }
    }
    return count;
}
//5.13
char** smatrix(int n) 
{
    char** matr = (char**)calloc(n, sizeof(char*));
    for (int i = 0; i < n; i++)
    {
        matr[i] = (char*)calloc(LEN, sizeof(char));
        gets(matr[i]);
    }
    return matr;
}
//5.14
void scmp_size(char* str, char* str1)
{
    if (slen(str) == slen(str1))
        printf("The lenghts of two strs are equal!\n");
    else if (slen(str) > slen(str1))
        printf("The first str is longer!\n");
    else if (slen(str) < slen(str1))
        printf("The second str is longer!\n");
}
//5.15
void smSort(char** matr, int n) 
{
    for (int i = 0; i < n - 1; i++)
    {
        if (slen(matr[i]) > slen(matr[i + 1]))
        {
            char* tmp = matr[i];
            matr[i] = matr[i + 1];
            matr[i + 1] = tmp;
        }
    }
}

int main()
{
    char str[LEN], str1[LEN];
    printf("Enter your str: ");
    gets(str);
    printf("Your str lenght: %d\n", slen(str));
    //5.1 тест
    printf("There're %d 'c' in your str", c_counter(str));
    //5.2 тест
    b_to_a(str);
    //5.3 тест
    smirror(str);
    //5.4 тест
    palindr(str);
    //5.5 тест
    _delete(str);
    //5.6 тест
    extra_delete(str);

    printf("Your new str: ");
    puts(str);

    //5.7 тест
    char** word = words(str);
    printf("Words:\n");
    for (int i = 0; i < count_words(str); i++)
        puts(word[i]);
    for (int i = 0; i < count_words(str); i++)
        free(word[i]);
    free(word);
    //5.8 тест
    printf("Enter the second str to compare: ");
    gets(str1);
    scmp_size(str, str1); //5.14 тест
    if (scmp_symb(str, str1) == true)
        printf("Strs are equal!\n");
    else
        printf("Strs aren't equal!\n");
    //5.9 тест
    char A[LEN], B[LEN];
    printf("\nEnter A: ");
    gets(A);
    printf("Enter B: ");
    gets(B);
    char** wA = words(A);
    char** wB = words(B);
    int cwA = count_words(A), cwB = count_words(B);
    char* C = abc(wA, cwA, wB, cwB);
    puts(C);
    for (int i = 0; i < cwA; i++)
        free(wA[i]);
    free(wA);
    for (int i = 0; i < cwB; i++)
        free(wB[i]);
    free(wB);
    free(C);
    //5.10 тест
    char ints[LEN];
    printf("Enter the number: ");
    gets(ints);
    printf("Your number is %d", toInt(ints));
    //5.11 тест
    char floats[LEN];
    printf("Enter the number: ");
    gets(floats);
    printf("Your number is %f", toFloat(floats));
    //5.12 тест
    char str2[LEN], str3[LEN];
    printf("Enter str1 to count occurences in: ");
    gets(str2);
    printf("Enter str2 to count occurences of: ");
    gets(str3);
    printf("str2 occurs %d times in str1\n", soccur(str2,str3));
    //5.13 тест
    int n;
    printf("Enter the number of rows: ");
    scanf_s("%d", &n);
    getchar();
    char** matr = smatrix(n);
    smSort(matr, n); //5.15 тест
    printf("Your matrix:\n");
    for (int i = 0; i < n; i++)
        puts(matr[i]);
    for (int i = 0; i < n; i++)
        free(matr[i]);
    free(matr);
}