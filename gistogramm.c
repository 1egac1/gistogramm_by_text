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

int biggest(int word_cnt, int16_t *in_every_word){
    int bigest = 0;

    for (int i = 1; i < word_cnt; i++){
        if (*in_every_word > *(in_every_word - 1)){
            bigest = i;
        }
    }

    return bigest;
}

int is_nothing(int16_t *in_every_word, int word_cnt){
    for (int i = 0; i < word_cnt; i++){
        if (*(in_every_word + i) != 0)
            return 0;
    }

    return 1;
}

void gistogramm_drawing(int word_cnt, int16_t *in_every_word){
    int16_t massive[word_cnt + 1];
    for (int i = 0; i < word_cnt; i++){
        massive[i] = *(in_every_word + i);
    }

    int biggest_1 = biggest(word_cnt, &massive[0]);

    while (is_nothing(&massive[0], word_cnt) != 1){
        biggest_1 = biggest(word_cnt, &massive[0]);
        for(int i = 0; i < word_cnt; i++){
            if (massive[i] == massive[biggest_1]){
                printf("# ");
                massive[i]--;
            }else{
                printf("  ");
            }
        }
        putchar('\n');
    }
}

int main () {
    char my_string[200];
    fgets(my_string, 199, stdin);

    int word_counter = count_word(&my_string[0]);
    int16_t words_sym_counter[word_counter + 1];

    count_sym(&my_string[0], &words_sym_counter[0]);

//    for (int i = 0; i < word_counter; i++){
//        printf("%d ", words_sym_counter[i]);
//    }
//    printf("%d\n", word_counter);
    gistogramm_drawing(word_counter, &words_sym_counter[0]);

    return 0;
}
