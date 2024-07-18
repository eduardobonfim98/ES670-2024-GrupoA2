Visão Geral

Este projeto foi desenvolvido para o curso ES670 - Projeto de Sistemas Embarcados da Unicamp. O objetivo é criar um sistema de controle de temperatura que utiliza um resistor como aquecedor e um cooler para resfriamento. O sistema controla a temperatura do resistor com precisão através de um controlador PID, sintonizado pelo método de Ziegler-Nichols.

Componentes de Hardware

	•	Microcontrolador: NUCLEO-G474RE
	•	Interfaces: Display LCD, botões, buzzer, LEDs
	•	Aquecimento e Resfriamento: Resistor como aquecedor e ventilador como cooler
	•	Sensores: Sensores de temperatura digital e analógico, fotodiodo e LED para tacômetro

Funcionalidades do Software

Desenvolvido em C com CubeIDE, o software do sistema inclui:

	•	Manutenção de Temperatura: Controle da temperatura do resistor conforme o setpoint definido pelo usuário.
	•	Interface Local: Botões e display LCD para ajuste e monitoramento da temperatura.
	•	Controle Remoto via UART: Ajuste de parâmetros do controlador PID e monitoramento remoto.
	•	Indicadores Visuais e Sonoros: LEDs para indicação de faixas de temperatura e buzzer para feedback de botões.

Procedimentos de Utilização

	1.	Definir Temperatura: Utilize os botões para aumentar/diminuir o setpoint e para mudar a tela do LCD.
	2.	Monitoramento: Acompanhe a temperatura atual e desejada, a velocidade do cooler, Kp, Ki, Kd no display LCD.
	3.	Ajuste de parâmetros da planta de controle: Use comandos UART para ajustar Kp, Ki e Kd.

Mudança de Ownership do Repositório

Este repositório foi originalmente criado na conta GitHub associada ao meu email universitário (eduardosiqueiraunicamp). Para fins de portfólio e melhor organização, o repositório foi transferido para a minha conta profissional no GitHub (eduardobonfim98).

Documentação Completa

Para mais detalhes, consulte a documentação completa no arquivo Relatorio.pdf incluído neste repositório. A documentação cobre:

	•	Requisitos do projeto
	•	Representação do hardware
	•	Diagramas de camadas e classes
	•	Fluxogramas e máquina de estados
	•	Procedimentos de sintonização do controlador
	•	Manual de utilização
	•	Problemas identificados e não resolvidos

Créditos

Autores do projeto:

	•	Eduardo Siqueira (RA: 196308)
	•	Henrique Akira (RA: 198741)
	•	Lucas Finzzeto Pavarini (RA: 182509)

Licença

Este projeto está licenciado sob os termos da licença MIT. Para mais detalhes, veja o arquivo LICENSE.

Este README fornece uma visão geral do projeto e instrui sobre como utilizá-lo e entendê-lo. Para informações detalhadas, consulte a documentação no repositório.
