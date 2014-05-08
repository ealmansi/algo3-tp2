csv_dir = '../problema2/csv/';
eps_dir = '../problema2/eps/';

ms_20p = cargar_mediciones([csv_dir 'instancia_aleatoria_20p.csv']);
ms_40p = cargar_mediciones([csv_dir 'instancia_aleatoria_40p.csv']);
ms_60p = cargar_mediciones([csv_dir 'instancia_aleatoria_60p.csv']);
ms_80p = cargar_mediciones([csv_dir 'instancia_aleatoria_80p.csv']);
ms_100p = cargar_mediciones([csv_dir 'instancia_aleatoria_100p.csv']);

grafico_complejidad_varios_k(ms_20p, ms_40p, ms_60p, ms_80p, ms_100p, 'Instancias aleatorias, multiples valores de k', {'k = 20% * n', 'k = 40% * n', 'k = 60% * n', 'k = 80% * n', 'k = 100% * n'});
saveas(gca, [eps_dir '/instancia_aleatoria_varios_k.eps'],'epsc');

grafico_complejidad_varios_k_div_n(ms_20p, ms_40p, ms_60p, ms_80p, ms_100p, 'Instancias aleatorias, multiples valores de k (dividido n)', {'k = 20% * n', 'k = 40% * n', 'k = 60% * n', 'k = 80% * n', 'k = 100% * n'});
saveas(gca, [eps_dir '/instancia_aleatoria_varios_k_div_n.eps'],'epsc');

grafico_complejidad_varios_k_div_n2(ms_20p, ms_40p, ms_60p, ms_80p, ms_100p, 'Instancias aleatorias, multiples valores de k (dividido n^2)', {'k = 20% * n', 'k = 40% * n', 'k = 60% * n', 'k = 80% * n', 'k = 100% * n'});
saveas(gca, [eps_dir '/instancia_aleatoria_varios_k_div_n2.eps'],'epsc');