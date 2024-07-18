# Sistema de Controle de Temperatura

## Mudança de Ownership do Repositório

Este repositório foi originalmente criado na conta GitHub associada ao meu email universitário (eduardosiqueiraunicamp). Para fins de portfólio e melhor organização, o repositório foi transferido para a minha conta profissional no GitHub (eduardobonfim98). O projeto foi feito em um grupo de três e tem os seguintes autores:

	•	Eduardo Siqueira Bonfim
	•	Henrique Akira 
	•	Lucas Finzzeto Pavarini 

## Visão Geral

Este projeto visa desenvolver um sistema de controle de temperatura eficiente. O principal objetivo do sistema é controlar a temperatura de um resistor, ajustando-a conforme a temperatura alvo definida pelo usuário. Para atingir essa meta, o sistema manipula a corrente do resistor utilizando um sinal PWM (Pulse Width Modulation) dentro de uma malha de controle. Quando a temperatura desejada é maior do que a atual, o sistema utiliza o aquecedor, quando é menor, utiliza o cooler.

## Hardware

O sistema é constituído por:
- Um microcontrolador NUCLEO-G474RE
- Duas daughterboards
- Um display LCD
- Um teclado matricial (não utilizado)

### Detalhes do Hardware

- **Daughterboard 1**: Fornece alimentação ao microcontrolador.
- **Daughterboard 2**: Contém os elementos de interface com o usuário, além dos componentes de aquecimento e resfriamento. Inclui um buzzer, cinco LEDs, cinco botões, um teclado matricial com 16 teclas, um display LCD 2x16 e uma saída UART.
- **Sistema de Aquecimento**: Composto por um resistor que funciona como aquecedor e uma ventoinha para resfriamento.
- **Sensores**: Dois sensores de temperatura (um digital e um analógico) para monitorar a temperatura do resistor, e um par de fotodiodo e LED utilizado como tacômetro para medir a velocidade de rotação da ventoinha.

### Comunicação

- **I2C**: Utilizado na comunicação entre o microcontrolador e o display LCD.
- **UART**: Utilizado para a comunicação entre o microcontrolador e o computador via USB.

## Software

O software do sistema foi desenvolvido em linguagem C utilizando o ambiente de desenvolvimento CubeIDE. Esse ambiente facilita a configuração de diversas funcionalidades do microcontrolador através de uma interface gráfica, permitindo a nomeação e configuração dos pinos, a configuração dos clocks e dos timers de interrupções. As configurações automáticas geradas pelo CubeIDE simplificam o desenvolvimento do código, que é organizado em módulos e bibliotecas para cada função, facilitando futuras modificações.

### Controle de Temperatura

O controle de temperatura é realizado por um controlador PID que atua sobre a corrente do resistor através de um sinal PWM. A sintonia do controlador PID foi realizada utilizando o método Ziegler-Nichols, com um overshoot máximo definido de 2°C, assegurando precisão e eficiência ao sistema.

## Documentação do Sistema

### Requisitos do Projeto

#### Requisitos Funcionais

1. O sistema deve ser capaz de manter a temperatura do resistor no valor determinado pelo usuário.
2. No momento em que se solta o botão, o buzzer emite um som, independentemente de ser apenas um clique ou de estar segurando o botão.
3. O set point aumenta ou diminui em 1°C quando o botão “up” ou “down” é clicado.
4. O set point aumenta ou diminui em 10°C quando o botão “up” ou “down” é segurado, com incrementos a cada 500ms.
5. O LCD possui três telas distintas. Para mudar de tela, é necessário segurar o botão “enter” por 3 segundos.
    - **Primeira Tela**: Exibe a temperatura atual, a temperatura desejada e a rotação do cooler.
    - **Segunda Tela**: Exibe a temperatura atual, a temperatura desejada, o duty cycle do aquecedor e o duty cycle do cooler.
    - **Terceira Tela**: Exibe os valores de Kp, Ki, Kd.
6. O sistema deverá apresentar um indicador visual das temperaturas utilizando LEDs de cores diferentes para indicar faixas de temperatura:
    - Verde para temperaturas entre 0°C e 40°C.
    - Amarelo para temperaturas entre 40°C e 60°C.
    - Vermelho para temperaturas entre 60°C e 90°C.
   Este indicador deve alterar as cores de acordo com a temperatura atual do resistor, proporcionando um feedback visual imediato sobre o estado de operação do sistema.
7. Implementada funcionalidade de ajuste dos valores de Kp, Ki, Kd via UART.

#### Requisitos Não Funcionais

1. O sistema deve ser capaz de aquecer o resistor o mais rápido possível para atingir a temperatura desejada em um curto período de tempo.
2. O overshoot, ou seja, a quantidade pela qual a temperatura ultrapassa o valor desejado antes de se estabilizar, deve ser de no máximo 2°C.
3. A velocidade do cooler deve ser monitorada.
4. O sistema opera entre a temperatura ambiente e 90°C. A temperatura máxima ocorre devido a limitações físicas do resistor.


## Documentação Completa

Para mais detalhes, consulte a documentação completa no arquivo Relatorio.pdf incluído neste repositório. A documentação cobre:

	•	Requisitos do projeto
	•	Representação do hardware
	•	Diagramas de camadas e classes
	•	Fluxogramas e máquina de estados
	•	Procedimentos de sintonização do controlador
	•	Manual de utilização
	•	Problemas identificados e não resolvidos

## Licença

Este projeto está licenciado sob os termos da licença MIT. Para mais detalhes, veja o arquivo LICENSE.

Este README fornece uma visão geral do projeto e instrui sobre como utilizá-lo e entendê-lo. Para informações detalhadas, consulte a documentação no repositório.
