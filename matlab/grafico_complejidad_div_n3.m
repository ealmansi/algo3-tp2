function grafico_complejidad(ms, label)
  if ~isfloat(ms) || size(ms,2) ~= 2
      error('Entrada inválida.')
  end

  figure;
  plot(ms(:,1),ms(:,2)./(ms(:,1).^3));
  title([label ' : ' 'Tiempo de ejecucion / cubica vs Tamano de entrada']);
  ylabel('Tiempo de ejecucion / cubica (ns / n^3)');
  xlabel('Tamano de entrada (n)');
  legend('T(n) / n^3');
end