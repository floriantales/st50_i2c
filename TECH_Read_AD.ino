// Fonction d'aquisition AnalogDigital moyennée : exemple readAvgAD(A0, 1, 10) - pinoche A0, 1ms entre chaques acquisisons, 10 acquisitions
int readAvgAD(int pin, int waitDelay, int count)
{
   int k=0;
   int sum=0;
   for(k=0;k<count;k++)
   {
       sum += analogRead(pin);
       delay(waitDelay);
   }
   
   return (int)(sum/count);
}
