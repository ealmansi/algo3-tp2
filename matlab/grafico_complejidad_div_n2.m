function grafico_complejidad(ms, label)
  if ~isfloat(ms) || size(ms,2) ~= 2
      error('Entrada inválida.')
  end

  figure;
  plot(ms(:,1),ms(:,2)./(ms(:,1).^2));
  title([label ' : ' 'Tiempo de ejecucion / cuadratica vs Tamano de entrada']);
  ylabel('Tiempo de ejecucion / cuadratica (ns / n^2)');
  xlabel('Tamano de entrada (n)');
  legend('T(n) / n^2');
end