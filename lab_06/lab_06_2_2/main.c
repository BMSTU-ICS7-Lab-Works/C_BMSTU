#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 256

void swap(char **a, char **b)
{
    char *t = *a;
    *a = *b;
    *b = t;
}


int is_separator(const char c)
{
    const char str_separator[8] = { ' ', ',', ';', ':', '-', '.', '!', '?' };
    for (int i = 0; i < 8; ++i)
    {
        if (c == str_separator[i])
        {
            return 1;
        }
    }
    return 0;
}

void read_str(char *const data, char **starts, int *const count_words)
{
    int position = 0;
    char c = getchar();
    int is_prev_sep = 1;
    while (c != '\n' && c != EOF)
    {
        data[position] = c;
        if (is_separator(c))
        {
            is_prev_sep = 1;
            data[position] = '\0';
        }
        else
        {
            if (is_prev_sep)
            {
                is_prev_sep = 0;
                starts[(*count_words)++] = &data[position];
            }
        }
        position++;
        c = getchar();
    }
    data[position] = '\0';
}

void make_unique(char **starts, int *const count_words)
{
    for (int i = 0; i < *count_words; ++i)
    {
        for (int j = i + 1; j < *count_words; ++j)
        {
            if (strcmp(starts[i], starts[j]) == 0)
            {
                swap(&starts[j], &starts[(*count_words) - 1]);
                (*count_words)--;
                j--;
            }
        }
    }
}

void print_ans(char *const *starts, char *const *starts1, const int count_words, const int count_words1)
{
    int flag = 1;
    printf("Result:");
    for (int i = 0; i < count_words; ++i)
    {
        for (int j = 0; j < count_words1; j++)
        {
            if (strcmp(starts[i], starts1[j]) == 0)
            {
                printf("%s yes \n", starts[i]);
                flag = 0;
            }
        }
        if (flag == 1)
            printf("%s no \n", starts[i]);
        flag = 1;
    }
}


int main()
{
    char data[MAX_LENGTH + 1];
    char data1[MAX_LENGTH + 1];
    char *starts[MAX_LENGTH];
    char *starts1[MAX_LENGTH];
    int count_words = 0;
    int count_words1 = 0;
    read_str(data, starts, &count_words);
    if (count_words == 0)
    {
        printf("Only separators.\n");
        return -1;
    }
    read_str(data1, starts1, &count_words1);
    if (count_words1 == 0)
    {
        printf("Only separators.\n");
        return -1;
    }
    make_unique(starts, &count_words);
    make_unique(starts1, &count_words1);
    print_ans(starts, starts1, count_words, count_words1);
    return 0;
}
