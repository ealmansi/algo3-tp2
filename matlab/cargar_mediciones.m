function ms = cargar_mediciones(nombre_archivo)
  ms = double(csvread(nombre_archivo, 1, 0));
end