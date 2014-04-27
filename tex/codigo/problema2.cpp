struct Pieza
{
  Pieza(int indice, int perdida, int tiempo)
    : indice(indice), perdida(perdida), tiempo(tiempo) {}
  static bool comparar_piezas(const Pieza& lhs, const Pieza& rhs)
  {
    return lhs.tiempo * rhs.perdida < rhs.tiempo * lhs.perdida;
  }

  int indice;
  int perdida;
  int tiempo;
};

Salida Problema2::resolver(const Entrada &e)
{
  Salida s; 
  s.piezas = vector<Pieza>(e.piezas);
  s.perdida_total = 0;

  sort(s.piezas.begin(), s.piezas.end(), Pieza::comparar_piezas);

  int acum_tiempo = 0;
  for (vector<Pieza>::const_iterator i = s.piezas.begin(); i != s.piezas.end(); ++i)
  {
    acum_tiempo += i->tiempo;
    s.perdida_total += acum_tiempo * i->perdida;
  }

  return s;
}