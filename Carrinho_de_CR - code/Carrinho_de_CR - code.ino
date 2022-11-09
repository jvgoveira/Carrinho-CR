/*       
          Autores: João Vitor Gome e Mateus Lima
   Funcionalidade: O programa a seguir faz o controle de direção, velocidade e 
                   iluminação de um carrinho bluetooth montado em um arduino
                   UNO, com uma shield ponte H, através do protocolo serial
                   
*/

//Aqui pode ser feito o ajuste de correção:
#define Fator_correcao_Dir 1
#define Fator_correcao_Tra 1

//Aqui pode ser alterada a potencia do motor 
#define vmax_D 127
#define vmax_T 191

//Pinos de sáida de dados do motor:
#define motor_direcional 11
#define motor_traseiro 10

/*Saidas de dados para a shield ponte H responsavel
pela direção dos motores*/
#define IN1 3
#define IN2 5
#define IN3 6
#define IN4 9

//Variaveis responsaveis pelo controle dos motores
char estado=0;
int veloc_max_D;
int veloc_max_T;

void setup() 
{
  Serial.begin(9600);
  pinMode(A0,OUTPUT);  //Saidas de dados LED enderecavel
  pinMode(motor_direcional,OUTPUT);  //PWM motor direcional
  pinMode(motor_traseiro,OUTPUT);  //PWM motor traseiro
  pinMode(IN1, OUTPUT); //entrada 1 shield ponte H 
  pinMode(IN2, OUTPUT); //entrada 2 shield ponte H
  pinMode(IN3, OUTPUT); //entrada 3 shield ponte H
  pinMode(IN4, OUTPUT); //entrada 4 shield ponte H
}

void loop() 
{ 
 //Os valores lidos pelo serial sao alocados na variavel "estado"
 if(Serial.available()>0)
 {
   estado = Serial.read();
   Serial.write(estado);
 }


if(estado == '0')
{
  veloc_max_D = vmax_D * 0;
  veloc_max_T = vmax_T * 0;
}
if(estado == '1')
{
  veloc_max_D = vmax_D * 0.1;
  veloc_max_T = vmax_T * 0.1;
}
if(estado == '2')
{
  veloc_max_D = vmax_D * 0.2;
  veloc_max_T = vmax_T * 0.2;
}
if(estado == '3')
{
  veloc_max_D = vmax_D * 0.3;
  veloc_max_T = vmax_T * 0.3;
}
if(estado == '4')
{
  veloc_max_D = vmax_D * 0.39;
  veloc_max_T = vmax_T * 0.39;
}
if(estado == '5')
{
  veloc_max_D = vmax_D * 0.5;
  veloc_max_T = vmax_T * 0.5;
}
if(estado == '6')
{
  veloc_max_D = vmax_D * 0.6;
  veloc_max_T = vmax_T * 0.6;
}
if(estado == '7')
{
  veloc_max_D = vmax_D * 0.7;
  veloc_max_T = vmax_T * 0.7;
}
if(estado == '8')
{
  veloc_max_D = vmax_D * 0.78;
  veloc_max_T = vmax_T * 0.78;
}
if(estado == '9')
{
  veloc_max_D = vmax_D * 9;
  veloc_max_T = vmax_T * 9;
}
if(estado == 'q')
{
  veloc_max_T = vmax_T;
}


// Se o estado recebido for igual a 'F', o carro se movimenta para frente.
if(estado == 'F') 
{
  digitalWrite(IN1,0);
  digitalWrite(IN2,0);
  digitalWrite(IN3,1);
  digitalWrite(IN4,0);
  digitalWrite(motor_direcional,veloc_max_D * Fator_correcao_Dir);
  digitalWrite(motor_traseiro,veloc_max_T * Fator_correcao_Tra);
}

// Se o estado recebido for igual a 'I', o carro se movimenta para Frente Esquerda.
if(estado == 'G')
{
  digitalWrite(IN1,1);
  digitalWrite(IN2,0);
  digitalWrite(IN3,1);
  digitalWrite(IN4,0);
  digitalWrite(motor_direcional,veloc_max_D * Fator_correcao_Dir);
  digitalWrite(motor_traseiro,veloc_max_T * Fator_correcao_Tra);
}

// Se o estado recebido for igual a 'G', o carro se movimenta para Frente Direita.
if(estado == 'I')
{
  digitalWrite(IN1,0);
  digitalWrite(IN2,1);
  digitalWrite(IN3,1);
  digitalWrite(IN4,0);
  digitalWrite(motor_direcional,veloc_max_D * Fator_correcao_Dir);
  digitalWrite(motor_traseiro,veloc_max_T * Fator_correcao_Tra);
}

// Se o estado recebido for igual a 'B', o carro se movimenta para trás.
if(estado == 'B')
{
  digitalWrite(IN1,0);
  digitalWrite(IN2,0);
  digitalWrite(IN3,0);
  digitalWrite(IN4,1);
  digitalWrite(motor_direcional,veloc_max_D * Fator_correcao_Dir);
  digitalWrite(motor_traseiro,veloc_max_T * Fator_correcao_Tra);
}

// Se o estado recebido for igual a 'H', o carro se movimenta para Trás Esquerda.
if(estado == 'H')
{
  digitalWrite(IN1,1);
  digitalWrite(IN2,0);
  digitalWrite(IN3,0);
  digitalWrite(IN4,1);
  digitalWrite(motor_direcional,veloc_max_D * Fator_correcao_Dir);
  digitalWrite(motor_traseiro,veloc_max_T * Fator_correcao_Tra);
}

// Se o estado recebido for igual a 'J', o carro se movimenta para Trás Direita.
if(estado == 'J')
{
  digitalWrite(IN1,0);
  digitalWrite(IN2,1);
  digitalWrite(IN3,0);
  digitalWrite(IN4,1);
  digitalWrite(motor_direcional,veloc_max_D * Fator_correcao_Dir);
  digitalWrite(motor_traseiro,veloc_max_T * Fator_correcao_Tra);
}

// Se o estado recebido for igual a 'L', o carro se movimenta para esquerda.
if(estado == 'L')
{
  digitalWrite(IN1,1);
  digitalWrite(IN2,0);
  digitalWrite(IN3,0);
  digitalWrite(IN4,0);
  digitalWrite(motor_direcional,veloc_max_D * Fator_correcao_Dir);
  digitalWrite(motor_traseiro,veloc_max_T * Fator_correcao_Tra);
}

// Se o estado recebido for igual a 'R', o carro se movimenta para direita.
if(estado == 'R')
{
  digitalWrite(IN1,0);
  digitalWrite(IN2,1);
  digitalWrite(IN3,0);
  digitalWrite(IN4,0);
  digitalWrite(motor_direcional,veloc_max_D * Fator_correcao_Dir);
  digitalWrite(motor_traseiro,veloc_max_T * Fator_correcao_Tra);
}

// Se o estado recebido for igual a 'S', o carro permanece parado.
if(estado == 'S')
{
  digitalWrite(IN1,0);
  digitalWrite(IN2,0);
  digitalWrite(IN3,0);
  digitalWrite(IN4,0);
  digitalWrite(motor_direcional,veloc_max_D * Fator_correcao_Dir);
  digitalWrite(motor_traseiro,veloc_max_T * Fator_correcao_Tra);
}
}