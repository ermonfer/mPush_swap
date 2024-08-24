#!/bin/zsh

# Verifica si se proporcionaron los argumentos necesarios
if [ $# -ne 2 ]; then
    echo "Uso: $0 <longitud de lista> <número_de_ejecuciones>"
    exit 1
fi

cantidad=$1
ejecuciones=$2
maximo=0

# Bucle para ejecutar el comando el número especificado de veces
for i in {1..$ejecuciones}
do
    # Genera la lista de números y la pasa a push_swap
    resultado=$(shuf -i 1-1000 -n $cantidad | tr '\n' ' ' | xargs ./push_swap | wc -l)
    
    # Compara el resultado con el máximo actual
    if (( resultado > maximo )); then
        maximo=$resultado
    fi
done

# Imprime el resultado máximo
echo $maximo