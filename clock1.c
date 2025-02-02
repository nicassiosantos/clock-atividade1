#include <stdio.h>
#include "pico/stdlib.h" // Biblioteca padrão do Raspberry Pi Pico para GPIO, temporização e E/S.
#include "pico/time.h"   // Biblioteca para gerenciamento de tempo e temporizadores.

// Definição dos pinos GPIO usados para os LEDs
#define LED_R 13 // LED vermelho
#define LED_B 12 // LED azul
#define LED_G 11 // LED verde

// Variável global volátil para controlar a mudança de cores dos LEDs
uint volatile cont = 2;

// Função de callback chamada repetidamente pelo temporizador
// Retorna `true` para continuar repetindo a chamada
bool repeating_timer_callback(struct repeating_timer *t) { 
    if (cont == 1) {
        // Acende o LED vermelho e apaga os outros
        gpio_put(LED_R, 1);
        gpio_put(LED_G, 0);
        gpio_put(LED_B, 0);
        cont = 2; // Muda o estado para a próxima cor
    } else if (cont == 2) {
        // Acende o LED azul e apaga os outros
        gpio_put(LED_R, 0);
        gpio_put(LED_G, 0);
        gpio_put(LED_B, 1);
        cont = 3; // Muda o estado para a próxima cor
    } else if (cont == 3) {
        // Acende o LED verde e apaga os outros
        gpio_put(LED_R, 0);
        gpio_put(LED_G, 1);
        gpio_put(LED_B, 0);
        cont = 1; // Volta ao primeiro estado
    }

    return true; // Mantém o temporizador ativo
}

int main() {
    uint contador = 0; // Variável para contar segundos passados
    stdio_init_all();  // Inicializa a comunicação serial

    // Configuração dos pinos GPIO como saída e inicialização dos LEDs
    gpio_init(LED_R);
    gpio_set_dir(LED_R, GPIO_OUT);
    gpio_put(LED_R, 1); // Começa com o LED vermelho aceso

    gpio_init(LED_B);
    gpio_set_dir(LED_B, GPIO_OUT);
    gpio_put(LED_B, 0); // LED azul apagado

    gpio_init(LED_G);
    gpio_set_dir(LED_G, GPIO_OUT);
    gpio_put(LED_G, 0); // LED verde apagado

    struct repeating_timer timer;

    // Configura um temporizador que chama a função de callback a cada 3 segundos
    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer);

    // Loop infinito para manter o programa rodando
    while (true) {
        if (contador == 3) {
            contador = 0; // Reinicia a contagem após 3 segundos
        }
        sleep_ms(1000); // Aguarda 1 segundo
        contador++; // Incrementa o contador de segundos
        printf("Passou se %d segundo(s)\n", contador); // Imprime no terminal
    }
}
