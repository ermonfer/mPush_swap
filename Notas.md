1. Paseo. Esto hay que hacerlo si o si.
	- Todos los argumentos que te pasan son como arrays. Ha estos arrays a que hacerles un split para espacios. Solo reconoce espacios. Una quitado los espacios mirar que son numeros, y una vez hecho esto comprobar que estan en int. La forma más es pasar a atol. Las comprobaciones después de los espacios lo puedes ir cargando en las estructruas ya que ahora sabes lo que ocupan en caso de que todo salga bien. Una vez cargados en un array los ordenas para comprobar que no hay dobles. Estas listo ahora para empezar a ordenar tu pila.

2. Caso base de ordenación.
	- De momento lo dejamos en una función que ordene a 3 elementos y después vemos si inclimos también como básicos los casos 4 o 5.

3. Ordenación por el Turco.
	- El bucle básico es el mismo en las dos fases. Tenemos que sacar el coste de colorcar cada elememento encima del Target.
		* Puedes implementarlo primero para todos y luego ver cuando puedes dejar de calcular.
		* El bucle de cálculo de coste es el centro del algoritmo y marca la estructura
		de datos usada en función de la cantidad de movimientos y de veces que tengas que recorrer la línea. Básicamente esto es el push-swap. La buena noticia es que en
		cuanto saques esto ya lo tienes.
			- Buscas para cada número de tu pila a:
				* El target de la pila b. Te requiere recorrer la pila b una vez por elemento. Aunque es una pila que ya esta ordenada, luego no hace falta recorrerla entera.
				* Calculo de movimientos, deberías sacarlo sabiendo la posición de ambos elementos en sus respectivas pilas, lo que es algo que sabes en ambos casos simplemente porque has ido recorriendo la pila.
				? Quizá merece la pena para estas cosas calcular la posición de la mediana. Es fácil con ambas estructuras.
				* Es simplemente calcular el número de movimientos que le hace falta en cada caso para arriba y para abajo. Y quedarte con el máximo de ambos movimientos en una misma dirección.
				* Cuando tienes el máximo de todos, simplemente efectuas los movimientos, es decir, actualizas las pilas y almacenas el texto necesario para devolver.
				* El texto necesario para devolver lo puedes ir alamacenando ahora así, en una estructura de array más puntero a la siguiente lista. Es posible que es un trabajo que no necesites pero prefiero que sea robusto.


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