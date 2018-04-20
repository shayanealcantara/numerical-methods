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
for i = 1:n
  for j = 1:n
    if i == j
      matriz(i,j) = a;
      if i > 1
        matriz(i-1,j) = b;
      end
      if i < n
        matriz(i+1,j) = b;
      end
    end

  end
end

# Display matriz
matriz

# Calculate Autovalor and Autovetor of matriz
[autovetor autovalor] = eig(matriz);
disp("autovalor = \n")
disp(diag(autovalor))
disp("")

autovetor
