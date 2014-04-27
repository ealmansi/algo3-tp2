Salida Problema1::resolver(const Entrada &e)
{
  Salida s;

  vector<int> dias(e.dias);
  sort(dias.begin(), dias.end());

  s.dia_inicial = -1;
  s.max_cant_camiones = -1;
  int i = 0, j = 0, cant_camiones;
  for (; i < e.cant_dias; ++i)
  {
    if (0 < i && dias[i - 1] == dias[i]) continue;
  
    for (; (j < e.cant_dias) && (dias[j] - dias[i] < e.cant_dias_inspeccion); ++j)
      /* vacío */;

    cant_camiones = j - i;
    if (s.max_cant_camiones < cant_camiones)
    {
      s.max_cant_camiones = cant_camiones;
      s.dia_inicial = dias[i];
    }
  }

  return s;
}