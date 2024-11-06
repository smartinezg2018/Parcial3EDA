## Queries para usar dentro del programa
Realizado por Simón Martínez

INSERT INTO clientes (nombre,edad) ('Juan',22),
INSERT INTO clientes (nombre,edad) ('Laura',24),
INSERT INTO clientes (nombre,edad) ('Luis',29),
INSERT INTO clientes (nombre,edad) ('Maria',31),

UPDATE clientes SET edad=68 WHERE nombre='Laura'

select (nombre,edad) from clientes
select (edad) from clientes

INSERT INTO estudiantes (id,nombre,edad) (1,'Juan',22)
INSERT INTO estudiantes (id,nombre,edad) (2,'Ana',30)
INSERT INTO estudiantes (id,nombre,edad) (3,'Carlos',25)
INSERT INTO estudiantes (id,nombre,edad) (7,'Miguel',27)
INSERT INTO estudiantes (id,nombre,edad) (8,'Laura',24)
INSERT INTO estudiantes (id,nombre,edad) (9,'Luis',29)
INSERT INTO estudiantes (id,nombre,edad,fecha) (10,'Maria',31,12/10/2000)

select (id,edad) from estudiantes
