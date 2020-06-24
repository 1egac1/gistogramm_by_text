#include <stdio.h>
#include <stdint.h>

int count_word(char* text){
    int number_of_didgits = 0;
           
    for (int sign = 0; text[sign] != '\0'; sign++){
        if (text[sign] == ' ' || text[sign] == '\t'){
            ++number_of_didgits;
        }
    }

    ++number_of_didgits;

    return number_of_didgits;
}

int count_sym (char* text, int16_t* mas_pointer){
   int esp = 0;
   int eip = 0;

   while (text[esp] != '\0'){
       while (text[esp] != ' ' ||
               text[esp] != '\t' ||
               text[esp] != '\0'){
           esp++; 
       }
       eip += 2;
   }
}

int main () {
    char my_string[200];

    scanf("%s", my_string);

    int word_counter = count_word(my_string);
    int16_t words_sym_counter[word_counter];

    count_sym(&my_string[0], &words_sym_counter[0]);

    for (int i = 0; i < word_counter; i++){
        printf("%d ", words_sym_counter[i]);
    }

    return 0;
}
