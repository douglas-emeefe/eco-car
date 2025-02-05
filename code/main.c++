/*
 * Nome Projeto: Carrinho Bluetooth com materiais reciclados
 * Autor: DOUGLAS OLIVEIRA
 * Biblioteca AFMotor: https://learn.adafruit.com/adafruit-motor-shield/library-install
 */

#include <AFMotor.h>

// Inicialição dos pinos do motor
AF_DCMotor motor1(1, MOTOR12_1KHZ);
AF_DCMotor motor2(2, MOTOR12_1KHZ);

int status;
int Speeed = 255;

void setup()
{
    Serial.begin(9600); // Definindo taxa de transmissão do módulo Bluetooth
}

void loop()
{
    if (Serial.available() > 0)
    {
        status = Serial.read();

        Stop(); // Inicializa com os motores desligados

        if (status == 'F')
        {
            forward();
        }

        if (status == 'B')
        {
            back();
        }

        if (status == 'L')
        {
            left();
        }

        if (status == 'R')
        {
            right();
        }

        if (status == 'S')
        {
            Stop();
        }
    }
}

// Função movimentar carrinho para frente
void forward()
{
    motor1.setSpeed(Speeed); // Define velocidade máxima
    motor1.run(FORWARD);     // Gira motor no sentido horário
    motor2.setSpeed(Speeed); // Define velocidade máxima
    motor2.run(FORWARD);     // Gira motor no sentido horário
}

// Função movimentar carrinho para trás
void back()
{
    motor1.setSpeed(Speeed); // Define velocidade máxima
    motor1.run(BACKWARD);    // Gira motor no sentido anti-horário
    motor2.setSpeed(Speeed); // Define velocidade máxima
    motor2.run(BACKWARD);    // Gira motor no sentido anti-horário
}

// Função movimentar carrinho para esquerda
void left()
{
    motor1.setSpeed(Speeed); // Define velocidade máxima
    motor1.run(BACKWARD);    // Gira motor no sentido anti-horário
    motor2.setSpeed(Speeed); // Define velocidade máxima
    motor2.run(FORWARD);     // Gira motor no sentido horário
}

// Função movimentar carrinho para direita
void right()
{
    motor1.setSpeed(Speeed); // Define velocidade máxima
    motor1.run(FORWARD);     // Gira motor no sentido horário
    motor2.setSpeed(Speeed); // Define velocidade máxima
    motor2.run(BACKWARD);    // Gira motor no sentido anti-horário
}

// Função parar carro
void Stop()
{
    motor1.setSpeed(0);  // Define velocidade mínima
    motor1.run(RELEASE); // stop the motor when release the button
    motor2.setSpeed(0);  // Define velocidade mínima
    motor2.run(RELEASE); // Gira motor no sentido horário
}