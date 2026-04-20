#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

string encrypt (string, string);
int argv_checker(int ,string);

int main(int argc,  char *argv[])
{
    if (argc !=2){
        printf("Usaage: ./substitute key\n");
        return 1;
    }
    
    int checker = argv_checker(argc, argv[1]);
    if (checker != 0){
        return checker;
    }
    string plaintext = get_string("plaintext: ");
    string encrypted = encrypt(argv[1], plaintext);
    printf("%s\n", encrypted);
    return 0;
}

int argv_checker(int length, string key)
{

    if (strlen(key)!= 26){
        printf("Type 26 unique letters\n");
        return 1;
    }
    for (int i = 0, n = strlen(key); i < n ; i++)
    {
        if (!isalpha(key[i]))
        {
       
            printf("Type 26 unique letters\n");
            return 1;
        }
        for (int j = i +1 ; j < n; j++)
        {
            if (tolower(key[i]) == tolower(key[j]))
            {
                return 1;
            }
            
        }
        
    }
    
    return 0;
}

string encrypt(string key, string sentence)
{
    for (int i = 0, n = strlen(sentence); i < n; i++)
    {
        if (isupper(sentence[i]))
        {
            sentence[i] = toupper(key[sentence[i] - 'A']);
        }
        else if (islower(sentence[i]))
        {
            sentence[i] = tolower(key[sentence[i] - 'a']);
        }
    }
    return sentence;
}