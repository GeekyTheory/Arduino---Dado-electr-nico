/*
  Autor: Mario Pérez Esteso
  Web: www.geekytheory.com
  Twitter: @geekytheory
  Facebook: www.facebook.com/geekytheory
*/

int Pin_Pulsador = 2;
int apagado=99;
void setup()                 
{
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(8, OUTPUT);
    pinMode(9, OUTPUT);
    pinMode(10, OUTPUT);
    pinMode(11, OUTPUT);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    pinMode(2,INPUT);
    Serial.begin(9600); //Con esto, podremos ver el número obtenido en la ventana de debug
    //Se podría haber hecho la inicialización de los pines con un
    // bucle for, pero se ha escrito así para comprenderlo mejor
  randomSeed(analogRead(0)); //Para que no sea siempre la misma semilla
}


void loop()
{
  if (digitalRead(Pin_Pulsador)) //Si pulso el interruptor
  {
    tiroeldado();
  }
  delay(50);
}

void tiroeldado()
{
  int numero;
  int veces_aleatorio = random(15, 30);
  for (int i = 0; i < veces_aleatorio; i++)
  {
    numero = random(1, 13);
    mostrar(numero);
    delay(50 + i*10); //Cada vez va más lento
  }
  Serial.println(numero);
  for(int j=0;j<3;j++)
  {
  mostrar(apagado);
  delay(1000);
  mostrar(numero);
  delay(1000);
}
}


void mostrar(int numero_a_mostrar)
{
  if(numero_a_mostrar==99) //Apago los displays
  {
    digitalWrite(3,HIGH);  //A
    digitalWrite(4,HIGH);   //B
    digitalWrite(5,HIGH);  //C
    digitalWrite(6,HIGH);  //D
    digitalWrite(8,HIGH);  //A
    digitalWrite(9,HIGH);   //B
    digitalWrite(10,HIGH);  //C
    digitalWrite(11,HIGH);  //D
  } else
  {
  int Display_1=numero_a_mostrar*0.1;//Cojo la segunda cifra del resultado (decenas)
  int Display_2=numero_a_mostrar-Display_1*10;//Cojo la primera cifra del resultado (unidades)
  if(Display_1==0)
  {
    digitalWrite(8,LOW);  //A
    digitalWrite(9,LOW);   //B
    digitalWrite(10,LOW);  //C
    digitalWrite(11,LOW);  //D
  }else if(Display_1==1)
  {
    digitalWrite(8,HIGH);  //A
    digitalWrite(9,LOW);   //B
    digitalWrite(10,LOW);  //C
    digitalWrite(11,LOW);  //D
  } 
  
  if(Display_2==0)
  {
    digitalWrite(3,LOW); //A
    digitalWrite(4,LOW);  //B
    digitalWrite(5,LOW);  //C
    digitalWrite(6,LOW);  //D
  }else if(Display_2==1)
  {
    digitalWrite(3,HIGH); //A
    digitalWrite(4,LOW);  //B
    digitalWrite(5,LOW);  //C
    digitalWrite(6,LOW);  //D
  } else if(Display_2==2)
  {
    digitalWrite(3,LOW); //A
    digitalWrite(4,HIGH);  //B
    digitalWrite(5,LOW);  //C
    digitalWrite(6,LOW);  //D
  } else if(Display_2==3)
  {
    digitalWrite(3,HIGH); //A
    digitalWrite(4,HIGH);  //B
    digitalWrite(5,LOW);  //C
    digitalWrite(6,LOW);  //D
  } else if(Display_2==4)
  {
    digitalWrite(3,LOW); //A
    digitalWrite(4,LOW);  //B
    digitalWrite(5,HIGH);  //C
    digitalWrite(6,LOW);  //D
  } else if(Display_2==5)
  {
    digitalWrite(3,HIGH); //A
    digitalWrite(4,LOW);  //B
    digitalWrite(5,HIGH);  //C
    digitalWrite(6,LOW);  //D
  } else if(Display_2==6)
  {
    digitalWrite(3,LOW); //A
    digitalWrite(4,HIGH);  //B
    digitalWrite(5,HIGH);  //C
    digitalWrite(6,LOW);  //D
  } else if(Display_2==7)
  {
    digitalWrite(3,HIGH); //A
    digitalWrite(4,HIGH);  //B
    digitalWrite(5,HIGH);  //C
    digitalWrite(6,LOW);  //D
  } else if(Display_2==8)
  {
    digitalWrite(3,LOW); //A
    digitalWrite(4,LOW);  //B
    digitalWrite(5,LOW);  //C
    digitalWrite(6,HIGH);  //D
  } else if(Display_2==9)
  {
    digitalWrite(3,HIGH); //A
    digitalWrite(4,LOW);  //B
    digitalWrite(5,LOW);  //C
    digitalWrite(6,HIGH);  //D
  }
  }
}
