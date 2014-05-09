csv_dir = '../problema3/csv/';
eps_dir = '../problema3/eps/';

ms_k_02 = cargar_mediciones([csv_dir 'instancia_p_80p_k_02.csv']);
ms_k_04 = cargar_mediciones([csv_dir 'instancia_p_80p_k_04.csv']);
ms_k_06 = cargar_mediciones([csv_dir 'instancia_p_80p_k_06.csv']);
ms_k_08 = cargar_mediciones([csv_dir 'instancia_p_80p_k_08.csv']);
ms_k_10 = cargar_mediciones([csv_dir 'instancia_p_80p_k_10.csv']);

grafico_complejidad_varios_k(ms_k_02, ms_k_04, ms_k_06, ms_k_08, ms_k_10, 'Instancias con potencia 4n/5 en funcion de n', {'k = 2', 'k = 4', 'k = 6', 'k = 8', 'k = 10'}, 'us');
saveas(gca, [eps_dir '/instancia_p_80p_varios_k.eps'],'epsc');

grafico_complejidad_varios_k_div_n(ms_k_02, ms_k_04, ms_k_06, ms_k_08, ms_k_10, 'Instancias con potencia 4n/5 en funcion de n (dividido n)', {'k = 2', 'k = 4', 'k = 6', 'k = 8', 'k = 10'}, 'us');
saveas(gca, [eps_dir '/instancia_p_80p_varios_k_div_n.eps'],'epsc');

grafico_complejidad_varios_k_div_n2(ms_k_02, ms_k_04, ms_k_06, ms_k_08, ms_k_10, 'Instancias con potencia 4n/5 en funcion de n (dividido n^2)', {'k = 2', 'k = 4', 'k = 6', 'k = 8', 'k = 10'}, 'us');
saveas(gca, [eps_dir '/instancia_p_80p_varios_k_div_n2.eps'],'epsc');

ms_n_5 = cargar_mediciones([csv_dir 'instancia_p_80p_n_5.csv']);
ms_n_10 = cargar_mediciones([csv_dir 'instancia_p_80p_n_10.csv']);
ms_n_15 = cargar_mediciones([csv_dir 'instancia_p_80p_n_15.csv']);
ms_n_20 = cargar_mediciones([csv_dir 'instancia_p_80p_n_20.csv']);
ms_n_25 = cargar_mediciones([csv_dir 'instancia_p_80p_n_25.csv']);

grafico_complejidad_varios_n(ms_n_5, ms_n_10, ms_n_15, ms_n_20, ms_n_25, 'Instancias con potencia 4n/5 en funcion de k', {'n = 5', 'n = 10', 'n = 15', 'n = 20', 'n = 25'}, 'us');
saveas(gca, [eps_dir '/instancia_p_80p_varios_n.eps'],'epsc');

ms_n_5 = ms_n_5(50:end,:);
ms_n_10 = ms_n_10(50:end,:);
ms_n_15 = ms_n_15(50:end,:);
ms_n_20 = ms_n_20(50:end,:);
ms_n_25 = ms_n_25(50:end,:);
grafico_complejidad_varios_n(ms_n_5, ms_n_10, ms_n_15, ms_n_20, ms_n_25, 'Instancias con potencia 4n/5 en funcion de k', {'n = 5', 'n = 10', 'n = 15', 'n = 20', 'n = 25'}, 'us');
saveas(gca, [eps_dir '/instancia_p_80p_varios_n_zoom.eps'],'epsc');