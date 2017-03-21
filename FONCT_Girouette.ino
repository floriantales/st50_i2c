// Fonction d'acquisition girouette vent apparent
int readAWA()
{
  // Lecture du capteur:
  float green = (float)readAvgAD(A0, 1, 5); // On appel la fonction readAvgAD
  float blue = (float)readAvgAD(A1, 1, 5);
    
  // Reduction de l'ellipse en XY 0:
  green -= xc;
  blue -= yc;

  // Calcul de l'angle de vent apparent:
  float xmap = (wcx0 * green) + (wcx1 * blue);
  float ymap = (wcy0 * green) + (wcy1 * blue);  
  int awa_measured = int(atan2(ymap, xmap) * 180/pi + 180);
  
  // Ajout de l'offset de calibration et conversion en 360°
  awa_measured += offsetAWA;
  convert: 
  if (awa_measured < 0) {
    awa_measured += 360;
    goto convert;
  }
  if (awa_measured > 360) {
    awa_measured -= 360;
    goto convert;
  }
  if (awa_measured == 360) awa_measured = 0;
  
  return awa_measured;
}
