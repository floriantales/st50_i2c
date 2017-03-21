// Fonction d'acquisition anemometre vent apparent
float readAWS()
{  
  unsigned long duration_Anemo = 0;
  float aws_measured = 0 ;
  // Lecture de n samples de la durée du front haut:
  for (byte c=0; c<samples_read_Anemo; c++) duration_Anemo += pulseIn(pin_Anemo, HIGH, 2000000);
  
  // On moyenne:
  duration_Anemo = (unsigned long)(duration_Anemo / samples_read_Anemo);

  // Conversion en noeuds: 
  if (duration_Anemo != 0) aws_measured = factorAWS * 1/(((float)duration_Anemo/1000000)*2);
  
  return aws_measured;
}
