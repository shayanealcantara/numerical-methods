# Format output to show just 2 decimals
format bank

# Initialize constants
a = 1;
b = 0.5;
n = 10;

# Change value of n if passed as command line argument
try
  # Get arguments list
  arg_list = argv ();
  n = str2double(arg_list{1});
catch
  printf ("Using default value of n: %d\n", n)
end

# Initialize matriz NxN with zeros
matriz = zeros(n);

# Set b and a of matriz
matriz(1, 1) = a;
matriz(1, 2) = b;
matriz(n, n) = a;
matriz(n, n-1) = b;

for i = 2:(n-1)
  matriz(i, i) = a;
  matriz(i, i - 1) = b;
  matriz(i, i + 1) = b;
end

# Display matriz
matriz

# Calculate Autovalor and Autovetor of matriz
[autovetor autovalor] = eig(matriz);
disp("autovalor = \n")
disp(diag(autovalor))
disp("")

autovetor
