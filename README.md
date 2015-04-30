#Trabalho para Faculdade

Sistema de Campeonato de Futebol em C.



Descrição:

Um campeonato de futebol está ocorrendo e é necessário armazenar dados sobre as partidas realizadas, bem como saber a classificação das equipes. São realizadas diversas partidas, sempre envolvendo 2 equipes distintas. Para cada partida, deve-se armazenar o número de gols de cada equipe. A vitória de uma equipe dá a ela 3 pontos, enquanto que empate dá a ambas 1 ponto.

Os dados, que devem ser fornecidos via arquivo texto, têm o seguinte formato: primeiramente indica-se a quantidade E de equipes participantes (2 <= E <= 20). Cada equipe tem uma identificação numérica sequencial, entre 401 e 400 + E. Em seguida, são descritas inúmeras partidas P (1 <= P <= 500), cada uma delas contendo 4 valores X, Y, Z, W. X e Z indicam equipes, enquanto Y e W indicam a quantidade de gols que X e Z, respectivamente, marcaram na partida. Um fim de arquivo é usado para indicar o final das entradas.

Ex.:<br>
3     // 3 equipes participam<br>
401 2 402 0    // eq. 401 fez 2 a 0 na eq. 402<br>
403 1 401 1   // eq. 403 empatou em 1 a 1 com eq. 401<br>
402 1 403 4<br>
402 2 401 0<br>
401 1 403 0<br>
403 2 402 2<br><br>

A saída deve conter os números de identificação das equipes, em ordem, considerando os seguintes critérios: a) número de pontos; b) saldo de gols; c) número de gols marcados. Caso haja empate nos 3 critérios, a equipe com menor identificação numérica deve ser mostrada primeiro.

Ex. (para o caso acima)

401 403 402

Obs.: Para a ordenação dos dados, você não deve utilizar métodos/funções prontas de linguagem de programação.
