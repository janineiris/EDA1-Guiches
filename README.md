# EDA1-Guiches
Estrutura de Dados e Algoritmos I - Sistema de Guichês

## Compilação
Para compilar basta rodar o comando
```
make
```
E executar o arquivo *output*.

## Execução
* Este programa não necessita de entrada de usuário. Ele roda 48 iterações, equivalentes a 4 horas. 1 iteração = 5 minutos. Controlado pela variável cont.

* Há uma lista de Guichês, dos quais 2 são de prioridades;
duas filas de clientes, uma para clientes de prioridade e outra para clientes comuns;
duas pilhas de senhas para clientes.

* No início do programa, as listas são iniciadas e preenchidas. Um vetor, base para as senhas dos clientes, também é preenchido.

* A cada iteração, pelo menos um cliente entra no estabelecimento. A quantidade de clientes a entrar é aleatória, num range de 1 a 4. Se mais de 2 clientes entrarem no estabelecimento, um deles será de prioridade. Caso as senhas "acabem", novas senhas serão geradas.
A complexidade dos problemas dos clientes é escolhida de forma randômica.
Os novos clientes são enfileirados em duas filas, baseado em prioridade.

* A cada 5 hipotéticos minutos, o programa verifica se um guichê precisa ser desativado para o momento de descanso de seu operador. As condições de parada de um guichê são ter trabalhado por, pelo menos, 1h e não estar atendendo. O tempo máximo para um guichê ficar ativo é 1h30, este tempo só pode ser excedido se o guichê estiver em atendimento.
Os guichês de prioridade se revezam, podendo estar ativos ao mesmo tempo.

* O tempo mínimo de descanso é 10 minutos
Caso haja menos que 5 guichês ativos, guichês desativados aleatórios serão escolhidos para operarem. Porém, se algum destes guichês inativos estiverem no momento de descanso, não serão ativados.

* Qualquer guichê pode atender qualquer tipo de cliente, desde que sua fila original esteja vazia.


## Autora
**Iris Nogueira**
