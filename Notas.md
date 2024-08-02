1. Implementar los stacks como listas circulares enlazadas.
	* Al principio creas la lista con un nodo para cada número y otra vacía.
	* Los nodos una vez creados no se borran y se destruyen. De forma que el número de mallocs y frees no será muy alto.
	* Pese a todo es mejor que estén alocados en memoria por si te meten una cantidad de números grandes, aunque sabemos que
		en principio no te deberian pasar más de 5000. Aún así nos podrían crear un segmentation fault con un número muy grande, así
		que no podemos hacerlo en estático.

2. Chequeamos el número de argumentos. Al menos dos y el segundo no debe estar vacío. 

2. El parseo (que sean números y que no se repitan podría ser previo o según cargamos la estructura).
	* Si nos lo meten en forma de cadena hacemos un split.
	* Hacemos chequeo de formato. Puede ser dentro o fuera del itol. Es más natural hacerlo dentro del itol.
	* Tenemos que hacer un itol. Chequeamos en cambio que 
	* Tenemos que chequear que no haya repetidos. Para ello hay que llevar una registro de los números leídos.


3. Implementación del algoritmo. El turco.



//Declare pointers to two data structures/linked lists, one for stack `a` and another for `b`
	//Set both pointers to NULL to avoid undefined behaviour and indicate we're starting with empty stacks

//Handle input count errors. Argument count must be 2 or more, and the second input must not be empty
	//If input errors, return error

//Handle both cases of input, whether a variable number of command line arguments, or as a string
	//If the input of numbers is as a string, call split() to split the substrings

//Initialize stack `a` by appending each input number as a node to stack `a`
	//Handle integer overflow, duplicates, and syntax errors, e.g. input must only contain digits, or `-` `+` signs
		//If errors found, free stack `a` and return error
	//Check for each input, if it is a long integer
		//If the input is a string, convert it to a long integer 
	//Append the nodes to stack `a`

//Check if stack `a` is sorted
	//If not sorted, implement our sorting algorithm 
		//Check for 2 numbers
			//If so, simply swap the numbers
		//Check for 3 numbers
			//If so, implement our simple `sort three` algorithim
		//Check if the stack has more than 3 numbers
			//If so, implent our Turk Algorithm

//Clean up the stack