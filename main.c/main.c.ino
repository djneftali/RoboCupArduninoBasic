
#include <infrarrojo.h>

infrarrojo derecha(13);//DEFINICION DEL PIN DEL ARDUINO A USAR
infrarrojo  izquierda(10);//DEFINICION DEL PIN DEL ARDUINO A USAR
int VALOR;//VARIBLE QUE RECIBE EL DATO
int led =12;//REDEFINICION DE PIN DE ARDUINO PARA LED INDICADOR DE PULSO(ESTO ES OPCIONAL)
int led_estado;//VARIABLE
int motor1 = 2;
int motor2 = 3;
int motor4 = 4;
int motor3 = 5;
long distancia;
int contador=0;
long tiempo;
void adelante(int status){
if (status==1)
{ 
 digitalWrite(motor1,HIGH);
 digitalWrite(motor2,HIGH);
}
}

int mover_x_pasos(int status,int pasos, int contador){ 
  if(contador < pasos){
     adelante(status);
     contador +=1;
  } 
  else{
    detener(1);
   }
  return contador;
}

void atras(int status){
if (status==1)
{
 digitalWrite(motor4,HIGH);
 digitalWrite(motor3,HIGH);
}}


void mover_derecha(int status){
if (status==1)
{
 digitalWrite(motor1,HIGH);
 digitalWrite(motor2,LOW);
}}

void mover_izquierda(int status){
if (status==1)
{
 digitalWrite(motor1,LOW);
 digitalWrite(motor2,HIGH);
}}

void detener(int status){
if (status==1)
{
 digitalWrite(motor1,LOW);
 digitalWrite(motor2,LOW);
}}



void setup()
{
pinMode(led,OUTPUT);//LED QUE INDICA EL ESTADO DEL LED
Serial.begin(9600); //VELOCIDAD COMUNICACION SERIAL
pinMode(9, OUTPUT); /*activación del pin 9 como salida: para el pulso ultrasónico*/
pinMode(8, INPUT); /*activación del pin 8 como entrada: tiempo del rebote del ultrasonido*/
pinMode(motor1,OUTPUT);
pinMode(motor2,OUTPUT);
pinMode(motor4,OUTPUT);
pinMode(motor3,OUTPUT);
}
//CODIGO PRINCIPAL
void loop(){
  
  Serial.print("\n derecha: \n");//IMPRIME MENSAJE EN PC
Serial.print(derecha.lectura(VALOR));//IMPRIME EL ESTADO DEL Vo DEL SENSOR MEDIANTE LA VARIABLE VALOR
led_estado = derecha.lectura(VALOR);//LED QUE RECOGE EL ESTADO DEL SENSOR
//if(led_estado != 1)//ETAPA DE COMPARACION PARA ACTIVAR UN LED SEGUN EL ESTADO DEL SENSOR
//{
// adelante(1);
//}else{
// mover_izquierda(1);
//}
 Serial.print(contador);
contador = mover_x_pasos(1,50,contador);
delay(10);
}








//{
//{
//Serial.print("\n derecha: \n");//IMPRIME MENSAJE EN PC
//Serial.print(derecha.lectura(VALOR));//IMPRIME EL ESTADO DEL Vo DEL SENSOR MEDIANTE LA VARIABLE VALOR
//led_estado = derecha.lectura(VALOR);//LED QUE RECOGE EL ESTADO DEL SENSOR
//if(led_estado == 1)//ETAPA DE COMPARACION PARA ACTIVAR UN LED SEGUN EL ESTADO DEL SENSOR
//{
//  digitalWrite(led,HIGH);//PRENDE UN LED SI EL SENSOR DETECTA OBSTACULO
//    servo1.write(90);
//}
//else
//{
//  servo1.write(1);
//}
//delay(100);//GENERA UN TIEMPO PARA LEER E IMPRIMIR EN PUERTO SERIE  
//}
//
//{
//Serial.print("\n izquierda: \n");//IMPRIME MENSAJE EN PC
//Serial.print(izquierda.lectura(VALOR));//IMPRIME EL ESTADO DEL Vo DEL SENSOR MEDIANTE LA VARIABLE VALOR
//led_estado = izquierda.lectura(VALOR);//LED QUE RECOGE EL ESTADO DEL SENSOR
//if(led_estado == 1)//ETAPA DE COMPARACION PARA ACTIVAR UN LED SEGUN EL ESTADO DEL SENSOR
//{
//  digitalWrite(led,HIGH);//PRENDE UN LED SI EL SENSOR DETECTA OBSTACULO
//   servo2.write(90);
//}
//else
//{
// servo2.write(1);
//}
//delay(100);//GENERA UN TIEMPO PARA LEER E IMPRIMIR EN PUERTO SERIE
//}
//{
//  digitalWrite(9,LOW); /* Por cuestión de estabilización del sensor*/
//  delayMicroseconds(5);
//  digitalWrite(9, HIGH); /* envío del pulso ultrasónico*/
//  delayMicroseconds(10);
//  tiempo=pulseIn(8, HIGH); /* Función para medir la longitud del pulso entrante. Mide el tiempo que transcurrido entre el envío
//  del pulso ultrasónico y cuando el sensor recibe el rebote, es decir: desde que el pin 12 empieza a recibir el rebote, HIGH, hasta que
//  deja de hacerlo, LOW, la longitud del pulso entrante*/
//  distancia= int(0.017*tiempo); /*fórmula para calcular la distancia obteniendo un valor entero*/
//  /*Monitorización en centímetros por el monitor serial*/
//  Serial.println("Distancia ");
//  Serial.println(distancia);
//  Serial.println(" cm");
//  }
//  
//  if (distancia < 5)
//{
//  digitalWrite(4,LOW);
//  digitalWrite(5,LOW);
//}
//else
//{
//  digitalWrite(4,HIGH);
//  digitalWrite(5,HIGH);
//}
//}
