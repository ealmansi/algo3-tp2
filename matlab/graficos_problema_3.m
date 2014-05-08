csv_dir = '../problema3/csv/';
eps_dir = '../problema3/eps/';

ms_k_0 = cargar_mediciones([csv_dir 'instancia_p_5_k_0.csv']);
ms_k_10 = cargar_mediciones([csv_dir 'instancia_p_5_k_10.csv']);
ms_k_20 = cargar_mediciones([csv_dir 'instancia_p_5_k_20.csv']);
ms_k_30 = cargar_mediciones([csv_dir 'instancia_p_5_k_30.csv']);
ms_k_40 = cargar_mediciones([csv_dir 'instancia_p_5_k_40.csv']);

grafico_complejidad_varios_k(ms_k_0, ms_k_10, ms_k_20, ms_k_30, ms_k_40, 'Instancias con potencia unitaria en funcion de n', {'k = 0', 'k = 10', 'k = 20', 'k = 30', 'k = 40'});
saveas(gca, [eps_dir '/instancia_p_5_varios_k.eps'],'epsc');

grafico_complejidad_varios_k_div_n(ms_k_0, ms_k_10, ms_k_20, ms_k_30, ms_k_40, 'Instancias con potencia unitaria en funcion de n (dividido n)', {'k = 0', 'k = 10', 'k = 20', 'k = 30', 'k = 40'});
saveas(gca, [eps_dir '/instancia_p_5_varios_k_div_n.eps'],'epsc');

grafico_complejidad_varios_k_div_n2(ms_k_0, ms_k_10, ms_k_20, ms_k_30, ms_k_40, 'Instancias con potencia unitaria en funcion de n (dividido n^2)', {'k = 0', 'k = 10', 'k = 20', 'k = 30', 'k = 40'});
saveas(gca, [eps_dir '/instancia_p_5_varios_k_div_n2.eps'],'epsc');

ms_n_5 = cargar_mediciones([csv_dir 'instancia_p_5_n_5.csv']);
ms_n_10 = cargar_mediciones([csv_dir 'instancia_p_5_n_10.csv']);
ms_n_15 = cargar_mediciones([csv_dir 'instancia_p_5_n_15.csv']);
ms_n_20 = cargar_mediciones([csv_dir 'instancia_p_5_n_20.csv']);
ms_n_25 = cargar_mediciones([csv_dir 'instancia_p_5_n_25.csv']);

grafico_complejidad_varios_n(ms_n_5, ms_n_10, ms_n_15, ms_n_20, ms_n_25, 'Instancias con potencia unitaria en funcion de k', {'n = 5', 'n = 10', 'n = 15', 'n = 20', 'n = 25'});
saveas(gca, [eps_dir '/instancia_p_5_varios_n.eps'],'epsc');

ms_n_5 = ms_n_5(50:end,:);
ms_n_10 = ms_n_10(50:end,:);
ms_n_15 = ms_n_15(50:end,:);
ms_n_20 = ms_n_20(50:end,:);
ms_n_25 = ms_n_25(50:end,:);
grafico_complejidad_varios_n(ms_n_5, ms_n_10, ms_n_15, ms_n_20, ms_n_25, 'Instancias con potencia unitaria en funcion de k', {'n = 5', 'n = 10', 'n = 15', 'n = 20', 'n = 25'});
saveas(gca, [eps_dir '/instancia_p_5_varios_n_zoom.eps'],'epsc');