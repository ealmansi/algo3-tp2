function grafico_complejidad_varios_k(ms_n_5, ms_n_10, ms_n_15, ms_n_20, ms_n_25, fig_title, labels, unidades)

  if ~exist('unidades','var')
    unidades='ns';
  end

  cc=hsv(5);
  figure;
  hold on;
  plot(ms_n_5(:,1), ms_n_5(:,2), 'color', cc(1,:));
  plot(ms_n_10(:,1), ms_n_10(:,2), 'color', cc(2,:));
  plot(ms_n_15(:,1), ms_n_15(:,2), 'color', cc(3,:));
  plot(ms_n_20(:,1), ms_n_20(:,2), 'color', cc(4,:));
  plot(ms_n_25(:,1), ms_n_25(:,2), 'color', cc(5,:));

  title([fig_title]);
  ylabel(['Tiempo de ejecucion (' unidades ')']);
  xlabel('Unidades de salto extra (k)');
  legend(labels);

end