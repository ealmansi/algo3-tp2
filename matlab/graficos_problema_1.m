csv_dir = '../problema1/csv/';
eps_dir = '../problema1/eps/';

ms = cargar_mediciones([csv_dir 'instancia_aleatoria.csv']);
ms = ms(10:end,:);

grafico_complejidad(ms, 'Instancias aleatorias');
saveas(gca, [eps_dir '/instancia_aleatoria.eps'],'epsc');

grafico_complejidad_div_n2(ms, 'Instancias aleatorias');
saveas(gca, [eps_dir '/instancia_aleatoria_div_n2.eps'],'epsc');

grafico_complejidad_div_n3(ms, 'Instancias aleatorias');
saveas(gca, [eps_dir '/instancia_aleatoria_div_n3.eps'],'epsc');