function grafico_complejidad_varios_k(ms_k_0, ms_k_10, ms_k_20, ms_k_30, ms_k_40, fig_title, labels)

  cc=hsv(5);
  figure;
  hold on;
  plot(ms_k_0(:,1), ms_k_0(:,2), 'color', cc(1,:));
  plot(ms_k_10(:,1), ms_k_10(:,2), 'color', cc(2,:));
  plot(ms_k_20(:,1), ms_k_20(:,2), 'color', cc(3,:));
  plot(ms_k_30(:,1), ms_k_30(:,2), 'color', cc(4,:));
  plot(ms_k_40(:,1), ms_k_40(:,2), 'color', cc(5,:));

  title([fig_title]);
  ylabel('Tiempo de ejecucion (ns)');
  xlabel('Tamano de entrada (n)');
  legend(labels);

end