function grafico_complejidad_varios_k_div_n2(ms_k_1, ms_k_2, ms_k_3, ms_k_4, ms_k_5, fig_title, labels)

  cc=hsv(5);
  figure;
  hold on;
  plot(ms_k_1(:,1), ms_k_1(:,2) ./ (ms_k_1(:,1).^2), 'color', cc(1,:));
  plot(ms_k_2(:,1), ms_k_2(:,2) ./ (ms_k_2(:,1).^2), 'color', cc(2,:));
  plot(ms_k_3(:,1), ms_k_3(:,2) ./ (ms_k_3(:,1).^2), 'color', cc(3,:));
  plot(ms_k_4(:,1), ms_k_4(:,2) ./ (ms_k_4(:,1).^2), 'color', cc(4,:));
  plot(ms_k_5(:,1), ms_k_5(:,2) ./ (ms_k_5(:,1).^2), 'color', cc(5,:));

  title([fig_title]);
  ylabel('Tiempo de ejecucion / cuadratica (ns/n^2)');
  xlabel('Tamano de entrada (n)');
  legend(labels);

end