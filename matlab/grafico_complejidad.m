function grafico_complejidad(ms, label)
  if ~isfloat(ms) || size(ms,2) ~= 2
      error('Entrada inválida.')
  end

  figure;
  plot(ms(:,1),ms(:,2));
  title([label ' : ' 'Tiempo de ejecucion vs Tamano de entrada']);
  ylabel('Tiempo de ejecucion (ns)');
  xlabel('Tamano de entrada (n)');
  legend('T(n)');
end