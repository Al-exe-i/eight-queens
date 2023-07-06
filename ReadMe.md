﻿# Решение задачи о восьми ферзях

**Суть задачи**

Расставить на стандартной 64-клеточной шахматной доске 8 ферзей так, чтобы ни один из них не находился под боем другого.

## Алгоритм решения задачи

*Для решения используется поиск с возвратом: первый ферзь ставится на первую горизонталь, затем каждый следующий ставится на следующую так, чтобы его не били ранее установленные ферзи. Если на очередном этапе постановки свободных полей не оказывается, происходит возврат на шаг назад — переставляется ранее установленный ферзь.*