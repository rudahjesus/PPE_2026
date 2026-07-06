//integrantes: Rudah Santos de Jesus, Isaac José Guedes Pinheiro de Matos, Raquel de Santana Nascimento, Alvaro Matheus Santos de Oliveira, João Vitor Rodrigues Coelho Ferreira
// Esse é um código que simula o movimento de um robô seguidor de linha utilizando um sistema de controle proporcional
// O robô tem 2 rodas (motores) e 4 sensores. O Código gera um valor aleatório entre 0 e 255 para os sensores como posição inicial
// O 0 significa que o robô não está lendo a linha e 255 significa que o robô está lendo perfeitamente a linha
// Porém, intervalos entre 0 e 70 podem significar que o sensor está fora da linha, e entre 80 e 255 geralmente significam acima da linha
// O código se propõe a forçar os dois sensores do meio (2 e 3) a ficarem em cima da linha, enquanto os dos cantos (1 e 4) ficam fora da linha
// O código foi feito e testado em online gbd, então, se utilizando gcc, vscode ou devc++, pode ser necessário modificar algumas bibliotecas
// Como por exemplo, <unistd.h> pode precisar ser trocado por <windows.h>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main()
{
    int speedMotorA = 20;
    int speedMotorB = 20;

    
    int sensor[4];

    srand(time(NULL));

    for(int i = 0; i < 4; i++)
{
    sensor[i] = rand() % 256;
}

    for(int i = 0; i < 20; i++)
    {
        int nextSpeedMotorA = 0;
        int nextSpeedMotorB = 0;

        if(sensor[0] >= 100 && sensor[1] >= 100)
        {
            sensor[2] = sensor[2] / 10;
            sensor[3] = sensor[3] / 10;
        }

        if(sensor[2] >= 100 && sensor[3] >= 100)
        {
            sensor[0] = sensor[2] / 10;
            sensor[1] = sensor[3] / 10;
        }

        if(sensor[1] >= 100 && sensor[2] >= 100)
        {
            sensor[0] = sensor[2] / 10;
            sensor[3] = sensor[3] / 10;
        }

        sensor[0] = sensor[0] + speedMotorB;
        sensor[1] = sensor[1] + speedMotorB * 2;
        sensor[2] = sensor[2] + speedMotorA * 2;
        sensor[3] = sensor[3] + speedMotorA;

        for(int k = 0; k < 4; k++)
        {
            if(sensor[k] <= 0)
            {
                sensor[k] = 0;
            }

            if(sensor[k] >= 256)
            {
                sensor[k] = 256;
            }
        }

        nextSpeedMotorA =
            sensor[0] / 2 +
            sensor[1] / 5 -
            sensor[2] / 5 -
            sensor[3] / 2;

        nextSpeedMotorB =
            sensor[3] / 2 +
            sensor[2] / 5 -
            sensor[1] / 5 -
            sensor[0] / 2;

        printf("sensor 0: %d || ", sensor[0]);
        printf("sensor 1: %d || ", sensor[1]);
        printf("sensor 2: %d || ", sensor[2]);
        printf("sensor 3: %d\n", sensor[3]);

        printf("prox. vel. motor A = %d || prox. vel. motor B = %d\n",
               nextSpeedMotorA,
               nextSpeedMotorB);

        printf("---------------------------------------------------------------------\n");

        speedMotorA = nextSpeedMotorA;
        speedMotorB = nextSpeedMotorB;

        sleep(2);
    }

    return 0;
}
