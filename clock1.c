#include <stdio.h>
#include "pico/stdlib.h" // Biblioteca padrão para funcionalidades básicas como GPIO, temporização e E/S.
#include "pico/time.h"   // Biblioteca para gerenciamento de tempo, como manipulação de temporizadores e atrasos.

#define LED_R 13 //Definição da GPIO de saída
#define LED_B 12 //Definição da GPIO de saída
#define LED_G 11 //Definição da GPIO de saída

uint volatile cont = 2;

// Função de callback que será chamada repetidamente pelo temporizador
// O tipo bool indica que a função deve retornar verdadeiro ou falso para continuar ou parar o temporizador.
bool repeating_timer_callback(struct repeating_timer *t) { 
    if(cont == 1){
        gpio_put(LED_R, 1);
        gpio_put(LED_G, 0);
        gpio_put(LED_B, 0);
        cont = 2;
    }else if(cont == 2){
        gpio_put(LED_R, 0);
        gpio_put(LED_G, 0);
        gpio_put(LED_B, 1);
        cont = 3;
    }else if(cont == 3){
        gpio_put(LED_R, 0);
        gpio_put(LED_G, 1);
        gpio_put(LED_B, 0);
        cont = 1;
    }

    return true;
}

int main() {
    uint contador = 0;
    stdio_init_all(); // Inicializa a comunicação serial

    // Inicializar os pinos
    gpio_init(LED_R);              
    gpio_set_dir(LED_R, GPIO_OUT); 
    gpio_put(LED_R, 1);       

    gpio_init(LED_B);              
    gpio_set_dir(LED_B, GPIO_OUT); 
    gpio_put(LED_B, 0); 

    gpio_init(LED_G);              
    gpio_set_dir(LED_G, GPIO_OUT); 
    gpio_put(LED_G, 0); 

    struct repeating_timer timer;

    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer);

    // Loop infinito que mantém o programa em execução contínua.
    while (true) {
        if(contador == 3){
            contador = 0;
        }
        sleep_ms(1000);
        contador++;
        printf("Passou se %d segundo(s)\n", contador);
    }
}