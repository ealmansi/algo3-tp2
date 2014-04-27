struct Pieza
{
  Pieza(int indice, int sup, int izq, int der, int inf)
    : indice(indice), sup(sup), izq(izq), der(der), inf(inf) {}
  int indice;
  int sup;
  int izq;
  int der;
  int inf;
};

struct Tablero
{
  Tablero(int n, int m) : cantPiezas(0), casilleros(n, vector<int>(m, 0)) {}

  int cantPiezas;
  vector<vector<int> > casilleros;
};

Salida Problema3::resolver(const Entrada &e)
{
  Tablero solucionParcial(e.n, e.m), solucionOptima(e.n, e.m);
  vector<bool> piezaDisponible(e.n * e.m, true);

  resolverBacktracking(0, 0, solucionParcial, solucionOptima, piezaDisponible, e);

  Salida s;
  s.casilleros = solucionOptima.casilleros;
  return s;
}

void resolverBacktracking(int i, int j, Tablero &solucionParcial,
  Tablero &solucionOptima, vector<bool> &piezaDisponible, const Entrada &e)
{
  int sig_i, sig_j;
  calcularSiguientePos(sig_i, sig_j, i, j, e);

  for (int indicePieza = 1; indicePieza <= e.n * e.m; ++indicePieza)
  {
    if (!piezaDisponible[indicePieza - 1]) continue;
    if (!esCompatible(indicePieza, i, j, solucionParcial, e)) continue;

    colocarPieza(indicePieza, i, j, solucionParcial, piezaDisponible);

    if (solucionOptima.cantPiezas < solucionParcial.cantPiezas)
      solucionOptima = solucionParcial;

    if (llamarRecursivamente(sig_i, sig_j, solucionParcial, solucionOptima, piezaDisponible, e))
      resolverBacktracking(sig_i, sig_j, solucionParcial, solucionOptima, piezaDisponible, e);

    removerPieza(indicePieza, i, j, solucionParcial, piezaDisponible);
  }

  if (llamarRecursivamente(sig_i, sig_j, solucionParcial, solucionOptima, piezaDisponible, e))
    resolverBacktracking(sig_i, sig_j, solucionParcial, solucionOptima, piezaDisponible, e);
}

bool llamarRecursivamente(int i, int j, Tablero &solucionParcial,
  Tablero &solucionOptima, vector<bool> &piezaDisponible, const Entrada &e)
{
  if (solucionOptima.cantPiezas == e.n * e.m)
    return false;

  if (e.n <= i || e.m <= j)
    return false;

  int espaciosRestantes = e.n * e.m - (i * e.m + j);
  vector<int> coloresNecesarios(e.c, 0);
  int f, c, indice;
  f = (i == 0) ? 0 : i - 1;
  c = (i == 0) ? 0 : j;
  for (; f != i && c != j ; calcularSiguientePos(f, c, f, c, e))
  {
    indice = solucionParcial.casilleros[f][c];
    if (indice != 0)
      ++coloresNecesarios[e.piezas[indice - 1].inf - 1];
  }

  for (int h = 0; h < e.n * e.m; ++h)
    if (piezaDisponible[h])
      --coloresNecesarios[e.piezas[h - 1].sup - 1];

  for (int h = 0; h < e.c; ++h)
    if (coloresNecesarios[h] > 0)
      espaciosRestantes -= coloresNecesarios[h];

  if (solucionParcial.cantPiezas + espaciosRestantes <= solucionOptima.cantPiezas)
    return false;

  return true;
}

void calcularSiguientePos(int &sig_i, int &sig_j, int i, int j, const Entrada &e)
{
  sig_i = i + (j + 1) / e.m;
  sig_j = (j + 1) % e.m;
}

bool esCompatible(int indicePieza, int i, int j, Tablero &solucionParcial, const Entrada &e)
{
  const Pieza &pieza = e.piezas[indicePieza - 1];
  if (0 < j)
  {
    int indicePiezaIzq = solucionParcial.casilleros[i][j - 1];
    if (0 < indicePiezaIzq)
      if (pieza.izq != e.piezas[indicePiezaIzq - 1].der)
        return false;
  }
  if (0 < i)
  {
    int indicePiezaSup = solucionParcial.casilleros[i - 1][j];
    if (0 < indicePiezaSup)
      if (pieza.sup != e.piezas[indicePiezaSup - 1].inf)
        return false;
  }

  return true;
}

void colocarPieza(int indicePieza, int i, int j,
  Tablero &tablero, vector<bool> &piezaDisponible)
{
  tablero.casilleros[i][j] = indicePieza;
  ++tablero.cantPiezas;
  piezaDisponible[indicePieza - 1] = false;
}

void removerPieza(int indicePieza, int i, int j,
  Tablero &tablero, vector<bool> &piezaDisponible)
{
  tablero.casilleros[i][j] = 0;
  --tablero.cantPiezas;
  piezaDisponible[indicePieza - 1] = true;
}

