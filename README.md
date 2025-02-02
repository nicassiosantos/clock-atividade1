# Controle de LEDs com Temporizador no Raspberry Pi Pico

## Descrição
Este projeto implementa um sistema de controle de LEDs utilizando um temporizador repetitivo no Raspberry Pi Pico. Três LEDs (vermelho, azul e verde) são acionados alternadamente a cada 3 segundos, criando um ciclo de troca de cores.

## Funcionalidade
O programa utiliza um temporizador que chama a função `repeating_timer_callback()` a cada 3 segundos para alternar entre os LEDs. Além disso, um contador exibe no terminal a passagem de tempo em segundos.

## 🛠️ Tecnologias Utilizadas

- *Linguagem de Programação*: C.
- *Placas Microcontroladoras*:
  - BitDogLab.
  - Pico w.
- *Ferramentas*:
  - Wokwi.

## Esquemático de Conexão
| LED | GPIO |
|------|------|
| Vermelho | 13 |
| Azul | 12 |
| Verde | 11 |

Cada LED deve estar em série com um resistor e conectado ao respectivo pino GPIO do Raspberry Pi Pico.

## Como Funciona
1. O programa inicializa os pinos GPIO e define seus estados iniciais.
2. Um temporizador é configurado para chamar a função `repeating_timer_callback()` a cada 3 segundos.
3. A função `repeating_timer_callback()` alterna a cor do LED ligado, seguindo a ordem:
   - Vermelho (13) -> Azul (12) -> Verde (11) -> Vermelho ...
4. Um loop infinito imprime no terminal a contagem de segundos.

## Saída Esperada
No terminal, serão exibidas mensagens indicando a passagem do tempo:
```
Passou se 1 segundo(s)
Passou se 2 segundo(s)
Passou se 3 segundo(s)
Passou se 1 segundo(s)
...
```
Enquanto isso, os LEDs mudarão de cor a cada 3 segundos.

## 🗂️ Estrutura do Repositório

- `clock1.c`: Código-fonte.
- `README.md`/: Tutoriais e explicações sobre a Documentação do projeto.
- `diagram.jso`n/: Diagramas de conexão e esquemas de hardware.
- 
## Autor
- **[Nicassio Santos.](https://github.com/nicassiosantos)**




