#include <stdio.h>
#include <stdint.h>

int count_word(char* text){
    int number_of_didgits = 0;
           
    for (int sign = 0; *(text + sign) != '\0'; sign++){
        if ( *(text + sign) == ' ' || *(text + sign) == '\t'){
            ++number_of_didgits;
        }
    }

    ++number_of_didgits;

    return number_of_didgits;
}

int count_sym (char* text, int16_t* mas_pointer){
    int esp = 1;

    for (int i = 0; *(text + i) != '\0'; i++){
        if (*(text + i + 1) == ' ' 
                || *(text + i + 1) == '\t' 
                || *(text + i + 1) == '\0'){
            *mas_pointer = esp;
            esp = 0;
            ++mas_pointer;
            i++;
        }
            esp += 1;
    }

}

int main () {
    char my_string[] = "Hello World!";
    int word_counter = count_word(&my_string[0]);
    int16_t words_sym_counter[word_counter + 1];

    count_sym(&my_string[0], &words_sym_counter[0]);

    for (int i = 0; i < word_counter; i++){
        printf("%d ", words_sym_counter[i]);
    }
    printf("%d\n", word_counter);

    return 0;
}
