Ejercicio 1
=========

a) Implementar en C++ el datatype DateTime, el cual representa una fecha. Este contiene la fecha considerando el año, mes y día en los formatos: YYYY, MM, DD respectivamente; y la hora considerando horas y minutos en el formato HH:MM.
⋅Se puede asumir que todos los meses tienen 30 días.
⋅El constructor por defecto deberá crear un DateTime utilizando los datos de fecha/hora del sistema.
⋅Debe ser posible obtener una instancia de DateTime indicando o no la hora. Asuma como valor por omisión para la hora los valores 00:00.
b) Agregar la sobrecarga de los siguientes operadores:
⋅Asignación (operador =)
⋅Comparación (operadores ==, !=, <, >, <=, >=)
⋅Suma (operador + double (días)).
⋅⋅Por ejemplo la expresión
⋅⋅⋅DateTime(1997, 2, 1, 0, 0) + 1.5 == DateTime(1997, 2, 2, 12, 0) es true
⋅Resta (operador – double (días))
⋅⋅Por ejemplo la expresión
⋅⋅⋅DateTime(1987, 2, 12, 0, 0) - 1.5 == DateTime(1997, 2, 10, 12, 0) es true
⋅Resta (operador – DateTime). Devuelve la diferencia entre las fechas como un número double con los días de diferencia entre ambas fechas.
c) Agregar la sobrecarga del operador de inserción de flujo (i.e. <<) en un objeto de tipo std::ostream. El mismo debe imprimir en el flujo de salida la fecha en el siguiente formato: YYYY/MM/DD HH:MM.
⋅Por ejemplo la sentencia cout << DateTime(2013, 18, 3, 17, 5) << “\n” debe imprimir “2013/03/18 17:05” y un salto de línea en la salida estándar.
d) Realizar un procedimiento main() que permita, mediante un menú, probar todas las
funcionalidades implementadas en las partes anteriores.
